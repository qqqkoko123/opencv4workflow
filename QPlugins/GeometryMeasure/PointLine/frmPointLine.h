#pragma once

#include <QDialog>
#include "ui_frmPointLine.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include <QButtonGroup>
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmPointLine : public Toolnterface
{
	Q_OBJECT

public:
	frmPointLine(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmPointLine();

private:
	Ui::frmPointLineClass ui;

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
	void on_btnLinkPoint_clicked();
	void on_btnDelLinkPoint_clicked();
	void on_btnLinkLinek_clicked();
	void on_btnDelLinkLinek_clicked();
	void on_btnLinkLineb_clicked();
	void on_btnDelLinkLineb_clicked();
	void on_btnLinkPoint1_clicked();
	void on_btnDelLinkPoint1_clicked();
	void on_btnLinkPoint2_clicked();
	void on_btnDelLinkPoint2_clicked();

private:
	int RunToolPro();
	cv::Point2f GetFootOfPerpendicular(const cv::Point2f pt, const cv::Point2f line_begin, const cv::Point2f line_end);
	double CalcPPDist(const cv::Point2f startPoint, const cv::Point2f endPoint);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QButtonGroup* btnGroupRadio;
	QGraphicsViews* view;
	QStringList strs;
	QList<QString> keys;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	cv::Point2f Pedal;
	double Distance;
	double k;  //斜率
	double b;  //截距	
	QList<QString> point_keys;
	int k_buf, b_buf, point_buf, point_buf1, point_buf2;
	cv::Point p0, p1, p2;
	cv::Point2f p0f, p1f, p2f;	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
