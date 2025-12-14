#include"find_line.h"
using namespace std;
//降噪
cv::Mat	QF_blur(cv::Mat& src) {
	cv::Mat dst, edge, gray;
	//创建与src同类型和大小的矩阵(dst)
	dst.create(src.size(), src.type());

	// 将原图像转换为灰度图像
	//cvtColor(src, gray, CV_BGR2GRAY);

	//使用 3x3内核来降噪
	//cv::GaussianBlur
	blur(gray, edge, cv::Size(3, 3));
	return edge;

}
//计算梯度
cv::Mat QF_grad(cv::Mat& src) {
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y, dst;

	//求 X方向梯度
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1);
	convertScaleAbs(grad_x, abs_grad_x);

	//求Y方向梯度
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 1);
	convertScaleAbs(grad_y, abs_grad_y);

	//【5】合并梯度(近似)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	return dst;

}
//找边
void QF_LocateEdge(cv::Mat& Src /*, &dstV, pstart, pEnd, dir, thresh, flags*/) {

}
