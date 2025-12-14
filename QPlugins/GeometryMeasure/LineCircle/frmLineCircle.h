#pragma once

#include <QDialog>
#include "ui_frmLineCircle.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include <QButtonGroup>
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class Ellipse {
public:
	double a;
	double b;
	double angle;
	cv::Point2f center;
	Ellipse() :a(0), b(0), angle(0), center(cv::Point2f(0, 0)) {}
	Ellipse(double a_, double b_, double angle_, cv::Point2f center_) :
		a(a_), b(b_), angle(angle_), center(center_) {}
};

class frmLineCircle : public Toolnterface
{
	Q_OBJECT

public:
	frmLineCircle(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmLineCircle();

private:
	Ui::frmLineCircleClass ui;

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
	void on_btnLinkLinek_clicked();
	void on_btnDelLinkLinek_clicked();
	void on_btnLinkLineb_clicked();
	void on_btnDelLinkLineb_clicked();
	void on_btnLinkPoint1_clicked();
	void on_btnDelLinkPoint1_clicked();
	void on_btnLinkPoint2_clicked();
	void on_btnDelLinkPoint2_clicked();
	void on_btnLinkCircleCPoint_clicked();
	void on_btnDelLinkCircleCPoint_clicked();
	void on_btnLinkCircleRadius_clicked();
	void on_btnDelLinkCircleRadius_clicked();

private:
	int RunToolPro();
	double CalcPPDist(const cv::Point2f startPoint, const cv::Point2f endPoint);
	bool JudgePoint(const Ellipse& e, const double x, const double y);
	cv::Point2f FindIntersections(const Ellipse& e, const double& k, const double& b, const int flag);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	Ellipse cir_ellipse;
	QButtonGroup* btnGroupRadio;
	QGraphicsViews* view;
	QStringList strs;
	QList<QString> keys;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	vector<cv::Point2f> Intersections = vector<cv::Point2f>(10);  //交点
	double k;  //斜率
	double b;  //截距	
	double radius;
	QList<QString> point_keys;
	int k_buf, b_buf, point_buf1, point_buf2, circle_point_buf, circle_radius_buf;
	cv::Point p1, p2, cir_p;
	cv::Point2f p1f, p2f, cir_pf;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
