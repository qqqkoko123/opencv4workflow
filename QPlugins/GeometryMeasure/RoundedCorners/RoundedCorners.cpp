#include "RoundedCorners.h"
#include "frmRoundedCorners.h"

RoundedCorners::RoundedCorners()
{
}

QString RoundedCorners::name()
{
    return "查找圆缺角";
}

QString RoundedCorners::information()
{
    return "几何测量";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmRoundedCorners* ss = new frmRoundedCorners(toolName, toolBase);
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
