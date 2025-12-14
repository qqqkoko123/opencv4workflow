#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include <QLayout>
#include <QDockWidget>
#include <QtDebug>
#include <QStatusBar>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include "dockwidget.h"
#include "showcpumemory.h"
#include "datavar.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	this->setContextMenuPolicy(Qt::NoContextMenu);
	this->setWindowFlags(Qt::Widget);
	//连接登入登出信号与槽函数
	connect(this, &MainWindow::sig_Login, dataVar::fProItemTab, &frmProItemTab::slot_Login);
	connect(this, &MainWindow::sig_Logout, dataVar::fProItemTab, &frmProItemTab::slot_Logout);
	//连接循环运行或停止信号与槽函数
	connect(dataVar::fProItemTab, &frmProItemTab::sig_CycleRun, this, &MainWindow::slot_CycleRun);
	connect(dataVar::fProItemTab, &frmProItemTab::sig_CycleStop, this, &MainWindow::slot_CycleStop);
	connect(this, &MainWindow::sig_ManualRun, dataVar::fProItemTab, &frmProItemTab::slot_ManualRun);
	connect(this, &MainWindow::sig_ManualStop, dataVar::fProItemTab, &frmProItemTab::slot_ManualStop);
	initMenu();
	initToolBar();
	initDock();
	initStatusBar();
	slot_LogoutBtnState();
	slot_InitLayout();
	//长时间处理事件
	pFolderOperation = new FolderOperation();
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(10 * 60 * 1000);  //10分钟
}

MainWindow::~MainWindow()
{
	if (objLogTime != nullptr)
	{
		delete objLogTime;
	}
	if (objSignOutTime != nullptr)
	{
		delete objSignOutTime;
	}
	if (pFolderOperation != nullptr)
	{
		delete pFolderOperation;
	}
	this->deleteLater();
}

void MainWindow::timerEvent()
{
	int day = 0;
	objLogTime = dataVar::fSystemSetUp->findChild<QSpinBox*>("spinLogTime");
	day = 0 - objLogTime->value();
	pFolderOperation->FindFileForDelete(dataVar::soft_key, dataVar::path_LA, day);
}

//自定义菜单栏图标大小
DFMenuIconStyle::DFMenuIconStyle()
	: QProxyStyle()
{
	m_nSize = 22;
}

DFMenuIconStyle::~DFMenuIconStyle()
{
}

void DFMenuIconStyle::SetCustomSize(int size)
{
	m_nSize = size;
}

int DFMenuIconStyle::pixelMetric(PixelMetric metric, const QStyleOption* option, const QWidget* widget) const
{
	int s = QProxyStyle::pixelMetric(metric, option, widget);
	if (metric == QStyle::PM_SmallIconSize)
	{
		s = m_nSize;
	}
	return s;
}

void MainWindow::setToolDockWidget(QWidget* w)
{
	if (m_pToolDock)
		m_pToolDock->setWidget(w);
}

void MainWindow::setFlowDockWidget(QWidget* w)
{
	if (m_pFlowDock)
		m_pFlowDock->setWidget(w);
}

void MainWindow::setLogDockWidget(QWidget* w)
{
	if (m_pLogDock)
		m_pLogDock->setWidget(w);
}

void MainWindow::setCenterWidget(QWidget* w)
{
	if (m_pCenterWidget)
	{
		m_pBoxLayout->removeWidget(m_pCenterWidget);
		m_pCenterWidget->setParent(nullptr);
		m_pCenterWidget = nullptr;
	}
	if (w)
	{
		m_pBoxLayout->addWidget(w);
		m_pCenterWidget = w;
	}
}

void MainWindow::setStatusInfo(const QString& info)
{
	if (m_pStatusInfoLabel)
	{
		m_pStatusInfoLabel->setText(info);
		m_pStatusInfoLabel->adjustSize();
	}
}

int MainWindow::centerWidgetHeight() const
{
	return this->centralWidget()->height();
}

void MainWindow::initMenu()
{
	QMenuBar* menuBar = new QMenuBar(this);
	this->setMenuBar(menuBar);
	//自定义菜单栏图标大小
	DFMenuIconStyle* m_pMenuStyle = new DFMenuIconStyle();
	menuBar->setStyle(m_pMenuStyle);
	menuBar->setStyleSheet("background-color: rgb(240, 248, 226);font-size:16px;");
	//菜单样式
	QString menuStyle(
		"QMenu::item{"				
		"color: rgb(20, 20, 20);"
		"}"
		"QMenu::item:hover{"
		"background-color: rgb(199, 208, 233);"
		"}"
		"QMenu::item:selected{"
		"background-color: rgb(152, 170, 216);"
		"}"
	);
	fileMenu = menuBar->addMenu("文件");
	fileMenu->setStyleSheet(menuStyle);
	QAction* pToolCreateProAc = fileMenu->addAction("新建项目");
	pToolCreateProAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolCreateProAc->setIcon(QIcon(":/res/ico/NewProducts.png"));
	connect(pToolCreateProAc, &QAction::triggered, this, &MainWindow::slot_DoCreateProject);
	QAction* pToolOpenProAc = fileMenu->addAction("打开项目");
	pToolOpenProAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolOpenProAc->setIcon(QIcon(":/res/ico/Open.png"));
	connect(pToolOpenProAc, &QAction::triggered, this, &MainWindow::slot_DoOpenProject);
	QAction* pToolSaveProAc = fileMenu->addAction("保存项目");
	pToolSaveProAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolSaveProAc->setIcon(QIcon(":/res/ico/Save.png"));
	connect(pToolSaveProAc, &QAction::triggered, this, &MainWindow::slot_DoSaveProject);
	QAction* pToolSaveAsProAc = fileMenu->addAction("项目另存为");
	pToolSaveAsProAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolSaveAsProAc->setIcon(QIcon(":/res/ico/Save as.png"));
	connect(pToolSaveAsProAc, &QAction::triggered, this, &MainWindow::slot_DoSaveAsProject);
	viewMenu = menuBar->addMenu("视图");
	viewMenu->setStyleSheet(menuStyle);
	QAction* pToolAc = viewMenu->addAction("工具箱");
	pToolAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolAc->setIcon(QIcon(":/Bitmaps/set.png"));
	QAction* pFlowAc = viewMenu->addAction("流程图");
	pFlowAc->setFont(QFont("Microsoft YaHei,13.5"));
	pFlowAc->setIcon(QIcon(":/Bitmaps/pros.png"));
	QAction* pLogAc = viewMenu->addAction("运行日志");
	pLogAc->setFont(QFont("Microsoft YaHei,13.5"));
	pLogAc->setIcon(QIcon(":/Bitmaps/log.png"));
	QAction* pDefaultLayoutAc = viewMenu->addAction("默认布局");
	pDefaultLayoutAc->setFont(QFont("Microsoft YaHei,13.5"));
	pDefaultLayoutAc->setIcon(QIcon(":/Bitmaps/default_layout.png"));
	QAction* pSaveLayoutAc = viewMenu->addAction("保存布局");
	pSaveLayoutAc->setFont(QFont("Microsoft YaHei,13.5"));
	pSaveLayoutAc->setIcon(QIcon(":/Bitmaps/save_layout.png"));
	connect(pToolAc, &QAction::triggered, this, [this]() {
		m_pToolDock->setVisible(true);
		m_pToolDock->setFloating(false);
		});
	connect(pFlowAc, &QAction::triggered, this, [this]() {
		m_pFlowDock->setVisible(true);
		m_pFlowDock->setFloating(false);
		});
	connect(pLogAc, &QAction::triggered, this, [this]() {
		m_pLogDock->setVisible(true);
		m_pLogDock->setFloating(false);
		});
	connect(pDefaultLayoutAc, &QAction::triggered, this, &MainWindow::slot_DefaultLayout);
	connect(pSaveLayoutAc, &QAction::triggered, this, &MainWindow::slot_SaveLayout);
	setMenu = menuBar->addMenu("设置");
	setMenu->setStyleSheet(menuStyle);
	QAction* pToolAcqAc = setMenu->addAction("相机设置");
	pToolAcqAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolAcqAc->setIcon(QIcon(":/res/ico/cam.png"));
	connect(pToolAcqAc, &QAction::triggered, this, &MainWindow::slot_DoCameraSetUp);
	QAction* pToolNetworkAc = setMenu->addAction("仪器通讯");
	pToolNetworkAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolNetworkAc->setIcon(QIcon(":/res/ico/network.png"));
	connect(pToolNetworkAc, &QAction::triggered, this, &MainWindow::slot_Instrumentation);
	QAction* pToolVarAc = setMenu->addAction("全局变量");
	pToolVarAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolVarAc->setIcon(QIcon(":/res/ico/var.ico"));
	connect(pToolVarAc, &QAction::triggered, this, &MainWindow::slot_DoGlobalVariable);
	QAction* pToolFormSetAc = setMenu->addAction("图像布局");
	pToolFormSetAc->setFont(QFont("Microsoft YaHei,13.5"));
	pToolFormSetAc->setIcon(QIcon(":/res/ico/osd.png"));
	connect(pToolFormSetAc, &QAction::triggered, this, &MainWindow::slot_DoImageLayout);
	QAction* argMenu = setMenu->addAction("系统参数");
	argMenu->setFont(QFont("Microsoft YaHei,13.5"));
	argMenu->setIcon(QIcon(":/res/ico/set.png"));
	connect(argMenu, &QAction::triggered, this, &MainWindow::slot_DoSystemSetUp);
	permisMenu = menuBar->addMenu("权限");
	permisMenu->setStyleSheet(menuStyle);
	pToolLogin = permisMenu->addAction("用户登录");
	pToolLogin->setFont(QFont("Microsoft YaHei,13.5"));
	pToolLogin->setIcon(QIcon(":/res/ico/user.png"));
	connect(pToolLogin, &QAction::triggered, this, &MainWindow::slot_DoLogin);
	QAction* pPermisSet = permisMenu->addAction("权限管理");
	pPermisSet->setFont(QFont("Microsoft YaHei,13.5"));
	pPermisSet->setIcon(QIcon(":/Bitmaps/permis.png"));
	connect(pPermisSet, &QAction::triggered, this, &MainWindow::slot_PermisSet);
	auto* helpMenu = menuBar->addMenu("帮助");
	helpMenu->setStyleSheet(menuStyle);
	QAction* btnAbout = helpMenu->addAction("关于本软件...");
	btnAbout->setFont(QFont("Microsoft YaHei,13.5"));
	btnAbout->setIcon(QIcon(":/res/ico/about.png"));
	connect(btnAbout, &QAction::triggered, this, &MainWindow::slot_DoAbout);
}

