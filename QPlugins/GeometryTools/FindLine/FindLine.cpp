#include "FindLine.h"
#include "frmFindLine.h"

FindLine::FindLine()
{
}

QString FindLine::name()
{
    return "Ѱ��ֱ��";
}

QString FindLine::information()
{
    return "���ι���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFindLine* ss = new frmFindLine(toolName, toolBase);
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
