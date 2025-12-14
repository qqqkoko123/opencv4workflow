#pragma once

#include <QDialog>
#include "ui_frmSelectShape.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitSelectShapeData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	qreal Lenth1;
	qreal Lenth2;
	qreal Pi;
	qreal R;
	QList<QPointF> init_points;
	QList<QList<QPointF>> list_ps;
	QColor color;
};
Q_DECLARE_METATYPE(InitSelectShapeData);

class frmSelectShape : public Toolnterface
{
	Q_OBJECT

public:
	frmSelectShape(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmSelectShape();

private:
	Ui::frmSelectShapeClass ui;

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
	void on_btnAddType_clicked();
	void on_btnDeleteType_clicked();
	void slot_DoubleClicked(int, int);
	void on_btnAddROI_clicked();
	void on_btnDeleteROI_clicked();
	void on_btnRoiColor_clicked();
	void slotCModeChanged(int);

private:
	int RunToolPro();	
	bool SelectCShape(cv::Mat& src_gray_mat, vector<vector<cv::Point>>& use_vvp, vector<double>& area, vector<cv::Point2f>& center_points, const double min_feature_value, const double max_feature_value, const int mode, const int method, const QString find_mode);
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
	int region_buf = 0;
	RectangleItem* rectangle_item;
	RectangleRItem* rectangler_item;
	CircleItem* circle_item;
	PolygonItem* polygon_item;
	MRectangle m_rectangle;
	MRotatedRect m_rotatedrect;
	MCircle m_circle;
	MPolygon m_polygon;
	cv::Rect rect;
	cv::Mat mask;
	cv::Mat dst;
	QColor color;
	vector<cv::Point> pts = vector<cv::Point>(200);
	vector<vector<cv::Point>> contours = vector<vector<cv::Point>>(10000);
	vector<double> areas = vector<double>(10000);
	vector<cv::Point2f> center_points = vector<cv::Point2f>(10000);
	vector<vector<cv::Point>> all_contours = vector<vector<cv::Point>>(10000);
	vector<vector<cv::Point>> all_contours_buf_and = vector<vector<cv::Point>>(10000);	
	vector<vector<cv::Point>> all_contours_buf_or = vector<vector<cv::Point>>(10000);
	int table_count, cycle_count;
	bool view_contours;
	QString c_mode;
	double min_feature_value, max_feature_value;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