void MainWindow::initToolBar()
{
	//工具箱
	QToolBar* toolBar = new QToolBar("toolbar", this); //创建工具箱
	addToolBar(Qt::TopToolBarArea, toolBar);
	toolBar->setMovable(false);
	toolBar->setIconSize(QSize(36, 36));
	toolBar->layout()->setSpacing(8);
	toolBar->layout()->setContentsMargins(2, 2, 2, 2);
	toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
	//按钮样式  
	QString btnStyle(
		"QWidget{"
		"background-color: rgb(240, 248, 226);"
		"}"
		"QToolButton:hover{"
		"background-color: rgb(199, 208, 233);"
		"}"
		"QToolButton:pressed{"
		"background-color: rgb(152, 170, 216);"
		"}"
	);
	toolBar->setStyleSheet(btnStyle);
	m_pCreateProAc = toolBar->addAction(QIcon(":/res/ico/NewProducts.png"), "新建项目");
	connect(m_pCreateProAc, &QAction::triggered, this, &MainWindow::slot_DoCreateProject);	
	m_pOpenProAc = toolBar->addAction(QIcon(":/res/ico/Open.png"), "打开项目");
	connect(m_pOpenProAc, &QAction::triggered, this, &MainWindow::slot_DoOpenProject);
	m_pSaveProAc = toolBar->addAction(QIcon(":/res/ico/Save.png"), "保存项目");
	connect(m_pSaveProAc, &QAction::triggered, this, &MainWindow::slot_DoSaveProject);
	toolBar->addSeparator();
	m_pVarAc = toolBar->addAction(QIcon(":/res/ico/var.ico"), "全局变量");
	connect(m_pVarAc, &QAction::triggered, this, &MainWindow::slot_DoGlobalVariable);
	m_pNetworkAc = toolBar->addAction(QIcon(":/res/ico/network.png"), "仪器通讯");
	connect(m_pNetworkAc, &QAction::triggered, this, &MainWindow::slot_Instrumentation);
	m_pAcqAc = toolBar->addAction(QIcon(":/res/ico/cam.png"), "相机设置");
	connect(m_pAcqAc, &QAction::triggered, this, &MainWindow::slot_DoCameraSetUp);
	m_pLoginAc = toolBar->addAction(QIcon(":/res/ico/user.png"), "用户登录");
	connect(m_pLoginAc, &QAction::triggered, this, &MainWindow::slot_DoLogin);
	toolBar->addSeparator();
	m_pRunOnceAc = toolBar->addAction(QIcon(":/res/ico/run.png"), "单次执行");
	connect(m_pRunOnceAc, &QAction::triggered, dataVar::fProItemTab, &frmProItemTab::slot_AllCycleRunOnce);
	m_pRunContinueAc = toolBar->addAction(QIcon(":/res/ico/cycle.png"), "连续执行");
	m_pRunContinueAc->setObjectName("m_pRunContinueAc"); //关联on_m_pRunContinueAc槽函数
	QMetaObject::connectSlotsByName(this);
	connect(m_pRunContinueAc, &QAction::triggered, dataVar::fProItemTab, &frmProItemTab::slot_AllCycleRunContinue);	
	m_pStopAc = toolBar->addAction(QIcon(":/res/ico/stop.png"), "停止");
	connect(m_pStopAc, &QAction::triggered, this, &MainWindow::slot_AllCycleStop);
	connect(m_pStopAc, &QAction::triggered, dataVar::fProItemTab, &frmProItemTab::slot_AllCycleStop);
	m_leftToolbar = new QToolBar("left_bar", this);
	m_bottomToolbar = new QToolBar("bottom_bar", this);
	m_leftToolbar->setMovable(false);
	m_leftToolbar->layout()->setSpacing(8);
	m_leftToolbar->layout()->setContentsMargins(2, 2, 2, 2);
	m_leftToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	m_bottomToolbar->setMovable(false);
	m_bottomToolbar->layout()->setSpacing(8);
	m_bottomToolbar->layout()->setContentsMargins(2, 2, 2, 2);
	m_bottomToolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	addToolBar(Qt::LeftToolBarArea, m_leftToolbar);
	addToolBar(Qt::BottomToolBarArea, m_bottomToolbar);
	m_leftToolbar->setVisible(false);
	m_bottomToolbar->setVisible(false);
	m_pToolAc = new QAction(QIcon(":/Bitmaps/set.png"), "工\n具\n箱", this);
	m_pFlowAc = new QAction(QIcon(":/Bitmaps/pros.png"), "流\n程\n图", this);
	m_pLogAc = new QAction(QIcon(":/Bitmaps/log.png"), "运行日志", this);
	connect(m_pToolAc, &QAction::triggered, this, [this]() {
		auto point = this->mapToGlobal(m_leftToolbar->pos());
		int w = m_pToolDock->width();
		int h = centerWidgetHeight();
		m_pToolDock->setGeometry(point.x() + m_leftToolbar->width(),
			point.y(),
			w, h);
		m_pToolDock->setVisible(true);
		m_pToolDock->activateWindow();
		});
	connect(m_pFlowAc, &QAction::triggered, this, [this]() {
		auto point = this->mapToGlobal(m_leftToolbar->pos());
		int w = m_pFlowDock->width();
		int h = centerWidgetHeight();
		m_pFlowDock->setGeometry(point.x() + m_leftToolbar->width(),
			point.y(),
			w, h);
		m_pFlowDock->setVisible(true);
		m_pFlowDock->activateWindow();
		});
	connect(m_pLogAc, &QAction::triggered, this, [this]() {
		auto point = this->mapToGlobal(m_bottomToolbar->pos());
		int w = this->width();
		int h = m_pLogDock->height();
		m_pLogDock->setGeometry(point.x(),
			point.y() - h,
			w, h);
		m_pLogDock->setVisible(true);
		m_pLogDock->activateWindow();
		});
}

