#pragma once

#include <QDialog>
#include "ui_frmGetContourPoints.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitGetContourPointsData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal width;
	qreal height;	
	qreal R;	
	QColor color;
};
Q_DECLARE_METATYPE(InitGetContourPointsData);

class frmGetContourPoints : public Toolnterface
{
	Q_OBJECT

public:
	frmGetContourPoints(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmGetContourPoints();

private:
	Ui::frmGetContourPointsClass ui;

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

private:
	int RunToolPro();	
	std::vector<cv::Point2f> GetContourPoints(cv::Mat& gray_img, vector<vector<cv::Point2f>>& outContours, const double alpha, const int low_thresh, const int high_thresh) const;
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
	RectangleItem* rectangle_item;	
	CircleItem* circle_item;	
	MRectangle m_rectangle;	
	MCircle m_circle;
	cv::Rect rect;	
	cv::Mat dst;
	QColor color;	
	vector<cv::Point2f> xy = vector<cv::Point2f>(1000000);  //点集
	vector<cv::Point2f> BorderPoints;  //点集
	vector<vector<cv::Point2f>> out_Contours = vector<vector<cv::Point2f>>(10000);  
	bool view_contour;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
