#pragma once
#include<opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace cv;
//找边
void fitLineRansac(const std::vector<cv::Point2f>& points,
	cv::Vec4f& line, int iterations, double sigma,
	double k_min, double k_max);
//RANSAC 拟合2D 直线
//输入参数：points--输入点集
//        iterations--迭代次数
//        sigma--数据和模型之间可接受的差值,车道线像素宽带一般为10左右
//              （Parameter use to compute the fitting score）
//        k_min/k_max--拟合的直线斜率的取值范围.
//                     考虑到左右车道线在图像中的斜率位于一定范围内，
//                      添加此参数，同时可以避免检测垂线和水平线
//输出参数:line--拟合的直线参数,(vx, vy, x0, y0) 
// (vx, vy) 直线方向,(x0, y0)直线点集

//改进的canny边缘识别算子
void cannyEdgeDetection(cv::Mat img, cv::Mat& result, int guaSize, 
	double hightThres, double lowThres);
