#include "ColorIdentify.h"
#include "frmColorIdentify.h"

ColorIdentify::ColorIdentify()
{
}

QString ColorIdentify::name()
{
    return "��ɫʶ��";
}

QString ColorIdentify::information()
{
    return "���ʶ��";
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
