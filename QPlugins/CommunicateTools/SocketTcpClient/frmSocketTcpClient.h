#pragma once

#include <QDialog>
#include "ui_frmSocketTcpClient.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitSocketTcpClientData
{
	int client_index;
	QVector<QString> client_tools;
};
Q_DECLARE_METATYPE(InitSocketTcpClientData);

class frmSocketTcpClient : public Toolnterface
{
	Q_OBJECT

public:
	frmSocketTcpClient(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmSocketTcpClient();

private:
	Ui::frmSocketTcpClientClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteSocketTcpClientLink(const QMap<QString, gVariable::SocketTcpClient_Var> sockettcpclient_var_link);
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
	void slot_ReadServer();	
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
	QTcpSocket* tcp_client = nullptr;
	QTcpSocket* tcp_client_buf = nullptr;
	int client_buf = 0;
	int choose_index = -10000;
	int choose_num;		
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
