#include "ImageRotate.h"
#include "frmImageRotate.h"

ImageRotate::ImageRotate()
{
}

QString ImageRotate::name()
{
    return "Í¼ÏñÐý×ª";
}

QString ImageRotate::information()
{
    return "Í¼Ïñ´¦Àí";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageRotate* ss = new frmImageRotate(toolName, toolBase);
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
