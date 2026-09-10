#pragma once

#include <QDialog>
#include "QToolBase.h"
#include "gvariable.h"

class QToolBase;  //头文件相互调用前置声明

class Toolnterface : public QDialog
{
	Q_OBJECT

public:
	Toolnterface(QString toolName, QToolBase* toolBase, QWidget* parent);
	virtual ~Toolnterface();

	//Execute函数说明：toolname-当前工具名字
	virtual int Execute(const QString toolname);	
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteGotoLink(const QMap<QString, gVariable::Goto_Var> goto_var_link);
	virtual int ExecuteCameraLink(const QMap<QString, gVariable::Camera_Var> camera_var_link);
	virtual int ExecuteGeneralIoLink(const QMap<QString, gVariable::GeneralIo_Var> generalio_var_link);
	virtual int ExecutePlcCommunicateLink(const QMap<QString, gVariable::PlcCommunicate_Var> plccommunicate_var_link);
	virtual int ExecuteSerialPortLink(const QMap<QString, gVariable::SerialPort_Var> serialport_var_link);
	virtual int ExecuteSocketTcpServerLink(const QMap<QString, gVariable::SocketTcpServer_Var> sockettcpserver_var_link);
	virtual int ExecuteSocketTcpClientLink(const QMap<QString, gVariable::SocketTcpClient_Var> sockettcpclient_var_link);
	virtual int ExecuteScriptEditLink(const QMap<QToolBase*, gVariable::ScriptEdit_Var> scriptedit_var_link);
	virtual QString GetToolName();
	virtual QToolBase* GetToolBase();
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();
	
private:
	QString ToolName;	
	QToolBase* sToolBase;
};
