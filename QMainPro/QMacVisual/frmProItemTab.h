#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmProItemTab.h"
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include "GlobalVariable.h"
#include "FlowListWidget.h"
#include "QGraphicsViews.h"
#include <QThread>

#pragma region 图像处理
//动态库--获取图像
typedef int (*GetImageSource)();
typedef void (*SetImageSource)();
//动态库--创建ROI
typedef int (*GetCreateRoi)();
typedef void (*SetCreateRoi)();
//动态库--裁切图像
typedef int (*GetCropImage)();
typedef void (*SetCropImage)();
//动态库--图像翻转
typedef int (*GetImageFlip)();
typedef void (*SetImageFlip)();
//动态库--预处理
typedef int (*GetImageMorphology)();
typedef void (*SetImageMorphology)();
//动态库--图像修复
typedef int (*GetImageRepair)();
typedef void (*SetImageRepair)();
//动态库--图像旋转
typedef int (*GetImageRotate)();
typedef void (*SetImageRotate)();
//动态库--图像拼接
typedef int (*GetImageSplice)();
typedef void (*SetImageSplice)();
//动态库--图像显示
typedef int (*GetImageView)();
typedef void (*SetImageView)();
//动态库--透视变换
typedef int (*GetPerspectiveTransform)();
typedef void (*SetPerspectiveTransform)();
//动态库--图像细化
typedef int (*GetSkeleton)();
typedef void (*SetSkeleton)();
//动态库--导出图像
typedef int (*GetExportImage)();
typedef void (*SetExportImage)();
//动态库--自动打印
typedef int (*GetImagePrint)();
typedef void (*SetImagePrint)();
#pragma endregion

#pragma region 检测识别
//动态库--条形码识别
typedef int (*GetBarcodeIdentify)();
typedef void (*SetBarcodeIdentify)();
//动态库--斑点分析
typedef int (*GetBlobDetector)();
typedef void (*SetBlobDetector)();
//动态库--亮度检测
typedef int (*GetBrightness)();
typedef void (*SetBrightness)();
//动态库--颜色识别
typedef int (*GetColorIdentify)();
typedef void (*SetColorIdentify)();
//动态库--二维码识别
typedef int (*GetQRcodeIdentify)();
typedef void (*SetQRcodeIdentify)();
//动态库--二维码生成
typedef int (*GetQRcodeGenerate)();
typedef void (*SetQRcodeGenerate)();
//动态库--轮廓特征选择
typedef int (*GetSelectShape)();
typedef void (*SetSelectShape)();
//动态库--分类器
typedef int (*GetClassifier)();
typedef void (*SetClassifier)();
#pragma endregion

#pragma region 标定工具
//动态库--N点标定
typedef int (*GetERTCalibration)();
typedef void (*SetERTCalibration)();
//动态库--测量标定
typedef int (*GetMeasureCalibration)();
typedef void (*SetMeasureCalibration)();
#pragma endregion

#pragma region 对位工具
//动态库--目标跟踪
typedef int (*GetCamShiftTrack)();
typedef void (*SetCamShiftTrack)();
//动态库--线性计算
typedef int (*GetLinearCalculation)();
typedef void (*SetLinearCalculation)();
//动态库--灰度匹配
typedef int (*GetTemplateMatch)();
typedef void (*SetTemplateMatch)();
//动态库--形状匹配
typedef int (*GetShapeMatch)();
typedef void (*SetShapeMatch)();
#pragma endregion

#pragma region 几何工具
//动态库--寻找圆
typedef int (*GetFindCircle)();
typedef void (*SetFindCircle)();
//动态库--寻找直线
typedef int (*GetFindLine)();
typedef void (*SetFindLine)();
//动态库--拟合圆
typedef int (*GetFitCircle)();
typedef void (*SetFitCircle)();
//动态库--拟合椭圆
typedef int (*GetFitEllipse)();
typedef void (*SetFitEllipse)();
//动态库--拟合直线
typedef int (*GetFitLine)();
typedef void (*SetFitLine)();
//动态库--获取边界点
typedef int (*GetContourPoints)();
typedef void (*SetContourPoints)();
#pragma endregion

