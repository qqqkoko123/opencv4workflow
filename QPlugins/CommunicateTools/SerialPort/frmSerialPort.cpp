#include "frmSerialPort.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QElapsedTimer>
#include <QGraphicsOpacityEffect>
#include <QMetaMethod>
#include <QThread>

frmSerialPort::frmSerialPort(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/serial_port.png"));
	//初始化标题栏
	initTitleBar();	
	connect(this, &frmSerialPort::sig_SendMsg, this, &frmSerialPort::slot_SendMsg, Qt::DirectConnection);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtComReceiveData->setGraphicsEffect(e);
	h_this = QThread::currentThread();
	connect(this, &frmSerialPort::sig_SMsg, this, &frmSerialPort::slot_SMsg, Qt::BlockingQueuedConnection);
	connect(this, &frmSerialPort::sig_ReadMsg, this, &frmSerialPort::slot_ReadMsg, Qt::BlockingQueuedConnection);
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(300);
}

frmSerialPort::~frmSerialPort()
{		
	this->deleteLater();
}

void frmSerialPort::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/serial_port.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmSerialPort::paintEvent(QPaintEvent* event)
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

void frmSerialPort::onButtonCloseClicked()
{
	this->close();
}

int frmSerialPort::Execute(const QString toolname)
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

int frmSerialPort::RunToolPro()
{
	try
	{
		send_buffer.clear();
		keys.reserve(300);
		keys.clear();
		keys = gvariable.global_variable_link.uniqueKeys();
		if (ui.comboCommName->count() == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}
		if (ui.chkSendEnable->isChecked() == true)
		{
			if (ui.txtLinkContent->text() == QString())
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			//使用全局变量
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (key == ui.txtLinkContent->text())
				{
					send_buffer = gvariable.global_variable_link.value(key).global_qstring_value;
					if (ui.radioEndEnter->isChecked() == true)
					{
						send_buffer += "\r";
					}
					else if (ui.radioEndNewline->isChecked() == true)
					{
						send_buffer += "\n";
					}
					else if (ui.radioEndEnterNewline->isChecked() == true)
					{
						send_buffer += "\r\n";
					}
					if (port_state == 1)
					{
						emit sig_SendMsg(send_buffer);
						QElapsedTimer t;
						t.start();
						while (t.elapsed() < 100);
					}
					else
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					if (choose_num == 1 && port_state == 0)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					break;
				}
			}
		}
		if (ui.chkSendEnable->isChecked() == false && ui.chkReceiveEnable->isChecked() == false)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}
		GetToolBase()->m_Tools[tool_index].PublicCommunication.InputData = buffer;
		GetToolBase()->m_Tools[tool_index].PublicCommunication.OutputData = send_buffer;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{	
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

void frmSerialPort::slot_SendMsg(QString msg)
{
	try
	{
		//发送数据	
		h_send = QThread::currentThread();
		if (h_this != h_send)
		{
			emit sig_SMsg(msg);
		}
		else
		{
			if (ui.chkComHexSend->isChecked() == true)
			{
				QString str = byteArrayToHexStr(msg.toLocal8Bit());
				QByteArray send_buf = hexStrToByteArray(str);
				if (s_port->isOpen())
				{
					s_port->write(send_buf);
				}
			}
			else
			{
				if (s_port->isOpen())
				{
					s_port->write(msg.toLocal8Bit().toStdString().data());
				}
			}
		}		
	}
	catch(...){}	
}

void frmSerialPort::slot_SMsg(QString msg)
{
	try
	{
		if (ui.chkComHexSend->isChecked() == true)
		{
			QString str = byteArrayToHexStr(msg.toLocal8Bit());
			QByteArray send_buf = hexStrToByteArray(str);
			if (s_port->isOpen())
			{
				s_port->write(send_buf);
			}
		}
		else
		{
			if (s_port->isOpen())
			{
				s_port->write(msg.toLocal8Bit().toStdString().data());
			}
		}
	}
	catch (...) {}
}

void frmSerialPort::slot_ReadData()
{
	try
	{
		//读取数据	
		h_read = QThread::currentThread();
		if (h_this != h_read)
		{
			emit sig_ReadMsg();
		}
		else
		{
			if (ui.chkReceiveEnable->isChecked() == true)
			{				
				QByteArray data = s_port->readAll();
				if (ui.chkComHexReceive->isChecked() == true)
				{
					buffer = byteArrayToHexStr(data);
					ui.txtComReceiveData->append(buffer);
				}
				else
				{
					buffer = QString::fromLocal8Bit(data);
					ui.txtComReceiveData->append(buffer);
				}				
			}
			else
			{
				buffer.clear();
			}
		}		
	}
	catch (...) {}	
}

void frmSerialPort::slot_ReadMsg()
{
	try
	{
		if (ui.chkReceiveEnable->isChecked() == true)
		{			
			QByteArray data = s_port->readAll();
			if (ui.chkComHexReceive->isChecked() == true)
			{
				buffer = byteArrayToHexStr(data);
				ui.txtComReceiveData->append(buffer);
			}
			else
			{
				buffer = QString::fromLocal8Bit(data);
				ui.txtComReceiveData->append(buffer);
			}			
		}
		else
		{
			buffer.clear();
		}
	}
	catch (...) {}
}

void frmSerialPort::timerEvent()
{
	if (ui.txtComReceiveData->document()->blockCount() > 1000)
	{
		ui.txtComReceiveData->clear();
	}
}

void frmSerialPort::on_comboCommName_currentIndexChanged(int index)
{
	port_state = 0;
	keys.reserve(300);
	keys.clear();
	keys = gvariable.serialport_variable_link.uniqueKeys();
	for (int p = 0; p < keys.length(); p++)
	{
		QString key = keys[p];				
		if (key == ui.comboCommName->itemText(index))
		{			
			s_port = gvariable.serialport_variable_link.value(key).serialport_value;
			if (port_buf == 0)
			{
				connect(s_port, SIGNAL(readyRead()), this, SLOT(slot_ReadData()), Qt::DirectConnection);
				s_port_buf = s_port;
				port_buf = 1;
			}
			if (s_port != s_port_buf)
			{
				if (s_port_buf != nullptr)
				{
					disconnect(s_port_buf, SIGNAL(readyRead()), this, SLOT(slot_ReadData()));
				}				
				connect(s_port, SIGNAL(readyRead()), this, SLOT(slot_ReadData()), Qt::DirectConnection);
				s_port_buf = s_port;
			}
			port_state = 1;			
			choose_index = index;
			return;
		}		
	}	
}

int frmSerialPort::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "QString")
				{
					if (key == str_link)
					{
						ui.txtLinkContent->setText(str_link);
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

int frmSerialPort::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmSerialPort::ExecuteSerialPortLink(const QMap<QString, gVariable::SerialPort_Var> serialport_var_link)
{
	try
	{
		gvariable.serialport_variable_link = serialport_var_link;
		if (choose_index >= 0)
		{
			port_state = 0;
			choose_num = 0;
			keys.reserve(300);
			keys.clear();
			keys = gvariable.serialport_variable_link.uniqueKeys();
			if (keys.length() != ui.comboCommName->count())
			{				
				for (int p = 0; p < ui.comboCommName->count(); p++)
				{
					QString key = ui.comboCommName->itemText(p);
					if (gvariable.serialport_variable_link.value(key).connect_state != 1 && key == ui.comboCommName->itemText(choose_index))
					{
						s_port_buf = nullptr; 
						choose_num = 1;					
					}
				}				
				return -1;
			}				
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];				
				if (key == ui.comboCommName->itemText(choose_index))
				{			
					s_port = gvariable.serialport_variable_link.value(key).serialport_value;
					if (s_port != s_port_buf)
					{		
						if (s_port_buf != nullptr)
						{
							disconnect(s_port_buf, SIGNAL(readyRead()), this, SLOT(slot_ReadData()));
						}
						connect(s_port, SIGNAL(readyRead()), this, SLOT(slot_ReadData()), Qt::DirectConnection);
						s_port_buf = s_port;
					}					
					port_state = 1;				
					return 0;
				}				
			}
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmSerialPort::InitSetToolData(const QVariant data)
{
	try
	{
		InitSerialPortData init_data;
		init_data = data.value<InitSerialPortData>();
		ui.comboCommName->clear();
		for (int i = 0; i < init_data.sport_tools.count(); i++)
		{
			ui.comboCommName->addItem(init_data.sport_tools[i]);
		}
		ui.comboCommName->setCurrentIndex(init_data.sport_index);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmSerialPort::InitGetToolData()
{
	InitSerialPortData init_data;
	init_data.sport_index = ui.comboCommName->currentIndex();
	for (int i = 0; i < ui.comboCommName->count(); i++)
	{
		init_data.sport_tools.append(ui.comboCommName->itemText(i));
	}
	return QVariant::fromValue(init_data);
}

void frmSerialPort::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());	
	ui.btnExecute->setEnabled(true);
}

void frmSerialPort::on_btnUpdata_clicked()
{
	ui.comboCommName->clear();
	QList<QString> tool_keys;
	tool_keys.reserve(100);
	tool_keys.clear();
	tool_keys = gvariable.serialport_variable_link.uniqueKeys();
	for (int i = 0; i < tool_keys.count(); i++)
	{
		QString key = tool_keys[i];
		ui.comboCommName->addItem(key);
	}
}

void frmSerialPort::on_btnLinkContent_clicked()
{
	QConfig::nFormState = 1;
}

void frmSerialPort::on_btnDelLinkContent_clicked()
{
	ui.txtLinkContent->clear();
}

void frmSerialPort::on_btnComClear_clicked()
{
	ui.txtComReceiveData->clear();
}

QByteArray frmSerialPort::hexStrToByteArray(const QString& str)
{
	QByteArray senddata;
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = str.length();
	senddata.resize(len / 2);
	char lstr, hstr;
	for (int i = 0; i < len;)
	{
		hstr = str.at(i).toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
		{
			break;
		}
		lstr = str.at(i).toLatin1();
		hexdata = convertHexChar(hstr);
		lowhexdata = convertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
		{
			break;
		}
		else
		{
			hexdata = hexdata * 16 + lowhexdata;
		}
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.resize(hexdatalen);
	return senddata;
}

char frmSerialPort::convertHexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
	{
		return ch - 0x30;
	}
	else if ((ch >= 'A') && (ch <= 'F'))
	{
		return ch - 'A' + 10;
	}
	else if ((ch >= 'a') && (ch <= 'f'))
	{
		return ch - 'a' + 10;
	}
	else
	{
		return (-1);
	}
}

QString frmSerialPort::byteArrayToHexStr(const QByteArray& data)
{
	QString temp = "";
	QString hex = data.toHex();
	for (int i = 0; i < hex.length(); i = i + 2) {
		temp += hex.mid(i, 2) + " ";
	}
	return temp.trimmed().toUpper();
}

//全局变量控制
int QConfig::nFormState = 0;
