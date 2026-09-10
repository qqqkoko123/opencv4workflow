#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif
#include "plate_engine.h"
#include <onnxruntime_cxx_api.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#endif
#include <QPainter>
#include <QFont>
#include <QImage>
#include <QFontMetrics>

namespace
{
static const std::vector<std::string> PLATE_COLOR = {
	"\xE9\xBB\x91\xE8\x89\xB2", "\xE8\x93\x9D\xE8\x89\xB2", "\xE7\xBB\xBF\xE8\x89\xB2", "\xE7\x99\xBD\xE8\x89\xB2", "\xE9\xBB\x84\xE8\x89\xB2"
};

static const std::vector<std::string> PLATE_CHR = {
	"\x23","\xE4\xBA\xAC","\xE6\xB2\xAA","\xE6\xB4\xA5","\xE6\xB8\x9D","\xE5\x86\x80","\xE6\x99\x8B","\xE8\x92\x99","\xE8\xBE\xBD","\xE5\x90\x89",
	"\xE9\xBB\x91","\xE8\x8B\x8F","\xE6\xB5\x99","\xE7\x9A\x96","\xE9\x97\xBD","\xE8\xB5\xA3","\xE9\xB2\x81","\xE8\xB1\xAB","\xE9\x84\x82","\xE6\xB9\x98",
	"\xE7\xB2\xA4","\xE6\xA1\x82","\xE7\x90\xBC","\xE5\xB7\x9D","\xE8\xB4\xB5","\xE4\xBA\x91","\xE8\x97\x8F","\xE9\x99\x95","\xE7\x94\x98","\xE9\x9D\x92",
	"\xE5\xAE\x81","\xE6\x96\xB0","\xE5\xAD\xA6","\xE8\xAD\xA6","\xE6\xB8\xAF","\xE6\xBE\xB3","\xE6\x8C\x82","\xE4\xBD\xBF","\xE9\xA2\x86","\xE6\xB0\x91",
	"\xE8\x88\xAA","\xE5\x8D\xB1","\x30","\x31","\x32","\x33","\x34","\x35","\x36","\x37",
	"\x38","\x39","\x41","\x42","\x43","\x44","\x45","\x46","\x47","\x48",
	"\x4A","\x4B","\x4C","\x4D","\x4E","\x50","\x51","\x52","\x53","\x54",
	"\x55","\x56","\x57","\x58","\x59","\x5A","\xE9\x99\xA9","\xE5\x93\x81"
};

constexpr float PLATE_MEAN = 0.588f;
constexpr float PLATE_STD = 0.193f;
constexpr int PLATE_INPUT_W = 168;
constexpr int PLATE_INPUT_H = 48;
constexpr int PLATE_NUM_CLASSES = 78;
constexpr int PLATE_COLOR_NUM = 5;
constexpr int DETECT_SIZE = 640;

struct PreParam
{
	float ratio = 1.0f;
	float dw = 0.0f;
	float dh = 0.0f;
	float height = 0.f;
	float width = 0.f;
};

inline float clampv(float val, float minv, float maxv)
{
	return val > minv ? (val < maxv ? val : maxv) : minv;
}

#ifdef _WIN32
std::wstring toWide(const std::string& s)
{
	if (s.empty()) return std::wstring();
	int n = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0);
	std::wstring w(n, 0);
	MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), &w[0], n);
	return w;
}
#endif

void softmax(float* data, int len)
{
	float max_val = *std::max_element(data, data + len);
	float sum = 0.f;
	for (int i = 0; i < len; ++i)
	{
		data[i] = std::exp(data[i] - max_val);
		sum += data[i];
	}
	if (sum <= 0.f) return;
	for (int i = 0; i < len; ++i) data[i] /= sum;
}

void decodePlate(const int* preds, int seq_len, std::vector<int>& out_indices, std::vector<int>& out_positions)
{
	int pre = 0;
	for (int i = 0; i < seq_len; ++i)
	{
		if (preds[i] != 0 && preds[i] != pre)
		{
			out_indices.push_back(preds[i]);
			out_positions.push_back(i);
		}
		pre = preds[i];
	}
}

