#include "FitLine.h"
#include "frmFitLine.h"

FitLine::FitLine()
{
}

QString FitLine::name()
{
    return "拟合直线";
}

QString FitLine::information()
{
    return "几何工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFitLine* ss = new frmFitLine(toolName, toolBase);
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
