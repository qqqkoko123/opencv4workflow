#include "FitLine.h"
#include "frmFitLine.h"

FitLine::FitLine()
{
}

QString FitLine::name()
{
    return "���ֱ��";
}

QString FitLine::information()
{
    return "���ι���";
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
