#include "LineCircle.h"
#include "frmLineCircle.h"

LineCircle::LineCircle()
{
}

QString LineCircle::name()
{
    return "线圆交点";
}

QString LineCircle::information()
{
    return "几何测量";
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
