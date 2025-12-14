#pragma once

#include <QDialog>
#include "ui_frmCamShiftTrack.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitCamShiftTrackData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;	
};
Q_DECLARE_METATYPE(InitCamShiftTrackData);

class frmCamShiftTrack : public Toolnterface
{
	Q_OBJECT

public:
	frmCamShiftTrack(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmCamShiftTrack();

private:
	Ui::frmCamShiftTrackClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

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
	void on_btnAddROI_clicked();
	void on_btnDeleteROI_clicked();

private:
	int RunToolPro();
	bool CamShiftCheck(cv::Mat src_mat, cv::Rect rect, cv::Mat& dst_mat, cv::RotatedRect& trackBox, const int smin = 30, const int ksize = 3, const int line_width = 10) const;
	QImage Mat2QImage(const cv::Mat& mat);	

private:	
	gVariable gvariable;
	QGraphicsViews* view;	
	QStringList strs;	
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	RectangleItem* rectangle_item;
	MRectangle MRect;	
	cv::Rect rect;	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
