#include "LogicGoto.h"
#include "frmLogicGoto.h"

LogicGoto::LogicGoto()
{
}

QString LogicGoto::name()
{
    return "��ת���";
}

QString LogicGoto::information()
{
    return "�߼�����";
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
