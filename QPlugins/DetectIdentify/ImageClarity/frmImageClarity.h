#pragma once

#include <QDialog>
#include "ui_frmImageClarity.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmImageClarity : public Toolnterface
{
	Q_OBJECT

public:
	frmImageClarity(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmImageClarity();

private:
	Ui::frmImageClarityClass ui;

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
	void on_btnSelectPath_clicked();	
	void slot_PathMessage();

signals:		
	void sig_PathMessage();
	void sig_ClarityValue(QString InfoVal);

private:
	int RunToolPro();	
	int GetMaxAndIndex(const std::vector<double> pa);
	double CalcClarity(const cv::Mat src_mat);
	double CalcClarityTenengrad(const cv::Mat src_mat);
	double CalcClarityLaplacian(const cv::Mat src_mat);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	cv::Mat srcImage;
	cv::Mat dstImage;	
	QStringList mImgNames;	
	QString imgsPath;
	QString imgsPathBuf;
	int tool_index = 0;
};
