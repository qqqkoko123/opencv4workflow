#pragma once

#include <QDialog>
#include "ui_frmImageRepair.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmImageRepair : public Toolnterface
{
	Q_OBJECT

public:
	frmImageRepair(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmImageRepair();

private:
	Ui::frmImageRepairClass ui;

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

private:
	int RunToolPro();
	QImage Mat2QImage(const cv::Mat& mat);
	bool Inpaint(const cv::Mat src_mat, cv::Mat& dst_mat, const int min_threshold = 200, const int max_threshold = 255, const double inpaint_radius = 10);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
