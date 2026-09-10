#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QProxyStyle>
#include <QSpinBox>
#include "QWorld.h"

class DockWidget;
class QLabel;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //设置对应的dock窗口
    void setToolDockWidget(QWidget *w);
    void setFlowDockWidget(QWidget *w);
    void setLogDockWidget(QWidget *w);
    //设置中心界面
    void setCenterWidget(QWidget *w);
    //设置状态栏信息
    void setStatusInfo(const QString &info);
    int centerWidgetHeight() const;

private:       
    void initMenu();
    void initToolBar();
    void initDock();
    void initStatusBar();

signals:
    void sig_ToThreadCpu();
    void sig_LoginSignal();
    void sig_AboutSignal();
    void sig_Login();
    void sig_Logout();   
    void sig_PermisSet();
    void sig_ManualRun();
    void sig_ManualStop();

private slots:
    void slot_DoTopLevelChanged(bool topLevel = false);
    void slot_DoDockClosed();
    void slot_DoLogin();
    void slot_DoAbout();
    void slot_CycleRun();
    void slot_CycleStop();   
    void on_m_pRunContinueAc_triggered();     
    void slot_PermisSet();
    void slot_DoSystemSetUp();
    void slot_DoImageLayout();
    void slot_DoGlobalVariable();
    void slot_DoCameraSetUp();
    void slot_Instrumentation();
    void slot_DoCreateProject();
    void slot_DoOpenProject();
    void slot_DoSaveProject();
    void slot_DoSaveAsProject();
    void slot_DefaultLayout();
    void slot_SaveLayout();
    void slot_InitLayout();
    void slot_RestoreToolDock();
    void slot_RestoreFlowDock();
    void slot_RestoreLogDock();
    void slot_DelParam();

private:
    void SetToolDockSize(QDockWidget* dock, const QSize size) const;
    void SetFlowDockSize(QDockWidget* dock, const QSize size) const;
    void SetLogDockSize(QDockWidget* dock, const QSize size) const;

public slots:
    void timerEvent();
    void slot_AllCycleStop();
    void timerUpdate();
    void slot_LoginBtnState();
    void slot_LogoutBtnState();
    void slot_OpenProjectParam();
    void slot_SaveProjectParam(int mode);

public:
    DockWidget* m_pFlowDock = nullptr;

private:
    FolderOperation* pFolderOperation;
    QSpinBox* objLogTime;
    QSpinBox* objSignOutTime;
    QThread* m_pthreadCpu;   //线程获取内存信息
    QHBoxLayout *m_pBoxLayout = nullptr;
    QWidget *m_pCenterWidget = nullptr;
    QToolBar *m_leftToolbar = nullptr;
    QToolBar *m_bottomToolbar = nullptr;
    QList<QAction *> m_leftAcList;
    QList<QAction *> m_bottomAcList;
    QAction *m_pToolAc = nullptr;
    QAction *m_pFlowAc = nullptr;
    QAction *m_pLogAc = nullptr;   
    DockWidget *m_pToolDock = nullptr;    
    DockWidget *m_pLogDock = nullptr;
    QLabel *m_pStatusInfoLabel = nullptr;
    QLabel* m_pStatusTimeLabel = nullptr;
    //登入/出按钮状态   
    QMenu *fileMenu = nullptr;
    QMenu *viewMenu = nullptr;
    QMenu *setMenu = nullptr;
    QMenu* permisMenu = nullptr;
    QAction* pToolLogin = nullptr;
    QAction* m_pLoginAc = nullptr;
    QAction *m_pCreateProAc = nullptr;
    QAction* m_pOpenProAc = nullptr;
    QAction *m_pSaveProAc = nullptr;
    QAction *m_pVarAc = nullptr;
    QAction *m_pNetworkAc = nullptr;
    QAction *m_pAcqAc = nullptr;
    QAction* m_pRunOnceAc = nullptr;
    QAction* m_pRunContinueAc = nullptr;
    QAction* m_pStopAc = nullptr;

private:    
    QList<QWidget*> parents;
    QString tool_width, tool_visible, tool_float;
    QString flow_width, flow_visible, flow_float;
    QString log_height, log_visible, log_float;
};

//自定义菜单栏图标大小
class DFMenuIconStyle : public QProxyStyle
{
    Q_OBJECT

public:
    DFMenuIconStyle();
    ~DFMenuIconStyle();

    void SetCustomSize(int);
    virtual int pixelMetric(PixelMetric metric, const QStyleOption* option, const QWidget* widget) const;

private:
    int m_nSize;
};
