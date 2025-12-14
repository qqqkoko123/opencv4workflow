#pragma once

#include <QDialog>
#include "ui_frmRoundedCorners.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitRoundedCornersData
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
Q_DECLARE_METATYPE(InitRoundedCornersData);

class frmRoundedCorners : public Toolnterface
{
	Q_OBJECT

public:
	frmRoundedCorners(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmRoundedCorners();

private:
	Ui::frmRoundedCornersClass ui;

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
	const int GetCircleGapAngle(cv::Mat& src_mat, const std::vector<QPointF> ring_small_points, const std::vector<QPointF> ring_big_points, vector<QPointF>& xy, double& line_angle, cv::Point2f& cir_center, cv::RotatedRect& fit_ellipse, cv::Point2f& line_point1, cv::Point2f& line_point2, cv::Point2f& vertical_point, const int diff_radius = 10, const int threshold_delta = 20, const int direction = 0, const int in_out_circle = 0, const int segment_num = 120) const;
	QPointF FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta) const;
	cv::Point2f GetFootOfPerpendicular(const cv::Point2f pt, const cv::Point2f line_begin, const cv::Point2f line_end) const;
	cv::Point2f AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point);
	QImage Mat2QImage(const cv::Mat& mat) const;

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
	int direction, in_out_circle;
	cv::Point2f Center;
	cv::Point2f Pedal;
	double Angle;
	bool view_points;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
