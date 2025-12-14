#include "Flatness.h"
#include "frmFlatness.h"

Flatness::Flatness()
{
}

QString Flatness::name()
{
    return "拟合平面";
}

QString Flatness::information()
{
    return "三维检测";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFlatness* ss = new frmFlatness(toolName, toolBase);
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
