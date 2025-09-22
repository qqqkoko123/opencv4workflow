#pragma once
#pragma execution_character_set("utf-8")

#include <QObject>
#include "Toolnterface.h"
#include <vector>
#include <QMap>
#include <opencv2\opencv.hpp>
using namespace std;

class Toolnterface;  //头文件相互调用前置声明

//图像
typedef struct VisionToolImage
{	
	QString Name;  //名称
	cv::Mat InputImage;  //输入图像
	cv::Mat OutputImage;  //输出图像
	cv::Mat OutputRoiImage;  //输出ROI图像
	QImage OutputViewImage;  //输出显示图像
}VisionToolIMAGE;

//工具
typedef struct VisionToolInfo
{
	QString Name;  //名称
	int Number;  //工具号
}VisionToolINFO;

//屏幕号
typedef struct VisionToolScreen
{	
	int ScreenNumber;  //屏幕号
	int ImageIndex;  //图像索引
}VisionToolSCREEN;

//图像处理
typedef struct VisionToolImageProcess
{	
	cv::Rect CvRect;  //矩形
	cv::RotatedRect CvRotatedRect;  //旋转矩形
	QVector<QString> GetViewMsg = QVector<QString>(100);  //信息
	bool ViewMsgState;
}VisionToolIMAGEPROCESS;

//检测识别
typedef struct VisionToolDetect
{	
	vector<QString> Code = vector<QString>(100);  //条形码/二维码
	int Quantity;  //斑点个数
	QString Character;  //字符	
	QString Category;  //类别
	double Score;  //相似度
	double Brightness;  //亮度
	double Clarity;  //清晰度
	vector<vector<cv::Point>> Contours = vector<vector<cv::Point>>(10000);  //轮廓
	vector<double> Areas = vector<double>(10000);  //面积
	vector<cv::Point2f> CenterPoints = vector<cv::Point2f>(10000);  //重心	
}VisionToolDETECT;

//标定工具
typedef struct VisionToolCalib
{	
	cv::Mat CameraMatrix;  //内参K
	cv::Mat DistCoeffs;  //畸变系数
	vector<double> EstimateAffine = vector<double>(10);  //N点标定参数
	double PixelEquivalentX;  //像素当量X
	double PixelEquivalentY;  //像素当量Y
	cv::Point2f RotateCenter;  //旋转中心
	cv::Point2f DatumPoint1;  //基准点1
	cv::Point2f DatumPoint2;  //基准点2
	double DatumAngle;  //基准角度
}VisionToolCALIB;

//对位工具
typedef struct VisionTTPosition
{	
	cv::Point2f DatumCenter;  //匹配基准中心
	vector<cv::Point2f> Center;  //匹配中心坐标
	vector<double> Angle;  //匹配角度
	vector<double> OutScore;  //匹配分数
	vector<double> Scale;  //缩放因子
	cv::RotatedRect CvRotatedRect;  //旋转矩形
	double MovingDistanceX;  //移动量X
	double MovingDistanceY;  //移动量Y
	cv::Point2f WorldCoordinatePoint;  //世界坐标点	
}VisionTTPOSITION;

//几何工具/测量
typedef struct VisionToolGeometry
{	
	cv::Point2f Center;  //中心坐标/圆心坐标
	double Angle;  //角度/夹角
	double Distance;  //距离/边缘宽度
	double k;  //斜率
	double b;  //截距
	double Radius;  //半径
	double Length1;  //长轴长度
	double Length2;  //短轴长度
	cv::Point2f Pedal;  //垂足坐标
	cv::Point2f Intersection;  //交点坐标
	vector<cv::Point2f> Intersections = vector<cv::Point2f>(10);  //交点坐标
	vector<cv::Point2f> BorderPoints = vector<cv::Point2f>(1000000);  //点集	
}VisionToolGEOMETRY;

//三维检测
typedef struct VisionToolThreeD
{	
	vector<double> Flatness = vector<double>(10);  //平面参数
	double Distance;  //点到平面距离
}VisionToolTHREED;

