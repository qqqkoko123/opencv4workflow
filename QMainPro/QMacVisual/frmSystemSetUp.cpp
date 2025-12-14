#include "frmSystemSetUp.h"
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include "datavar.h"
using namespace std;

frmSystemSetUp::frmSystemSetUp(QWidget*parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);	
	this->setWindowIcon(QIcon(":/res/ico/set.png"));	
	connect(ui.checkProgramSelfStart, SIGNAL(toggled(bool)), this, SLOT(slot_ProgramSelfStart(bool)));
	connect(ui.checkProcessSelfStart, SIGNAL(toggled(bool)), this, SLOT(slot_ProcessSelfStart(bool)));
	connect(ui.checkSignOutTime, SIGNAL(toggled(bool)), this, SLOT(slot_SignOutTime(bool)));
	//初始化标题栏
	initTitleBar();		
}

frmSystemSetUp::~frmSystemSetUp()	
{
	this->deleteLater();
}

void frmSystemSetUp::initTitleBar()
{	
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/set.png");
	m_titleBar->setTitleContent("系统参数");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmSystemSetUp::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor("#bcc2bc")));
	return QWidget::paintEvent(event);
}

//设置程序自启动appPath程序路径
void frmSystemSetUp::SetProcessAutoRunSelf(const QString& appPath)
{
	//注册表路径需要使用双反斜杠，如果是32位系统，要使用QSettings::Registry32Format
	QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::Registry64Format);
	//以程序名称作为注册表中的键，根据键获取对应的值(程序路径)
	QFileInfo fInfo(appPath);
	QString name = fInfo.baseName();
	QString path = settings.value(name).toString();
	QString newPath = QDir::toNativeSeparators(appPath);
	if (path != newPath)
	{
		settings.setValue(name, newPath);
	}
}

//移除程序自启动appPath程序路径
void frmSystemSetUp::RemoveProcessAutoRunSelf(const QString& appPath)
{
	//注册表路径需要使用双反斜杠，如果是32位系统，要使用QSettings::Registry32Format
	QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::Registry64Format);
	//以程序名称作为注册表中的键，根据键获取对应的值(程序路径)
	QFileInfo fInfo(appPath);
	QString name = fInfo.baseName();
	settings.remove(name);
}

void frmSystemSetUp::slot_ProgramSelfStart(bool state)
{
	if (state == true)
	{
		SetProcessAutoRunSelf(qApp->applicationFilePath());
	}
	else
	{
		RemoveProcessAutoRunSelf(qApp->applicationFilePath());
	}
}

void frmSystemSetUp::slot_ProcessSelfStart(bool state)
{
	if (state == true)
	{
		dataVar::process_self_start = true;
	}
	else
	{
		dataVar::process_self_start = false;
	}
}

void frmSystemSetUp::slot_SignOutTime(bool state)
{
	if (state == true)
	{
		dataVar::auto_login_out = true;
	}
	else
	{
		dataVar::auto_login_out = false;
	}
}
