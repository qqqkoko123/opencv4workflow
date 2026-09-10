#include "ImageClarity.h"
#include "frmImageClarity.h"

ImageClarity::ImageClarity()
{
}

QString ImageClarity::name()
{
    return "图像清晰度";
}

QString ImageClarity::information()
{
    return "检测识别";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageClarity* ss = new frmImageClarity(toolName, toolBase);
    return ss;
}
