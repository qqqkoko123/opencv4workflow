#include "frmProItemTab.h"
#include <QDebug>
#include <QMessageBox>
#include <QStyleFactory>
#include <QGraphicsOpacityEffect>
#include <QFileInfo>
#include <QDateTime>
#include "qlibrary.h"
#include "QToolBase.h"
#include "datavar.h"
#include "gvariable.h"
#include "frmLink.h"

frmProItemTab::frmProItemTab(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//隐藏QTabWidget标签
	ui.ProItemTabWidget->tabBar()->hide();
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.9);
	ui.ProItemTabWidget->setGraphicsEffect(e);
	//Log信号与槽函数
	connect(this, &frmProItemTab::sig_Log, dataVar::fLog, &FrmLog::slot_Message, Qt::AutoConnection);
	connect(this, &frmProItemTab::sig_InfoClick, dataVar::fLog, &FrmLog::slot_InfoClick, Qt::AutoConnection);
	connect(this, &frmProItemTab::sig_WarnClick, dataVar::fLog, &FrmLog::slot_WarnClick, Qt::AutoConnection);
	connect(this, &frmProItemTab::sig_ErrorClick, dataVar::fLog, &FrmLog::slot_ErrorClick, Qt::AutoConnection);
	//显示图像信号与槽函数
	connect(this, &frmProItemTab::sig_ImageShow_B1, dataVar::fImageView, &FrmImageView::ImageShow_B1, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B2, dataVar::fImageView, &FrmImageView::ImageShow_B2, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B3, dataVar::fImageView, &FrmImageView::ImageShow_B3, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B4, dataVar::fImageView, &FrmImageView::ImageShow_B4, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B5, dataVar::fImageView, &FrmImageView::ImageShow_B5, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B6, dataVar::fImageView, &FrmImageView::ImageShow_B6, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B7, dataVar::fImageView, &FrmImageView::ImageShow_B7, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B8, dataVar::fImageView, &FrmImageView::ImageShow_B8, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B9, dataVar::fImageView, &FrmImageView::ImageShow_B9, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B10, dataVar::fImageView, &FrmImageView::ImageShow_B10, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B11, dataVar::fImageView, &FrmImageView::ImageShow_B11, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B12, dataVar::fImageView, &FrmImageView::ImageShow_B12, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B13, dataVar::fImageView, &FrmImageView::ImageShow_B13, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B14, dataVar::fImageView, &FrmImageView::ImageShow_B14, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B15, dataVar::fImageView, &FrmImageView::ImageShow_B15, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B16, dataVar::fImageView, &FrmImageView::ImageShow_B16, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B17, dataVar::fImageView, &FrmImageView::ImageShow_B17, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B18, dataVar::fImageView, &FrmImageView::ImageShow_B18, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B19, dataVar::fImageView, &FrmImageView::ImageShow_B19, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ImageShow_B20, dataVar::fImageView, &FrmImageView::ImageShow_B20, Qt::DirectConnection);
	connect(this, &frmProItemTab::sig_ManualCycleStop, this, &frmProItemTab::slot_ManualCycleStop, Qt::AutoConnection);
	//图像读取错误信号与槽函数
	connect(this, &frmProItemTab::sig_CycleProErr, this, &frmProItemTab::slot_CycleProErr, Qt::AutoConnection);
	//获取流程列表信号与槽函数
	connect(this, &frmProItemTab::sig_CreateList, dataVar::fProcessSetUp, &frmProcessSetUp::slot_CreateList, Qt::AutoConnection);
	//创建手动运行线程
	Thread_A = new QThread(this);
	dataVar::manualCycleThread.moveToThread(Thread_A);  	//把自定义的线程加入到子线程中	
	connect(this, &frmProItemTab::sig_CyclePro, &dataVar::manualCycleThread, &manualThread::funThread_A, Qt::AutoConnection);
	//创建自动运行流程1线程
	Thread_B1 = new QThread(this);
	dataVar::autoCycleThread_B1.moveToThread(Thread_B1);
	connect(this, &frmProItemTab::sig_CyclePro_B1, &dataVar::autoCycleThread_B1, &autoThread_B1::funThread_B1, Qt::AutoConnection);
	//创建自动运行流程2线程
	Thread_B2 = new QThread(this);
	dataVar::autoCycleThread_B2.moveToThread(Thread_B2);
	connect(this, &frmProItemTab::sig_CyclePro_B2, &dataVar::autoCycleThread_B2, &autoThread_B2::funThread_B2, Qt::AutoConnection);
	//创建自动运行流程3线程
	Thread_B3 = new QThread(this);
	dataVar::autoCycleThread_B3.moveToThread(Thread_B3);
	connect(this, &frmProItemTab::sig_CyclePro_B3, &dataVar::autoCycleThread_B3, &autoThread_B3::funThread_B3, Qt::AutoConnection);
	//创建自动运行流程4线程
	Thread_B4 = new QThread(this);
	dataVar::autoCycleThread_B4.moveToThread(Thread_B4);
	connect(this, &frmProItemTab::sig_CyclePro_B4, &dataVar::autoCycleThread_B4, &autoThread_B4::funThread_B4, Qt::AutoConnection);
	//创建自动运行流程5线程
	Thread_B5 = new QThread(this);
	dataVar::autoCycleThread_B5.moveToThread(Thread_B5);
	connect(this, &frmProItemTab::sig_CyclePro_B5, &dataVar::autoCycleThread_B5, &autoThread_B5::funThread_B5, Qt::AutoConnection);
	//创建自动运行流程6线程
	Thread_B6 = new QThread(this);
	dataVar::autoCycleThread_B6.moveToThread(Thread_B6);
	connect(this, &frmProItemTab::sig_CyclePro_B6, &dataVar::autoCycleThread_B6, &autoThread_B6::funThread_B6, Qt::AutoConnection);
	//创建自动运行流程7线程
	Thread_B7 = new QThread(this);
	dataVar::autoCycleThread_B7.moveToThread(Thread_B7);
	connect(this, &frmProItemTab::sig_CyclePro_B7, &dataVar::autoCycleThread_B7, &autoThread_B7::funThread_B7, Qt::AutoConnection);
	//创建自动运行流程8线程
	Thread_B8 = new QThread(this);
	dataVar::autoCycleThread_B8.moveToThread(Thread_B8);
	connect(this, &frmProItemTab::sig_CyclePro_B8, &dataVar::autoCycleThread_B8, &autoThread_B8::funThread_B8, Qt::AutoConnection);
	//创建自动运行流程9线程
	Thread_B9 = new QThread(this);
	dataVar::autoCycleThread_B9.moveToThread(Thread_B9);
	connect(this, &frmProItemTab::sig_CyclePro_B9, &dataVar::autoCycleThread_B9, &autoThread_B9::funThread_B9, Qt::AutoConnection);
	//创建自动运行流程10线程
	Thread_B10 = new QThread(this);
	dataVar::autoCycleThread_B10.moveToThread(Thread_B10);
	connect(this, &frmProItemTab::sig_CyclePro_B10, &dataVar::autoCycleThread_B10, &autoThread_B10::funThread_B10, Qt::AutoConnection);
	//创建自动运行流程11线程
	Thread_B11 = new QThread(this);
	dataVar::autoCycleThread_B11.moveToThread(Thread_B11);
	connect(this, &frmProItemTab::sig_CyclePro_B11, &dataVar::autoCycleThread_B11, &autoThread_B11::funThread_B11, Qt::AutoConnection);
	//创建自动运行流程12线程
	Thread_B12 = new QThread(this);
	dataVar::autoCycleThread_B12.moveToThread(Thread_B12);
	connect(this, &frmProItemTab::sig_CyclePro_B12, &dataVar::autoCycleThread_B12, &autoThread_B12::funThread_B12, Qt::AutoConnection);
	//创建自动运行流程13线程
	Thread_B13 = new QThread(this);
	dataVar::autoCycleThread_B13.moveToThread(Thread_B13);
	connect(this, &frmProItemTab::sig_CyclePro_B13, &dataVar::autoCycleThread_B13, &autoThread_B13::funThread_B13, Qt::AutoConnection);
	//创建自动运行流程14线程
	Thread_B14 = new QThread(this);
	dataVar::autoCycleThread_B14.moveToThread(Thread_B14);
	connect(this, &frmProItemTab::sig_CyclePro_B14, &dataVar::autoCycleThread_B14, &autoThread_B14::funThread_B14, Qt::AutoConnection);
	//创建自动运行流程15线程
	Thread_B15 = new QThread(this);
	dataVar::autoCycleThread_B15.moveToThread(Thread_B15);
	connect(this, &frmProItemTab::sig_CyclePro_B15, &dataVar::autoCycleThread_B15, &autoThread_B15::funThread_B15, Qt::AutoConnection);
	//创建自动运行流程16线程
	Thread_B16 = new QThread(this);
	dataVar::autoCycleThread_B16.moveToThread(Thread_B16);
	connect(this, &frmProItemTab::sig_CyclePro_B16, &dataVar::autoCycleThread_B16, &autoThread_B16::funThread_B16, Qt::AutoConnection);
	//创建自动运行流程17线程
	Thread_B17 = new QThread(this);
	dataVar::autoCycleThread_B17.moveToThread(Thread_B17);
	connect(this, &frmProItemTab::sig_CyclePro_B17, &dataVar::autoCycleThread_B17, &autoThread_B17::funThread_B17, Qt::AutoConnection);
	//创建自动运行流程18线程
	Thread_B18 = new QThread(this);
	dataVar::autoCycleThread_B18.moveToThread(Thread_B18);
	connect(this, &frmProItemTab::sig_CyclePro_B18, &dataVar::autoCycleThread_B18, &autoThread_B18::funThread_B18, Qt::AutoConnection);
	//创建自动运行流程19线程
	Thread_B19 = new QThread(this);
	dataVar::autoCycleThread_B19.moveToThread(Thread_B19);
	connect(this, &frmProItemTab::sig_CyclePro_B19, &dataVar::autoCycleThread_B19, &autoThread_B19::funThread_B19, Qt::AutoConnection);
	//创建自动运行流程20线程
	Thread_B20 = new QThread(this);
	dataVar::autoCycleThread_B20.moveToThread(Thread_B20);
	connect(this, &frmProItemTab::sig_CyclePro_B20, &dataVar::autoCycleThread_B20, &autoThread_B20::funThread_B20, Qt::AutoConnection);
	p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(300);
	p_autotimer = new QTimer(this);
	connect(p_autotimer, SIGNAL(timeout()), this, SLOT(slot_Cutover()));
	//流程列表初始化
	ProcessTreeInit();
	//按钮样式
	QString btnStyle(
		"QWidget{"
		"border: none;"
		"}"
		"QPushButton:hover{"
		"background-color: rgb(199, 208, 233);"
		"}"
		"QPushButton:pressed{"
		"background-color: rgb(152, 170, 216);"
		"}"
	);
	ui.btnAddProFlow->setStyleSheet(btnStyle);
	ui.btnDelProFlow->setStyleSheet(btnStyle);
	ui.btnSetProFlow->setStyleSheet(btnStyle);
	ui.btnRunOnce->setStyleSheet(btnStyle);
	ui.btnRunCycle->setStyleSheet(btnStyle);
	ui.btnStop->setStyleSheet(btnStyle);
}

frmProItemTab::~frmProItemTab()
{
	if (itemParent != nullptr)
	{
		delete itemParent;
	}
	//释放单流程循环运行线程句柄
	if (Thread_A != nullptr)
	{
		Thread_A->terminate();
		Thread_A->deleteLater();
		Thread_A = nullptr;
	}
	//释放多流程循环运行线程句柄	
	if (Thread_B1 != nullptr)
	{
		Thread_B1->terminate();
		Thread_B1->deleteLater();
		Thread_B1 = nullptr;
	}
	if (Thread_B2 != nullptr)
	{
		Thread_B2->terminate();
		Thread_B2->deleteLater();
		Thread_B2 = nullptr;
	}
	if (Thread_B3 != nullptr)
	{
		Thread_B3->terminate();
		Thread_B3->deleteLater();
		Thread_B3 = nullptr;
	}
	if (Thread_B4 != nullptr)
	{
		Thread_B4->terminate();
		Thread_B4->deleteLater();
		Thread_B4 = nullptr;
	}
	if (Thread_B5 != nullptr)
	{
		Thread_B5->terminate();
		Thread_B5->deleteLater();
		Thread_B5 = nullptr;
	}
	if (Thread_B6 != nullptr)
	{
		Thread_B6->terminate();
		Thread_B6->deleteLater();
		Thread_B6 = nullptr;
	}
	if (Thread_B7 != nullptr)
	{
		Thread_B7->terminate();
		Thread_B7->deleteLater();
		Thread_B7 = nullptr;
	}
	if (Thread_B8 != nullptr)
	{
		Thread_B8->terminate();
		Thread_B8->deleteLater();
		Thread_B8 = nullptr;
	}
	if (Thread_B9 != nullptr)
	{
		Thread_B9->terminate();
		Thread_B9->deleteLater();
		Thread_B9 = nullptr;
	}
	if (Thread_B10 != nullptr)
	{
		Thread_B10->terminate();
		Thread_B10->deleteLater();
		Thread_B10 = nullptr;
	}
	if (Thread_B11 != nullptr)
	{
		Thread_B11->terminate();
		Thread_B11->deleteLater();
		Thread_B11 = nullptr;
	}
	if (Thread_B12 != nullptr)
	{
		Thread_B12->terminate();
		Thread_B12->deleteLater();
		Thread_B12 = nullptr;
	}
	if (Thread_B13 != nullptr)
	{
		Thread_B13->terminate();
		Thread_B13->deleteLater();
		Thread_B13 = nullptr;
	}
	if (Thread_B14 != nullptr)
	{
		Thread_B14->terminate();
		Thread_B14->deleteLater();
		Thread_B14 = nullptr;
	}
	if (Thread_B15 != nullptr)
	{
		Thread_B15->terminate();
		Thread_B15->deleteLater();
		Thread_B15 = nullptr;
	}
	if (Thread_B16 != nullptr)
	{
		Thread_B16->terminate();
		Thread_B16->deleteLater();
		Thread_B16 = nullptr;
	}
	if (Thread_B17 != nullptr)
	{
		Thread_B17->terminate();
		Thread_B17->deleteLater();
		Thread_B17 = nullptr;
	}
	if (Thread_B18 != nullptr)
	{
		Thread_B18->terminate();
		Thread_B18->deleteLater();
		Thread_B18 = nullptr;
	}
	if (Thread_B19 != nullptr)
	{
		Thread_B19->terminate();
		Thread_B19->deleteLater();
		Thread_B19 = nullptr;
	}
	if (Thread_B20 != nullptr)
	{
		Thread_B20->terminate();
		Thread_B20->deleteLater();
		Thread_B20 = nullptr;
	}
	if (this != nullptr)
	{
		this->deleteLater();
	}
	for (int i = 0; i < QConfig::ToolBase.size(); i++)
	{
		if (QConfig::ToolBase[i] != nullptr)
		{
			QConfig::ToolBase[i]->deleteLater();
			QConfig::ToolBase[i] = nullptr;
		}
	}
}

