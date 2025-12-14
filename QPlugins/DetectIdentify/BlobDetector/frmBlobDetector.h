#pragma once

#include <QDialog>
#include "ui_frmBlobDetector.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitBlobDetectorData
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
Q_DECLARE_METATYPE(InitBlobDetectorData);

class frmBlobDetector : public Toolnterface
{
	Q_OBJECT

public:
	frmBlobDetector(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmBlobDetector();

private:
	Ui::frmBlobDetectorClass ui;

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
	void on_btnRoiColor_clicked();

signals:
	void sig_BlobValue(QString InfoVal);

private:
	int RunToolPro();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;	
	QStringList strs;
	//存储blob
	vector<cv::KeyPoint> keypoints;
	//使用参数设置检测器
	cv::Ptr<cv::SimpleBlobDetector> detector;
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
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
