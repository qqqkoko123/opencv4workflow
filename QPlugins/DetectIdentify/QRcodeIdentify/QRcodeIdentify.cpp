#include "QRcodeIdentify.h"
#include "frmQRcodeIdentify.h"

QRcodeIdentify::QRcodeIdentify()
{
}

QString QRcodeIdentify::name()
{
    return "二维码识别";
}

QString QRcodeIdentify::information()
{
    return "检测识别";
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
