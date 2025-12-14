#include "ColorIdentify.h"
#include "frmColorIdentify.h"

ColorIdentify::ColorIdentify()
{
}

QString ColorIdentify::name()
{
    return "颜色识别";
}

QString ColorIdentify::information()
{
    return "检测识别";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmColorIdentify* ss = new frmColorIdentify(toolName, toolBase);
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
