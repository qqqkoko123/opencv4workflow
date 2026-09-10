#include "FindCircle.h"
#include "frmFindCircle.h"

FindCircle::FindCircle()
{
}

QString FindCircle::name()
{
    return "寻找圆";
}

QString FindCircle::information()
{
    return "几何工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFindCircle* ss = new frmFindCircle(toolName, toolBase);
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
