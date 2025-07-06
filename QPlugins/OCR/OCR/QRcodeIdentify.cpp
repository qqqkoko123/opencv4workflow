#include "QRcodeIdentify.h"
#include "frmQRcodeIdentify.h"

QRcodeIdentify::QRcodeIdentify()
{
}

QString QRcodeIdentify::name()
{
    return "OCR";
}

QString QRcodeIdentify::information()
{
    return "OCRʶ��";
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
