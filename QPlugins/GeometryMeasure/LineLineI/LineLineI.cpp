#include "LineLineI.h"
#include "frmLineLineI.h"

LineLineI::LineLineI()
{
}

QString LineLineI::name()
{
    return "���߽���";
}

QString LineLineI::information()
{
    return "���β���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmLineLineI* ss = new frmLineLineI(toolName, toolBase);
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
