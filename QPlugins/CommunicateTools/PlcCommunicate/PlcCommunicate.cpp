#include "PlcCommunicate.h"
#include "frmPlcCommunicate.h"

PlcCommunicate::PlcCommunicate()
{
}

QString PlcCommunicate::name()
{
    return "PLC通信";
}

QString PlcCommunicate::information()
{
    return "通讯工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmPlcCommunicate* ss = new frmPlcCommunicate(toolName, toolBase);
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
