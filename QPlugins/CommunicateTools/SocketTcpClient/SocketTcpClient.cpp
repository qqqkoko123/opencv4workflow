#include "SocketTcpClient.h"
#include "frmSocketTcpClient.h"

SocketTcpClient::SocketTcpClient()
{
}

QString SocketTcpClient::name()
{
    return "TCP/IP客户端";
}

QString SocketTcpClient::information()
{
    return "通讯工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmSocketTcpClient* ss = new frmSocketTcpClient(toolName, toolBase);
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
