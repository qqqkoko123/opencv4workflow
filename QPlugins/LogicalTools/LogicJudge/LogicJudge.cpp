#include "LogicJudge.h"
#include "frmLogicJudge.h"

LogicJudge::LogicJudge()
{
}

QString LogicJudge::name()
{
    return "�ж����";
}

QString LogicJudge::information()
{
    return "�߼�����";
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