#pragma region 几何测量
//动态库--线圆交点
typedef int (*GetLineCircle)();
typedef void (*SetLineCircle)();
//动态库--线线交点
typedef int (*GetLineLineI)();
typedef void (*SetLineLineI)();
//动态库--点+线
typedef int (*GetPointLine)();
typedef void (*SetPointLine)();
//动态库--点+点
typedef int (*GetPointPoint)();
typedef void (*SetPointPoint)();
//动态库--圆缺口角度
typedef int (*GetRoundedCorners)();
typedef void (*SetRoundedCorners)();
//动态库--边缘宽度测量
typedef int (*GetEdgeWidthMeasure)();
typedef void (*SetEdgeWidthMeasure)();
#pragma endregion

#pragma region 三维检测
//动态库--拟合平面
typedef int (*GetFlatness)();
typedef void (*SetFlatness)();
#pragma endregion

#pragma region 逻辑工具
//动态库--扩展库
typedef int (*GetExtensionLibrary)();
typedef void (*SetExtensionLibrary)();
//动态库--跳转语句
typedef int (*GetLogicGoto)();
typedef void (*SetLogicGoto)();
//动态库--判断语句
typedef int (*GetLogicJudge)();
typedef void (*SetLogicJudge)();
//动态库--结束语句
typedef int (*GetLogicJudgeEnd)();
typedef void (*SetLogicJudgeEnd)();
#pragma endregion

#pragma region 通讯工具
//动态库--PLC通信
typedef int (*GetPlcCommunicate)();
typedef void (*SetPlcCommunicate)();
//动态库--串口通信
typedef int (*GetSerialPort)();
typedef void (*SetSerialPort)();
//动态库--TCP/IP服务器
typedef int (*GetSocketTcpServer)();
typedef void (*SetSocketTcpServer)();
//动态库--TCP/IP客户端
typedef int (*GetSocketTcpClient)();
typedef void (*SetSocketTcpClient)();
#pragma endregion

#pragma region 系统工具
//动态库--导出CSV
typedef int (*GetExportCsv)();
typedef void (*SetExportCsv)();
#pragma endregion


#pragma region 目标检测
//动态库--Yolov13
typedef int (*GetYoloV13)();
typedef void (*SetYoloV13)();
#pragma endregion

