#include "LogicGoto.h"
#include "frmLogicGoto.h"

LogicGoto::LogicGoto()
{
}

QString LogicGoto::name()
{
    return "跳转语句";
}

QString LogicGoto::information()
{
    return "逻辑工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmLogicGoto* ss = new frmLogicGoto(toolName, toolBase);
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
