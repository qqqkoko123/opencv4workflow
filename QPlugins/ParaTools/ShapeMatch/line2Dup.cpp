#include "line2Dup.h"
#include <iostream>
#include <chrono>
using namespace std;

class Timer
{
public:
	Timer() : beg_(clock_::now()) {}
	void reset() { beg_ = clock_::now(); }
	double elapsed() const {
		return std::chrono::duration_cast<second_>
			(clock_::now() - beg_).count();
	}
	void out(std::string message = "") {
		double t = elapsed();
		std::cout << message << "\nelasped time:" << t << "s\n" << std::endl;
		reset();
	}

private:
	typedef std::chrono::high_resolution_clock clock_;
	typedef std::chrono::duration<double, std::ratio<1> > second_;
	std::chrono::time_point<clock_> beg_;
};

namespace line2Dup
{
	static inline int getLabel(int quantized)
	{
		switch (quantized)
		{
		case 1:
			return 0;
		case 2:
			return 1;
		case 4:
			return 2;
		case 8:
			return 3;
		case 16:
			return 4;
		case 32:
			return 5;
		case 64:
			return 6;
		case 128:
			return 7;
		default:
			return -1;
		}
	}

	void Feature::read(const cv::FileNode& fn)
	{
		cv::FileNodeIterator fni = fn.begin();
		fni >> x >> y >> label;
	}

	void Feature::write(cv::FileStorage& fs) const
	{
		fs << "[:" << x << y << label << "]";
	}

	void Template::read(const cv::FileNode& fn)
	{
		width = fn["width"];
		height = fn["height"];
		tl_x = fn["tl_x"];
		tl_y = fn["tl_y"];
		pyramid_level = fn["pyramid_level"];
		cv::FileNode features_fn = fn["features"];
		features.resize(features_fn.size());
		cv::FileNodeIterator it = features_fn.begin(), it_end = features_fn.end();
		for (int i = 0; it != it_end; ++it, ++i)
		{
			features[i].read(*it);
		}
	}

	void Template::write(cv::FileStorage& fs) const
	{
		fs << "width" << width;
		fs << "height" << height;
		fs << "tl_x" << tl_x;
		fs << "tl_y" << tl_y;
		fs << "pyramid_level" << pyramid_level;
		fs << "features"
			<< "[";
		for (int i = 0; i < (int)features.size(); ++i)
		{
			features[i].write(fs);
		}
		fs << "]";
	}

	static cv::Rect cropTemplates(std::vector<Template>& templates)
	{
		int min_x = std::numeric_limits<int>::max();
		int min_y = std::numeric_limits<int>::max();
		int max_x = std::numeric_limits<int>::min();
		int max_y = std::numeric_limits<int>::min();
		for (int i = 0; i < (int)templates.size(); ++i)
		{
			Template& templ = templates[i];
			for (int j = 0; j < (int)templ.features.size(); ++j)
			{
				int x = templ.features[j].x << templ.pyramid_level;
				int y = templ.features[j].y << templ.pyramid_level;
				min_x = std::min(min_x, x);
				min_y = std::min(min_y, y);
				max_x = std::max(max_x, x);
				max_y = std::max(max_y, y);
			}
		}
		if (min_x % 2 == 1)
			--min_x;
		if (min_y % 2 == 1)
			--min_y;
		for (int i = 0; i < (int)templates.size(); ++i)
		{
			Template& templ = templates[i];
			templ.width = (max_x - min_x) >> templ.pyramid_level;
			templ.height = (max_y - min_y) >> templ.pyramid_level;
			templ.tl_x = min_x >> templ.pyramid_level;
			templ.tl_y = min_y >> templ.pyramid_level;
			for (int j = 0; j < (int)templ.features.size(); ++j)
			{
				templ.features[j].x -= templ.tl_x;
				templ.features[j].y -= templ.tl_y;
			}
		}
		return cv::Rect(min_x, min_y, max_x - min_x, max_y - min_y);
	}

	bool ColorGradientPyramid::selectScatteredFeatures(const std::vector<Candidate>& candidates,
		std::vector<Feature>& features,
		size_t num_features, float distance)
	{
		features.clear();
		float distance_sq = distance * distance;
		int i = 0;
		bool first_select = true;
		while (true)
		{
			Candidate c = candidates[i];
			bool keep = true;
			for (int j = 0; (j < (int)features.size()) && keep; ++j)
			{
				Feature f = features[j];
				keep = (c.f.x - f.x) * (c.f.x - f.x) + (c.f.y - f.y) * (c.f.y - f.y) >= distance_sq;
			}
			if (keep)
				features.push_back(c.f);
			if (++i == (int)candidates.size())
			{
				bool num_ok = features.size() >= num_features;
				if (first_select)
				{
					if (num_ok)
					{
						features.clear();
						i = 0;
						distance += 1.0f;
						distance_sq = distance * distance;
						continue;
					}
					else
					{
						first_select = false;
					}
				}
				i = 0;
				distance -= 1.0f;
				distance_sq = distance * distance;
				if (num_ok || distance < 3) {
					break;
				}
			}
		}
		return true;
	}

