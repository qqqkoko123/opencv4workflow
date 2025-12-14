#include "FitCircle.h"
#include "frmFitCircle.h"

FitCircle::FitCircle()
{
}

QString FitCircle::name()
{
    return "拟合圆";
}

QString FitCircle::information()
{
    return "几何工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFitCircle* ss = new frmFitCircle(toolName, toolBase);
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
