#pragma once

#include <QDialog>
#include "ui_frmLinearCalculation.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

class frmLinearCalculation : public Toolnterface
{
	Q_OBJECT

public:
	frmLinearCalculation(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmLinearCalculation();

private:
	Ui::frmLinearCalculationClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:
	void on_btnExecute_clicked();
	void on_btnLinkERTCalib_clicked();
	void on_btnDelLinkERTCalib_clicked();
	void on_btnLinkRotateCenter_clicked();
	void on_btnDelLinkRotateCenter_clicked();
	void on_btnLinkDatumPoint_clicked();
	void on_btnDelLinkDatumPoint_clicked();
	void on_btnLinkCurrentPoint_clicked();
	void on_btnDelLinkCurrentPoint_clicked();
	void on_btnLinkRotateAngle_clicked();
	void on_btnDelLinkRotateAngle_clicked();
	void on_btnLinkDatumPoint1_clicked();
	void on_btnDelLinkDatumPoint1_clicked();
	void on_btnLinkDatumPoint2_clicked();
	void on_btnDelLinkDatumPoint2_clicked();
	void on_btnLinkCurrentPoint1_clicked();
	void on_btnDelLinkCurrentPoint1_clicked();
	void on_btnLinkRotateAngle1_clicked();
	void on_btnDelLinkRotateAngle1_clicked();
	void on_btnLinkImagePoint_clicked();
	void on_btnDelLinkImagePoint_clicked();	
	void on_comboMethod_currentIndexChanged(int index);

private:
	int RunToolPro();
	bool CalcMoveDisUseRC(const double rx0, const double ry0, const double X0, const double Y0, const double X1, const double Y1, const double angle, double& CDx, double& CDy);
	bool CalcMoveDisNoUseRC(const double X0, const double Y0, const double X1, const double Y1, const double X2, const double Y2, const double angle, double& CDx, double& CDy);
	cv::Point2f ImageC_To_MachineC(const cv::Point2f pPoint, const double A, const double B, const double C, const double D, const double E, const double F);

private:	
	gVariable gvariable;
	QStringList strs;	
	QList<QString> keys;
	int tool_index = 0;
	double MovingDistanceX;  //移动量X
	double MovingDistanceY;  //移动量Y
	cv::Point2f WorldCoordinatePoint;  //世界坐标点	
	cv::Point2f ImageCoordinatePoint;  //图像坐标点
	vector<double> EstimateAffine = vector<double>(10);  //N点标定参数
	QList<QString> value_keys;
	//使用N点标定
	int method_npoint_buf;
	//计算Robot移动量(使用旋转中心)
	int method1_point_buf1, method1_point_buf2, method1_point_buf3, method1_angle_buf;
	cv::Point2f method1_p1f, method1_p2f, method1_p3f;
	double method1_angle;
	//计算Robot移动量(不使用旋转中心)
	int method2_point_buf1, method2_point_buf2, method2_point_buf3, method2_angle_buf;
	cv::Point2f method2_p1f, method2_p2f, method2_p3f;
	double method2_angle;
	//图像坐标转换为世界坐标
	int method3_point_buf;
	cv::Point2f method3_pf;	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
