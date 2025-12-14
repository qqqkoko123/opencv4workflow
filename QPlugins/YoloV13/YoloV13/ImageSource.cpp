#include "ImageSource.h"
#include "frmImageSource.h"

ImageSource::ImageSource()
{
}

QString ImageSource::name()
{
    return "获取图像";
}

QString ImageSource::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase2* toolBase)
{   
    frmImageSource* ss = new frmImageSource(toolName, toolBase);
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
