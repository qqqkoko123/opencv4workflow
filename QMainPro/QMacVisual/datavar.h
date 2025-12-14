#pragma once

#include "QWorld.h"
#include "mainwindow.h"
#include "frmImageView.h"
#include "frmProItemTab.h"
#include "manualThread.h"
#include "autoThread.h"
#include "frmProcessSetUp.h"
#include "frmSystemSetUp.h"
#include "frmImageLayout.h"
#include "frmGlobalVariable.h"
#include "frmCameraSetUp.h"
#include "frmInstrumentation.h"
#include "frmLog.h"
#include "QtWidgetsSaveLoad.h"

class dataVar 
{	
public:	
	//静态数据成员的声明 	
	static QString soft_key;	
	static QWidget* p_MainWidget;
	static MainWindow* m_pWindow;
	static FrmImageView* fImageView;
	static frmProItemTab* fProItemTab;
	static frmProcessSetUp* fProcessSetUp;
	static frmSystemSetUp* fSystemSetUp;
	static frmImageLayout* fImageLayout;
	static frmGlobalVariable* fGlobalVariable;
	static frmCameraSetUp* fCameraSetUp;
	static frmInstrumentation* fInstrumentation;	
	static FrmLog* fLog;
	static QMap <QString, QtDragListWidget*> FlowProMap;
	static QVector<QString> camera_state;
	static QVector<QString> io_client_ip;
	static QVector<QString> io_client_port;
	static QVector<QString> mit_plc_client_ip;
	static QVector<QString> mit_plc_client_port;
	static QVector<QString> tcp_client_ip;
	static QVector<QString> tcp_client_port;
	static manualThread manualCycleThread;	
	static autoThread_B1 autoCycleThread_B1;
	static autoThread_B2 autoCycleThread_B2;
	static autoThread_B3 autoCycleThread_B3;
	static autoThread_B4 autoCycleThread_B4;
	static autoThread_B5 autoCycleThread_B5;
	static autoThread_B6 autoCycleThread_B6;
	static autoThread_B7 autoCycleThread_B7;
	static autoThread_B8 autoCycleThread_B8;
	static autoThread_B9 autoCycleThread_B9;
	static autoThread_B10 autoCycleThread_B10;
	static autoThread_B11 autoCycleThread_B11;
	static autoThread_B12 autoCycleThread_B12;
	static autoThread_B13 autoCycleThread_B13;
	static autoThread_B14 autoCycleThread_B14;
	static autoThread_B15 autoCycleThread_B15;
	static autoThread_B16 autoCycleThread_B16;
	static autoThread_B17 autoCycleThread_B17;
	static autoThread_B18 autoCycleThread_B18;
	static autoThread_B19 autoCycleThread_B19;
	static autoThread_B20 autoCycleThread_B20;
	static int stopThread_A;
	static int stopThread_B1;
	static int stopThread_B2;
	static int stopThread_B3;	
	static int stopThread_B4;
	static int stopThread_B5;
	static int stopThread_B6;
	static int stopThread_B7;
	static int stopThread_B8;
	static int stopThread_B9;
	static int stopThread_B10;
	static int stopThread_B11;
	static int stopThread_B12;
	static int stopThread_B13;
	static int stopThread_B14;
	static int stopThread_B15;
	static int stopThread_B16;
	static int stopThread_B17;
	static int stopThread_B18;
	static int stopThread_B19;
	static int stopThread_B20;
	static int m_a_state;	
	static QString pageState;
	static QString user_name;
	static int login_state;
	static int admin_login_state;
	static int auto_table;
	static QSqlDatabase database;
	static SQLite sqlite;	
	static bool bol_connect;
	static XML xml;
	static int img_choose;
	static bool runFinish_A;
	static bool runFinish_B1;
	static bool runFinish_B2;
	static bool runFinish_B3;
	static bool runFinish_B4;
	static bool runFinish_B5;
	static bool runFinish_B6;
	static bool runFinish_B7;
	static bool runFinish_B8;
	static bool runFinish_B9;
	static bool runFinish_B10;
	static bool runFinish_B11;
	static bool runFinish_B12;
	static bool runFinish_B13;
	static bool runFinish_B14;
	static bool runFinish_B15;
	static bool runFinish_B16;
	static bool runFinish_B17;
	static bool runFinish_B18;
	static bool runFinish_B19;
	static bool runFinish_B20;
	static int img_view_count_B1;
	static int img_view_count_buf_B1;
	static int img_view_count_B2;
	static int img_view_count_buf_B2;
	static int img_view_count_B3;
	static int img_view_count_buf_B3;
	static int img_view_count_B4;
	static int img_view_count_buf_B4;
	static int img_view_count_B5;
	static int img_view_count_buf_B5;
	static int img_view_count_B6;
	static int img_view_count_buf_B6;
	static int img_view_count_B7;
	static int img_view_count_buf_B7;
	static int img_view_count_B8;
	static int img_view_count_buf_B8;
	static int img_view_count_B9;
	static int img_view_count_buf_B9;
	static int img_view_count_B10;
	static int img_view_count_buf_B10;
	static int img_view_count_B11;
	static int img_view_count_buf_B11;
	static int img_view_count_B12;
	static int img_view_count_buf_B12;
	static int img_view_count_B13;
	static int img_view_count_buf_B13;
	static int img_view_count_B14;
	static int img_view_count_buf_B14;
	static int img_view_count_B15;
	static int img_view_count_buf_B15;
	static int img_view_count_B16;
	static int img_view_count_buf_B16;
	static int img_view_count_B17;
	static int img_view_count_buf_B17;
	static int img_view_count_B18;
	static int img_view_count_buf_B18;
	static int img_view_count_B19;
	static int img_view_count_buf_B19;
	static int img_view_count_B20;
	static int img_view_count_buf_B20;
	static bool app_state;
	static bool form_max_state;
	static bool process_self_start;
	static bool auto_login_out;
	static QDateTime startTime;
	static QString path_P;
	static QString path_PF;
	static QString path_L;
	static QString path_LA;
	static QString path_Image;
	static QString path_DB;	
	static QGraphicsViews* img_view_B1;
	static QGraphicsViews* img_view_B2;
	static QGraphicsViews* img_view_B3;
	static QGraphicsViews* img_view_B4;
	static QGraphicsViews* img_view_B5;
	static QGraphicsViews* img_view_B6;
	static QGraphicsViews* img_view_B7;
	static QGraphicsViews* img_view_B8;
	static QGraphicsViews* img_view_B9;
	static QGraphicsViews* img_view_B10;
	static QGraphicsViews* img_view_B11;
	static QGraphicsViews* img_view_B12;
	static QGraphicsViews* img_view_B13;
	static QGraphicsViews* img_view_B14;
	static QGraphicsViews* img_view_B15;
	static QGraphicsViews* img_view_B16;
	static QGraphicsViews* img_view_B17;
	static QGraphicsViews* img_view_B18;
	static QGraphicsViews* img_view_B19;
	static QGraphicsViews* img_view_B20;
	static QGraphicsViews* img_view1;
	static QGraphicsViews* img_view2;
	static QGraphicsViews* img_view3;
	static QGraphicsViews* img_view4;
	static QGraphicsViews* img_view5;
	static QGraphicsViews* img_view6;
	static QGraphicsViews* img_view7;
	static QGraphicsViews* img_view8;
	static QGraphicsViews* img_view9;		
	//项目名称
	static QString projectName;			
	static int int_link;
	static QString str_link;	
	static QtWidgetsSaveLoad* qtWidgetsSaveLoad;	
	static int dragNumber;
	//计算耗时
	static int nCostTime_B1;
	static int nCostTime_B2;
	static int nCostTime_B3;
	static int nCostTime_B4;
	static int nCostTime_B5;
	static int nCostTime_B6;
	static int nCostTime_B7;
	static int nCostTime_B8;
	static int nCostTime_B9;
	static int nCostTime_B10;
	static int nCostTime_B11;
	static int nCostTime_B12;
	static int nCostTime_B13;
	static int nCostTime_B14;
	static int nCostTime_B15;
	static int nCostTime_B16;
	static int nCostTime_B17;
	static int nCostTime_B18;
	static int nCostTime_B19;
	static int nCostTime_B20;
	//多线程自动运行一次
	static short manualRunOnce_A;
	static short autoRunOnce_B1;
	static short autoRunOnce_B2;
	static short autoRunOnce_B3;
	static short autoRunOnce_B4;
	static short autoRunOnce_B5;
	static short autoRunOnce_B6;
	static short autoRunOnce_B7;
	static short autoRunOnce_B8;
	static short autoRunOnce_B9;
	static short autoRunOnce_B10;
	static short autoRunOnce_B11;
	static short autoRunOnce_B12;
	static short autoRunOnce_B13;
	static short autoRunOnce_B14;
	static short autoRunOnce_B15;
	static short autoRunOnce_B16;
	static short autoRunOnce_B17;
	static short autoRunOnce_B18;
	static short autoRunOnce_B19;
	static short autoRunOnce_B20;	
	static QVector<DragListWidgetPrivate*> dragD;		
	static QMap<int, int> all_link_process;
	static int comm_state_buf;
};