#include "PlcCommunicate.h"
#include "frmPlcCommunicate.h"

PlcCommunicate::PlcCommunicate()
{
}

QString PlcCommunicate::name()
{
    return "PLCͨ��";
}

QString PlcCommunicate::information()
{
    return "ͨѶ����";
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
