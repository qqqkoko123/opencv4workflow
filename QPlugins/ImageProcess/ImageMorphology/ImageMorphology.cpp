#include "ImageMorphology.h"
#include "frmImageMorphology.h"

ImageMorphology::ImageMorphology()
{
}

QString ImageMorphology::name()
{
    return "预处理";
}

QString ImageMorphology::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageMorphology* ss = new frmImageMorphology(toolName, toolBase);
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
