#include "BarcodeIdentify.h"
#include "frmBarcodeIdentify.h"

BarcodeIdentify::BarcodeIdentify()
{
}

QString BarcodeIdentify::name()
{
    return "条形码识别";
}

QString BarcodeIdentify::information()
{
    return "检测识别";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmBarcodeIdentify* ss = new frmBarcodeIdentify(toolName, toolBase);
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