cv::Mat fourPointTransform(const cv::Mat& src, const std::vector<float>& kps)
{
	if (kps.size() < 8) return cv::Mat();
	cv::Point2f tl(kps[0], kps[1]);
	cv::Point2f tr(kps[2], kps[3]);
	cv::Point2f br(kps[4], kps[5]);
	cv::Point2f bl(kps[6], kps[7]);

	float width_a = (float)cv::norm(br - bl);
	float width_b = (float)cv::norm(tr - tl);
	int max_width = (std::max)((int)width_a, (int)width_b);

	float height_a = (float)cv::norm(tr - br);
	float height_b = (float)cv::norm(tl - bl);
	int max_height = (std::max)((int)height_a, (int)height_b);
	if (max_width <= 0 || max_height <= 0) return cv::Mat();

	std::vector<cv::Point2f> src_pts = { tl, tr, br, bl };
	std::vector<cv::Point2f> dst_pts = {
		{0.f, 0.f},
		{(float)(max_width - 1), 0.f},
		{(float)(max_width - 1), (float)(max_height - 1)},
		{0.f, (float)(max_height - 1)}
	};
	cv::Mat M = cv::getPerspectiveTransform(src_pts, dst_pts);
	cv::Mat warped;
	cv::warpPerspective(src, warped, M, cv::Size(max_width, max_height));
	return warped;
}

cv::Mat getSplitMerge(const cv::Mat& img)
{
	int upper_h = (int)(5.0 / 12 * img.rows);
	int lower_y = (int)(1.0 / 3 * img.rows);
	int lower_h = img.rows - lower_y;
	if (upper_h <= 0 || lower_h <= 0 || img.cols <= 0) return img.clone();

	cv::Rect upper_rect(0, 0, img.cols, upper_h);
	cv::Rect lower_rect(0, lower_y, img.cols, lower_h);
	upper_rect &= cv::Rect(0, 0, img.cols, img.rows);
	lower_rect &= cv::Rect(0, 0, img.cols, img.rows);
	if (upper_rect.area() <= 0 || lower_rect.area() <= 0) return img.clone();

	cv::Mat img_upper = img(upper_rect).clone();
	cv::Mat img_lower = img(lower_rect).clone();
	cv::resize(img_upper, img_upper, img_lower.size());

	cv::Mat out(img_lower.rows, img_lower.cols + img_upper.cols, CV_8UC3, cv::Scalar(114, 114, 114));
	img_upper.copyTo(out(cv::Rect(0, 0, img_upper.cols, img_upper.rows)));
	img_lower.copyTo(out(cv::Rect(img_upper.cols, 0, img_lower.cols, img_lower.rows)));
	return out;
}

void letterbox(const cv::Mat& image, cv::Mat& nchw, PreParam& pparam, int inp_w, int inp_h)
{
	float height = (float)image.rows;
	float width = (float)image.cols;
	float r = (std::min)((float)inp_h / height, (float)inp_w / width);
	int padw = (int)std::round(width * r);
	int padh = (int)std::round(height * r);

	cv::Mat tmp;
	if ((int)width != padw || (int)height != padh)
		cv::resize(image, tmp, cv::Size(padw, padh));
	else
		tmp = image.clone();

	float dw = ((float)inp_w - padw) / 2.0f;
	float dh = ((float)inp_h - padh) / 2.0f;
	int top = (int)std::round(dh - 0.1f);
	int bottom = (int)std::round(dh + 0.1f);
	int left = (int)std::round(dw - 0.1f);
	int right = (int)std::round(dw + 0.1f);
	cv::copyMakeBorder(tmp, tmp, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(114, 114, 114));
	cv::dnn::blobFromImage(tmp, nchw, 1 / 255.f, cv::Size(), cv::Scalar(0, 0, 0), true, false, CV_32F);

	pparam.ratio = 1 / r;
	pparam.dw = dw;
	pparam.dh = dh;
	pparam.height = height;
	pparam.width = width;
}

