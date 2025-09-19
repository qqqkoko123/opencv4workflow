#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
//using namespace cv;
//图像四则运算
cv::Mat add(cv::Mat img1, cv::Mat img2);//加add
cv::Mat sub(cv::Mat img1, cv::Mat img2);//减substract
cv::Mat div(cv::Mat img1, cv::Mat img2);//除divide
cv::Mat mul(cv::Mat img1, cv::Mat img2);//乘multiply
//读取
cv::Mat QF_ReadImage(const cv::String& path, int flag = 1);
//保存
void QF_WriteImage(const cv::String& filename, const cv::Mat& src);
//显示 
//flag 0表示CV_WINDOW_NORMAL可自由调节大小，1表示WINDOW_AUTOSIZE不可调节大小
void QF_ShowImage(const cv::Mat& src, const cv::String winName, int flag = 1);
//画线
void QF_drawline(const cv::Mat& src, cv::Point pt1, cv::Point pt2,
	const cv::Scalar& color, int thickness);
//画矩形
void QF_DrawRectangle(const cv::Mat& src, cv::Rect rect,
	cv::Scalar& color, int thickness);

////画圆
void QF_DrawCircle(const cv::Mat& src, cv::Point center,
	int radius, cv::Scalar color, int Thickness);
//椭圆  cv里没有椭圆函数
void QF_drawEllipse(const cv::Mat& src);
//绘制箭头
void QF_DrawArrow(const cv::Mat& src, cv::Point p1, cv::Point p2,
	const cv::Scalar color, int thickness);
//文字
void QF_DrawText(cv::Mat& src, // 待绘制的图像
	const cv::String& text, // 待绘制的文字
	cv::Point origin, // 文本框的左下角
	int fontFace, // 字体 (如cv::FONT_HERSHEY_PLAIN)
	double fontScale, // 尺寸因子，值越大文字越大
	cv::Scalar color, // 线条的颜色（BGR）
	int thickness);
//创建图像
cv::Mat QF_CreateImage(int rows, int cols, int PixelType);
//复制与移动图像
cv::Mat QF_CopyImage(cv::Mat& src, int x/*x的偏移量*/, int y/*y的偏移量*/);
//仿射变换
void QF_WarpAffine(cv::Mat& src, cv::Mat& dst, cv::Mat& matrix, cv::Size dsize);
//求仿射矩阵 返回一个2*3的矩阵用于warpaffine 需要两组三个点
cv::Mat QF_GetAffineTransformation(const cv::Point2f* src, const cv::Point2f* dst);
//求透视变换矩阵 需要两组四个点
cv::Mat QF_GetPerspectiveTransformation(const cv::Point2f* src, const cv::Point2f* dst);
//透视变换
void QF_WarpPerspective(cv::Mat& src, cv::Mat& dst, cv::Mat& matrix);