void MainWindow::initDock()
{
	this->setDockOptions(QMainWindow::AnimatedDocks | QMainWindow::AllowNestedDocks);
	m_pToolDock = new DockWidget("工具箱", this);
	m_pToolDock->setFont(QFont("Microsoft YaHei,23.5"));
	m_pFlowDock = new DockWidget("流程图", this);
	m_pLogDock = new DockWidget("运行日志", this);
	connect(m_pToolDock, &DockWidget::topLevelChanged, this, &MainWindow::slot_DoTopLevelChanged);
	connect(m_pFlowDock, &DockWidget::topLevelChanged, this, &MainWindow::slot_DoTopLevelChanged);
	connect(m_pLogDock, &DockWidget::topLevelChanged, this, &MainWindow::slot_DoTopLevelChanged);
	connect(m_pToolDock, &DockWidget::sigClose, this, &MainWindow::slot_DoDockClosed);
	connect(m_pFlowDock, &DockWidget::sigClose, this, &MainWindow::slot_DoDockClosed);
	connect(m_pLogDock, &DockWidget::sigClose, this, &MainWindow::slot_DoDockClosed);
	m_pToolDock->setMinimumWidth(205); //设置最小宽度
	m_pFlowDock->setMinimumWidth(269); //设置最小宽度    
	m_pLogDock->setMinimumHeight(150); //设置最小高度 	
	m_pToolDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	m_pFlowDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	m_pLogDock->setAllowedAreas(Qt::BottomDockWidgetArea);
	m_pToolDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	m_pFlowDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	m_pLogDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	this->addDockWidget(Qt::LeftDockWidgetArea, m_pToolDock);
	this->addDockWidget(Qt::LeftDockWidgetArea, m_pFlowDock);
	this->addDockWidget(Qt::BottomDockWidgetArea, m_pLogDock);
	this->splitDockWidget(m_pToolDock, m_pFlowDock, Qt::Horizontal);
	//设置DockWidget的初始化宽度
	resizeDocks({ m_pToolDock ,m_pFlowDock }, { 205, 269 }, Qt::Horizontal);
	QWidget* pCenterWidget = new QWidget(this);
	pCenterWidget->setProperty("type", "xblack");
	m_pBoxLayout = new QHBoxLayout(pCenterWidget);
	m_pBoxLayout->setContentsMargins(0, 0, 0, 0);
	m_pBoxLayout->setSpacing(0);
	this->setCentralWidget(pCenterWidget);
}

void MainWindow::initStatusBar()
{
	//状态栏
	QStatusBar* pStatusBar = statusBar(); //创建状态栏
	pStatusBar->setStyleSheet("background-color: rgb(240, 248, 226);");
	//CPU运行状态
	ShowCpuMemory* showCpuMemory = new ShowCpuMemory();
	//线程
	m_pthreadCpu = new QThread(this);
	showCpuMemory->moveToThread(m_pthreadCpu);
	QObject::connect(this, &MainWindow::sig_ToThreadCpu, showCpuMemory, &ShowCpuMemory::GetCpuMemory, Qt::AutoConnection);
	QObject::connect(m_pthreadCpu, &QThread::finished, showCpuMemory, &QObject::deleteLater, Qt::AutoConnection);
	m_pStatusInfoLabel = new QLabel(this);
	m_pStatusInfoLabel->setObjectName("view_cpu");
	m_pStatusInfoLabel->setProperty("type", "xblack");
	m_pStatusInfoLabel->setStyleSheet("background-color: rgb(240, 248, 226);");
	showCpuMemory->SetLab(m_pStatusInfoLabel);
	pStatusBar->addWidget(m_pStatusInfoLabel);
	m_pthreadCpu->start();
	emit sig_ToThreadCpu();
	//显示时间
	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
	timer->start(1000);
	m_pStatusTimeLabel = new QLabel(this);
	m_pStatusTimeLabel->setObjectName("view_time");
	m_pStatusTimeLabel->setProperty("type", "xblack");
	m_pStatusTimeLabel->setStyleSheet("background-color: rgb(240, 248, 226);");
	pStatusBar->addWidget(m_pStatusTimeLabel);
}

