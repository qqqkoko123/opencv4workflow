#include "LineLineI.h"
#include "frmLineLineI.h"

LineLineI::LineLineI()
{
}

QString LineLineI::name()
{
    return "线线交点";
}

QString LineLineI::information()
{
    return "几何测量";
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
