#include "rice.h"
#include <vector>
#include <QMessageBox>
#include <QtCore/qglobal.h>

using namespace std;
cv::Mat gray_img = cv::Mat();//灰度图
std::vector<std::vector<cv::Point>> rice_pionts;//所有米粒
/* 米粒计数函数 */
int count(qreal& aver_area, int thereshold, bool autothereshold)
{
    int value = thereshold;//获取设定的阈值
    rice_pionts.resize(0);//将米粒数重置为0
    cv::Mat bin_img = cv::Mat();
    if(autothereshold) //假如阈值是自动调整的
    {
        value = cv::threshold(gray_img, bin_img, 0, 255, cv::THRESH_OTSU); //使用大津法来调整阈值，二值化
    }
    else //假如阈值是手动调整的
    {
        cv::threshold(gray_img, bin_img, value, 255, cv::THRESH_BINARY); //按照设定的值，二值化
    }
    //为下面的形态学开操作准备一个结构元素
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::morphologyEx(bin_img, bin_img, cv::MORPH_OPEN, element);//执行形态学开操作
    std::vector<std::vector<cv::Point>> contours;//存放找到的所有闭形区域（可能的米粒）
    cv::findContours(bin_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);//寻找图像中闭形区域
    aver_area = 0;//重置平均面积为零，此变量是为了下一步缺陷分析准备
    for(const auto &cont : contours)//遍历所有闭形区域
    {
        qreal area = cv::contourArea(cont);//得到闭形区域面积
        if(area > 100)//面积大于100
        {
            aver_area += area;
            rice_pionts.push_back(cont);//则是米粒，放入存放米粒的vector中
        }
    }
    aver_area = aver_area / rice_pionts.size();//计算平均面积
    return rice_pionts.size();//返回米粒个数
}

/* 缺陷分析函数 */
int defectAnalysis(cv::Mat &result_img, qreal aver_area)
{
    size_t i = 0, good_rice = 0;
    for(const auto &rp : rice_pionts)//遍历所有米粒
    {
        cv::Scalar color;
        cv::String text;
        cv::Point pre_point = rp.front();//得到该米粒的坐标
        cv::Point2f potf[4];
        cv::RotatedRect rrt(cv::minAreaRect(rp));//求该米粒的最小外接矩形
        //得到矩形的最长边和最小边的比值
        qreal rate = (rrt.size.width > rrt.size.height) ? (rrt.size.width / rrt.size.height) :
                     (rrt.size.height / rrt.size.width);
        //当面积小于平均面积的0.75或比值小于1.58，则认为有缺陷
        if(rate < 1.58 || (cv::contourArea(rp) < (aver_area * 0.75)))
            color = cv::Scalar(0, 0, 255);//将米粒的轮廓设置为红色
        else//否则，认为无缺陷
        {
            ++good_rice;//无缺陷米计数增1
            color = cv::Scalar(0, 255, 0);//将米粒的轮廓设置为绿色
        }
        rrt.points(potf);//得到矩形的四个顶点
        /* 画出矩形，线条粗细设置为2 */
        cv::line(result_img, potf[0], potf[1], color, 2);
        cv::line(result_img, potf[1], potf[2], color, 2);
        cv::line(result_img, potf[2], potf[3], color, 2);
        cv::line(result_img, potf[3], potf[0], color, 2);
        //标明米粒的序号
        cv::putText(result_img, std::to_string(++i), pre_point, cv::FONT_HERSHEY_COMPLEX, 0.6, color, 2);
    }
    return good_rice;//返回无缺陷米的数量
}

/* 槽函数，点击计数按钮开始技术及缺陷分析 */
std::vector<int> on_btnStart(cv::Mat& frame, int thereshold, bool autothereshold, cv::Mat& dstImage)
{
    std::vector<int> result = { 0, 0, 0 };
    qreal aver_area;
    cv::Mat result_img = frame.clone();//得到一份原图的副本，在其上绘制结果
    cv::cvtColor(frame, gray_img, cv::COLOR_RGB2GRAY);//将图像转换为灰度，位米粒计数作准备
    int total_rice = count(aver_area,thereshold,autothereshold);//得到全部米粒数
    //进行缺陷分析，得到结果图和无缺陷米的数量
    int good_rice = defectAnalysis(result_img, aver_area);
    
	result[0] = total_rice;
	result[1] = good_rice;
	result[2] = total_rice - good_rice;
	dstImage = result_img;
	return result;
}
