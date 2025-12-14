#pragma once

#include <QDialog>
#include "ui_frmFindCircle.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitFindCircleData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal RadiusMin;
	qreal RadiusMax;
	int segment_line_num;
	QVector<QPointF> ring_s_points;
	QVector<QPointF> ring_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitFindCircleData);

typedef struct Box
{
	double x;
	double y;
	double r;
}Box;

class frmFindCircle : public Toolnterface
{
	Q_OBJECT

public:
	frmFindCircle(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmFindCircle();

private:
	Ui::frmFindCircleClass ui;

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
	int FindBorderPoints(const cv::Mat& src_mat, const std::vector<QPointF> ring_small_points, const std::vector<QPointF> ring_big_points, std::vector<QPointF>& xy, const int threshold_delta = 20, const int direction = 0, const int in_out_circle = 0, const int segment_num = 90);
	QPointF FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta);
	Box fitCircle(const std::vector<cv::Point2f>& points);
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
	ConcentricCircleItem* concentric_circle_item;
	CCircle c_circle;
	QColor color;
	cv::Point2f match_origin_point, match_current_point;
	double match_origin_angle = 0, match_current_angle = 0;	
	vector<QPointF> ring_small_points = vector<QPointF>(1000);
	vector<QPointF> ring_big_points = vector<QPointF>(1000);
	vector<QPointF> xy = vector<QPointF>(1000);
	vector<cv::Point2f> select_xy = vector<cv::Point2f>(1000);
	vector<cv::Point2f> cull_xy = vector<cv::Point2f>(1000);
	int direction, in_out_circle;
	cv::Point2f Center;
	double Radius;
	bool view_points;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
