#include "ImageSource.h"
#include "frmImageSource.h"

ImageSource::ImageSource()
{
}

QString ImageSource::name()
{
    return "��ȡͼ��";
}

QString ImageSource::information()
{
    return "ͼ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
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
