#pragma once

#include <QDialog>
#include "ui_frmPointPoint.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmPointPoint : public Toolnterface
{
	Q_OBJECT

public:
	frmPointPoint(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmPointPoint();

private:
	Ui::frmPointPointClass ui;

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
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();	
	void on_btnLinkPoint1_clicked();
	void on_btnDelLinkPoint1_clicked();
	void on_btnLinkPoint2_clicked();
	void on_btnDelLinkPoint2_clicked();

private:
	int RunToolPro();
	double CalcPPDist(const cv::Point2f startPoint, const cv::Point2f endPoint);
	double CalcLineHorizontalAngle(const cv::Point2f line_pointf1, const cv::Point2f line_pointf2);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	QList<QString> keys;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	cv::Point2f Center;
	double Angle;
	double Distance;	
	QList<QString> point_keys;
	int point_buf1, point_buf2;
	cv::Point p1, p2;
	cv::Point2f p1f, p2f;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
