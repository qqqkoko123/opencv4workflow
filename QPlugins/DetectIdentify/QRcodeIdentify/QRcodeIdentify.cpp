#include "QRcodeIdentify.h"
#include "frmQRcodeIdentify.h"

QRcodeIdentify::QRcodeIdentify()
{
}

QString QRcodeIdentify::name()
{
    return "��ά��ʶ��";
}

QString QRcodeIdentify::information()
{
    return "���ʶ��";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmQRcodeIdentify* ss = new frmQRcodeIdentify(toolName, toolBase);
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
