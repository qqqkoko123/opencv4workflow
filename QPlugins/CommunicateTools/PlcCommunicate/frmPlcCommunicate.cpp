#include "frmPlcCommunicate.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QThread>
#include "qmutex.h"

frmPlcCommunicate::frmPlcCommunicate(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/plc.png"));
	//初始化标题栏
	initTitleBar();
	//设置表格列宽	
	ui.tableWidgetPlc->setColumnWidth(0, 599);
	//设置表格行间距
	ui.tableWidgetPlc->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetPlc->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetPlc->verticalHeader()->setVisible(false);
	ui.tableWidgetPlc->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetPlc->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetPlc, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_PlcDoubleClicked(int, int)));
	connect(ui.txtMitRegisterAddress, &QLineEdit::textChanged, this, &frmPlcCommunicate::slot_MitRegisterAddress, Qt::AutoConnection);
	//选项按钮
	btnGroupRadio = new QButtonGroup(this);
	btnGroupRadio->addButton(ui.radioMitRead, 0);
	connect(ui.radioMitRead, SIGNAL(clicked()), this, SLOT(onRadioClick()));
	ui.radioMitRead->click();
	btnGroupRadio->addButton(ui.radioMitWrite, 1);
	connect(ui.radioMitWrite, SIGNAL(clicked()), this, SLOT(onRadioClick()));
	h1 = QThread::currentThread();
	connect(this, &frmPlcCommunicate::sig_AsciiWrite1D, this, &frmPlcCommunicate::AsciiWrite1D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_AsciiRead1D, this, &frmPlcCommunicate::AsciiRead1D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_AsciiWrite2D, this, &frmPlcCommunicate::AsciiWrite2D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_AsciiRead2D, this, &frmPlcCommunicate::AsciiRead2D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_BinaryWrite1D, this, &frmPlcCommunicate::BinaryWrite1D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_BinaryWrite2D, this, &frmPlcCommunicate::BinaryWrite2D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_BinaryRead1D, this, &frmPlcCommunicate::BinaryRead1D, Qt::BlockingQueuedConnection);
	connect(this, &frmPlcCommunicate::sig_BinaryRead2D, this, &frmPlcCommunicate::BinaryRead2D, Qt::BlockingQueuedConnection);
}

frmPlcCommunicate::~frmPlcCommunicate()
{
	this->deleteLater();
}

void frmPlcCommunicate::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/plc.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmPlcCommunicate::paintEvent(QPaintEvent* event)
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

void frmPlcCommunicate::onButtonCloseClicked()
{
	this->close();
}

void frmPlcCommunicate::onRadioClick()
{
	switch (btnGroupRadio->checkedId())
	{
	case 0:
		ui.btnLinkMitRegisterData->setEnabled(false);
		ui.btnDelLinkMitRegisterData->setEnabled(false);
		break;
	case 1:
		ui.btnLinkMitRegisterData->setEnabled(true);
		ui.btnDelLinkMitRegisterData->setEnabled(true);
		break;
	}
}

int frmPlcCommunicate::Execute(const QString toolname)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
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

