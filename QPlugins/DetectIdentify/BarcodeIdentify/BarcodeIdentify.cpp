#include "BarcodeIdentify.h"
#include "frmBarcodeIdentify.h"

BarcodeIdentify::BarcodeIdentify()
{
}

QString BarcodeIdentify::name()
{
    return "������ʶ��";
}

QString BarcodeIdentify::information()
{
    return "���ʶ��";
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
