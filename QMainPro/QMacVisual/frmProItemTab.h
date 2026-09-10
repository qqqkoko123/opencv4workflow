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

#pragma region ?????
//?????--??????
typedef int (*GetImageSource)();
typedef void (*SetImageSource)();
//?????--????ROI
typedef int (*GetCreateRoi)();
typedef void (*SetCreateRoi)();
//?????--???????
typedef int (*GetCropImage)();
typedef void (*SetCropImage)();
//?????--????
typedef int (*GetImageFlip)();
typedef void (*SetImageFlip)();
//?????--?????
typedef int (*GetImageMorphology)();
typedef void (*SetImageMorphology)();
//?????--??????
typedef int (*GetImageRepair)();
typedef void (*SetImageRepair)();
//?????--??????
typedef int (*GetImageRotate)();
typedef void (*SetImageRotate)();
//?????--??????
typedef int (*GetImageSplice)();
typedef void (*SetImageSplice)();
//?????--??????
typedef int (*GetImageView)();
typedef void (*SetImageView)();
//?????--?????
typedef int (*GetPerspectiveTransform)();
typedef void (*SetPerspectiveTransform)();
//?????--??????
typedef int (*GetSkeleton)();
typedef void (*SetSkeleton)();
//?????--???????
typedef int (*GetExportImage)();
typedef void (*SetExportImage)();
//?????--??????
typedef int (*GetImagePrint)();
typedef void (*SetImagePrint)();
#pragma endregion

#pragma region ??????
//?????--?????????
typedef int (*GetBarcodeIdentify)();
typedef void (*SetBarcodeIdentify)();
//?????--??????
typedef int (*GetBlobDetector)();
typedef void (*SetBlobDetector)();
//?????--??????
typedef int (*GetBrightness)();
typedef void (*SetBrightness)();
//?????--??????
typedef int (*GetColorIdentify)();
typedef void (*SetColorIdentify)();
//?????--????????
typedef int (*GetQRcodeIdentify)();
typedef void (*SetQRcodeIdentify)();
//?????--?????????
typedef int (*GetQRcodeGenerate)();
typedef void (*SetQRcodeGenerate)();
//?????--???????????
typedef int (*GetSelectShape)();
typedef void (*SetSelectShape)();
//?????--??????
typedef int (*GetClassifier)();
typedef void (*SetClassifier)();
#pragma endregion

#pragma region ??????
//?????--N???
typedef int (*GetERTCalibration)();
typedef void (*SetERTCalibration)();
//?????--??????
typedef int (*GetMeasureCalibration)();
typedef void (*SetMeasureCalibration)();
#pragma endregion

#pragma region ????????
//?????--??????
typedef int (*GetCamShiftTrack)();
typedef void (*SetCamShiftTrack)();
//?????--???????
typedef int (*GetLinearCalculation)();
typedef void (*SetLinearCalculation)();
//?????--??????
typedef int (*GetTemplateMatch)();
typedef void (*SetTemplateMatch)();
//?????--??????
typedef int (*GetShapeMatch)();
typedef void (*SetShapeMatch)();
#pragma endregion

#pragma region ????????
//?????--????
typedef int (*GetFindCircle)();
typedef void (*SetFindCircle)();
//?????--??????
typedef int (*GetFindLine)();
typedef void (*SetFindLine)();
//?????--????
typedef int (*GetFitCircle)();
typedef void (*SetFitCircle)();
//?????--??????
typedef int (*GetFitEllipse)();
typedef void (*SetFitEllipse)();
//?????--??????
typedef int (*GetFitLine)();
typedef void (*SetFitLine)();
//?????--???????
typedef int (*GetContourPoints)();
typedef void (*SetContourPoints)();
#pragma endregion

#pragma region ????????
//?????--???????
typedef int (*GetLineCircle)();
typedef void (*SetLineCircle)();
//?????--???????
typedef int (*GetLineLineI)();
typedef void (*SetLineLineI)();
//?????--??+??
typedef int (*GetPointLine)();
typedef void (*SetPointLine)();
//?????--??+??
typedef int (*GetPointPoint)();
typedef void (*SetPointPoint)();
//?????--??????
typedef int (*GetRoundedCorners)();
typedef void (*SetRoundedCorners)();
//?????--??????????
typedef int (*GetEdgeWidthMeasure)();
typedef void (*SetEdgeWidthMeasure)();
#pragma endregion