void collectNames(Ort::Session* session, bool input, std::vector<std::string>& names, std::vector<const char*>& ptrs)
{
	names.clear();
	ptrs.clear();
	Ort::AllocatorWithDefaultOptions allocator;
	size_t n = input ? session->GetInputCount() : session->GetOutputCount();
	for (size_t i = 0; i < n; ++i)
	{
		Ort::AllocatedStringPtr p = input
			? session->GetInputNameAllocated(i, allocator)
			: session->GetOutputNameAllocated(i, allocator);
		names.emplace_back(p.get());
	}
	for (auto& s : names) ptrs.push_back(s.c_str());
}

QImage matToQImage(const cv::Mat& mat)
{
	if (mat.empty()) return QImage();
	cv::Mat rgb;
	if (mat.channels() == 1)
		cv::cvtColor(mat, rgb, cv::COLOR_GRAY2RGB);
	else if (mat.channels() == 4)
		cv::cvtColor(mat, rgb, cv::COLOR_BGRA2RGB);
	else
		cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
	QImage img(rgb.data, rgb.cols, rgb.rows, (int)rgb.step, QImage::Format_RGB888);
	return img.copy();
}

cv::Mat qImageToMat(const QImage& img)
{
	QImage c = img.convertToFormat(QImage::Format_RGB888);
	cv::Mat mat(c.height(), c.width(), CV_8UC3, (void*)c.bits(), c.bytesPerLine());
	cv::Mat bgr;
	cv::cvtColor(mat, bgr, cv::COLOR_RGB2BGR);
	return bgr.clone();
}
}

struct PlateEngine::Impl
{
	Ort::Env env{ ORT_LOGGING_LEVEL_ERROR, "PlateEngine" };
	Ort::SessionOptions det_opt;
	Ort::SessionOptions rec_opt;
	std::unique_ptr<Ort::Session> det_session;
	std::unique_ptr<Ort::Session> rec_session;
	std::vector<std::string> det_in_names, det_out_names, rec_in_names, rec_out_names;
	std::vector<const char*> det_in_ptrs, det_out_ptrs, rec_in_ptrs, rec_out_ptrs;
	std::string detect_path, rec_path;
	bool use_gpu = false;
	bool ready = false;
	std::string error;

	void setupOptions(Ort::SessionOptions& opt, bool gpu)
	{
		opt.SetIntraOpNumThreads(4);
		opt.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
		(void)gpu;
	}

	bool loadSession(std::unique_ptr<Ort::Session>& sess, Ort::SessionOptions& opt,
		const std::string& path, std::vector<std::string>& in_names, std::vector<std::string>& out_names,
		std::vector<const char*>& in_ptrs, std::vector<const char*>& out_ptrs)
	{
		std::ifstream f(path.c_str(), std::ios::binary);
		if (!f.good())
		{
			error = "cannot open model: " + path;
			return false;
		}
		f.close();
		try
		{
#ifdef _WIN32
			sess.reset(new Ort::Session(env, toWide(path).c_str(), opt));
#else
			sess.reset(new Ort::Session(env, path.c_str(), opt));
#endif
		}
		catch (const Ort::Exception& e)
		{
			error = std::string("load model failed: ") + e.what();
			return false;
		}
		collectNames(sess.get(), true, in_names, in_ptrs);
		collectNames(sess.get(), false, out_names, out_ptrs);
		return true;
	}

