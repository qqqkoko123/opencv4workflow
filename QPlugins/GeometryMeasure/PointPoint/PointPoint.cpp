#include "PointPoint.h"
#include "frmPointPoint.h"

PointPoint::PointPoint()
{
}

QString PointPoint::name()
{
    return "��+��";
}

QString PointPoint::information()
{
    return "���β���";
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