	void hysteresisGradient(cv::Mat& magnitude, cv::Mat& quantized_angle,
		cv::Mat& angle, float threshold)
	{
		cv::Mat_<unsigned char> quantized_unfiltered;
		angle.convertTo(quantized_unfiltered, CV_8U, 16.0 / 360.0);
		memset(quantized_unfiltered.ptr(), 0, quantized_unfiltered.cols);
		memset(quantized_unfiltered.ptr(quantized_unfiltered.rows - 1), 0, quantized_unfiltered.cols);
		for (int r = 0; r < quantized_unfiltered.rows; ++r)
		{
			quantized_unfiltered(r, 0) = 0;
			quantized_unfiltered(r, quantized_unfiltered.cols - 1) = 0;
		}
		for (int r = 1; r < angle.rows - 1; ++r)
		{
			uchar* quant_r = quantized_unfiltered.ptr<uchar>(r);
			for (int c = 1; c < angle.cols - 1; ++c)
			{
				quant_r[c] &= 7;
			}
		}
		quantized_angle = cv::Mat::zeros(angle.size(), CV_8U);
		for (int r = 1; r < angle.rows - 1; ++r)
		{
			float* mag_r = magnitude.ptr<float>(r);
			for (int c = 1; c < angle.cols - 1; ++c)
			{
				if (mag_r[c] > threshold)
				{
					int histogram[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
					uchar* patch3x3_row = &quantized_unfiltered(r - 1, c - 1);
					histogram[patch3x3_row[0]]++;
					histogram[patch3x3_row[1]]++;
					histogram[patch3x3_row[2]]++;
					patch3x3_row += quantized_unfiltered.step1();
					histogram[patch3x3_row[0]]++;
					histogram[patch3x3_row[1]]++;
					histogram[patch3x3_row[2]]++;
					patch3x3_row += quantized_unfiltered.step1();
					histogram[patch3x3_row[0]]++;
					histogram[patch3x3_row[1]]++;
					histogram[patch3x3_row[2]]++;
					int max_votes = 0;
					int index = -1;
					for (int i = 0; i < 8; ++i)
					{
						if (max_votes < histogram[i])
						{
							index = i;
							max_votes = histogram[i];
						}
					}
					static const int NEIGHBOR_THRESHOLD = 5;
					if (max_votes >= NEIGHBOR_THRESHOLD)
						quantized_angle.at<uchar>(r, c) = uchar(1 << index);
				}
			}
		}
	}

	static void quantizedOrientations(const cv::Mat& src, cv::Mat& magnitude,
		cv::Mat& angle, cv::Mat& angle_ori, float threshold)
	{
		cv::Mat smoothed;
		static const int KERNEL_SIZE = 7;
		cv::GaussianBlur(src, smoothed, cv::Size(KERNEL_SIZE, KERNEL_SIZE), 0, 0, cv::BORDER_REPLICATE);
		if (src.channels() == 1)
		{
			cv::Mat sobel_dx, sobel_dy, sobel_ag;
			cv::Sobel(smoothed, sobel_dx, CV_32F, 1, 0, 3, 1.0, 0.0, cv::BORDER_REPLICATE);
			cv::Sobel(smoothed, sobel_dy, CV_32F, 0, 1, 3, 1.0, 0.0, cv::BORDER_REPLICATE);
			magnitude = sobel_dx.mul(sobel_dx) + sobel_dy.mul(sobel_dy);
			cv::phase(sobel_dx, sobel_dy, sobel_ag, true);
			hysteresisGradient(magnitude, angle, sobel_ag, threshold * threshold);
			angle_ori = sobel_ag;
		}
		else
		{
			magnitude.create(src.size(), CV_32F);
			cv::Size size = src.size();
			cv::Mat sobel_3dx;
			cv::Mat sobel_3dy;
			cv::Mat sobel_dx(size, CV_32F);
			cv::Mat sobel_dy(size, CV_32F);
			cv::Mat sobel_ag;
			cv::Sobel(smoothed, sobel_3dx, CV_16S, 1, 0, 3, 1.0, 0.0, cv::BORDER_REPLICATE);
			cv::Sobel(smoothed, sobel_3dy, CV_16S, 0, 1, 3, 1.0, 0.0, cv::BORDER_REPLICATE);
			short* ptrx = (short*)sobel_3dx.data;
			short* ptry = (short*)sobel_3dy.data;
			float* ptr0x = (float*)sobel_dx.data;
			float* ptr0y = (float*)sobel_dy.data;
			float* ptrmg = (float*)magnitude.data;
			const int length1 = static_cast<const int>(sobel_3dx.step1());
			const int length2 = static_cast<const int>(sobel_3dy.step1());
			const int length3 = static_cast<const int>(sobel_dx.step1());
			const int length4 = static_cast<const int>(sobel_dy.step1());
			const int length5 = static_cast<const int>(magnitude.step1());
			const int length0 = sobel_3dy.cols * 3;
			for (int r = 0; r < sobel_3dy.rows; ++r)
			{
				int ind = 0;
				for (int i = 0; i < length0; i += 3)
				{
					int mag1 = ptrx[i + 0] * ptrx[i + 0] + ptry[i + 0] * ptry[i + 0];
					int mag2 = ptrx[i + 1] * ptrx[i + 1] + ptry[i + 1] * ptry[i + 1];
					int mag3 = ptrx[i + 2] * ptrx[i + 2] + ptry[i + 2] * ptry[i + 2];
					if (mag1 >= mag2 && mag1 >= mag3)
					{
						ptr0x[ind] = ptrx[i];
						ptr0y[ind] = ptry[i];
						ptrmg[ind] = (float)mag1;
					}
					else if (mag2 >= mag1 && mag2 >= mag3)
					{
						ptr0x[ind] = ptrx[i + 1];
						ptr0y[ind] = ptry[i + 1];
						ptrmg[ind] = (float)mag2;
					}
					else
					{
						ptr0x[ind] = ptrx[i + 2];
						ptr0y[ind] = ptry[i + 2];
						ptrmg[ind] = (float)mag3;
					}
					++ind;
				}
				ptrx += length1;
				ptry += length2;
				ptr0x += length3;
				ptr0y += length4;
				ptrmg += length5;
			}
			cv::phase(sobel_dx, sobel_dy, sobel_ag, true);
			hysteresisGradient(magnitude, angle, sobel_ag, threshold * threshold);
			angle_ori = sobel_ag;
		}
	}

	ColorGradientPyramid::ColorGradientPyramid(const cv::Mat& _src, const cv::Mat& _mask,
		float _weak_threshold, size_t _num_features,
		float _strong_threshold)
		: src(_src),
		mask(_mask),
		pyramid_level(0),
		weak_threshold(_weak_threshold),
		num_features(_num_features),
		strong_threshold(_strong_threshold)
	{
		update();
	}

	void ColorGradientPyramid::update()
	{
		quantizedOrientations(src, magnitude, angle, angle_ori, weak_threshold);
	}

	void ColorGradientPyramid::pyrDown()
	{
		num_features /= 2;
		++pyramid_level;
		cv::Size size(src.cols / 2, src.rows / 2);
		cv::Mat next_src;
		cv::pyrDown(src, next_src, size);
		src = next_src;
		if (!mask.empty())
		{
			cv::Mat next_mask;
			cv::resize(mask, next_mask, size, 0.0, 0.0, cv::INTER_AREA);
			mask = next_mask;
		}
		update();
	}

	void ColorGradientPyramid::quantize(cv::Mat& dst) const
	{
		dst = cv::Mat::zeros(angle.size(), CV_8U);
		angle.copyTo(dst, mask);
	}

	bool ColorGradientPyramid::extractTemplate(Template& templ) const
	{
		cv::Mat local_mask;
		if (!mask.empty())
		{
			cv::erode(mask, local_mask, cv::Mat(), cv::Point(-1, -1), 1, cv::BORDER_REPLICATE);
		}
		std::vector<Candidate> candidates;
		bool no_mask = local_mask.empty();
		float threshold_sq = strong_threshold * strong_threshold;
		int nms_kernel_size = 5;
		cv::Mat magnitude_valid = cv::Mat(magnitude.size(), CV_8UC1, cv::Scalar(255));
		for (int r = 0 + nms_kernel_size / 2; r < magnitude.rows - nms_kernel_size / 2; ++r)
		{
			const uchar* mask_r = no_mask ? NULL : local_mask.ptr<uchar>(r);
			for (int c = 0 + nms_kernel_size / 2; c < magnitude.cols - nms_kernel_size / 2; ++c)
			{
				if (no_mask || mask_r[c])
				{
					float score = 0;
					if (magnitude_valid.at<uchar>(r, c) > 0)
					{
						score = magnitude.at<float>(r, c);
						bool is_max = true;
						for (int r_offset = -nms_kernel_size / 2; r_offset <= nms_kernel_size / 2; r_offset++) {
							for (int c_offset = -nms_kernel_size / 2; c_offset <= nms_kernel_size / 2; c_offset++) {
								if (r_offset == 0 && c_offset == 0) continue;
								if (score < magnitude.at<float>(r + r_offset, c + c_offset))
								{
									score = 0;
									is_max = false;
									break;
								}
							}
							if (!is_max) break;
						}
						if (is_max)
						{
							for (int r_offset = -nms_kernel_size / 2; r_offset <= nms_kernel_size / 2; r_offset++)
							{
								for (int c_offset = -nms_kernel_size / 2; c_offset <= nms_kernel_size / 2; c_offset++)
								{
									if (r_offset == 0 && c_offset == 0) continue;
									magnitude_valid.at<uchar>(r + r_offset, c + c_offset) = 0;
								}
							}
						}
					}
					if (score > threshold_sq && angle.at<uchar>(r, c) > 0)
					{
						candidates.push_back(Candidate(c, r, getLabel(angle.at<uchar>(r, c)), score));
						candidates.back().f.theta = angle_ori.at<float>(r, c);
					}
				}
			}
		}
		if (candidates.size() < num_features)
		{
			if (candidates.size() <= 4)
			{
				std::cout << "too few features, abort" << std::endl;
				return false;
			}
			std::cout << "have no enough features, exaustive mode" << std::endl;
		}
		std::stable_sort(candidates.begin(), candidates.end());
		float distance = static_cast<float>(candidates.size() / num_features + 1);
		if (!selectScatteredFeatures(candidates, templ.features, num_features, distance))
		{
			return false;
		}
		templ.width = -1;
		templ.height = -1;
		templ.pyramid_level = pyramid_level;
		return true;
	}

	ColorGradient::ColorGradient()
		: weak_threshold(30.0f),
		num_features(63),
		strong_threshold(60.0f)
	{
	}

	ColorGradient::ColorGradient(float _weak_threshold, size_t _num_features, float _strong_threshold)
		: weak_threshold(_weak_threshold),
		num_features(_num_features),
		strong_threshold(_strong_threshold)
	{
	}

	static const char CG_NAME[] = "ColorGradient";

	std::string ColorGradient::name() const
	{
		return CG_NAME;
	}

	void ColorGradient::read(const cv::FileNode& fn)
	{
		cv::String type = fn["type"];
		CV_Assert(type == CG_NAME);
		weak_threshold = fn["weak_threshold"];
		num_features = int(fn["num_features"]);
		strong_threshold = fn["strong_threshold"];
	}

	void ColorGradient::write(cv::FileStorage& fs) const
	{
		fs << "type" << CG_NAME;
		fs << "weak_threshold" << weak_threshold;
		fs << "num_features" << int(num_features);
		fs << "strong_threshold" << strong_threshold;
	}

	static void orUnaligned8u(const uchar* src, const int src_stride,
		uchar* dst, const int dst_stride,
		const int width, const int height)
	{
		for (int r = 0; r < height; ++r)
		{
			int c = 0;
			while (reinterpret_cast<unsigned long long>(src + c) % 16 != 0)
			{
				dst[c] |= src[c];
				c++;
			}
			for (; c <= width - mipp::N<uint8_t>(); c += mipp::N<uint8_t>())
			{
				mipp::Reg<uint8_t> src_v((uint8_t*)src + c);
				mipp::Reg<uint8_t> dst_v((uint8_t*)dst + c);
				mipp::Reg<uint8_t> res_v = mipp::orb(src_v, dst_v);
				res_v.store((uint8_t*)dst + c);
			}
			for (; c < width; c++)
				dst[c] |= src[c];
			src += src_stride;
			dst += dst_stride;
		}
	}

	static void spread(const cv::Mat& src, cv::Mat& dst, int T)
	{
		dst = cv::Mat::zeros(src.size(), CV_8U);
		for (int r = 0; r < T; ++r)
		{
			for (int c = 0; c < T; ++c)
			{
				orUnaligned8u(&src.at<unsigned char>(r, c), static_cast<const int>(src.step1()), dst.ptr(),
					static_cast<const int>(dst.step1()), src.cols - c, src.rows - r);
			}
		}
	}

	static const unsigned char LUT3 = 3;

	CV_DECL_ALIGNED(16)
		static const unsigned char SIMILARITY_LUT[256] = { 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, 0, LUT3, 4, 4, LUT3, LUT3, 4, 4, 0, LUT3, 4, 4, LUT3, LUT3, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, LUT3, 4, 4, 4, 4, LUT3, LUT3, LUT3, LUT3, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, LUT3, LUT3, LUT3, 4, 4, 4, 4, 4, 4, 4, 4, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, LUT3, 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 4, LUT3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, 4, 4, LUT3, LUT3, 4, 4, 0, LUT3, 4, 4, LUT3, LUT3, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LUT3, LUT3, 4, 4, 4, 4, LUT3, LUT3, LUT3, LUT3, 4, 4, 4, 4, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, LUT3, 0, 0, 0, 0, LUT3, LUT3, LUT3, LUT3, 4, 4, 4, 4, 4, 4, 4, 4 };

	static void computeResponseMaps(const cv::Mat& src, std::vector<cv::Mat>& response_maps)
	{
		CV_Assert((src.rows * src.cols) % 16 == 0);
		response_maps.resize(8);
		for (int i = 0; i < 8; ++i)
			response_maps[i].create(src.size(), CV_8U);
		cv::Mat lsb4(src.size(), CV_8U);
		cv::Mat msb4(src.size(), CV_8U);
		for (int r = 0; r < src.rows; ++r)
		{
			const uchar* src_r = src.ptr(r);
			uchar* lsb4_r = lsb4.ptr(r);
			uchar* msb4_r = msb4.ptr(r);
			for (int c = 0; c < src.cols; ++c)
			{
				lsb4_r[c] = src_r[c] & 15;
				msb4_r[c] = (src_r[c] & 240) >> 4;
			}
		}
		{
			uchar* lsb4_data = lsb4.ptr<uchar>();
			uchar* msb4_data = msb4.ptr<uchar>();
			bool no_max = true;
			bool no_shuff = true;

#ifdef has_max_int8_t
			no_max = false;
#endif

#ifdef has_shuff_int8_t
			no_shuff = false;
#endif		
			for (int ori = 0; ori < 8; ++ori)
			{
				uchar* map_data = response_maps[ori].ptr<uchar>();
				const uchar* lut_low = SIMILARITY_LUT + 32 * ori;
				if (mipp::N<uint8_t>() == 1 || no_max || no_shuff)
				{
					for (int i = 0; i < src.rows * src.cols; ++i)
						map_data[i] = std::max(lut_low[lsb4_data[i]], lut_low[msb4_data[i] + 16]);
				}
				else if (mipp::N<uint8_t>() == 16)
				{
					const uchar* lut_low = SIMILARITY_LUT + 32 * ori;
					mipp::Reg<uint8_t> lut_low_v((uint8_t*)lut_low);
					mipp::Reg<uint8_t> lut_high_v((uint8_t*)lut_low + 16);
					for (int i = 0; i < src.rows * src.cols; i += mipp::N<uint8_t>())
					{
						mipp::Reg<uint8_t> low_mask((uint8_t*)lsb4_data + i);
						mipp::Reg<uint8_t> high_mask((uint8_t*)msb4_data + i);
						mipp::Reg<uint8_t> low_res = mipp::shuff(lut_low_v, low_mask);
						mipp::Reg<uint8_t> high_res = mipp::shuff(lut_high_v, high_mask);
						mipp::Reg<uint8_t> result = mipp::max(low_res, high_res);
						result.store((uint8_t*)map_data + i);
					}
				}
				else if (mipp::N<uint8_t>() == 16 || mipp::N<uint8_t>() == 32
					|| mipp::N<uint8_t>() == 64)
				{
					CV_Assert((src.rows * src.cols) % mipp::N<uint8_t>() == 0);
					uint8_t lut_temp[mipp::N<uint8_t>()] = { 0 };
					for (int slice = 0; slice < mipp::N<uint8_t>() / 16; slice++)
					{
						std::copy_n(lut_low, 16, lut_temp + slice * 16);
					}
					mipp::Reg<uint8_t> lut_low_v(lut_temp);
					uint8_t base_add_array[mipp::N<uint8_t>()] = { 0 };
					for (uint8_t slice = 0; slice < mipp::N<uint8_t>(); slice += 16)
					{
						std::copy_n(lut_low + 16, 16, lut_temp + slice);
						std::fill_n(base_add_array + slice, 16, slice);
					}
					mipp::Reg<uint8_t> base_add(base_add_array);
					mipp::Reg<uint8_t> lut_high_v(lut_temp);
					for (int i = 0; i < src.rows * src.cols; i += mipp::N<uint8_t>())
					{
						mipp::Reg<uint8_t> mask_low_v((uint8_t*)lsb4_data + i);
						mipp::Reg<uint8_t> mask_high_v((uint8_t*)msb4_data + i);
						mask_low_v += base_add;
						mask_high_v += base_add;
						mipp::Reg<uint8_t> shuff_low_result = mipp::shuff(lut_low_v, mask_low_v);
						mipp::Reg<uint8_t> shuff_high_result = mipp::shuff(lut_high_v, mask_high_v);
						mipp::Reg<uint8_t> result = mipp::max(shuff_low_result, shuff_high_result);
						result.store((uint8_t*)map_data + i);
					}
				}
				else
				{
					for (int i = 0; i < src.rows * src.cols; ++i)
						map_data[i] = std::max(lut_low[lsb4_data[i]], lut_low[msb4_data[i] + 16]);
				}
			}
		}
	}

	static void linearize(const cv::Mat& response_map, cv::Mat& linearized, int T)
	{
		CV_Assert(response_map.rows % T == 0);
		CV_Assert(response_map.cols % T == 0);
		int mem_width = response_map.cols / T;
		int mem_height = response_map.rows / T;
		linearized.create(T * T, mem_width * mem_height, CV_8U);
		int index = 0;
		for (int r_start = 0; r_start < T; ++r_start)
		{
			for (int c_start = 0; c_start < T; ++c_start)
			{
				uchar* memory = linearized.ptr(index);
				++index;
				for (int r = r_start; r < response_map.rows; r += T)
				{
					const uchar* response_data = response_map.ptr(r);
					for (int c = c_start; c < response_map.cols; c += T)
						*memory++ = response_data[c];
				}
			}
		}
	}

	static const unsigned char* accessLinearMemory(const std::vector<cv::Mat>& linear_memories,
		const Feature& f, int T, int W)
	{
		const cv::Mat& memory_grid = linear_memories[f.label];
		CV_DbgAssert(memory_grid.rows == T * T);
		CV_DbgAssert(f.x >= 0);
		CV_DbgAssert(f.y >= 0);
		int grid_x = f.x % T;
		int grid_y = f.y % T;
		int grid_index = grid_y * T + grid_x;
		CV_DbgAssert(grid_index >= 0);
		CV_DbgAssert(grid_index < memory_grid.rows);
		const unsigned char* memory = memory_grid.ptr(grid_index);
		int lm_x = f.x / T;
		int lm_y = f.y / T;
		int lm_index = lm_y * W + lm_x;
		CV_DbgAssert(lm_index >= 0);
		CV_DbgAssert(lm_index < memory_grid.cols);
		return memory + lm_index;
	}

	static void similarity(const std::vector<cv::Mat>& linear_memories, const Template& templ,
		cv::Mat& dst, cv::Size size, int T)
	{
		CV_Assert(templ.features.size() < 8192);
		int W = size.width / T;
		int H = size.height / T;
		int wf = (templ.width - 1) / T + 1;
		int hf = (templ.height - 1) / T + 1;
		int span_x = W - wf;
		int span_y = H - hf;
		int template_positions = span_y * W + span_x + 1;
		dst = cv::Mat::zeros(H, W, CV_16U);
		short* dst_ptr = dst.ptr<short>();
		mipp::Reg<uint8_t> zero_v(uint8_t(0));
		for (int i = 0; i < (int)templ.features.size(); ++i)
		{
			Feature f = templ.features[i];
			if (f.x < 0 || f.x >= size.width || f.y < 0 || f.y >= size.height)
				continue;
			const uchar* lm_ptr = accessLinearMemory(linear_memories, f, T, W);
			int j = 0;
			for (; j <= template_positions - mipp::N<int16_t>() * 2; j += mipp::N<int16_t>())
			{
				mipp::Reg<uint8_t> src8_v((uint8_t*)lm_ptr + j);
				mipp::Reg<int16_t> src16_v(mipp::interleavelo(src8_v, zero_v).r);
				mipp::Reg<int16_t> dst_v((int16_t*)dst_ptr + j);
				mipp::Reg<int16_t> res_v = src16_v + dst_v;
				res_v.store((int16_t*)dst_ptr + j);
			}
			for (; j < template_positions; j++)
				dst_ptr[j] += short(lm_ptr[j]);
		}
	}

	static void similarityLocal(const std::vector<cv::Mat>& linear_memories, const Template& templ,
		cv::Mat& dst, cv::Size size, int T, cv::Point center)
	{
		CV_Assert(templ.features.size() < 8192);
		int W = size.width / T;
		dst = cv::Mat::zeros(16, 16, CV_16U);
		int offset_x = (center.x / T - 8) * T;
		int offset_y = (center.y / T - 8) * T;
		mipp::Reg<uint8_t> zero_v = uint8_t(0);
		for (int i = 0; i < (int)templ.features.size(); ++i)
		{
			Feature f = templ.features[i];
			f.x += offset_x;
			f.y += offset_y;
			if (f.x < 0 || f.y < 0 || f.x >= size.width || f.y >= size.height)
				continue;
			const uchar* lm_ptr = accessLinearMemory(linear_memories, f, T, W);
			{
				short* dst_ptr = dst.ptr<short>();
				if (mipp::N<uint8_t>() > 32)
				{
					for (int row = 0; row < 16; row += mipp::N<int16_t>() / 16)
					{
						mipp::Reg<int16_t> dst_v((int16_t*)dst_ptr + row * 16);
						uint8_t local_v[mipp::N<uint8_t>()] = { 0 };
						for (int slice = 0; slice < mipp::N<uint8_t>() / 16 / 2; slice++)
						{
							std::copy_n(lm_ptr, 16, &local_v[16 * slice]);
							lm_ptr += W;
						}
						mipp::Reg<uint8_t> src8_v(local_v);
						mipp::Reg<int16_t> src16_v(mipp::interleavelo(src8_v, zero_v).r);
						mipp::Reg<int16_t> res_v = src16_v + dst_v;
						res_v.store((int16_t*)dst_ptr);
						dst_ptr += mipp::N<int16_t>();
					}
				}
				else
				{
					for (int row = 0; row < 16; ++row)
					{
						for (int col = 0; col < 16; col += mipp::N<int16_t>())
						{
							mipp::Reg<uint8_t> src8_v((uint8_t*)lm_ptr + col);
							mipp::Reg<int16_t> src16_v(mipp::interleavelo(src8_v, zero_v).r);
							mipp::Reg<int16_t> dst_v((int16_t*)dst_ptr + col);
							mipp::Reg<int16_t> res_v = src16_v + dst_v;
							res_v.store((int16_t*)dst_ptr + col);
						}
						dst_ptr += 16;
						lm_ptr += W;
					}
				}
			}
		}
	}

	static void similarity_64(const std::vector<cv::Mat>& linear_memories, const Template& templ,
		cv::Mat& dst, cv::Size size, int T)
	{
		CV_Assert(templ.features.size() < 64);
		int W = size.width / T;
		int H = size.height / T;
		int wf = (templ.width - 1) / T + 1;
		int hf = (templ.height - 1) / T + 1;
		int span_x = W - wf;
		int span_y = H - hf;
		int template_positions = span_y * W + span_x + 1;
		dst = cv::Mat::zeros(H, W, CV_8U);
		uchar* dst_ptr = dst.ptr<uchar>();
		for (int i = 0; i < (int)templ.features.size(); ++i)
		{
			Feature f = templ.features[i];
			if (f.x < 0 || f.x >= size.width || f.y < 0 || f.y >= size.height)
				continue;
			const uchar* lm_ptr = accessLinearMemory(linear_memories, f, T, W);
			int j = 0;
			for (; j <= template_positions - mipp::N<uint8_t>(); j += mipp::N<uint8_t>())
			{
				mipp::Reg<uint8_t> src_v((uint8_t*)lm_ptr + j);
				mipp::Reg<uint8_t> dst_v((uint8_t*)dst_ptr + j);
				mipp::Reg<uint8_t> res_v = src_v + dst_v;
				res_v.store((uint8_t*)dst_ptr + j);
			}
			for (; j < template_positions; j++)
				dst_ptr[j] += lm_ptr[j];
		}
	}

	static void similarityLocal_64(const std::vector<cv::Mat>& linear_memories, const Template& templ,
		cv::Mat& dst, cv::Size size, int T, cv::Point center)
	{
		CV_Assert(templ.features.size() < 64);
		int W = size.width / T;
		dst = cv::Mat::zeros(16, 16, CV_8U);
		int offset_x = (center.x / T - 8) * T;
		int offset_y = (center.y / T - 8) * T;
		for (int i = 0; i < (int)templ.features.size(); ++i)
		{
			Feature f = templ.features[i];
			f.x += offset_x;
			f.y += offset_y;
			if (f.x < 0 || f.y < 0 || f.x >= size.width || f.y >= size.height)
				continue;
			const uchar* lm_ptr = accessLinearMemory(linear_memories, f, T, W);
			{
				uchar* dst_ptr = dst.ptr<uchar>();
				if (mipp::N<uint8_t>() > 16)
				{
					for (int row = 0; row < 16; row += mipp::N<uint8_t>() / 16)
					{
						mipp::Reg<uint8_t> dst_v((uint8_t*)dst_ptr);
						uint8_t local_v[mipp::N<uint8_t>()];
						for (int slice = 0; slice < mipp::N<uint8_t>() / 16; slice++)
						{
							std::copy_n(lm_ptr, 16, &local_v[16 * slice]);
							lm_ptr += W;
						}
						mipp::Reg<uint8_t> src_v(local_v);
						mipp::Reg<uint8_t> res_v = src_v + dst_v;
						res_v.store((uint8_t*)dst_ptr);
						dst_ptr += mipp::N<uint8_t>();
					}
				}
				else
				{
					for (int row = 0; row < 16; ++row)
					{
						for (int col = 0; col < 16; col += mipp::N<uint8_t>())
						{
							mipp::Reg<uint8_t> src_v((uint8_t*)lm_ptr + col);
							mipp::Reg<uint8_t> dst_v((uint8_t*)dst_ptr + col);
							mipp::Reg<uint8_t> res_v = src_v + dst_v;
							res_v.store((uint8_t*)dst_ptr + col);
						}
						dst_ptr += 16;
						lm_ptr += W;
					}
				}
			}
		}
	}

	Detector::Detector()
	{
		this->modality = cv::makePtr<ColorGradient>();
		pyramid_levels = 2;
		T_at_level.push_back(4);
		T_at_level.push_back(8);
	}

	Detector::Detector(std::vector<int> T)
	{
		this->modality = cv::makePtr<ColorGradient>();
		pyramid_levels = T.size();
		T_at_level = T;
	}

	Detector::Detector(int num_features, std::vector<int> T, float weak_thresh, float strong_threash)
	{
		this->modality = cv::makePtr<ColorGradient>(weak_thresh, num_features, strong_threash);
		pyramid_levels = T.size();
		T_at_level = T;
	}

	std::vector<Match> Detector::match(cv::Mat source, float threshold,
		const std::vector<std::string>& class_ids, const cv::Mat mask) const
	{
		Timer timer;
		std::vector<Match> matches;
		std::vector<cv::Ptr<ColorGradientPyramid>> quantizers;
		CV_Assert(mask.empty() || mask.size() == source.size());
		quantizers.push_back(modality->process(source, mask));
		LinearMemoryPyramid lm_pyramid(pyramid_levels,
			std::vector<LinearMemories>(1, LinearMemories(8)));
		std::vector<cv::Size> sizes;
		for (int l = 0; l < pyramid_levels; ++l)
		{
			int T = T_at_level[l];
			std::vector<LinearMemories>& lm_level = lm_pyramid[l];
			if (l > 0)
			{
				for (int i = 0; i < (int)quantizers.size(); ++i)
					quantizers[i]->pyrDown();
			}
			cv::Mat quantized, spread_quantized;
			std::vector<cv::Mat> response_maps;
			for (int i = 0; i < (int)quantizers.size(); ++i)
			{
				quantizers[i]->quantize(quantized);
				spread(quantized, spread_quantized, T);
				computeResponseMaps(spread_quantized, response_maps);
				LinearMemories& memories = lm_level[i];
				for (int j = 0; j < 8; ++j)
					linearize(response_maps[j], memories[j], T);
			}
			sizes.push_back(quantized.size());
		}
		timer.out("construct response map");
		if (class_ids.empty())
		{
			TemplatesMap::const_iterator it = class_templates.begin(), itend = class_templates.end();
			for (; it != itend; ++it)
				matchClass(lm_pyramid, sizes, threshold, matches, it->first, it->second);
		}
		else
		{
			for (int i = 0; i < (int)class_ids.size(); ++i)
			{
				TemplatesMap::const_iterator it = class_templates.find(class_ids[i]);
				if (it != class_templates.end())
				{
					matchClass(lm_pyramid, sizes, threshold, matches, it->first, it->second);					
				}					
			}
		}
		std::sort(matches.begin(), matches.end());
		std::vector<Match>::iterator new_end = std::unique(matches.begin(), matches.end());
		matches.erase(new_end, matches.end());
		timer.out("templ match");
		return matches;
	}

	struct MatchPredicate
	{
		MatchPredicate(float _threshold) : threshold(_threshold) {}
		bool operator()(const Match& m) { return m.similarity < threshold; }
		float threshold;
	};

	void Detector::matchClass(const LinearMemoryPyramid& lm_pyramid,
		const std::vector<cv::Size>& sizes,
		float threshold, std::vector<Match>& matches,
		const std::string& class_id,
		const std::vector<TemplatePyramid>& template_pyramids) const
	{
		float score_buf = threshold;
#pragma omp declare reduction \
    (omp_insert: std::vector<Match>: omp_out.insert(omp_out.end(), omp_in.begin(), omp_in.end()))

#pragma omp parallel for reduction(omp_insert:matches)
		for (size_t template_id = 0; template_id < template_pyramids.size(); ++template_id)
		{
			const TemplatePyramid& tp = template_pyramids[template_id];
			const std::vector<LinearMemories>& lowest_lm = lm_pyramid.back();
			std::vector<Match> candidates;
			{
				cv::Mat similarities;
				int lowest_start = static_cast<int>(tp.size() - 1);
				int lowest_T = T_at_level.back();
				int num_features = 0;
				{
					const Template& templ = tp[lowest_start];
					num_features += static_cast<int>(templ.features.size());
					if (templ.features.size() < 64)
					{
						similarity_64(lowest_lm[0], templ, similarities, sizes.back(), lowest_T);
						similarities.convertTo(similarities, CV_16U);
					}
					else if (templ.features.size() < 8192)
					{
						similarity(lowest_lm[0], templ, similarities, sizes.back(), lowest_T);
					}
				}
				for (int r = 0; r < similarities.rows; ++r)
				{
					ushort* row = similarities.ptr<ushort>(r);
					for (int c = 0; c < similarities.cols; ++c)
					{
						int raw_score = row[c];
						float score = (raw_score * 100.f) / (4 * num_features);
						if (score > threshold)
						{
							threshold = score;
							int offset = lowest_T / 2 + (lowest_T % 2 - 1);
							int x = c * lowest_T + offset;
							int y = r * lowest_T + offset;
							candidates.push_back(Match(x, y, score, class_id, static_cast<int>(template_id)));
						}
					}
				}
			}
			for (int l = pyramid_levels - 2; l >= 0; --l)
			{
				const std::vector<LinearMemories>& lms = lm_pyramid[l];
				int T = T_at_level[l];
				int start = static_cast<int>(l);
				cv::Size size = sizes[l];
				int border = 8 * T;
				int offset = T / 2 + (T % 2 - 1);
				int max_x = size.width - tp[start].width - border;
				int max_y = size.height - tp[start].height - border;
				cv::Mat similarities2;
				for (int m = 0; m < (int)candidates.size(); ++m)
				{
					Match& match2 = candidates[m];
					int x = match2.x * 2 + 1;
					int y = match2.y * 2 + 1;
					x = std::max(x, border);
					y = std::max(y, border);
					x = std::min(x, max_x);
					y = std::min(y, max_y);
					int numFeatures = 0;
					{
						const Template& templ = tp[start];
						numFeatures += static_cast<int>(templ.features.size());
						if (templ.features.size() < 64)
						{
							similarityLocal_64(lms[0], templ, similarities2, size, T, cv::Point(x, y));
							similarities2.convertTo(similarities2, CV_16U);
						}
						else if (templ.features.size() < 8192)
						{
							similarityLocal(lms[0], templ, similarities2, size, T, cv::Point(x, y));
						}
					}
					float best_score = 0;
					int best_r = -1, best_c = -1;
					for (int r = 0; r < similarities2.rows; ++r)
					{
						ushort* row = similarities2.ptr<ushort>(r);
						for (int c = 0; c < similarities2.cols; ++c)
						{
							int score_int = row[c];
							float score = (score_int * 100.f) / (4 * numFeatures);
							if (score > best_score)
							{
								best_score = score;
								best_r = r;
								best_c = c;
							}
						}
					}
					match2.similarity = best_score;
					match2.x = (x / T - 8 + best_c) * T + offset;
					match2.y = (y / T - 8 + best_r) * T + offset;
				}
				std::vector<Match>::iterator new_end = std::remove_if(candidates.begin(), candidates.end(),
					MatchPredicate(score_buf));
				candidates.erase(new_end, candidates.end());
			}
			matches.insert(matches.end(), candidates.begin(), candidates.end());
			threshold = score_buf;
		}
	}

	int Detector::addTemplate(const cv::Mat source, const std::string& class_id,
		const cv::Mat& object_mask, int num_features)
	{
		std::vector<TemplatePyramid>& template_pyramids = class_templates[class_id];
		int template_id = static_cast<int>(template_pyramids.size());
		TemplatePyramid tp;
		tp.resize(pyramid_levels);
		{
			cv::Ptr<ColorGradientPyramid> qp = modality->process(source, object_mask);
			if (num_features > 0)
				qp->num_features = num_features;
			for (int l = 0; l < pyramid_levels; ++l)
			{
				if (l > 0)
					qp->pyrDown();
				bool success = qp->extractTemplate(tp[l]);
				if (!success)
					return -1;
			}
		}
		cropTemplates(tp);
		template_pyramids.push_back(tp);
		return template_id;
	}

	static cv::Point2f rotate2d(const cv::Point2f inPoint, const double angRad)
	{
		cv::Point2f outPoint;
		outPoint.x = std::cos(angRad) * inPoint.x - std::sin(angRad) * inPoint.y;
		outPoint.y = std::sin(angRad) * inPoint.x + std::cos(angRad) * inPoint.y;
		return outPoint;
	}

	static cv::Point2f rotatePoint(const cv::Point2f inPoint, const cv::Point2f center, const double angRad)
	{
		return rotate2d(inPoint - center, angRad) + center;
	}

	int Detector::addTemplate_rotate(const string& class_id, int zero_id,
		float theta, cv::Point2f center)
	{
		std::vector<TemplatePyramid>& template_pyramids = class_templates[class_id];
		int template_id = static_cast<int>(template_pyramids.size());
		const auto& to_rotate_tp = template_pyramids[zero_id];
		TemplatePyramid tp;
		tp.resize(pyramid_levels);
		for (int l = 0; l < pyramid_levels; ++l)
		{
			if (l > 0) center /= 2;
			for (auto& f : to_rotate_tp[l].features)
			{
				cv::Point2f p;
				p.x = f.x + to_rotate_tp[l].tl_x;
				p.y = f.y + to_rotate_tp[l].tl_y;
				cv::Point2f p_rot = rotatePoint(p, center, -theta / 180 * CV_PI);
				Feature f_new;
				f_new.x = int(p_rot.x + 0.5f);
				f_new.y = int(p_rot.y + 0.5f);
				f_new.theta = f.theta - theta;
				while (f_new.theta > 360) f_new.theta -= 360;
				while (f_new.theta < 0) f_new.theta += 360;
				f_new.label = int(f_new.theta * 16 / 360 + 0.5f);
				f_new.label &= 7;
				tp[l].features.push_back(f_new);
			}
			tp[l].pyramid_level = l;
		}
		cropTemplates(tp);
		template_pyramids.push_back(tp);
		return template_id;
	}

	const std::vector<Template>& Detector::getTemplates(const std::string& class_id, int template_id) const
	{
		TemplatesMap::const_iterator i = class_templates.find(class_id);
		CV_Assert(i != class_templates.end());
		CV_Assert(i->second.size() > size_t(template_id));
		return i->second[template_id];
	}

	int Detector::numTemplates() const
	{
		int ret = 0;
		TemplatesMap::const_iterator i = class_templates.begin(), iend = class_templates.end();
		for (; i != iend; ++i)
			ret += static_cast<int>(i->second.size());
		return ret;
	}

	int Detector::numTemplates(const std::string& class_id) const
	{
		TemplatesMap::const_iterator i = class_templates.find(class_id);
		if (i == class_templates.end())
			return 0;
		return static_cast<int>(i->second.size());
	}

	std::vector<std::string> Detector::classIds() const
	{
		std::vector<std::string> ids;
		TemplatesMap::const_iterator i = class_templates.begin(), iend = class_templates.end();
		for (; i != iend; ++i)
		{
			ids.push_back(i->first);
		}
		return ids;
	}

	void Detector::read(const cv::FileNode& fn)
	{
		class_templates.clear();
		pyramid_levels = fn["pyramid_levels"];
		fn["T"] >> T_at_level;
		modality = cv::makePtr<ColorGradient>();
	}

	void Detector::write(cv::FileStorage& fs) const
	{
		fs << "pyramid_levels" << pyramid_levels;
		fs << "T" << T_at_level;
		modality->write(fs);
	}

	std::string Detector::readClass(const cv::FileNode& fn, const std::string& class_id_override)
	{
		cv::String class_id;
		if (class_id_override.empty())
		{
			cv::String class_id_tmp = fn["class_id"];
			CV_Assert(class_templates.find(class_id_tmp) == class_templates.end());
			class_id = class_id_tmp;
		}
		else
		{
			class_id = class_id_override;
		}
		TemplatesMap::value_type v(class_id, std::vector<TemplatePyramid>());
		std::vector<TemplatePyramid>& tps = v.second;
		int expected_id = 0;
		cv::FileNode tps_fn = fn["template_pyramids"];
		tps.resize(tps_fn.size());
		cv::FileNodeIterator tps_it = tps_fn.begin(), tps_it_end = tps_fn.end();
		for (; tps_it != tps_it_end; ++tps_it, ++expected_id)
		{
			int template_id = (*tps_it)["template_id"];
			CV_Assert(template_id == expected_id);
			cv::FileNode templates_fn = (*tps_it)["templates"];
			tps[template_id].resize(templates_fn.size());
			cv::FileNodeIterator templ_it = templates_fn.begin(), templ_it_end = templates_fn.end();
			int idx = 0;
			for (; templ_it != templ_it_end; ++templ_it)
			{
				tps[template_id][idx++].read(*templ_it);
			}
		}
		class_templates.insert(v);
		return class_id;
	}

	void Detector::writeClass(const std::string& class_id, cv::FileStorage& fs) const
	{
		TemplatesMap::const_iterator it = class_templates.find(class_id);
		CV_Assert(it != class_templates.end());
		const std::vector<TemplatePyramid>& tps = it->second;
		fs << "class_id" << it->first;
		fs << "pyramid_levels" << pyramid_levels;
		fs << "template_pyramids"
			<< "[";
		for (size_t i = 0; i < tps.size(); ++i)
		{
			const TemplatePyramid& tp = tps[i];
			fs << "{";
			fs << "template_id" << int(i);
			fs << "templates"
				<< "[";
			for (size_t j = 0; j < tp.size(); ++j)
			{
				fs << "{";
				tp[j].write(fs);
				fs << "}";
			}
			fs << "]";
			fs << "}";
		}
		fs << "]";
	}

	void Detector::readClasses(const std::vector<std::string>& class_ids,
		const std::string& format)
	{
		for (size_t i = 0; i < class_ids.size(); ++i)
		{
			const cv::String& class_id = class_ids[i];
			cv::String filename = cv::format(format.c_str(), class_id.c_str());
			cv::FileStorage fs(filename, cv::FileStorage::READ);
			readClass(fs.root());
		}
	}

	void Detector::writeClasses(const std::string& format) const
	{
		TemplatesMap::const_iterator it = class_templates.begin(), it_end = class_templates.end();
		for (; it != it_end; ++it)
		{
			const cv::String& class_id = it->first;
			cv::String filename = cv::format(format.c_str(), class_id.c_str());
			cv::FileStorage fs(filename, cv::FileStorage::WRITE);
			writeClass(class_id, fs);
		}
	}
}
