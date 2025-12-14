#pragma once

#include <QDialog>
#include "ui_frmERTCalibration.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include <QButtonGroup>
#include "QGraphicsViews.h"
#include "Toolnterface.h"

typedef struct Box
{
	double x;
	double y;
	double r;
}Box;

class frmERTCalibration : public Toolnterface
{
	Q_OBJECT

public:
	frmERTCalibration(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmERTCalibration();

private:
	Ui::frmERTCalibrationClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();
	void onRadioClick(bool);

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnAddROI_clicked();
	void on_btnDeleteROI_clicked();	
	void on_btnGetCenter_clicked();
	void on_spinSegment_valueChanged(int value);
	void on_comboCalibMethod_currentIndexChanged(int index);

private:
	int RunToolPro();
	int RunFindCirclePro();
	int FindBorderPoints(const cv::Mat& src_mat, const std::vector<QPointF> ring_small_points, const std::vector<QPointF> ring_big_points, std::vector<QPointF>& xy, const int threshold_delta = 20, const int direction = 0, const int in_out_circle = 0, const int segment_num = 90);
	QPointF FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta);
	Box fitCircle(const std::vector<cv::Point2f>& points);	
	bool NinePointsCalib(const std::vector<cv::Point2f> points_image, const std::vector<cv::Point2f> points_robot, double& A, double& B, double& C, double& D, double& E, double& F);
	cv::Point2f ImageC_To_MachineC(const cv::Point2f pPoint, const double A, const double B, const double C, const double D, const double E, const double F);
	bool CalcRotationCenter(const double X1, const double Y1, const double X2, const double Y2, const double X3, const double Y3, double& rx0, double& ry0);
	bool CalcRotationCenter(const double X1, const double Y1, const double X2, const double Y2, const double angle, double& rx0, double& ry0);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QButtonGroup* btnGroupRadio;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;	
	int image_index = 0;
	int tool_index = 0;
	ConcentricCircleItem* concentric_circle_item;
	CCircle c_circle;
	QColor color;
	vector<QPointF> xy = vector<QPointF>(1000);
	vector<cv::Point2f> select_xy = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy = vector<cv::Point2f>(1000);
	int direction, in_out_circle;
	cv::Point2f Center;
	double Radius;
	bool view_points;
	bool get_cir_center;
	vector<double> EstimateAffine = vector<double>(10);  //N点标定参数
	double PixelEquivalentX;  //像素当量X
	double PixelEquivalentY;  //像素当量Y
	cv::Point2f RotateCenter;  //旋转中心
	cv::Point2f DatumPoint1;  //基准点1
	cv::Point2f MacDatumPoint1;  //机械基准点1
	cv::Point2f DatumPoint2;  //基准点2
	double DatumAngle;  //基准角度
	std::vector<cv::Point2f> points_image = std::vector<cv::Point2f>(9);
	std::vector<cv::Point2f> points_robot = std::vector<cv::Point2f>(9);
	double A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	double E = 0;
	double F = 0;
	double rx0 = 0, ry0 = 0;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
