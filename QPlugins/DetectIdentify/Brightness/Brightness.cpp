#include "Brightness.h"
#include "frmBrightness.h"

Brightness::Brightness()
{
}

QString Brightness::name()
{
    return "���ȼ��";
}

QString Brightness::information()
{
    return "���ʶ��";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmBrightness* ss = new frmBrightness(toolName, toolBase);
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
