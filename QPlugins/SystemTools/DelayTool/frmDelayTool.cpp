#include "frmDelayTool.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QThread>
#include <QElapsedTimer>

frmDelayTool::frmDelayTool(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/delay.png"));
	//初始化标题栏
	initTitleBar();	
	//选项按钮
	btnGroupRadio = new QButtonGroup(this);
	btnGroupRadio->addButton(ui.radioThread, 0);
	connect(ui.radioThread, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
	ui.radioThread->click();
	btnGroupRadio->addButton(ui.radioTime, 1);
	connect(ui.radioTime, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
}

frmDelayTool::~frmDelayTool()
{
	this->deleteLater();
}

void frmDelayTool::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/delay.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmDelayTool::paintEvent(QPaintEvent* event)
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

void frmDelayTool::onButtonCloseClicked()
{
	this->close();
}

void frmDelayTool::onRadioClick(bool state)
{
	switch (btnGroupRadio->checkedId())
	{
	case 0:
		radio_index = 0;
		break;
	case 1:
		radio_index = 1;
		break;	
	}
}

int frmDelayTool::Execute(const QString toolname)
{		
	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
	{
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
			//工具在工具数组中的索引
			tool_index = i;
		}
	}
	int result = RunToolPro();
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmDelayTool::RunToolPro()
{
	try
	{
		switch (radio_index)
		{
		case 0:			
			QThread::msleep(ui.spinDelayTime->value());
			break;
		case 1:			
			QElapsedTimer t;
			t.start();
			while (t.elapsed() < ui.spinDelayTime->value());
			break;
		}
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmDelayTool::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmDelayTool::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	try
	{
		gvariable.global_variable_link = g_variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmDelayTool::on_btnExecute_clicked()
{		
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.btnExecute->setEnabled(true);
}
