#include "ImageClarity.h"
#include "frmImageClarity.h"

ImageClarity::ImageClarity()
{
}

QString ImageClarity::name()
{
    return "ͼ��������";
}

QString ImageClarity::information()
{
    return "���ʶ��";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageClarity* ss = new frmImageClarity(toolName, toolBase);
    return ss;
}
