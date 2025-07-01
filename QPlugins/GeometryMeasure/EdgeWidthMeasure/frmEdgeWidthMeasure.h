﻿#pragma once

#include <QDialog>
#include "ui_frmEdgeWidthMeasure.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitEdgeWidthMeasureData
{
	bool use_roi;
	QString type;
	qreal x1;
	qreal y1;
	qreal x2;
	qreal y2;
	qreal height;
	float row;
	float col;
	float len1;
	float len2;
	float angle;
	QPointF pp1;
	QPointF pp2;
	int segment_line_num;
	QVector<QPointF> line_s_points;
	QVector<QPointF> line_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitEdgeWidthMeasureData);

class frmEdgeWidthMeasure : public Toolnterface
{
	Q_OBJECT

public:
	frmEdgeWidthMeasure(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmEdgeWidthMeasure();

private:
	Ui::frmEdgeWidthMeasureClass ui;

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
	void on_btnLinkFollow_clicked();
	void on_btnDelLinkFollow_clicked();
	void on_btnAddROI_clicked();
	void on_btnDeleteROI_clicked();
	void on_btnRoiColor_clicked();
	void on_spinSegment_valueChanged(int value);

private:
	int RunToolPro();
	int GetEdgeWidth(const cv::Mat& src_mat, const std::vector<QPointF> line_small_points, const std::vector<QPointF> line_big_points, vector<QPointF>& edge_points1, vector<QPointF>& edge_points2, const int threshold_delta1 = 20, const int direction1 = 0, const int threshold_delta2 = 20, const int direction2 = 0, const int segment_num = 120);
	QPointF FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta);
	double GetDistP2L(const cv::Point2f pointP, const cv::Point2f pointA, const cv::Point2f pointB);
	double Average(const vector<double> arrays, const int n);
	cv::Point2f AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	cv::Mat dstRoiImage;
	int image_index = 0;
	int tool_index = 0;
	Caliper* caliper_item;
	CaliperP caliper_p;
	QColor color;
	cv::Point2f match_origin_point, match_current_point;
	double match_origin_angle = 0, match_current_angle = 0;
	vector<QPointF> line_small_points = vector<QPointF>(1000);
	vector<QPointF> line_big_points = vector<QPointF>(1000);
	vector<QPointF> xy1 = vector<QPointF>(1000);
	vector<QPointF> xy2 = vector<QPointF>(1000);
	vector<cv::Point2f> select_xy1 = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy1 = vector<cv::Point2f>(1000);	
	vector<cv::Point2f> select_xy2 = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy2 = vector<cv::Point2f>(1000);
	int direction;
	double k;  //斜率
	double b;  //截距	
	double Distance;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