void frmProItemTab::timerEvent()
{
	try
	{
#pragma region 图像处理
		//获取图像
		if (nImageSourceState_buf == 1)
		{
			nImageSourceState = getImageSourceState();
			if (nImageSourceState == 1 || nImageSourceState == 2)
			{
				if (nImageSourceState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nImageSourceState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageSourceState();
				nImageSourceState = 0;
			}
		}
		//创建ROI
		if (nCreateRoiState_buf == 1)
		{
			nCreateRoiState = getCreateRoiState();
			if (nCreateRoiState == 1 || nCreateRoiState == 2)
			{
				if (nCreateRoiState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nCreateRoiState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setCreateRoiState();
				nCreateRoiState = 0;
			}
		}
		//裁切图像
		if (nCropImageState_buf == 1)
		{
			nCropImageState = getCropImageState();
			if (nCropImageState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setCropImageState();
				nCropImageState = 0;
			}
		}
		//图像翻转
		if (nImageFlipState_buf == 1)
		{
			nImageFlipState = getImageFlipState();
			if (nImageFlipState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageFlipState();
				nImageFlipState = 0;
			}
		}
		//预处理
		if (nImageMorphologyState_buf == 1)
		{
			nImageMorphologyState = getImageMorphologyState();
			if (nImageMorphologyState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageMorphologyState();
				nImageMorphologyState = 0;
			}
		}
		//图像修复
		if (nImageRepairState_buf == 1)
		{
			nImageRepairState = getImageRepairState();
			if (nImageRepairState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageRepairState();
				nImageRepairState = 0;
			}
		}
		//图像旋转
		if (nImageRotateState_buf == 1)
		{
			nImageRotateState = getImageRotateState();
			if (nImageRotateState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageRotateState();
				nImageRotateState = 0;
			}
		}
		//图像拼接
		if (nImageSpliceState_buf == 1)
		{
			nImageSpliceState = getImageSpliceState();
			if (nImageSpliceState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageSpliceState();
				nImageSpliceState = 0;
			}
		}
		//图像显示
		if (nImageViewState_buf == 1)
		{
			nImageViewState = getImageViewState();
			if (nImageViewState == 1 || nImageViewState == 2 || nImageViewState == 3 || nImageViewState == 4 || nImageViewState == 5)
			{
				if (nImageViewState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nImageViewState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nImageViewState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nImageViewState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nImageViewState == 5)
				{
					dataVar::int_link = 5;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImageViewState();
				nImageViewState = 0;
			}
		}
		//透视变换
		if (nPerspectiveTransformState_buf == 1)
		{
			nPerspectiveTransformState = getPerspectiveTransformState();
			if (nPerspectiveTransformState == 1 || nPerspectiveTransformState == 2 || nPerspectiveTransformState == 3 || nPerspectiveTransformState == 4 || nPerspectiveTransformState == 5 || nPerspectiveTransformState == 6 || nPerspectiveTransformState == 7 || nPerspectiveTransformState == 8 || nPerspectiveTransformState == 9)
			{
				if (nPerspectiveTransformState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nPerspectiveTransformState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nPerspectiveTransformState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nPerspectiveTransformState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nPerspectiveTransformState == 5)
				{
					dataVar::int_link = 5;
				}
				else if (nPerspectiveTransformState == 6)
				{
					dataVar::int_link = 6;
				}
				else if (nPerspectiveTransformState == 7)
				{
					dataVar::int_link = 7;
				}
				else if (nPerspectiveTransformState == 8)
				{
					dataVar::int_link = 8;
				}
				else if (nPerspectiveTransformState == 9)
				{
					dataVar::int_link = 9;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setPerspectiveTransformState();
				nPerspectiveTransformState = 0;
			}
		}
		//图像细化
		if (nSkeletonState_buf == 1)
		{
			nSkeletonState = getSkeletonState();
			if (nSkeletonState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setSkeletonState();
				nSkeletonState = 0;
			}
		}
		//自动打印
		if (nImagePrintState_buf == 1)
		{
			nImagePrintState = getImagePrintState();
			if (nImagePrintState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setImagePrintState();
				nImagePrintState = 0;
			}
		}
		//导出图像
		if (nExportImageState_buf == 1)
		{
			nExportImageState = getExportImageState();
			if (nExportImageState == 1 || nExportImageState == 2)
			{
				if (nExportImageState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nExportImageState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setExportImageState();
				nExportImageState = 0;
			}
		}
#pragma endregion

#pragma region 检测识别
		//条形码识别
		if (nBarcodeIdentifyState_buf == 1)
		{
			nBarcodeIdentifyState = getBarcodeIdentifyState();
			if (nBarcodeIdentifyState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setBarcodeIdentifyState();
				nBarcodeIdentifyState = 0;
			}
		}
		//斑点分析
		if (nBlobDetectorState_buf == 1)
		{
			nBlobDetectorState = getBlobDetectorState();
			if (nBlobDetectorState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setBlobDetectorState();
				nBlobDetectorState = 0;
			}
		}
		//亮度检测
		if (nBrightnessState_buf == 1)
		{
			nBrightnessState = getBrightnessState();
			if (nBrightnessState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setBrightnessState();
				nBrightnessState = 0;
			}
		}
		//颜色识别
		if (nColorIdentifyState_buf == 1)
		{
			nColorIdentifyState = getColorIdentifyState();
			if (nColorIdentifyState == 1 || nColorIdentifyState == 2)
			{
				if (nColorIdentifyState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nColorIdentifyState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setColorIdentifyState();
				nColorIdentifyState = 0;
			}
		}
		//二维码识别
		if (nQRcodeIdentifyState_buf == 1)
		{
			nQRcodeIdentifyState = getQRcodeIdentifyState();
			if (nQRcodeIdentifyState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setQRcodeIdentifyState();
				nQRcodeIdentifyState = 0;
			}
		}
		//二维码生成
		if (nQRcodeGenerateState_buf == 1)
		{
			nQRcodeGenerateState = getQRcodeGenerateState();
			if (nQRcodeGenerateState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setQRcodeGenerateState();
				nQRcodeGenerateState = 0;
			}
		}
		//轮廓特征选择
		if (nSelectShapeState_buf == 1)
		{
			nSelectShapeState = getSelectShape();
			if (nSelectShapeState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setSelectShape();
				nSelectShapeState = 0;
			}
		}
		//分类器
		if (nClassifierState_buf == 1)
		{
			nClassifierState = getClassifierState();
			if (nClassifierState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setClassifierState();
				nClassifierState = 0;
			}
		}
#pragma endregion

#pragma region 标定工具
		//N点标定
		if (nERTCalibrationState_buf == 1)
		{
			nERTCalibrationState = getERTCalibrationState();
			if (nERTCalibrationState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setERTCalibrationState();
				nERTCalibrationState = 0;
			}
		}
		//测量标定
		if (nMeasureCalibrationState_buf == 1)
		{
			nMeasureCalibrationState = getMeasureCalibrationState();
			if (nMeasureCalibrationState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setMeasureCalibrationState();
				nMeasureCalibrationState = 0;
			}
		}
#pragma endregion

#pragma region 对位工具
		//目标跟踪
		if (nCamShiftTrackState_buf == 1)
		{
			nCamShiftTrackState = getCamShiftTrackState();
			if (nCamShiftTrackState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setCamShiftTrackState();
				nCamShiftTrackState = 0;
			}
		}
		//线性计算
		if (nLinearCalculationState_buf == 1)
		{
			nLinearCalculationState = getLinearCalculationState();
			if (nLinearCalculationState == 1 || nLinearCalculationState == 2 || nLinearCalculationState == 3 || nLinearCalculationState == 4 || nLinearCalculationState == 5 || nLinearCalculationState == 6 || nLinearCalculationState == 7 || nLinearCalculationState == 8 || nLinearCalculationState == 9 || nLinearCalculationState == 10)
			{
				if (nLinearCalculationState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLinearCalculationState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nLinearCalculationState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nLinearCalculationState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nLinearCalculationState == 5)
				{
					dataVar::int_link = 5;
				}
				else if (nLinearCalculationState == 6)
				{
					dataVar::int_link = 6;
				}
				else if (nLinearCalculationState == 7)
				{
					dataVar::int_link = 7;
				}
				else if (nLinearCalculationState == 8)
				{
					dataVar::int_link = 8;
				}
				else if (nLinearCalculationState == 9)
				{
					dataVar::int_link = 9;
				}
				else if (nLinearCalculationState == 10)
				{
					dataVar::int_link = 10;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLinearCalculationState();
				nLinearCalculationState = 0;
			}
		}
		//灰度匹配
		if (nTemplateMatchState_buf == 1)
		{
			nTemplateMatchState = getTemplateMatchState();
			if (nTemplateMatchState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setTemplateMatchState();
				nTemplateMatchState = 0;
			}
		}
		//形状匹配
		if (nShapeMatchState_buf == 1)
		{
			nShapeMatchState = getShapeMatchState();
			if (nShapeMatchState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setShapeMatchState();
				nShapeMatchState = 0;
			}
		}
#pragma endregion

#pragma region 几何工具
		//寻找圆
		if (nFindCircleState_buf == 1)
		{
			nFindCircleState = getFindCircleState();
			if (nFindCircleState == 1 || nFindCircleState == 2)
			{
				if (nFindCircleState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFindCircleState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFindCircleState();
				nFindCircleState = 0;
			}
		}
		//寻找直线
		if (nFindLineState_buf == 1)
		{
			nFindLineState = getFindLineState();
			if (nFindLineState == 1 || nFindLineState == 2)
			{
				if (nFindLineState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFindLineState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFindLineState();
				nFindLineState = 0;
			}
		}
		//拟合圆
		if (nFitCircleState_buf == 1)
		{
			nFitCircleState = getFitCircleState();
			if (nFitCircleState == 1 || nFitCircleState == 2)
			{
				if (nFitCircleState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFitCircleState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFitCircleState();
				nFitCircleState = 0;
			}
		}
		//拟合椭圆
		if (nFitEllipseState_buf == 1)
		{
			nFitEllipseState = getFitEllipseState();
			if (nFitEllipseState == 1 || nFitEllipseState == 2)
			{
				if (nFitEllipseState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFitEllipseState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFitEllipseState();
				nFitEllipseState = 0;
			}
		}
		//拟合直线
		if (nFitLineState_buf == 1)
		{
			nFitLineState = getFitLineState();
			if (nFitLineState == 1 || nFitLineState == 2)
			{
				if (nFitLineState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFitLineState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFitLineState();
				nFitLineState = 0;
			}
		}
		//获取边界点
		if (nContourPointsState_buf == 1)
		{
			nContourPointsState = getContourPointsState();
			if (nContourPointsState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setContourPointsState();
				nContourPointsState = 0;
			}
		}
#pragma endregion

#pragma region 几何测量
		//线圆交点
		if (nLineCircleState_buf == 1)
		{
			nLineCircleState = getLineCircleState();
			if (nLineCircleState == 1 || nLineCircleState == 2 || nLineCircleState == 3 || nLineCircleState == 4 || nLineCircleState == 5 || nLineCircleState == 6 || nLineCircleState == 7)
			{
				if (nLineCircleState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLineCircleState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nLineCircleState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nLineCircleState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nLineCircleState == 5)
				{
					dataVar::int_link = 5;
				}
				else if (nLineCircleState == 6)
				{
					dataVar::int_link = 6;
				}
				else if (nLineCircleState == 7)
				{
					dataVar::int_link = 7;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLineCircleState();
				nLineCircleState = 0;
			}
		}
		//线线交点
		if (nLineLineIState_buf == 1)
		{
			nLineLineIState = getLineLineIState();
			if (nLineLineIState == 1 || nLineLineIState == 2 || nLineLineIState == 3 || nLineLineIState == 4 || nLineLineIState == 5 || nLineLineIState == 6 || nLineLineIState == 7 || nLineLineIState == 8 || nLineLineIState == 9)
			{
				if (nLineLineIState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLineLineIState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nLineLineIState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nLineLineIState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nLineLineIState == 5)
				{
					dataVar::int_link = 5;
				}
				else if (nLineLineIState == 6)
				{
					dataVar::int_link = 6;
				}
				else if (nLineLineIState == 7)
				{
					dataVar::int_link = 7;
				}
				else if (nLineLineIState == 8)
				{
					dataVar::int_link = 8;
				}
				else if (nLineLineIState == 9)
				{
					dataVar::int_link = 9;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLineLineIState();
				nLineLineIState = 0;
			}
		}
		//点+线
		if (nPointLineState_buf == 1)
		{
			nPointLineState = getPointLineState();
			if (nPointLineState == 1 || nPointLineState == 2 || nPointLineState == 3 || nPointLineState == 4 || nPointLineState == 5 || nPointLineState == 6)
			{
				if (nPointLineState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nPointLineState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nPointLineState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nPointLineState == 4)
				{
					dataVar::int_link = 4;
				}
				else if (nPointLineState == 5)
				{
					dataVar::int_link = 5;
				}
				else if (nPointLineState == 6)
				{
					dataVar::int_link = 6;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setPointLineState();
				nPointLineState = 0;
			}
		}
		//点+点
		if (nPointPointState_buf == 1)
		{
			nPointPointState = getPointPointState();
			if (nPointPointState == 1 || nPointPointState == 2 || nPointPointState == 3)
			{
				if (nPointPointState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nPointPointState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nPointPointState == 3)
				{
					dataVar::int_link = 3;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setPointPointState();
				nPointPointState = 0;
			}
		}
		//圆缺口角度
		if (nRoundedCornersState_buf == 1)
		{
			nRoundedCornersState = getRoundedCornersState();
			if (nRoundedCornersState == 1 || nRoundedCornersState == 2)
			{
				if (nRoundedCornersState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nRoundedCornersState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setRoundedCornersState();
				nRoundedCornersState = 0;
			}
		}
		//边缘宽度测量
		if (nEdgeWidthMeasureState_buf == 1)
		{
			nEdgeWidthMeasureState = getEdgeWidthMeasureState();
			if (nEdgeWidthMeasureState == 1 || nEdgeWidthMeasureState == 2)
			{
				if (nEdgeWidthMeasureState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nEdgeWidthMeasureState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setEdgeWidthMeasureState();
				nEdgeWidthMeasureState = 0;
			}
		}
#pragma endregion

#pragma region 三维检测
		//拟合平面
		if (nFlatnessState_buf == 1)
		{
			nFlatnessState = getFlatnessState();
			if (nFlatnessState == 1 || nFlatnessState == 2 || nFlatnessState == 3 || nFlatnessState == 4)
			{
				if (nFlatnessState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nFlatnessState == 2)
				{
					dataVar::int_link = 2;
				}
				else if (nFlatnessState == 3)
				{
					dataVar::int_link = 3;
				}
				else if (nFlatnessState == 4)
				{
					dataVar::int_link = 4;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setFlatnessState();
				nFlatnessState = 0;
			}
		}
#pragma endregion

#pragma region 逻辑工具
		//扩展库
		if (nExtensionLibraryState_buf == 1)
		{
			nExtensionLibraryState = getExtensionLibraryState();
			if (nExtensionLibraryState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setExtensionLibraryState();
				nExtensionLibraryState = 0;
			}
		}
		//跳转语句
		if (nLogicGotoState_buf == 1)
		{
			nLogicGotoState = getLogicGotoState();
			if (nLogicGotoState == 1 || nLogicGotoState == 2)
			{
				if (nLogicGotoState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLogicGotoState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLogicGotoState();
				nLogicGotoState = 0;
			}
		}
		//判断语句
		if (nLogicJudgeState_buf == 1)
		{
			nLogicJudgeState = getLogicJudgeState();
			if (nLogicJudgeState == 1 || nLogicJudgeState == 2)
			{
				if (nLogicJudgeState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLogicJudgeState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLogicJudgeState();
				nLogicJudgeState = 0;
			}
		}
		//结束语句
		if (nLogicJudgeEndState_buf == 1)
		{
			nLogicJudgeEndState = getLogicJudgeEndState();
			if (nLogicJudgeEndState == 1 || nLogicJudgeEndState == 2)
			{
				if (nLogicJudgeEndState == 1)
				{
					dataVar::int_link = 1;
				}
				else if (nLogicJudgeEndState == 2)
				{
					dataVar::int_link = 2;
				}
				frmLink* fLink = new frmLink();
				fLink->exec();
				setLogicJudgeEndState();
				nLogicJudgeEndState = 0;
			}
		}
#pragma endregion

#pragma region 通讯工具
		//PLC通信
		if (nPlcCommunicateState_buf == 1)
		{
			nPlcCommunicateState = getPlcCommunicate();
			if (nPlcCommunicateState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setPlcCommunicate();
				nPlcCommunicateState = 0;
			}
		}
		//串口通信
		if (nSerialPortState_buf == 1)
		{
			nSerialPortState = getSerialPort();
			if (nSerialPortState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setSerialPort();
				nSerialPortState = 0;
			}
		}
		//TCP/IP服务器
		if (nSocketTcpServerState_buf == 1)
		{
			nSocketTcpServerState = getSocketTcpServer();
			if (nSocketTcpServerState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setSocketTcpServer();
				nSocketTcpServerState = 0;
			}
		}
		//TCP/IP客户端
		if (nSocketTcpClientState_buf == 1)
		{
			nSocketTcpClientState = getSocketTcpClient();
			if (nSocketTcpClientState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setSocketTcpClient();
				nSocketTcpClientState = 0;
			}
		}
#pragma endregion

#pragma region 系统工具
		//导出CSV
		if (nExportCsvState_buf == 1)
		{
			nExportCsvState = getExportCsv();
			if (nExportCsvState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setExportCsv();
				nExportCsvState = 0;
			}
		}
#pragma endregion	
#pragma region 目标检测
		//YoloV13
		if (nYoloV13State_buf == 1)
		{
			nYoloV13State = getYoloV13();
			if (nYoloV13State == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setYoloV13();
				nYoloV13State = 0;
			}
		}
#pragma endregion
#pragma region OCR
		//OCR
		if (nOCRState_buf == 1)
		{
			nOCRState = getOCR();
			if (nOCRState == 1)
			{
				dataVar::int_link = 1;
				frmLink* fLink = new frmLink();
				fLink->exec();
				setOCR();
				nOCRState = 0;
			}
		}
#pragma endregion
	}
	catch (...) {
		//报错信息
		emit sig_InfoClick();
		emit sig_Log("流程错误！");
	}
}

//流程列表初始化
void frmProItemTab::ProcessTreeInit()
{
	//程序启动记录Log
	emit sig_InfoClick();
	emit sig_Log("主程序启动完成...");
	ui.ProItemTreeWidget->setIconSize(QSize(22, 22));
	//更换系统默认图标
	ui.ProItemTreeWidget->setStyleSheet("QTreeWidget::branch:has-children:!has-siblings:closed,\
	QWidget{border: 1px;border-style: solid;border-color: #d9d9d9}\
	QTreeWidget::item{color: #363636}\
	QTreeWidget::item{height: 26px}\
    QTreeView::item::selected{background-color:#96B5A8}\
	QTreeWidget::branch:closed:has-children:!has-siblings{border-style: none; border-image: none; image: url(:/res/ico/unfold_2.png);}\
	QTreeWidget::branch:closed:has-children:has-siblings{border-image: none; image: url(:/res/ico/unfold_2.png);}\
	QTreeWidget::branch:open:has-children:!has-siblings{border-image: none; image: url(:/res/ico/fold_2.png);}\
	QTreeWidget::branch:open:has-children:has-siblings{border-image: none; image: url(:/res/ico/fold_2.png);}"
		"QScrollBar:vertical{" //设置滚动条样式
		"background:#FFFFF2;"  //背景色  
		"padding-top:20px;"    //上预留位置(放置向上箭头）  
		"padding-bottom:20px;" //下预留位置(放置向下箭头）  
		"padding-left:2px;"    //左预留位置 
		"padding-right:2px;"   //右预留位置 
		"border-left:1px solid #d7d7d7;}" //左分割线  
		"QScrollBar::handle:vertical{" //滑块样式  
		"background:#dbdbdb;"  //滑块颜色  
		"border-radius:6px;"   //边角圆
		"min-height:20px;}"    //滑块最小高度
		"QScrollBar::handle:vertical:hover{" //鼠标触及滑块样式  
		"background:#d0d0d0;}" //滑块颜色  
		"QScrollBar::add-line:vertical{" //向下箭头样式  
		"background:url(:/res/ico/down.png) center no-repeat;}"
		"QScrollBar::sub-line:vertical{" //向上箭头样式
		"background:url(:/res/ico/up.png) center no-repeat;}");
	//设置字体及字体大小
	QFont font("Microsoft YaHei");
	font.setPixelSize(14.5);
	ui.ProItemTreeWidget->setFont(font);
	ui.ProItemTreeWidget->header()->setVisible(false);
	ui.ProItemTreeWidget->clear();
	this->setAcceptDrops(false);
	ui.ProItemTreeWidget->setFixedHeight(28);
	//添加节点	
	itemParent = new QTreeWidgetItem(ui.ProItemTreeWidget);
	itemParent->setText(0, "项目流程方案");
	itemParent->setIcon(0, QIcon(":/res/ico/tool_2.png"));
	itemParent->setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled);
	//信号与槽函数	
	connect(ui.ProItemTreeWidget, &QTreeWidget::itemExpanded, this, &frmProItemTab::slotItemExpanded, Qt::AutoConnection);
	connect(ui.ProItemTreeWidget, &QTreeWidget::itemCollapsed, this, &frmProItemTab::slotItemCollapsed, Qt::AutoConnection);
	connect(ui.ProItemTreeWidget, &QTreeWidget::itemPressed, this, &frmProItemTab::slotItemPressed, Qt::AutoConnection);
}

void frmProItemTab::slotItemExpanded(QTreeWidgetItem* item)
{
	//遍历treeWidget
	QTreeWidgetItemIterator it(ui.ProItemTreeWidget);
	treeList.clear();
	while (*it)
	{
		treeList.append((*it)->text(0));
		++it;
	}
	if (treeList.count() < 11)
	{
		ui.ProItemTreeWidget->setFixedHeight(27 * treeList.count());
	}
	else
	{
		ui.ProItemTreeWidget->setFixedHeight(297);
	}
}

void frmProItemTab::slotItemCollapsed(QTreeWidgetItem* item)
{
	ui.ProItemTreeWidget->setFixedHeight(28);
}

void frmProItemTab::slotItemPressed(QTreeWidgetItem* item, int column)
{
	QTreeWidgetItem* parent = item->parent();
	if (NULL == parent)
		return;
	press_index = parent->indexOfChild(item);
	ui.dockTabWidget->setWindowTitle(parent->child(press_index)->text(0));
	//切换QTabWidget
	ui.ProItemTabWidget->setCurrentIndex(press_index);
	QTreeWidgetItemIterator it(ui.ProItemTreeWidget);  //遍历treeWidget
	QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		QTreeWidgetItem* key = pro_keys[i];
		if ((*it)->child(press_index) == pro_keys[i])
		{
			//获取线程所对应的流程号
			dataVar::dragNumber = m_pro_value.values(key).at(0);
		}
	}
}

void frmProItemTab::slot_Login()
{
	ui.btnAddProFlow->setEnabled(true);
	ui.btnDelProFlow->setEnabled(true);
	ui.btnSetProFlow->setEnabled(true);
	ui.ProItemTabWidget->setEnabled(true);
	ui.btnRunOnce->setEnabled(true);
	ui.btnRunCycle->setEnabled(true);
	ui.btnStop->setEnabled(true);
	ui.ProItemTreeWidget->setEnabled(true);
}

void frmProItemTab::slot_Logout()
{
	ui.btnAddProFlow->setEnabled(false);
	ui.btnDelProFlow->setEnabled(false);
	ui.btnSetProFlow->setEnabled(false);
	ui.ProItemTabWidget->setEnabled(false);
	ui.btnRunOnce->setEnabled(false);
	ui.btnRunCycle->setEnabled(false);
	ui.btnStop->setEnabled(false);
	ui.ProItemTreeWidget->collapseAll();
	ui.ProItemTreeWidget->setEnabled(false);
}

void frmProItemTab::slot_ManualRun()
{
	ui.btnStop->setEnabled(true);
	ui.ProItemTreeWidget->collapseAll();
	ui.ProItemTreeWidget->setEnabled(false);
}

void frmProItemTab::slot_ManualStop()
{
	ui.ProItemTreeWidget->setEnabled(true);
}

ToolNameList frmProItemTab::GetProcessItemNum(const QString itemName)
{
	if (itemName.contains("获取图像")) return ToolNameList::IMAGE_SOURCE;
	if (itemName.contains("图像显示")) return ToolNameList::IMAGE_VIEW;
	if (itemName.contains("导出图像")) return ToolNameList::EXPORT_IMAGE;
	if (itemName.contains("预处理")) return ToolNameList::IMAGE_MORPHOLOGY;
	if (itemName.contains("图像拼接")) return ToolNameList::IMAGE_SPLICE;
	if (itemName.contains("图像修复")) return ToolNameList::IMAGE_REPAIR;
	if (itemName.contains("图像细化")) return ToolNameList::SKELETON;
	if (itemName.contains("图像翻转")) return ToolNameList::IMAGE_FLIP;
	if (itemName.contains("图像旋转")) return ToolNameList::IMAGE_ROTATE;
	if (itemName.contains("透视变换")) return ToolNameList::PERSPECTIVE_TRANSFORM;
	if (itemName.contains("裁切图像")) return ToolNameList::CROP_IMAGE;
	if (itemName.contains("创建ROI")) return ToolNameList::CREATE_ROI;
	if (itemName.contains("条形码识别")) return ToolNameList::BARCODE_IDENTIFY;
	if (itemName.contains("斑点分析")) return ToolNameList::BLOB_DETECTOR;
	if (itemName.contains("二维码识别")) return ToolNameList::QRCODE_IDENTIFY;
	if (itemName.contains("字符识别")) return ToolNameList::OCR_IDENTIFY;
	if (itemName.contains("分类器")) return ToolNameList::CLASSIFIER;
	if (itemName.contains("颜色识别")) return ToolNameList::COLOR_IDENTIFY;
	if (itemName.contains("亮度检测")) return ToolNameList::BRIGHTNESS;
	if (itemName.contains("图像清晰度")) return ToolNameList::IMAGE_CLARITY;
	if (itemName.contains("轮廓特征选择")) return ToolNameList::SELECT_SHAPE;
	if (itemName.contains("N点标定")) return ToolNameList::ERT_CALIBRATION;
	if (itemName.contains("畸变标定")) return ToolNameList::DISTORTION_CALIBRATION;
	if (itemName.contains("测量标定")) return ToolNameList::MEASURE_CALIBRATION;
	if (itemName.contains("灰度匹配")) return ToolNameList::TEMPLATE_MATCH;
	if (itemName.contains("形状匹配")) return ToolNameList::SHAPE_MATCH;
	if (itemName.contains("目标跟踪")) return ToolNameList::CAMSHIFT_TRACK;
	if (itemName.contains("线性计算")) return ToolNameList::LINEAR_CALCULATION;
	if (itemName.contains("线圆交点")) return ToolNameList::LINE_CIRCLE;
	if (itemName.contains("点+点")) return ToolNameList::POINT_POINT;
	if (itemName.contains("点+线")) return ToolNameList::POINT_LINE;
	if (itemName.contains("线线交点")) return ToolNameList::LINE_LINE_I;
	if (itemName.contains("查找圆缺角")) return ToolNameList::ROUNDED_CORNERS;
	if (itemName.contains("寻找圆")) return ToolNameList::FIND_CIRCLE;
	if (itemName.contains("寻找直线")) return ToolNameList::FIND_LINE;
	if (itemName.contains("拟合圆")) return ToolNameList::FIT_CIRCLE;
	if (itemName.contains("拟合椭圆")) return ToolNameList::FIT_ELLIPSE;
	if (itemName.contains("拟合直线")) return ToolNameList::FIT_LINE;
	if (itemName.contains("获取边界点")) return ToolNameList::GET_CONTOUR_POINTS;
	if (itemName.contains("边缘宽度测量")) return ToolNameList::EDGE_WIDTH;
	if (itemName.contains("拟合平面")) return ToolNameList::FLATNESS;
	if (itemName.contains("扩展库")) return ToolNameList::EXTENSION_LIBRARY;
	if (itemName.contains("跳转语句")) return ToolNameList::LOGIC_GOTO;
	if (itemName.contains("判断语句")) return ToolNameList::LOGIC_JUDGE;
	if (itemName.contains("结束语句")) return ToolNameList::LOGIC_JUDGE_END;
	if (itemName.contains("脚本编辑")) return ToolNameList::SCRIPT_EDIT;
	if (itemName.contains("TCP/IP服务器")) return ToolNameList::SOCKET_TCP_SERVER;
	if (itemName.contains("TCP/IP客户端")) return ToolNameList::SOCKET_TCP_CLIENT;
	if (itemName.contains("PLC通信")) return ToolNameList::PLC_COMMUNICATE;
	if (itemName.contains("串口通信")) return ToolNameList::SERIAL_PORT;
	if (itemName.contains("通用I/O")) return ToolNameList::GENERAL_IO;
	if (itemName.contains("延时")) return ToolNameList::DELAY_TOOL;
	if (itemName.contains("导出CSV")) return ToolNameList::EXPORT_CSV;
	if (itemName.contains("YoloV13")) return ToolNameList::YOLOV13;
	if (itemName.contains("OCR")) return ToolNameList::OCR;
	if (itemName.contains("二维码生成")) return ToolNameList::QRCODE_GENERATE;
	if (itemName.contains("自动打印")) return ToolNameList::IMAGE_PRINT;
	return ToolNameList::DEFULT_ERROR;
}

typedef Toolnterface* (*Funs)(QString sToolName, QToolBase* toolBase); //定义函数指针
Toolnterface* frmProItemTab::GetNewToolDlg(const int mode, const QString sToolName, const ToolNameList toolName)
{
	int flow_index = 0;
	if (mode == -10000)
	{
		int flow = ui.ProItemTabWidget->currentIndex();  //索引号	
		QTreeWidgetItemIterator it(ui.ProItemTreeWidget);  //遍历treeWidget
		QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
		for (int i = 0; i < (*it)->childCount(); i++)
		{
			QTreeWidgetItem* key = pro_keys[i];
			if ((*it)->child(flow) == pro_keys[i])
			{
				//获取线程所对应的流程号
				flow_index = m_pro_value.values(key).at(0);
			}
		}
	}
	else
	{
		flow_index = mode;
	}
	switch (toolName)
	{
#pragma region 图像处理
	case IMAGE_SOURCE: {
		//获取图像
		QLibrary mylib("./Plugins/A_ImageSource.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageSourceState = (GetImageSource)mylib.resolve("ShowFormState");
			setImageSourceState = (SetImageSource)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageSourceState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}		
	}break;
	case CREATE_ROI: {
		//创建ROI
		QLibrary mylib("./Plugins/CreateRoi.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getCreateRoiState = (GetCreateRoi)mylib.resolve("ShowFormState");
			setCreateRoiState = (SetCreateRoi)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nCreateRoiState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case CROP_IMAGE: {
		//裁切图像
		QLibrary mylib("./Plugins/CropImage.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getCropImageState = (GetCropImage)mylib.resolve("ShowFormState");
			setCropImageState = (SetCropImage)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nCropImageState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_FLIP: {
		//图像翻转
		QLibrary mylib("./Plugins/ImageFlip.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageFlipState = (GetImageFlip)mylib.resolve("ShowFormState");
			setImageFlipState = (SetImageFlip)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageFlipState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_MORPHOLOGY: {
		//预处理
		QLibrary mylib("./Plugins/ImageMorphology.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageMorphologyState = (GetImageMorphology)mylib.resolve("ShowFormState");
			setImageMorphologyState = (SetImageMorphology)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageMorphologyState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_REPAIR: {
		//图像修复
		QLibrary mylib("./Plugins/ImageRepair.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageRepairState = (GetImageRepair)mylib.resolve("ShowFormState");
			setImageRepairState = (SetImageRepair)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageRepairState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_ROTATE: {
		//图像旋转
		QLibrary mylib("./Plugins/ImageRotate.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageRotateState = (GetImageRotate)mylib.resolve("ShowFormState");
			setImageRotateState = (SetImageRotate)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageRotateState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_SPLICE: {
		//图像拼接
		QLibrary mylib("./Plugins/ImageSplice.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageSpliceState = (GetImageSplice)mylib.resolve("ShowFormState");
			setImageSpliceState = (SetImageSplice)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageSpliceState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_VIEW: {
		//图像显示
		QLibrary mylib("./Plugins/ImageView.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImageViewState = (GetImageView)mylib.resolve("ShowFormState");
			setImageViewState = (SetImageView)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImageViewState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case PERSPECTIVE_TRANSFORM: {
		//透视变换
		QLibrary mylib("./Plugins/PerspectiveTransform.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getPerspectiveTransformState = (GetPerspectiveTransform)mylib.resolve("ShowFormState");
			setPerspectiveTransformState = (SetPerspectiveTransform)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nPerspectiveTransformState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SKELETON: {
		//图像细化
		QLibrary mylib("./Plugins/Skeleton.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getSkeletonState = (GetSkeleton)mylib.resolve("ShowFormState");
			setSkeletonState = (SetSkeleton)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nSkeletonState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case EXPORT_IMAGE: {
		//导出图像
		QLibrary mylib("./Plugins/Z_ExportImage.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getExportImageState = (GetExportImage)mylib.resolve("ShowFormState");
			setExportImageState = (SetExportImage)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nExportImageState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 检测识别
	case BARCODE_IDENTIFY: {
		//条形码识别
		QLibrary mylib("./Plugins/BarcodeIdentify.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getBarcodeIdentifyState = (GetBarcodeIdentify)mylib.resolve("ShowFormState");
			setBarcodeIdentifyState = (SetBarcodeIdentify)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nBarcodeIdentifyState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case BLOB_DETECTOR: {
		//斑点分析
		QLibrary mylib("./Plugins/BlobDetector.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getBlobDetectorState = (GetBlobDetector)mylib.resolve("ShowFormState");
			setBlobDetectorState = (SetBlobDetector)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nBlobDetectorState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case BRIGHTNESS: {
		//亮度检测
		QLibrary mylib("./Plugins/Brightness.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getBrightnessState = (GetBrightness)mylib.resolve("ShowFormState");
			setBrightnessState = (SetBrightness)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nBrightnessState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case COLOR_IDENTIFY: {
		//颜色识别
		QLibrary mylib("./Plugins/ColorIdentify.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getColorIdentifyState = (GetColorIdentify)mylib.resolve("ShowFormState");
			setColorIdentifyState = (SetColorIdentify)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nColorIdentifyState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_CLARITY: {
		//图像清晰度
		QLibrary mylib("./Plugins/ImageClarity.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case OCR_IDENTIFY: {
		//字符识别
		QLibrary mylib("./Plugins/OCRIdentify.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case QRCODE_IDENTIFY: {
		//二维码识别
		QLibrary mylib("./Plugins/QRcodeIdentify.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getQRcodeIdentifyState = (GetQRcodeIdentify)mylib.resolve("ShowFormState");
			setQRcodeIdentifyState = (SetQRcodeIdentify)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nQRcodeIdentifyState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case QRCODE_GENERATE: {
		//二维码生成
		QLibrary mylib("./Plugins/QRcodeGenerate.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getQRcodeGenerateState = (GetQRcodeGenerate)mylib.resolve("ShowFormState");
			setQRcodeGenerateState = (SetQRcodeGenerate)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nQRcodeGenerateState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case IMAGE_PRINT: {
		//自动打印
		QLibrary mylib("./Plugins/ImagePrint.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getImagePrintState = (GetImagePrint)mylib.resolve("ShowFormState");
			setImagePrintState = (SetImagePrint)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nImagePrintState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SELECT_SHAPE: {
		//轮廓特征选择
		QLibrary mylib("./Plugins/SelectShape.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getSelectShape = (GetSelectShape)mylib.resolve("ShowFormState");
			setSelectShape = (SetSelectShape)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nSelectShapeState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case CLASSIFIER: {
		//分类器
		QLibrary mylib("./Plugins/Z_Classifier.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getClassifierState = (GetClassifier)mylib.resolve("ShowFormState");
			setClassifierState = (SetClassifier)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nClassifierState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 标定工具
	case DISTORTION_CALIBRATION: {
		//畸变标定
		QLibrary mylib("./Plugins/DistortionCalibration.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case ERT_CALIBRATION: {
		//N点标定
		QLibrary mylib("./Plugins/ERTCalibration.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getERTCalibrationState = (GetERTCalibration)mylib.resolve("ShowFormState");
			setERTCalibrationState = (SetERTCalibration)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nERTCalibrationState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case MEASURE_CALIBRATION: {
		//测量标定
		QLibrary mylib("./Plugins/MeasureCalibration.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getMeasureCalibrationState = (GetMeasureCalibration)mylib.resolve("ShowFormState");
			setMeasureCalibrationState = (SetMeasureCalibration)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nMeasureCalibrationState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 对位工具
	case CAMSHIFT_TRACK: {
		//目标跟踪
		QLibrary mylib("./Plugins/CamShiftTrack.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getCamShiftTrackState = (GetCamShiftTrack)mylib.resolve("ShowFormState");
			setCamShiftTrackState = (SetCamShiftTrack)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nCamShiftTrackState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case LINEAR_CALCULATION: {
		//线性计算
		QLibrary mylib("./Plugins/LinearCalculation.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLinearCalculationState = (GetLinearCalculation)mylib.resolve("ShowFormState");
			setLinearCalculationState = (SetLinearCalculation)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLinearCalculationState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case TEMPLATE_MATCH: {
		//灰度匹配
		QLibrary mylib("./Plugins/TemplateMatch.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getTemplateMatchState = (GetTemplateMatch)mylib.resolve("ShowFormState");
			setTemplateMatchState = (SetTemplateMatch)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nTemplateMatchState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SHAPE_MATCH: {
		//形状匹配
		QLibrary mylib("./Plugins/ShapeMatch.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getShapeMatchState = (GetShapeMatch)mylib.resolve("ShowFormState");
			setShapeMatchState = (SetShapeMatch)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nShapeMatchState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion	

#pragma region 几何工具
	case FIND_CIRCLE: {
		//寻找圆
		QLibrary mylib("./Plugins/FindCircle.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFindCircleState = (GetFindCircle)mylib.resolve("ShowFormState");
			setFindCircleState = (SetFindCircle)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFindCircleState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case FIND_LINE: {
		//寻找直线
		QLibrary mylib("./Plugins/FindLine.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFindLineState = (GetFindLine)mylib.resolve("ShowFormState");
			setFindLineState = (SetFindLine)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFindLineState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case FIT_CIRCLE: {
		//拟合圆
		QLibrary mylib("./Plugins/FitCircle.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFitCircleState = (GetFitCircle)mylib.resolve("ShowFormState");
			setFitCircleState = (SetFitCircle)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFitCircleState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case FIT_ELLIPSE: {
		//拟合椭圆
		QLibrary mylib("./Plugins/FitEllipse.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFitEllipseState = (GetFitEllipse)mylib.resolve("ShowFormState");
			setFitEllipseState = (SetFitEllipse)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFitEllipseState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case FIT_LINE: {
		//拟合直线
		QLibrary mylib("./Plugins/FitLine.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFitLineState = (GetFitLine)mylib.resolve("ShowFormState");
			setFitLineState = (SetFitLine)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFitLineState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case GET_CONTOUR_POINTS: {
		//获取边界点
		QLibrary mylib("./Plugins/GetContourPoints.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getContourPointsState = (GetContourPoints)mylib.resolve("ShowFormState");
			setContourPointsState = (SetContourPoints)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nContourPointsState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 几何测量
	case LINE_CIRCLE: {
		//线圆交点
		QLibrary mylib("./Plugins/LineCircle.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLineCircleState = (GetLineCircle)mylib.resolve("ShowFormState");
			setLineCircleState = (SetLineCircle)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLineCircleState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case LINE_LINE_I: {
		//线线交点
		QLibrary mylib("./Plugins/LineLineI.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLineLineIState = (GetLineLineI)mylib.resolve("ShowFormState");
			setLineLineIState = (SetLineLineI)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLineLineIState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case POINT_LINE: {
		//点+线
		QLibrary mylib("./Plugins/PointLine.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getPointLineState = (GetPointLine)mylib.resolve("ShowFormState");
			setPointLineState = (SetPointLine)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nPointLineState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case POINT_POINT: {
		//点+点
		QLibrary mylib("./Plugins/PointPoint.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getPointPointState = (GetPointPoint)mylib.resolve("ShowFormState");
			setPointPointState = (SetPointPoint)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nPointPointState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case ROUNDED_CORNERS: {
		//查找圆缺角
		QLibrary mylib("./Plugins/RoundedCorners.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getRoundedCornersState = (GetRoundedCorners)mylib.resolve("ShowFormState");
			setRoundedCornersState = (SetRoundedCorners)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nRoundedCornersState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case EDGE_WIDTH: {
		//边缘宽度测量
		QLibrary mylib("./Plugins/Z_EdgeWidthMeasure.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getEdgeWidthMeasureState = (GetEdgeWidthMeasure)mylib.resolve("ShowFormState");
			setEdgeWidthMeasureState = (SetEdgeWidthMeasure)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nEdgeWidthMeasureState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 三维检测
	case FLATNESS: {
		//拟合面度
		QLibrary mylib("./Plugins/Flatness.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getFlatnessState = (GetFlatness)mylib.resolve("ShowFormState");
			setFlatnessState = (SetFlatness)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nFlatnessState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 逻辑工具
	case EXTENSION_LIBRARY: {
		//扩展库
		QLibrary mylib("./Plugins/ExtensionLibrary.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getExtensionLibraryState = (GetExtensionLibrary)mylib.resolve("ShowFormState");
			setExtensionLibraryState = (SetExtensionLibrary)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nExtensionLibraryState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case LOGIC_GOTO: {
		//跳转语句
		QLibrary mylib("./Plugins/LogicGoto.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLogicGotoState = (GetLogicGoto)mylib.resolve("ShowFormState");
			setLogicGotoState = (SetLogicGoto)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLogicGotoState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case LOGIC_JUDGE: {
		//判断语句
		QLibrary mylib("./Plugins/LogicJudge.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLogicJudgeState = (GetLogicJudge)mylib.resolve("ShowFormState");
			setLogicJudgeState = (SetLogicJudge)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLogicJudgeState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case LOGIC_JUDGE_END: {
		//结束语句
		QLibrary mylib("./Plugins/LogicJudgeEnd.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getLogicJudgeEndState = (GetLogicJudgeEnd)mylib.resolve("ShowFormState");
			setLogicJudgeEndState = (SetLogicJudgeEnd)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nLogicJudgeEndState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SCRIPT_EDIT: {
		//脚本编辑
		QLibrary mylib("./Plugins/ScriptEdit.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 通讯工具
	case GENERAL_IO: {
		//通用I/O
		QLibrary mylib("./Plugins/GeneralIo.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case PLC_COMMUNICATE: {
		//PLC通信
		QLibrary mylib("./Plugins/PlcCommunicate.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getPlcCommunicate = (GetPlcCommunicate)mylib.resolve("ShowFormState");
			setPlcCommunicate = (SetPlcCommunicate)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nPlcCommunicateState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SERIAL_PORT: {
		//串口通信
		QLibrary mylib("./Plugins/SerialPort.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getSerialPort = (GetSerialPort)mylib.resolve("ShowFormState");
			setSerialPort = (SetSerialPort)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nSerialPortState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SOCKET_TCP_SERVER: {
		//TCP/IP服务器
		QLibrary mylib("./Plugins/SocketTcpServer.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getSocketTcpServer = (GetSocketTcpServer)mylib.resolve("ShowFormState");
			setSocketTcpServer = (SetSocketTcpServer)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nSocketTcpServerState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case SOCKET_TCP_CLIENT: {
		//TCP/IP客户端
		QLibrary mylib("./Plugins/SocketTcpClient.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getSocketTcpClient = (GetSocketTcpClient)mylib.resolve("ShowFormState");
			setSocketTcpClient = (SetSocketTcpClient)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nSocketTcpClientState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 系统工具
	case DELAY_TOOL: {
		//延时
		QLibrary mylib("./Plugins/DelayTool.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
	case EXPORT_CSV: {
		//导出CSV
		QLibrary mylib("./Plugins/ExportCsv.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getExportCsv = (GetExportCsv)mylib.resolve("ShowFormState");
			setExportCsv = (SetExportCsv)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nExportCsvState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion

#pragma region 目标检测
	case YOLOV13: {
		//YoloV13
		QLibrary mylib("./Plugins/YoloV13.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getYoloV13 = (GetYoloV13)mylib.resolve("ShowFormState");
			setYoloV13 = (SetYoloV13)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nYoloV13State_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion
#pragma region OCR
	case OCR: {
		//OCR
		QLibrary mylib("./Plugins/OCR.dll");   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			getOCR = (GetOCR)mylib.resolve("ShowFormState");
			setOCR = (SetOCR)mylib.resolve("SetFormState");
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				nOCRState_buf = 1;
				Toolnterface* frmPage = open(sToolName, QConfig::ToolBase[flow_index]);
				frmPage->setObjectName(sToolName);
				return frmPage;
			}
		}
	}break;
#pragma endregion
	default: break;
	}
	return new Toolnterface(sToolName, QConfig::ToolBase[flow_index], this);
}

//修改流程名称
void frmProItemTab::slot_UpdateQTreeWidget(const QString key_old_name, const QString key_new_name)
{
	//Tab流程
	FlowTabMapBuf.clear();
	QList<QString> keys = FlowTabMap.uniqueKeys();
	for (int k = 0; k < keys.length(); k++)
	{
		QString key = keys[k];
		QList<QToolBase*> values = FlowTabMap.values(key);
		for (int j = 0; j < values.length(); j++)
		{
			if (key == key_old_name)
			{
				key = key_new_name;
			}
			FlowTabMapBuf.insertMulti(key, values.at(j));
		}
	}
	FlowTabMap.swap(FlowTabMapBuf);
	//程序流程
	FlowProMapBuf.clear();
	QList<QString> pro_keys = dataVar::FlowProMap.uniqueKeys();
	for (int k = 0; k < pro_keys.length(); k++)
	{
		QString key = pro_keys[k];
		QList<QtDragListWidget*> values = dataVar::FlowProMap.values(key);
		for (int j = 0; j < values.length(); j++)
		{
			if (key == key_old_name)
			{
				key = key_new_name;
			}
			FlowProMapBuf.insertMulti(key, values.at(j));
		}
	}
	dataVar::FlowProMap.swap(FlowProMapBuf);
}

//反序列化初始化流程
void frmProItemTab::DeserializeInitProcess()
{
	//选项样式
	QString tabStyle(
		"QWidget{"
		"background-color:rgb(240, 248, 226);"
         "}"
		"QTabBar::tab{"
		"background-color:rgb(240, 248, 226);color:rgb(70, 70, 70);"	
		"}"
		"QTabBar::tab:selected{"
		"background:rgb(129, 188, 133);color:rgb(60, 60, 60);"
		"}"
	);
	ui.ProItemTabWidget->setAttribute(Qt::WA_StyledBackground);
	ui.ProItemTabWidget->setStyleSheet(tabStyle);		
	ui.ProItemTreeWidget->setStyle(QStyleFactory::create("windows"));  //显示虚线	
	ui.ProItemTreeWidget->expandAll();	
	if (itemParent->childCount() != 0)
	{
		ui.dockTabWidget->setWindowTitle(treeItem[0]->text(0));
		ui.ProItemTabWidget->setCurrentIndex(0);
	}	
	//流程图
	for (int k = 0; k < itemParent->childCount(); k++)
	{
		if (treeItem[k]->text(0).mid(0, 5) == "新建流程-" && treeItem[k]->text(0).size() == 6)
		{
			fNameList.append(treeItem[k]->text(0));
		}
		QToolBase* NewToolBase = new QToolBase;
		QString flowName = treeItem[k]->text(0);
		NewToolBase->setObjectName(flowName);
		FlowTabMap.insert(flowName, NewToolBase);
		QConfig::ToolBase[k] = NewToolBase;
		dataVar::dragNumber = k;
		dataVar::all_link_process.insert(k, k);
		QtDragListWidget* NewFlowListWidget = new QtDragListWidget;
		NewFlowListWidget->setObjectName(flowName);		
		connect(NewFlowListWidget, SIGNAL(sig_ActionProItem(int, QString, bool)),
			this, SLOT(slot_ActionProItem(int, QString, bool)));		
		ui.ProItemTabWidget->insertTab(k, NewFlowListWidget, flowName);			
		dataVar::FlowProMap.insert(flowName, NewFlowListWidget);		
		switch (k) {
		case 0:
			connect(QConfig::ToolBase[0], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B1 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubText_B1, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubIcon_B1, Qt::DirectConnection);
			break;
		case 1:
			connect(QConfig::ToolBase[1], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B2 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubText_B2, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubIcon_B2, Qt::DirectConnection);
			break;
		case 2:
			connect(QConfig::ToolBase[2], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B3 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubText_B3, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubIcon_B3, Qt::DirectConnection);
			break;
		case 3:
			connect(QConfig::ToolBase[3], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B4 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubText_B4, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubIcon_B4, Qt::DirectConnection);
			break;
		case 4:
			connect(QConfig::ToolBase[4], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B5 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubText_B5, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubIcon_B5, Qt::DirectConnection);
			break;
		case 5:
			connect(QConfig::ToolBase[5], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B6 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubText_B6, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubIcon_B6, Qt::DirectConnection);
			break;
		case 6:
			connect(QConfig::ToolBase[6], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B7 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubText_B7, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubIcon_B7, Qt::DirectConnection);
			break;
		case 7:
			connect(QConfig::ToolBase[7], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B8 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubText_B8, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubIcon_B8, Qt::DirectConnection);
			break;
		case 8:
			connect(QConfig::ToolBase[8], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B9 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubText_B9, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubIcon_B9, Qt::DirectConnection);
			break;
		case 9:
			connect(QConfig::ToolBase[9], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B10 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubText_B10, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubIcon_B10, Qt::DirectConnection);
			break;
		case 10:
			connect(QConfig::ToolBase[10], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B11 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubText_B11, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubIcon_B11, Qt::DirectConnection);
			break;
		case 11:
			connect(QConfig::ToolBase[11], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B12 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubText_B12, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubIcon_B12, Qt::DirectConnection);
			break;
		case 12:
			connect(QConfig::ToolBase[12], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B13 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubText_B13, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubIcon_B13, Qt::DirectConnection);
			break;
		case 13:
			connect(QConfig::ToolBase[13], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B14 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubText_B14, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubIcon_B14, Qt::DirectConnection);
			break;
		case 14:
			connect(QConfig::ToolBase[14], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B15 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubText_B15, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubIcon_B15, Qt::DirectConnection);
			break;
		case 15:
			connect(QConfig::ToolBase[15], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B16 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubText_B16, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubIcon_B16, Qt::DirectConnection);
			break;
		case 16:
			connect(QConfig::ToolBase[16], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B17 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubText_B17, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubIcon_B17, Qt::DirectConnection);
			break;
		case 17:
			connect(QConfig::ToolBase[17], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B18 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubText_B18, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubIcon_B18, Qt::DirectConnection);
			break;
		case 18:
			connect(QConfig::ToolBase[18], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B19 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubText_B19, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubIcon_B19, Qt::DirectConnection);
			break;
		case 19:
			connect(QConfig::ToolBase[19], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B20 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubText_B20, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubIcon_B20, Qt::DirectConnection);
			break;
		}
	}	
}

//获取随机字符
QString frmProItemTab::getRandomString()
{
	qsrand(QDateTime::currentMSecsSinceEpoch());
	const char ch[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int size = sizeof(ch);
	QString str;
	int num = 0;
	num = rand() % (size - 1);
	str = ch[num];
	return str;
}

//新建流程
void frmProItemTab::on_btnAddProFlow_clicked()
{
	if (dataVar::projectName == QString())
	{
		emit sig_WarnClick();
		emit sig_Log("新建流程时，请先新建项目！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请先新建项目！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	//判断有无空流程
	bool bolFlowState = false;
	if (dataVar::FlowProMap.size() == 0)
	{
		bolFlowState = true;
	}
	else
	{
		QVector<QString>  FlowProItemListX = QVector<QString>(100);
		FlowProItemListX.clear();
		QMap<QString, QtDragListWidget*>::iterator iterX = dataVar::FlowProMap.begin();
		while (iterX != dataVar::FlowProMap.end())
		{
			TempDragListWidget = iterX.value();
			FlowProItemListX = TempDragListWidget->GetAllItemList();
			if (FlowProItemListX.count() == 0)
			{
				bolFlowState = false;
				break;
			}
			else
			{
				bolFlowState = true;
			}
			iterX++;
		}
	}
	if (bolFlowState == true)
	{
		int i = itemParent->childCount();
		if (i >= 20)
		{
			emit sig_WarnClick();
			emit sig_Log("新建流程时，最多创建20个流程！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "最多创建20个流程！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
		//删除流程后重新计算
		if (m_process_buf.count() != 0)
		{
			//按升序排序
			qSort(m_process_buf.begin(), m_process_buf.end());
			//最小值
			i = m_process_buf[0];
			m_process_buf.removeAt(0);
		}
		//项目流程方案
	loop:
		QString fName = getRandomString();
		for (int n = 0; n < fNameList.count(); n++)
		{
			if (fNameList[n] == fName)
			{
				goto loop;
			}
		}
		fNameList.append(fName);
		QString flowName = "新建流程-" + fName;
		emit sig_InfoClick();
		emit sig_Log(flowName + "创建完成...");
		ui.ProItemTreeWidget->setStyle(QStyleFactory::create("windows"));  //显示虚线			
		treeItem[i] = new QTreeWidgetItem();
		treeItem[i]->setText(0, flowName);
		treeItem[i]->setIcon(0, QIcon(":/res/ico/arrow_p.png"));
		itemParent->insertChild(i, treeItem[i]);
		ui.ProItemTreeWidget->expandAll();		
		//记录流程对应的索引值
		m_pro_value.insert(treeItem[i], i);
		//流程图
		QToolBase* NewToolBase = new QToolBase;
		NewToolBase->setObjectName(flowName);
		FlowTabMap.insert(flowName, NewToolBase);
		QConfig::ToolBase[i] = NewToolBase;
		dataVar::dragNumber = i;
		dataVar::all_link_process.insert(i, i);
		QtDragListWidget* NewFlowListWidget = new QtDragListWidget;
		NewFlowListWidget->setObjectName(flowName);
		connect(NewFlowListWidget, SIGNAL(sig_ActionProItem(int, QString, bool)),
			this, SLOT(slot_ActionProItem(int, QString, bool)));
		//选项样式
		QString tabStyle(		
			"QTabBar::tab{"
			"background-color:rgb(240, 248, 226);color:rgb(70, 70, 70);"		
			"}"
			"QTabBar::tab:selected{"
			"background:rgb(129, 188, 133);color:rgb(60, 60, 60);"
			"}"
		);
		ui.ProItemTabWidget->setAttribute(Qt::WA_StyledBackground);			
		ui.ProItemTabWidget->setStyleSheet(tabStyle);
		ui.ProItemTabWidget->insertTab(i, NewFlowListWidget, flowName);		
		dataVar::FlowProMap.insert(flowName, NewFlowListWidget);
		if (itemParent->childCount() != 0)
		{
			ui.dockTabWidget->setWindowTitle(flowName);
			ui.ProItemTabWidget->setCurrentIndex(i);
		}
		switch (i) {
		case 0:			
			connect(QConfig::ToolBase[0], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[0], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B1 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubText_B1, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubIcon_B1, Qt::DirectConnection);
			break;
		case 1:
			connect(QConfig::ToolBase[1], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[1], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B2 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubText_B2, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubIcon_B2, Qt::DirectConnection);
			break;
		case 2:
			connect(QConfig::ToolBase[2], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[2], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B3 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubText_B3, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubIcon_B3, Qt::DirectConnection);
			break;
		case 3:
			connect(QConfig::ToolBase[3], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[3], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B4 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubText_B4, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubIcon_B4, Qt::DirectConnection);
			break;
		case 4:
			connect(QConfig::ToolBase[4], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[4], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B5 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubText_B5, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubIcon_B5, Qt::DirectConnection);
			break;
		case 5:
			connect(QConfig::ToolBase[5], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[5], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B6 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubText_B6, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubIcon_B6, Qt::DirectConnection);
			break;
		case 6:
			connect(QConfig::ToolBase[6], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[6], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B7 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubText_B7, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubIcon_B7, Qt::DirectConnection);
			break;
		case 7:
			connect(QConfig::ToolBase[7], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[7], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B8 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubText_B8, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubIcon_B8, Qt::DirectConnection);
			break;
		case 8:
			connect(QConfig::ToolBase[8], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[8], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B9 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubText_B9, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubIcon_B9, Qt::DirectConnection);
			break;
		case 9:
			connect(QConfig::ToolBase[9], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[9], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B10 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubText_B10, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubIcon_B10, Qt::DirectConnection);
			break;
		case 10:
			connect(QConfig::ToolBase[10], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[10], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B11 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubText_B11, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubIcon_B11, Qt::DirectConnection);
			break;
		case 11:
			connect(QConfig::ToolBase[11], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[11], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B12 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubText_B12, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubIcon_B12, Qt::DirectConnection);
			break;
		case 12:
			connect(QConfig::ToolBase[12], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[12], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B13 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubText_B13, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubIcon_B13, Qt::DirectConnection);
			break;
		case 13:
			connect(QConfig::ToolBase[13], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[13], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B14 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubText_B14, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubIcon_B14, Qt::DirectConnection);
			break;
		case 14:
			connect(QConfig::ToolBase[14], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[14], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B15 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubText_B15, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubIcon_B15, Qt::DirectConnection);
			break;
		case 15:
			connect(QConfig::ToolBase[15], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[15], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B16 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubText_B16, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubIcon_B16, Qt::DirectConnection);
			break;
		case 16:
			connect(QConfig::ToolBase[16], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[16], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B17 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubText_B17, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubIcon_B17, Qt::DirectConnection);
			break;
		case 17:
			connect(QConfig::ToolBase[17], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[17], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B18 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubText_B18, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubIcon_B18, Qt::DirectConnection);
			break;
		case 18:
			connect(QConfig::ToolBase[18], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[18], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B19 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubText_B19, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubIcon_B19, Qt::DirectConnection);
			break;
		case 19:
			connect(QConfig::ToolBase[19], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn, Qt::DirectConnection);
			connect(QConfig::ToolBase[19], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error, Qt::DirectConnection);
			TempDragListWidget_B20 = NewFlowListWidget;
			connect(this, &frmProItemTab::sig_TextShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubText_B20, Qt::DirectConnection);
			connect(this, &frmProItemTab::sig_IconShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubIcon_B20, Qt::DirectConnection);
			break;
		}
	}
	else
	{
		emit sig_WarnClick();
		emit sig_Log("新建流程时，流程未建立程序！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "流程未建立程序！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
	}
}

//删除流程
void frmProItemTab::on_btnDelProFlow_clicked()
{
	//删除QTreeWidget
	QTreeWidgetItem* currentItem = ui.ProItemTreeWidget->currentItem();
	if (currentItem == NULL || currentItem->parent() == nullptr)
	{
		emit sig_ErrorClick();
		emit sig_Log("流程未选定或无流程可删！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "流程未选定或无流程可删！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	int flow_index = currentItem->parent()->indexOfChild(currentItem);  //索引号
	int flow = 0;
	//删除流程对应的索引值	
	QTreeWidgetItemIterator it(ui.ProItemTreeWidget);  //遍历treeWidget
	QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		QTreeWidgetItem* key = pro_keys[i];
		if ((*it)->child(flow_index) == pro_keys[i])
		{
			flow = m_pro_value.values(key).at(0);
			m_pro_value.remove((*it)->child(flow_index));
		}
	}
	//删除子节点	
	delete currentItem->parent()->takeChild(ui.ProItemTreeWidget->currentIndex().row());
	slotItemExpanded(itemParent);
	//删除QTabWidget
	QString flowPageName = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
	emit sig_InfoClick();
	emit sig_Log(flowPageName + "删除完成...");
	dataVar::FlowProMap.remove(flowPageName);
	FlowTabMap.remove(flowPageName);
	if (flowPageName.mid(0, 5) == "新建流程-" && flowPageName.size() == 6)
	{
		fNameList.removeOne(flowPageName.mid(5,1));
	}
	ui.ProItemTabWidget->removeTab(ui.ProItemTabWidget->currentIndex());
	m_process_buf.append(flow);
	dataVar::all_link_process.remove(flow);
	for (int i = 0; i < QConfig::ToolBase[flow]->m_Tools.size(); i++)
	{
		QConfig::ToolBase[flow]->m_Tools[i].PublicToolDlg->deleteLater();
	}
	QConfig::ToolBase[flow]->m_FlowSortList.clear();
	QConfig::ToolBase[flow]->m_Tools.clear();	
	treeItem[flow] = nullptr;
	switch (flow) {
	case 0:
		disconnect(QConfig::ToolBase[0], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[0], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[0], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[0], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);		
		disconnect(this, &frmProItemTab::sig_TextShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubText_B1);
		disconnect(this, &frmProItemTab::sig_IconShow_B1, TempDragListWidget_B1, &QtDragListWidget::SetItemSubIcon_B1);
		delete TempDragListWidget_B1;
		TempDragListWidget_B1 = nullptr;
		break;
	case 1:
		disconnect(QConfig::ToolBase[1], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[1], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[1], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[1], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubText_B2);
		disconnect(this, &frmProItemTab::sig_IconShow_B2, TempDragListWidget_B2, &QtDragListWidget::SetItemSubIcon_B2);
		delete TempDragListWidget_B2;
		TempDragListWidget_B2 = nullptr;
		break;
	case 2:
		disconnect(QConfig::ToolBase[2], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[2], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[2], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[2], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubText_B3);
		disconnect(this, &frmProItemTab::sig_IconShow_B3, TempDragListWidget_B3, &QtDragListWidget::SetItemSubIcon_B3);
		delete TempDragListWidget_B3;
		TempDragListWidget_B3 = nullptr;
		break;
	case 3:
		disconnect(QConfig::ToolBase[3], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[3], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[3], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[3], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubText_B4);
		disconnect(this, &frmProItemTab::sig_IconShow_B4, TempDragListWidget_B4, &QtDragListWidget::SetItemSubIcon_B4);
		delete TempDragListWidget_B4;
		TempDragListWidget_B4 = nullptr;
		break;
	case 4:
		disconnect(QConfig::ToolBase[4], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[4], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[4], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[4], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubText_B5);
		disconnect(this, &frmProItemTab::sig_IconShow_B5, TempDragListWidget_B5, &QtDragListWidget::SetItemSubIcon_B5);
		delete TempDragListWidget_B5;
		TempDragListWidget_B5 = nullptr;
		break;
	case 5:
		disconnect(QConfig::ToolBase[5], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[5], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[5], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[5], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubText_B6);
		disconnect(this, &frmProItemTab::sig_IconShow_B6, TempDragListWidget_B6, &QtDragListWidget::SetItemSubIcon_B6);
		delete TempDragListWidget_B6;
		TempDragListWidget_B6 = nullptr;
		break;
	case 6:
		disconnect(QConfig::ToolBase[6], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[6], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[6], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[6], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubText_B7);
		disconnect(this, &frmProItemTab::sig_IconShow_B7, TempDragListWidget_B7, &QtDragListWidget::SetItemSubIcon_B7);
		delete TempDragListWidget_B7;
		TempDragListWidget_B7 = nullptr;
		break;
	case 7:
		disconnect(QConfig::ToolBase[7], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[7], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[7], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[7], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubText_B8);
		disconnect(this, &frmProItemTab::sig_IconShow_B8, TempDragListWidget_B8, &QtDragListWidget::SetItemSubIcon_B8);
		delete TempDragListWidget_B8;
		TempDragListWidget_B8 = nullptr;
		break;
	case 8:
		disconnect(QConfig::ToolBase[8], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[8], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[8], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[8], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubText_B9);
		disconnect(this, &frmProItemTab::sig_IconShow_B9, TempDragListWidget_B9, &QtDragListWidget::SetItemSubIcon_B9);
		delete TempDragListWidget_B9;
		TempDragListWidget_B9 = nullptr;
		break;
	case 9:
		disconnect(QConfig::ToolBase[9], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[9], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[9], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[9], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubText_B10);
		disconnect(this, &frmProItemTab::sig_IconShow_B10, TempDragListWidget_B10, &QtDragListWidget::SetItemSubIcon_B10);
		delete TempDragListWidget_B10;
		TempDragListWidget_B10 = nullptr;
		break;
	case 10:
		disconnect(QConfig::ToolBase[10], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[10], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[10], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[10], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubText_B11);
		disconnect(this, &frmProItemTab::sig_IconShow_B11, TempDragListWidget_B11, &QtDragListWidget::SetItemSubIcon_B11);
		delete TempDragListWidget_B11;
		TempDragListWidget_B11 = nullptr;
		break;
	case 11:
		disconnect(QConfig::ToolBase[11], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[11], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[11], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[11], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubText_B12);
		disconnect(this, &frmProItemTab::sig_IconShow_B12, TempDragListWidget_B12, &QtDragListWidget::SetItemSubIcon_B12);
		delete TempDragListWidget_B12;
		TempDragListWidget_B12 = nullptr;
		break;
	case 12:
		disconnect(QConfig::ToolBase[12], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[12], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[12], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[12], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubText_B13);
		disconnect(this, &frmProItemTab::sig_IconShow_B13, TempDragListWidget_B13, &QtDragListWidget::SetItemSubIcon_B13);
		delete TempDragListWidget_B13;
		TempDragListWidget_B13 = nullptr;
		break;
	case 13:
		disconnect(QConfig::ToolBase[13], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[13], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[13], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[13], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubText_B14);
		disconnect(this, &frmProItemTab::sig_IconShow_B14, TempDragListWidget_B14, &QtDragListWidget::SetItemSubIcon_B14);
		delete TempDragListWidget_B14;
		TempDragListWidget_B14 = nullptr;
		break;
	case 14:
		disconnect(QConfig::ToolBase[14], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[14], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[14], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[14], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubText_B15);
		disconnect(this, &frmProItemTab::sig_IconShow_B15, TempDragListWidget_B15, &QtDragListWidget::SetItemSubIcon_B15);
		delete TempDragListWidget_B15;
		TempDragListWidget_B15 = nullptr;
		break;
	case 15:
		disconnect(QConfig::ToolBase[15], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[15], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[15], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[15], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubText_B16);
		disconnect(this, &frmProItemTab::sig_IconShow_B16, TempDragListWidget_B16, &QtDragListWidget::SetItemSubIcon_B16);
		delete TempDragListWidget_B16;
		TempDragListWidget_B16 = nullptr;
		break;
	case 16:
		disconnect(QConfig::ToolBase[16], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[16], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[16], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[16], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubText_B17);
		disconnect(this, &frmProItemTab::sig_IconShow_B17, TempDragListWidget_B17, &QtDragListWidget::SetItemSubIcon_B17);
		delete TempDragListWidget_B17;
		TempDragListWidget_B17 = nullptr;
		break;
	case 17:
		disconnect(QConfig::ToolBase[17], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[17], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[17], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[17], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubText_B18);
		disconnect(this, &frmProItemTab::sig_IconShow_B18, TempDragListWidget_B18, &QtDragListWidget::SetItemSubIcon_B18);
		delete TempDragListWidget_B18;
		TempDragListWidget_B18 = nullptr;
		break;
	case 18:
		disconnect(QConfig::ToolBase[18], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[18], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[18], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[18], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubText_B19);
		disconnect(this, &frmProItemTab::sig_IconShow_B19, TempDragListWidget_B19, &QtDragListWidget::SetItemSubIcon_B19);
		delete TempDragListWidget_B19;
		TempDragListWidget_B19 = nullptr;
		break;
	case 19:
		disconnect(QConfig::ToolBase[19], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
		disconnect(QConfig::ToolBase[19], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
		disconnect(QConfig::ToolBase[19], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
		disconnect(QConfig::ToolBase[19], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
		disconnect(this, &frmProItemTab::sig_TextShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubText_B20);
		disconnect(this, &frmProItemTab::sig_IconShow_B20, TempDragListWidget_B20, &QtDragListWidget::SetItemSubIcon_B20);
		delete TempDragListWidget_B20;
		TempDragListWidget_B20 = nullptr;
		break;
	}
	//设置QDockWidget标题名称
	currentItem = ui.ProItemTreeWidget->currentItem();
	if (currentItem == NULL || currentItem->parent() == nullptr)
	{
		ui.ProItemTreeWidget->setStyle(QStyleFactory::create("fusion"));
		ui.dockTabWidget->setWindowTitle(QString());
		return;
	}
	int p_index = itemParent->indexOfChild(currentItem);
	ui.dockTabWidget->setWindowTitle(itemParent->child(p_index)->text(0));
}

//流程设置
void frmProItemTab::on_btnSetProFlow_clicked()
{
	//发射信号
	emit sig_CreateList();
	dataVar::fProcessSetUp->exec();
}

void frmProItemTab::slot_ActionProItem(int nType, QString itemName, bool isAdd)
{
	int flow = ui.ProItemTabWidget->currentIndex();  //索引号
	int flow_index = 0;
	QTreeWidgetItemIterator it(ui.ProItemTreeWidget);  //遍历treeWidget
	QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		QTreeWidgetItem* key = pro_keys[i];
		if ((*it)->child(flow) == pro_keys[i])
		{
			//获取线程所对应的流程号
			flow_index = m_pro_value.values(key).at(0);
		}
	}
	// 0: Item变化   1: 删除工具   2: 运行到当前工具
	if (nType == 0)
	{
		if (true == isAdd)
		{
			if (false == itemName.isEmpty())
			{
				QConfig::ToolBase[flow_index]->AddTool(itemName);
				QConfig::ToolBase[flow_index]->AddToolDlg(itemName, GetNewToolDlg(-10000, itemName, GetProcessItemNum(itemName)));
			}
		}
		else
		{
			bool isFlowExist = false;
			QVector<QString> FlowProItemList = QVector<QString>(100);
			QString flowPageName = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
			QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
			while (iter != dataVar::FlowProMap.end())
			{
				if (iter.key() == flowPageName)
				{
					isFlowExist = true;
					TempDragListWidget = iter.value();
					FlowProItemList = TempDragListWidget->GetAllItemList();
					break;
				}
				iter++;
			}
			if (false == isFlowExist)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到该流程数据: " + flowPageName);
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
				return;
			}
			QConfig::ToolBase[flow_index]->m_FlowSortList = FlowProItemList;
		}
	}
	if (nType == 1)
	{
		for (int i = 0; i < QConfig::ToolBase[flow_index]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[flow_index]->m_Tools[i].PublicToolName == itemName)
			{
				QConfig::ToolBase[flow_index]->m_Tools[i].PublicToolDlg->deleteLater();
				QConfig::ToolBase[flow_index]->m_Tools.erase(QConfig::ToolBase[flow_index]->m_Tools.begin() + i);
				break;
			}
		}
		for (int i = 0; i < QConfig::ToolBase[flow_index]->m_FlowSortList.count(); i++)
		{
			if (QConfig::ToolBase[flow_index]->m_FlowSortList[i] == itemName)
			{
				QConfig::ToolBase[flow_index]->m_FlowSortList.removeAt(i);
				break;
			}
		}
	}
	if (nType == 2)
	{
		bool isFlowExist = false;
		QVector<QString>  FlowProItemList = QVector<QString>(100);
		QString flowPageName = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
		QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
		while (iter != dataVar::FlowProMap.end())
		{
			if (iter.key() == flowPageName)
			{
				isFlowExist = true;
				TempDragListWidget = iter.value();
				FlowProItemList = TempDragListWidget->GetAllItemList();
				break;
			}
			iter++;
		}
		if (false == isFlowExist)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到该流程数据: " + flowPageName);
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		//获取流程中工具的激活/禁用状态			
		flowNames_A.reserve(100);
		flowNames_A.clear();
		QString strCurrentItemText;
		int intCurrentItemId;
		GetItemState_A = TempDragListWidget->GetItemState();
		strCurrentItemText = TempDragListWidget->GetCurrentItemText();
		intCurrentItemId = TempDragListWidget->GetCurrentItemId();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_A.begin();
		while (iter_icon != GetItemState_A.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames_A.append(iter_icon.key());
			}
			iter_icon++;
		}
		FlowProItemListState_A.clear();
		for (int m = 0; m < intCurrentItemId; m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames_A.count(); n++)
			{
				if (FlowProItemList[m] == flowNames_A[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_A.append(FlowProItemList[m]);
				if (strCurrentItemText == FlowProItemList[m])
				{
					break;
				}
			}
		}
		QConfig::ToolBase[flow_index]->m_FlowSortList = FlowProItemList;
		for (int i = 0; i < FlowProItemListState_A.count(); i++)
		{
			for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
			{
				QString toolName;
				toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
				if (FlowProItemListState_A[i] == toolName)
				{
					//子线程中执行流程				
					switch (flow_index) {
					case 0:
						QConfig::ToolBase[flow_index]->RunToolFlow_B1(toolName);
						break;
					case 1:
						QConfig::ToolBase[flow_index]->RunToolFlow_B2(toolName);
						break;
					case 2:
						QConfig::ToolBase[flow_index]->RunToolFlow_B3(toolName);
						break;
					case 3:
						QConfig::ToolBase[flow_index]->RunToolFlow_B4(toolName);
						break;
					case 4:
						QConfig::ToolBase[flow_index]->RunToolFlow_B5(toolName);
						break;
					case 5:
						QConfig::ToolBase[flow_index]->RunToolFlow_B6(toolName);
						break;
					case 6:
						QConfig::ToolBase[flow_index]->RunToolFlow_B7(toolName);
						break;
					case 7:
						QConfig::ToolBase[flow_index]->RunToolFlow_B8(toolName);
						break;
					case 8:
						QConfig::ToolBase[flow_index]->RunToolFlow_B9(toolName);
						break;
					case 9:
						QConfig::ToolBase[flow_index]->RunToolFlow_B10(toolName);
						break;
					case 10:
						QConfig::ToolBase[flow_index]->RunToolFlow_B11(toolName);
						break;
					case 11:
						QConfig::ToolBase[flow_index]->RunToolFlow_B12(toolName);
						break;
					case 12:
						QConfig::ToolBase[flow_index]->RunToolFlow_B13(toolName);
						break;
					case 13:
						QConfig::ToolBase[flow_index]->RunToolFlow_B14(toolName);
						break;
					case 14:
						QConfig::ToolBase[flow_index]->RunToolFlow_B15(toolName);
						break;
					case 15:
						QConfig::ToolBase[flow_index]->RunToolFlow_B16(toolName);
						break;
					case 16:
						QConfig::ToolBase[flow_index]->RunToolFlow_B17(toolName);
						break;
					case 17:
						QConfig::ToolBase[flow_index]->RunToolFlow_B18(toolName);
						break;
					case 18:
						QConfig::ToolBase[flow_index]->RunToolFlow_B19(toolName);
						break;
					case 19:
						QConfig::ToolBase[flow_index]->RunToolFlow_B20(toolName);
						break;
					}
				}
			}
		}
	}
	//传递流程工具名到跳转工具		
	gVariable::goto_variable_link.clear();
	gVariable::GotoVar.goto_array_name_value.clear();
	gVariable::GotoVar.goto_array_name_value.resize(QConfig::ToolBase[flow_index]->m_FlowSortList.count());
	for (int m = 0; m < QConfig::ToolBase[flow_index]->m_FlowSortList.count(); m++)
	{
		gVariable::GotoVar.goto_array_name_value[m] = QConfig::ToolBase[flow_index]->m_FlowSortList[m];
		gVariable::goto_variable_link.insert(QString::number(flow_index), gVariable::GotoVar);
	}
	//更新跳转工具
	QConfig::ToolBase[flow_index]->RunGotoToolLink();
	//更新通讯工具
	QConfig::ToolBase[flow_index]->RunCommunicationLink(QString());
#pragma region 脚本编辑链接列表
	QVector<QString>  FlowProItemList_S = QVector<QString>(100);
	QString flowPageName_S = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());	
	QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
	while (iter != dataVar::FlowProMap.end())
	{
		if (iter.key() == flowPageName_S)
		{			
			TempDragListWidget = iter.value();
			FlowProItemList_S = TempDragListWidget->GetAllItemList();			
			break;
		}
		iter++;
	}
	gVariable::ScriptEditVar.flow_pro_item_list = FlowProItemList_S;
	gVariable::ScriptEditVar.item_id = flow_index;
	gVariable::scriptedit_variable_link.insert(QConfig::ToolBase[flow_index], gVariable::ScriptEditVar);
	//更新变量
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunAllToolLink();
				QConfig::ToolBase[key]->RunScriptEditToolLink();
			}
		}
	}
#pragma endregion
}

//流程执行一次
void frmProItemTab::on_btnRunOnce_clicked()
{
	//手动程序流程
	dataVar::m_a_state = 1;
	dataVar::manualRunOnce_A = 0;
	dataVar::stopThread_A = 0;
	stop_goto_A = false;
	stop_goto_manual_A = true;
	emit sig_InfoClick();
	emit sig_Log("项目方案单个流程执行一次...");
	ProgramManualFlow();
}

//流程循环执行
void frmProItemTab::on_btnRunCycle_clicked()
{
	dataVar::m_a_state = 1;
	dataVar::manualRunOnce_A = 0;
	dataVar::stopThread_A = 0;
	emit sig_InfoClick();
	emit sig_Log("项目方案单个流程开始循环执行...");
	emit sig_CycleRun();
	ui.btnRunCycle->setEnabled(false);
	ui.btnRunOnce->setEnabled(false);
	stop_goto_A = false;
	stop_goto_manual_A = false;
	Begin_Thread_A();
}

void frmProItemTab::slot_CycleProErr()
{
	ui.btnRunOnce->setEnabled(true);
	ui.btnRunCycle->setEnabled(true);
}

void frmProItemTab::slot_CyclePro()
{
	//手动程序流程	
	ProgramManualFlow();
}

//流程停止执行
void frmProItemTab::on_btnStop_clicked()
{
	emit sig_InfoClick();
	emit sig_Log("项目方案单个流程停止执行...");
	dataVar::stopThread_A = 1;
	emit sig_CycleStop();
}

//所有流程执行一次
void frmProItemTab::slot_AllCycleRunOnce()
{
	//自动程序流程
	AutoRunOnce_B();
	AutoRunStop_B();
	dataVar::m_a_state = 2;
	stop_goto_manual_B = true;
	bool isFlowExist = false;
	QVector<QString> FlowProItemList = QVector<QString>(100);
	FlowProItemList.clear();
	//获取流程数据
	QString flowPageName = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
	QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
	while (iter != dataVar::FlowProMap.end())
	{
		if (iter.key() == flowPageName)
		{
			isFlowExist = true;
			TempDragListWidget = iter.value();
			FlowProItemList = TempDragListWidget->GetAllItemList();
			GetItemState_A = TempDragListWidget->GetItemState();
			break;
		}
		iter++;
	}
	if (false == isFlowExist || FlowProItemList.count() == 0)
	{
		emit sig_ErrorClick();
		emit sig_Log("项目方案所有流程执行一次时: 未找到该流程数据: " + flowPageName);
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到该流程数据: " + flowPageName);
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	else
	{
		emit sig_InfoClick();
		emit sig_Log("项目方案所有流程执行一次...");
		QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
		for (int i = 0; i < pro_keys.count(); i++)
		{
			QTreeWidgetItem* key = pro_keys[i];
			//获取线程所对应的流程号
			int flow_index = m_pro_value.values(key).at(0);
			switch (flow_index) {
			case 0:
				pro_name_B1 = key->text(0);
				ProgramAutoFlow_B1();
				break;
			case 1:
				pro_name_B2 = key->text(0);
				ProgramAutoFlow_B2();
				break;
			case 2:
				pro_name_B3 = key->text(0);
				ProgramAutoFlow_B3();
				break;
			case 3:
				pro_name_B4 = key->text(0);
				ProgramAutoFlow_B4();
				break;
			case 4:
				pro_name_B5 = key->text(0);
				ProgramAutoFlow_B5();
				break;
			case 5:
				pro_name_B6 = key->text(0);
				ProgramAutoFlow_B6();
				break;
			case 6:
				pro_name_B7 = key->text(0);
				ProgramAutoFlow_B7();
				break;
			case 7:
				pro_name_B8 = key->text(0);
				ProgramAutoFlow_B8();
				break;
			case 8:
				pro_name_B9 = key->text(0);
				ProgramAutoFlow_B9();
				break;
			case 9:
				pro_name_B10 = key->text(0);
				ProgramAutoFlow_B10();
				break;
			case 10:
				pro_name_B11 = key->text(0);
				ProgramAutoFlow_B11();
				break;
			case 11:
				pro_name_B12 = key->text(0);
				ProgramAutoFlow_B12();
				break;
			case 12:
				pro_name_B13 = key->text(0);
				ProgramAutoFlow_B13();
				break;
			case 13:
				pro_name_B14 = key->text(0);
				ProgramAutoFlow_B14();
				break;
			case 14:
				pro_name_B15 = key->text(0);
				ProgramAutoFlow_B15();
				break;
			case 15:
				pro_name_B16 = key->text(0);
				ProgramAutoFlow_B16();
				break;
			case 16:
				pro_name_B17 = key->text(0);
				ProgramAutoFlow_B17();
				break;
			case 17:
				pro_name_B18 = key->text(0);
				ProgramAutoFlow_B18();
				break;
			case 18:
				pro_name_B19 = key->text(0);
				ProgramAutoFlow_B19();
				break;
			case 19:
				pro_name_B20 = key->text(0);
				ProgramAutoFlow_B20();
				break;
			}
		}
	}
}

//所有流程连续执行
void frmProItemTab::slot_AllCycleRunContinue()
{
	//自动程序流程
	AutoRunOnce_B();
	AutoRunStop_B();
	dataVar::m_a_state = 2;
	stop_goto_manual_B = false;
	bool isFlowExist = false;
	QVector<QString> FlowProItemList = QVector<QString>(100);
	FlowProItemList.clear();
	//获取流程数据
	QString flowPageName = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
	QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
	while (iter != dataVar::FlowProMap.end())
	{
		if (iter.key() == flowPageName)
		{
			isFlowExist = true;
			TempDragListWidget = iter.value();
			FlowProItemList = TempDragListWidget->GetAllItemList();
			GetItemState_A = TempDragListWidget->GetItemState();
			break;
		}
		iter++;
	}
	if (false == isFlowExist || FlowProItemList.count() == 0)
	{
		emit sig_ErrorClick();
		emit sig_Log("项目方案所有流程连续执行时: 未找到该流程数据: " + flowPageName);
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到该流程数据: " + flowPageName);
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		emit sig_AllCycleStop();
		return;
	}
	else
	{
		emit sig_InfoClick();
		emit sig_Log("项目方案所有流程开始循环执行...");
		QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
		for (int i = 0; i < pro_keys.count(); i++)
		{
			QTreeWidgetItem* key = pro_keys[i];
			//获取线程所对应的流程号
			int flow_index = m_pro_value.values(key).at(0);
			switch (flow_index) {
			case 0:
				pro_name_B1 = key->text(0);
				dataVar::runFinish_B1 = true;
				Begin_Thread_B1();
				break;
			case 1:
				pro_name_B2 = key->text(0);
				dataVar::runFinish_B2 = true;
				Begin_Thread_B2();
				break;
			case 2:
				pro_name_B3 = key->text(0);
				dataVar::runFinish_B3 = true;
				Begin_Thread_B3();
				break;
			case 3:
				pro_name_B4 = key->text(0);
				dataVar::runFinish_B4 = true;
				Begin_Thread_B4();
				break;
			case 4:
				pro_name_B5 = key->text(0);
				dataVar::runFinish_B5 = true;
				Begin_Thread_B5();
				break;
			case 5:
				pro_name_B6 = key->text(0);
				dataVar::runFinish_B6 = true;
				Begin_Thread_B6();
				break;
			case 6:
				pro_name_B7 = key->text(0);
				dataVar::runFinish_B7 = true;
				Begin_Thread_B7();
				break;
			case 7:
				pro_name_B8 = key->text(0);
				dataVar::runFinish_B8 = true;
				Begin_Thread_B8();
				break;
			case 8:
				pro_name_B9 = key->text(0);
				dataVar::runFinish_B9 = true;
				Begin_Thread_B9();
				break;
			case 9:
				pro_name_B10 = key->text(0);
				dataVar::runFinish_B10 = true;
				Begin_Thread_B10();
				break;
			case 10:
				pro_name_B11 = key->text(0);
				dataVar::runFinish_B11 = true;
				Begin_Thread_B11();
				break;
			case 11:
				pro_name_B12 = key->text(0);
				dataVar::runFinish_B12 = true;
				Begin_Thread_B12();
				break;
			case 12:
				pro_name_B13 = key->text(0);
				dataVar::runFinish_B13 = true;
				Begin_Thread_B13();
				break;
			case 13:
				pro_name_B14 = key->text(0);
				dataVar::runFinish_B14 = true;
				Begin_Thread_B14();
				break;
			case 14:
				pro_name_B15 = key->text(0);
				dataVar::runFinish_B15 = true;
				Begin_Thread_B15();
				break;
			case 15:
				pro_name_B16 = key->text(0);
				dataVar::runFinish_B16 = true;
				Begin_Thread_B16();
				break;
			case 16:
				pro_name_B17 = key->text(0);
				dataVar::runFinish_B17 = true;
				Begin_Thread_B17();
				break;
			case 17:
				pro_name_B18 = key->text(0);
				dataVar::runFinish_B18 = true;
				Begin_Thread_B18();
				break;
			case 18:
				pro_name_B19 = key->text(0);
				dataVar::runFinish_B19 = true;
				Begin_Thread_B19();
				break;
			case 19:
				pro_name_B20 = key->text(0);
				dataVar::runFinish_B20 = true;
				Begin_Thread_B20();
				break;
			}
		}
		cutover_index = 0;
		p_autotimer->start(3600);
	}
}

//所有流程停止
void frmProItemTab::slot_AllCycleStop()
{
	emit sig_InfoClick();
	emit sig_Log("项目方案所有流程停止执行...");
	Stop_Thread_B();
	p_autotimer->stop();
	AutoRunOnce_B();
	emit sig_CycleStop();
	if (dataVar::login_state == 1)
	{
		ui.btnRunOnce->setEnabled(true);
		ui.btnRunCycle->setEnabled(true);
		ui.btnStop->setEnabled(true);
	}
}

//初始化参数
void frmProItemTab::AutoRunOnce_B()
{
	stop_goto_B1 = false;
	stop_goto_B2 = false;
	stop_goto_B3 = false;
	stop_goto_B4 = false;
	stop_goto_B5 = false;
	stop_goto_B6 = false;
	stop_goto_B7 = false;
	stop_goto_B8 = false;
	stop_goto_B9 = false;
	stop_goto_B10 = false;
	stop_goto_B11 = false;
	stop_goto_B12 = false;
	stop_goto_B13 = false;
	stop_goto_B14 = false;
	stop_goto_B15 = false;
	stop_goto_B16 = false;
	stop_goto_B17 = false;
	stop_goto_B18 = false;
	stop_goto_B19 = false;
	stop_goto_B20 = false;
	dataVar::autoRunOnce_B1 = 0;
	dataVar::autoRunOnce_B2 = 0;
	dataVar::autoRunOnce_B3 = 0;
	dataVar::autoRunOnce_B4 = 0;
	dataVar::autoRunOnce_B5 = 0;
	dataVar::autoRunOnce_B6 = 0;
	dataVar::autoRunOnce_B7 = 0;
	dataVar::autoRunOnce_B8 = 0;
	dataVar::autoRunOnce_B9 = 0;
	dataVar::autoRunOnce_B10 = 0;
	dataVar::autoRunOnce_B11 = 0;
	dataVar::autoRunOnce_B12 = 0;
	dataVar::autoRunOnce_B13 = 0;
	dataVar::autoRunOnce_B14 = 0;
	dataVar::autoRunOnce_B15 = 0;
	dataVar::autoRunOnce_B16 = 0;
	dataVar::autoRunOnce_B17 = 0;
	dataVar::autoRunOnce_B18 = 0;
	dataVar::autoRunOnce_B19 = 0;
	dataVar::autoRunOnce_B20 = 0;
}

void frmProItemTab::AutoRunStop_B()
{
	dataVar::stopThread_B1 = 0;
	dataVar::stopThread_B2 = 0;
	dataVar::stopThread_B3 = 0;
	dataVar::stopThread_B4 = 0;
	dataVar::stopThread_B5 = 0;
	dataVar::stopThread_B6 = 0;
	dataVar::stopThread_B7 = 0;
	dataVar::stopThread_B8 = 0;
	dataVar::stopThread_B9 = 0;
	dataVar::stopThread_B10 = 0;
	dataVar::stopThread_B11 = 0;
	dataVar::stopThread_B12 = 0;
	dataVar::stopThread_B13 = 0;
	dataVar::stopThread_B14 = 0;
	dataVar::stopThread_B15 = 0;
	dataVar::stopThread_B16 = 0;
	dataVar::stopThread_B17 = 0;
	dataVar::stopThread_B18 = 0;
	dataVar::stopThread_B19 = 0;
	dataVar::stopThread_B20 = 0;
}

//切换流程显示
void frmProItemTab::slot_Cutover()
{
	int count = ui.ProItemTabWidget->count();
	if (cutover_index >= count)
	{
		cutover_index = 0;
	}
	if (cutover_index < count)
	{
		ui.ProItemTabWidget->setCurrentIndex(cutover_index);
		ui.dockTabWidget->setWindowTitle(ui.ProItemTabWidget->tabText(cutover_index));
		++cutover_index;
	}
}

#pragma region 手动程序流程
//手动程序流程
void frmProItemTab::ProgramManualFlow()
{
	bool isFlowExist = false;
	if (dataVar::manualRunOnce_A == 0)
	{
		dataVar::manualRunOnce_A = 1;
		FlowProItemList_A.clear();
		FlowProItemListState_A.clear();
		int flow = ui.ProItemTabWidget->currentIndex();  //索引号	
		QTreeWidgetItemIterator it(ui.ProItemTreeWidget);  //遍历treeWidget
		QList<QTreeWidgetItem*> pro_keys = m_pro_value.uniqueKeys();
		for (int i = 0; i < (*it)->childCount(); i++)
		{
			QTreeWidgetItem* key = pro_keys[i];
			if ((*it)->child(flow) == pro_keys[i])
			{
				//获取线程所对应的流程号
				manual_flow_index = m_pro_value.values(key).at(0);
			}
		}
		//获取流程数据
		flowPageName_A = ui.ProItemTabWidget->tabText(ui.ProItemTabWidget->currentIndex());
		flowPageName_buf = flowPageName_A;
		QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
		while (iter != dataVar::FlowProMap.end())
		{
			if (iter.key() == flowPageName_A)
			{
				isFlowExist = true;
				TempDragListWidget = iter.value();
				FlowProItemList_A = TempDragListWidget->GetAllItemList();
				GetItemState_A = TempDragListWidget->GetItemState();
				break;
			}
			iter++;
		}
		if (false == isFlowExist || FlowProItemList_A.count() == 0)
		{
			Stop_Thread_A();
			emit sig_ManualCycleStop();
			emit sig_CycleStop();
			return;
		}
		//获取流程中工具的激活/禁用状态			
		flowNames_A.reserve(100);
		flowNames_A.clear();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_A.begin();
		while (iter_icon != GetItemState_A.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames_A.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_A.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames_A.count(); n++)
			{
				if (FlowProItemList_A[m] == flowNames_A[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_A.append(FlowProItemList_A[m]);
			}
		}
	}
	switch (manual_flow_index) {
	case 0:
		dataVar::img_view_count_buf_B1 = 0;
		pro_name_B1 = flowPageName_A;
		break;
	case 1:
		dataVar::img_view_count_buf_B2 = 0;
		pro_name_B2 = flowPageName_A;
		break;
	case 2:
		dataVar::img_view_count_buf_B3 = 0;
		pro_name_B3 = flowPageName_A;
		break;
	case 3:
		dataVar::img_view_count_buf_B4 = 0;
		pro_name_B4 = flowPageName_A;
		break;
	case 4:
		dataVar::img_view_count_buf_B5 = 0;
		pro_name_B5 = flowPageName_A;
		break;
	case 5:
		dataVar::img_view_count_buf_B6 = 0;
		pro_name_B6 = flowPageName_A;
		break;
	case 6:
		dataVar::img_view_count_buf_B7 = 0;
		pro_name_B7 = flowPageName_A;
		break;
	case 7:
		dataVar::img_view_count_buf_B8 = 0;
		pro_name_B8 = flowPageName_A;
		break;
	case 8:
		dataVar::img_view_count_buf_B9 = 0;
		pro_name_B9 = flowPageName_A;
		break;
	case 9:
		dataVar::img_view_count_buf_B10 = 0;
		pro_name_B10 = flowPageName_A;
		break;
	case 10:
		dataVar::img_view_count_buf_B11 = 0;
		pro_name_B11 = flowPageName_A;
		break;
	case 11:
		dataVar::img_view_count_buf_B12 = 0;
		pro_name_B12 = flowPageName_A;
		break;
	case 12:
		dataVar::img_view_count_buf_B13 = 0;
		pro_name_B13 = flowPageName_A;
		break;
	case 13:
		dataVar::img_view_count_buf_B14 = 0;
		pro_name_B14 = flowPageName_A;
		break;
	case 14:
		dataVar::img_view_count_buf_B15 = 0;
		pro_name_B15 = flowPageName_A;
		break;
	case 15:
		dataVar::img_view_count_buf_B16 = 0;
		pro_name_B16 = flowPageName_A;
		break;
	case 16:
		dataVar::img_view_count_buf_B17 = 0;
		pro_name_B17 = flowPageName_A;
		break;
	case 17:
		dataVar::img_view_count_buf_B18 = 0;
		pro_name_B18 = flowPageName_A;
		break;
	case 18:
		dataVar::img_view_count_buf_B19 = 0;
		pro_name_B19 = flowPageName_A;
		break;
	case 19:
		dataVar::img_view_count_buf_B20 = 0;
		pro_name_B20 = flowPageName_A;
		break;
	}
	QConfig::ToolBase[manual_flow_index]->m_FlowSortList = FlowProItemList_A;
	for (int i = 0; i < FlowProItemListState_A.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[manual_flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[manual_flow_index]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_A[i] == toolName)
			{
				switch (manual_flow_index) {
				case 0:
					dataVar::img_view_count_B1 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B1(toolName);
					break;
				case 1:
					dataVar::img_view_count_B2 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B2(toolName);
					break;
				case 2:
					dataVar::img_view_count_B3 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B3(toolName);
					break;
				case 3:
					dataVar::img_view_count_B4 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B4(toolName);
					break;
				case 4:
					dataVar::img_view_count_B5 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B5(toolName);
					break;
				case 5:
					dataVar::img_view_count_B6 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B6(toolName);
					break;
				case 6:
					dataVar::img_view_count_B7 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B7(toolName);
					break;
				case 7:
					dataVar::img_view_count_B8 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B8(toolName);
					break;
				case 8:
					dataVar::img_view_count_B9 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B9(toolName);
					break;
				case 9:
					dataVar::img_view_count_B10 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B10(toolName);
					break;
				case 10:
					dataVar::img_view_count_B11 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B11(toolName);
					break;
				case 11:
					dataVar::img_view_count_B12 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B12(toolName);
					break;
				case 12:
					dataVar::img_view_count_B13 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B13(toolName);
					break;
				case 13:
					dataVar::img_view_count_B14 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B14(toolName);
					break;
				case 14:
					dataVar::img_view_count_B15 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B15(toolName);
					break;
				case 15:
					dataVar::img_view_count_B16 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B16(toolName);
					break;
				case 16:
					dataVar::img_view_count_B17 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B17(toolName);
					break;
				case 17:
					dataVar::img_view_count_B18 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B18(toolName);
					break;
				case 18:
					dataVar::img_view_count_B19 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B19(toolName);
					break;
				case 19:
					dataVar::img_view_count_B20 = FlowProItemListState_A.count();
					run_state_A = QConfig::ToolBase[manual_flow_index]->RunToolFlow_B20(toolName);
					break;
				}
				if (run_state_A == false)
				{
					return;
				}
				//提取不含数字字符串				
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_A = toolName.mid(0, str_count);
				if (tool_name_A == "跳转语句")
				{
					if (stop_goto_A == true)
					{
						return;
					}
					int goto_index = 0;
					for (int q = 0; q < QConfig::ToolBase[manual_flow_index]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[manual_flow_index]->m_Tools[q].PublicToolName == toolName)
						{
							goto_index = q;
						}
					}
					if (QConfig::ToolBase[manual_flow_index]->m_Tools[goto_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_A.count(); p++)
						{
							if (FlowProItemListState_A[p] == QConfig::ToolBase[manual_flow_index]->m_Tools[goto_index].PublicLogic.GotoToolName)
							{
								switch (manual_flow_index) {
								case 0:
									if (i < p)
									{
										dataVar::img_view_count_buf_B1 = dataVar::img_view_count_buf_B1 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B1 = dataVar::img_view_count_buf_B1 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 1:
									if (i < p)
									{
										dataVar::img_view_count_buf_B2 = dataVar::img_view_count_buf_B2 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B2 = dataVar::img_view_count_buf_B2 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 2:
									if (i < p)
									{
										dataVar::img_view_count_buf_B3 = dataVar::img_view_count_buf_B3 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B3 = dataVar::img_view_count_buf_B3 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 3:
									if (i < p)
									{
										dataVar::img_view_count_buf_B4 = dataVar::img_view_count_buf_B4 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B4 = dataVar::img_view_count_buf_B4 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 4:
									if (i < p)
									{
										dataVar::img_view_count_buf_B5 = dataVar::img_view_count_buf_B5 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B5 = dataVar::img_view_count_buf_B5 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 5:
									if (i < p)
									{
										dataVar::img_view_count_buf_B6 = dataVar::img_view_count_buf_B6 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B6 = dataVar::img_view_count_buf_B6 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 6:
									if (i < p)
									{
										dataVar::img_view_count_buf_B7 = dataVar::img_view_count_buf_B7 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B7 = dataVar::img_view_count_buf_B7 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 7:
									if (i < p)
									{
										dataVar::img_view_count_buf_B8 = dataVar::img_view_count_buf_B8 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B8 = dataVar::img_view_count_buf_B8 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 8:
									if (i < p)
									{
										dataVar::img_view_count_buf_B9 = dataVar::img_view_count_buf_B9 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B9 = dataVar::img_view_count_buf_B9 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 9:
									if (i < p)
									{
										dataVar::img_view_count_buf_B10 = dataVar::img_view_count_buf_B10 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B10 = dataVar::img_view_count_buf_B10 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 10:
									if (i < p)
									{
										dataVar::img_view_count_buf_B11 = dataVar::img_view_count_buf_B11 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B11 = dataVar::img_view_count_buf_B11 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 11:
									if (i < p)
									{
										dataVar::img_view_count_buf_B12 = dataVar::img_view_count_buf_B12 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B12 = dataVar::img_view_count_buf_B12 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 12:
									if (i < p)
									{
										dataVar::img_view_count_buf_B13 = dataVar::img_view_count_buf_B13 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B13 = dataVar::img_view_count_buf_B13 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 13:
									if (i < p)
									{
										dataVar::img_view_count_buf_B14 = dataVar::img_view_count_buf_B14 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B14 = dataVar::img_view_count_buf_B14 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 14:
									if (i < p)
									{
										dataVar::img_view_count_buf_B15 = dataVar::img_view_count_buf_B15 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B15 = dataVar::img_view_count_buf_B15 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 15:
									if (i < p)
									{
										dataVar::img_view_count_buf_B16 = dataVar::img_view_count_buf_B16 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B16 = dataVar::img_view_count_buf_B16 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 16:
									if (i < p)
									{
										dataVar::img_view_count_buf_B17 = dataVar::img_view_count_buf_B17 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B17 = dataVar::img_view_count_buf_B17 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 17:
									if (i < p)
									{
										dataVar::img_view_count_buf_B18 = dataVar::img_view_count_buf_B18 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B18 = dataVar::img_view_count_buf_B18 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 18:
									if (i < p)
									{
										dataVar::img_view_count_buf_B19 = dataVar::img_view_count_buf_B19 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B19 = dataVar::img_view_count_buf_B19 - (i - p - 1);
										i = p - 1;
									}
									break;
								case 19:
									if (i < p)
									{
										dataVar::img_view_count_buf_B20 = dataVar::img_view_count_buf_B20 + (p - i - 1);
										i = p - 1;
									}
									else
									{
										if (stop_goto_manual_A == true)
										{
											stop_goto_A = true;
										}
										dataVar::img_view_count_buf_B20 = dataVar::img_view_count_buf_B20 - (i - p - 1);
										i = p - 1;
									}
									break;
								}
							}
						}
					}
				}
				else if (tool_name_A == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[manual_flow_index]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[manual_flow_index]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index;
					switch (manual_flow_index) {
					case 0:
						if_judge_index = TempDragListWidget_B1->GetIfJudgeIndex();
						break;
					case 1:
						if_judge_index = TempDragListWidget_B2->GetIfJudgeIndex();
						break;
					case 2:
						if_judge_index = TempDragListWidget_B3->GetIfJudgeIndex();
						break;
					case 3:
						if_judge_index = TempDragListWidget_B4->GetIfJudgeIndex();
						break;
					case 4:
						if_judge_index = TempDragListWidget_B5->GetIfJudgeIndex();
						break;
					case 5:
						if_judge_index = TempDragListWidget_B6->GetIfJudgeIndex();
						break;
					case 6:
						if_judge_index = TempDragListWidget_B7->GetIfJudgeIndex();
						break;
					case 7:
						if_judge_index = TempDragListWidget_B8->GetIfJudgeIndex();
						break;
					case 8:
						if_judge_index = TempDragListWidget_B9->GetIfJudgeIndex();
						break;
					case 9:
						if_judge_index = TempDragListWidget_B10->GetIfJudgeIndex();
						break;
					case 10:
						if_judge_index = TempDragListWidget_B11->GetIfJudgeIndex();
						break;
					case 11:
						if_judge_index = TempDragListWidget_B12->GetIfJudgeIndex();
						break;
					case 12:
						if_judge_index = TempDragListWidget_B13->GetIfJudgeIndex();
						break;
					case 13:
						if_judge_index = TempDragListWidget_B14->GetIfJudgeIndex();
						break;
					case 14:
						if_judge_index = TempDragListWidget_B15->GetIfJudgeIndex();
						break;
					case 15:
						if_judge_index = TempDragListWidget_B16->GetIfJudgeIndex();
						break;
					case 16:
						if_judge_index = TempDragListWidget_B17->GetIfJudgeIndex();
						break;
					case 17:
						if_judge_index = TempDragListWidget_B18->GetIfJudgeIndex();
						break;
					case 18:
						if_judge_index = TempDragListWidget_B19->GetIfJudgeIndex();
						break;
					case 19:
						if_judge_index = TempDragListWidget_B20->GetIfJudgeIndex();
						break;
					}
					if (QConfig::ToolBase[manual_flow_index]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_A = true;
						return;
					}
					else if (QConfig::ToolBase[manual_flow_index]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						switch (manual_flow_index) {
						case 0:
							dataVar::img_view_count_buf_B1 = if_judge_index;
							break;
						case 1:
							dataVar::img_view_count_buf_B2 = if_judge_index;
							break;
						case 2:
							dataVar::img_view_count_buf_B3 = if_judge_index;
							break;
						case 3:
							dataVar::img_view_count_buf_B4 = if_judge_index;
							break;
						case 4:
							dataVar::img_view_count_buf_B5 = if_judge_index;
							break;
						case 5:
							dataVar::img_view_count_buf_B6 = if_judge_index;
							break;
						case 6:
							dataVar::img_view_count_buf_B7 = if_judge_index;
							break;
						case 7:
							dataVar::img_view_count_buf_B8 = if_judge_index;
							break;
						case 8:
							dataVar::img_view_count_buf_B9 = if_judge_index;
							break;
						case 9:
							dataVar::img_view_count_buf_B10 = if_judge_index;
							break;
						case 10:
							dataVar::img_view_count_buf_B11 = if_judge_index;
							break;
						case 11:
							dataVar::img_view_count_buf_B12 = if_judge_index;
							break;
						case 12:
							dataVar::img_view_count_buf_B13 = if_judge_index;
							break;
						case 13:
							dataVar::img_view_count_buf_B14 = if_judge_index;
							break;
						case 14:
							dataVar::img_view_count_buf_B15 = if_judge_index;
							break;
						case 15:
							dataVar::img_view_count_buf_B16 = if_judge_index;
							break;
						case 16:
							dataVar::img_view_count_buf_B17 = if_judge_index;
							break;
						case 17:
							dataVar::img_view_count_buf_B18 = if_judge_index;
							break;
						case 18:
							dataVar::img_view_count_buf_B19 = if_judge_index;
							break;
						case 19:
							dataVar::img_view_count_buf_B20 = if_judge_index;
							break;
						}
					}
				}
				else if (tool_name_A == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[manual_flow_index]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[manual_flow_index]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[manual_flow_index]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_A = true;
						return;
					}
				}
				break;
			}
		}
	}
}

void frmProItemTab::slot_ManualCycleStop()
{
	emit sig_ErrorClick();
	emit sig_Log("手动程序流程: 未找到该流程数据: " + flowPageName_buf);
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到该流程数据: " + flowPageName_buf);
	msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
	msgBox.exec();
}
#pragma endregion

#pragma region 自动程序流程
//自动程序流程1
void frmProItemTab::ProgramAutoFlow_B1()
{
	if (dataVar::autoRunOnce_B1 == 0)
	{
		dataVar::autoRunOnce_B1 = 1;
		FlowProItemListState_B1.clear();
		QVector<QString> FlowProItemList_B1 = QVector<QString>(100);
		FlowProItemList_B1.clear();
		FlowProItemList_B1 = TempDragListWidget_B1->GetAllItemList_B1();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B1 = TempDragListWidget_B1->GetItemState_B1();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B1.begin();
		while (iter_icon != GetItemState_B1.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B1.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B1[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B1.append(FlowProItemList_B1[m]);
			}
		}
		QConfig::ToolBase[0]->m_FlowSortList = FlowProItemList_B1;
	}
	dataVar::img_view_count_buf_B1 = 0;
	for (int i = 0; i < FlowProItemListState_B1.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[0]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[0]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B1[i] == toolName)
			{
				dataVar::img_view_count_B1 = FlowProItemListState_B1.count();
				run_state_B1 = QConfig::ToolBase[0]->RunToolFlow_B1(toolName);
				if (run_state_B1 == false)
				{
					return;
				}
				//提取不含数字字符串				
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B1 = toolName.mid(0, str_count);
				if (tool_name_B1 == "跳转语句")
				{
					if (stop_goto_B1 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[0]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[0]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[0]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B1.count(); p++)
						{
							if (FlowProItemListState_B1[p] == QConfig::ToolBase[0]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B1 = dataVar::img_view_count_buf_B1 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B1 = true;
									}
									dataVar::img_view_count_buf_B1 = dataVar::img_view_count_buf_B1 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B1 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[0]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[0]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B1->GetIfJudgeIndex();
					if (QConfig::ToolBase[0]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B1 = true;
						return;
					}
					else if (QConfig::ToolBase[0]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B1 = if_judge_index;
					}
				}
				else if (tool_name_B1 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[0]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[0]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[0]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B1 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程2
void frmProItemTab::ProgramAutoFlow_B2()
{
	if (dataVar::autoRunOnce_B2 == 0)
	{
		dataVar::autoRunOnce_B2 = 1;
		FlowProItemListState_B2.clear();
		QVector<QString> FlowProItemList_B2 = QVector<QString>(100);
		FlowProItemList_B2.clear();
		FlowProItemList_B2 = TempDragListWidget_B2->GetAllItemList_B2();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B2 = TempDragListWidget_B2->GetItemState_B2();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B2.begin();
		while (iter_icon != GetItemState_B2.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B2.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B2[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B2.append(FlowProItemList_B2[m]);
			}
		}
		QConfig::ToolBase[1]->m_FlowSortList = FlowProItemList_B2;
	}
	dataVar::img_view_count_buf_B2 = 0;
	for (int i = 0; i < FlowProItemListState_B2.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[1]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[1]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B2[i] == toolName)
			{
				dataVar::img_view_count_B2 = FlowProItemListState_B2.count();
				run_state_B2 = QConfig::ToolBase[1]->RunToolFlow_B2(toolName);
				if (run_state_B2 == false)
				{
					return;
				}
				//提取不含数字字符串				
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B2 = toolName.mid(0, str_count);
				if (tool_name_B2 == "跳转语句")
				{
					if (stop_goto_B2 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[1]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[1]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[1]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B2.count(); p++)
						{
							if (FlowProItemListState_B2[p] == QConfig::ToolBase[1]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B2 = dataVar::img_view_count_buf_B2 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B2 = true;
									}
									dataVar::img_view_count_buf_B2 = dataVar::img_view_count_buf_B2 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B2 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[1]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[1]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B2->GetIfJudgeIndex();
					if (QConfig::ToolBase[1]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B2 = true;
						return;
					}
					else if (QConfig::ToolBase[1]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B2 = if_judge_index;
					}
				}
				else if (tool_name_B2 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[1]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[1]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[1]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B2 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程3
void frmProItemTab::ProgramAutoFlow_B3()
{
	if (dataVar::autoRunOnce_B3 == 0)
	{
		dataVar::autoRunOnce_B3 = 1;
		FlowProItemListState_B3.clear();
		QVector<QString> FlowProItemList_B3 = QVector<QString>(100);
		FlowProItemList_B3.clear();
		FlowProItemList_B3 = TempDragListWidget_B3->GetAllItemList_B3();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B3 = TempDragListWidget_B3->GetItemState_B3();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B3.begin();
		while (iter_icon != GetItemState_B3.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B3.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B3[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B3.append(FlowProItemList_B3[m]);
			}
		}
		QConfig::ToolBase[2]->m_FlowSortList = FlowProItemList_B3;
	}
	dataVar::img_view_count_buf_B3 = 0;
	for (int i = 0; i < FlowProItemListState_B3.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[2]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[2]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B3[i] == toolName)
			{
				dataVar::img_view_count_B3 = FlowProItemListState_B3.count();
				run_state_B3 = QConfig::ToolBase[2]->RunToolFlow_B3(toolName);
				if (run_state_B3 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B3 = toolName.mid(0, str_count);
				if (tool_name_B3 == "跳转语句")
				{
					if (stop_goto_B3 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[2]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[2]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[2]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B3.count(); p++)
						{
							if (FlowProItemListState_B3[p] == QConfig::ToolBase[2]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B3 = dataVar::img_view_count_buf_B3 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B3 = true;
									}
									dataVar::img_view_count_buf_B3 = dataVar::img_view_count_buf_B3 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B3 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[2]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[2]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B3->GetIfJudgeIndex();
					if (QConfig::ToolBase[2]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B3 = true;
						return;
					}
					else if (QConfig::ToolBase[2]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B3 = if_judge_index;
					}
				}
				else if (tool_name_B3 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[2]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[2]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[2]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B3 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程4
void frmProItemTab::ProgramAutoFlow_B4()
{
	if (dataVar::autoRunOnce_B4 == 0)
	{
		dataVar::autoRunOnce_B4 = 1;
		FlowProItemListState_B4.clear();
		QVector<QString> FlowProItemList_B4 = QVector<QString>(100);
		FlowProItemList_B4.clear();
		FlowProItemList_B4 = TempDragListWidget_B4->GetAllItemList_B4();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B4 = TempDragListWidget_B4->GetItemState_B4();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B4.begin();
		while (iter_icon != GetItemState_B4.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B4.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B4[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B4.append(FlowProItemList_B4[m]);
			}
		}
		QConfig::ToolBase[3]->m_FlowSortList = FlowProItemList_B4;
	}
	dataVar::img_view_count_buf_B4 = 0;
	for (int i = 0; i < FlowProItemListState_B4.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[3]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[3]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B4[i] == toolName)
			{
				dataVar::img_view_count_B4 = FlowProItemListState_B4.count();
				run_state_B4 = QConfig::ToolBase[3]->RunToolFlow_B4(toolName);
				if (run_state_B4 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B4 = toolName.mid(0, str_count);
				if (tool_name_B4 == "跳转语句")
				{
					if (stop_goto_B4 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[3]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[3]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[3]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B4.count(); p++)
						{
							if (FlowProItemListState_B4[p] == QConfig::ToolBase[3]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B4 = dataVar::img_view_count_buf_B4 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B4 = true;
									}
									dataVar::img_view_count_buf_B4 = dataVar::img_view_count_buf_B4 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B4 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[3]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[3]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B4->GetIfJudgeIndex();
					if (QConfig::ToolBase[3]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B4 = true;
						return;
					}
					else if (QConfig::ToolBase[3]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B4 = if_judge_index;
					}
				}
				else if (tool_name_B4 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[3]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[3]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[3]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B4 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程5
void frmProItemTab::ProgramAutoFlow_B5()
{
	if (dataVar::autoRunOnce_B5 == 0)
	{
		dataVar::autoRunOnce_B5 = 1;
		FlowProItemListState_B5.clear();
		QVector<QString> FlowProItemList_B5 = QVector<QString>(100);
		FlowProItemList_B5.clear();
		FlowProItemList_B5 = TempDragListWidget_B5->GetAllItemList_B5();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B5 = TempDragListWidget_B5->GetItemState_B5();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B5.begin();
		while (iter_icon != GetItemState_B5.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B5.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B5[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B5.append(FlowProItemList_B5[m]);
			}
		}
		QConfig::ToolBase[4]->m_FlowSortList = FlowProItemList_B5;
	}
	dataVar::img_view_count_buf_B5 = 0;
	for (int i = 0; i < FlowProItemListState_B5.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[4]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[4]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B5[i] == toolName)
			{
				dataVar::img_view_count_B5 = FlowProItemListState_B5.count();
				run_state_B5 = QConfig::ToolBase[4]->RunToolFlow_B5(toolName);
				if (run_state_B5 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B5 = toolName.mid(0, str_count);
				if (tool_name_B5 == "跳转语句")
				{
					if (stop_goto_B5 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[4]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[4]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[4]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B5.count(); p++)
						{
							if (FlowProItemListState_B5[p] == QConfig::ToolBase[4]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B5 = dataVar::img_view_count_buf_B5 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B5 = true;
									}
									dataVar::img_view_count_buf_B5 = dataVar::img_view_count_buf_B5 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B5 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[4]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[4]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B5->GetIfJudgeIndex();
					if (QConfig::ToolBase[4]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B5 = true;
						return;
					}
					else if (QConfig::ToolBase[4]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B5 = if_judge_index;
					}
				}
				else if (tool_name_B5 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[4]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[4]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[4]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B5 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程6
void frmProItemTab::ProgramAutoFlow_B6()
{
	if (dataVar::autoRunOnce_B6 == 0)
	{
		dataVar::autoRunOnce_B6 = 1;
		FlowProItemListState_B6.clear();
		QVector<QString> FlowProItemList_B6 = QVector<QString>(100);
		FlowProItemList_B6.clear();
		FlowProItemList_B6 = TempDragListWidget_B6->GetAllItemList_B6();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B6 = TempDragListWidget_B6->GetItemState_B6();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B6.begin();
		while (iter_icon != GetItemState_B6.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B6.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B6[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B6.append(FlowProItemList_B6[m]);
			}
		}
		QConfig::ToolBase[5]->m_FlowSortList = FlowProItemList_B6;
	}
	dataVar::img_view_count_buf_B6 = 0;
	for (int i = 0; i < FlowProItemListState_B6.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[5]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[5]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B6[i] == toolName)
			{
				dataVar::img_view_count_B6 = FlowProItemListState_B6.count();
				run_state_B6 = QConfig::ToolBase[5]->RunToolFlow_B6(toolName);
				if (run_state_B6 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B6 = toolName.mid(0, str_count);
				if (tool_name_B6 == "跳转语句")
				{
					if (stop_goto_B6 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[5]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[5]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[5]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B6.count(); p++)
						{
							if (FlowProItemListState_B6[p] == QConfig::ToolBase[5]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B6 = dataVar::img_view_count_buf_B6 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B6 = true;
									}
									dataVar::img_view_count_buf_B6 = dataVar::img_view_count_buf_B6 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B6 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[5]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[5]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B6->GetIfJudgeIndex();
					if (QConfig::ToolBase[5]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B6 = true;
						return;
					}
					else if (QConfig::ToolBase[5]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B6 = if_judge_index;
					}
				}
				else if (tool_name_B6 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[5]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[5]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[5]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B6 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程7
void frmProItemTab::ProgramAutoFlow_B7()
{
	if (dataVar::autoRunOnce_B7 == 0)
	{
		dataVar::autoRunOnce_B7 = 1;
		FlowProItemListState_B7.clear();
		QVector<QString> FlowProItemList_B7 = QVector<QString>(100);
		FlowProItemList_B7.clear();
		FlowProItemList_B7 = TempDragListWidget_B7->GetAllItemList_B7();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B7 = TempDragListWidget_B7->GetItemState_B7();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B7.begin();
		while (iter_icon != GetItemState_B7.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B7.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B7[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B7.append(FlowProItemList_B7[m]);
			}
		}
		QConfig::ToolBase[6]->m_FlowSortList = FlowProItemList_B7;
	}
	dataVar::img_view_count_buf_B7 = 0;
	for (int i = 0; i < FlowProItemListState_B7.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[6]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[6]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B7[i] == toolName)
			{
				dataVar::img_view_count_B7 = FlowProItemListState_B7.count();
				run_state_B7 = QConfig::ToolBase[6]->RunToolFlow_B7(toolName);
				if (run_state_B7 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B7 = toolName.mid(0, str_count);
				if (tool_name_B7 == "跳转语句")
				{
					if (stop_goto_B7 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[6]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[6]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[6]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B7.count(); p++)
						{
							if (FlowProItemListState_B7[p] == QConfig::ToolBase[6]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B7 = dataVar::img_view_count_buf_B7 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B7 = true;
									}
									dataVar::img_view_count_buf_B7 = dataVar::img_view_count_buf_B7 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B7 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[6]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[6]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B7->GetIfJudgeIndex();
					if (QConfig::ToolBase[6]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B7 = true;
						return;
					}
					else if (QConfig::ToolBase[6]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B7 = if_judge_index;
					}
				}
				else if (tool_name_B7 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[6]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[6]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[6]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B7 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程8
void frmProItemTab::ProgramAutoFlow_B8()
{
	if (dataVar::autoRunOnce_B8 == 0)
	{
		dataVar::autoRunOnce_B8 = 1;
		FlowProItemListState_B8.clear();
		QVector<QString> FlowProItemList_B8 = QVector<QString>(100);
		FlowProItemList_B8.clear();
		FlowProItemList_B8 = TempDragListWidget_B8->GetAllItemList_B8();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B8 = TempDragListWidget_B8->GetItemState_B8();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B8.begin();
		while (iter_icon != GetItemState_B8.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B8.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B8[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B8.append(FlowProItemList_B8[m]);
			}
		}
		QConfig::ToolBase[7]->m_FlowSortList = FlowProItemList_B8;
	}
	dataVar::img_view_count_buf_B8 = 0;
	for (int i = 0; i < FlowProItemListState_B8.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[7]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[7]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B8[i] == toolName)
			{
				dataVar::img_view_count_B8 = FlowProItemListState_B8.count();
				run_state_B8 = QConfig::ToolBase[7]->RunToolFlow_B8(toolName);
				if (run_state_B8 == false)
				{
					return;
				}
				//提取不含数字字符串				
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B8 = toolName.mid(0, str_count);
				if (tool_name_B8 == "跳转语句")
				{
					if (stop_goto_B8 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[7]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[7]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[7]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B8.count(); p++)
						{
							if (FlowProItemListState_B8[p] == QConfig::ToolBase[7]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B8 = dataVar::img_view_count_buf_B8 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B8 = true;
									}
									dataVar::img_view_count_buf_B8 = dataVar::img_view_count_buf_B8 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B8 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[7]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[7]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B8->GetIfJudgeIndex();
					if (QConfig::ToolBase[7]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B8 = true;
						return;
					}
					else if (QConfig::ToolBase[7]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B8 = if_judge_index;
					}
				}
				else if (tool_name_B8 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[7]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[7]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[7]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B8 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程9
void frmProItemTab::ProgramAutoFlow_B9()
{
	if (dataVar::autoRunOnce_B9 == 0)
	{
		dataVar::autoRunOnce_B9 = 1;
		FlowProItemListState_B9.clear();
		QVector<QString> FlowProItemList_B9 = QVector<QString>(100);
		FlowProItemList_B9.clear();
		FlowProItemList_B9 = TempDragListWidget_B9->GetAllItemList_B9();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B9 = TempDragListWidget_B9->GetItemState_B9();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B9.begin();
		while (iter_icon != GetItemState_B9.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B9.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B9[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B9.append(FlowProItemList_B9[m]);
			}
		}
		QConfig::ToolBase[8]->m_FlowSortList = FlowProItemList_B9;
	}
	dataVar::img_view_count_buf_B9 = 0;
	for (int i = 0; i < FlowProItemListState_B9.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[8]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[8]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B9[i] == toolName)
			{
				dataVar::img_view_count_B9 = FlowProItemListState_B9.count();
				run_state_B9 = QConfig::ToolBase[8]->RunToolFlow_B9(toolName);
				if (run_state_B9 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B9 = toolName.mid(0, str_count);
				if (tool_name_B9 == "跳转语句")
				{
					if (stop_goto_B9 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[8]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[8]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[8]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B9.count(); p++)
						{
							if (FlowProItemListState_B9[p] == QConfig::ToolBase[8]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B9 = dataVar::img_view_count_buf_B9 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B9 = true;
									}
									dataVar::img_view_count_buf_B9 = dataVar::img_view_count_buf_B9 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B9 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[8]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[8]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B9->GetIfJudgeIndex();
					if (QConfig::ToolBase[8]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B9 = true;
						return;
					}
					else if (QConfig::ToolBase[8]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B9 = if_judge_index;
					}
				}
				else if (tool_name_B9 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[8]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[8]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[8]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B9 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程10
void frmProItemTab::ProgramAutoFlow_B10()
{
	if (dataVar::autoRunOnce_B10 == 0)
	{
		dataVar::autoRunOnce_B10 = 1;
		FlowProItemListState_B10.clear();
		QVector<QString> FlowProItemList_B10 = QVector<QString>(100);
		FlowProItemList_B10.clear();
		FlowProItemList_B10 = TempDragListWidget_B10->GetAllItemList_B10();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B10 = TempDragListWidget_B10->GetItemState_B10();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B10.begin();
		while (iter_icon != GetItemState_B10.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B10.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B10[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B10.append(FlowProItemList_B10[m]);
			}
		}
		QConfig::ToolBase[9]->m_FlowSortList = FlowProItemList_B10;
	}
	dataVar::img_view_count_buf_B10 = 0;
	for (int i = 0; i < FlowProItemListState_B10.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[9]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[9]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B10[i] == toolName)
			{
				dataVar::img_view_count_B10 = FlowProItemListState_B10.count();
				run_state_B10 = QConfig::ToolBase[9]->RunToolFlow_B10(toolName);
				if (run_state_B10 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B10 = toolName.mid(0, str_count);
				if (tool_name_B10 == "跳转语句")
				{
					if (stop_goto_B10 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[9]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[9]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[9]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B10.count(); p++)
						{
							if (FlowProItemListState_B10[p] == QConfig::ToolBase[9]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B10 = dataVar::img_view_count_buf_B10 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B10 = true;
									}
									dataVar::img_view_count_buf_B10 = dataVar::img_view_count_buf_B10 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B10 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[9]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[9]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B10->GetIfJudgeIndex();
					if (QConfig::ToolBase[9]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B10 = true;
						return;
					}
					else if (QConfig::ToolBase[9]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B10 = if_judge_index;
					}
				}
				else if (tool_name_B10 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[9]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[9]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[9]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B10 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程11
void frmProItemTab::ProgramAutoFlow_B11()
{
	if (dataVar::autoRunOnce_B11 == 0)
	{
		dataVar::autoRunOnce_B11 = 1;
		FlowProItemListState_B11.clear();
		QVector<QString> FlowProItemList_B11 = QVector<QString>(100);
		FlowProItemList_B11.clear();
		FlowProItemList_B11 = TempDragListWidget_B11->GetAllItemList_B11();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B11 = TempDragListWidget_B11->GetItemState_B11();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B11.begin();
		while (iter_icon != GetItemState_B11.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B11.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B11[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B11.append(FlowProItemList_B11[m]);
			}
		}
		QConfig::ToolBase[10]->m_FlowSortList = FlowProItemList_B11;
	}
	dataVar::img_view_count_buf_B11 = 0;
	for (int i = 0; i < FlowProItemListState_B11.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[10]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[10]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B11[i] == toolName)
			{
				dataVar::img_view_count_B11 = FlowProItemListState_B11.count();
				run_state_B11 = QConfig::ToolBase[10]->RunToolFlow_B11(toolName);
				if (run_state_B11 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B11 = toolName.mid(0, str_count);
				if (tool_name_B11 == "跳转语句")
				{
					if (stop_goto_B11 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[10]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[10]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[10]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B11.count(); p++)
						{
							if (FlowProItemListState_B11[p] == QConfig::ToolBase[10]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B11 = dataVar::img_view_count_buf_B11 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B11 = true;
									}
									dataVar::img_view_count_buf_B11 = dataVar::img_view_count_buf_B11 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B11 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[10]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[10]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B11->GetIfJudgeIndex();
					if (QConfig::ToolBase[10]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B11 = true;
						return;
					}
					else if (QConfig::ToolBase[10]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B11 = if_judge_index;
					}
				}
				else if (tool_name_B11 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[10]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[10]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[10]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B11 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程12
void frmProItemTab::ProgramAutoFlow_B12()
{
	if (dataVar::autoRunOnce_B12 == 0)
	{
		dataVar::autoRunOnce_B12 = 1;
		FlowProItemListState_B12.clear();
		QVector<QString> FlowProItemList_B12 = QVector<QString>(100);
		FlowProItemList_B12.clear();
		FlowProItemList_B12 = TempDragListWidget_B12->GetAllItemList_B12();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B12 = TempDragListWidget_B12->GetItemState_B12();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B12.begin();
		while (iter_icon != GetItemState_B12.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B12.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B12[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B12.append(FlowProItemList_B12[m]);
			}
		}
		QConfig::ToolBase[11]->m_FlowSortList = FlowProItemList_B12;
	}
	dataVar::img_view_count_buf_B12 = 0;
	for (int i = 0; i < FlowProItemListState_B12.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[11]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[11]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B12[i] == toolName)
			{
				dataVar::img_view_count_B12 = FlowProItemListState_B12.count();
				run_state_B12 = QConfig::ToolBase[11]->RunToolFlow_B12(toolName);
				if (run_state_B12 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B12 = toolName.mid(0, str_count);
				if (tool_name_B12 == "跳转语句")
				{
					if (stop_goto_B12 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[11]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[11]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[11]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B12.count(); p++)
						{
							if (FlowProItemListState_B12[p] == QConfig::ToolBase[11]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B12 = dataVar::img_view_count_buf_B12 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B12 = true;
									}
									dataVar::img_view_count_buf_B12 = dataVar::img_view_count_buf_B12 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B12 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[11]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[11]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B12->GetIfJudgeIndex();
					if (QConfig::ToolBase[11]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B12 = true;
						return;
					}
					else if (QConfig::ToolBase[11]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B12 = if_judge_index;
					}
				}
				else if (tool_name_B12 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[11]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[11]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[11]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B12 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程13
void frmProItemTab::ProgramAutoFlow_B13()
{
	if (dataVar::autoRunOnce_B13 == 0)
	{
		dataVar::autoRunOnce_B13 = 1;
		FlowProItemListState_B13.clear();
		QVector<QString> FlowProItemList_B13 = QVector<QString>(100);
		FlowProItemList_B13.clear();
		FlowProItemList_B13 = TempDragListWidget_B13->GetAllItemList_B13();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B13 = TempDragListWidget_B13->GetItemState_B13();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B13.begin();
		while (iter_icon != GetItemState_B13.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B13.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B13[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B13.append(FlowProItemList_B13[m]);
			}
		}
		QConfig::ToolBase[12]->m_FlowSortList = FlowProItemList_B13;
	}
	dataVar::img_view_count_buf_B13 = 0;
	for (int i = 0; i < FlowProItemListState_B13.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[12]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[12]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B13[i] == toolName)
			{
				dataVar::img_view_count_B13 = FlowProItemListState_B13.count();
				run_state_B13 = QConfig::ToolBase[12]->RunToolFlow_B13(toolName);
				if (run_state_B13 == false)
				{
					return;
				}
				//提取不含数字字符串				
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B13 = toolName.mid(0, str_count);
				if (tool_name_B13 == "跳转语句")
				{
					if (stop_goto_B13 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[12]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[12]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[12]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B13.count(); p++)
						{
							if (FlowProItemListState_B13[p] == QConfig::ToolBase[12]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B13 = dataVar::img_view_count_buf_B13 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B13 = true;
									}
									dataVar::img_view_count_buf_B13 = dataVar::img_view_count_buf_B13 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B13 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[12]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[12]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B13->GetIfJudgeIndex();
					if (QConfig::ToolBase[12]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B13 = true;
						return;
					}
					else if (QConfig::ToolBase[12]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B13 = if_judge_index;
					}
				}
				else if (tool_name_B13 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[12]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[12]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[12]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B13 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程14
void frmProItemTab::ProgramAutoFlow_B14()
{
	if (dataVar::autoRunOnce_B14 == 0)
	{
		dataVar::autoRunOnce_B14 = 1;
		FlowProItemListState_B14.clear();
		QVector<QString> FlowProItemList_B14 = QVector<QString>(100);
		FlowProItemList_B14.clear();
		FlowProItemList_B14 = TempDragListWidget_B14->GetAllItemList_B14();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B14 = TempDragListWidget_B14->GetItemState_B14();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B14.begin();
		while (iter_icon != GetItemState_B14.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B14.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B14[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B14.append(FlowProItemList_B14[m]);
			}
		}
		QConfig::ToolBase[13]->m_FlowSortList = FlowProItemList_B14;
	}
	dataVar::img_view_count_buf_B14 = 0;
	for (int i = 0; i < FlowProItemListState_B14.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[13]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[13]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B14[i] == toolName)
			{
				dataVar::img_view_count_B14 = FlowProItemListState_B14.count();
				run_state_B14 = QConfig::ToolBase[13]->RunToolFlow_B14(toolName);
				if (run_state_B14 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B14 = toolName.mid(0, str_count);
				if (tool_name_B14 == "跳转语句")
				{
					if (stop_goto_B14 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[13]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[13]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[13]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B14.count(); p++)
						{
							if (FlowProItemListState_B14[p] == QConfig::ToolBase[13]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B14 = dataVar::img_view_count_buf_B14 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B14 = true;
									}
									dataVar::img_view_count_buf_B14 = dataVar::img_view_count_buf_B14 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B14 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[13]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[13]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B14->GetIfJudgeIndex();
					if (QConfig::ToolBase[13]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B14 = true;
						return;
					}
					else if (QConfig::ToolBase[13]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B14 = if_judge_index;
					}
				}
				else if (tool_name_B14 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[13]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[13]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[13]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B14 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程15
void frmProItemTab::ProgramAutoFlow_B15()
{
	if (dataVar::autoRunOnce_B15 == 0)
	{
		dataVar::autoRunOnce_B15 = 1;
		FlowProItemListState_B15.clear();
		QVector<QString> FlowProItemList_B15 = QVector<QString>(100);
		FlowProItemList_B15.clear();
		FlowProItemList_B15 = TempDragListWidget_B15->GetAllItemList_B15();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B15 = TempDragListWidget_B15->GetItemState_B15();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B15.begin();
		while (iter_icon != GetItemState_B15.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B15.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B15[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B15.append(FlowProItemList_B15[m]);
			}
		}
		QConfig::ToolBase[14]->m_FlowSortList = FlowProItemList_B15;
	}
	dataVar::img_view_count_buf_B15 = 0;
	for (int i = 0; i < FlowProItemListState_B15.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[14]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[14]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B15[i] == toolName)
			{
				dataVar::img_view_count_B15 = FlowProItemListState_B15.count();
				run_state_B15 = QConfig::ToolBase[14]->RunToolFlow_B15(toolName);
				if (run_state_B15 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B15 = toolName.mid(0, str_count);
				if (tool_name_B15 == "跳转语句")
				{
					if (stop_goto_B15 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[14]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[14]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[14]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B15.count(); p++)
						{
							if (FlowProItemListState_B15[p] == QConfig::ToolBase[14]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B15 = dataVar::img_view_count_buf_B15 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B15 = true;
									}
									dataVar::img_view_count_buf_B15 = dataVar::img_view_count_buf_B15 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B15 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[14]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[14]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B15->GetIfJudgeIndex();
					if (QConfig::ToolBase[14]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B15 = true;
						return;
					}
					else if (QConfig::ToolBase[14]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B15 = if_judge_index;
					}
				}
				else if (tool_name_B15 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[14]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[14]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[14]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B15 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程16
void frmProItemTab::ProgramAutoFlow_B16()
{
	if (dataVar::autoRunOnce_B16 == 0)
	{
		dataVar::autoRunOnce_B16 = 1;
		FlowProItemListState_B16.clear();
		QVector<QString> FlowProItemList_B16 = QVector<QString>(100);
		FlowProItemList_B16.clear();
		FlowProItemList_B16 = TempDragListWidget_B16->GetAllItemList_B16();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B16 = TempDragListWidget_B16->GetItemState_B16();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B16.begin();
		while (iter_icon != GetItemState_B16.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B16.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B16[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B16.append(FlowProItemList_B16[m]);
			}
		}
		QConfig::ToolBase[15]->m_FlowSortList = FlowProItemList_B16;
	}
	dataVar::img_view_count_buf_B16 = 0;
	for (int i = 0; i < FlowProItemListState_B16.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[15]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[15]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B16[i] == toolName)
			{
				dataVar::img_view_count_B16 = FlowProItemListState_B16.count();
				run_state_B16 = QConfig::ToolBase[15]->RunToolFlow_B16(toolName);
				if (run_state_B16 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B16 = toolName.mid(0, str_count);
				if (tool_name_B16 == "跳转语句")
				{
					if (stop_goto_B16 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[15]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[15]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[15]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B16.count(); p++)
						{
							if (FlowProItemListState_B16[p] == QConfig::ToolBase[15]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B16 = dataVar::img_view_count_buf_B16 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B16 = true;
									}
									dataVar::img_view_count_buf_B16 = dataVar::img_view_count_buf_B16 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B16 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[15]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[15]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B16->GetIfJudgeIndex();
					if (QConfig::ToolBase[15]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B16 = true;
						return;
					}
					else if (QConfig::ToolBase[15]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B16 = if_judge_index;
					}
				}
				else if (tool_name_B16 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[15]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[15]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[15]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B16 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程17
void frmProItemTab::ProgramAutoFlow_B17()
{
	if (dataVar::autoRunOnce_B17 == 0)
	{
		dataVar::autoRunOnce_B17 = 1;
		FlowProItemListState_B17.clear();
		QVector<QString> FlowProItemList_B17 = QVector<QString>(100);
		FlowProItemList_B17.clear();
		FlowProItemList_B17 = TempDragListWidget_B17->GetAllItemList_B17();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B17 = TempDragListWidget_B17->GetItemState_B17();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B17.begin();
		while (iter_icon != GetItemState_B17.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B17.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B17[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B17.append(FlowProItemList_B17[m]);
			}
		}
		QConfig::ToolBase[16]->m_FlowSortList = FlowProItemList_B17;
	}
	dataVar::img_view_count_buf_B17 = 0;
	for (int i = 0; i < FlowProItemListState_B17.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[16]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[16]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B17[i] == toolName)
			{
				dataVar::img_view_count_B17 = FlowProItemListState_B17.count();
				run_state_B17 = QConfig::ToolBase[16]->RunToolFlow_B17(toolName);
				if (run_state_B17 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B17 = toolName.mid(0, str_count);
				if (tool_name_B17 == "跳转语句")
				{
					if (stop_goto_B17 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[16]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[16]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[16]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B17.count(); p++)
						{
							if (FlowProItemListState_B17[p] == QConfig::ToolBase[16]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B17 = dataVar::img_view_count_buf_B17 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B17 = true;
									}
									dataVar::img_view_count_buf_B17 = dataVar::img_view_count_buf_B17 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B17 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[16]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[16]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B17->GetIfJudgeIndex();
					if (QConfig::ToolBase[16]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B17 = true;
						return;
					}
					else if (QConfig::ToolBase[16]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B17 = if_judge_index;
					}
				}
				else if (tool_name_B17 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[16]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[16]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[16]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B17 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程18
void frmProItemTab::ProgramAutoFlow_B18()
{
	if (dataVar::autoRunOnce_B18 == 0)
	{
		dataVar::autoRunOnce_B18 = 1;
		FlowProItemListState_B18.clear();
		QVector<QString> FlowProItemList_B18 = QVector<QString>(100);
		FlowProItemList_B18.clear();
		FlowProItemList_B18 = TempDragListWidget_B18->GetAllItemList_B18();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B18 = TempDragListWidget_B18->GetItemState_B18();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B18.begin();
		while (iter_icon != GetItemState_B18.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B18.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B18[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B18.append(FlowProItemList_B18[m]);
			}
		}
		QConfig::ToolBase[17]->m_FlowSortList = FlowProItemList_B18;
	}
	dataVar::img_view_count_buf_B18 = 0;
	for (int i = 0; i < FlowProItemListState_B18.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[17]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[17]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B18[i] == toolName)
			{
				dataVar::img_view_count_B18 = FlowProItemListState_B18.count();
				run_state_B18 = QConfig::ToolBase[17]->RunToolFlow_B18(toolName);
				if (run_state_B18 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B18 = toolName.mid(0, str_count);
				if (tool_name_B18 == "跳转语句")
				{
					if (stop_goto_B18 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[17]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[17]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[17]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B18.count(); p++)
						{
							if (FlowProItemListState_B18[p] == QConfig::ToolBase[17]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B18 = dataVar::img_view_count_buf_B18 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B18 = true;
									}
									dataVar::img_view_count_buf_B18 = dataVar::img_view_count_buf_B18 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B18 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[17]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[17]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B18->GetIfJudgeIndex();
					if (QConfig::ToolBase[17]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B18 = true;
						return;
					}
					else if (QConfig::ToolBase[17]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B18 = if_judge_index;
					}
				}
				else if (tool_name_B18 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[17]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[17]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[17]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B18 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程19
void frmProItemTab::ProgramAutoFlow_B19()
{
	if (dataVar::autoRunOnce_B19 == 0)
	{
		dataVar::autoRunOnce_B19 = 1;
		FlowProItemListState_B19.clear();
		QVector<QString> FlowProItemList_B19 = QVector<QString>(100);
		FlowProItemList_B19.clear();
		FlowProItemList_B19 = TempDragListWidget_B19->GetAllItemList_B19();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B19 = TempDragListWidget_B19->GetItemState_B19();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B19.begin();
		while (iter_icon != GetItemState_B19.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B19.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B19[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B19.append(FlowProItemList_B19[m]);
			}
		}
		QConfig::ToolBase[18]->m_FlowSortList = FlowProItemList_B19;
	}
	dataVar::img_view_count_buf_B19 = 0;
	for (int i = 0; i < FlowProItemListState_B19.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[18]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[18]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B19[i] == toolName)
			{
				dataVar::img_view_count_B19 = FlowProItemListState_B19.count();
				run_state_B19 = QConfig::ToolBase[18]->RunToolFlow_B19(toolName);
				if (run_state_B19 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B19 = toolName.mid(0, str_count);
				if (tool_name_B19 == "跳转语句")
				{
					if (stop_goto_B19 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[18]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[18]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[18]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B19.count(); p++)
						{
							if (FlowProItemListState_B19[p] == QConfig::ToolBase[18]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B19 = dataVar::img_view_count_buf_B19 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B19 = true;
									}
									dataVar::img_view_count_buf_B19 = dataVar::img_view_count_buf_B19 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B19 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[18]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[18]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B19->GetIfJudgeIndex();
					if (QConfig::ToolBase[18]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B19 = true;
						return;
					}
					else if (QConfig::ToolBase[18]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B19 = if_judge_index;
					}
				}
				else if (tool_name_B19 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[18]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[18]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[18]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B19 = true;
						return;
					}
				}
				break;
			}
		}
	}
}

//自动程序流程20
void frmProItemTab::ProgramAutoFlow_B20()
{
	if (dataVar::autoRunOnce_B20 == 0)
	{
		dataVar::autoRunOnce_B20 = 1;
		FlowProItemListState_B20.clear();
		QVector<QString> FlowProItemList_B20 = QVector<QString>(100);
		FlowProItemList_B20.clear();
		FlowProItemList_B20 = TempDragListWidget_B20->GetAllItemList_B20();
		//获取流程中工具的激活/禁用状态	
		QList<QString> flowNames;
		flowNames.reserve(100);
		flowNames.clear();
		GetItemState_B20 = TempDragListWidget_B20->GetItemState_B20();
		QMap<QString, QtDragListWidget*>::iterator iter_icon = GetItemState_B20.begin();
		while (iter_icon != GetItemState_B20.end())
		{
			if (iter_icon.key() != QString())
			{
				flowNames.append(iter_icon.key());
			}
			iter_icon++;
		}
		for (int m = 0; m < FlowProItemList_B20.count(); m++)
		{
			bool list_state = false;
			for (int n = 0; n < flowNames.count(); n++)
			{
				if (FlowProItemList_B20[m] == flowNames[n])
				{
					list_state = true;
				}
			}
			if (list_state == false)
			{
				FlowProItemListState_B20.append(FlowProItemList_B20[m]);
			}
		}
		QConfig::ToolBase[19]->m_FlowSortList = FlowProItemList_B20;
	}
	dataVar::img_view_count_buf_B20 = 0;
	for (int i = 0; i < FlowProItemListState_B20.count(); i++)
	{
		for (int j = 0; j < QConfig::ToolBase[19]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[19]->m_Tools[j].PublicToolName;
			if (FlowProItemListState_B20[i] == toolName)
			{
				dataVar::img_view_count_B20 = FlowProItemListState_B20.count();
				run_state_B20 = QConfig::ToolBase[19]->RunToolFlow_B20(toolName);
				if (run_state_B20 == false)
				{
					return;
				}
				//提取不含数字字符串			
				int str_count = 0;
				for (int k = 0; k < toolName.length(); k++)
				{
					if (!(toolName[k] > '0' && toolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString tool_name_B20 = toolName.mid(0, str_count);
				if (tool_name_B20 == "跳转语句")
				{
					if (stop_goto_B20 == true)
					{
						return;
					}
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[19]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[19]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[19]->m_Tools[end_index].PublicResult.State == true)
					{
						for (int p = 0; p < FlowProItemListState_B20.count(); p++)
						{
							if (FlowProItemListState_B20[p] == QConfig::ToolBase[19]->m_Tools[end_index].PublicLogic.GotoToolName)
							{
								if (i < p)
								{
									dataVar::img_view_count_buf_B20 = dataVar::img_view_count_buf_B20 + (p - i - 1);
									i = p - 1;
								}
								else
								{
									if (stop_goto_manual_B == true)
									{
										stop_goto_B20 = true;
									}
									dataVar::img_view_count_buf_B20 = dataVar::img_view_count_buf_B20 - (i - p - 1);
									i = p - 1;
								}
							}
						}
					}
				}
				else if (tool_name_B20 == "判断语句")
				{
					int judge_index = 0;
					for (int q = 0; q < QConfig::ToolBase[19]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[19]->m_Tools[q].PublicToolName == toolName)
						{
							judge_index = q;
						}
					}
					int if_judge_index = TempDragListWidget_B20->GetIfJudgeIndex();
					if (QConfig::ToolBase[19]->m_Tools[judge_index].PublicResult.State == false && if_judge_index == 0)
					{
						dataVar::runFinish_B20 = true;
						return;
					}
					else if (QConfig::ToolBase[19]->m_Tools[judge_index].PublicResult.State == false && if_judge_index != 0)
					{
						i = if_judge_index - 1;
						dataVar::img_view_count_buf_B20 = if_judge_index;
					}
				}
				else if (tool_name_B20 == "结束语句")
				{
					int end_index = 0;
					for (int q = 0; q < QConfig::ToolBase[19]->m_Tools.size(); q++)
					{
						if (QConfig::ToolBase[19]->m_Tools[q].PublicToolName == toolName)
						{
							end_index = q;
						}
					}
					if (QConfig::ToolBase[19]->m_Tools[end_index].PublicResult.State == true)
					{
						dataVar::runFinish_B20 = true;
						return;
					}
				}
				break;
			}
		}
	}
}
#pragma endregion

#pragma region 线程
void frmProItemTab::Begin_Thread_A()
{
	if (Thread_A->isRunning() == false)
	{
		dataVar::manualCycleThread.setStopFlag(false);
		dataVar::manualCycleThread.setPauseFlag(false);
		Thread_A->start();
		dataVar::runFinish_A = true;
		emit sig_CyclePro();
	}
}

void frmProItemTab::Stop_Thread_A()
{
	if (Thread_A != nullptr)
	{
		dataVar::manualCycleThread.setStopFlag(true);
		if (Thread_A->isRunning() == true)
		{
			dataVar::runFinish_A = false;
			stop_goto_A = true;
			Thread_A->quit();
		}
	}
	emit sig_CycleProErr();
}

void frmProItemTab::Stop_Thread_B()
{
	dataVar::stopThread_B1 = 1;
	dataVar::stopThread_B2 = 1;
	dataVar::stopThread_B3 = 1;
	dataVar::stopThread_B4 = 1;
	dataVar::stopThread_B5 = 1;
	dataVar::stopThread_B6 = 1;
	dataVar::stopThread_B7 = 1;
	dataVar::stopThread_B8 = 1;
	dataVar::stopThread_B9 = 1;
	dataVar::stopThread_B10 = 1;
	dataVar::stopThread_B11 = 1;
	dataVar::stopThread_B12 = 1;
	dataVar::stopThread_B13 = 1;
	dataVar::stopThread_B14 = 1;
	dataVar::stopThread_B15 = 1;
	dataVar::stopThread_B16 = 1;
	dataVar::stopThread_B17 = 1;
	dataVar::stopThread_B18 = 1;
	dataVar::stopThread_B19 = 1;
	dataVar::stopThread_B20 = 1;
}

void frmProItemTab::Begin_Thread_B1()
{
	if (Thread_B1->isRunning() == false)
	{
		dataVar::autoCycleThread_B1.setStopFlag_B1(false);
		Thread_B1->start();
		emit sig_CyclePro_B1();
	}
}

void frmProItemTab::Stop_Thread_B1()
{
	if (Thread_B1 != nullptr)
	{
		dataVar::autoCycleThread_B1.setStopFlag_B1(true);
		if (Thread_B1->isRunning() == true)
		{
			dataVar::runFinish_B1 = false;
			stop_goto_B1 = true;
			Thread_B1->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B2()
{
	if (Thread_B2->isRunning() == false)
	{
		dataVar::autoCycleThread_B2.setStopFlag_B2(false);
		Thread_B2->start();
		emit sig_CyclePro_B2();
	}
}

void frmProItemTab::Stop_Thread_B2()
{
	if (Thread_B2 != nullptr)
	{
		dataVar::autoCycleThread_B2.setStopFlag_B2(true);
		if (Thread_B2->isRunning() == true)
		{
			dataVar::runFinish_B2 = false;
			stop_goto_B2 = true;
			Thread_B2->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B3()
{
	if (Thread_B3->isRunning() == false)
	{
		dataVar::autoCycleThread_B3.setStopFlag_B3(false);
		Thread_B3->start();
		emit sig_CyclePro_B3();
	}
}

void frmProItemTab::Stop_Thread_B3()
{
	if (Thread_B3 != nullptr)
	{
		dataVar::autoCycleThread_B3.setStopFlag_B3(true);
		if (Thread_B3->isRunning() == true)
		{
			dataVar::runFinish_B3 = false;
			stop_goto_B3 = true;
			Thread_B3->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B4()
{
	if (Thread_B4->isRunning() == false)
	{
		dataVar::autoCycleThread_B4.setStopFlag_B4(false);
		Thread_B4->start();
		emit sig_CyclePro_B4();
	}
}

void frmProItemTab::Stop_Thread_B4()
{
	if (Thread_B4 != nullptr)
	{
		dataVar::autoCycleThread_B4.setStopFlag_B4(true);
		if (Thread_B4->isRunning() == true)
		{
			dataVar::runFinish_B4 = false;
			stop_goto_B4 = true;
			Thread_B4->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B5()
{
	if (Thread_B5->isRunning() == false)
	{
		dataVar::autoCycleThread_B5.setStopFlag_B5(false);
		Thread_B5->start();
		emit sig_CyclePro_B5();
	}
}

void frmProItemTab::Stop_Thread_B5()
{
	if (Thread_B5 != nullptr)
	{
		dataVar::autoCycleThread_B5.setStopFlag_B5(true);
		if (Thread_B5->isRunning() == true)
		{
			dataVar::runFinish_B5 = false;
			stop_goto_B5 = true;
			Thread_B5->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B6()
{
	if (Thread_B6->isRunning() == false)
	{
		dataVar::autoCycleThread_B6.setStopFlag_B6(false);
		Thread_B6->start();
		emit sig_CyclePro_B6();
	}
}

void frmProItemTab::Stop_Thread_B6()
{
	if (Thread_B6 != nullptr)
	{
		dataVar::autoCycleThread_B6.setStopFlag_B6(true);
		if (Thread_B6->isRunning() == true)
		{
			dataVar::runFinish_B6 = false;
			stop_goto_B6 = true;
			Thread_B6->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B7()
{
	if (Thread_B7->isRunning() == false)
	{
		dataVar::autoCycleThread_B7.setStopFlag_B7(false);
		Thread_B7->start();
		emit sig_CyclePro_B7();
	}
}

void frmProItemTab::Stop_Thread_B7()
{
	if (Thread_B7 != nullptr)
	{
		dataVar::autoCycleThread_B7.setStopFlag_B7(true);
		if (Thread_B7->isRunning() == true)
		{
			dataVar::runFinish_B7 = false;
			stop_goto_B7 = true;
			Thread_B7->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B8()
{
	if (Thread_B8->isRunning() == false)
	{
		dataVar::autoCycleThread_B8.setStopFlag_B8(false);
		Thread_B8->start();
		emit sig_CyclePro_B8();
	}
}

void frmProItemTab::Stop_Thread_B8()
{
	if (Thread_B8 != nullptr)
	{
		dataVar::autoCycleThread_B8.setStopFlag_B8(true);
		if (Thread_B8->isRunning() == true)
		{
			dataVar::runFinish_B8 = false;
			stop_goto_B8 = true;
			Thread_B8->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B9()
{
	if (Thread_B9->isRunning() == false)
	{
		dataVar::autoCycleThread_B9.setStopFlag_B9(false);
		Thread_B9->start();
		emit sig_CyclePro_B9();
	}
}

void frmProItemTab::Stop_Thread_B9()
{
	if (Thread_B9 != nullptr)
	{
		dataVar::autoCycleThread_B9.setStopFlag_B9(true);
		if (Thread_B9->isRunning() == true)
		{
			dataVar::runFinish_B9 = false;
			stop_goto_B9 = true;
			Thread_B9->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B10()
{
	if (Thread_B10->isRunning() == false)
	{
		dataVar::autoCycleThread_B10.setStopFlag_B10(false);
		Thread_B10->start();
		emit sig_CyclePro_B10();
	}
}

void frmProItemTab::Stop_Thread_B10()
{
	if (Thread_B10 != nullptr)
	{
		dataVar::autoCycleThread_B10.setStopFlag_B10(true);
		if (Thread_B10->isRunning() == true)
		{
			dataVar::runFinish_B10 = false;
			stop_goto_B10 = true;
			Thread_B10->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B11()
{
	if (Thread_B11->isRunning() == false)
	{
		dataVar::autoCycleThread_B11.setStopFlag_B11(false);
		Thread_B11->start();
		emit sig_CyclePro_B11();
	}
}

void frmProItemTab::Stop_Thread_B11()
{
	if (Thread_B11 != nullptr)
	{
		dataVar::autoCycleThread_B11.setStopFlag_B11(true);
		if (Thread_B11->isRunning() == true)
		{
			dataVar::runFinish_B11 = false;
			stop_goto_B11 = true;
			Thread_B11->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B12()
{
	if (Thread_B12->isRunning() == false)
	{
		dataVar::autoCycleThread_B12.setStopFlag_B12(false);
		Thread_B12->start();
		emit sig_CyclePro_B12();
	}
}

void frmProItemTab::Stop_Thread_B12()
{
	if (Thread_B12 != nullptr)
	{
		dataVar::autoCycleThread_B12.setStopFlag_B12(true);
		if (Thread_B12->isRunning() == true)
		{
			dataVar::runFinish_B12 = false;
			stop_goto_B12 = true;
			Thread_B12->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B13()
{
	if (Thread_B13->isRunning() == false)
	{
		dataVar::autoCycleThread_B13.setStopFlag_B13(false);
		Thread_B13->start();
		emit sig_CyclePro_B13();
	}
}

void frmProItemTab::Stop_Thread_B13()
{
	if (Thread_B13 != nullptr)
	{
		dataVar::autoCycleThread_B13.setStopFlag_B13(true);
		if (Thread_B13->isRunning() == true)
		{
			dataVar::runFinish_B13 = false;
			stop_goto_B13 = true;
			Thread_B13->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B14()
{
	if (Thread_B14->isRunning() == false)
	{
		dataVar::autoCycleThread_B14.setStopFlag_B14(false);
		Thread_B14->start();
		emit sig_CyclePro_B14();
	}
}

void frmProItemTab::Stop_Thread_B14()
{
	if (Thread_B14 != nullptr)
	{
		dataVar::autoCycleThread_B14.setStopFlag_B14(true);
		if (Thread_B14->isRunning() == true)
		{
			dataVar::runFinish_B14 = false;
			stop_goto_B14 = true;
			Thread_B14->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B15()
{
	if (Thread_B15->isRunning() == false)
	{
		dataVar::autoCycleThread_B15.setStopFlag_B15(false);
		Thread_B15->start();
		emit sig_CyclePro_B15();
	}
}

void frmProItemTab::Stop_Thread_B15()
{
	if (Thread_B15 != nullptr)
	{
		dataVar::autoCycleThread_B15.setStopFlag_B15(true);
		if (Thread_B15->isRunning() == true)
		{
			dataVar::runFinish_B15 = false;
			stop_goto_B15 = true;
			Thread_B15->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B16()
{
	if (Thread_B16->isRunning() == false)
	{
		dataVar::autoCycleThread_B16.setStopFlag_B16(false);
		Thread_B16->start();
		emit sig_CyclePro_B16();
	}
}

void frmProItemTab::Stop_Thread_B16()
{
	if (Thread_B16 != nullptr)
	{
		dataVar::autoCycleThread_B16.setStopFlag_B16(true);
		if (Thread_B16->isRunning() == true)
		{
			dataVar::runFinish_B16 = false;
			stop_goto_B16 = true;
			Thread_B16->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B17()
{
	if (Thread_B17->isRunning() == false)
	{
		dataVar::autoCycleThread_B17.setStopFlag_B17(false);
		Thread_B17->start();
		emit sig_CyclePro_B17();
	}
}

void frmProItemTab::Stop_Thread_B17()
{
	if (Thread_B17 != nullptr)
	{
		dataVar::autoCycleThread_B17.setStopFlag_B17(true);
		if (Thread_B17->isRunning() == true)
		{
			dataVar::runFinish_B17 = false;
			stop_goto_B17 = true;
			Thread_B17->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B18()
{
	if (Thread_B18->isRunning() == false)
	{
		dataVar::autoCycleThread_B18.setStopFlag_B18(false);
		Thread_B18->start();
		emit sig_CyclePro_B18();
	}
}

void frmProItemTab::Stop_Thread_B18()
{
	if (Thread_B18 != nullptr)
	{
		dataVar::autoCycleThread_B18.setStopFlag_B18(true);
		if (Thread_B18->isRunning() == true)
		{
			dataVar::runFinish_B18 = false;
			stop_goto_B18 = true;
			Thread_B18->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B19()
{
	if (Thread_B19->isRunning() == false)
	{
		dataVar::autoCycleThread_B19.setStopFlag_B19(false);
		Thread_B19->start();
		emit sig_CyclePro_B19();
	}
}

void frmProItemTab::Stop_Thread_B19()
{
	if (Thread_B19 != nullptr)
	{
		dataVar::autoCycleThread_B19.setStopFlag_B19(true);
		if (Thread_B19->isRunning() == true)
		{
			dataVar::runFinish_B19 = false;
			stop_goto_B19 = true;
			Thread_B19->quit();
		}
	}
}

void frmProItemTab::Begin_Thread_B20()
{
	if (Thread_B20->isRunning() == false)
	{
		dataVar::autoCycleThread_B20.setStopFlag_B20(false);
		Thread_B20->start();
		emit sig_CyclePro_B20();
	}
}

void frmProItemTab::Stop_Thread_B20()
{
	if (Thread_B20 != nullptr)
	{
		dataVar::autoCycleThread_B20.setStopFlag_B20(true);
		if (Thread_B20->isRunning() == true)
		{
			dataVar::runFinish_B20 = false;
			stop_goto_B20 = true;
			Thread_B20->quit();
		}
	}
}
#pragma endregion

#pragma region 流程工具错误信息
//流程1工具错误信息
void frmProItemTab::slot_ToolWrong_B1(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B1 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B1(toolName, strTime);
	emit sig_IconShow_B1(toolName, QPixmap(":/res/ico/err.png"));
}

//流程2工具错误信息
void frmProItemTab::slot_ToolWrong_B2(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B2 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B2(toolName, strTime);
	emit sig_IconShow_B2(toolName, QPixmap(":/res/ico/err.png"));
}

//流程3工具错误信息
void frmProItemTab::slot_ToolWrong_B3(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B3 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B3(toolName, strTime);
	emit sig_IconShow_B3(toolName, QPixmap(":/res/ico/err.png"));
}

//流程4工具错误信息
void frmProItemTab::slot_ToolWrong_B4(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B4 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B4(toolName, strTime);
	emit sig_IconShow_B4(toolName, QPixmap(":/res/ico/err.png"));
}

//流程5工具错误信息
void frmProItemTab::slot_ToolWrong_B5(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B5 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B5(toolName, strTime);
	emit sig_IconShow_B5(toolName, QPixmap(":/res/ico/err.png"));
}

//流程6工具错误信息
void frmProItemTab::slot_ToolWrong_B6(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B6 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B6(toolName, strTime);
	emit sig_IconShow_B6(toolName, QPixmap(":/res/ico/err.png"));
}

//流程7工具错误信息
void frmProItemTab::slot_ToolWrong_B7(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B7 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B7(toolName, strTime);
	emit sig_IconShow_B7(toolName, QPixmap(":/res/ico/err.png"));
}

//流程8工具错误信息
void frmProItemTab::slot_ToolWrong_B8(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B8 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B8(toolName, strTime);
	emit sig_IconShow_B8(toolName, QPixmap(":/res/ico/err.png"));
}

//流程9工具错误信息
void frmProItemTab::slot_ToolWrong_B9(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B9 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B9(toolName, strTime);
	emit sig_IconShow_B9(toolName, QPixmap(":/res/ico/err.png"));
}

//流程10工具错误信息
void frmProItemTab::slot_ToolWrong_B10(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B10 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B10(toolName, strTime);
	emit sig_IconShow_B10(toolName, QPixmap(":/res/ico/err.png"));
}

//流程11工具错误信息
void frmProItemTab::slot_ToolWrong_B11(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B11 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B11(toolName, strTime);
	emit sig_IconShow_B11(toolName, QPixmap(":/res/ico/err.png"));
}

//流程12工具错误信息
void frmProItemTab::slot_ToolWrong_B12(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B12 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B12(toolName, strTime);
	emit sig_IconShow_B12(toolName, QPixmap(":/res/ico/err.png"));
}

//流程13工具错误信息
void frmProItemTab::slot_ToolWrong_B13(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B13 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B13(toolName, strTime);
	emit sig_IconShow_B13(toolName, QPixmap(":/res/ico/err.png"));
}

//流程14工具错误信息
void frmProItemTab::slot_ToolWrong_B14(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B14 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B14(toolName, strTime);
	emit sig_IconShow_B14(toolName, QPixmap(":/res/ico/err.png"));
}

//流程15工具错误信息
void frmProItemTab::slot_ToolWrong_B15(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B15 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B15(toolName, strTime);
	emit sig_IconShow_B15(toolName, QPixmap(":/res/ico/err.png"));
}

//流程16工具错误信息
void frmProItemTab::slot_ToolWrong_B16(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B16 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B16(toolName, strTime);
	emit sig_IconShow_B16(toolName, QPixmap(":/res/ico/err.png"));
}

//流程17工具错误信息
void frmProItemTab::slot_ToolWrong_B17(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B17 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B17(toolName, strTime);
	emit sig_IconShow_B17(toolName, QPixmap(":/res/ico/err.png"));
}

//流程18工具错误信息
void frmProItemTab::slot_ToolWrong_B18(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B18 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B18(toolName, strTime);
	emit sig_IconShow_B18(toolName, QPixmap(":/res/ico/err.png"));
}

//流程19工具错误信息
void frmProItemTab::slot_ToolWrong_B19(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B19 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B19(toolName, strTime);
	emit sig_IconShow_B19(toolName, QPixmap(":/res/ico/err.png"));
}

//流程20工具错误信息
void frmProItemTab::slot_ToolWrong_B20(const QString toolName)
{
	if (dataVar::m_a_state == 1)
	{
		dataVar::manualRunOnce_A = 1;
	}
	else if (dataVar::m_a_state == 2)
	{
		dataVar::autoRunOnce_B20 = 1;
	}
	QString strTime = QString::number(-1) + "ms";
	emit sig_TextShow_B20(toolName, strTime);
	emit sig_IconShow_B20(toolName, QPixmap(":/res/ico/err.png"));
}
#pragma endregion

#pragma region 流程刷新工具处理结果
//流程1刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B1(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B1) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标			
			emit sig_IconShow_B1(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		if (dataVar::autoRunOnce_B1 == 1)
		{
			//工具执行正常图标				
			emit sig_IconShow_B1(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B1(toolName, strTime);
	//提取不含数字字符串		
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B1 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B1 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[0]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[0]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[0]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[0]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B1 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B1 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B1 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B1 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B1 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B1 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B1 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B1 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B1 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B1 != nullptr)
		{
			state_B1 = QConfig::ToolBase[0]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B1 == true)
			{
				nViewMsgState_B1.clear();
				nViewMsgState_B1 = QConfig::ToolBase[0]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B1.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B1[n]);
				}
			}
			emit sig_ImageShow_B1(dataVar::img_view_B1, out_img);
		}
	}
	++dataVar::img_view_count_buf_B1;
	if (dataVar::img_view_count_buf_B1 == dataVar::img_view_count_B1)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B1 = 2;
		dataVar::img_view_count_B1 = 0;
		dataVar::img_view_count_buf_B1 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B1 = true;
		}
	}
}

//流程2刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B2(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B2) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标			
			emit sig_IconShow_B2(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		if (dataVar::autoRunOnce_B2 == 1)
		{
			//工具执行正常图标				
			emit sig_IconShow_B2(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B2(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B2 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B2 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[1]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[1]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[1]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[1]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B2 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B2 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B2 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B2 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B2 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B2 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B2 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B2 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B2 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B2 != nullptr)
		{
			state_B2 = QConfig::ToolBase[1]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B2 == true)
			{
				nViewMsgState_B2.clear();
				nViewMsgState_B2 = QConfig::ToolBase[1]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B2.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B2[n]);
				}
			}
			emit sig_ImageShow_B2(dataVar::img_view_B2, out_img);
		}
	}
	++dataVar::img_view_count_buf_B2;
	if (dataVar::img_view_count_buf_B2 == dataVar::img_view_count_B2)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B2 = 2;
		dataVar::img_view_count_B2 = 0;
		dataVar::img_view_count_buf_B2 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B2 = true;
		}
	}
}

//流程3刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B3(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B3) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B3(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		if (dataVar::autoRunOnce_B3 == 1)
		{
			//工具执行正常图标				
			emit sig_IconShow_B3(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B3(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B3 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B3 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[2]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[2]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[2]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[2]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B3 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B3 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B3 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B3 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B3 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B3 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B3 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B3 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B3 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B3 != nullptr)
		{
			state_B3 = QConfig::ToolBase[2]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B3 == true)
			{
				nViewMsgState_B3.clear();
				nViewMsgState_B3 = QConfig::ToolBase[2]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B3.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B3[n]);
				}
			}
			emit sig_ImageShow_B3(dataVar::img_view_B3, out_img);
		}
	}
	++dataVar::img_view_count_buf_B3;
	if (dataVar::img_view_count_buf_B3 == dataVar::img_view_count_B3)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B3 = 2;
		dataVar::img_view_count_B3 = 0;
		dataVar::img_view_count_buf_B3 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B3 = true;
		}
	}
}

//流程4刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B4(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B4) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B4(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B4 == 1)
		{
			emit sig_IconShow_B4(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B4(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B4 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B4 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[3]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[3]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[3]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[3]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B4 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B4 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B4 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B4 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B4 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B4 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B4 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B4 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B4 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B4 != nullptr)
		{
			state_B4 = QConfig::ToolBase[3]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B4 == true)
			{
				nViewMsgState_B4.clear();
				nViewMsgState_B4 = QConfig::ToolBase[3]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B4.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B4[n]);
				}
			}
			emit sig_ImageShow_B4(dataVar::img_view_B4, out_img);
		}
	}
	++dataVar::img_view_count_buf_B4;
	if (dataVar::img_view_count_buf_B4 == dataVar::img_view_count_B4)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B4 = 2;
		dataVar::img_view_count_B4 = 0;
		dataVar::img_view_count_buf_B4 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B4 = true;
		}
	}
}

//流程5刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B5(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B5) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标		
			emit sig_IconShow_B5(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B5 == 1)
		{
			emit sig_IconShow_B5(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B5(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B5 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B5 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[4]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[4]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[4]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[4]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B5 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B5 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B5 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B5 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B5 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B5 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B5 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B5 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B5 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B5 != nullptr)
		{
			state_B5 = QConfig::ToolBase[4]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B5 == true)
			{
				nViewMsgState_B5.clear();
				nViewMsgState_B5 = QConfig::ToolBase[4]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B5.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B5[n]);
				}
			}
			emit sig_ImageShow_B5(dataVar::img_view_B5, out_img);
		}
	}
	++dataVar::img_view_count_buf_B5;
	if (dataVar::img_view_count_buf_B5 == dataVar::img_view_count_B5)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B5 = 2;
		dataVar::img_view_count_B5 = 0;
		dataVar::img_view_count_buf_B5 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B5 = true;
		}
	}
}

//流程6刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B6(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B6) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B6(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B6 == 1)
		{
			emit sig_IconShow_B6(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B6(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B6 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B6 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[5]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[5]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[5]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[5]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B6 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B6 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B6 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B6 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B6 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B6 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B6 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B6 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B6 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B6 != nullptr)
		{
			state_B6 = QConfig::ToolBase[5]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B6 == true)
			{
				nViewMsgState_B6.clear();
				nViewMsgState_B6 = QConfig::ToolBase[5]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B6.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B6[n]);
				}
			}
			emit sig_ImageShow_B6(dataVar::img_view_B6, out_img);
		}
	}
	++dataVar::img_view_count_buf_B6;
	if (dataVar::img_view_count_buf_B6 == dataVar::img_view_count_B6)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B6 = 2;
		dataVar::img_view_count_B6 = 0;
		dataVar::img_view_count_buf_B6 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B6 = true;
		}
	}
}

//流程7刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B7(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B7) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B7(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B7 == 1)
		{
			emit sig_IconShow_B7(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B7(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B7 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B7 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[6]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[6]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[6]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[6]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B7 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B7 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B7 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B7 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B7 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B7 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B7 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B7 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B7 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B7 != nullptr)
		{
			state_B7 = QConfig::ToolBase[6]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B7 == true)
			{
				nViewMsgState_B7.clear();
				nViewMsgState_B7 = QConfig::ToolBase[6]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B7.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B7[n]);
				}
			}
			emit sig_ImageShow_B7(dataVar::img_view_B7, out_img);
		}
	}
	++dataVar::img_view_count_buf_B7;
	if (dataVar::img_view_count_buf_B7 == dataVar::img_view_count_B7)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B7 = 2;
		dataVar::img_view_count_B7 = 0;
		dataVar::img_view_count_buf_B7 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B7 = true;
		}
	}
}

//流程8刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B8(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B8) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B8(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B8 == 1)
		{
			emit sig_IconShow_B8(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B8(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B8 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B8 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[7]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[7]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[7]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[7]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B8 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B8 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B8 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B8 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B8 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B8 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B8 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B8 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B8 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B8 != nullptr)
		{
			state_B8 = QConfig::ToolBase[7]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B8 == true)
			{
				nViewMsgState_B8.clear();
				nViewMsgState_B8 = QConfig::ToolBase[7]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B8.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B8[n]);
				}
			}
			emit sig_ImageShow_B8(dataVar::img_view_B8, out_img);
		}
	}
	++dataVar::img_view_count_buf_B8;
	if (dataVar::img_view_count_buf_B8 == dataVar::img_view_count_B8)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B8 = 2;
		dataVar::img_view_count_B8 = 0;
		dataVar::img_view_count_buf_B8 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B8 = true;
		}
	}
}

//流程9刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B9(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B9) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B9(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B9 == 1)
		{
			emit sig_IconShow_B9(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B9(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B9 = toolName.mid(0, str_count);
	//流程运行更新图像
	if (str_name_B9 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[8]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[8]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[8]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[8]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B9 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B9 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B9 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B9 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B9 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B9 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B9 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B9 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B9 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B9 != nullptr)
		{
			state_B9 = QConfig::ToolBase[8]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B9 == true)
			{
				nViewMsgState_B9.clear();
				nViewMsgState_B9 = QConfig::ToolBase[8]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B9.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B9[n]);
				}
			}
			emit sig_ImageShow_B9(dataVar::img_view_B9, out_img);
		}
	}
	++dataVar::img_view_count_buf_B9;
	if (dataVar::img_view_count_buf_B9 == dataVar::img_view_count_B9)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B9 = 2;
		dataVar::img_view_count_B9 = 0;
		dataVar::img_view_count_buf_B9 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B9 = true;
		}
	}
}

//流程10刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B10(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B10) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B10(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B10 == 1)
		{
			emit sig_IconShow_B10(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B10(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B10 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B10 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[9]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[9]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[9]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[9]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B10 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B10 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B10 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B10 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B10 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B10 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B10 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B10 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B10 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B10 != nullptr)
		{
			state_B10 = QConfig::ToolBase[9]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B10 == true)
			{
				nViewMsgState_B10.clear();
				nViewMsgState_B10 = QConfig::ToolBase[9]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B10.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B10[n]);
				}
			}
			emit sig_ImageShow_B10(dataVar::img_view_B10, out_img);
		}
	}
	++dataVar::img_view_count_buf_B10;
	if (dataVar::img_view_count_buf_B10 == dataVar::img_view_count_B10)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B10 = 2;
		dataVar::img_view_count_B10 = 0;
		dataVar::img_view_count_buf_B10 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B10 = true;
		}
	}
}

//流程11刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B11(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B11) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B11(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B11 == 1)
		{
			emit sig_IconShow_B11(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B11(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B11 = toolName.mid(0, str_count);
	//流程运行更新图像
	if (str_name_B11 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[10]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[10]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[10]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[10]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B11 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B11 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B11 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B11 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B11 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B11 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B11 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B11 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B11 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B11 != nullptr)
		{
			state_B11 = QConfig::ToolBase[10]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B11 == true)
			{
				nViewMsgState_B11.clear();
				nViewMsgState_B11 = QConfig::ToolBase[10]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B11.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B11[n]);
				}
			}
			emit sig_ImageShow_B11(dataVar::img_view_B11, out_img);
		}
	}
	++dataVar::img_view_count_buf_B11;
	if (dataVar::img_view_count_buf_B11 == dataVar::img_view_count_B11)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B11 = 2;
		dataVar::img_view_count_B11 = 0;
		dataVar::img_view_count_buf_B11 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B11 = true;
		}
	}
}

//流程12刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B12(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B12) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B12(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B12 == 1)
		{
			emit sig_IconShow_B12(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B12(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B12 = toolName.mid(0, str_count);
	//流程运行更新图像
	if (str_name_B12 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[11]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[11]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[11]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[11]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B12 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B12 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B12 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B12 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B12 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B12 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B12 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B12 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B12 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B12 != nullptr)
		{
			state_B12 = QConfig::ToolBase[11]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B12 == true)
			{
				nViewMsgState_B12.clear();
				nViewMsgState_B12 = QConfig::ToolBase[11]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B12.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B12[n]);
				}
			}
			emit sig_ImageShow_B12(dataVar::img_view_B12, out_img);
		}
	}
	++dataVar::img_view_count_buf_B12;
	if (dataVar::img_view_count_buf_B12 == dataVar::img_view_count_B12)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B12 = 2;
		dataVar::img_view_count_B12 = 0;
		dataVar::img_view_count_buf_B12 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B12 = true;
		}
	}
}

//流程13刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B13(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B13) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B13(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B13 == 1)
		{
			emit sig_IconShow_B13(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B13(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B13 = toolName.mid(0, str_count);
	//流程运行更新图像
	if (str_name_B13 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[12]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[12]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[12]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[12]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B13 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B13 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B13 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B13 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B13 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B13 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B13 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B13 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B13 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B13 != nullptr)
		{
			state_B13 = QConfig::ToolBase[12]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B13 == true)
			{
				nViewMsgState_B13.clear();
				nViewMsgState_B13 = QConfig::ToolBase[12]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B13.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B13[n]);
				}
			}
			emit sig_ImageShow_B13(dataVar::img_view_B13, out_img);
		}
	}
	++dataVar::img_view_count_buf_B13;
	if (dataVar::img_view_count_buf_B13 == dataVar::img_view_count_B13)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B13 = 2;
		dataVar::img_view_count_B13 = 0;
		dataVar::img_view_count_buf_B13 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B13 = true;
		}
	}
}

//流程14刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B14(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B14) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B14(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B14 == 1)
		{
			emit sig_IconShow_B14(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B14(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B14 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B14 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[13]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[13]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[13]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[13]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B14 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B14 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B14 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B14 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B14 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B14 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B14 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B14 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B14 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B14 != nullptr)
		{
			state_B14 = QConfig::ToolBase[13]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B14 == true)
			{
				nViewMsgState_B14.clear();
				nViewMsgState_B14 = QConfig::ToolBase[13]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B14.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B14[n]);
				}
			}
			emit sig_ImageShow_B14(dataVar::img_view_B14, out_img);
		}
	}
	++dataVar::img_view_count_buf_B14;
	if (dataVar::img_view_count_buf_B14 == dataVar::img_view_count_B14)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B14 = 2;
		dataVar::img_view_count_B14 = 0;
		dataVar::img_view_count_buf_B14 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B14 = true;
		}
	}
}

//流程15刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B15(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B15) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B15(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B15 == 1)
		{
			emit sig_IconShow_B15(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B15(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B15 = toolName.mid(0, str_count);
	//流程运行更新图像
	if (str_name_B15 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[14]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[14]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[14]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[14]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B15 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B15 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B15 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B15 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B15 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B15 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B15 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B15 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B15 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B15 != nullptr)
		{
			state_B15 = QConfig::ToolBase[14]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B15 == true)
			{
				nViewMsgState_B15.clear();
				nViewMsgState_B15 = QConfig::ToolBase[14]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B15.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B15[n]);
				}
			}
			emit sig_ImageShow_B15(dataVar::img_view_B15, out_img);
		}
	}
	++dataVar::img_view_count_buf_B15;
	if (dataVar::img_view_count_buf_B15 == dataVar::img_view_count_B15)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B15 = 2;
		dataVar::img_view_count_B15 = 0;
		dataVar::img_view_count_buf_B15 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B15 = true;
		}
	}
}

//流程16刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B16(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B16) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B16(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B16 == 1)
		{
			emit sig_IconShow_B16(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B16(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B16 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B16 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[15]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[15]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[15]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[15]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B16 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B16 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B16 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B16 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B16 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B16 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B16 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B16 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B16 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B16 != nullptr)
		{
			state_B16 = QConfig::ToolBase[15]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B16 == true)
			{
				nViewMsgState_B16.clear();
				nViewMsgState_B16 = QConfig::ToolBase[15]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B16.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B16[n]);
				}
			}
			emit sig_ImageShow_B16(dataVar::img_view_B16, out_img);
		}
	}
	++dataVar::img_view_count_buf_B16;
	if (dataVar::img_view_count_buf_B16 == dataVar::img_view_count_B16)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B16 = 2;
		dataVar::img_view_count_B16 = 0;
		dataVar::img_view_count_buf_B16 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B16 = true;
		}
	}
}

//流程17刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B17(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B17) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B17(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B17 == 1)
		{
			emit sig_IconShow_B17(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B17(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B17 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B17 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[16]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[16]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[16]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[16]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B17 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B17 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B17 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B17 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B17 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B17 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B17 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B17 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B17 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B17 != nullptr)
		{
			state_B17 = QConfig::ToolBase[16]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B17 == true)
			{
				nViewMsgState_B17.clear();
				nViewMsgState_B17 = QConfig::ToolBase[16]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B17.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B17[n]);
				}
			}
			emit sig_ImageShow_B17(dataVar::img_view_B17, out_img);
		}
	}
	++dataVar::img_view_count_buf_B17;
	if (dataVar::img_view_count_buf_B17 == dataVar::img_view_count_B17)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B17 = 2;
		dataVar::img_view_count_B17 = 0;
		dataVar::img_view_count_buf_B17 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B17 = true;
		}
	}
}

//流程18刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B18(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B18) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B18(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B18 == 1)
		{
			emit sig_IconShow_B18(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B18(toolName, strTime);
	//提取不含数字字符串
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B18 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B18 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[17]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[17]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[17]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[17]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B18 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B18 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B18 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B18 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B18 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B18 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B18 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B18 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B18 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B18 != nullptr)
		{
			state_B18 = QConfig::ToolBase[17]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B18 == true)
			{
				nViewMsgState_B18.clear();
				nViewMsgState_B18 = QConfig::ToolBase[17]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B18.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B18[n]);
				}
			}
			emit sig_ImageShow_B18(dataVar::img_view_B18, out_img);
		}
	}
	++dataVar::img_view_count_buf_B18;
	if (dataVar::img_view_count_buf_B18 == dataVar::img_view_count_B18)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B18 = 2;
		dataVar::img_view_count_B18 = 0;
		dataVar::img_view_count_buf_B18 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B18 = true;
		}
	}
}

//流程19刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B19(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B19) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B19(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B19 == 1)
		{
			emit sig_IconShow_B19(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B19(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B19 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B19 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[18]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[18]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[18]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[18]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B19 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B19 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B19 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B19 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B19 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B19 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B19 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B19 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B19 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B19 != nullptr)
		{
			state_B19 = QConfig::ToolBase[18]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B19 == true)
			{
				nViewMsgState_B19.clear();
				nViewMsgState_B19 = QConfig::ToolBase[18]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B19.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B19[n]);
				}
			}
			emit sig_ImageShow_B19(dataVar::img_view_B19, out_img);
		}
	}
	++dataVar::img_view_count_buf_B19;
	if (dataVar::img_view_count_buf_B19 == dataVar::img_view_count_B19)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B19 = 2;
		dataVar::img_view_count_B19 = 0;
		dataVar::img_view_count_buf_B19 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B19 = true;
		}
	}
}

//流程20刷新工具处理结果
void frmProItemTab::slot_ToolRunFinish_B20(const QString toolName)
{
	QString strTime = QString::number(dataVar::nCostTime_B20) + "ms";
	if (dataVar::m_a_state == 1)
	{
		if (dataVar::manualRunOnce_A == 1)
		{
			//工具执行正常图标
			emit sig_IconShow_B20(toolName, QPixmap(":/res/ico/ok_manual.png"));
		}
	}
	else if (dataVar::m_a_state == 2)
	{
		//工具执行正常图标
		if (dataVar::autoRunOnce_B20 == 1)
		{
			emit sig_IconShow_B20(toolName, QPixmap(":/res/ico/ok_auto.png"));
			emit sig_InfoClick();
		}
	}
	//显示流程运行时间
	emit sig_TextShow_B20(toolName, strTime);
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < toolName.length(); k++)
	{
		if (!(toolName[k] > '0' && toolName[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_B20 = toolName.mid(0, str_count);
	//流程运行更新图像	
	if (str_name_B20 == "图像显示")
	{
		int index = 0;
		for (int i = 0; i < QConfig::ToolBase[19]->m_Tools.size(); i++)
		{
			if (QConfig::ToolBase[19]->m_Tools[i].PublicToolName == toolName)
			{
				//工具在工具数组中的索引
				index = i;
			}
		}
		QImage out_img = QConfig::ToolBase[19]->m_Tools[index].PublicImage.OutputViewImage;
		int screen = QConfig::ToolBase[19]->m_Tools[index].PublicScreen.ScreenNumber;
		switch (screen) {
		case 1:
			dataVar::img_view_B20 = dataVar::img_view1;
			break;
		case 2:
			dataVar::img_view_B20 = dataVar::img_view2;
			break;
		case 3:
			dataVar::img_view_B20 = dataVar::img_view3;
			break;
		case 4:
			dataVar::img_view_B20 = dataVar::img_view4;
			break;
		case 5:
			dataVar::img_view_B20 = dataVar::img_view5;
			break;
		case 6:
			dataVar::img_view_B20 = dataVar::img_view6;
			break;
		case 7:
			dataVar::img_view_B20 = dataVar::img_view7;
			break;
		case 8:
			dataVar::img_view_B20 = dataVar::img_view8;
			break;
		case 9:
			dataVar::img_view_B20 = dataVar::img_view9;
			break;
		}
		if (dataVar::img_view_B20 != nullptr)
		{
			state_B20 = QConfig::ToolBase[19]->m_Tools[index].PublicImageProcess.ViewMsgState;
			if (state_B20 == true)
			{
				nViewMsgState_B20.clear();
				nViewMsgState_B20 = QConfig::ToolBase[19]->m_Tools[index].PublicImageProcess.GetViewMsg;
				for (int n = 0; n < nViewMsgState_B20.count(); n++)
				{
					dataVar::fLog->slot_Message_Info(nViewMsgState_B20[n]);
				}
			}
			emit sig_ImageShow_B20(dataVar::img_view_B20, out_img);
		}
	}
	++dataVar::img_view_count_buf_B20;
	if (dataVar::img_view_count_buf_B20 == dataVar::img_view_count_B20)
	{
		dataVar::manualRunOnce_A = 2;
		dataVar::autoRunOnce_B20 = 2;
		dataVar::img_view_count_B20 = 0;
		dataVar::img_view_count_buf_B20 = 0;
		if (dataVar::m_a_state == 1)
		{
			dataVar::runFinish_A = true;
		}
		else if (dataVar::m_a_state == 2)
		{
			dataVar::runFinish_B20 = true;
		}
	}
}
#pragma endregion
