#include "PointLine.h"
#include "frmPointLine.h"

PointLine::PointLine()
{
}

QString PointLine::name()
{
    return "��+��";
}

QString PointLine::information()
{
    return "���β���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmPointLine* ss = new frmPointLine(toolName, toolBase);
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
