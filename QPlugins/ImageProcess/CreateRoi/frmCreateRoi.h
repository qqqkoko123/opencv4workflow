#pragma once

#include <QDialog>
#include "ui_frmCreateRoi.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmCreateRoi : public Toolnterface
{
	Q_OBJECT

public:
	frmCreateRoi(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmCreateRoi();

private:
	Ui::frmCreateRoiClass ui;

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
	vector<vector<cv::Point>> mergeContours(const vector<vector<cv::Point>> contours);
	QImage Mat2QImage(const cv::Mat& mat);		

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	int contour_index = 0;
	bool view_contour;
	cv::Rect rect;
	cv::RotatedRect rrect;
	vector<cv::Point> pts = vector<cv::Point>(200);
	vector<vector<cv::Point>> all_contours;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
