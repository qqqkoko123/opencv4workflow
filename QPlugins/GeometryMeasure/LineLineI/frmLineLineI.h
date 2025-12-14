#pragma once

#include <QDialog>
#include "ui_frmLineLineI.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include <QButtonGroup>
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmLineLineI : public Toolnterface
{
	Q_OBJECT

public:
	frmLineLineI(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmLineLineI();

private:
	Ui::frmLineLineIClass ui;

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
	void on_btnLinkLine1k_clicked();
	void on_btnDelLinkLine1k_clicked();
	void on_btnLinkLine1b_clicked();
	void on_btnDelLinkLine1b_clicked();
	void on_btnLinkLine2k_clicked();
	void on_btnDelLinkLine2k_clicked();
	void on_btnLinkLine2b_clicked();
	void on_btnDelLinkLine2b_clicked();
	void on_btnLinkLine1Point1_clicked();
	void on_btnDelLinkLine1Point1_clicked();
	void on_btnLinkLine1Point2_clicked();
	void on_btnDelLinkLine1Point2_clicked();
	void on_btnLinkLine2Point1_clicked();
	void on_btnDelLinkLine2Point1_clicked();
	void on_btnLinkLine2Point2_clicked();
	void on_btnDelLinkLine2Point2_clicked();

private:
	int RunToolPro();
	cv::Vec4d lines_intersection(const cv::Vec4d l1, const cv::Vec4d l2);
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
	cv::Point2f Intersection;
	double Angle;
	double line1_k, line2_k;  //斜率
	double line1_b, line2_b;  //截距	
	QList<QString> point_keys;
	int k1_buf, k2_buf, b1_buf, b2_buf, point1_1_buf, point1_2_buf, point2_1_buf, point2_2_buf;
	cv::Point p1_1, p1_2, p2_1, p2_2;
	cv::Point2f p1_1f, p1_2f, p2_1f, p2_2f;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
