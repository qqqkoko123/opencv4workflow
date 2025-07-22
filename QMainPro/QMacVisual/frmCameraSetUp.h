﻿#pragma once

#include <QDialog>
#include "ui_frmCameraSetUp.h"
#include <QButtonGroup>
#include "mytitlebar.h"
#include "gvariable.h"
#include "MvCameraControl.h"
#include "MvCamera.h"
#ifdef _WIN64
#pragma comment(lib, "./CommTools/Camera/MindVision/MVCAMSDK_X64.lib")
#else
#pragma comment(lib, "./CommTools/Camera/MindVision/MVCAMSDK.lib")
#endif

class frmCameraSetUp : public QDialog
{
	Q_OBJECT

public:
	frmCameraSetUp(QWidget* parent = Q_NULLPTR);
	~frmCameraSetUp();

private:
	Ui::frmCameraSetUpClass ui;

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	
	void AddRightButtonMenu();   //右键菜单	
	void moveRow(QTableWidget* pTable, int nFrom, int nTo);

private slots:
	void onButtonCloseClicked();
	void on_btnAddCamera_clicked();
	void on_btnSearchCamera_clicked();
	QString IPIntToStr(uint32_t ipInt);
	void on_btnConnect_clicked();
	void connectHikVison();
	int startCamera();
	int stopCamera();
	int closeCamera();
	int softTrigger();
	int ReadBuffer(cv::Mat& image);
	int getHeight();
	int getWidth();
	float getExposureTime();
	int setHeight(unsigned int height);
	int setWidth(unsigned int width);
	int setOffsetX(unsigned int offsetX);
	int setOffsetY(unsigned int offsetY);
	int setTriggerMode(unsigned int TriggerModeNum);
	int setTriggerSource(unsigned int TriggerSourceNum);
	int setFrameRateEnable(bool comm);
	int setHeartBeatTime(unsigned int time);
	int setExposureTime(float ExposureTimeNum);
	int setExposureAuto(bool exposureAutoFlag);
	int setGainAuto(bool gainAutoFlag);
	void clearBuffer();
	void on_btnDisconnect_clicked();	
	void on_btnSave_clicked();
	void slot_MoveUp();
	void slot_MoveDown();
	void slot_DeleteName();
	void slot_DoubleClicked(int, int);

public slots:
	void InitCameraConnect(QString camera_key_value);
	
private:		
	QList<QString> camera_keys;
	//迈德威视
	CameraHandle mindvision_haldle;
	BYTE* mindvision_framebuffer = nullptr;	
	int mindvision_camera_state;	
	QVector<tSdkCameraDevInfo> sCameraList;
	CameraSdkStatus status;
	tSdkCameraCapbility sCameraInfo;
	int iCameraNums;
	//海康威视
	QVector<MV_CC_DEVICE_INFO_LIST> hCameraList;
	MV_CC_DEVICE_INFO* m_Device = NULL;
	void* m_hDevHandle;
	CMvCamera* m_pcMyCamera = new CMvCamera();
	gVariable gvariable;
public:	
	//相机
	typedef struct CAMERACONTENT
	{		
		int ccd_index;
		int global_exposure;
		double global_gain;
		double global_gamma;
		int global_contrast;
		QString global_trigger_mode;
		int global_timeout;
		QString global_remark;
	} Camera_Content;
	Camera_Content CameraContent;
	QMap<QString, Camera_Content> global_camera_content;
	// 用于保存图像的缓存
	unsigned int m_nBufSizeForSaveImage;
	// 用于从驱动获取图像的缓存
	unsigned int m_nBufSizeForDriver;
};
