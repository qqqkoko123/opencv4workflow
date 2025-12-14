#include "frmGeneralIo.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>

frmGeneralIo::frmGeneralIo(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/general_io.png"));
	//初始化标题栏
	initTitleBar();	
}

frmGeneralIo::~frmGeneralIo()
{
	this->deleteLater();
}

void frmGeneralIo::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/general_io.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmGeneralIo::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
	return QWidget::paintEvent(event);
}

void frmGeneralIo::onButtonCloseClicked()
{
	this->close();
}

int frmGeneralIo::Execute(const QString toolname)
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
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	return 0;
}

int frmGeneralIo::RunToolPro()
{
	try
	{
		InPutIoX.clear();		
		//输入点
		if (ui.checkInPutX0->isChecked() == true)  //输入点1
		{
			bool state_X0;
			InPutIoX.insert(0, state_X0);
		}
		else
		{
			InPutIoX.insert(0, false);
		}
		if (ui.checkInPutX1->isChecked() == true)  //输入点2
		{
			bool state_X1;
			InPutIoX.insert(1, state_X1);
		}
		else
		{
			InPutIoX.insert(1, false);
		}
		if (ui.checkInPutX2->isChecked() == true)  //输入点3
		{
			bool state_X2;
			InPutIoX.insert(2, state_X2);
		}
		else
		{
			InPutIoX.insert(2, false);
		}
		if (ui.checkInPutX3->isChecked() == true)  //输入点4
		{
			bool state_X3;
			InPutIoX.insert(3, state_X3);
		}
		else
		{
			InPutIoX.insert(3, false);
		}
		if (ui.checkInPutX4->isChecked() == true)  //输入点5
		{
			bool state_X4;
			InPutIoX.insert(4, state_X4);
		}
		else
		{
			InPutIoX.insert(4, false);
		}
		if (ui.checkInPutX5->isChecked() == true)  //输入点6
		{
			bool state_X5;
			InPutIoX.insert(5, state_X5);
		}
		else
		{
			InPutIoX.insert(5, false);
		}
		if (ui.checkInPutX6->isChecked() == true)  //输入点7
		{
			bool state_X6;
			InPutIoX.insert(6, state_X6);
		}
		else
		{
			InPutIoX.insert(6, false);
		}
		if (ui.checkInPutX7->isChecked() == true)  //输入点8
		{
			bool state_X7;
			InPutIoX.insert(7, state_X7);
		}
		else
		{
			InPutIoX.insert(7, false);
		}
		//输出点
		if (ui.checkOutPutY0->isChecked() == true)  //输出点1
		{
			
		}
		if (ui.checkOutPutY1->isChecked() == true)  //输出点2
		{

		}
		if (ui.checkOutPutY2->isChecked() == true)  //输出点3
		{

		}
		if (ui.checkOutPutY3->isChecked() == true)  //输出点4
		{

		}
		if (ui.checkOutPutY4->isChecked() == true)  //输出点5
		{

		}
		if (ui.checkOutPutY5->isChecked() == true)  //输出点6
		{

		}
		if (ui.checkOutPutY6->isChecked() == true)  //输出点7
		{

		}
		if (ui.checkOutPutY7->isChecked() == true)  //输出点8
		{

		}
		GetToolBase()->m_Tools[tool_index].PublicCommunication.InPutIoX = InPutIoX;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmGeneralIo::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmGeneralIo::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmGeneralIo::ExecuteGeneralIoLink(const QMap<QString, gVariable::GeneralIo_Var> generalio_var_link)
{
	try
	{
		gvariable.generalio_variable_link = generalio_var_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmGeneralIo::InitSetToolData(const QVariant data)
{
	try
	{
		InitGeneralIoData init_data;
		init_data = data.value<InitGeneralIoData>();
		ui.comboType->clear();
		for (int i = 0; i < init_data.io_tools.count(); i++)
		{
			ui.comboType->addItem(init_data.io_tools[i]);
		}
		ui.comboType->setCurrentIndex(init_data.io_index);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmGeneralIo::InitGetToolData()
{
	InitGeneralIoData init_data;
	init_data.io_index = ui.comboType->currentIndex();
	for (int i = 0; i < ui.comboType->count(); i++)
	{
		init_data.io_tools.append(ui.comboType->itemText(i));
	}
	return QVariant::fromValue(init_data);
}

void frmGeneralIo::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());	
	ui.btnExecute->setEnabled(true);
}

void frmGeneralIo::on_btnUpdata_clicked()
{
	ui.comboType->clear();
	QList<QString> tool_keys;
	tool_keys.reserve(100);
	tool_keys.clear();
	tool_keys = gvariable.generalio_variable_link.uniqueKeys();
	for (int i = 0; i < tool_keys.count(); i++)
	{
		QString key = tool_keys[i];
		ui.comboType->addItem(key);
	}
}
