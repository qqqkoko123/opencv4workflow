#include "LogicJudgeEnd.h"
#include "frmLogicJudgeEnd.h"

LogicJudgeEnd::LogicJudgeEnd()
{
}

QString LogicJudgeEnd::name()
{
    return "结束语句";
}

QString LogicJudgeEnd::information()
{
    return "逻辑工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmLogicJudgeEnd* ss = new frmLogicJudgeEnd(toolName, toolBase);
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
