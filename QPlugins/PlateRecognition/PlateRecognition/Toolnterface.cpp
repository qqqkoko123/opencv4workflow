#include "Toolnterface.h"
#include <QVariant>

Toolnterface::Toolnterface(QString toolName, QToolBase* toolBase, QWidget* parent)
	: ToolName(toolName), sToolBase(toolBase),
	QDialog(parent)
{
}

Toolnterface::~Toolnterface()
{	
}

QString Toolnterface::GetToolName()
{
	return ToolName;
}

QToolBase* Toolnterface::GetToolBase()
{
	return sToolBase;
}

int Toolnterface::Execute(const QString toolname)
{
	return -1;
}

int Toolnterface::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	return -1;
}

int Toolnterface::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	return -1;
}

int Toolnterface::ExecuteGotoLink(const QMap<QString, gVariable::Goto_Var> goto_var_link)
{
	return -1;
}

int Toolnterface::ExecuteCameraLink(const QMap<QString, gVariable::Camera_Var> camera_var_link)
{
	return -1;
}

int Toolnterface::ExecuteGeneralIoLink(const QMap<QString, gVariable::GeneralIo_Var> generalio_var_link)
{
	return -1;
}

int Toolnterface::ExecutePlcCommunicateLink(const QMap<QString, gVariable::PlcCommunicate_Var> plccommunicate_var_link)
{
	return -1;
}

int Toolnterface::ExecuteSerialPortLink(const QMap<QString, gVariable::SerialPort_Var> serialport_var_link)
{
	return -1;
}

int Toolnterface::ExecuteSocketTcpServerLink(const QMap<QString, gVariable::SocketTcpServer_Var> sockettcpserver_var_link)
{
	return -1;
}

int Toolnterface::ExecuteSocketTcpClientLink(const QMap<QString, gVariable::SocketTcpClient_Var> sockettcpclient_var_link)
{
	return -1;
}

int Toolnterface::ExecuteScriptEditLink(const QMap<QToolBase*, gVariable::ScriptEdit_Var> scriptedit_var_link)
{
	return -1;
}

QVariant Toolnterface::InitGetToolData()
{
	return -1;
}

int Toolnterface::InitSetToolData(const QVariant data)
{
	return -1;
}
