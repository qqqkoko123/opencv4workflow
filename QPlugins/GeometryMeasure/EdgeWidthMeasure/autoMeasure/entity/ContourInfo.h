/**
 * Created by Jiajun Chen on 2022/1/9.
 */


#include <vector>
#include <opencv2/core/types.hpp>
#ifndef QT_OBJECT_MEASURE_CONTOURINFO_H
#define QT_OBJECT_MEASURE_CONTOURINFO_H

struct ContourInfo
{
    std::vector<cv::Point> finalContours;
    int area;
    std::vector<cv::Point> apex;
    ContourInfo(std::vector<cv::Point> finalContours,int area,std::vector<cv::Point> apex):
            finalContours(std::move(finalContours)),
            area(area),
            apex(std::move(apex)){}
};

#endif
