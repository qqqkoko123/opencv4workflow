#pragma once

#include <QDialog>
#include "ui_frmPerspectiveTransform.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmPerspectiveTransform : public Toolnterface
{
	Q_OBJECT

public:
	frmPerspectiveTransform(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmPerspectiveTransform();

private:
	Ui::frmPerspectiveTransformClass ui;

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
	void on_btnLinkInPutPos1_clicked();
	void on_btnLinkInPutPos2_clicked();
	void on_btnLinkInPutPos3_clicked();
	void on_btnLinkInPutPos4_clicked();
	void on_btnDelLinkInPutPos1_clicked();
	void on_btnDelLinkInPutPos2_clicked();
	void on_btnDelLinkInPutPos3_clicked();
	void on_btnDelLinkInPutPos4_clicked();
	void on_btnLinkOutPutPos1_clicked();
	void on_btnLinkOutPutPos2_clicked();
	void on_btnLinkOutPutPos3_clicked();
	void on_btnLinkOutPutPos4_clicked();
	void on_btnDelLinkOutPutPos1_clicked();
	void on_btnDelLinkOutPutPos2_clicked();
	void on_btnDelLinkOutPutPos3_clicked();
	void on_btnDelLinkOutPutPos4_clicked();	

private:
	int RunToolPro();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	QList<QString> keys;
	cv::Point2f input_point1, input_point2, input_point3, input_point4;
	cv::Point2f output_point1, output_point2, output_point3, output_point4;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
