#include "LineCircle.h"
#include "frmLineCircle.h"

LineCircle::LineCircle()
{
}

QString LineCircle::name()
{
    return "��Բ����";
}

QString LineCircle::information()
{
    return "���β���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmLineCircle* ss = new frmLineCircle(toolName, toolBase);
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
