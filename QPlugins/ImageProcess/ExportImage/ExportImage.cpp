#include "ExportImage.h"
#include "frmExportImage.h"

ExportImage::ExportImage()
{
}

QString ExportImage::name()
{
    return "����ͼ��";
}

QString ExportImage::information()
{
    return "ͼ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmExportImage* ss = new frmExportImage(toolName, toolBase);
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