#pragma region ??????
//?????--??????
typedef int (*GetFlatness)();
typedef void (*SetFlatness)();
#pragma endregion

#pragma region ???????
//?????--?????
typedef int (*GetExtensionLibrary)();
typedef void (*SetExtensionLibrary)();
//?????--??????
typedef int (*GetLogicGoto)();
typedef void (*SetLogicGoto)();
//?????--???????
typedef int (*GetLogicJudge)();
typedef void (*SetLogicJudge)();
//?????--???????
typedef int (*GetLogicJudgeEnd)();
typedef void (*SetLogicJudgeEnd)();
#pragma endregion

#pragma region ??????
//?????--PLC???
typedef int (*GetPlcCommunicate)();
typedef void (*SetPlcCommunicate)();
//?????--???????
typedef int (*GetSerialPort)();
typedef void (*SetSerialPort)();
//?????--TCP/IP??????
typedef int (*GetSocketTcpServer)();
typedef void (*SetSocketTcpServer)();
//?????--TCP/IP?????
typedef int (*GetSocketTcpClient)();
typedef void (*SetSocketTcpClient)();
#pragma endregion

#pragma region ??????
//?????--????CSV
typedef int (*GetExportCsv)();
typedef void (*SetExportCsv)();
#pragma endregion


#pragma region ?????
//?????--Yolov13
typedef int (*GetYoloV13)();
typedef void (*SetYoloV13)();
#pragma endregion

#pragma region OCR
//?????--OCR
typedef int (*GetOCR)();
typedef void (*SetOCR)();
#pragma endregion

#pragma region ???????
typedef int (*GetPlateRecognition)();
typedef void (*SetPlateRecognition)();
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
	//?????????????
	void ProcessTreeInit();
	QList<QString> treeList;
	int press_index;
	int cutover_index;
	QString flowPageName_buf;	
	QString getRandomString();
	QVector<QString> fNameList;

public:
	QTreeWidgetItem* itemParent = nullptr;
	QMap<QString, QToolBase*> FlowTabMap;
	QVector<QTreeWidgetItem*> treeItem = QVector<QTreeWidgetItem*>(20);
	QMap<QTreeWidgetItem*, int> m_pro_value;  //????????????????	
	void DeserializeInitProcess();  //?????????????????	
	QtDragListWidget* TempDragListWidget = nullptr;
	QtDragListWidget* TempDragListWidget_B1 = nullptr, * TempDragListWidget_B2 = nullptr, * TempDragListWidget_B3 = nullptr, * TempDragListWidget_B4 = nullptr, * TempDragListWidget_B5 = nullptr, * TempDragListWidget_B6 = nullptr, * TempDragListWidget_B7 = nullptr, * TempDragListWidget_B8 = nullptr, * TempDragListWidget_B9 = nullptr, * TempDragListWidget_B10 = nullptr;
	QtDragListWidget* TempDragListWidget_B11 = nullptr, * TempDragListWidget_B12 = nullptr, * TempDragListWidget_B13 = nullptr, * TempDragListWidget_B14 = nullptr, * TempDragListWidget_B15 = nullptr, * TempDragListWidget_B16 = nullptr, * TempDragListWidget_B17 = nullptr, * TempDragListWidget_B18 = nullptr, * TempDragListWidget_B19 = nullptr, * TempDragListWidget_B20 = nullptr;
	
