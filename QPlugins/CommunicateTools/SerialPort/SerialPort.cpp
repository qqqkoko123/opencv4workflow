#include "SerialPort.h"
#include "frmSerialPort.h"

SerialPort::SerialPort()
{
}

QString SerialPort::name()
{
    return "串口通信";
}

QString SerialPort::information()
{
    return "通讯工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmSerialPort* ss = new frmSerialPort(toolName, toolBase);
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
