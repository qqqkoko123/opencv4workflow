#include "QRcodeIdentify.h"
#include "frmQRcodeIdentify.h"

QRcodeIdentify::QRcodeIdentify()
{
}

QString QRcodeIdentify::name()
{
    return "自动打印";
}

QString QRcodeIdentify::information()
{
    return "图像处理";
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
