#include "FindCircle.h"
#include "frmFindCircle.h"

FindCircle::FindCircle()
{
}

QString FindCircle::name()
{
    return "Ѱ��Բ";
}

QString FindCircle::information()
{
    return "���ι���";
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
