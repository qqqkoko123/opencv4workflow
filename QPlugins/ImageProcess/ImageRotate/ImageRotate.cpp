#include "ImageRotate.h"
#include "frmImageRotate.h"

ImageRotate::ImageRotate()
{
}

QString ImageRotate::name()
{
    return "图像旋转";
}

QString ImageRotate::information()
{
    return "图像处理";
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
