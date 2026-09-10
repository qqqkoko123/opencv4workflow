#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <memory>

struct PlateDet
{
	cv::Rect_<float> bbox;
	float confidence = 0.f;
	int plate_type = 0; // 0=single 1=double
	std::vector<float> key_points;
	std::string plate_license;
	std::string plate_color;
	float color_conf = 0.f;
};

class PlateEngine
{
public:
	PlateEngine();
	~PlateEngine();

	bool init(const std::string& detect_model, const std::string& rec_model, bool use_gpu);
	bool isReady() const;
	std::string lastError() const;

	std::vector<PlateDet> infer(const cv::Mat& image, float score_thres = 0.25f);

	void drawResults(cv::Mat& image, const std::vector<PlateDet>& dets) const;

private:
	struct Impl;
	std::unique_ptr<Impl> d;
};
