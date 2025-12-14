#include "LogicJudge.h"
#include "frmLogicJudge.h"

LogicJudge::LogicJudge()
{
}

QString LogicJudge::name()
{
    return "ÅÐ¶ÏÓï¾ä";
}

QString LogicJudge::information()
{
    return "Âß¼­¹¤¾ß";
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
