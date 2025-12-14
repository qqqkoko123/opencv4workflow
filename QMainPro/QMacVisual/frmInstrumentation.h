#pragma once

#include <QDialog>
#include "ui_frmInstrumentation.h"
#include "gvariable.h"
#include "mytitlebar.h"

class frmInstrumentation : public QDialog
{
	Q_OBJECT

public:
	frmInstrumentation(QWidget* parent = Q_NULLPTR);
	~frmInstrumentation();

private:
	Ui::frmInstrumentationClass ui;

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	
	void AddRightButtonMenu();   //右键菜单
	int GetValue(QVector<int> n);
	void moveRow(QTableWidget* pTable, int nFrom, int nTo);

	void disconnectInovance();

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;

private slots:
	void on_btnAdd_clicked();
	void on_btnConnect_clicked();
	void on_btnDisconnect_clicked();	
	void on_btnSave_clicked();
	void slot_MoveUp();
	void slot_MoveDown();
	void slot_DeleteName();
	void slotInstrumentChanged(int);
	void slot_DoubleClicked(int, int);
	void on_comboProtocol_currentIndexChanged(int);

public slots:
	void InitIoConnect(QString io_key_value, QString ip_value, int port_value, int over_time_value);
	void InitPlcConnect(QString plc_key_value, QString ip_value, int port_value, int over_time_value);
	bool InovancePLC_connect(QString IP, int Port);
	void InitSerialportConnect(QString serialport_key_value, QString portname_value, int baudrate_value, QString parity_value, QString databits_value, QString stopbits_value, QString flowcontrol_value);
	void InitServerConnect(QString server_key_value, int port_value);
	void InitClientConnect(QString client_key_value, QString ip_value, int port_value);

private slots:
	void onIoConnected();
	void onIoDisconnected();
	void onMitPlcConnected();
	void onMitPlcDisconnected();
	void onTcpConnected();
	void onTcpDisconnected();

private:	
	QList<QString> comm_keys;
	QTcpSocket* io_client;	
	int io_client_state = 0;
	QTcpSocket* mit_plc_client;
	int mit_plc_client_state = 0;
	QTcpSocket* inv_plc_client; //汇川PLC
	int inv_plc_client_state = 0; //汇川PLC状态
	QSerialPort* s_port;
	bool s_port_state;
	QTcpServer* server;	
	QTcpSocket* client;	
	int client_state = 0;
	int init_state = 0;
	QString init_key_value;

public:
	//通用I/O
	typedef struct IOCONTENT
	{		
		QString global_ip;
		int global_port;
		int global_timeout;
		QString global_remark;
	} Io_Content;
	Io_Content IoContent;
	QMap<QString, Io_Content> global_io_content;
	//PLC通信
	typedef struct PLCCONTENT
	{	
		QString global_ip;
		int global_port;
		int global_timeout;
		QString global_remark;
	} Plc_Content;
	Plc_Content PlcContent;
	modbus_t *ctx;
	QMap<QString, Plc_Content> global_plc_content;
	//串口通信
	typedef struct SERIALPORTCONTENT
	{		
		QString global_serial_port;
		QString global_baud_rate;
		QString global_check_digit;
		QString global_data_bits;
		QString global_stop_bit;
		QString global_flowcontrol;
		QString global_remark;
	} SerialPort_Content;
	SerialPort_Content SerialPortContent;
	QMap<QString, SerialPort_Content> global_serialport_content;
	//TCP/IP通信
	typedef struct TCPCONTENT
	{		
		QString global_protocol;
		QString global_ip;
		int global_port;	
		QString global_remark;
	} Tcp_Content;
	Tcp_Content TcpContent;
	QMap<QString, Tcp_Content> global_tcp_content;
};
