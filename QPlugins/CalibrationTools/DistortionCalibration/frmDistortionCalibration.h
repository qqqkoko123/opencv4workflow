#pragma once

#include <QDialog>
#include "ui_frmDistortionCalibration.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmDistortionCalibration : public Toolnterface
{
	Q_OBJECT

public:
	frmDistortionCalibration(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmDistortionCalibration();

private:
	Ui::frmDistortionCalibrationClass ui;

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
	void on_btnSelectPath_clicked();
	void on_btnStoragePath_clicked();
	void on_btnBlobParam_clicked();
	void on_btnCorrectedImage_clicked();
	void slot_PathMessage();
	void slot_ErrorMessage();

signals:
	void sig_PathMessage();
	void sig_ErrorMessage();

private:
	int RunToolPro();
	bool PlateCalibration(const QString imagesPath, const string outputFilename, const cv::Size boardSize, const cv::Size squareSize);
	cv::Mat PlateCorrectedImage(const cv::Mat src_mat, const QString inputFilename);
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	cv::Mat srcImage;
	cv::Mat dstImage;
	QStringList mImgNames;
	QString imgsPath;
	QString imgsPathBuf;
	QString imgSaveCalib;
	int tool_index = 0;
	int imgIndex;
	//存储blob
	vector<cv::KeyPoint> keypoints;
	//使用参数设置检测器
	cv::Ptr<cv::SimpleBlobDetector> detector;
};
