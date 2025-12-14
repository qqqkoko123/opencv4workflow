#pragma once

#include <QDialog>
#include "ui_frmShapeMatch.h"
#include <opencv2\opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"
#include "line2Dup.h"

struct InitShapeMatchData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	QColor color;
	QImage srcModelImage;
	QPointF datum_center;
	QString fileModelName;
};
Q_DECLARE_METATYPE(InitShapeMatchData);

class frmShapeMatch : public Toolnterface
{
	Q_OBJECT

public:
	frmShapeMatch(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmShapeMatch();

private:
	Ui::frmShapeMatchClass ui;

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
	void on_btnAddROI_2_clicked();
	void on_btnDeleteROI_2_clicked();
	void on_btnCreateROI_clicked();
	void on_btnDeleteModel_clicked();
	void on_btnRoiColor_clicked();	
	void on_comboViewMode_currentIndexChanged(int index);

private:
	int RunToolPro();
	bool Save_Mat(const string path, const string mat_name, const cv::Mat src_mat);
	cv::Mat Load_Mat(const QString path, const string mat_name);
	QImage Mat2QImage(const cv::Mat& mat);	
	cv::Mat QImageToMat(const QImage& image);
	int GetTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, cv::Point2f& center, double& angle, int num_feature);
	int MatchTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, const bool use_roi, const MRectangle m_rectangle, vector<cv::Point2f>& center, vector<double>& angle, vector<double>& out_score, const int num_levels, const int angle_start_end, const int num_matches, const double max_overlap, const int num_feature, const double int_score, const bool show_result, const int thickness);
	void DrawMarkCross(const cv::Mat& matDraw, const int iX, const int iY, const int iLength, const cv::Scalar color, const int iThickness);

private:		
	gVariable gvariable;
	QGraphicsViews* view;	
	QStringList strs;
	int match_mode;
	bool contour_view;
	cv::Mat srcImage;
	cv::Mat dstImage;
	cv::Mat dstRoiImage;
	cv::Mat model;
	cv::Mat model_buf;
	int image_index = 0;
	int tool_index = 0;
	QColor color;
	RectangleItem* rectangle_item;	
	MRectangle m_rectangle;
	cv::Rect rect;
	cv::Mat mask;
	cv::Mat dst;
	bool use_roi;
	cv::Point2f DatumCenter;	
	line2Dup::Detector detector;
	int num_feature = 30;
	std::vector<std::string> ids;
	std::vector<shape_based_matching::shapeInfo_producer::Info> infos;		
	//定义输出数据
	vector<cv::Point2f> center = vector<cv::Point2f>(1000);	
	vector<double> angle = vector<double>(1000);
	vector<double> out_score = vector<double>(1000);	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
