#include "RoundedCorners.h"
#include "frmRoundedCorners.h"

RoundedCorners::RoundedCorners()
{
}

QString RoundedCorners::name()
{
    return "����Բȱ��";
}

QString RoundedCorners::information()
{
    return "���β���";
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
