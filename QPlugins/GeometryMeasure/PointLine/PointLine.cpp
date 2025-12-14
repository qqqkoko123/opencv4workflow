#include "PointLine.h"
#include "frmPointLine.h"

PointLine::PointLine()
{
}

QString PointLine::name()
{
    return "点+线";
}

QString PointLine::information()
{
    return "几何测量";
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
