#include "SocketTcpServer.h"
#include "frmSocketTcpServer.h"

SocketTcpServer::SocketTcpServer()
{
}

QString SocketTcpServer::name()
{
    return "TCP/IP������";
}

QString SocketTcpServer::information()
{
    return "ͨѶ����";
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
