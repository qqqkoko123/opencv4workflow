#pragma once

#include <QDialog>
#include "ui_frmImageSource.h"
#include <opencv2\opencv.hpp>
#include <QButtonGroup>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"
#include <QCameraImageCapture>
#ifdef _WIN64
#pragma comment(lib, "./CommTools/Camera/MindVision/MVCAMSDK_X64.lib")
#else
#pragma comment(lib, "./CommTools/Camera/MindVision/MVCAMSDK.lib")
#endif

struct InitImageSourceData
{
	int camera_index;
	QVector<QString> g_camera;
};
Q_DECLARE_METATYPE(InitImageSourceData);

class frmImageSource : public Toolnterface
{
	Q_OBJECT

public:
	frmImageSource(QString toolName, QToolBase* toolBase, QWidget *parent = Q_NULLPTR);
	~frmImageSource();

private:
	Ui::frmImageSourceClass ui;

public:
	virtual int Execute(const QString toolname);	
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteCameraLink(const QMap<QString, gVariable::Camera_Var> camera_var_link);
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
	void on_btnSelectImage_clicked();
	void on_btnSelectPath_clicked();
	void on_btnSelectCalibPath_clicked();
	void on_btnLinkCameraMatrix_clicked();
	void on_btnDelLinkCameraMatrix_clicked();
	void on_btnLinkDistCoeffs_clicked();
	void on_btnDelLinkDistCoeffs_clicked();
	void on_btnExecute_clicked();	
	void on_btnUpdata_clicked();
	void on_comboCamera_currentIndexChanged(int index);

signals:
	void imageCapturedInMemory(int id, const QImage& image);
	void imageBufferAvailable(int id, const QImage& image);
	void sig_Message();
	void sig_PathMessage();
	void sig_ShowBlockageWarning();
	void sig_HideBlockageWarning();

private slots:
	void onRadioClick(bool);
	void onCalibRadioClick(bool);
	int ReadBuffer(unsigned int m_nBufSizeForSaveImage, void* m_hDevHandle, cv::Mat& image, int timeout);
	int ReadBuffer(unsigned int m_nBufSizeForSaveImage, void* m_hDevHandle, cv::Mat& image, QString key);
	void slot_Message();
	void slot_PathMessage();

private:
	int RunToolPro(QString image_path, const int index);
	bool connectSignals(QCameraImageCapture* imageCapture);
	void onImageCapturedToMemory(int id, const QImage& preview);
	void onImageAvailableInMemory(int id, const QVideoFrame& buffer);
	cv::Mat QImage2Mat(const QImage& image, bool cloneData);
	QImage convertVideoFrameToImage(const QVideoFrame& frame);
	void onImageMetadataAvailable(int id, const QString& key, const QVariant& value);
	void onCaptureError(int id, QCameraImageCapture::Error error, const QString& errorString);
	void hideBlockageWarning();
	void showBlockageWarning();
	bool isCameraBlocked(cv::Mat& frame);
	QImage Mat2QImage(const cv::Mat& mat);
	int m_totalFrames = 0;
	int m_blockedFrames = 0;
private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QButtonGroup* btnGroupRadio;
	QButtonGroup* btnCalibGroupRadio;
	QStringList strs;
	QStringList mImgNames;
	
	cv::Mat dstImage= cv::Mat();
	int tool_index = 0;
	int param_index = 0;
	int imgIndex;
	int init_param_buf;
	cv::Mat cameraMatrixRead, distCoeffsRead;
	QList<QString> keys;	
	int choose_index = -10000;
	int choose_num;
	int cam_state;
	CameraHandle mindvision_haldle;
	void* hikvision_haldle;
	QVector<int*>* hikvision_haldleList = new QVector<int*>();
	QMap<QString, void*> hikvision_map = QMap<QString, void*>();
	QMap<QString, int> hikvision_timeout_map = QMap<QString, int>();
	BYTE* mindvision_framebuffer = nullptr;
	tSdkFrameHead m_sFrInfo_A;	 //用于保存当前图像帧的帧头信息		
	tSdkFrameHead sFrameInfo_A;
	BYTE* pbyBuffer_A;
	CameraSdkStatus status_A;
	int time_out;
	QCameraImageCapture* imageCapture;
public:
	//static cv::Mat srcImg;
	static cv::Mat srcImg; //原图像
		// 用于保存图像的缓存
	//unsigned int m_nBufSizeForSaveImage;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
