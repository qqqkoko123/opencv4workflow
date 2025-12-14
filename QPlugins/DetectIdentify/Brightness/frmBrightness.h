#pragma once

#include <QDialog>
#include "ui_frmBrightness.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmBrightness : public Toolnterface
{
	Q_OBJECT

public:
	frmBrightness(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmBrightness();

private:
	Ui::frmBrightnessClass ui;

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

signals:	
	void sig_BrightnessValue(QString InfoVal);

private:
	int RunToolPro();
	bool DetectBrightness(const cv::Mat src_mat, float& cast, float& da);
	QImage Mat2QImage(const cv::Mat& mat);	

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