#pragma region OCR
//动态库--OCR
typedef int (*GetOCR)();
typedef void (*SetOCR)();
#pragma endregion
class frmProItemTab : public QWidget
{
	Q_OBJECT

public:
	frmProItemTab(QWidget* parent = Q_NULLPTR);
	~frmProItemTab();

private:
	Ui::frmProItemTabClass ui;

public:
	ToolNameList GetProcessItemNum(const QString itemName);
	Toolnterface* GetNewToolDlg(const int mode, const QString sToolName, const ToolNameList toolName);

private:
	void ProgramManualFlow();

public slots:
	void slot_CyclePro();
	void ProgramAutoFlow_B1();
	void ProgramAutoFlow_B2();
	void ProgramAutoFlow_B3();
	void ProgramAutoFlow_B4();
	void ProgramAutoFlow_B5();
	void ProgramAutoFlow_B6();
	void ProgramAutoFlow_B7();
	void ProgramAutoFlow_B8();
	void ProgramAutoFlow_B9();
	void ProgramAutoFlow_B10();
	void ProgramAutoFlow_B11();
	void ProgramAutoFlow_B12();
	void ProgramAutoFlow_B13();
	void ProgramAutoFlow_B14();
	void ProgramAutoFlow_B15();
	void ProgramAutoFlow_B16();
	void ProgramAutoFlow_B17();
	void ProgramAutoFlow_B18();
	void ProgramAutoFlow_B19();
	void ProgramAutoFlow_B20();

private slots:
	void on_btnAddProFlow_clicked();
	void on_btnDelProFlow_clicked();
	void on_btnSetProFlow_clicked();
	void on_btnRunOnce_clicked();
	void on_btnRunCycle_clicked();
	void on_btnStop_clicked();

private slots:
	void slotItemExpanded(QTreeWidgetItem* item);
	void slotItemCollapsed(QTreeWidgetItem* item);
	void slotItemPressed(QTreeWidgetItem* item, int column);

private slots:
	void slot_ActionProItem(int nType, QString addName, bool isAdd);
	void slot_CycleProErr();
	void timerEvent();
	void slot_Cutover();
	void slot_ManualCycleStop();

public slots:
	void slot_ToolRunFinish_B1(const QString);
	void slot_ToolRunFinish_B2(const QString);
	void slot_ToolRunFinish_B3(const QString);
	void slot_ToolRunFinish_B4(const QString);
	void slot_ToolRunFinish_B5(const QString);
	void slot_ToolRunFinish_B6(const QString);
	void slot_ToolRunFinish_B7(const QString);
	void slot_ToolRunFinish_B8(const QString);
	void slot_ToolRunFinish_B9(const QString);
	void slot_ToolRunFinish_B10(const QString);
	void slot_ToolRunFinish_B11(const QString);
	void slot_ToolRunFinish_B12(const QString);
	void slot_ToolRunFinish_B13(const QString);
	void slot_ToolRunFinish_B14(const QString);
	void slot_ToolRunFinish_B15(const QString);
	void slot_ToolRunFinish_B16(const QString);
	void slot_ToolRunFinish_B17(const QString);
	void slot_ToolRunFinish_B18(const QString);
	void slot_ToolRunFinish_B19(const QString);
	void slot_ToolRunFinish_B20(const QString);
	void slot_ToolWrong_B1(const QString);
	void slot_ToolWrong_B2(const QString);
	void slot_ToolWrong_B3(const QString);
	void slot_ToolWrong_B4(const QString);
	void slot_ToolWrong_B5(const QString);
	void slot_ToolWrong_B6(const QString);
	void slot_ToolWrong_B7(const QString);
	void slot_ToolWrong_B8(const QString);
	void slot_ToolWrong_B9(const QString);
	void slot_ToolWrong_B10(const QString);
	void slot_ToolWrong_B11(const QString);
	void slot_ToolWrong_B12(const QString);
	void slot_ToolWrong_B13(const QString);
	void slot_ToolWrong_B14(const QString);
	void slot_ToolWrong_B15(const QString);
	void slot_ToolWrong_B16(const QString);
	void slot_ToolWrong_B17(const QString);
	void slot_ToolWrong_B18(const QString);
	void slot_ToolWrong_B19(const QString);
	void slot_ToolWrong_B20(const QString);
	void slot_Login();
	void slot_Logout();
	void slot_ManualRun();
	void slot_ManualStop();
	void slot_AllCycleRunOnce();
	void slot_AllCycleRunContinue();
	void slot_AllCycleStop();
	void slot_UpdateQTreeWidget(const QString, const QString);

signals:
	void sig_TextShow_B1(const QString toolName, const QString nCostTime);
	void sig_TextShow_B2(const QString toolName, const QString nCostTime);
	void sig_TextShow_B3(const QString toolName, const QString nCostTime);
	void sig_TextShow_B4(const QString toolName, const QString nCostTime);
	void sig_TextShow_B5(const QString toolName, const QString nCostTime);
	void sig_TextShow_B6(const QString toolName, const QString nCostTime);
	void sig_TextShow_B7(const QString toolName, const QString nCostTime);
	void sig_TextShow_B8(const QString toolName, const QString nCostTime);
	void sig_TextShow_B9(const QString toolName, const QString nCostTime);
	void sig_TextShow_B10(const QString toolName, const QString nCostTime);
	void sig_TextShow_B11(const QString toolName, const QString nCostTime);
	void sig_TextShow_B12(const QString toolName, const QString nCostTime);
	void sig_TextShow_B13(const QString toolName, const QString nCostTime);
	void sig_TextShow_B14(const QString toolName, const QString nCostTime);
	void sig_TextShow_B15(const QString toolName, const QString nCostTime);
	void sig_TextShow_B16(const QString toolName, const QString nCostTime);
	void sig_TextShow_B17(const QString toolName, const QString nCostTime);
	void sig_TextShow_B18(const QString toolName, const QString nCostTime);
	void sig_TextShow_B19(const QString toolName, const QString nCostTime);
	void sig_TextShow_B20(const QString toolName, const QString nCostTime);
	void sig_IconShow_B1(const QString toolName, const QPixmap pix);
	void sig_IconShow_B2(const QString toolName, const QPixmap pix);
	void sig_IconShow_B3(const QString toolName, const QPixmap pix);
	void sig_IconShow_B4(const QString toolName, const QPixmap pix);
	void sig_IconShow_B5(const QString toolName, const QPixmap pix);
	void sig_IconShow_B6(const QString toolName, const QPixmap pix);
	void sig_IconShow_B7(const QString toolName, const QPixmap pix);
	void sig_IconShow_B8(const QString toolName, const QPixmap pix);
	void sig_IconShow_B9(const QString toolName, const QPixmap pix);
	void sig_IconShow_B10(const QString toolName, const QPixmap pix);
	void sig_IconShow_B11(const QString toolName, const QPixmap pix);
	void sig_IconShow_B12(const QString toolName, const QPixmap pix);
	void sig_IconShow_B13(const QString toolName, const QPixmap pix);
	void sig_IconShow_B14(const QString toolName, const QPixmap pix);
	void sig_IconShow_B15(const QString toolName, const QPixmap pix);
	void sig_IconShow_B16(const QString toolName, const QPixmap pix);
	void sig_IconShow_B17(const QString toolName, const QPixmap pix);
	void sig_IconShow_B18(const QString toolName, const QPixmap pix);
	void sig_IconShow_B19(const QString toolName, const QPixmap pix);
	void sig_IconShow_B20(const QString toolName, const QPixmap pix);

signals:
	void sig_ImageShow_B1(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B2(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B3(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B4(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B5(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B6(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B7(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B8(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B9(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B10(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B11(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B12(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B13(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B14(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B15(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B16(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B17(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B18(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B19(QGraphicsViews* img_view, const QImage image);
	void sig_ImageShow_B20(QGraphicsViews* img_view, const QImage image);
	void sig_CyclePro();
	void sig_CyclePro_B1();
	void sig_CyclePro_B2();
	void sig_CyclePro_B3();
	void sig_CyclePro_B4();
	void sig_CyclePro_B5();
	void sig_CyclePro_B6();
	void sig_CyclePro_B7();
	void sig_CyclePro_B8();
	void sig_CyclePro_B9();
	void sig_CyclePro_B10();
	void sig_CyclePro_B11();
	void sig_CyclePro_B12();
	void sig_CyclePro_B13();
	void sig_CyclePro_B14();
	void sig_CyclePro_B15();
	void sig_CyclePro_B16();
	void sig_CyclePro_B17();
	void sig_CyclePro_B18();
	void sig_CyclePro_B19();
	void sig_CyclePro_B20();
	void sig_CycleProErr();
	void sig_CycleRun();
	void sig_ManualCycleStop();
	void sig_AllCycleStop();
	void sig_CycleStop();
	void sig_CreateList();

signals:
	void sig_Log(QString strMsg);	
	void sig_InfoClick();
	void sig_WarnClick();
	void sig_ErrorClick();

private:	
	//流程列表初始化
	void ProcessTreeInit();
	QList<QString> treeList;
	int press_index;
	int cutover_index;
	QString flowPageName_buf;	
	QString getRandomString();
	QVector<QString> fNameList;

public:
	QTreeWidgetItem* itemParent;
	QMap<QString, QToolBase*> FlowTabMap;
	QVector<QTreeWidgetItem*> treeItem = QVector<QTreeWidgetItem*>(20);
	QMap<QTreeWidgetItem*, int> m_pro_value;  //记录流程对应的索引值	
	void DeserializeInitProcess();  //反序列化初始化流程	
	QtDragListWidget* TempDragListWidget = nullptr;
	QtDragListWidget* TempDragListWidget_B1 = nullptr, * TempDragListWidget_B2 = nullptr, * TempDragListWidget_B3 = nullptr, * TempDragListWidget_B4 = nullptr, * TempDragListWidget_B5 = nullptr, * TempDragListWidget_B6 = nullptr, * TempDragListWidget_B7 = nullptr, * TempDragListWidget_B8 = nullptr, * TempDragListWidget_B9 = nullptr, * TempDragListWidget_B10 = nullptr;
	QtDragListWidget* TempDragListWidget_B11 = nullptr, * TempDragListWidget_B12 = nullptr, * TempDragListWidget_B13 = nullptr, * TempDragListWidget_B14 = nullptr, * TempDragListWidget_B15 = nullptr, * TempDragListWidget_B16 = nullptr, * TempDragListWidget_B17 = nullptr, * TempDragListWidget_B18 = nullptr, * TempDragListWidget_B19 = nullptr, * TempDragListWidget_B20 = nullptr;
	
private:
	//多线程	
	QThread* Thread_A;
	QThread* Thread_B1, * Thread_B2, * Thread_B3, * Thread_B4, * Thread_B5, * Thread_B6, * Thread_B7, * Thread_B8, * Thread_B9, * Thread_B10;
	QThread* Thread_B11, * Thread_B12, * Thread_B13, * Thread_B14, * Thread_B15, * Thread_B16, * Thread_B17, * Thread_B18, * Thread_B19, * Thread_B20;
	void Begin_Thread_A();
	void Begin_Thread_B1(), Begin_Thread_B2(), Begin_Thread_B3(), Begin_Thread_B4(), Begin_Thread_B5(), Begin_Thread_B6(), Begin_Thread_B7(), Begin_Thread_B8(), Begin_Thread_B9(), Begin_Thread_B10();
	void Begin_Thread_B11(), Begin_Thread_B12(), Begin_Thread_B13(), Begin_Thread_B14(), Begin_Thread_B15(), Begin_Thread_B16(), Begin_Thread_B17(), Begin_Thread_B18(), Begin_Thread_B19(), Begin_Thread_B20();
	bool stop_goto_A, stop_goto_B1, stop_goto_B2, stop_goto_B3, stop_goto_B4, stop_goto_B5, stop_goto_B6, stop_goto_B7, stop_goto_B8, stop_goto_B9, stop_goto_B10;
	bool stop_goto_B11, stop_goto_B12, stop_goto_B13, stop_goto_B14, stop_goto_B15, stop_goto_B16, stop_goto_B17, stop_goto_B18, stop_goto_B19, stop_goto_B20;
	bool stop_goto_manual_A, stop_goto_manual_B;
	QMap<QString, QtDragListWidget*> GetItemState_A;
	QMap<QString, QtDragListWidget*> GetItemState_B1, GetItemState_B2, GetItemState_B3, GetItemState_B4, GetItemState_B5, GetItemState_B6, GetItemState_B7, GetItemState_B8, GetItemState_B9, GetItemState_B10;
	QMap<QString, QtDragListWidget*> GetItemState_B11, GetItemState_B12, GetItemState_B13, GetItemState_B14, GetItemState_B15, GetItemState_B16, GetItemState_B17, GetItemState_B18, GetItemState_B19, GetItemState_B20;
	QVector<QString>  FlowProItemListState_B1 = QVector<QString>(100), FlowProItemListState_B2 = QVector<QString>(100), FlowProItemListState_B3 = QVector<QString>(100), FlowProItemListState_B4 = QVector<QString>(100), FlowProItemListState_B5 = QVector<QString>(100), FlowProItemListState_B6 = QVector<QString>(100), FlowProItemListState_B7 = QVector<QString>(100), FlowProItemListState_B8 = QVector<QString>(100), FlowProItemListState_B9 = QVector<QString>(100), FlowProItemListState_B10 = QVector<QString>(100);
	QVector<QString>  FlowProItemListState_B11 = QVector<QString>(100), FlowProItemListState_B12 = QVector<QString>(100), FlowProItemListState_B13 = QVector<QString>(100), FlowProItemListState_B14 = QVector<QString>(100), FlowProItemListState_B15 = QVector<QString>(100), FlowProItemListState_B16 = QVector<QString>(100), FlowProItemListState_B17 = QVector<QString>(100), FlowProItemListState_B18 = QVector<QString>(100), FlowProItemListState_B19 = QVector<QString>(100), FlowProItemListState_B20 = QVector<QString>(100);
	QVector<QString> FlowProItemList_A = QVector<QString>(100);
	QVector<QString> FlowProItemListState_A = QVector<QString>(100);
	QList<QString> flowNames_A;
	QString flowPageName_A;
	void AutoRunOnce_B();
	void AutoRunStop_B();	
	QMap<QString, QtDragListWidget*> FlowProMapBuf;	
	QMap<QString, QToolBase*> FlowTabMapBuf;
	QList<int> m_process_buf;
	int manual_flow_index;
	QTimer* p_timer, * p_autotimer;
	bool run_state_A, run_state_B1, run_state_B2, run_state_B3, run_state_B4, run_state_B5, run_state_B6, run_state_B7, run_state_B8, run_state_B9, run_state_B10;
	bool run_state_B11, run_state_B12, run_state_B13, run_state_B14, run_state_B15, run_state_B16, run_state_B17, run_state_B18, run_state_B19, run_state_B20;	
	QString pro_name_B1, pro_name_B2, pro_name_B3, pro_name_B4, pro_name_B5, pro_name_B6, pro_name_B7, pro_name_B8, pro_name_B9, pro_name_B10;
	QString pro_name_B11, pro_name_B12, pro_name_B13, pro_name_B14, pro_name_B15, pro_name_B16, pro_name_B17, pro_name_B18, pro_name_B19, pro_name_B20;

public:
	void Stop_Thread_A(), Stop_Thread_B();
	void Stop_Thread_B1(), Stop_Thread_B2(), Stop_Thread_B3(), Stop_Thread_B4(), Stop_Thread_B5(), Stop_Thread_B6(), Stop_Thread_B7(), Stop_Thread_B8(), Stop_Thread_B9(), Stop_Thread_B10();
	void Stop_Thread_B11(), Stop_Thread_B12(), Stop_Thread_B13(), Stop_Thread_B14(), Stop_Thread_B15(), Stop_Thread_B16(), Stop_Thread_B17(), Stop_Thread_B18(), Stop_Thread_B19(), Stop_Thread_B20();

private:
#pragma region 图像处理
	//获取图像链接
	GetImageSource getImageSourceState;
	SetImageSource setImageSourceState;
	int nImageSourceState;
	int nImageSourceState_buf;
	//创建ROI链接
	GetCreateRoi getCreateRoiState;
	SetCreateRoi setCreateRoiState;
	int nCreateRoiState;
	int nCreateRoiState_buf;
	//裁切图像链接
	GetCropImage getCropImageState;
	SetCropImage setCropImageState;
	int nCropImageState;
	int nCropImageState_buf;
	//图像翻转链接
	GetImageFlip getImageFlipState;
	SetImageFlip setImageFlipState;
	int nImageFlipState;
	int nImageFlipState_buf;
	//预处理链接
	GetImageMorphology getImageMorphologyState;
	SetImageMorphology setImageMorphologyState;
	int nImageMorphologyState;
	int nImageMorphologyState_buf;
	//图像修复链接
	GetImageRepair getImageRepairState;
	SetImageRepair setImageRepairState;
	int nImageRepairState;
	int nImageRepairState_buf;
	//图像旋转链接
	GetImageRotate getImageRotateState;
	SetImageRotate setImageRotateState;
	int nImageRotateState;
	int nImageRotateState_buf;
	//图像拼接链接
	GetImageSplice getImageSpliceState;
	SetImageSplice setImageSpliceState;
	int nImageSpliceState;
	int nImageSpliceState_buf;
	//图像显示链接
	GetImageView getImageViewState;
	SetImageView setImageViewState;
	int nImageViewState;
	int nImageViewState_buf;	
	QVector<QString> nViewMsgState_B1 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B2 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B3 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B4 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B5 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B6 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B7 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B8 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B9 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B10 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B11 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B12 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B13 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B14 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B15 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B16 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B17 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B18 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B19 = QVector<QString>(100);
	QVector<QString> nViewMsgState_B20 = QVector<QString>(100);	
	bool state_B1 = false, state_B2 = false, state_B3 = false, state_B4 = false, state_B5 = false, state_B6 = false, state_B7 = false, state_B8 = false, state_B9 = false, state_B10 = false;
	bool state_B11 = false, state_B12 = false, state_B13 = false, state_B14 = false, state_B15 = false, state_B16 = false, state_B17 = false, state_B18 = false, state_B19 = false, state_B20 = false;
	//透视变换链接
	GetPerspectiveTransform getPerspectiveTransformState;
	SetPerspectiveTransform setPerspectiveTransformState;
	int nPerspectiveTransformState;
	int nPerspectiveTransformState_buf;
	//图像细化链接
	GetSkeleton getSkeletonState;
	SetSkeleton setSkeletonState;
	int nSkeletonState;
	int nSkeletonState_buf;
	//导出图像链接
	GetExportImage getExportImageState;
	SetExportImage setExportImageState;
	int nExportImageState;
	int nExportImageState_buf;
	//自动打印
	GetImagePrint getImagePrintState;
	SetImagePrint setImagePrintState;
	int nImagePrintState;
	int nImagePrintState_buf;
#pragma endregion

#pragma region 检测识别
	//条形码识别链接
	GetBarcodeIdentify getBarcodeIdentifyState;
	SetBarcodeIdentify setBarcodeIdentifyState;
	int nBarcodeIdentifyState;
	int nBarcodeIdentifyState_buf;
	//斑点分析链接
	GetBlobDetector getBlobDetectorState;
	SetBlobDetector setBlobDetectorState;
	int nBlobDetectorState;
	int nBlobDetectorState_buf;
	//亮度检测链接
	GetBrightness getBrightnessState;
	SetBrightness setBrightnessState;
	int nBrightnessState;
	int nBrightnessState_buf;
	//颜色识别链接
	GetColorIdentify getColorIdentifyState;
	SetColorIdentify setColorIdentifyState;
	int nColorIdentifyState;
	int nColorIdentifyState_buf;
	//二维码识别链接
	GetQRcodeIdentify getQRcodeIdentifyState;
	SetQRcodeIdentify setQRcodeIdentifyState;
	int nQRcodeIdentifyState;
	int nQRcodeIdentifyState_buf;
	//二维码生成链接
	GetQRcodeGenerate getQRcodeGenerateState;
	SetQRcodeGenerate setQRcodeGenerateState;
	int nQRcodeGenerateState;
	int nQRcodeGenerateState_buf;
	//轮廓特征选择链接
	GetSelectShape getSelectShape;
	SetSelectShape setSelectShape;
	int nSelectShapeState;
	int nSelectShapeState_buf;
	//分类器链接
	GetClassifier getClassifierState;
	SetClassifier setClassifierState;
	int nClassifierState;
	int nClassifierState_buf;
#pragma endregion

#pragma region 标定工具
	//N点标定链接
	GetERTCalibration getERTCalibrationState;
	SetERTCalibration setERTCalibrationState;
	int nERTCalibrationState;
	int nERTCalibrationState_buf;
	//测量标定链接
	GetMeasureCalibration getMeasureCalibrationState;
	SetMeasureCalibration setMeasureCalibrationState;
	int nMeasureCalibrationState;
	int nMeasureCalibrationState_buf;
#pragma endregion

#pragma region 对位工具
	//目标跟踪链接
	GetCamShiftTrack getCamShiftTrackState;
	SetCamShiftTrack setCamShiftTrackState;
	int nCamShiftTrackState;
	int nCamShiftTrackState_buf;
	//线性计算链接
	GetLinearCalculation getLinearCalculationState;
	SetLinearCalculation setLinearCalculationState;
	int nLinearCalculationState;
	int nLinearCalculationState_buf;
	//灰度匹配链接
	GetTemplateMatch getTemplateMatchState;
	SetTemplateMatch setTemplateMatchState;
	int nTemplateMatchState;
	int nTemplateMatchState_buf;
	//形状匹配链接
	GetShapeMatch getShapeMatchState;
	SetShapeMatch setShapeMatchState;
	int nShapeMatchState;
	int nShapeMatchState_buf;
#pragma endregion

#pragma region 几何工具
	//寻找圆链接
	GetFindCircle getFindCircleState;
	SetFindCircle setFindCircleState;
	int nFindCircleState;
	int nFindCircleState_buf;
	//寻找直线链接
	GetFindLine getFindLineState;
	SetFindLine setFindLineState;
	int nFindLineState;
	int nFindLineState_buf;
	//拟合圆链接
	GetFitCircle getFitCircleState;
	SetFitCircle setFitCircleState;
	int nFitCircleState;
	int nFitCircleState_buf;
	//拟合椭圆链接
	GetFitEllipse getFitEllipseState;
	SetFitEllipse setFitEllipseState;
	int nFitEllipseState;
	int nFitEllipseState_buf;
	//拟合直线链接
	GetFitLine getFitLineState;
	SetFitLine setFitLineState;
	int nFitLineState;
	int nFitLineState_buf;
	//获取边界点链接
	GetContourPoints getContourPointsState;
	SetContourPoints setContourPointsState;
	int nContourPointsState;
	int nContourPointsState_buf;
#pragma endregion

#pragma region 几何测量
	//线圆交点链接
	GetLineCircle getLineCircleState;
	SetLineCircle setLineCircleState;
	int nLineCircleState;
	int nLineCircleState_buf;
	//线线交点链接
	GetLineLineI getLineLineIState;
	SetLineLineI setLineLineIState;
	int nLineLineIState;
	int nLineLineIState_buf;
	//点+线链接
	GetPointLine getPointLineState;
	SetPointLine setPointLineState;
	int nPointLineState;
	int nPointLineState_buf;
	//点+点链接
	GetPointPoint getPointPointState;
	SetPointPoint setPointPointState;
	int nPointPointState;
	int nPointPointState_buf;
	//圆缺口角度链接
	GetRoundedCorners getRoundedCornersState;
	SetRoundedCorners setRoundedCornersState;
	int nRoundedCornersState;
	int nRoundedCornersState_buf;
	//边缘宽度测量链接
	GetEdgeWidthMeasure getEdgeWidthMeasureState;
	SetEdgeWidthMeasure setEdgeWidthMeasureState;
	int nEdgeWidthMeasureState;
	int nEdgeWidthMeasureState_buf;
#pragma endregion	

#pragma region 三维检测
	//拟合平面链接
	GetFlatness getFlatnessState;
	SetFlatness setFlatnessState;
	int nFlatnessState;
	int nFlatnessState_buf;
#pragma endregion

#pragma region 逻辑工具
	//扩展库链接
	GetExtensionLibrary getExtensionLibraryState;
	SetExtensionLibrary setExtensionLibraryState;
	int nExtensionLibraryState;
	int nExtensionLibraryState_buf;
	//跳转语句链接
	GetLogicGoto getLogicGotoState;
	SetLogicGoto setLogicGotoState;
	int nLogicGotoState;
	int nLogicGotoState_buf;
	//判断语句链接
	GetLogicJudge getLogicJudgeState;
	SetLogicJudge setLogicJudgeState;
	int nLogicJudgeState;
	int nLogicJudgeState_buf;
	//结束语句链接
	GetLogicJudgeEnd getLogicJudgeEndState;
	SetLogicJudgeEnd setLogicJudgeEndState;
	int nLogicJudgeEndState;
	int nLogicJudgeEndState_buf;
#pragma endregion

#pragma region 通讯工具
	//PLC通信
	GetPlcCommunicate getPlcCommunicate;
	SetPlcCommunicate setPlcCommunicate;
	int nPlcCommunicateState;
	int nPlcCommunicateState_buf;
	//串口通信
	GetSerialPort getSerialPort;
	SetSerialPort setSerialPort;
	int nSerialPortState;
	int nSerialPortState_buf;
	//TCP/IP服务器
	GetSocketTcpServer getSocketTcpServer;
	SetSocketTcpServer setSocketTcpServer;
	int nSocketTcpServerState;
	int nSocketTcpServerState_buf;
	//TCP/IP客户端
	GetSocketTcpClient getSocketTcpClient;
	SetSocketTcpClient setSocketTcpClient;
	int nSocketTcpClientState;
	int nSocketTcpClientState_buf;
#pragma endregion

#pragma region 系统工具
	//导出CSV链接
	GetExportCsv getExportCsv;
	SetExportCsv setExportCsv;
	int nExportCsvState;
	int nExportCsvState_buf;
#pragma endregion

#pragma region 目标检测
	//YoloV13
	GetYoloV13 getYoloV13;
	SetYoloV13 setYoloV13;
	int nYoloV13State;
	int nYoloV13State_buf;
#pragma endregion

#pragma region OCR
	//OCR
	GetOCR getOCR;
	SetOCR setOCR;
	int nOCRState;
	int nOCRState_buf;
#pragma endregion
};