	std::vector<float> preprocessRec(const cv::Mat& image)
	{
		cv::Mat bgr;
		if (image.channels() == 1)
			cv::cvtColor(image, bgr, cv::COLOR_GRAY2BGR);
		else if (image.channels() == 4)
			cv::cvtColor(image, bgr, cv::COLOR_BGRA2BGR);
		else
			bgr = image;

		cv::Mat resized;
		int interp = (bgr.cols < PLATE_INPUT_W || bgr.rows < PLATE_INPUT_H) ? cv::INTER_CUBIC : cv::INTER_LINEAR;
		cv::resize(bgr, resized, cv::Size(PLATE_INPUT_W, PLATE_INPUT_H), 0, 0, interp);

		int channel_size = PLATE_INPUT_H * PLATE_INPUT_W;
		std::vector<float> data(3 * channel_size);
		for (int row = 0; row < PLATE_INPUT_H; ++row)
		{
			const uchar* uc_pixel = resized.data + row * resized.step;
			for (int col = 0; col < PLATE_INPUT_W; ++col)
			{
				int i = row * PLATE_INPUT_W + col;
				data[i] = ((float)uc_pixel[0] / 255.0f - PLATE_MEAN) / PLATE_STD;
				data[i + channel_size] = ((float)uc_pixel[1] / 255.0f - PLATE_MEAN) / PLATE_STD;
				data[i + 2 * channel_size] = ((float)uc_pixel[2] / 255.0f - PLATE_MEAN) / PLATE_STD;
				uc_pixel += 3;
			}
		}
		return data;
	}

	bool recognize(const cv::Mat& roi, std::string& plate, std::string& color, float& color_conf)
	{
		plate.clear();
		color.clear();
		color_conf = 0.f;
		if (!rec_session) return false;

		std::vector<float> data = preprocessRec(roi);
		std::array<int64_t, 4> shape{ 1, 3, PLATE_INPUT_H, PLATE_INPUT_W };
		Ort::MemoryInfo mem = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
		Ort::Value input_tensor = Ort::Value::CreateTensor<float>(mem, data.data(), data.size(), shape.data(), shape.size());

		auto outputs = rec_session->Run(Ort::RunOptions{ nullptr }, rec_in_ptrs.data(), &input_tensor, 1, rec_out_ptrs.data(), rec_out_ptrs.size());

		float* ocr_ptr = nullptr;
		float* color_ptr = nullptr;
		int seq_len = 21;
		for (size_t i = 0; i < outputs.size(); ++i)
		{
			auto info = outputs[i].GetTensorTypeAndShapeInfo();
			auto dims = info.GetShape();
			size_t sz = 1;
			for (auto d : dims) sz *= (d > 0 ? (size_t)d : 1);
			std::string name = (i < rec_out_names.size()) ? rec_out_names[i] : "";
			if (name == "ocr_output" || sz >= (size_t)(PLATE_NUM_CLASSES * 8))
			{
				ocr_ptr = outputs[i].GetTensorMutableData<float>();
				if (dims.size() >= 2)
				{
					int last = (int)dims.back();
					int prev = (int)dims[dims.size() - 2];
					if (last == PLATE_NUM_CLASSES) seq_len = prev;
					else if (prev == PLATE_NUM_CLASSES) seq_len = last;
				}
			}
			else if (name == "color_output" || sz == (size_t)PLATE_COLOR_NUM)
			{
				color_ptr = outputs[i].GetTensorMutableData<float>();
			}
		}
		if (!ocr_ptr && !outputs.empty())
			ocr_ptr = outputs[0].GetTensorMutableData<float>();
		if (!ocr_ptr) return false;

		std::vector<int> argmax_seq(seq_len);
		std::vector<float> max_probs(seq_len);
		for (int t = 0; t < seq_len; ++t)
		{
			std::vector<float> row(ocr_ptr + t * PLATE_NUM_CLASSES, ocr_ptr + t * PLATE_NUM_CLASSES + PLATE_NUM_CLASSES);
			int best_idx = (int)(std::max_element(row.begin(), row.end()) - row.begin());
			argmax_seq[t] = best_idx;
			softmax(row.data(), PLATE_NUM_CLASSES);
			max_probs[t] = row[best_idx];
		}

		std::vector<int> char_indices, char_positions;
		decodePlate(argmax_seq.data(), seq_len, char_indices, char_positions);
		for (int idx : char_indices)
		{
			if (idx >= 0 && idx < (int)PLATE_CHR.size())
				plate += PLATE_CHR[idx];
		}

		if (color_ptr)
		{
			int best_color = (int)(std::max_element(color_ptr, color_ptr + PLATE_COLOR_NUM) - color_ptr);
			std::vector<float> color_vec(color_ptr, color_ptr + PLATE_COLOR_NUM);
			softmax(color_vec.data(), PLATE_COLOR_NUM);
			if (best_color >= 0 && best_color < (int)PLATE_COLOR.size())
				color = PLATE_COLOR[best_color];
			color_conf = color_vec[best_color];
		}
		return !plate.empty();
	}
};

