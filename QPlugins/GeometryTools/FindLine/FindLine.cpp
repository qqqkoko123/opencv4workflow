#include "FindLine.h"
#include "frmFindLine.h"

FindLine::FindLine()
{
}

QString FindLine::name()
{
    return "寻找直线";
}

QString FindLine::information()
{
    return "几何工具";
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
