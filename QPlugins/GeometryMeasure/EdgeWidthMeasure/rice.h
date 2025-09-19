
#include <opencv2/opencv.hpp>
#include <QtCore/qglobal.h>

    std::vector<int> on_btnStart(cv::Mat& frame, int thereshold, bool autothereshold, cv::Mat& dstImage);
    int count(qreal& aver_area, int thereshold, bool autothereshold);//米粒计数
    int defectAnalysis(cv::Mat& result_img, qreal aver_area);
    