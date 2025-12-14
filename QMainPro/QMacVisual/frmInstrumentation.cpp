#include "frmInstrumentation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QWidgetAction>
#include "datavar.h"
#include "modbus-tcp.h"

frmInstrumentation::frmInstrumentation(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/res/ico/network.png"));
	//初始化标题栏
	initTitleBar();
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 270);
	//隐藏水平header
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选	
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
	ui.tableWidget->setItemDelegateForColumn(0, readOnlyDelegate); //设置第1列只读	
	//添加右键菜单
	AddRightButtonMenu();
	connect(ui.comboInstrument, SIGNAL(currentIndexChanged(int)), this, SLOT(slotInstrumentChanged(int)));
	ui.widgetIoIP->setIP("192.168.1.10");
	ui.widgetPlcIP->setIP("192.168.1.20");
	ui.widgetSocketIP->setIP("192.168.1.30");
}

frmInstrumentation::~frmInstrumentation()
{
	this->deleteLater();
}

void frmInstrumentation::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/network.png");
	m_titleBar->setTitleContent("仪器通讯");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmInstrumentation::paintEvent(QPaintEvent* event)
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

void frmInstrumentation::onButtonCloseClicked()
{
	this->close();
}

void frmInstrumentation::on_comboProtocol_currentIndexChanged(int index)
{
	switch (index)
	{
	case 0:
		ui.lbl_ip->setText("本地IP地址：");
		ui.lbl_port->setText("本地端口号：");
		break;
	case 1:
		ui.lbl_ip->setText("远程IP地址：");
		ui.lbl_port->setText("远程端口号：");
		break;
	}
}

