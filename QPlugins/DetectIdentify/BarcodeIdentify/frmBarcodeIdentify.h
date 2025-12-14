#pragma once

#include <QDialog>
#include "ui_frmBarcodeIdentify.h"
#include <opencv2\opencv.hpp>
#include "opencv2/barcode.hpp"
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmBarcodeIdentify : public Toolnterface
{
	Q_OBJECT

public:
	frmBarcodeIdentify(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmBarcodeIdentify();

private:
	Ui::frmBarcodeIdentifyClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

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
	void on_btnTestImage_clicked();

private:
	int RunTestImage();
	int RunToolPro();
	bool InitDetector();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;	
	cv::Mat srcImage;
	cv::Mat dstImage;	
	int image_index = 0;
	int tool_index = 0;
	bool view_rect = false;
	cv::Ptr<cv::barcode::BarcodeDetector> detector = nullptr;
	std::vector<cv::barcode::BarcodeType> decoded_format = std::vector<cv::barcode::BarcodeType>(100);
	vector<cv::Point> vPoints = vector<cv::Point>(1000);;
	vector<string> strDecoded = vector<string>(100);
	vector<QString> Code = vector<QString>(100);
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