void MainWindow::timerUpdate()
{
	m_pStatusTimeLabel->setText("时间: " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	m_pStatusTimeLabel->update();
	//自动登出
	if (dataVar::auto_login_out == true)
	{
		QDateTime stopTime = QDateTime::currentDateTime();
		double elapsed = (double)dataVar::startTime.msecsTo(stopTime) / 60000;
		objSignOutTime = dataVar::fSystemSetUp->findChild<QSpinBox*>("spinSignOutTime");
		if ((int)elapsed >= objSignOutTime->value())
		{
			if (dataVar::login_state == 1)
			{
				dataVar::startTime = QDateTime();
				slot_LogoutBtnState();
				dataVar::login_state = 0;
				dataVar::admin_login_state = 0;
			}
		}
	}
}

void MainWindow::slot_DoTopLevelChanged(bool topLevel)
{
	QObject* obj = this->sender();
	DockWidget* dock = qobject_cast<DockWidget*>(obj);
	if (topLevel)//floating
	{
		dock->setVisible(false);
		//添加对应的ac
		if (dock == m_pToolDock)
		{
			m_leftToolbar->addAction(m_pToolAc);
			m_leftAcList.append(m_pToolAc);
		}
		else if (dock == m_pFlowDock)
		{
			m_leftToolbar->addAction(m_pFlowAc);
			m_leftAcList.append(m_pFlowAc);
		}
		else if (dock == m_pLogDock)
		{
			m_bottomToolbar->addAction(m_pLogAc);
			m_bottomAcList.append(m_pLogAc);
		}
	}
	else
	{
		//移除对应的ac
		if (dock == m_pToolDock)
		{
			m_leftToolbar->removeAction(m_pToolAc);
			m_leftAcList.removeOne(m_pToolAc);
		}
		else if (dock == m_pFlowDock)
		{
			m_leftToolbar->removeAction(m_pFlowAc);
			m_leftAcList.removeOne(m_pFlowAc);
		}
		else if (dock == m_pLogDock)
		{
			m_bottomToolbar->removeAction(m_pLogAc);
			m_bottomAcList.removeOne(m_pLogAc);
		}
		dock->setVisible(true);
	}
	m_leftToolbar->setVisible(m_leftAcList.length() > 0);
	m_bottomToolbar->setVisible(m_bottomAcList.length() > 0);
}

void MainWindow::slot_DoDockClosed()
{
	QObject* obj = this->sender();
	DockWidget* pDock = qobject_cast<DockWidget*>(obj);
	//移除对应的ac
	if (pDock == m_pToolDock)
	{
		m_leftToolbar->removeAction(m_pToolAc);
		m_leftAcList.removeOne(m_pToolAc);
	}
	else if (pDock == m_pFlowDock)
	{
		m_leftToolbar->removeAction(m_pFlowAc);
		m_leftAcList.removeOne(m_pFlowAc);
	}
	else if (pDock == m_pLogDock)
	{
		m_bottomToolbar->removeAction(m_pLogAc);
		m_bottomAcList.removeOne(m_pLogAc);
	}
	m_leftToolbar->setVisible(m_leftAcList.length() > 0);
	m_bottomToolbar->setVisible(m_bottomAcList.length() > 0);
}

//新建项目
void MainWindow::slot_DoCreateProject()
{
	if (dataVar::projectName == QString())
	{
		dataVar::projectName = "新建项目";
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("新建项目完成！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "新建项目完成！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}
	else
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("已存在项目，是否重新创建项目？");
		QMessageBox* msgBox = new QMessageBox(this);
		msgBox->setIcon(QMessageBox::Question);
		msgBox->setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox->setWindowTitle("警告");
		msgBox->setText("~~ 已存在项目，是否重新创建项目？ ~~");
		QPushButton* btn_sure = msgBox->addButton("确定", QMessageBox::ButtonRole::YesRole);	
		QPushButton* btn_cancel = msgBox->addButton("取消", QMessageBox::ButtonRole::NoRole);
		btn_sure->setStyleSheet("QPushButton{background-color:rgb(125,125,125);border:5px solid gray;font-size:15px;color:white;}");	
		btn_cancel->setStyleSheet("QPushButton{background-color:rgb(125,125,125);border:5px solid gray;font-size:15px;color:white;}");
		msgBox->setStyleSheet("color:black;font-size:16px;");
		if (!msgBox->exec())
		{
			slot_DelParam();
			QDockWidget* objDockName = dataVar::fProItemTab->findChild<QDockWidget*>("dockTabWidget");
			objDockName->setWindowTitle(QString());
			QTreeWidget* objTName = dataVar::fProItemTab->findChild<QTreeWidget*>("ProItemTreeWidget");
			objTName->setFixedHeight(28);
			dataVar::projectName = "新建项目";			
			msgBox->deleteLater();
			btn_sure->deleteLater();
			btn_cancel->deleteLater();
		}
		else
		{
			msgBox->deleteLater();
			btn_sure->deleteLater();
			btn_cancel->deleteLater();
		}				
	}
}

void MainWindow::slot_DelParam()
{
	QList<QString> comm_keys;
	//相机
	comm_keys.clear();
	comm_keys = gVariable::camera_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::camera_variable_link.value(key).mindvision_framebuffer_value != nullptr)
		{
			CameraStop(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
			//相机反初始化，释放资源
			CameraUnInit(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
			CameraAlignFree(gVariable::camera_variable_link.value(key).mindvision_framebuffer_value);
		}
	}
	//通用I/O
	comm_keys.clear();
	comm_keys = gVariable::generalio_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::generalio_variable_link.value(key).io_value != nullptr)
		{
			gVariable::generalio_variable_link.value(key).io_value->close();
			gVariable::generalio_variable_link.value(key).io_value->deleteLater();
			gVariable::GeneralIoVar.connect_state = 0;
			gVariable::GeneralIoVar.io_value = nullptr;
			gVariable::generalio_variable_link.insert(key, gVariable::GeneralIoVar);
		}
	}
	//PLC通信
	comm_keys.clear();
	comm_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::plccommunicate_variable_link.value(key).mit_value != nullptr)
		{
			gVariable::plccommunicate_variable_link.value(key).mit_value->close();
			gVariable::plccommunicate_variable_link.value(key).mit_value->deleteLater();
			gVariable::PlcCommunicateVar.connect_state = 0;
			gVariable::PlcCommunicateVar.mit_value = nullptr;
			gVariable::plccommunicate_variable_link.insert(key, gVariable::PlcCommunicateVar);
		}
	}
	//串口通信
	comm_keys.clear();
	comm_keys = gVariable::serialport_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::serialport_variable_link.value(key).serialport_value != nullptr)
		{
			gVariable::serialport_variable_link.value(key).serialport_value->close();
			gVariable::serialport_variable_link.value(key).serialport_value->deleteLater();
		}
	}
	//TCP/IP通信
	comm_keys.clear();
	comm_keys = gVariable::sockettcpserver_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::sockettcpserver_variable_link.value(key).server_value != nullptr)
		{
			gVariable::sockettcpserver_variable_link.value(key).server_value->close();
			gVariable::sockettcpserver_variable_link.value(key).server_value->deleteLater();
		}
	}
	comm_keys.clear();
	comm_keys = gVariable::sockettcpclient_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::sockettcpclient_variable_link.value(key).client_value != nullptr)
		{
			gVariable::sockettcpclient_variable_link.value(key).client_value->close();
			gVariable::sockettcpclient_variable_link.value(key).client_value->deleteLater();
			gVariable::SocketTcpClientVar.connect_state = 0;
			gVariable::SocketTcpClientVar.client_value = nullptr;
			gVariable::sockettcpclient_variable_link.insert(key, gVariable::SocketTcpClientVar);
		}
	}
	dataVar::fCameraSetUp->global_camera_content.clear();
	gVariable::camera_variable_link.clear();
	dataVar::fInstrumentation->global_io_content.clear();
	dataVar::fInstrumentation->global_plc_content.clear();
	dataVar::fInstrumentation->global_serialport_content.clear();
	dataVar::fInstrumentation->global_tcp_content.clear();
	gVariable::generalio_variable_link.clear();
	gVariable::plccommunicate_variable_link.clear();
	gVariable::serialport_variable_link.clear();
	gVariable::sockettcpserver_variable_link.clear();
	gVariable::sockettcpclient_variable_link.clear();
	gVariable::goto_variable_link.clear();
	gVariable::scriptedit_variable_link.clear();
	gVariable::global_variable_link.clear();
	//更新变量
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("获取图像");
				QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
				QConfig::ToolBase[key]->RunGotoToolLink();
				QConfig::ToolBase[key]->RunAllToolLink();
				QConfig::ToolBase[key]->RunScriptEditToolLink();
			}
		}
	}
	for (int m = 0; m < 20; m++)
	{
		if (QConfig::ToolBase[m] != nullptr)
		{			
			if (dataVar::dragD[m] != nullptr)
			{				
				dataVar::dragD[m] = nullptr;
			}
			disconnect(QConfig::ToolBase[m], &QToolBase::sig_SetGlobalValue, dataVar::fGlobalVariable, &frmGlobalVariable::slot_SetGlobalValue);
			disconnect(QConfig::ToolBase[m], &QToolBase::sig_Info, dataVar::fLog, &FrmLog::slot_Message_Info);
			disconnect(QConfig::ToolBase[m], &QToolBase::sig_Warn, dataVar::fLog, &FrmLog::slot_Message_Warn);
			disconnect(QConfig::ToolBase[m], &QToolBase::sig_Error, dataVar::fLog, &FrmLog::slot_Message_Error);
			QConfig::ToolBase[m]->m_FlowSortList.clear();
			QConfig::ToolBase[m]->m_Tools.clear();
			for (int i = 0; i < QConfig::ToolBase[m]->m_Tools.size(); i++)
			{
				QConfig::ToolBase[m]->m_Tools[i].PublicToolDlg->deleteLater();
			}			
			QConfig::ToolBase[m]->deleteLater();
			QConfig::ToolBase[m] = nullptr;
		}
	}
	if (dataVar::fProItemTab->TempDragListWidget_B1 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B1, dataVar::fProItemTab->TempDragListWidget_B1, &QtDragListWidget::SetItemSubText_B1);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B1, dataVar::fProItemTab->TempDragListWidget_B1, &QtDragListWidget::SetItemSubIcon_B1);
		delete dataVar::fProItemTab->TempDragListWidget_B1;
		dataVar::fProItemTab->TempDragListWidget_B1 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B2 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B2, dataVar::fProItemTab->TempDragListWidget_B2, &QtDragListWidget::SetItemSubText_B2);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B2, dataVar::fProItemTab->TempDragListWidget_B2, &QtDragListWidget::SetItemSubIcon_B2);
		delete dataVar::fProItemTab->TempDragListWidget_B2;
		dataVar::fProItemTab->TempDragListWidget_B2 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B3 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B3, dataVar::fProItemTab->TempDragListWidget_B3, &QtDragListWidget::SetItemSubText_B3);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B3, dataVar::fProItemTab->TempDragListWidget_B3, &QtDragListWidget::SetItemSubIcon_B3);
		delete dataVar::fProItemTab->TempDragListWidget_B3;
		dataVar::fProItemTab->TempDragListWidget_B3 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B4 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B4, dataVar::fProItemTab->TempDragListWidget_B4, &QtDragListWidget::SetItemSubText_B4);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B4, dataVar::fProItemTab->TempDragListWidget_B4, &QtDragListWidget::SetItemSubIcon_B4);
		delete dataVar::fProItemTab->TempDragListWidget_B4;
		dataVar::fProItemTab->TempDragListWidget_B4 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B5 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B5, dataVar::fProItemTab->TempDragListWidget_B5, &QtDragListWidget::SetItemSubText_B5);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B5, dataVar::fProItemTab->TempDragListWidget_B5, &QtDragListWidget::SetItemSubIcon_B5);
		delete dataVar::fProItemTab->TempDragListWidget_B5;
		dataVar::fProItemTab->TempDragListWidget_B5 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B6 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B6, dataVar::fProItemTab->TempDragListWidget_B6, &QtDragListWidget::SetItemSubText_B6);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B6, dataVar::fProItemTab->TempDragListWidget_B6, &QtDragListWidget::SetItemSubIcon_B6);
		delete dataVar::fProItemTab->TempDragListWidget_B6;
		dataVar::fProItemTab->TempDragListWidget_B6 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B7 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B7, dataVar::fProItemTab->TempDragListWidget_B7, &QtDragListWidget::SetItemSubText_B7);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B7, dataVar::fProItemTab->TempDragListWidget_B7, &QtDragListWidget::SetItemSubIcon_B7);
		delete dataVar::fProItemTab->TempDragListWidget_B7;
		dataVar::fProItemTab->TempDragListWidget_B7 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B8 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B8, dataVar::fProItemTab->TempDragListWidget_B8, &QtDragListWidget::SetItemSubText_B8);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B8, dataVar::fProItemTab->TempDragListWidget_B8, &QtDragListWidget::SetItemSubIcon_B8);
		delete dataVar::fProItemTab->TempDragListWidget_B8;
		dataVar::fProItemTab->TempDragListWidget_B8 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B9 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B9, dataVar::fProItemTab->TempDragListWidget_B9, &QtDragListWidget::SetItemSubText_B9);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B9, dataVar::fProItemTab->TempDragListWidget_B9, &QtDragListWidget::SetItemSubIcon_B9);
		delete dataVar::fProItemTab->TempDragListWidget_B9;
		dataVar::fProItemTab->TempDragListWidget_B9 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B10 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B10, dataVar::fProItemTab->TempDragListWidget_B10, &QtDragListWidget::SetItemSubText_B10);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B10, dataVar::fProItemTab->TempDragListWidget_B10, &QtDragListWidget::SetItemSubIcon_B10);
		delete dataVar::fProItemTab->TempDragListWidget_B10;
		dataVar::fProItemTab->TempDragListWidget_B10 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B11 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B11, dataVar::fProItemTab->TempDragListWidget_B11, &QtDragListWidget::SetItemSubText_B11);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B11, dataVar::fProItemTab->TempDragListWidget_B11, &QtDragListWidget::SetItemSubIcon_B11);
		delete dataVar::fProItemTab->TempDragListWidget_B11;
		dataVar::fProItemTab->TempDragListWidget_B11 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B12 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B12, dataVar::fProItemTab->TempDragListWidget_B12, &QtDragListWidget::SetItemSubText_B12);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B12, dataVar::fProItemTab->TempDragListWidget_B12, &QtDragListWidget::SetItemSubIcon_B12);
		delete dataVar::fProItemTab->TempDragListWidget_B12;
		dataVar::fProItemTab->TempDragListWidget_B12 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B13 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B13, dataVar::fProItemTab->TempDragListWidget_B13, &QtDragListWidget::SetItemSubText_B13);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B13, dataVar::fProItemTab->TempDragListWidget_B13, &QtDragListWidget::SetItemSubIcon_B13);
		delete dataVar::fProItemTab->TempDragListWidget_B13;
		dataVar::fProItemTab->TempDragListWidget_B13 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B14 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B14, dataVar::fProItemTab->TempDragListWidget_B14, &QtDragListWidget::SetItemSubText_B14);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B14, dataVar::fProItemTab->TempDragListWidget_B14, &QtDragListWidget::SetItemSubIcon_B14);
		delete dataVar::fProItemTab->TempDragListWidget_B14;
		dataVar::fProItemTab->TempDragListWidget_B14 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B15 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B15, dataVar::fProItemTab->TempDragListWidget_B15, &QtDragListWidget::SetItemSubText_B15);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B15, dataVar::fProItemTab->TempDragListWidget_B15, &QtDragListWidget::SetItemSubIcon_B15);
		delete dataVar::fProItemTab->TempDragListWidget_B15;
		dataVar::fProItemTab->TempDragListWidget_B15 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B16 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B16, dataVar::fProItemTab->TempDragListWidget_B16, &QtDragListWidget::SetItemSubText_B16);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B16, dataVar::fProItemTab->TempDragListWidget_B16, &QtDragListWidget::SetItemSubIcon_B16);
		delete dataVar::fProItemTab->TempDragListWidget_B16;
		dataVar::fProItemTab->TempDragListWidget_B16 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B17 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B17, dataVar::fProItemTab->TempDragListWidget_B17, &QtDragListWidget::SetItemSubText_B17);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B17, dataVar::fProItemTab->TempDragListWidget_B17, &QtDragListWidget::SetItemSubIcon_B17);
		delete dataVar::fProItemTab->TempDragListWidget_B17;
		dataVar::fProItemTab->TempDragListWidget_B17 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B18 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B18, dataVar::fProItemTab->TempDragListWidget_B18, &QtDragListWidget::SetItemSubText_B18);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B18, dataVar::fProItemTab->TempDragListWidget_B18, &QtDragListWidget::SetItemSubIcon_B18);
		delete dataVar::fProItemTab->TempDragListWidget_B18;
		dataVar::fProItemTab->TempDragListWidget_B18 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B19 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B19, dataVar::fProItemTab->TempDragListWidget_B19, &QtDragListWidget::SetItemSubText_B19);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B19, dataVar::fProItemTab->TempDragListWidget_B19, &QtDragListWidget::SetItemSubIcon_B19);
		delete dataVar::fProItemTab->TempDragListWidget_B19;
		dataVar::fProItemTab->TempDragListWidget_B19 = nullptr;
	}
	if (dataVar::fProItemTab->TempDragListWidget_B20 != nullptr)
	{
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_TextShow_B20, dataVar::fProItemTab->TempDragListWidget_B20, &QtDragListWidget::SetItemSubText_B20);
		disconnect(dataVar::fProItemTab, &frmProItemTab::sig_IconShow_B20, dataVar::fProItemTab->TempDragListWidget_B20, &QtDragListWidget::SetItemSubIcon_B20);
		delete dataVar::fProItemTab->TempDragListWidget_B20;
		dataVar::fProItemTab->TempDragListWidget_B20 = nullptr;
	}
	dataVar::fProItemTab->m_pro_value.clear();
	dataVar::fProItemTab->FlowTabMap.clear();
	dataVar::FlowProMap.clear();
	dataVar::all_link_process.clear();
	QTreeWidget* objTreeName = dataVar::fProItemTab->findChild<QTreeWidget*>("ProItemTreeWidget");
	QTreeWidgetItemIterator it(objTreeName);  //遍历treeWidget		
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		qDeleteAll((*it)->takeChildren());
	}
	QTabWidget* objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
	objTabName->clear();
	QTableWidget* objCameraName = dataVar::fCameraSetUp->findChild<QTableWidget*>("tableWidget");
	for (int i = objCameraName->rowCount() - 1; i >= 0; --i)
	{
		objCameraName->removeRow(i);
	}
	QTableWidget* objInstrumentationName = dataVar::fInstrumentation->findChild<QTableWidget*>("tableWidget");
	for (int i = objInstrumentationName->rowCount() - 1; i >= 0; --i)
	{
		objInstrumentationName->removeRow(i);
	}
	QTableWidget* objGlobalName = dataVar::fGlobalVariable->findChild<QTableWidget*>("tableWidget");
	for (int i = objGlobalName->rowCount() - 1; i >= 0; --i)
	{
		objGlobalName->removeRow(i);
	}
}

