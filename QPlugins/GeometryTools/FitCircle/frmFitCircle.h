#pragma once

#include <QDialog>
#include "ui_frmFitCircle.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

typedef struct Box
{
	double x;
	double y;
	double r;
}Box;

class frmFitCircle : public Toolnterface
{
	Q_OBJECT

public:
	frmFitCircle(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmFitCircle();

private:
	Ui::frmFitCircleClass ui;

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
	void on_btnLinkContour_clicked();
	void on_btnDelLinkContour_clicked();

private:
	int RunToolPro();
	Box fitCircle(const std::vector<cv::Point2f>& points);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	cv::Point2f Center;
	double Radius;	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
