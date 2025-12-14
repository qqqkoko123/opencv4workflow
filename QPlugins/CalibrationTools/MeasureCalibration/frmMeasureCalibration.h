#pragma once

#include <QDialog>
#include "ui_frmMeasureCalibration.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitMeasureCalibrationData
{
	double PixelEquivalentX;
	double PixelEquivalentY;
};
Q_DECLARE_METATYPE(InitMeasureCalibrationData);

class frmMeasureCalibration : public Toolnterface
{
	Q_OBJECT

public:
	frmMeasureCalibration(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmMeasureCalibration();

private:
	Ui::frmMeasureCalibrationClass ui;

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
	void on_spinSegment_valueChanged(int value);
	void on_comboMode_currentIndexChanged(int index);

private:
	int RunToolPro();
	int GetEdgeWidth(const cv::Mat& src_mat, const std::vector<QPointF> line_small_points, const std::vector<QPointF> line_big_points, vector<QPointF>& edge_points1, vector<QPointF>& edge_points2, const int threshold_delta1 = 20, const int direction1 = 0, const int threshold_delta2 = 20, const int direction2 = 0, const int segment_num = 120);
	QPointF FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta);
	double GetDistP2L(const cv::Point2f pointP, const cv::Point2f pointA, const cv::Point2f pointB);
	double Average(const vector<double> arrays, const int n);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	Caliper* caliper_item;
	CaliperP caliper_p;
	QColor color;
	vector<QPointF> xy1 = vector<QPointF>(1000);
	vector<QPointF> xy2 = vector<QPointF>(1000);
	vector<cv::Point2f> select_xy1 = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy1 = vector<cv::Point2f>(1000);	
	vector<cv::Point2f> select_xy2 = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy2 = vector<cv::Point2f>(1000);
	int direction;
	double k;  //斜率
	double b;  //截距	
	double PixelEquivalentX = 0, PixelEquivalentY = 0;
	bool view_state = false;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
