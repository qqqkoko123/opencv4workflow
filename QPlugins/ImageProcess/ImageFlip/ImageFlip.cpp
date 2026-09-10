#include "ImageFlip.h"
#include "frmImageFlip.h"

ImageFlip::ImageFlip()
{
}

QString ImageFlip::name()
{
    return "图像翻转";
}

QString ImageFlip::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageFlip* ss = new frmImageFlip(toolName, toolBase);
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
