#include "SocketTcpClient.h"
#include "frmSocketTcpClient.h"

SocketTcpClient::SocketTcpClient()
{
}

QString SocketTcpClient::name()
{
    return "TCP/IP�ͻ���";
}

QString SocketTcpClient::information()
{
    return "ͨѶ����";
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