PlateEngine::PlateEngine() : d(new Impl) {}
PlateEngine::~PlateEngine() = default;

bool PlateEngine::init(const std::string& detect_model, const std::string& rec_model, bool use_gpu)
{
	d->ready = false;
	d->error.clear();
	d->detect_path = detect_model;
	d->rec_path = rec_model;
	d->use_gpu = use_gpu;
	d->det_session.reset();
	d->rec_session.reset();
	d->det_opt = Ort::SessionOptions();
	d->rec_opt = Ort::SessionOptions();
	d->setupOptions(d->det_opt, use_gpu);
	d->setupOptions(d->rec_opt, use_gpu);
	if (!d->loadSession(d->det_session, d->det_opt, detect_model, d->det_in_names, d->det_out_names, d->det_in_ptrs, d->det_out_ptrs))
		return false;
	if (!d->loadSession(d->rec_session, d->rec_opt, rec_model, d->rec_in_names, d->rec_out_names, d->rec_in_ptrs, d->rec_out_ptrs))
		return false;
	d->ready = true;
	return true;
}

bool PlateEngine::isReady() const { return d && d->ready; }
std::string PlateEngine::lastError() const { return d ? d->error : std::string("engine null"); }

std::vector<PlateDet> PlateEngine::infer(const cv::Mat& image, float score_thres)
{
	std::vector<PlateDet> results;
	if (!isReady() || image.empty() || !d->det_session) return results;

	cv::Mat bgr;
	if (image.channels() == 1)
		cv::cvtColor(image, bgr, cv::COLOR_GRAY2BGR);
	else if (image.channels() == 4)
		cv::cvtColor(image, bgr, cv::COLOR_BGRA2BGR);
	else
		bgr = image;

	PreParam pparam;
	cv::Mat nchw;
	letterbox(bgr, nchw, pparam, DETECT_SIZE, DETECT_SIZE);

	std::array<int64_t, 4> shape{ 1, 3, DETECT_SIZE, DETECT_SIZE };
	Ort::MemoryInfo mem = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
	Ort::Value input_tensor = Ort::Value::CreateTensor<float>(mem, nchw.ptr<float>(), nchw.total(), shape.data(), shape.size());

	auto outputs = d->det_session->Run(Ort::RunOptions{ nullptr }, d->det_in_ptrs.data(), &input_tensor, 1, d->det_out_ptrs.data(), d->det_out_ptrs.size());
	if (outputs.empty()) return results;

	auto info = outputs[0].GetTensorTypeAndShapeInfo();
	auto dims = info.GetShape();
	const float* ptr = outputs[0].GetTensorData<float>();
	int max_det = 300;
	int stride = 14;
	bool end2end = false;
	if (dims.size() == 3)
	{
		if (dims[2] == 14) { max_det = (int)dims[1]; stride = 14; end2end = true; }
		else if (dims[1] == 14) { max_det = (int)dims[2]; stride = 14; end2end = true; }
	}

	if (end2end)
	{
		bool trans = (dims.size() == 3 && dims[1] == 14);
		for (int i = 0; i < max_det; ++i)
		{
			const float* p;
			float buf[14];
			if (trans)
			{
				for (int k = 0; k < 14; ++k) buf[k] = ptr[k * max_det + i];
				p = buf;
			}
			else
			{
				p = ptr + i * stride;
			}
			float conf = p[4];
			if (conf < score_thres) continue;
			float x0 = clampv((p[0] - pparam.dw) * pparam.ratio, 0.f, pparam.width);
			float y0 = clampv((p[1] - pparam.dh) * pparam.ratio, 0.f, pparam.height);
			float x1 = clampv((p[2] - pparam.dw) * pparam.ratio, 0.f, pparam.width);
			float y1 = clampv((p[3] - pparam.dh) * pparam.ratio, 0.f, pparam.height);
			if (x0 >= x1 || y0 >= y1) continue;
			std::vector<float> kps(8);
			for (int k = 0; k < 4; ++k)
			{
				kps[2 * k] = clampv((p[6 + 2 * k] - pparam.dw) * pparam.ratio, 0.f, pparam.width);
				kps[2 * k + 1] = clampv((p[6 + 2 * k + 1] - pparam.dh) * pparam.ratio, 0.f, pparam.height);
			}
			PlateDet det;
			det.bbox = cv::Rect_<float>(x0, y0, x1 - x0, y1 - y0);
			det.confidence = conf;
			det.plate_type = (int)p[5];
			det.key_points = kps;
			results.push_back(det);
		}
	}

	for (auto& det : results)
	{
		cv::Mat roi;
		if (det.key_points.size() >= 8)
			roi = fourPointTransform(bgr, det.key_points);
		if (roi.empty())
		{
			cv::Rect rect((int)det.bbox.x, (int)det.bbox.y, (int)det.bbox.width, (int)det.bbox.height);
			rect &= cv::Rect(0, 0, bgr.cols, bgr.rows);
			if (rect.area() <= 0) continue;
			roi = bgr(rect).clone();
		}
		if (roi.empty()) continue;
		if (det.plate_type == 1)
			roi = getSplitMerge(roi);
		d->recognize(roi, det.plate_license, det.plate_color, det.color_conf);
	}
	return results;
}