//逻辑工具
typedef struct VisionToolLogic
{
	QString GotoToolName;  //跳转工具名
}VisionToolLOGIC;

//通讯工具
typedef struct VisionToolCommunication
{	
	QVector<bool> InPutIoX = QVector<bool>(8);  //输入点
	QString InputData;  //接收数据
	QString OutputData;  //发送数据
	QVector<int> RegisterReadData;  //寄存器读取数据
	QVector<int> RegisterWriteData;  //寄存器写入数据
}VisionToolCOMMUNICATION;

//系统工具
typedef struct VisionToolSystem
{
	
}VisionToolSYSTEM;

//结果
typedef struct VisionToolResult
{
	QString Name;  //名称
	bool State;  //状态		
	int Regex;  //表达式
}VisionToolRESULT;

//处理模块数据
typedef struct VisionTool
{
	QString PublicToolName;	
	Toolnterface* PublicToolDlg;
	VisionToolIMAGE PublicImage;
	VisionToolINFO PublicInfo;	
	VisionToolSCREEN PublicScreen;	
	VisionToolIMAGEPROCESS PublicImageProcess;
	VisionToolDETECT PublicDetect;
	VisionToolCALIB PublicCalib;
	VisionTTPOSITION PublicTPosition;
	VisionToolGEOMETRY PublicGeometry;
	VisionToolTHREED PublicThreeD;
	VisionToolLOGIC PublicLogic;
	VisionToolCOMMUNICATION PublicCommunication;
	VisionToolSYSTEM PublicSystem;
	VisionToolRESULT PublicResult;
}VisionTOOL;

//工具类
class QToolBase : public QObject
{
	Q_OBJECT

public:
	QToolBase();
	~QToolBase();

	vector<VisionTOOL> m_Tools = vector<VisionTOOL>(100); //处理模块数据链
	QVector<QString> m_FlowSortList = QVector<QString>(100);

	QToolBase* operator= (const QToolBase*& t) 
	{
		this->m_Tools.clear();
		for (int i = 0; i < t->m_Tools.size(); i++)
		{
			this->m_Tools.push_back(t->m_Tools[i]);
		}
		return this;
	}

signals:
	void sig_Info(const QString strMsg);
	void sig_Warn(const QString strMsg);
	void sig_Error(const QString strMsg);
	QString sig_SetGlobalValue(const QString strVar, const QString value, const int flowIndex);

public:
	//添加/删除/获取/处理模块数据
	bool AddTool(const QString toolname);
	bool AddToolInfo(const QString toolname, const VisionToolINFO toolinfo);
	bool AddToolDlg(const QString toolname, Toolnterface* toolDlg);
	bool GetToolDlg(const QString toolname);		
	bool RunToolFlow_B1(const QString toolname);
	bool RunToolFlow_B2(const QString toolname);
	bool RunToolFlow_B3(const QString toolname);
	bool RunToolFlow_B4(const QString toolname);
	bool RunToolFlow_B5(const QString toolname);
	bool RunToolFlow_B6(const QString toolname);
	bool RunToolFlow_B7(const QString toolname);
	bool RunToolFlow_B8(const QString toolname);
	bool RunToolFlow_B9(const QString toolname);
	bool RunToolFlow_B10(const QString toolname);
	bool RunToolFlow_B11(const QString toolname);
	bool RunToolFlow_B12(const QString toolname);
	bool RunToolFlow_B13(const QString toolname);
	bool RunToolFlow_B14(const QString toolname);
	bool RunToolFlow_B15(const QString toolname);
	bool RunToolFlow_B16(const QString toolname);
	bool RunToolFlow_B17(const QString toolname);
	bool RunToolFlow_B18(const QString toolname);
	bool RunToolFlow_B19(const QString toolname);
	bool RunToolFlow_B20(const QString toolname);
	bool RunToolLink(const QString toolname, const int int_link, const QString str_link);
	bool RunAllToolLink();
	bool RunGotoToolLink();
	bool RunCommunicationLink(const QString toolname);	
	bool RunScriptEditToolLink();
};
