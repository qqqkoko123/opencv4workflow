#include "SerialPort.h"
#include "frmSerialPort.h"

SerialPort::SerialPort()
{
}

QString SerialPort::name()
{
    return "����ͨ��";
}

QString SerialPort::information()
{
    return "ͨѶ����";
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
