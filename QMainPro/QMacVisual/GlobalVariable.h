#pragma once

#include <QLabel>
#include <QAbstractButton>
#include <QToolButton>
#include "QToolBase.h"
#include <opencv2\opencv.hpp>
using namespace std;

enum ToolNameList
{
	IMAGE_SOURCE = 0,              //获取图像
	IMAGE_VIEW,                    //图像显示
    EXPORT_IMAGE,                  //导出图像  
    IMAGE_MORPHOLOGY,              //预处理
    IMAGE_SPLICE,                  //图像拼接
    IMAGE_REPAIR,                  //图像修复
    SKELETON,                      //图像细化
    IMAGE_FLIP,                    //图像翻转
    IMAGE_ROTATE,                  //图像旋转
    PERSPECTIVE_TRANSFORM,         //透视变换
    CROP_IMAGE,                    //裁切图像
    CREATE_ROI,                    //创建ROI
    BARCODE_IDENTIFY,              //条形码识别
    BLOB_DETECTOR,                 //斑点分析
    QRCODE_IDENTIFY,               //二维码识别
    OCR_IDENTIFY,                  //字符识别
    CLASSIFIER,                    //分类器
    COLOR_IDENTIFY,                //颜色识别   
    BRIGHTNESS,                    //亮度检测
    IMAGE_CLARITY,                 //图像清晰度     
    SELECT_SHAPE,                  //轮廓特征选择
    ERT_CALIBRATION,               //N点标定  
    DISTORTION_CALIBRATION,        //畸变标定
    MEASURE_CALIBRATION,           //测量标定
    TEMPLATE_MATCH,                //灰度匹配   
    SHAPE_MATCH,                   //形状匹配   
    CAMSHIFT_TRACK,                //目标跟踪
    LINEAR_CALCULATION,            //线性计算
    FIND_CIRCLE,                   //寻找圆
    FIND_LINE,                     //寻找直线
    FIT_CIRCLE,                    //拟合圆
    FIT_ELLIPSE,                   //拟合椭圆
    FIT_LINE,                      //拟合直线
    GET_CONTOUR_POINTS,            //获取边界点
    LINE_CIRCLE,                   //线圆交点
    POINT_POINT,                   //点+点
    POINT_LINE,                    //点+线
    LINE_LINE_I,                   //线线交点
    ROUNDED_CORNERS,               //查找圆缺角  
    EDGE_WIDTH,                    //边缘宽度测量
    FLATNESS,                      //拟合平面 
    EXTENSION_LIBRARY,             //扩展库
    LOGIC_GOTO,                    //跳转语句
    LOGIC_JUDGE,                   //判断语句
    LOGIC_JUDGE_END,               //结束语句
    SCRIPT_EDIT,                   //脚本编辑
    SOCKET_TCP_SERVER,             //TCP/IP服务器
    SOCKET_TCP_CLIENT,             //TCP/IP客户端  
    PLC_COMMUNICATE,               //PLC通信
    SERIAL_PORT,                   //串口通信
    GENERAL_IO,                    //通用I/O
    DELAY_TOOL,                    //延时 
    EXPORT_CSV,                    //导出CSV 
    YOLOV13,                       //YoloV13 
    OCR,                           //OCR 
    QRCODE_GENERATE,               //二维码生成
    IMAGE_PRINT,               //自动打印
	DEFULT_ERROR,
};

//图形字体处理类
class IconHelper : public QObject
{
    Q_OBJECT

public:
    static IconHelper* Instance();
    explicit IconHelper(QObject* parent = 0);  
   
    QPixmap getPixmap(QString& fileName);
   
private:
    static IconHelper* self;    //对象自身
    QFont iconFont;             //图形字体    
};

//全局变量控制
class QConfig
{
public:      
    static QVector<QToolBase*> ToolBase;
};