//右键菜单
void frmInstrumentation::AddRightButtonMenu()
{
	QMenu* m_menu = new QMenu(this);
	//菜单样式
	QString menuStyle(
		"QMenu::item{"
		"color: rgb(0, 0, 0);"
		"}"
		"QMenu::item:hover{"
		"background-color: rgb(176, 190, 225);"
		"}"
		"QMenu::item:selected{"
		"background-color: rgb(176, 190, 225);"
		"}"
	);
	QString buttonStyle(
		"QPushButton{"
		"color: rgb(0, 0, 0);"
		"border: none;"
		"text-align: left;"
		"font: 9pt Microsoft YaHei;"
		"padding-left: 5px;"
		"padding-right: 5px;"
		"min-height: 23px;"
		"}"
		"QPushButton::hover{"
		"background-color: rgba(176, 190, 225, 200);"
		"}"
		"QPushButton::selected{"
		"background-color: rgba(176, 190, 255, 255);"
		"}"
	);
	m_menu->setStyleSheet(menuStyle);
	QPushButton* moveUpAction_buf = new QPushButton(m_menu);
	moveUpAction_buf->setStyleSheet(buttonStyle);
	moveUpAction_buf->setText("上移");
	moveUpAction_buf->setIconSize(QSize(20, 20));
	moveUpAction_buf->setIcon(QIcon(":/res/ico/previous.png"));
	QWidgetAction* moveUpAction = new QWidgetAction(this);
	moveUpAction->setDefaultWidget(moveUpAction_buf);
	connect(moveUpAction_buf, &QPushButton::clicked, this, &frmInstrumentation::slot_MoveUp);
	connect(moveUpAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(moveUpAction);
	QPushButton* moveDownAction_buf = new QPushButton(m_menu);
	moveDownAction_buf->setStyleSheet(buttonStyle);
	moveDownAction_buf->setText("下移");
	moveDownAction_buf->setIconSize(QSize(20, 20));
	moveDownAction_buf->setIcon(QIcon(":/res/ico/next.png"));
	QWidgetAction* moveDownAction = new QWidgetAction(this);
	moveDownAction->setDefaultWidget(moveDownAction_buf);
	connect(moveDownAction_buf, &QPushButton::clicked, this, &frmInstrumentation::slot_MoveDown);
	connect(moveDownAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(moveDownAction);
	QPushButton* deleteNameAction_buf = new QPushButton(m_menu);
	deleteNameAction_buf->setStyleSheet(buttonStyle);
	deleteNameAction_buf->setText("删除");
	deleteNameAction_buf->setIconSize(QSize(21, 21));
	deleteNameAction_buf->setIcon(QIcon(":/res/ico/del.png"));
	QWidgetAction* deleteNameAction = new QWidgetAction(this);
	deleteNameAction->setDefaultWidget(deleteNameAction_buf);
	connect(deleteNameAction_buf, &QPushButton::clicked, this, &frmInstrumentation::slot_DeleteName);
	connect(deleteNameAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(deleteNameAction);
	//给控件设置上下文菜单策略
	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	//给信号设置相应的槽函数
	connect(ui.tableWidget, &QTableWidget::customContextMenuRequested, [=](const QPoint& pos)
		{
			//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角
			m_menu->exec(QCursor::pos());
		});
}

void frmInstrumentation::slotInstrumentChanged(int index)
{
	switch (index) {
	case 0:
		ui.comboInstrumentName->clear();
		ui.comboInstrumentName->addItem("DAM-E3021N");
		ui.stackedWidget->setCurrentIndex(0);
		break;
	case 1:
		ui.comboInstrumentName->clear();
		ui.comboInstrumentName->addItem("Mitsubishi PLC");
		ui.comboInstrumentName->addItem("Omron PLC");
		ui.comboInstrumentName->addItem("Siemens PLC");
		ui.comboInstrumentName->addItem("Keyence PLC");
		ui.comboInstrumentName->addItem("Inovance PLC"); //汇川PLC
		ui.stackedWidget->setCurrentIndex(1);
		break;
	case 2:
		ui.comboInstrumentName->clear();
		ui.comboInstrumentName->addItem("SerialPort");
		ui.stackedWidget->setCurrentIndex(2);
		break;
	case 3:
		ui.comboInstrumentName->clear();
		ui.comboInstrumentName->addItem("EthernetTcp");
		ui.stackedWidget->setCurrentIndex(3);
		break;
	}
}

void frmInstrumentation::on_btnAdd_clicked()
{
	if (ui.comboInstrumentName->currentText() == QString())
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("未找到或选择仪器！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "未找到或选择仪器！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	else
	{
		int count = ui.tableWidget->rowCount();
		QVector<QString> all_instrument = QVector<QString>(300);
		all_instrument.clear();
		for (int i = 0; i < count; i++)
		{
			all_instrument.append(ui.tableWidget->item(i, 0)->text());
		}
		QVector<int> all_instrument_max = QVector<int>(100);
		int value = 0;
		QTableWidgetItem* item_type;
		all_instrument_max.clear();
		switch (ui.comboInstrument->currentIndex()) {
		case 0:
			for (int i = 0; i < count; i++)
			{
				QStringList strs;
				strs.reserve(10);
				strs.clear();
				strs = all_instrument[i].split("_");
				if (strs[0] == "DAM-E3021N")
				{
					all_instrument_max.append(strs[1].toInt());
				}
			}
			if (all_instrument_max.size() != 0)
			{
				qSort(all_instrument_max.begin(), all_instrument_max.end()); //排序
				value = GetValue(all_instrument_max);
			}
			ui.tableWidget->setRowCount(count + 1);  //设置行数
			if (value == 0 || all_instrument_max[0] > 1)
			{
				value = 1;
			}
			item_type = new QTableWidgetItem(ui.comboInstrumentName->currentText() + "_" + QString::number(value));
			item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			ui.tableWidget->setItem(count, 0, item_type);
			break;
		case 1:
			for (int i = 0; i < count; i++)
			{
				QStringList strs;
				strs.reserve(10);
				strs.clear();
				strs = all_instrument[i].split("_");
				if (strs[0] == "Mitsubishi PLC" || strs[0] == "Omron PLC" || strs[0] == "Siemens PLC" || strs[0] == "Keyence PLC" || strs[0] == "Inovance PLC")
				{
					all_instrument_max.append(strs[1].toInt());
				}
			}
			if (all_instrument_max.size() != 0)
			{
				qSort(all_instrument_max.begin(), all_instrument_max.end()); //排序
				value = GetValue(all_instrument_max);
			}
			ui.tableWidget->setRowCount(count + 1);  //设置行数
			if (value == 0 || all_instrument_max[0] > 1)
			{
				value = 1;
			}
			item_type = new QTableWidgetItem(ui.comboInstrumentName->currentText() + "_" + QString::number(value));
			item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			ui.tableWidget->setItem(count, 0, item_type);
			break;
		case 2:
			for (int i = 0; i < count; i++)
			{
				QStringList strs;
				strs.reserve(10);
				strs.clear();
				strs = all_instrument[i].split("_");
				if (strs[0] == "SerialPort")
				{
					all_instrument_max.append(strs[1].toInt());
				}
			}
			if (all_instrument_max.size() != 0)
			{
				qSort(all_instrument_max.begin(), all_instrument_max.end()); //排序
				value = GetValue(all_instrument_max);
			}
			ui.tableWidget->setRowCount(count + 1);  //设置行数
			if (value == 0 || all_instrument_max[0] > 1)
			{
				value = 1;
			}
			item_type = new QTableWidgetItem(ui.comboInstrumentName->currentText() + "_" + QString::number(value));
			item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			ui.tableWidget->setItem(count, 0, item_type);
			break;
		case 3:
			for (int i = 0; i < count; i++)
			{
				QStringList strs;
				strs.reserve(10);
				strs.clear();
				strs = all_instrument[i].split("_");
				if (strs[0] == "EthernetTcp")
				{
					all_instrument_max.append(strs[1].toInt());
				}
			}
			if (all_instrument_max.size() != 0)
			{
				qSort(all_instrument_max.begin(), all_instrument_max.end()); //排序
				value = GetValue(all_instrument_max);
			}
			ui.tableWidget->setRowCount(count + 1);  //设置行数
			if (value == 0 || all_instrument_max[0] > 1)
			{
				value = 1;
			}
			item_type = new QTableWidgetItem(ui.comboInstrumentName->currentText() + "_" + QString::number(value));
			item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			ui.tableWidget->setItem(count, 0, item_type);
			break;
		}
	}
}

int frmInstrumentation::GetValue(QVector<int> n)
{
	int low = 0;
	int high = n.count() - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (n[mid] > n[0] + mid) high = mid;
		else low = mid;
		if (high - low == 1)
		{
			if (n[high] - n[low] == 1) low = high;
			break;
		}
	}
	return n[low] + 1;
}

void frmInstrumentation::on_btnConnect_clicked()
{
	//连接仪器
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择仪器通讯名称或编号为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择仪器通讯名称或编号为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	QStringList strs = ui.lblType->text().split("_");
	if (strs[0] == "DAM-E3021N")
	{
		//通用I/O
		comm_keys.clear();
		comm_keys = global_io_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				count = 1;
				ui.widgetIoIP->setIP(global_io_content.value(key).global_ip);
				ui.spinIoPort->setValue(global_io_content.value(key).global_port);
				ui.spinIoTimeOut->setValue(global_io_content.value(key).global_timeout);
				ui.txtIoRemark->setText(global_io_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		for (int n = 0; n < dataVar::io_client_ip.count(); n++)
		{
			if (dataVar::io_client_ip[n] == ui.widgetIoIP->getIP() && dataVar::io_client_port[n] == ui.spinIoPort->text())
			{
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "模块已连接！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "模块已连接！");
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
				return;
			}
		}
		io_client = new QTcpSocket(this);
		io_client->connectToHost(QHostAddress(ui.widgetIoIP->getIP()), ui.spinIoPort->value());
		connect(io_client, SIGNAL(connected()), this, SLOT(onIoConnected()));
		connect(io_client, SIGNAL(disconnected()), this, SLOT(onIoDisconnected()));
		bool io_client_connected = io_client->waitForConnected(ui.spinIoTimeOut->value());
		if (io_client_connected == false)
		{
			disconnect(io_client, SIGNAL(connected()), this, SLOT(onIoConnected()));
			disconnect(io_client, SIGNAL(disconnected()), this, SLOT(onIoDisconnected()));
			delete io_client;
			io_client = nullptr;
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "模块连接失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "模块连接失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
		}
		return;
	}
	else if (strs[0] == "Mitsubishi PLC")
	{
		//PLC通信
		comm_keys.clear();
		comm_keys = global_plc_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				count = 1;
				ui.widgetPlcIP->setIP(global_plc_content.value(key).global_ip);
				ui.spinPlcPort->setValue(global_plc_content.value(key).global_port);
				ui.spinPlcTimeOut->setValue(global_plc_content.value(key).global_timeout);
				ui.txtPlcRemark->setText(global_plc_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		for (int n = 0; n < dataVar::mit_plc_client_ip.count(); n++)
		{
			if (dataVar::mit_plc_client_ip[n] == ui.widgetPlcIP->getIP() && dataVar::mit_plc_client_port[n] == ui.spinPlcPort->text())
			{
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "可编程控制器已连接！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "可编程控制器已连接！");
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
				return;
			}
		}
		mit_plc_client = new QTcpSocket(this);
		mit_plc_client->connectToHost(QHostAddress(ui.widgetPlcIP->getIP()), ui.spinPlcPort->value());
		connect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
		connect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
		bool mit_plc_client_connected = mit_plc_client->waitForConnected(ui.spinPlcTimeOut->value());
		if (mit_plc_client_connected == false)
		{
			disconnect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
			disconnect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
			delete mit_plc_client;
			mit_plc_client = nullptr;
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "可编程控制器连接失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "可编程控制器连接失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
		}
		return;
	}
	else if (strs[0] == "Inovance PLC")
	{
	//汇川PLC通信
	comm_keys.clear();
	comm_keys = global_plc_content.uniqueKeys();
	int count = 0;
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (key == ui.lblType->text())
		{
			count = 1;
			ui.widgetPlcIP->setIP(global_plc_content.value(key).global_ip);
			ui.spinPlcPort->setValue(global_plc_content.value(key).global_port);
			ui.spinPlcTimeOut->setValue(global_plc_content.value(key).global_timeout);
			ui.txtPlcRemark->setText(global_plc_content.value(key).global_remark);
		}
	}
	if (count == 0)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器通讯参数未保存！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	for (int n = 0; n < dataVar::mit_plc_client_ip.count(); n++)
	{
		if (dataVar::mit_plc_client_ip[n] == ui.widgetPlcIP->getIP() && dataVar::mit_plc_client_port[n] == ui.spinPlcPort->text())
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "可编程控制器已连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "可编程控制器已连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	mit_plc_client = new QTcpSocket(this);
	mit_plc_client->connectToHost(QHostAddress(ui.widgetPlcIP->getIP()), ui.spinPlcPort->value());
	connect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
	connect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
	bool mit_plc_client_connected = InovancePLC_connect(QHostAddress(ui.widgetPlcIP->getIP()).toString(), ui.spinPlcPort->value()); //mit_plc_client->waitForConnected(ui.spinPlcTimeOut->value());
	if (mit_plc_client_connected == false)
	{
		disconnect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
		disconnect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
		delete mit_plc_client;
		mit_plc_client = nullptr;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "可编程控制器连接失败！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "可编程控制器连接失败！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
	}
	return;
	}
	else if (strs[0] == "SerialPort")
	{
		//串口通信
		comm_keys.clear();
		comm_keys = global_serialport_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				count = 1;
				ui.comboSerialPort->setCurrentText(global_serialport_content.value(key).global_serial_port);
				ui.comboBaudRate->setCurrentText(global_serialport_content.value(key).global_baud_rate);
				ui.comboCheckDigit->setCurrentText(global_serialport_content.value(key).global_check_digit);
				ui.comboDataBits->setCurrentText(global_serialport_content.value(key).global_data_bits);
				ui.comboStopBit->setCurrentText(global_serialport_content.value(key).global_stop_bit);
				ui.comboFlowControl->setCurrentText(global_serialport_content.value(key).global_flowcontrol);
				ui.txtSPRemark->setText(global_serialport_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		s_port = new QSerialPort(this);
		s_port->setPortName(ui.comboSerialPort->currentText());  //串口号
		s_port->setBaudRate(ui.comboBaudRate->currentText().toInt());  //波特率
		QSerialPort::Parity parity;   //校验位
		if (ui.comboCheckDigit->currentText() == "无")
		{
			parity = QSerialPort::NoParity;
		}
		else if (ui.comboCheckDigit->currentText() == "奇")
		{
			parity = QSerialPort::Parity::OddParity;
		}
		else if (ui.comboCheckDigit->currentText() == "偶")
		{
			parity = QSerialPort::Parity::EvenParity;
		}
		else if (ui.comboCheckDigit->currentText() == "标志")
		{
			parity = QSerialPort::Parity::MarkParity;
		}
		else if (ui.comboCheckDigit->currentText() == "空格")
		{
			parity = QSerialPort::Parity::SpaceParity;
		}
		s_port->setParity(parity);
		QSerialPort::DataBits dataBits;  //数据位
		if (ui.comboDataBits->currentText() == "5")
		{
			dataBits = QSerialPort::Data5;
		}
		else if (ui.comboDataBits->currentText() == "6")
		{
			dataBits = QSerialPort::Data6;
		}
		else if (ui.comboDataBits->currentText() == "7")
		{
			dataBits = QSerialPort::Data7;
		}
		else if (ui.comboDataBits->currentText() == "8")
		{
			dataBits = QSerialPort::Data8;
		}
		s_port->setDataBits(dataBits);
		QSerialPort::StopBits stopBits;  //停止位
		if (ui.comboStopBit->currentText() == "1")
		{
			stopBits = QSerialPort::OneStop;
		}
		else if (ui.comboStopBit->currentText() == "1.5")
		{
			stopBits = QSerialPort::OneAndHalfStop;
		}
		else if (ui.comboStopBit->currentText() == "2")
		{
			stopBits = QSerialPort::TwoStop;
		}
		s_port->setStopBits(stopBits);
		QSerialPort::FlowControl flowControl;  //流控制
		if (ui.comboFlowControl->currentText() == "无")
		{
			flowControl = QSerialPort::FlowControl::NoFlowControl;
		}
		else if (ui.comboFlowControl->currentText() == "硬件")
		{
			flowControl = QSerialPort::FlowControl::HardwareControl;
		}
		else if (ui.comboFlowControl->currentText() == "软件")
		{
			flowControl = QSerialPort::FlowControl::SoftwareControl;
		}
		s_port->setFlowControl(flowControl);
		s_port_state = s_port->open(QIODevice::ReadWrite);
		if (s_port_state == true)
		{
			gVariable::SerialPortVar.serialport_value = s_port;
			gVariable::SerialPortVar.connect_state = 1;
			gVariable::SerialPortVar.portname_value = ui.comboSerialPort->currentText();
			gVariable::SerialPortVar.baudrate_value = ui.comboBaudRate->currentText().toInt();
			gVariable::SerialPortVar.parity_value = parity;
			gVariable::SerialPortVar.databits_value = dataBits;
			gVariable::SerialPortVar.stopbits_value = stopBits;
			gVariable::SerialPortVar.flowcontrol_value = flowControl;
			gVariable::SerialPortVar.remark_value = ui.txtSPRemark->text();
			gVariable::serialport_variable_link.insert(ui.lblType->text(), gVariable::SerialPortVar);
			emit dataVar::fProItemTab->sig_InfoClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "串口打开成功！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "串口打开成功！");
			msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
			msgBox.exec();
		}
		else
		{
			delete s_port;
			s_port = nullptr;
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "串口已打开或打开失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "串口已打开或打开失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "EthernetTcp")
	{
		//TCP/IP通信
		comm_keys.clear();
		comm_keys = global_tcp_content.uniqueKeys();
		int count = 0;
		QString strProtocol;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				count = 1;
				strProtocol = global_tcp_content.value(key).global_protocol;
				ui.comboProtocol->setCurrentText(strProtocol);
				ui.widgetSocketIP->setIP(global_tcp_content.value(key).global_ip);
				ui.spinSocketPort->setValue(global_tcp_content.value(key).global_port);
				ui.txtSocketRemark->setText(global_tcp_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		if (strProtocol == "TCP Server")
		{
			server = new QTcpServer(this);
			bool server_state = server->listen(QHostAddress::Any, ui.spinSocketPort->value());
			if (server_state == true)
			{
				gVariable::SocketTcpServerVar.server_value = server;
				gVariable::SocketTcpServerVar.connect_state = 1;
				gVariable::SocketTcpServerVar.protocol_value = ui.comboProtocol->currentText();
				gVariable::SocketTcpServerVar.ip_value = ui.widgetSocketIP->getIP();
				gVariable::SocketTcpServerVar.port_value = ui.spinSocketPort->value();
				gVariable::SocketTcpServerVar.remark_value = ui.txtSocketRemark->text();
				gVariable::sockettcpserver_variable_link.insert(ui.lblType->text(), gVariable::SocketTcpServerVar);
				emit dataVar::fProItemTab->sig_InfoClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "服务器打开成功！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "服务器打开成功！");
				msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
				msgBox.exec();
			}
			else
			{
				delete server;
				server = nullptr;
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "服务器已打开！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "服务器已打开！");
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
				return;
			}
		}
		else
		{
			for (int n = 0; n < dataVar::tcp_client_ip.count(); n++)
			{
				if (dataVar::tcp_client_ip[n] == ui.widgetSocketIP->getIP() && dataVar::tcp_client_port[n] == ui.spinSocketPort->text())
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "客户端已连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "客户端已连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
			}
			client = new QTcpSocket(this);
			client->connectToHost(QHostAddress(ui.widgetSocketIP->getIP()), ui.spinSocketPort->value());
			connect(client, SIGNAL(connected()), this, SLOT(onTcpConnected()));
			connect(client, SIGNAL(disconnected()), this, SLOT(onTcpDisconnected()));
			bool client_connected = client->waitForConnected(5000);
			if (client_connected == false)
			{
				disconnect(client, SIGNAL(connected()), this, SLOT(onTcpConnected()));
				disconnect(client, SIGNAL(disconnected()), this, SLOT(onTcpDisconnected()));
				delete client;
				client = nullptr;
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "客户端连接失败！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "客户端连接失败！");
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
			}
			return;
		}
	}
	//更新通讯工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
			}
		}
	}
}

//初始化通用I/O连接
void frmInstrumentation::InitIoConnect(QString io_key_value, QString ip_value, int port_value, int over_time_value)
{
	init_key_value = io_key_value;
	init_state = 1;
	io_client = new QTcpSocket(this);
	io_client->connectToHost(QHostAddress(ip_value), port_value);
	connect(io_client, SIGNAL(connected()), this, SLOT(onIoConnected()));
	connect(io_client, SIGNAL(disconnected()), this, SLOT(onIoDisconnected()));
	bool io_client_connected = io_client->waitForConnected(over_time_value);
	if (io_client_connected == false)
	{
		disconnect(io_client, SIGNAL(connected()), this, SLOT(onIoConnected()));
		disconnect(io_client, SIGNAL(disconnected()), this, SLOT(onIoDisconnected()));
		delete io_client;
		io_client = nullptr;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(io_key_value + "模块连接失败！");
		dataVar::io_client_ip.removeOne(ip_value);
		dataVar::io_client_port.removeOne(QString::number(port_value));
	}
	else
	{
		gVariable::GeneralIoVar.io_value = io_client;
		gVariable::generalio_variable_link.insert(io_key_value, gVariable::GeneralIoVar);
		//更新通讯工具
		QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
		for (int i = 0; i < link_keys.length(); i++)
		{
			int key = link_keys[i];
			for (int j = 0; j < 20; j++)
			{
				if (j == key)
				{
					QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
				}
			}
		}
	}
}

//初始化PLC通信连接
void frmInstrumentation::InitPlcConnect(QString plc_key_value, QString ip_value, int port_value, int over_time_value)
{
	init_key_value = plc_key_value;
	init_state = 1;
	QStringList strs = plc_key_value.split("_");
	if (strs[0] == "Mitsubishi PLC")
	{
		mit_plc_client = new QTcpSocket(this);
		mit_plc_client->connectToHost(QHostAddress(ip_value), port_value);
		connect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
		connect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
		bool mit_plc_client_connected = mit_plc_client->waitForConnected(over_time_value);
		if (mit_plc_client_connected == false)
		{
			disconnect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
			disconnect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
			delete mit_plc_client;
			mit_plc_client = nullptr;
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(plc_key_value + "可编程控制器连接失败！");
			dataVar::mit_plc_client_ip.removeOne(ip_value);
			dataVar::mit_plc_client_port.removeOne(QString::number(port_value));
		}
		else
		{
			gVariable::PlcCommunicateVar.mit_value = mit_plc_client;
			gVariable::plccommunicate_variable_link.insert(plc_key_value, gVariable::PlcCommunicateVar);
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
	}
	else if (strs[0] == "Inovance PLC")
	{
		mit_plc_client = new QTcpSocket(this);
		mit_plc_client->connectToHost(QHostAddress(ip_value), port_value);
		
		connect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
		connect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
		bool mit_plc_client_connected = InovancePLC_connect(QHostAddress(ip_value).toString(), port_value); //mit_plc_client->waitForConnected(over_time_value);
		if (mit_plc_client_connected == false)
		{
			disconnect(mit_plc_client, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
			disconnect(mit_plc_client, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
			delete mit_plc_client;
			mit_plc_client = nullptr;
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(plc_key_value + "可编程控制器连接失败！");
			dataVar::mit_plc_client_ip.removeOne(ip_value);
			dataVar::mit_plc_client_port.removeOne(QString::number(port_value));
		}
		else
		{
			gVariable::PlcCommunicateVar.mit_value = mit_plc_client;
			gVariable::plccommunicate_variable_link.insert(plc_key_value, gVariable::PlcCommunicateVar);
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
	}
}
bool frmInstrumentation::InovancePLC_connect(QString IP,int Port)
{
	try
	{
		std::cout << "modbus init success" << std::endl;

		// 设置PLC的IP地址与端口，建立TCP连接
		ctx = modbus_new_tcp(IP.toStdString().c_str(), Port);
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
			inv_plc_client_state = 1;
			gVariable::PlcCommunicateVar.ctx = ctx;
			return true;
		}
	}
	catch (...) {
		return false;
	}
	
}
//初始化串口通信连接
void frmInstrumentation::InitSerialportConnect(QString serialport_key_value, QString portname_value, int baudrate_value, QString parity_value, QString databits_value, QString stopbits_value, QString flowcontrol_value)
{
	init_key_value = serialport_key_value;
	s_port = new QSerialPort(this);
	s_port->setPortName(portname_value);  //串口号
	s_port->setBaudRate(baudrate_value);  //波特率
	QSerialPort::Parity parity;   //校验位
	if (parity_value == "无")
	{
		parity = QSerialPort::NoParity;
	}
	else if (parity_value == "奇")
	{
		parity = QSerialPort::Parity::OddParity;
	}
	else if (parity_value == "偶")
	{
		parity = QSerialPort::Parity::EvenParity;
	}
	else if (parity_value == "标志")
	{
		parity = QSerialPort::Parity::MarkParity;
	}
	else if (parity_value == "空格")
	{
		parity = QSerialPort::Parity::SpaceParity;
	}
	s_port->setParity(parity);
	QSerialPort::DataBits dataBits;  //数据位
	if (databits_value == "5")
	{
		dataBits = QSerialPort::Data5;
	}
	else if (databits_value == "6")
	{
		dataBits = QSerialPort::Data6;
	}
	else if (databits_value == "7")
	{
		dataBits = QSerialPort::Data7;
	}
	else if (databits_value == "8")
	{
		dataBits = QSerialPort::Data8;
	}
	s_port->setDataBits(dataBits);
	QSerialPort::StopBits stopBits;  //停止位
	if (stopbits_value == "1")
	{
		stopBits = QSerialPort::OneStop;
	}
	else if (stopbits_value == "1.5")
	{
		stopBits = QSerialPort::OneAndHalfStop;
	}
	else if (stopbits_value == "2")
	{
		stopBits = QSerialPort::TwoStop;
	}
	s_port->setStopBits(stopBits);
	QSerialPort::FlowControl flowControl;  //流控制
	if (flowcontrol_value == "无")
	{
		flowControl = QSerialPort::FlowControl::NoFlowControl;
	}
	else if (flowcontrol_value == "硬件")
	{
		flowControl = QSerialPort::FlowControl::HardwareControl;
	}
	else if (flowcontrol_value == "软件")
	{
		flowControl = QSerialPort::FlowControl::SoftwareControl;
	}
	s_port->setFlowControl(flowControl);
	s_port_state = s_port->open(QIODevice::ReadWrite);
	if (s_port_state == true)
	{
		gVariable::SerialPortVar.serialport_value = s_port;
		gVariable::serialport_variable_link.insert(serialport_key_value, gVariable::SerialPortVar);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log(serialport_key_value + "串口打开成功！");
		//更新通讯工具
		QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
		for (int i = 0; i < link_keys.length(); i++)
		{
			int key = link_keys[i];
			for (int j = 0; j < 20; j++)
			{
				if (j == key)
				{
					QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
				}
			}
		}
	}
	else
	{
		delete s_port;
		s_port = nullptr;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(serialport_key_value + "串口已打开或打开失败！");
	}
}

//初始化TCP/IP服务器连接
void frmInstrumentation::InitServerConnect(QString server_key_value, int port_value)
{
	init_key_value = server_key_value;
	server = new QTcpServer(this);
	bool server_state = server->listen(QHostAddress::Any, port_value);
	if (server_state == true)
	{
		gVariable::SocketTcpServerVar.server_value = server;
		gVariable::sockettcpserver_variable_link.insert(server_key_value, gVariable::SocketTcpServerVar);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log(server_key_value + "服务器打开成功！");
		//更新通讯工具
		QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
		for (int i = 0; i < link_keys.length(); i++)
		{
			int key = link_keys[i];
			for (int j = 0; j < 20; j++)
			{
				if (j == key)
				{
					QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
				}
			}
		}
	}
	else
	{
		delete server;
		server = nullptr;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(server_key_value + "服务器已打开或打开失败！");
	}
}

//初始化TCP/IP客户端连接
void frmInstrumentation::InitClientConnect(QString client_key_value, QString ip_value, int port_value)
{
	init_key_value = client_key_value;
	init_state = 1;
	client = new QTcpSocket(this);
	client->connectToHost(QHostAddress(ip_value), port_value);
	connect(client, SIGNAL(connected()), this, SLOT(onTcpConnected()));
	connect(client, SIGNAL(disconnected()), this, SLOT(onTcpDisconnected()));
	bool client_connected = client->waitForConnected(5000);
	if (client_connected == false)
	{
		disconnect(client, SIGNAL(connected()), this, SLOT(onTcpConnected()));
		disconnect(client, SIGNAL(disconnected()), this, SLOT(onTcpDisconnected()));
		delete client;
		client = nullptr;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(client_key_value + "客户端连接失败！");
		dataVar::tcp_client_ip.removeOne(ip_value);
		dataVar::tcp_client_port.removeOne(QString::number(port_value));
	}
	else
	{
		gVariable::SocketTcpClientVar.client_value = client;
		gVariable::sockettcpclient_variable_link.insert(client_key_value, gVariable::SocketTcpClientVar);
		//更新通讯工具
		QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
		for (int i = 0; i < link_keys.length(); i++)
		{
			int key = link_keys[i];
			for (int j = 0; j < 20; j++)
			{
				if (j == key)
				{
					QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
				}
			}
		}
	}
}

void frmInstrumentation::onIoConnected()
{
	try
	{
		if (init_state == 0)
		{
			dataVar::io_client_ip.append(ui.widgetIoIP->getIP());
			dataVar::io_client_port.append(QString::number(ui.spinIoPort->value()));
			gVariable::GeneralIoVar.io_value = io_client;
			gVariable::GeneralIoVar.connect_state = 1;
			gVariable::GeneralIoVar.ip_value = ui.widgetIoIP->getIP();
			gVariable::GeneralIoVar.port_value = ui.spinIoPort->value();
			gVariable::GeneralIoVar.over_time_value = ui.spinIoTimeOut->value();
			gVariable::GeneralIoVar.remark_value = ui.txtIoRemark->text();
			gVariable::generalio_variable_link.insert(ui.lblType->text(), gVariable::GeneralIoVar);
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
		emit dataVar::fProItemTab->sig_InfoClick();
		if (init_state == 0)
		{
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "模块连接成功！");
		}
		else
		{
			emit dataVar::fProItemTab->sig_Log(init_key_value + "模块连接成功！");
		}
		if (init_state == 0)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "模块连接成功！");
			msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
			msgBox.exec();
		}
		init_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::onIoDisconnected()
{
	try
	{
		if (dataVar::comm_state_buf == 1)
		{
			return;
		}
		if (io_client_state == 0)
		{
			comm_keys.clear();
			comm_keys = gVariable::generalio_variable_link.uniqueKeys();
			for (int k = 0; k < comm_keys.length(); k++)
			{
				QString key = comm_keys[k];
				if (io_client != nullptr)
				{
					disconnect(gVariable::generalio_variable_link.value(key).io_value, SIGNAL(connected()), this, SLOT(onIoConnected()));
					disconnect(gVariable::generalio_variable_link.value(key).io_value, SIGNAL(disconnected()), this, SLOT(onIoDisconnected()));
					if (gVariable::generalio_variable_link.value(key).io_value != nullptr)
					{
						gVariable::GeneralIoVar.connect_state = 0;
						dataVar::io_client_ip.removeOne(gVariable::generalio_variable_link.value(key).ip_value);
						dataVar::io_client_port.removeOne(QString::number(gVariable::generalio_variable_link.value(key).port_value));
						gVariable::generalio_variable_link.value(key).io_value->close();
						gVariable::generalio_variable_link.value(key).io_value->deleteLater();
						gVariable::GeneralIoVar.io_value = nullptr;
						gVariable::generalio_variable_link.insert(key, gVariable::GeneralIoVar);
						io_client = nullptr;
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log(key + "模块已断开连接，请检查网口或电源！");
					}
				}
			}
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
		io_client_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::onMitPlcConnected()
{
	try
	{
		if (init_state == 0)
		{
			dataVar::mit_plc_client_ip.append(ui.widgetPlcIP->getIP());
			dataVar::mit_plc_client_port.append(QString::number(ui.spinPlcPort->value()));
			gVariable::PlcCommunicateVar.ctx = ctx;
			gVariable::PlcCommunicateVar.mit_value = mit_plc_client;
			gVariable::PlcCommunicateVar.connect_state = 1;
			gVariable::PlcCommunicateVar.plc_type = ui.comboInstrumentName->itemText(ui.comboInstrumentName->currentIndex()); //"Mitsubishi PLC";
			gVariable::PlcCommunicateVar.mit_ip_value = ui.widgetPlcIP->getIP();
			gVariable::PlcCommunicateVar.mit_port_value = ui.spinPlcPort->value();
			gVariable::PlcCommunicateVar.mit_over_time_value = ui.spinPlcTimeOut->value();
			gVariable::PlcCommunicateVar.mit_remark_value = ui.txtPlcRemark->text();
			gVariable::plccommunicate_variable_link.insert(ui.lblType->text(), gVariable::PlcCommunicateVar);
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
		emit dataVar::fProItemTab->sig_InfoClick();
		if (init_state == 0)
		{
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "可编程控制器连接成功！");
		}
		else
		{
			emit dataVar::fProItemTab->sig_Log(init_key_value + "可编程控制器连接成功！");
		}
		if (init_state == 0)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "可编程控制器连接成功！");
			msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
			msgBox.exec();
		}
		init_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::onMitPlcDisconnected()
{
	try
	{
		if (dataVar::comm_state_buf == 1)
		{
			return;
		}
		if (mit_plc_client_state == 0)
		{
			comm_keys.clear();
			comm_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
			for (int k = 0; k < comm_keys.length(); k++)
			{
				QString key = comm_keys[k];
				if (mit_plc_client != nullptr)
				{
					disconnect(gVariable::plccommunicate_variable_link.value(key).mit_value, SIGNAL(connected()), this, SLOT(onMitPlcConnected()));
					disconnect(gVariable::plccommunicate_variable_link.value(key).mit_value, SIGNAL(disconnected()), this, SLOT(onMitPlcDisconnected()));
					if (gVariable::plccommunicate_variable_link.value(key).mit_value != nullptr)
					{

						gVariable::PlcCommunicateVar.connect_state = 0;
						dataVar::mit_plc_client_ip.removeOne(gVariable::plccommunicate_variable_link.value(key).mit_ip_value);
						dataVar::mit_plc_client_port.removeOne(QString::number(gVariable::plccommunicate_variable_link.value(key).mit_port_value));
						gVariable::plccommunicate_variable_link.value(key).mit_value->close();
						gVariable::plccommunicate_variable_link.value(key).mit_value->deleteLater();
						gVariable::PlcCommunicateVar.mit_value = nullptr;
						gVariable::PlcCommunicateVar.ctx = nullptr;
						gVariable::plccommunicate_variable_link.insert(key, gVariable::PlcCommunicateVar);
						mit_plc_client = nullptr;
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log(key + "PLC已断开连接，请检查网口或电源！");
					}
				}
			}
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
		mit_plc_client_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::onTcpConnected()
{
	try
	{
		if (init_state == 0)
		{
			dataVar::tcp_client_ip.append(ui.widgetSocketIP->getIP());
			dataVar::tcp_client_port.append(QString::number(ui.spinSocketPort->value()));
			gVariable::SocketTcpClientVar.client_value = client;
			gVariable::SocketTcpClientVar.connect_state = 1;
			gVariable::SocketTcpClientVar.protocol_value = ui.comboProtocol->currentText();
			gVariable::SocketTcpClientVar.ip_value = ui.widgetSocketIP->getIP();
			gVariable::SocketTcpClientVar.port_value = ui.spinSocketPort->value();
			gVariable::SocketTcpClientVar.remark_value = ui.txtSocketRemark->text();
			gVariable::sockettcpclient_variable_link.insert(ui.lblType->text(), gVariable::SocketTcpClientVar);
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}		
		emit dataVar::fProItemTab->sig_InfoClick();
		if (init_state == 0)
		{
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "客户端连接成功！");
		}
		else
		{
			emit dataVar::fProItemTab->sig_Log(init_key_value + "客户端连接成功！");
		}
		if (init_state == 0)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "客户端连接成功！");
			msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
			msgBox.exec();
		}
		init_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::onTcpDisconnected()
{
	try
	{
		if (dataVar::comm_state_buf == 1)
		{
			return;
		}
		if (client_state == 0)
		{
			comm_keys.clear();
			comm_keys = gVariable::sockettcpclient_variable_link.uniqueKeys();
			for (int k = 0; k < comm_keys.length(); k++)
			{
				QString key = comm_keys[k];
				if (gVariable::sockettcpclient_variable_link.value(key).protocol_value != "TCP Server")
				{
					if (client != nullptr)
					{
						disconnect(gVariable::sockettcpclient_variable_link.value(key).client_value, SIGNAL(connected()), this, SLOT(onTcpConnected()));
						disconnect(gVariable::sockettcpclient_variable_link.value(key).client_value, SIGNAL(disconnected()), this, SLOT(onTcpDisconnected()));						
						if (gVariable::sockettcpclient_variable_link.value(key).client_value != nullptr)
						{
							gVariable::SocketTcpClientVar.connect_state = 0;
							dataVar::tcp_client_ip.removeOne(gVariable::sockettcpclient_variable_link.value(key).ip_value);
							dataVar::tcp_client_port.removeOne(QString::number(gVariable::sockettcpclient_variable_link.value(key).port_value));
							gVariable::sockettcpclient_variable_link.value(key).client_value->close();
							gVariable::sockettcpclient_variable_link.value(key).client_value->deleteLater();
							gVariable::SocketTcpClientVar.client_value = nullptr;
							gVariable::sockettcpclient_variable_link.insert(key, gVariable::SocketTcpClientVar);
							client = nullptr;
							emit dataVar::fProItemTab->sig_ErrorClick();
							emit dataVar::fProItemTab->sig_Log(key + "服务器已断开连接，请检查网口或电源！");
						}
					}
				}
			}
			//更新通讯工具
			QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
			for (int i = 0; i < link_keys.length(); i++)
			{
				int key = link_keys[i];
				for (int j = 0; j < 20; j++)
				{
					if (j == key)
					{
						QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
					}
				}
			}
		}
		client_state = 0;
	}
	catch (...) {}
}

void frmInstrumentation::on_btnDisconnect_clicked()
{
	//断开仪器
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择仪器通讯名称或编号为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择仪器通讯名称或编号为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	QStringList strs = ui.lblType->text().split("_");
	if (strs[0] == "DAM-E3021N")
	{
		//通用I/O
		comm_keys.clear();
		comm_keys = gVariable::generalio_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::generalio_variable_link.value(key).io_value->isOpen() == true)
				{
					io_client_state = 1;
					gVariable::GeneralIoVar.connect_state = 0;
					dataVar::io_client_ip.removeOne(gVariable::generalio_variable_link.value(key).ip_value);
					dataVar::io_client_port.removeOne(QString::number(gVariable::generalio_variable_link.value(key).port_value));
					gVariable::generalio_variable_link.value(key).io_value->close();
					gVariable::generalio_variable_link.value(key).io_value->deleteLater();
					gVariable::generalio_variable_link.remove(key);
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "DAM-E3021N已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "Mitsubishi PLC")
	{
		//PLC通信
		comm_keys.clear();
		comm_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::plccommunicate_variable_link.value(key).mit_value->isOpen() == true)
				{
					mit_plc_client_state = 1;
					gVariable::PlcCommunicateVar.connect_state = 0;
					dataVar::mit_plc_client_ip.removeOne(gVariable::plccommunicate_variable_link.value(key).mit_ip_value);
					dataVar::mit_plc_client_port.removeOne(QString::number(gVariable::plccommunicate_variable_link.value(key).mit_port_value));
					gVariable::plccommunicate_variable_link.value(key).mit_value->close();
					gVariable::plccommunicate_variable_link.value(key).mit_value->deleteLater();
					gVariable::plccommunicate_variable_link.remove(key);
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "Inovance PLC")
	{
		//汇川PLC通信
		comm_keys.clear();
		comm_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::plccommunicate_variable_link.value(key).mit_value != nullptr) {
					if (gVariable::plccommunicate_variable_link.value(key).mit_value->isOpen() == true)
					{
						mit_plc_client_state = 1;
						gVariable::PlcCommunicateVar.connect_state = 0;
						dataVar::mit_plc_client_ip.removeOne(gVariable::plccommunicate_variable_link.value(key).mit_ip_value);
						dataVar::mit_plc_client_port.removeOne(QString::number(gVariable::plccommunicate_variable_link.value(key).mit_port_value));
						gVariable::plccommunicate_variable_link.value(key).mit_value->close();
						gVariable::plccommunicate_variable_link.value(key).mit_value->deleteLater();
						gVariable::plccommunicate_variable_link.remove(key);
						disconnectInovance();//汇川PLC断开连接
						count = 1;
						emit dataVar::fProItemTab->sig_InfoClick();
						emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
						QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "已断开连接！");
						msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
						msgBox.exec();
					}
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "SerialPort")
	{
		//串口通信
		comm_keys.clear();
		comm_keys = gVariable::serialport_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::serialport_variable_link.value(key).serialport_value->isOpen() == true)
				{
					gVariable::SerialPortVar.connect_state = 0;
					gVariable::serialport_variable_link.value(key).serialport_value->close();
					gVariable::serialport_variable_link.value(key).serialport_value->deleteLater();
					gVariable::serialport_variable_link.remove(key);
					s_port = nullptr;
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "该仪器已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "EthernetTcp")
	{
		//TCP/IP通信
		int count = 0;
		comm_keys.clear();
		comm_keys = gVariable::sockettcpserver_variable_link.uniqueKeys();
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::sockettcpserver_variable_link.value(key).server_value->isListening() == true)
				{
					gVariable::SocketTcpServerVar.connect_state = 0;
					gVariable::sockettcpserver_variable_link.value(key).server_value->close();
					gVariable::sockettcpserver_variable_link.value(key).server_value->deleteLater();
					gVariable::sockettcpserver_variable_link.remove(key);
					client = nullptr;
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		comm_keys.clear();
		comm_keys = gVariable::sockettcpclient_variable_link.uniqueKeys();
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::sockettcpclient_variable_link.value(key).client_value->isOpen() == true)
				{
					client_state = 1;
					gVariable::SocketTcpClientVar.connect_state = 0;
					dataVar::tcp_client_ip.removeOne(gVariable::sockettcpclient_variable_link.value(key).ip_value);
					dataVar::tcp_client_port.removeOne(QString::number(gVariable::sockettcpclient_variable_link.value(key).port_value));
					gVariable::sockettcpclient_variable_link.value(key).client_value->close();
					gVariable::sockettcpclient_variable_link.value(key).client_value->deleteLater();
					gVariable::sockettcpclient_variable_link.remove(key);
					server = nullptr;
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该仪器未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该仪器未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	//更新通讯工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
			}
		}
	}
}

void frmInstrumentation::on_btnSave_clicked()
{
	//保存参数
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择仪器通讯名称或编号为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择仪器通讯名称或编号为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	QStringList strs = ui.lblType->text().split("_");
	if (strs[0] == "DAM-E3021N")
	{
		//通用I/O		
		IoContent.global_ip = ui.widgetIoIP->getIP();
		IoContent.global_port = ui.spinIoPort->value();
		IoContent.global_timeout = ui.spinIoTimeOut->value();
		IoContent.global_remark = ui.txtIoRemark->text();
		global_io_content.insert(ui.lblType->text(), IoContent);
	}
	else if (strs[0] == "Mitsubishi PLC" || strs[0] == "Omron PLC" || strs[0] == "Siemens PLC" || strs[0] == "Keyence PLC" || strs[0] == "Inovance PLC")
	{
		//PLC通信		
		PlcContent.global_ip = ui.widgetPlcIP->getIP();
		PlcContent.global_port = ui.spinPlcPort->value();
		PlcContent.global_timeout = ui.spinPlcTimeOut->value();
		PlcContent.global_remark = ui.txtPlcRemark->text();
		global_plc_content.insert(ui.lblType->text(), PlcContent);
	}
	else if (strs[0] == "SerialPort")
	{
		//串口通信		
		SerialPortContent.global_serial_port = ui.comboSerialPort->currentText();
		SerialPortContent.global_baud_rate = ui.comboBaudRate->currentText();
		SerialPortContent.global_check_digit = ui.comboCheckDigit->currentText();
		SerialPortContent.global_data_bits = ui.comboDataBits->currentText();
		SerialPortContent.global_stop_bit = ui.comboStopBit->currentText();
		SerialPortContent.global_flowcontrol = ui.comboFlowControl->currentText();
		SerialPortContent.global_remark = ui.txtSPRemark->text();
		global_serialport_content.insert(ui.lblType->text(), SerialPortContent);
	}
	else if (strs[0] == "EthernetTcp")
	{
		//TCP/IP通信		
		TcpContent.global_protocol = ui.comboProtocol->currentText();
		TcpContent.global_ip = ui.widgetSocketIP->getIP();
		TcpContent.global_port = ui.spinSocketPort->value();
		TcpContent.global_remark = ui.txtSocketRemark->text();
		global_tcp_content.insert(ui.lblType->text(), TcpContent);
	}
	emit dataVar::fProItemTab->sig_InfoClick();
	emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "保存参数完成！");
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "保存参数完成！");
	msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
	msgBox.exec();
}

void frmInstrumentation::slot_DoubleClicked(int row, int column)
{
	QString selectInstrument = ui.tableWidget->item(row, 0)->text();
	ui.lblType->setText(selectInstrument);
	QStringList strs = selectInstrument.split("_");
	comm_keys.reserve(100);
	if (strs[0] == "DAM-E3021N")
	{
		ui.stackedWidget->setCurrentIndex(0);
		comm_keys.clear();
		comm_keys = global_io_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == selectInstrument)
			{
				count = 1;
				ui.widgetIoIP->setIP(global_io_content.value(key).global_ip);
				ui.spinIoPort->setValue(global_io_content.value(key).global_port);
				ui.spinIoTimeOut->setValue(global_io_content.value(key).global_timeout);
				ui.txtIoRemark->setText(global_io_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "Mitsubishi PLC" || strs[0] == "Omron PLC" || strs[0] == "Siemens PLC" || strs[0] == "Keyence PLC" || strs[0] == "Inovance PLC")
	{
		ui.stackedWidget->setCurrentIndex(1);
		comm_keys.clear();
		comm_keys = global_plc_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == selectInstrument)
			{
				count = 1;
				ui.widgetPlcIP->setIP(global_plc_content.value(key).global_ip);
				ui.spinPlcPort->setValue(global_plc_content.value(key).global_port);
				ui.spinPlcTimeOut->setValue(global_plc_content.value(key).global_timeout);
				ui.txtPlcRemark->setText(global_plc_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "SerialPort")
	{
		ui.stackedWidget->setCurrentIndex(2);
		comm_keys.clear();
		comm_keys = global_serialport_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == selectInstrument)
			{
				count = 1;
				ui.comboSerialPort->setCurrentText(global_serialport_content.value(key).global_serial_port);
				ui.comboBaudRate->setCurrentText(global_serialport_content.value(key).global_baud_rate);
				ui.comboCheckDigit->setCurrentText(global_serialport_content.value(key).global_check_digit);
				ui.comboDataBits->setCurrentText(global_serialport_content.value(key).global_data_bits);
				ui.comboStopBit->setCurrentText(global_serialport_content.value(key).global_stop_bit);
				ui.comboFlowControl->setCurrentText(global_serialport_content.value(key).global_flowcontrol);
				ui.txtSPRemark->setText(global_serialport_content.value(key).global_remark);
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "EthernetTcp")
	{
		ui.stackedWidget->setCurrentIndex(3);
		comm_keys.clear();
		comm_keys = global_tcp_content.uniqueKeys();
		int count = 0;
		for (int k = 0; k < comm_keys.length(); k++)
		{
			QString key = comm_keys[k];
			if (key == selectInstrument)
			{
				count = 1;
				ui.comboProtocol->setCurrentText(global_tcp_content.value(key).global_protocol);
				ui.widgetSocketIP->setIP(global_tcp_content.value(key).global_ip);
				ui.spinSocketPort->setValue(global_tcp_content.value(key).global_port);
				ui.txtSocketRemark->setText(global_tcp_content.value(key).global_remark);
				if (global_tcp_content.value(key).global_protocol == "TCP Server")
				{
					ui.lbl_ip->setText("本地IP地址：");
					ui.lbl_port->setText("本地端口号：");
				}
				else
				{
					ui.lbl_ip->setText("远程IP地址：");
					ui.lbl_port->setText("远程端口号：");
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("该仪器通讯参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "该仪器通讯参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
	}
}

void frmInstrumentation::slot_MoveUp()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow - 1);
}

void frmInstrumentation::slot_MoveDown()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow + 2);
}

void frmInstrumentation::slot_DeleteName()
{
	int rowIndex = ui.tableWidget->currentRow();
	if (rowIndex != -1)
	{
		QString str = ui.tableWidget->item(rowIndex, 0)->text();
		QStringList strs = str.split("_");
		if (strs[0] == "DAM-E3021N")
		{
			//通用I/O			
			global_io_content.remove(str);
			gVariable::generalio_variable_link.remove(str);
		}
		else if (strs[0] == "Mitsubishi PLC" || strs[0] == "Omron PLC" || strs[0] == "Siemens PLC" || strs[0] == "Keyence PLC" || strs[0] == "Inovance PLC")
		{
			//PLC通信
			global_plc_content.remove(str);
			gVariable::plccommunicate_variable_link.remove(str);
		}
		else if (strs[0] == "SerialPort")
		{
			//串口通信
			global_serialport_content.remove(str);
			gVariable::serialport_variable_link.remove(str);
		}
		else if (strs[0] == "EthernetTcp")
		{
			//TCP/IP通信
			global_tcp_content.remove(str);
			gVariable::sockettcpserver_variable_link.remove(str);
			gVariable::sockettcpclient_variable_link.remove(str);
		}
		ui.tableWidget->removeRow(rowIndex);
	}
	int count = ui.tableWidget->rowCount();
	if (count == 0)
	{
		ui.lblType->clear();
		global_io_content.clear();
		global_plc_content.clear();
		global_serialport_content.clear();
		global_tcp_content.clear();
		gVariable::generalio_variable_link.clear();
		gVariable::plccommunicate_variable_link.clear();
		gVariable::serialport_variable_link.clear();
		gVariable::sockettcpserver_variable_link.clear();
		gVariable::sockettcpclient_variable_link.clear();
	}
	//更新通讯工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("通讯工具");
			}
		}
	}
}

void frmInstrumentation::moveRow(QTableWidget* pTable, int nFrom, int nTo)
{
	if (pTable == NULL) return;
	pTable->setFocus();
	if (nFrom == nTo) return;
	if (nFrom < 0 || nTo < 0) return;
	int nRowCount = pTable->rowCount();
	if (nFrom >= nRowCount || nTo > nRowCount) return;
	if (nTo < nFrom) nFrom++; pTable->insertRow(nTo);
	int nCol = pTable->columnCount();
	for (int i = 0; i < nCol; i++)
	{
		pTable->setItem(nTo, i, pTable->takeItem(nFrom, i));
	}
	if (nFrom < nTo)
	{
		nTo--;
	}
	pTable->removeRow(nFrom); pTable->selectRow(nTo);
}
void frmInstrumentation::disconnectInovance()
{
	try
	{
		if (ctx != nullptr) {
			modbus_close(ctx);
			modbus_free(ctx);
			gVariable::PlcCommunicateVar.ctx = nullptr;
			gVariable::SocketTcpClientVar.connect_state = 0;
			std::cout << "Inovance PLC disconnect success " << std::endl;
		}
	}
	catch (...) {

	}
}
