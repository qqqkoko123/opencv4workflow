#include "CropImage.h"
#include "frmCropImage.h"

CropImage::CropImage()
{
}

QString CropImage::name()
{
    return "����ͼ��";
}

QString CropImage::information()
{
    return "ͼ����";
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
