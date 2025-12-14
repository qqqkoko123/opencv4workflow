#pragma once

#include <QDialog>
#include "ui_frmSocketTcpServer.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitSocketTcpServerData
{
	int server_index;
	QVector<QString> server_tools;
};
Q_DECLARE_METATYPE(InitSocketTcpServerData);

class frmSocketTcpServer : public Toolnterface
{
	Q_OBJECT

public:
	frmSocketTcpServer(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmSocketTcpServer();

private:
	Ui::frmSocketTcpServerClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteSocketTcpServerLink(const QMap<QString, gVariable::SocketTcpServer_Var> sockettcpserver_var_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;	

private slots:	
	void on_btnExecute_clicked();
	void on_btnUpdata_clicked();
	void on_btnLinkContent_clicked();
	void on_btnDelLinkContent_clicked();
	void on_btnTcpClear_clicked();
	void on_comboCommName_currentIndexChanged(int index);

signals:
	void sig_SendMsg(QString);
	void sig_SMsg(QString);
	void sig_ReadMsg();

private slots:
	void acceptConnection();
	void slot_ReadClient();
	void slot_SendMsg(QString);
	void slot_SMsg(QString);
	void slot_ReadMsg();
	void timerEvent();

private:
	int RunToolPro();
	QByteArray hexStrToByteArray(const QString& str);
	char convertHexChar(char ch);
	QString byteArrayToHexStr(const QByteArray& data);

private:
	gVariable gvariable;
	QStringList strs;
	int tool_index = 0;
	QList<QString> keys;
	QTcpServer* tcp_server = nullptr;
	QTcpServer* tcp_server_buf = nullptr;
	QTcpSocket* tcp_client_connection = nullptr;		
	QTcpSocket* tcp_client_connection_buf = nullptr;
	int server_buf = 0;
	int client_connection_buf = 0;
	int choose_index = -10000;
	int choose_num;	
	int tcp_client_connection_state;
	QString send_buffer;
	QString buffer;
	int tcp_state;
	QThread* h_this, * h_send, * h_read;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