//打开项目
void MainWindow::slot_DoOpenProject()
{
	QString file_name = QFileDialog::getOpenFileName(this,
		tr("打开项目"), dataVar::path_PF, "*.cfg");
	if (!file_name.isNull())
	{
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("正在打开项目，请稍后...");
		QApplication::processEvents();
		slot_DelParam();
		//打开项目
		QFileInfo flieInfo(file_name);
		dataVar::projectName = flieInfo.baseName();
		dataVar::qtWidgetsSaveLoad->setFilenameWithPath(file_name);		
		dataVar::qtWidgetsSaveLoad->loadFromFileFirst();
		parents.reserve(100);
		parents.clear();
		parents.append(dataVar::fProcessSetUp);
		parents.append(dataVar::fSystemSetUp);
		parents.append(dataVar::fImageLayout);
		parents.append(dataVar::fGlobalVariable);
		parents.append(dataVar::fCameraSetUp);
		parents.append(dataVar::fInstrumentation);
		for (int m = 0; m < 20; m++)
		{
			if (QConfig::ToolBase[m] != nullptr)
			{
				for (int n = 0; n < QConfig::ToolBase[m]->m_Tools.size(); n++)
				{
					parents.append(QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg);
				}
			}
		}
		dataVar::qtWidgetsSaveLoad->loadFromFile(parents);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("打开项目完成！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "打开项目完成！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}
}

//初始化时打开项目
void MainWindow::slot_OpenProjectParam()
{
	QFileInfo file(dataVar::path_PF + "init.xml");
	if (file.exists() == false)
	{
		return;
	}
	else
	{
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_PF + "init.xml", "Parameter1", dataVar::projectName);
	}
	QFileInfo file_cfg(dataVar::path_PF + dataVar::projectName + ".cfg");
	if (file_cfg.exists() == false)
	{
		return;
	}
	else
	{
		dataVar::qtWidgetsSaveLoad->setFilenameWithPath(dataVar::path_PF + dataVar::projectName + ".cfg");
		dataVar::qtWidgetsSaveLoad->loadFromFileFirst();
		parents.reserve(100);
		parents.clear();
		parents.append(dataVar::fProcessSetUp);
		parents.append(dataVar::fSystemSetUp);
		parents.append(dataVar::fImageLayout);
		parents.append(dataVar::fGlobalVariable);
		parents.append(dataVar::fCameraSetUp);
		parents.append(dataVar::fInstrumentation);
		for (int m = 0; m < 20; m++)
		{
			if (QConfig::ToolBase[m] != nullptr)
			{
				for (int n = 0; n < QConfig::ToolBase[m]->m_Tools.size(); n++)
				{
					parents.append(QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg);
				}
			}
		}
		dataVar::qtWidgetsSaveLoad->loadFromFile(parents);
		if (dataVar::process_self_start == true)
		{
			m_pRunContinueAc->triggered();
		}
	}
}

