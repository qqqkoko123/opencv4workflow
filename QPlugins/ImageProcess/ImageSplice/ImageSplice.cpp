#include "ImageSplice.h"
#include "frmImageSplice.h"

ImageSplice::ImageSplice()
{
}

QString ImageSplice::name()
{
    return "ͼ��ƴ��";
}

QString ImageSplice::information()
{
    return "ͼ����";
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
