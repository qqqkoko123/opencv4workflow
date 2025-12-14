#pragma once

#include <QDialog>
#include "ui_frmColorIdentify.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitColorIdentifyData
{	
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;	
	QColor color;
	QImage srcStandardImage;
};
Q_DECLARE_METATYPE(InitColorIdentifyData);

class frmColorIdentify : public Toolnterface
{
	Q_OBJECT

public:
	frmColorIdentify(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmColorIdentify();

private:
	Ui::frmColorIdentifyClass ui;

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
	void slot_Message();
	void slot_StandardImage();

signals:
	void sig_ScoreValue(QString InfoVal);
	void sig_Message();

private:
	int RunToolPro();
	bool ColorIdentifyCheck(const cv::Mat src_ori, const cv::Mat src_mat, double& score);
	cv::Point2f AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point);
	QImage Mat2QImage(const cv::Mat& mat);
	cv::Mat QImageToMat(const QImage& image);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcStandardImage;
	cv::Mat dstStandardImage;
	cv::Mat srcImage;
	cv::Mat dstImage;
	cv::Mat dstRoiImage;
	int image_index = 0;
	int tool_index = 0;
	RectangleItem* rectangle_item;	
	MRectangle m_rectangle;	
	cv::Rect rect;	
	cv::Mat mask;	
	QColor color;	
	vector<cv::Point> pts = vector<cv::Point>(200);
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