//保存项目
void MainWindow::slot_DoSaveProject()
{
	if (dataVar::projectName == QString())
	{
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("保存项目时，请先新建项目！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请先新建项目！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	//保存项目
	slot_SaveProjectParam(1);
	emit dataVar::fProItemTab->sig_InfoClick();
	emit dataVar::fProItemTab->sig_Log("项目保存完成！");
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "项目保存完成！");
	msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
	msgBox.exec();
}

//关闭时保存项目
void MainWindow::slot_SaveProjectParam(int mode)
{
	if (dataVar::projectName == QString())
	{
		return;
	}
	if (mode == 1)
	{
		QString file_name = dataVar::path_PF + dataVar::projectName + ".cfg";
		dataVar::qtWidgetsSaveLoad->setFilenameWithPath(file_name);
	}	
	parents.reserve(100);
	parents.clear();
	parents.append(dataVar::fProcessSetUp);
	parents.append(dataVar::fSystemSetUp);
	parents.append(dataVar::fImageLayout);
	parents.append(dataVar::fGlobalVariable);
	parents.append(dataVar::fCameraSetUp);
	parents.append(dataVar::fInstrumentation);
	dataVar::qtWidgetsSaveLoad->dataImageSourceList.clear();
	dataVar::qtWidgetsSaveLoad->dataImageSourceList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataCropImageList.clear();
	dataVar::qtWidgetsSaveLoad->dataCropImageList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataImageMorphologyList.clear();
	dataVar::qtWidgetsSaveLoad->dataImageMorphologyList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataSkeletonList.clear();
	dataVar::qtWidgetsSaveLoad->dataSkeletonList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataBlobDetectorList.clear();
	dataVar::qtWidgetsSaveLoad->dataBlobDetectorList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataSelectShapeList.clear();
	dataVar::qtWidgetsSaveLoad->dataSelectShapeList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataImageViewList.clear();
	dataVar::qtWidgetsSaveLoad->dataImageViewList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataColorIdentifyList.clear();
	dataVar::qtWidgetsSaveLoad->dataColorIdentifyList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataClassifierList.clear();
	dataVar::qtWidgetsSaveLoad->dataClassifierList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataCamShiftTrackList.clear();
	dataVar::qtWidgetsSaveLoad->dataCamShiftTrackList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataTemplateMatchList.clear();
	dataVar::qtWidgetsSaveLoad->dataTemplateMatchList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataShapeMatchList.clear();
	dataVar::qtWidgetsSaveLoad->dataShapeMatchList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataMeasureCalibrationList.clear();
	dataVar::qtWidgetsSaveLoad->dataMeasureCalibrationList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataGetContourPointsList.clear();
	dataVar::qtWidgetsSaveLoad->dataGetContourPointsList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataFindCircleList.clear();
	dataVar::qtWidgetsSaveLoad->dataFindCircleList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataRoundedCornersList.clear();
	dataVar::qtWidgetsSaveLoad->dataRoundedCornersList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataFindLineList.clear();
	dataVar::qtWidgetsSaveLoad->dataFindLineList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataEdgeWidthMeasureList.clear();
	dataVar::qtWidgetsSaveLoad->dataEdgeWidthMeasureList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataExportCsvList.clear();
	dataVar::qtWidgetsSaveLoad->dataExportCsvList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataExtensionLibraryList.clear();
	dataVar::qtWidgetsSaveLoad->dataExtensionLibraryList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataLogicGotoList.clear();
	dataVar::qtWidgetsSaveLoad->dataLogicGotoList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataGeneralIoList.clear();
	dataVar::qtWidgetsSaveLoad->dataGeneralIoList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataPlcCommunicateList.clear();
	dataVar::qtWidgetsSaveLoad->dataPlcCommunicateList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataSerialPortList.clear();
	dataVar::qtWidgetsSaveLoad->dataSerialPortList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataSocketTcpClientList.clear();
	dataVar::qtWidgetsSaveLoad->dataSocketTcpClientList.resize(20);
	dataVar::qtWidgetsSaveLoad->dataSocketTcpServerList.clear();
	dataVar::qtWidgetsSaveLoad->dataSocketTcpServerList.resize(20);
	int tool_count_buf = -1;
	for (int m = 0; m < 20; m++)
	{
		if (QConfig::ToolBase[m] != nullptr && QConfig::ToolBase[m]->m_Tools.size() != 0)
		{
			++tool_count_buf;
			QVector<QString> flowProItemList;
			switch (m) {
			case 0:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B1->GetAllItemList_B1();
				break;
			case 1:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B2->GetAllItemList_B2();
				break;
			case 2:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B3->GetAllItemList_B3();
				break;
			case 3:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B4->GetAllItemList_B4();
				break;
			case 4:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B5->GetAllItemList_B5();
				break;
			case 5:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B6->GetAllItemList_B6();
				break;
			case 6:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B7->GetAllItemList_B7();
				break;
			case 7:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B8->GetAllItemList_B8();
				break;
			case 8:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B9->GetAllItemList_B9();
				break;
			case 9:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B10->GetAllItemList_B10();
				break;
			case 10:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B11->GetAllItemList_B11();
				break;
			case 11:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B12->GetAllItemList_B12();
				break;
			case 12:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B13->GetAllItemList_B13();
				break;
			case 13:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B14->GetAllItemList_B14();
				break;
			case 14:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B15->GetAllItemList_B15();
				break;
			case 15:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B16->GetAllItemList_B16();
				break;
			case 16:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B17->GetAllItemList_B17();
				break;
			case 17:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B18->GetAllItemList_B18();
				break;
			case 18:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B19->GetAllItemList_B19();
				break;
			case 19:
				flowProItemList = dataVar::fProItemTab->TempDragListWidget_B20->GetAllItemList_B20();
				break;
			}
			for (int p = 0; p < flowProItemList.size(); p++)
			{
				for (int n = 0; n < QConfig::ToolBase[m]->m_Tools.size(); n++)
				{
					if (flowProItemList[p] == QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->objectName())
					{
						parents.append(QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg);
						//序列化各工具的特定参数						
						int str_count = 0;  //提取不含数字字符串
						for (int k = 0; k < QConfig::ToolBase[m]->m_Tools[n].PublicToolName.length(); k++)
						{
							if (!(QConfig::ToolBase[m]->m_Tools[n].PublicToolName[k] > '0' && QConfig::ToolBase[m]->m_Tools[n].PublicToolName[k] < '9'))
							{
								++str_count;
							}
						}
						QString str_name_buf = QConfig::ToolBase[m]->m_Tools[n].PublicToolName.mid(0, str_count);
						if (str_name_buf == "获取图像")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "裁切图像")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "预处理")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "图像细化")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "斑点分析")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "轮廓特征选择")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "图像显示")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "颜色识别")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "分类器")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "目标跟踪")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "灰度匹配")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "形状匹配")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "测量标定")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "获取边界点")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "寻找圆")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "查找圆缺角")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "寻找直线")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "边缘宽度测量")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "导出CSV")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "扩展库")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "跳转语句")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam2(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "通用I/O")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam3(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "PLC通信")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam3(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "串口通信")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam3(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "TCP/IP客户端")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam3(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "TCP/IP服务器")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam3(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "YoloV13")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
						}
						else if (str_name_buf == "OCR")
						{
							QVariant var = QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitGetToolData();
							dataVar::qtWidgetsSaveLoad->saveToolParam(tool_count_buf, str_name_buf, var);
							}
						break;
					}
				}
			}
		}
	}
	dataVar::qtWidgetsSaveLoad->saveToFile(parents);
	//保存文件路径名称
	QString init_file_name;
	if (mode == 1)
	{
		init_file_name = dataVar::path_PF + "init.xml";
		QFileInfo file(init_file_name);
		if (file.exists() == false)
		{
			dataVar::xml.CreateXml5(dataVar::soft_key, init_file_name, dataVar::projectName, "", "", "", "");
		}
		vector<string> parameter, value;
		parameter.push_back("Parameter1");
		parameter.push_back("Parameter2");
		parameter.push_back("Parameter3");
		parameter.push_back("Parameter4");
		parameter.push_back("Parameter5");
		value.push_back(dataVar::projectName.toStdString());
		value.push_back("");
		value.push_back("");
		value.push_back("");
		value.push_back("");
		dataVar::xml.ModifyXml(dataVar::soft_key, init_file_name, parameter, value);
	}	
}

