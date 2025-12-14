#include "frmLogicGoto.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>

frmLogicGoto::frmLogicGoto(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/goto.png"));
	//初始化标题栏
	initTitleBar();	
}

frmLogicGoto::~frmLogicGoto()
{
	this->deleteLater();
}

void frmLogicGoto::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/goto.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLogicGoto::paintEvent(QPaintEvent* event)
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

void frmLogicGoto::onButtonCloseClicked()
{
	ui.lblMsg->clear();
	this->close();
}

void frmLogicGoto::on_comboType_currentIndexChanged(int index)
{
	switch (index) {
	case 0:
		ui.groupC2->setEnabled(true);
		ui.groupC3->setEnabled(false);
		break;
	case 1:
		ui.groupC2->setEnabled(false);
		ui.groupC3->setEnabled(true);
		break;
	}
}

int frmLogicGoto::Execute(const QString toolname)
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

int frmLogicGoto::RunToolPro()
{
	try
	{
		state = false;
		keys.reserve(300);
		keys.clear();
		keys = gvariable.global_variable_link.uniqueKeys();
		//使用全局变量
		for (int p = 0; p < keys.length(); p++)
		{
			QString key = keys[p];
			switch (ui.comboType->currentIndex()) {
			case 0:
				if (gvariable.global_variable_link.value(key).global_type == "Bool")
				{
					if (key == ui.txtLinkBool->text())
					{
						var_state = gvariable.global_variable_link.value(key).global_bool_value;
						var_state_buf = 1;
					}
				}				
				break;
			case 1:
				if (gvariable.global_variable_link.value(key).global_type == "Int")
				{
					if (key == ui.txtLinkRegex->text())
					{
						var_regex = gvariable.global_variable_link.value(key).global_int_value;
						var_regex_buf = 1;
					}
				}
				break;
			}			
		}
		//使用工具变量
		if (var_state_buf != 1 || var_regex_buf != 1)
		{
			int end_index = 0;
			strs.reserve(100);
			switch (ui.comboType->currentIndex()) {
			case 0:
				if (var_state_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkBool->text().split(".");
					if (strs.size() == 1)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					bool link_state = false;
					for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
					{
						if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
						{
							end_index = i;
							link_state = true;
						}
					}			
					if (link_state == false)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -2;
					}
					if (strs[1] == "状态")
					{
						var_state = GetToolBase()->m_Tools[end_index].PublicResult.State;
					}
					else
					{
						var_state = false;
					}
				}
				break;
			case 1:
				if (var_regex_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkRegex->text().split(".");
					if (strs.size() == 1)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					bool link_state = false;
					for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
					{
						if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
						{
							end_index = i;
							link_state = true;
						}
					}		
					if (link_state == false)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -2;
					}
					if (strs[1] == "表达式")
					{
						var_regex = GetToolBase()->m_Tools[end_index].PublicResult.Regex;
					}
					else
					{
						var_regex = -1;
					}
				}
				break;
			}			
		}
		switch (ui.comboType->currentIndex()) {
		case 0:
			if (var_state == true)
			{
				state = true;
			}
			else
			{
				state = false;
			}
			break;
		case 1:
			int regex_index = ui.comboRegex->currentIndex();
			int value = var_regex - ui.spinRegex->value();
			if (value == 0 && regex_index == 0)
			{
				state = true;
			}
			else if (value != 0 && regex_index == 1)
			{
				state = true;
			}
			else if (value > 0 && regex_index == 2)
			{
				state = true;
			}
			else if (value >= 0 && regex_index == 3)
			{
				state = true;
			}
			else if (value < 0 && regex_index == 4)
			{
				state = true;
			}
			else if (value <= 0 && regex_index == 5)
			{
				state = true;
			}
			else
			{
				state = false;
			}			
			break;
		}		
		GetToolBase()->m_Tools[tool_index].PublicLogic.GotoToolName = ui.comboToolName->currentText();
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmLogicGoto::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "状态")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "状态")
			{
				ui.txtLinkBool->setText(str_link);
				return 0;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Bool")
				{
					if (key == str_link)
					{
						ui.txtLinkBool->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 2)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "表达式")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "表达式")
			{
				ui.txtLinkRegex->setText(str_link);
				return 0;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Int")
				{
					if (key == str_link)
					{
						ui.txtLinkRegex->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}		
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmLogicGoto::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmLogicGoto::ExecuteGotoLink(const QMap<QString, gVariable::Goto_Var> goto_var_link)
{
	try
	{	
		gvariable.goto_variable_link = goto_var_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmLogicGoto::InitSetToolData(const QVariant data)
{
	try
	{
		InitLogicGotoData init_data;
		init_data = data.value<InitLogicGotoData>();
		ui.comboToolName->clear();
		for (int i = 0; i < init_data.g_tools.count(); i++)
		{
			ui.comboToolName->addItem(init_data.g_tools[i]);
		}
		ui.comboToolName->setCurrentIndex(init_data.goto_index);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmLogicGoto::InitGetToolData()
{
	InitLogicGotoData init_data;
	init_data.goto_index = ui.comboToolName->currentIndex();
	for (int i = 0; i < ui.comboToolName->count(); i++)
	{
		init_data.g_tools.append(ui.comboToolName->itemText(i));
	}
	return QVariant::fromValue(init_data);
}

void frmLogicGoto::on_btnUpdata_clicked()
{
	ui.comboToolName->clear();
	QList<QString> tool_keys;
	tool_keys.reserve(100);
	tool_keys.clear();
	tool_keys = gvariable.goto_variable_link.uniqueKeys();
	for (int i = 0; i < tool_keys.count(); i++)
	{
		QString key = tool_keys[i];
		for (int j = 0; j < gvariable.goto_variable_link.value(key).goto_array_name_value.size(); j++)
		{
			if (gvariable.goto_variable_link.value(key).goto_array_name_value[j] != toolTitleName)
			{
				ui.comboToolName->addItem(gvariable.goto_variable_link.value(key).goto_array_name_value[j]);
			}			
		}		
	}
}

void frmLogicGoto::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.lblMsg->clear();
	ui.lblMsg->setText("跳转语句判定结果为：" + QString::number(state));
	ui.btnExecute->setEnabled(true);
}

void frmLogicGoto::on_btnLinkBool_clicked()
{
	QConfig::nFormState = 1;
}

void frmLogicGoto::on_btnDelLinkBool_clicked()
{
	ui.txtLinkBool->clear();
}

void frmLogicGoto::on_btnLinkRegex_clicked()
{
	QConfig::nFormState = 2;
}

void frmLogicGoto::on_btnDelLinkRegex_clicked()
{
	ui.txtLinkRegex->clear();
}

//全局变量控制
int QConfig::nFormState = 0;
