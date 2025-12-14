#include "DelayTool.h"
#include "frmDelayTool.h"

DelayTool::DelayTool()
{
}

QString DelayTool::name()
{
    return "延时";
}

QString DelayTool::information()
{
    return "系统工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmDelayTool* ss = new frmDelayTool(toolName, toolBase);
    return ss;
}