//项目另存为
void MainWindow::slot_DoSaveAsProject()
{
	if (dataVar::projectName == QString())
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("项目另存为时，请先新建项目！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请先新建项目！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("项目另存为"), dataVar::path_PF, tr("Config Files (*.cfg)"));
	if (!fileName.isNull())
	{
		dataVar::qtWidgetsSaveLoad->setFilenameWithPath(fileName);
		//保存项目		
		slot_SaveProjectParam(2);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("项目保存完成！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "项目保存完成！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}
}

void MainWindow::SetToolDockSize(QDockWidget* dock, const QSize size) const
{
	if (size.width() >= 0)
	{
		int nWidth = dock->width();
		if (nWidth < size.width())
			dock->setMinimumWidth(size.width());
		else
			dock->setMaximumWidth(size.width());
	}
	if (size.height() >= 0)
	{
		int nHeight = dock->height();
		if (nHeight < size.height())
			dock->setMinimumHeight(size.height());
		else
			dock->setMaximumHeight(size.height());
	}
	QTimer::singleShot(10, this, SLOT(slot_RestoreToolDock()));
}

void MainWindow::slot_RestoreToolDock()
{
	m_pToolDock->setMaximumSize(QSize(5000, 5000));
	m_pToolDock->setMinimumSize(QSize(205, 205));
}

void MainWindow::SetFlowDockSize(QDockWidget* dock, const QSize size) const
{
	if (size.width() >= 0)
	{
		int nWidth = dock->width();
		if (nWidth < size.width())
			dock->setMinimumWidth(size.width());
		else
			dock->setMaximumWidth(size.width());
	}
	if (size.height() >= 0)
	{
		int nHeight = dock->height();
		if (nHeight < size.height())
			dock->setMinimumHeight(size.height());
		else
			dock->setMaximumHeight(size.height());
	}
	QTimer::singleShot(30, this, SLOT(slot_RestoreFlowDock()));
}

void MainWindow::slot_RestoreFlowDock()
{
	m_pFlowDock->setMaximumSize(QSize(5000, 5000));
	m_pFlowDock->setMinimumSize(QSize(269, 269));
}

void MainWindow::SetLogDockSize(QDockWidget* dock, const QSize size) const
{
	if (size.width() >= 0)
	{
		int nWidth = dock->width();
		if (nWidth < size.width())
			dock->setMinimumWidth(size.width());
		else
			dock->setMaximumWidth(size.width());
	}
	if (size.height() >= 0)
	{
		int nHeight = dock->height();
		if (nHeight < size.height())
			dock->setMinimumHeight(size.height());
		else
			dock->setMaximumHeight(size.height());
	}
	QTimer::singleShot(50, this, SLOT(slot_RestoreLogDock()));
}

void MainWindow::slot_RestoreLogDock()
{
	m_pLogDock->setMaximumSize(QSize(5000, 5000));
	m_pLogDock->setMinimumSize(QSize(150, 150));
}

//初始化布局
void MainWindow::slot_InitLayout()
{
	try
	{
		QFileInfo file(dataVar::path_P + "layout.xml");
		if (!file.exists())
		{
			dataVar::xml.CreateXml9(dataVar::soft_key, dataVar::path_P + "layout.xml", "205", "true", "false", "269", "true", "false", "150", "true", "false");
		}
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter1", tool_width);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter2", tool_visible);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter3", tool_float);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter4", flow_width);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter5", flow_visible);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter6", flow_float);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter7", log_height);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter8", log_visible);
		dataVar::xml.ReadXml(dataVar::soft_key, dataVar::path_P + "layout.xml", "Parameter9", log_float);
		//工具箱				
		SetToolDockSize(m_pToolDock, QSize(tool_width.toInt(), m_pToolDock->height()));
		QVariant tool_visible_buf = tool_visible;
		m_pToolDock->setVisible(tool_visible_buf.toBool());
		QVariant tool_float_buf = tool_float;
		m_pToolDock->setFloating(tool_float_buf.toBool());
		//流程图				
		SetFlowDockSize(m_pFlowDock, QSize(flow_width.toInt(), m_pFlowDock->height()));
		QVariant flow_visible_buf = flow_visible;
		m_pFlowDock->setVisible(flow_visible_buf.toBool());
		QVariant flow_float_buf = flow_float;
		m_pFlowDock->setFloating(flow_float_buf.toBool());
		//运行日志		
		SetLogDockSize(m_pLogDock, QSize(m_pLogDock->width(), log_height.toInt()));
		QVariant log_visible_buf = log_visible;
		m_pLogDock->setVisible(log_visible_buf.toBool());
		QVariant log_float_buf = log_float;
		m_pLogDock->setFloating(log_float_buf.toBool());
	}
	catch (...) {}
}

