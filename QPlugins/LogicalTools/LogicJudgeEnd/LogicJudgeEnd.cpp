#include "LogicJudgeEnd.h"
#include "frmLogicJudgeEnd.h"

LogicJudgeEnd::LogicJudgeEnd()
{
}

QString LogicJudgeEnd::name()
{
    return "½áÊøÓï¾ä";
}

QString LogicJudgeEnd::information()
{
    return "Âß¼­¹¤¾ß";
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
