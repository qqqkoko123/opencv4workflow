#include "PointPoint.h"
#include "frmPointPoint.h"

PointPoint::PointPoint()
{
}

QString PointPoint::name()
{
    return "点+点";
}

QString PointPoint::information()
{
    return "几何测量";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmPointPoint* ss = new frmPointPoint(toolName, toolBase);
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