//默认布局
void MainWindow::slot_DefaultLayout()
{
	try
	{
		QFileInfo file(dataVar::path_P + "layout.xml");
		if (!file.exists())
		{
			dataVar::xml.CreateXml9(dataVar::soft_key, dataVar::path_P + "layout.xml", "205", "true", "false", "269", "true", "false", "150", "true", "false");
		}
		else
		{
			vector<string> parameter, value;
			parameter.push_back("Parameter1");
			parameter.push_back("Parameter2");
			parameter.push_back("Parameter3");
			parameter.push_back("Parameter4");
			parameter.push_back("Parameter5");
			parameter.push_back("Parameter6");
			parameter.push_back("Parameter7");
			parameter.push_back("Parameter8");
			parameter.push_back("Parameter9");
			value.push_back("205");
			value.push_back("true");
			value.push_back("false");
			value.push_back("269");
			value.push_back("true");
			value.push_back("false");
			value.push_back("150");
			value.push_back("true");
			value.push_back("false");
			dataVar::xml.ModifyXml(dataVar::soft_key, dataVar::path_P + "layout.xml", parameter, value);
		}
		//工具箱
		SetToolDockSize(m_pToolDock, QSize(205, m_pToolDock->height()));
		m_pToolDock->setVisible(true);
		m_pToolDock->setFloating(false);
		//流程图
		SetFlowDockSize(m_pFlowDock, QSize(269, m_pFlowDock->height()));
		m_pFlowDock->setVisible(true);
		m_pFlowDock->setFloating(false);
		//运行日志
		SetLogDockSize(m_pLogDock, QSize(m_pLogDock->width(), 150));
		m_pLogDock->setVisible(true);
		m_pLogDock->setFloating(false);
	}
	catch (...) {}
}

//保存布局
void MainWindow::slot_SaveLayout()
{
	try
	{
		QFileInfo file(dataVar::path_P + "layout.xml");
		if (!file.exists())
		{
			dataVar::xml.CreateXml9(dataVar::soft_key, dataVar::path_P + "layout.xml", "205", "true", "false", "269", "true", "false", "150", "true", "false");
		}
		vector<string> parameter, value;
		parameter.push_back("Parameter1");
		parameter.push_back("Parameter2");
		parameter.push_back("Parameter3");
		parameter.push_back("Parameter4");
		parameter.push_back("Parameter5");
		parameter.push_back("Parameter6");
		parameter.push_back("Parameter7");
		parameter.push_back("Parameter8");
		parameter.push_back("Parameter9");
		value.push_back(std::to_string(m_pToolDock->width()));
		bool tool_v = m_pToolDock->isVisible();
		value.push_back(QVariant(tool_v).toString().toStdString());
		bool tool_f = m_pToolDock->isFloating();
		value.push_back(QVariant(tool_f).toString().toStdString());
		value.push_back(std::to_string(m_pFlowDock->width()));
		bool flow_v = m_pFlowDock->isVisible();
		value.push_back(QVariant(flow_v).toString().toStdString());
		bool flow_f = m_pFlowDock->isFloating();
		value.push_back(QVariant(flow_f).toString().toStdString());
		value.push_back(std::to_string(m_pLogDock->height()));
		bool log_v = m_pLogDock->isVisible();
		value.push_back(QVariant(log_v).toString().toStdString());
		bool log_f = m_pLogDock->isFloating();
		value.push_back(QVariant(log_f).toString().toStdString());
		dataVar::xml.ModifyXml(dataVar::soft_key, dataVar::path_P + "layout.xml", parameter, value);
	}
	catch (...) {}
}

//所有连续执行状态
void MainWindow::on_m_pRunContinueAc_triggered()
{
	permisMenu->setEnabled(false);
	m_pLoginAc->setEnabled(false);
	m_pRunOnceAc->setEnabled(false);
	m_pRunContinueAc->setEnabled(false);
	fileMenu->setEnabled(false);
	setMenu->setEnabled(false);
	m_pCreateProAc->setEnabled(false);
	m_pOpenProAc->setEnabled(false);
	m_pSaveProAc->setEnabled(false);
	m_pVarAc->setEnabled(false);
	m_pNetworkAc->setEnabled(false);
	m_pAcqAc->setEnabled(false);
	emit sig_Logout();
}

//所有停止状态
void MainWindow::slot_AllCycleStop()
{
	permisMenu->setEnabled(true);
	m_pLoginAc->setEnabled(true);
	m_pOpenProAc->setEnabled(true);
	m_pRunOnceAc->setEnabled(true);
	m_pRunContinueAc->setEnabled(true);
	if (dataVar::login_state == 1)
	{
		fileMenu->setEnabled(true);
		setMenu->setEnabled(true);
		m_pCreateProAc->setEnabled(true);
		m_pSaveProAc->setEnabled(true);
		m_pVarAc->setEnabled(true);
		m_pNetworkAc->setEnabled(true);
		m_pAcqAc->setEnabled(true);
		emit sig_Login();
	}
}

//仪器通讯画面
void MainWindow::slot_Instrumentation()
{
	dataVar::fInstrumentation->exec();
}

//相机设置画面
void MainWindow::slot_DoCameraSetUp()
{
	dataVar::fCameraSetUp->exec();
}

//全局变量画面
void MainWindow::slot_DoGlobalVariable()
{
	dataVar::fGlobalVariable->exec();
}

//系统参数画面
void MainWindow::slot_DoSystemSetUp()
{
	dataVar::fSystemSetUp->exec();
}

//图像布局画面
void MainWindow::slot_DoImageLayout()
{
	dataVar::fImageLayout->exec();
}

//登录画面
void MainWindow::slot_DoLogin()
{
	emit sig_LoginSignal();
}

//权限管理画面
void MainWindow::slot_PermisSet()
{
	emit sig_PermisSet();
}

//关于画面
void MainWindow::slot_DoAbout()
{
	emit sig_AboutSignal();
}

//登入按钮状态
void MainWindow::slot_LoginBtnState()
{
	fileMenu->setEnabled(true);
	setMenu->setEnabled(true);
	m_pCreateProAc->setEnabled(true);
	m_pSaveProAc->setEnabled(true);
	m_pVarAc->setEnabled(true);
	m_pNetworkAc->setEnabled(true);
	m_pAcqAc->setEnabled(true);
	emit sig_Login();
}

//登出按钮状态
void MainWindow::slot_LogoutBtnState()
{
	fileMenu->setEnabled(false);
	setMenu->setEnabled(false);
	m_pCreateProAc->setEnabled(false);
	m_pSaveProAc->setEnabled(false);
	m_pVarAc->setEnabled(false);
	m_pNetworkAc->setEnabled(false);
	m_pAcqAc->setEnabled(false);
	emit sig_Logout();
}

//连续执行状态
void MainWindow::slot_CycleRun()
{
	permisMenu->setEnabled(false);
	m_pLoginAc->setEnabled(false);
	m_pRunOnceAc->setEnabled(false);
	m_pRunContinueAc->setEnabled(false);
	m_pStopAc->setEnabled(false);
	fileMenu->setEnabled(false);
	setMenu->setEnabled(false);
	m_pCreateProAc->setEnabled(false);
	m_pOpenProAc->setEnabled(false);
	m_pSaveProAc->setEnabled(false);
	m_pVarAc->setEnabled(false);
	m_pNetworkAc->setEnabled(false);
	m_pAcqAc->setEnabled(false);
	emit sig_Logout();
	emit sig_ManualRun();
}

//停止状态
void MainWindow::slot_CycleStop()
{
	permisMenu->setEnabled(true);
	m_pLoginAc->setEnabled(true);
	m_pOpenProAc->setEnabled(true);
	m_pRunOnceAc->setEnabled(true);
	m_pRunContinueAc->setEnabled(true);
	m_pStopAc->setEnabled(true);
	if (dataVar::login_state == 1)
	{
		fileMenu->setEnabled(true);
		setMenu->setEnabled(true);
		m_pCreateProAc->setEnabled(true);
		m_pSaveProAc->setEnabled(true);
		m_pVarAc->setEnabled(true);
		m_pNetworkAc->setEnabled(true);
		m_pAcqAc->setEnabled(true);
		emit sig_Login();
	}
	emit sig_ManualStop();
}
