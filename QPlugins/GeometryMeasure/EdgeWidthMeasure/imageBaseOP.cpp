#include"imageBaseOP.h"
//using namespace cv;
using namespace std;
//四则运算
cv::Mat add(cv::Mat img1, cv::Mat img2)//加add
{
	cv::Mat dst;
	cv::add(img1, img2, dst);
	return dst;
}
cv::Mat sub(cv::Mat img1, cv::Mat img2)//减subtract
{
	cv::Mat dst;
	cv::subtract(img1, img2, dst);
	return dst;
}
cv::Mat div(cv::Mat img1, cv::Mat img2)//除divide
{
	cv::Mat dst;
	cv::divide(img1, img2, dst);
	return dst;
}
cv::Mat mul(cv::Mat img1, cv::Mat img2)//乘multiply
{
	cv::Mat dst;
	cv::multiply(img1, img2, dst);
	return dst;
}
//读取图像
cv::Mat QF_ReadImage(const cv::String& path, int flag )
{
	
	try {
		cv::Mat dst = cv::imread(path, flag);
		if (dst.rows == 0 && dst.cols == 0) throw 1;
		return dst;
	}
	catch (int) {
		std::cout << "\033[31m invalid path of the input image \033[0m" << std::endl;
	}
	
	//if 
	/*flags > 0 三通道的彩色图像
	​flags = 0 灰度图像
	​flags < 0 不作改变也可以有以下的枚举值
	​CV_LOAD_IMAGE_ANYDEPTH、
	​CV_LOAD_IMAGE_COLOR、
	​CV_LOAD_IMAGE_GRAYSCALE*/
	
}
//保存图像
void QF_WriteImage(const cv::String& filename, const cv::Mat& src)
{
	imwrite(filename, src);
}
//显示图像
//flag 0表示CV_WINDOW_NORMAL可自由调节大小，1表示WINDOW_AUTOSIZE不可调节大小
void QF_ShowImage(const cv::Mat& src, const cv::String winName, int flag)
{
	cv::namedWindow(winName, flag);
	imshow(winName, src);
	cv::waitKey(0);
	//destroyWindow(winName);
}
//画线
void QF_drawline(const cv::Mat& src, cv::Point pt1, cv::Point pt2,
	const cv::Scalar& color, int thickness)
{
	line(src, pt1, pt2, color, thickness);
}
//画矩形
void QF_DrawRectangle(const cv::Mat& src, cv::Rect rect,
	cv::Scalar& color, int thickness)
{
	rectangle(src, rect, color, thickness);
}
//画圆
void QF_DrawCircle(const cv::Mat& src, cv::Point center,
	int radius, cv::Scalar color, int Thickness)
{
	cv::circle(src, center, radius, color, Thickness);
}
//绘制箭头
void QF_DrawArrow(const cv::Mat& src, cv::Point p1, cv::Point p2,
	const cv::Scalar color, int thickness)
{
	cv::arrowedLine(src, p1, p2, color, thickness);
}
//绘制文字
void QF_DrawText(cv::Mat& src, // 待绘制的图像
	const cv::String& text, // 待绘制的文字
	cv::Point origin, // 文本框的左下角
	int fontFace, // 字体 (如cv::FONT_HERSHEY_PLAIN)
	double fontScale, // 尺寸因子，值越大文字越大
	cv::Scalar color, // 线条的颜色（BGR）
	int thickness)// 线条宽度
{
	cv::putText(src, text, origin, fontFace, fontScale, thickness);
}
//创建图像
cv::Mat QF_CreateImage(int rows, int cols, int PixelType)
{
	cv::Mat img(rows, cols, PixelType);
	return img;
}
//复制与移动图像
cv::Mat QF_CopyImage(cv::Mat& src, int x/*x的偏移量*/, int y/*y的偏移量*/)
{
	cv::Mat dst = src.clone();//深拷贝
	cv::Size dst_size = dst.size();
	//平移矩阵
	cv::Mat t_mat = cv::Mat::zeros(2, 3, CV_32FC1);
	t_mat.at<float>(0, 0) = 1;
	t_mat.at<float>(0, 2) = x; //水平平移量
	t_mat.at<float>(1, 1) = 1;
	t_mat.at<float>(1, 2) = y; //竖直平移量

	cv::warpAffine(src, dst, t_mat, dst_size);
	return dst;
}
//仿射变换
void QF_WarpAffine(cv::Mat& src, cv::Mat& dst, cv::Mat& matrix, cv::Size dsize)
{
	warpAffine(src, dst, matrix, dsize);
}
//求仿射矩阵
cv::Mat QF_GetAffineTransformation(const cv::Point2f* src, const cv::Point2f* dst)
{
	cv::Mat matrix = cv::getAffineTransform(src, dst);
	return matrix;
}
//求透视变换矩阵 需要两组四个点
cv::Mat QF_GetPerspectiveTransformation(const cv::Point2f* src, const cv::Point2f* dst)
{
	cv::Mat m = cv::getPerspectiveTransform(src, dst);
	return m;
}
//透视变换
void QF_WarpPerspective(cv::Mat& src, cv::Mat& dst, cv::Mat& matrix)
{
	cv::perspectiveTransform(src, dst, matrix);
}
