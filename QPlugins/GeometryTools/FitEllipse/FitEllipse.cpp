#include "FitEllipse.h"
#include "frmFitEllipse.h"

FitEllipse::FitEllipse()
{
}

QString FitEllipse::name()
{
    return "拟合椭圆";
}

QString FitEllipse::information()
{
    return "几何工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFitEllipse* ss = new frmFitEllipse(toolName, toolBase);
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