int frmPlcCommunicate::RunToolPro()
{
	try
	{
		if (ui.comboCommName->count() == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		RegisterReadData.reserve(300);
		RegisterReadData.clear();
		RegisterWriteData.reserve(300);
		RegisterWriteData.clear();
		keys.reserve(300);
		keys.clear();
		keys = gvariable.plccommunicate_variable_link.uniqueKeys();
		register_keys.reserve(300);
		register_keys.clear();
		global_keys.reserve(300);
		global_keys.clear();
		global_keys = gvariable.global_variable_link.uniqueKeys();
		for (int p = 0; p < keys.length(); p++)
		{
			QString key = keys[p];
			strs.reserve(100);
			strs.clear();
			strs = key.split("_");
			if (strs.size() == 1)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			if (strs[0] == "Mitsubishi PLC")
			{
				register_keys = global_mit_register_content.uniqueKeys();
				if (register_keys.count() == 0)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				h2 = QThread::currentThread();
				for (int m = 0; m < register_keys.length(); m++)
				{
					QString mit_key = register_keys[m];
					if (global_mit_register_content.value(mit_key).mit_code == "二进制码")
					{
						string device = global_mit_register_content.value(mit_key).mit_address.mid(1).toStdString();
						if (global_mit_register_content.value(mit_key).mit_state == "Read")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								if (h1 != h2)
								{
									state = emit sig_BinaryRead1D(plc_tcp_client, device, value);
								}
								else
								{
									state = BinaryRead1D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								if (h1 != h2)
								{
									state = emit sig_BinaryRead2D(plc_tcp_client, device, value);
								}
								else
								{
									state = BinaryRead2D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(value);
							}
						}
						else if (global_mit_register_content.value(mit_key).mit_state == "Write")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									state = emit sig_BinaryWrite1D(plc_tcp_client, device, value);
								}
								else
								{
									state = BinaryWrite1D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									state = emit sig_BinaryWrite2D(plc_tcp_client, device, value);
								}
								else
								{
									state = BinaryWrite2D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
						}
					}
					else if (global_mit_register_content.value(mit_key).mit_code == "ASCII码")
					{
						QString device = global_mit_register_content.value(mit_key).mit_address.mid(1);
						if (global_mit_register_content.value(mit_key).mit_state == "Read")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								if (h1 != h2)
								{
									state = emit sig_AsciiRead1D(plc_tcp_client, device, value);
								}
								else
								{
									state = AsciiRead1D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								if (h1 != h2)
								{
									state = emit sig_AsciiRead2D(plc_tcp_client, device, value);
								}
								else
								{
									state = AsciiRead2D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(value);
							}
						}
						else if (global_mit_register_content.value(mit_key).mit_state == "Write")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									state = emit sig_AsciiWrite1D(plc_tcp_client, device, value);
								}
								else
								{
									state = AsciiWrite1D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									state = emit sig_AsciiWrite2D(plc_tcp_client, device, value);
								}
								else
								{
									state = AsciiWrite2D(plc_tcp_client, device, value);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
						}
					}
				}
				break;
			}
			else if (strs[0] == "Inovance PLC")
			{
				register_keys = global_mit_register_content.uniqueKeys();
				if (register_keys.count() == 0)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				//PLC断连重连
				if (!InovancePLC_connect(key)) 
				{
					if (!InovancePLC_connect(key))
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
				}
				h2 = QThread::currentThread();
				for (int m = 0; m < register_keys.length(); m++)
				{
					QString mit_key = register_keys[m];
					if (global_mit_register_content.value(mit_key).mit_code == "二进制码")
					{
						string device = global_mit_register_content.value(mit_key).mit_address.mid(1).toStdString();
						if (global_mit_register_content.value(mit_key).mit_state == "Read")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								int val;
								if (h1 != h2)
								{
									//state = emit sig_BinaryRead1D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key,1);
								}
								else
								{
									//state = BinaryRead1D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(val);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								int val;
								if (h1 != h2)
								{
									//state = emit sig_BinaryRead2D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
								}
								else
								{
									//state = BinaryRead2D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(val);
							}
						}
						else if (global_mit_register_content.value(global_mit_register_content.value(mit_key).mit_address).mit_state == "Write")
						{
							if (global_mit_register_content.value(global_mit_register_content.value(mit_key).mit_address).mit_method == "字")
							{
								short value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									//state = emit sig_BinaryWrite1D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(),value, key);
								}
								else
								{
									//state = BinaryWrite1D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									//state = emit sig_BinaryWrite2D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								else
								{
									//state = BinaryWrite2D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
						}
					}
					else if (global_mit_register_content.value(mit_key).mit_code == "ASCII码")
					{
						QString device = global_mit_register_content.value(mit_key).mit_address.mid(1);
						if (global_mit_register_content.value(mit_key).mit_state == "Read")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short val = 0;
								bool state;
								if (h1 != h2)
								{
									//state = emit sig_AsciiRead1D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
								}
								else
								{
									//state = AsciiRead1D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 1);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(val);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int val = 0;
								bool state;
								if (h1 != h2)
								{
									//state = emit sig_AsciiRead2D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
								}
								else
								{
									//state = AsciiRead2D(plc_tcp_client, device, value);
									state = emit readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
									val = readRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), key, 2);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterReadData.append(val);
							}
						}
						else if (global_mit_register_content.value(mit_key).mit_state == "Write")
						{
							if (global_mit_register_content.value(mit_key).mit_method == "字")
							{
								short value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									//state = emit sig_AsciiWrite1D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								else
								{
									//state = AsciiWrite1D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
							else if (global_mit_register_content.value(mit_key).mit_method == "双字")
							{
								int value = 0;
								bool state;
								//使用全局变量
								for (int n = 0; n < global_keys.length(); n++)
								{
									QString g_key = global_keys[n];
									if (g_key == global_mit_register_content.value(mit_key).mit_data)
									{
										value = gvariable.global_variable_link.value(g_key).global_int_value;
										break;
									}
								}
								if (h1 != h2)
								{
									//state = emit sig_AsciiWrite2D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								else
								{
									//state = AsciiWrite2D(plc_tcp_client, device, value);
									state = writeRegister(global_mit_register_content.value(mit_key).mit_address.mid(1).toInt(), value, key);
								}
								if (state == false)
								{
									GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
									return -1;
								}
								RegisterWriteData.append(value);
							}
						}
					}
				}
				break;
			}
		}
		GetToolBase()->m_Tools[tool_index].PublicCommunication.RegisterReadData = RegisterReadData;
		GetToolBase()->m_Tools[tool_index].PublicCommunication.RegisterWriteData = RegisterWriteData;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}
void frmPlcCommunicate::disconnect(QString key)
{
	try
	{
		modbus_close(gvariable.plccommunicate_variable_link.value(key).ctx);
		modbus_free(gvariable.plccommunicate_variable_link.value(key).ctx);
		gvariable.plccommunicate_variable_link[key].connect_state = 0;
		std::cout << "PLC disconnect success " << std::endl;
	}
	catch (...) {

	}
}
bool frmPlcCommunicate::writeRegister(int num, int value,QString key)
{
	try
	{
		if (modbus_write_register(gvariable.plccommunicate_variable_link.value(key).ctx, num, value) == -1)
		{
			std::cerr << "Failed to write to register: " << modbus_strerror(errno) << std::endl;
			return false;
		}
		else
		{
			//std::cout << "Changed Register " << num << " to : " << value << std::endl;
			return true;
		}
	}
	catch (...) {
		return false;
	}
}

int frmPlcCommunicate::readRegister(int num,QString key,int nb)
{
	uint16_t regs[1];
	try
	{
		modbus_t* ctx = gvariable.plccommunicate_variable_link.value(key).ctx;
		int res = modbus_read_registers(ctx, num, nb, regs);
		if (res == -1)
		{
			std::cerr << "Failed to read registers: " << modbus_strerror(errno) << std::endl;
			// 读取失败返回值0x0000
			regs[0] = 0x0000;
		}
		else
		{
			//std::cout << "Read Register " << num << " : " << regs[0] << std::endl;
		}
	}
	catch (...) {

	}
	// 返回读取值
	return regs[0];
}
void frmPlcCommunicate::on_comboCommName_currentIndexChanged(int index)
{
	plc_tcp_state = 0;
	keys.reserve(300);
	keys.clear();
	keys = gvariable.plccommunicate_variable_link.uniqueKeys();
	for (int p = 0; p < keys.length(); p++)
	{
		QString key = keys[p];
		if (key == ui.comboCommName->itemText(index))
		{
			strs.reserve(100);
			strs.clear();
			strs = key.split("_");
			if (strs.size() == 1)
			{
				return;
			}
			if (strs[0] == "Mitsubishi PLC" || strs[0] == "Inovance PLC")
			{
				plc_tcp_client = gvariable.plccommunicate_variable_link.value(key).mit_value;
			}
			plc_tcp_state = 1;
			choose_index = index;
			return;
		}
	}
}

int frmPlcCommunicate::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
				if (gvariable.global_variable_link.value(key).global_type == "Int")
				{
					if (key == str_link)
					{
						ui.txtMitRegisterData->setText(str_link);
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

int frmPlcCommunicate::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmPlcCommunicate::ExecutePlcCommunicateLink(const QMap<QString, gVariable::PlcCommunicate_Var> plccommunicate_var_link)
{
	try
	{
		gvariable.plccommunicate_variable_link = plccommunicate_var_link;
		if (choose_index >= 0)
		{
			plc_tcp_state = 0;
			choose_num = 0;
			keys.reserve(300);
			keys.clear();
			keys = gvariable.plccommunicate_variable_link.uniqueKeys();
			if (keys.length() != ui.comboCommName->count())
			{
				choose_num = 1;
				return -1;
			}
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (key == ui.comboCommName->itemText(choose_index))
				{
					strs.reserve(100);
					strs.clear();
					strs = key.split("_");
					if (strs.size() == 1)
					{
						return -1;
					}
					if (strs[0] == "Mitsubishi PLC" || strs[0] == "Inovance PLC")
					{
						plc_tcp_client = gvariable.plccommunicate_variable_link.value(key).mit_value;
					}
					plc_tcp_state = 1;
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

int frmPlcCommunicate::InitSetToolData(const QVariant data)
{
	try
	{
		InitPlcCommunicateData init_data;
		init_data = data.value<InitPlcCommunicateData>();
		ui.comboCommName->clear();
		for (int i = 0; i < init_data.plc_tools.count(); i++)
		{
			ui.comboCommName->addItem(init_data.plc_tools[i]);
		}
		ui.comboCommName->setCurrentIndex(init_data.plc_index);
		for (int m = 0; m < init_data.plc_key.count(); m++)
		{
			MitRegisterContent.mit_code = init_data.mit_code[m];
			MitRegisterContent.mit_state = init_data.mit_state[m];
			MitRegisterContent.mit_method = init_data.mit_method[m];
			MitRegisterContent.mit_address = init_data.mit_address[m];
			MitRegisterContent.mit_data = init_data.mit_data[m];
			global_mit_register_content.insert(init_data.plc_key[m], MitRegisterContent);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmPlcCommunicate::InitGetToolData()
{
	InitPlcCommunicateData init_data;
	init_data.plc_index = ui.comboCommName->currentIndex();
	for (int i = 0; i < ui.comboCommName->count(); i++)
	{
		init_data.plc_tools.append(ui.comboCommName->itemText(i));
	}
	QList<QString> text_keys;
	text_keys.reserve(100);
	text_keys.clear();
	text_keys = global_mit_register_content.uniqueKeys();
	for (int m = 0; m < text_keys.count(); m++)
	{
		QString key = text_keys[m];
		init_data.plc_key.append(key);
		init_data.mit_code.append(global_mit_register_content.value(key).mit_code);
		init_data.mit_state.append(global_mit_register_content.value(key).mit_state);
		init_data.mit_method.append(global_mit_register_content.value(key).mit_method);
		init_data.mit_address.append(global_mit_register_content.value(key).mit_address);
		init_data.mit_data.append(global_mit_register_content.value(key).mit_data);		
	}
	return QVariant::fromValue(init_data);
}

void frmPlcCommunicate::slot_PlcDoubleClicked(int row, int column)
{
	table_buf = 1;
	QString str = ui.tableWidgetPlc->item(row, 0)->text();
	RegisterAddress_buf = str;
	if (str.mid(0, 10) == "PLC寄存器链接地址")
	{
		ui.comboMitCode->setCurrentIndex(0);
		ui.radioMitRead->setChecked(true);
		ui.comboMitMethod->setCurrentIndex(0);
		ui.txtMitRegisterAddress->clear();
		ui.txtMitRegisterData->clear();
		ui.btnLinkMitRegisterData->setEnabled(false);
		ui.btnDelLinkMitRegisterData->setEnabled(false);
	}
	else
	{
		register_keys.reserve(300);
		register_keys.clear();
		register_keys = global_mit_register_content.uniqueKeys();
		for (int k = 0; k < register_keys.length(); k++)
		{
			QString key = register_keys[k];
			if (key == str)
			{
				ui.comboMitCode->setCurrentText(global_mit_register_content.value(key).mit_code);
				if (global_mit_register_content.value(key).mit_state == "Read")
				{
					ui.radioMitRead->setChecked(true);
					ui.radioMitWrite->setChecked(false);
					ui.btnLinkMitRegisterData->setEnabled(false);
					ui.btnDelLinkMitRegisterData->setEnabled(false);
				}
				else if (global_mit_register_content.value(key).mit_state == "Write")
				{
					ui.radioMitWrite->setChecked(true);
					ui.radioMitRead->setChecked(false);
					ui.btnLinkMitRegisterData->setEnabled(true);
					ui.btnDelLinkMitRegisterData->setEnabled(true);
				}
				ui.comboMitMethod->setCurrentText(global_mit_register_content.value(key).mit_method);
				ui.txtMitRegisterAddress->setText(global_mit_register_content.value(key).mit_address);
				ui.txtMitRegisterData->setText(global_mit_register_content.value(key).mit_data);
			}
		}
	}
	ui.stackedWidget->setCurrentIndex(1);
	register_index_row = row;
}

void frmPlcCommunicate::slot_MitRegisterAddress(QString text)
{
	if (text == QString())
	{
		return;
	}
	if (text.mid(0, 1) != "D")
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "寄存器地址第1个字符为“D”！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		ui.txtMitRegisterAddress->clear();
		return;
	}
	if (text.mid(1, 1) == "0")
	{
		if (text.length() > 2)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "寄存器地址第2个字符为“0”时，后面不能有字符！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
			ui.txtMitRegisterAddress->clear();
			return;
		}
	}
	if (text.length() >= 2)
	{
		if (text.mid(1, text.length() - 1).contains(QRegExp("[0-9]+$")) == false)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "寄存器地址输入错误！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
			ui.txtMitRegisterAddress->clear();
			return;
		}
	}
	if (text.mid(1, text.length() - 1).toInt() > 12288)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "寄存器地址超出范围！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		ui.txtMitRegisterAddress->clear();
		return;
	}
	if (table_buf == 0)
	{
		int table_count = ui.tableWidgetPlc->rowCount();
		for (int m = 0; m < table_count; m++)
		{
			if (ui.txtMitRegisterAddress->text() == ui.tableWidgetPlc->item(m, 0)->text())
			{
				ui.txtMitRegisterAddress->clear();
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该寄存器地址！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return;
			}
		}
	}
	table_buf = 0;
}

void frmPlcCommunicate::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	int count1 = RegisterReadData.size();
	for (int i = 0; i < count1; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 寄存器读取数据为: ");
		}
		ui.txtMsg->append(QString::number(RegisterReadData[i]));
	}
	int count2 = RegisterWriteData.size();
	for (int i = 0; i < count2; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 寄存器写入数据为: ");
		}
		ui.txtMsg->append(QString::number(RegisterWriteData[i]));
	}
	ui.btnExecute->setEnabled(true);
}

void frmPlcCommunicate::on_btnUpdata_clicked()
{
	ui.comboCommName->clear();
	QList<QString> tool_keys;
	tool_keys.reserve(100);
	tool_keys.clear();
	tool_keys = gvariable.plccommunicate_variable_link.uniqueKeys();
	for (int i = 0; i < tool_keys.count(); i++)
	{
		QString key = tool_keys[i];
		ui.comboCommName->addItem(key);
	}
}

void frmPlcCommunicate::on_btnAddRegister_clicked()
{
	if (ui.comboCommName->count() == 0)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "通讯名称为空！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	int count = ui.tableWidgetPlc->rowCount();
	ui.tableWidgetPlc->setRowCount(count + 1);  //设置行数	
	//删除流程后重新计算
	int i = 0;
	if (m_process_buf.count() != 0)
	{
		//按升序排序
		qSort(m_process_buf.begin(), m_process_buf.end());
		//最小值
		i = m_process_buf[0];
		m_process_buf.removeAt(0);
	}
	else
	{
		i = count + 1;
	}
	QTableWidgetItem* item_name = new QTableWidgetItem("PLC寄存器链接地址" + QString::number(i));
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetPlc->setItem(count, 0, item_name);
}

void frmPlcCommunicate::on_btnDeleteRegister_clicked()
{
	int rowIndex = ui.tableWidgetPlc->currentRow();
	if (rowIndex != -1)
	{
		QString str = ui.tableWidgetPlc->item(rowIndex, 0)->text();
		if (str.mid(0, 10) == "PLC寄存器链接地址")
		{
			int flow = str.mid(10, str.length()).toInt();
			m_process_buf.append(flow);
		}
		global_mit_register_content.remove(str);
		ui.tableWidgetPlc->removeRow(rowIndex);
	}
}

void frmPlcCommunicate::on_btnLinkMitRegisterData_clicked()
{
	QConfig::nFormState = 1;
}

void frmPlcCommunicate::on_btnDelLinkMitRegisterData_clicked()
{
	ui.txtMitRegisterData->clear();
}

void frmPlcCommunicate::on_btnMitSave_clicked()
{
	if (ui.txtMitRegisterAddress->text() == QString())
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "参数保存失败！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	if (ui.txtMitRegisterData->text() == QString() && ui.radioMitWrite->isChecked() == true)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "参数保存失败！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	MitRegisterContent.mit_code = ui.comboMitCode->currentText();
	if (ui.radioMitRead->isChecked() == true)
	{
		MitRegisterContent.mit_state = "Read";
	}
	else
	{
		MitRegisterContent.mit_state = "Write";
	}
	MitRegisterContent.mit_method = ui.comboMitMethod->currentText();
	MitRegisterContent.mit_address = ui.txtMitRegisterAddress->text();
	MitRegisterContent.mit_data = ui.txtMitRegisterData->text();
	global_mit_register_content.insert(ui.txtMitRegisterAddress->text(), MitRegisterContent);
	if (RegisterAddress_buf != ui.txtMitRegisterAddress->text() && RegisterAddress_buf.mid(0, 1) == "D")
	{
		int count = ui.tableWidgetPlc->rowCount();
		ui.tableWidgetPlc->setRowCount(count + 1);  //设置行数	
		QTableWidgetItem* item_name = new QTableWidgetItem(ui.txtMitRegisterAddress->text());
		item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
		item_name->setTextAlignment(Qt::AlignLeft);
		item_name->setTextAlignment(Qt::AlignVCenter);
		ui.tableWidgetPlc->setItem(count, 0, item_name);
	}
	else
	{
		ui.tableWidgetPlc->item(register_index_row, 0)->setText(ui.txtMitRegisterAddress->text());
	}
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "参数保存完成！");
	msgBox.setWindowIcon(QIcon(":/resource/info.png"));
	msgBox.exec();
}

void frmPlcCommunicate::on_btnMitBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}
bool frmPlcCommunicate::InovancePLC_connect(QString key)
{
	try
	{
		std::cout << "modbus init success" << std::endl;
		QString IP = gvariable.plccommunicate_variable_link.value(key).mit_ip_value;
		int Port = gvariable.plccommunicate_variable_link.value(key).mit_port_value;
		modbus_close(gvariable.plccommunicate_variable_link.value(key).ctx);
		modbus_free(gvariable.plccommunicate_variable_link.value(key).ctx);
		// 设置PLC的IP地址与端口，建立TCP连接
		modbus_t *ctx = modbus_new_tcp(IP.toStdString().c_str(), Port);
		if (ctx == NULL)
		{
			std::cout << "Unable to allocate libmodbus context " << modbus_strerror(errno) << std::endl;
		}

		//std::cout << "modbus_connect(ctx) =  " << modbus_connect(ctx) << std::endl;
		if (modbus_connect(ctx) == -1)
		{
			modbus_close(ctx);
			modbus_free(ctx);
			std::cout << "PLC connect failed " << modbus_strerror(errno) << std::endl;
			return false;
		}
		else
		{
			std::cout << "PLC connect success " << std::endl;
			gvariable.plccommunicate_variable_link[key].connect_state = 1;
			gvariable.plccommunicate_variable_link[key].ctx = ctx;
			return true;
		}
	}
	catch (...) {
		return false;
	}

}
#pragma region 三菱PLC
#pragma region Ascii
//写入16位寄存器
bool frmPlcCommunicate::AsciiWrite1D(QTcpSocket* m_socket, QString device, short value)
{
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		//十进制转十六进制(保留8位，不足补0)		
		QString strNumD = QString("%1").arg(value, 8, 16, QLatin1Char('0'));
		int lengthRec = strNumD.length();
		strNumD = strNumD.mid(lengthRec - 4);
		QString SData = "500000FF03FF00001C001014010000D*" + device + "0001" + strNumD;
		//发送数据
		m_socket->write(SData.toUtf8().data());
		//阻塞函数
		m_socket->waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket->readAll();
		if (RData.length() > 20 && RData.mid(18, 4) == "0000")
			return true;
		return false;		
	}
	catch (...)
	{
		return false;
	}
}

//读取16位寄存器
bool frmPlcCommunicate::AsciiRead1D(QTcpSocket* m_socket, QString device, short& value)
{
	try
	{
		QByteArray RData;
		RData.resize(26);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000018001004010000D*" + device + "0001";
		//发送数据
		m_socket->write(SData.toUtf8().data());
		//阻塞函数
		m_socket->waitForReadyRead(15);
		//接收数据
		RData = m_socket->readAll();
		QString strRData = RData;
		int lengthRec = strRData.length();
		strRData = strRData.mid(lengthRec - 4);
		//十六进制转十进制
		value = strRData.toInt(0, 16);
		if (value >= 32768)
		{
			value -= 65536;
		}
		if (RData.length() > 20 && RData.mid(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}
}

//写入32位寄存器
bool frmPlcCommunicate::AsciiWrite2D(QTcpSocket* m_socket, QString device, int value)
{
	try
	{
		QByteArray RData;
		RData.resize(257);
		int intNumD_L = 0;
		int intNumD_H = 0;
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		//双字转两个单字
		AsciiDWordToSWord(value, intNumD_L, intNumD_H);
		//十进制转十六进制(保留8位，不足补0)		
		QString strNumD_L = QString("%1").arg(intNumD_L, 8, 16, QLatin1Char('0'));
		strNumD_L = strNumD_L.right(4);
		QString strNumD_H = QString("%1").arg(intNumD_H, 8, 16, QLatin1Char('0'));
		strNumD_H = strNumD_H.right(4);
		QString SData = "500000FF03FF000020001014010000D*" + device + "0002" + strNumD_L + strNumD_H;
		//发送数据
		m_socket->write(SData.toUtf8().data());
		//阻塞函数
		m_socket->waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket->readAll();
		if (RData.length() > 20 && RData.mid(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}
}

//双字转两个单字
void frmPlcCommunicate::AsciiDWordToSWord(int int32Num, int& int16Num_L, int& int16Num_H)
{
	vector<short> nn(2);
	int iv = int32Num;
	//long long长度是64位
	long long lv = iv;
	uint uv = static_cast<uint>((lv + 65536LL * 65536LL) % (65536LL * 65536LL));
	//转成无符号范围的数             
	ulong ul = uv;
	uv = static_cast<uint>(ul % 65536);
	iv = static_cast<uint>(uv);
	//将超出 32768 一半的数转成负值 
	if ((iv >= 32768))
		iv -= 65536;
	nn[0] = static_cast<short>(iv);
	uv = static_cast<uint>(ul / 65536);
	iv = static_cast<int>(uv);
	//将超出 32768 一半的数转成负值 
	if ((iv >= 32768))
		iv -= 65536;
	nn[1] = static_cast<short>(iv);
	int16Num_L = nn[0];
	int16Num_H = nn[1];
}

//读取32位寄存器
bool frmPlcCommunicate::AsciiRead2D(QTcpSocket* m_socket, QString device, int& value)
{
	try
	{
		QByteArray RData;
		RData.resize(30);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000018001004010000D*" + device + "0002";
		//发送数据
		m_socket->write(SData.toUtf8().data());
		//阻塞函数
		m_socket->waitForReadyRead(15);
		//接收数据
		RData = m_socket->readAll();
		QString strRData = RData;
		int lengthRec = strRData.length();
		QString strRData_H = strRData.mid(lengthRec - 4);
		//十六进制转十进制
		int NumD_H = strRData_H.toInt(0, 16);
		if (NumD_H >= 32768)
		{
			NumD_H -= 65536;
		}
		QString strRData_L = strRData.mid(lengthRec - 8, 4);
		//十六进制转十进制
		int NumD_L = strRData_L.toInt(0, 16);
		if (NumD_L >= 32768)
		{
			NumD_L -= 65536;
		}
		//两个单字双字转
		AsciiSWordToDWord(NumD_L, NumD_H, value);
		if (RData.length() > 20 && RData.mid(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}
}

//两个单字转双字
void frmPlcCommunicate::AsciiSWordToDWord(int int16Num_L, int int16Num_H, int& int32Num)
{
	vector<int> iData(2);
	vector<long long> uData(2);
	//低16位值
	iData[0] = int16Num_L;
	//高16位值
	iData[1] = int16Num_H;
	//转成无符号 0-65535 范围的数
	uData[0] = (iData[0] + 65536) % 65536;
	//同上
	uData[1] = (iData[1] + 65536) % 65536;
	long long lData = uData[1] * 65536 + uData[0];
	//转成32位无符号范围的数
	//将超出 2^32 一半的数转成负值 
	if ((lData >= 65536L * 32768L))
	{
		lData -= 65536L * 65536L;
	}
	int32Num = static_cast<int>(lData);
}
#pragma endregion

#pragma region Binary
string& frmPlcCommunicate::std_string_format(string& _str, const char* _Format, ...)
{
	string tmp;
	va_list marker = NULL;
	va_start(marker, _Format);
	size_t num_of_chars = _vscprintf(_Format, marker);
	if (num_of_chars > tmp.capacity()) {
		tmp.resize(num_of_chars + 1);
	}
	vsprintf_s((char*)tmp.data(), tmp.capacity(), _Format, marker);
	va_end(marker);
	_str = tmp.c_str();
	return _str;
}

string frmPlcCommunicate::Int16ToHexConvert(short va)
{
	short num = (short)va;
	string temp;
	std_string_format(temp, "%02X", num);
	string xx = temp.substr(2, 2) + temp.substr(0, 2);
	return xx;
}

string frmPlcCommunicate::Int32ToHexConvert(int va)
{
	string temp;
	std_string_format(temp, "%04X", va);
	string xx = temp.substr(2, 2) + temp.substr(0, 2);
	return xx;
}

string frmPlcCommunicate::Int48ToHexConvert(int64 va)
{
	string temp;
	std_string_format(temp, "%06X", va);
	string xx = temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
	return xx;
}

string frmPlcCommunicate::Int64ToHexConvert(int64 va)
{
	string temp;
	std_string_format(temp, "%08X", va);
	string xx = temp.substr(6, 2) + temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
	return xx;
}

string frmPlcCommunicate::Int32ToHexConvert2(int va)
{
	string temp;
	std_string_format(temp, "%04X", va);
	string xx = temp.substr(6, 2) + temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
	return xx;
}

#define MAX_BUFF 1024

bool frmPlcCommunicate::BinarySendMessg(QTcpSocket* m_socket, string msg)
{
	int count = msg.length() / 2;
	char datas[MAX_BUFF] = { 0 };
	for (int i = 0; i < count; i++)
	{
		long num = strtol(msg.substr(i * 2, 2).data(), NULL, 16);
		datas[i] = num;
	}
	int retLen = m_socket->write((const char*)datas, count);
	if (retLen <= 0)
	{
		return false;
	}
	return true;
}

string frmPlcCommunicate::BinaryReceiveMsg(QTcpSocket* m_socket)
{
	string re = "";
	//阻塞函数
	m_socket->waitForReadyRead(15);
	QByteArray buffer;
	buffer.resize(MAX_BUFF);
	buffer = m_socket->readAll();
	char buf[MAX_BUFF]; //数组
	int len_array = buffer.size();
	int len_buf = sizeof(buf);
	int len = qMin(len_array, len_buf);
	//QByteArray转char*
	memcpy(buf, buffer, len);
	for (int i = 0; i < MAX_BUFF; i++)
	{
		string temp;
		std_string_format(temp, "%02X", buf[i]);
		re += temp;
	}
	string re_buf = "";
	for (int i = 0; i < 300; i = i + 6)
	{
		if (re.substr(i, 6) != "FFFFFF")
		{
			re_buf += re.substr(i, 6);
		}
	}
	return re_buf;
}

bool frmPlcCommunicate::BinaryWrite1D(QTcpSocket* m_socket, string device, short value)
{
	string sendStr = "500000FFFF0300";
	int len = 8 + 1 * 6;
	string temp = Int32ToHexConvert(len);
	sendStr += temp;
	sendStr += "100002140000";
	sendStr += Int32ToHexConvert(1);
	string name = Int48ToHexConvert(strtol(device.data(), NULL, 10));
	string va;
	if (value >= 0)
	{
		va = Int32ToHexConvert(value);
	}
	else
	{
		va = Int16ToHexConvert(value);
	}
	sendStr += name + "A8" + va;
	BinarySendMessg(m_socket, sendStr);
	string strRead = BinaryReceiveMsg(m_socket);
	if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
		return true;
	return false;
}

bool frmPlcCommunicate::BinaryWrite2D(QTcpSocket* m_socket, string device, int value)
{
	string sendStr = "500000FFFF0300";
	string temp = "";
	int len = 8 + 1 * 8;
	temp = Int32ToHexConvert(len);
	sendStr += temp;
	sendStr += "100002140000";
	sendStr += "0001";
	string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
	string va;
	if (value >= 0)
	{
		va = Int64ToHexConvert(value);
	}
	else
	{
		va = Int32ToHexConvert2(value);
	}
	sendStr += name + "A8" + va;
	BinarySendMessg(m_socket, sendStr);
	string strRead = BinaryReceiveMsg(m_socket);
	if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
		return true;
	return false;
}

bool frmPlcCommunicate::BinaryRead1D(QTcpSocket* m_socket, string device, short& value)
{
	string sendStr = "500000FFFF0300";
	string temp = "";
	int len = 12;
	temp = Int32ToHexConvert(len);
	sendStr += temp;
	sendStr += "100001040000";
	string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
	sendStr += name + "A8" + Int32ToHexConvert(1);
	BinarySendMessg(m_socket, sendStr);
	string strRead = BinaryReceiveMsg(m_socket);
	if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
	{
		short va = 0;
		strRead.erase(0, 28);
		string strTemp1 = "";
		string strTemp2 = "";
		strTemp1 = strRead.substr(0, 2);
		strTemp2 = strRead.substr(2, 2);
		strTemp2 += strTemp1;
		va = strtol(strTemp2.data(), NULL, 16);
		value = va;
		return true;
	}
	return false;
}

bool frmPlcCommunicate::BinaryRead2D(QTcpSocket* m_socket, string device, int& value)
{
	string sendStr = "500000FFFF0300";
	int len = 12;
	string temp = Int32ToHexConvert(len);
	sendStr += temp;
	sendStr += "100001040000";
	string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
	sendStr += name + "A8" + Int32ToHexConvert(2);
	BinarySendMessg(m_socket, sendStr);
	string strRead = BinaryReceiveMsg(m_socket);
	if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
	{
		strRead.erase(0, 28);
		string strTemp1 = strRead.substr(0, 8);
		string strTemp2 = strTemp1.substr(6, 2) + strTemp1.substr(4, 2) + strTemp1.substr(2, 2) + strTemp1.substr(0, 2);
		long long va = strtoll(strTemp2.data(), NULL, 16);
		value = va;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion

//全局变量控制
int QConfig::nFormState = 0;
