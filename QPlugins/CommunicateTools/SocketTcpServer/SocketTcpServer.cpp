#include "SocketTcpServer.h"
#include "frmSocketTcpServer.h"

SocketTcpServer::SocketTcpServer()
{
}

QString SocketTcpServer::name()
{
    return "TCP/IP服务器";
}

QString SocketTcpServer::information()
{
    return "通讯工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmSocketTcpServer* ss = new frmSocketTcpServer(toolName, toolBase);
    return ss;
}

int ShowFormState()
{
    return QConfig::nFormState;
}

void SetFormState()
{
    QConfig::nFormState = 0;
}
