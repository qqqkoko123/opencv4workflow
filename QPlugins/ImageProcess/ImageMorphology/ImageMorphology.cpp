#include "ImageMorphology.h"
#include "frmImageMorphology.h"

ImageMorphology::ImageMorphology()
{
}

QString ImageMorphology::name()
{
    return "Ԥ����";
}

QString ImageMorphology::information()
{
    return "ͼ����";
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
