#include "DelayTool.h"
#include "frmDelayTool.h"

DelayTool::DelayTool()
{
}

QString DelayTool::name()
{
    return "��ʱ";
}

QString DelayTool::information()
{
    return "ϵͳ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmDelayTool* ss = new frmDelayTool(toolName, toolBase);
    return ss;
}