private:
	//?????	
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
#pragma region ?????
	//??????????
	GetImageSource getImageSourceState;
	SetImageSource setImageSourceState;
	int nImageSourceState;
	int nImageSourceState_buf;
	//????ROI????
	GetCreateRoi getCreateRoiState;
	SetCreateRoi setCreateRoiState;
	int nCreateRoiState;
	int nCreateRoiState_buf;
	//???????????
	GetCropImage getCropImageState;
	SetCropImage setCropImageState;
	int nCropImageState;
	int nCropImageState_buf;
	//????????
	GetImageFlip getImageFlipState;
	SetImageFlip setImageFlipState;
	int nImageFlipState;
	int nImageFlipState_buf;
	//?????????
	GetImageMorphology getImageMorphologyState;
	SetImageMorphology setImageMorphologyState;
	int nImageMorphologyState;
	int nImageMorphologyState_buf;
	//??????????
	GetImageRepair getImageRepairState;
	SetImageRepair setImageRepairState;
	int nImageRepairState;
	int nImageRepairState_buf;
	//??????????
	GetImageRotate getImageRotateState;
	SetImageRotate setImageRotateState;
	int nImageRotateState;
	int nImageRotateState_buf;
	//??????????
	GetImageSplice getImageSpliceState;
	SetImageSplice setImageSpliceState;
	int nImageSpliceState;
	int nImageSpliceState_buf;
	//??????????
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
	//?????????
	GetPerspectiveTransform getPerspectiveTransformState;
	SetPerspectiveTransform setPerspectiveTransformState;
	int nPerspectiveTransformState;
	int nPerspectiveTransformState_buf;
	//??????????
	GetSkeleton getSkeletonState;
	SetSkeleton setSkeletonState;
	int nSkeletonState;
	int nSkeletonState_buf;
	//???????????
	GetExportImage getExportImageState;
	SetExportImage setExportImageState;
	int nExportImageState;
	int nExportImageState_buf;
	//??????
	GetImagePrint getImagePrintState;
	SetImagePrint setImagePrintState;
	int nImagePrintState;
	int nImagePrintState_buf;
#pragma endregion

#pragma region ??????
	//?????????????
	GetBarcodeIdentify getBarcodeIdentifyState;
	SetBarcodeIdentify setBarcodeIdentifyState;
	int nBarcodeIdentifyState;
	int nBarcodeIdentifyState_buf;
	//??????????
	GetBlobDetector getBlobDetectorState;
	SetBlobDetector setBlobDetectorState;
	int nBlobDetectorState;
	int nBlobDetectorState_buf;
	//??????????
	GetBrightness getBrightnessState;
	SetBrightness setBrightnessState;
	int nBrightnessState;
	int nBrightnessState_buf;
	//??????????
	GetColorIdentify getColorIdentifyState;
	SetColorIdentify setColorIdentifyState;
	int nColorIdentifyState;
	int nColorIdentifyState_buf;
	//????????????
	GetQRcodeIdentify getQRcodeIdentifyState;
	SetQRcodeIdentify setQRcodeIdentifyState;
	int nQRcodeIdentifyState;
	int nQRcodeIdentifyState_buf;
	//?????????????
	GetQRcodeGenerate getQRcodeGenerateState;
	SetQRcodeGenerate setQRcodeGenerateState;
	int nQRcodeGenerateState;
	int nQRcodeGenerateState_buf;
	//???????????????
	GetSelectShape getSelectShape;
	SetSelectShape setSelectShape;
	int nSelectShapeState;
	int nSelectShapeState_buf;
	//??????????
	GetClassifier getClassifierState;
	SetClassifier setClassifierState;
	int nClassifierState;
	int nClassifierState_buf;
#pragma endregion

#pragma region ??????
	//N???????
	GetERTCalibration getERTCalibrationState;
	SetERTCalibration setERTCalibrationState;
	int nERTCalibrationState;
	int nERTCalibrationState_buf;
	//??????????
	GetMeasureCalibration getMeasureCalibrationState;
	SetMeasureCalibration setMeasureCalibrationState;
	int nMeasureCalibrationState;
	int nMeasureCalibrationState_buf;
#pragma endregion

#pragma region ????????
	//??????????
	GetCamShiftTrack getCamShiftTrackState;
	SetCamShiftTrack setCamShiftTrackState;
	int nCamShiftTrackState;
	int nCamShiftTrackState_buf;
	//???????????
	GetLinearCalculation getLinearCalculationState;
	SetLinearCalculation setLinearCalculationState;
	int nLinearCalculationState;
	int nLinearCalculationState_buf;
	//??????????
	GetTemplateMatch getTemplateMatchState;
	SetTemplateMatch setTemplateMatchState;
	int nTemplateMatchState;
	int nTemplateMatchState_buf;
	//??????????
	GetShapeMatch getShapeMatchState;
	SetShapeMatch setShapeMatchState;
	int nShapeMatchState;
	int nShapeMatchState_buf;
#pragma endregion