void PlateEngine::drawResults(cv::Mat& image, const std::vector<PlateDet>& dets) const
{
	if (image.empty()) return;
	cv::Mat bgr;
	if (image.channels() == 1)
		cv::cvtColor(image, bgr, cv::COLOR_GRAY2BGR);
	else if (image.channels() == 4)
		cv::cvtColor(image, bgr, cv::COLOR_BGRA2BGR);
	else
		bgr = image;

	static cv::Scalar kp_colors[4] = {
		cv::Scalar(0, 255, 255), cv::Scalar(0, 0, 255),
		cv::Scalar(0, 255, 0), cv::Scalar(255, 0, 255)
	};
	for (const auto& d : dets)
	{
		int x1 = (int)d.bbox.x;
		int y1 = (int)d.bbox.y;
		int x2 = (int)(d.bbox.x + d.bbox.width);
		int y2 = (int)(d.bbox.y + d.bbox.height);
		cv::rectangle(bgr, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(255, 0, 0), 2);
		for (int k = 0; k < 4 && k * 2 + 1 < (int)d.key_points.size(); ++k)
		{
			int kx = (int)std::round(d.key_points[2 * k]);
			int ky = (int)std::round(d.key_points[2 * k + 1]);
			cv::circle(bgr, cv::Point(kx, ky), 4, kp_colors[k], -1);
		}
	}

	QImage qimg = matToQImage(bgr);
	QPainter painter(&qimg);
	painter.setRenderHint(QPainter::Antialiasing);
	QFont font("Microsoft YaHei", 14);
	painter.setFont(font);
	for (const auto& d : dets)
	{
		QString label = QString::fromUtf8(d.plate_license.c_str());
		if (!d.plate_color.empty())
			label += " " + QString::fromUtf8(d.plate_color.c_str());
		if (d.plate_type == 1) label += QString::fromUtf8(" \xE5\x8F\x8C\xE5\xB1\x82");
		int x1 = (int)d.bbox.x;
		int y1 = (int)d.bbox.y;
		QFontMetrics fm(font);
		QRect br = fm.boundingRect(label);
		int bg_y = y1 - br.height() - 8;
		if (bg_y < 0) bg_y = y1 + 2;
		QRect bg(x1, bg_y, br.width() + 8, br.height() + 6);
		painter.fillRect(bg, QColor(255, 255, 255));
		painter.setPen(QColor(0, 0, 0));
		painter.drawText(bg.adjusted(4, 0, 0, 0), Qt::AlignVCenter | Qt::AlignLeft, label);
	}
	painter.end();
	image = qImageToMat(qimg);
}
