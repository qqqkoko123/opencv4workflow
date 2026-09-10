#include "Brightness.h"
#include "frmBrightness.h"

Brightness::Brightness()
{
}

QString Brightness::name()
{
    return "亮度检测";
}

QString Brightness::information()
{
    return "检测识别";
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