#pragma region ????????
	//????????
	GetFindCircle getFindCircleState;
	SetFindCircle setFindCircleState;
	int nFindCircleState;
	int nFindCircleState_buf;
	//??????????
	GetFindLine getFindLineState;
	SetFindLine setFindLineState;
	int nFindLineState;
	int nFindLineState_buf;
	//????????
	GetFitCircle getFitCircleState;
	SetFitCircle setFitCircleState;
	int nFitCircleState;
	int nFitCircleState_buf;
	//??????????
	GetFitEllipse getFitEllipseState;
	SetFitEllipse setFitEllipseState;
	int nFitEllipseState;
	int nFitEllipseState_buf;
	//??????????
	GetFitLine getFitLineState;
	SetFitLine setFitLineState;
	int nFitLineState;
	int nFitLineState_buf;
	//???????????
	GetContourPoints getContourPointsState;
	SetContourPoints setContourPointsState;
	int nContourPointsState;
	int nContourPointsState_buf;
#pragma endregion

#pragma region ????????
	//???????????
	GetLineCircle getLineCircleState;
	SetLineCircle setLineCircleState;
	int nLineCircleState;
	int nLineCircleState_buf;
	//???????????
	GetLineLineI getLineLineIState;
	SetLineLineI setLineLineIState;
	int nLineLineIState;
	int nLineLineIState_buf;
	//??+??????
	GetPointLine getPointLineState;
	SetPointLine setPointLineState;
	int nPointLineState;
	int nPointLineState_buf;
	//??+??????
	GetPointPoint getPointPointState;
	SetPointPoint setPointPointState;
	int nPointPointState;
	int nPointPointState_buf;
	//??????????
	GetRoundedCorners getRoundedCornersState;
	SetRoundedCorners setRoundedCornersState;
	int nRoundedCornersState;
	int nRoundedCornersState_buf;
	//??????????????
	GetEdgeWidthMeasure getEdgeWidthMeasureState;
	SetEdgeWidthMeasure setEdgeWidthMeasureState;
	int nEdgeWidthMeasureState;
	int nEdgeWidthMeasureState_buf;
#pragma endregion	

#pragma region ??????
	//??????????
	GetFlatness getFlatnessState;
	SetFlatness setFlatnessState;
	int nFlatnessState;
	int nFlatnessState_buf;
#pragma endregion

#pragma region ???????
	//?????????
	GetExtensionLibrary getExtensionLibraryState;
	SetExtensionLibrary setExtensionLibraryState;
	int nExtensionLibraryState;
	int nExtensionLibraryState_buf;
	//??????????
	GetLogicGoto getLogicGotoState;
	SetLogicGoto setLogicGotoState;
	int nLogicGotoState;
	int nLogicGotoState_buf;
	//???????????
	GetLogicJudge getLogicJudgeState;
	SetLogicJudge setLogicJudgeState;
	int nLogicJudgeState;
	int nLogicJudgeState_buf;
	//???????????
	GetLogicJudgeEnd getLogicJudgeEndState;
	SetLogicJudgeEnd setLogicJudgeEndState;
	int nLogicJudgeEndState;
	int nLogicJudgeEndState_buf;
#pragma endregion

#pragma region ??????
	//PLC???
	GetPlcCommunicate getPlcCommunicate;
	SetPlcCommunicate setPlcCommunicate;
	int nPlcCommunicateState;
	int nPlcCommunicateState_buf;
	//???????
	GetSerialPort getSerialPort;
	SetSerialPort setSerialPort;
	int nSerialPortState;
	int nSerialPortState_buf;
	//TCP/IP??????
	GetSocketTcpServer getSocketTcpServer;
	SetSocketTcpServer setSocketTcpServer;
	int nSocketTcpServerState;
	int nSocketTcpServerState_buf;
	//TCP/IP?????
	GetSocketTcpClient getSocketTcpClient;
	SetSocketTcpClient setSocketTcpClient;
	int nSocketTcpClientState;
	int nSocketTcpClientState_buf;
#pragma endregion

#pragma region ??????
	//????CSV????
	GetExportCsv getExportCsv;
	SetExportCsv setExportCsv;
	int nExportCsvState;
	int nExportCsvState_buf;
#pragma endregion

#pragma region ?????
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

#pragma region ???????
	GetPlateRecognition getPlateRecognition = nullptr;
	SetPlateRecognition setPlateRecognition = nullptr;
	int nPlateRecognitionState = 0;
	int nPlateRecognitionState_buf = 0;
#pragma endregion
};
