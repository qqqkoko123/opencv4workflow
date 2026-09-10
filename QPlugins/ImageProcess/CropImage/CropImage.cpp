#include "CropImage.h"
#include "frmCropImage.h"

CropImage::CropImage()
{
}

QString CropImage::name()
{
    return "裁切图像";
}

QString CropImage::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmCropImage* ss = new frmCropImage(toolName, toolBase);
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
