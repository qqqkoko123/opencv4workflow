#include "ImageSplice.h"
#include "frmImageSplice.h"

ImageSplice::ImageSplice()
{
}

QString ImageSplice::name()
{
    return "图像拼接";
}

QString ImageSplice::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageSplice* ss = new frmImageSplice(toolName, toolBase);
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
