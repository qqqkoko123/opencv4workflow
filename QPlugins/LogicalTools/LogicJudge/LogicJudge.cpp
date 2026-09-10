#include "LogicJudge.h"
#include "frmLogicJudge.h"

LogicJudge::LogicJudge()
{
}

QString LogicJudge::name()
{
    return "判断语句";
}

QString LogicJudge::information()
{
    return "逻辑工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmLogicJudge* ss = new frmLogicJudge(toolName, toolBase);
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
