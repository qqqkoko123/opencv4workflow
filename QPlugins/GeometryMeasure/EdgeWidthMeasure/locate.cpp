#include"locate.h"
#include<vector>
#include"imageBaseOP.h"
#define pi 3.14159
#define CV_SORT_EVERY_ROW    0
#define CV_SORT_EVERY_COLUMN 1
#define CV_SORT_ASCENDING    0
#define CV_SORT_DESCENDING   16

using namespace std;

//改进的canny边缘识别算子
void cannyEdgeDetection(cv::Mat img, cv::Mat& result,int guaSize,
    double hightThres, double lowThres) 
{
    // 中值滤波
    cv::Rect rect; // IOU区域
    cv::Mat filterImg = cv::Mat::zeros(img.rows, img.cols, CV_64FC1);
    img.convertTo(img, CV_64FC1);
    result = cv::Mat::zeros(img.rows, img.cols, CV_64FC1);
    int guassCenter = guaSize / 2; // 高斯核的中心 // (2* guassKernelSize +1) * (2*guassKernelSize+1)高斯核大小
    double sigma = 1;   // 方差大小
    cv::Mat guassKernel = cv::Mat::zeros(guaSize, guaSize, CV_64FC1);
    for (int i = 0; i < guaSize; i++) {
        for (int j = 0; j < guaSize; j++) {
            guassKernel.at<double>(i, j) = (1.0 / (2.0 * pi * sigma * sigma)) *
                (double)exp(-(((double)pow((i - (guassCenter + 1)), 2) + (double)pow((j - (guassCenter + 1)), 2)) / (2.0 * sigma * sigma)));
            // std::cout<<guassKernel.at<double>(i, j) << " ";
        }
        // std::cout<<std::endl;
    }
    cv::Scalar sumValueScalar = cv::sum(guassKernel);
    double sum = sumValueScalar.val[0];
    guassKernel = guassKernel / sum;
 
    for (int i = guassCenter; i < img.rows - guassCenter; i++) {
        for (int j = guassCenter; j < img.cols - guassCenter; j++) {
            rect.x = j - guassCenter;
            rect.y = i - guassCenter;
            rect.width = guaSize;
            rect.height = guaSize;
            filterImg.at<double>(i, j) = cv::sum(guassKernel.mul(img(rect))).val[0];
            // std::cout<<filterImg.at<double>(i,j) << " ";
        }
        // std::cout<<std::endl;
    }
    cv::Mat guassResult;
    filterImg.convertTo(guassResult, CV_8UC1);
    // 计算梯度,用sobel算子
    cv::Mat gradX = cv::Mat::zeros(img.rows, img.cols, CV_64FC1); // 水平梯度
    cv::Mat gradY = cv::Mat::zeros(img.rows, img.cols, CV_64FC1); // 垂直梯度
    cv::Mat grad = cv::Mat::zeros(img.rows, img.cols, CV_64FC1);  // 梯度幅值
    cv::Mat thead = cv::Mat::zeros(img.rows, img.cols, CV_64FC1); // 梯度角度
    cv::Mat locateGrad = cv::Mat::zeros(img.rows, img.cols, CV_64FC1); //区域
    // x方向的sobel算子
    cv::Mat Sx = (cv::Mat_<double>(3, 3) << -1, 0, 1,
                                            -2, 0, 2,
                                            -1, 0, 1);
                                            
    // y方向sobel算子
    cv::Mat Sy = (cv::Mat_<double>(3, 3) << 1, 2, 1,
                                            0, 0, 0,
                                            -1, -2, -1);
    // 计算梯度赋值和角度
    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            // 卷积区域 3*3
            rect.x = j - 1;
            rect.y = i - 1;
            rect.width = 3;
            rect.height = 3;
            cv::Mat rectImg = cv::Mat::zeros(3, 3, CV_64FC1);
            filterImg(rect).copyTo(rectImg);
            // 梯度和角度
            gradX.at<double>(i, j) += cv::sum(rectImg.mul(Sx)).val[0];
            gradY.at<double>(i, j) += cv::sum(rectImg.mul(Sy)).val[0];
            grad.at<double>(i, j) = sqrt(pow(gradX.at<double>(i, j), 2) + pow(gradY.at<double>(i, j), 2));
            thead.at<double>(i, j) = atan(gradY.at<double>(i, j) / gradX.at<double>(i, j));
            // 设置四个区域
            if (0 <= thead.at<double>(i, j) <= (pi / 4.0)) {
                locateGrad.at<double>(i, j) = 0;
            }
            else if (pi / 4.0 < thead.at<double>(i, j) <= (pi / 2.0)) {
                locateGrad.at<double>(i, j) = 1;
            }
            else if (-pi / 2.0 <= thead.at<double>(i, j) <= (-pi / 4.0)) {
                locateGrad.at<double>(i, j) = 2;
            }
            else if (-pi / 4.0 < thead.at<double>(i, j) < 0) {
                locateGrad.at<double>(i, j) = 3;
            }
        }
    }
    // 梯度归一化
    double gradMax;
    cv::minMaxLoc(grad, &gradMax); // 求最大值
    if (gradMax != 0) {
        grad = grad / gradMax;
    }
    // debug
    cv::Mat tempGradN;
    grad.convertTo(tempGradN, CV_8UC1);
    imshow("gradN", tempGradN);

    // 双阈值确定
    cv::Mat caculateValue = cv::Mat::zeros(img.rows, img.cols, CV_64FC1); // grad变成一维
    cv::resize(grad, caculateValue, cv::Size(1, (grad.rows * grad.cols)));
    // caculateValue.convertTo(caculateValue, CV_64FC1);
    cv::sort(caculateValue, caculateValue, CV_SORT_EVERY_COLUMN + CV_SORT_ASCENDING); // 升序
    long long highIndex = img.rows * img.cols * hightThres;
    double highValue = caculateValue.at<double>(highIndex, 0); // 最大阈值
    // debug
    // std::cout<< "highValue: "<<highValue<<" "<<  caculateValue.cols << " "<<highIndex<< std::endl;

    double lowValue = highValue * lowThres; // 最小阈值
    // 3.非极大值抑制， 采用线性插值
    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            // 八个方位
            double N = grad.at<double>(i - 1, j);
            double NE = grad.at<double>(i - 1, j + 1);
            double E = grad.at<double>(i, j + 1);
            double SE = grad.at<double>(i + 1, j + 1);
            double S = grad.at<double>(i + 1, j);
            double SW = grad.at<double>(i - 1, j - 1);
            double W = grad.at<double>(i, j - 1);
            double NW = grad.at<double>(i - 1, j - 1);
            // 区域判断，线性插值处理
            double tanThead; // tan角度
            double Gp1; // 两个方向的梯度强度
            double Gp2;
            // 求角度，绝对值
            tanThead = abs(tan(thead.at<double>(i, j)));
            switch ((int)locateGrad.at<double>(i, j)) {
            case 0:
                Gp1 = (1 - tanThead) * E + tanThead * NE;
                Gp2 = (1 - tanThead) * W + tanThead * SW;
                break;
            case 1:
                Gp1 = (1 - tanThead) * N + tanThead * NE;
                Gp2 = (1 - tanThead) * S + tanThead * SW;
                break;
            case 2:
                Gp1 = (1 - tanThead) * N + tanThead * NW;
                Gp2 = (1 - tanThead) * S + tanThead * SE;
                break;
            case 3:
                Gp1 = (1 - tanThead) * W + tanThead * NW;
                Gp2 = (1 - tanThead) * E + tanThead * SE;
                break;
            default:
                break;
            }
            // NMS -非极大值抑制和双阈值检测
            if (grad.at<double>(i, j) >= Gp1 && grad.at<double>(i, j) >= Gp2) {
                //双阈值检测
                if (grad.at<double>(i, j) >= highValue) {
                    grad.at<double>(i, j) = highValue;
                    result.at<double>(i, j) = 255;
                }
                else if (grad.at<double>(i, j) < lowValue) {
                    grad.at<double>(i, j) = 0;
                }
                else {
                    grad.at<double>(i, j) = lowValue;
                }

            }
            else {
                grad.at<double>(i, j) = 0;
            }
        }
    }
    // NMS 和算阈值检测后的梯度图
    cv::Mat tempGradNMS;
    grad.convertTo(tempGradNMS, CV_8UC1);
    imshow("gradNMS", tempGradNMS);

    // 4.抑制孤立低阈值点 3*3. 找到高阈值就255
    for (int i = 1; i < img.rows - 1; i++) {
        for (int j = 1; j < img.cols - 1; j++) {
            if (grad.at<double>(i, j) == lowValue) {
                // 3*3区域找强梯度
                rect.x = j - 1;
                rect.y = i - 1;
                rect.width = 3;
                rect.height = 3;
                for (int i1 = 0; i1 < 3; i1++) {
                    for (int j1 = 0; j1 < 3; j1++) {
                        if (grad(rect).at<double>(i1, j1) == highValue) {
                            result.at<double>(i, j) = 255;
                            std::cout << result.at<double>(i, j);
                            break;
                        }
                    }
                }
            }
        }
    }
    // 结果
    result.convertTo(result, CV_8UC1);
    imshow("result", result);


}