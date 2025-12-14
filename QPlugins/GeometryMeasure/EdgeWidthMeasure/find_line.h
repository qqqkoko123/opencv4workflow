#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
//找边算子find_line.h
// 降噪
cv::Mat	QF_blur(cv::Mat& src);
//计算梯度
cv::Mat QF_grad(cv::Mat& src);
void QF_LocateEdge(cv::Mat& Src /*, &dstV, pstart, pEnd, dir, thresh, flags*/);

class FindLine {
	//计算图像梯度

};