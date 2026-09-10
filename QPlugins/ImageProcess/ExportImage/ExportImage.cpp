#include "ExportImage.h"
#include "frmExportImage.h"

ExportImage::ExportImage()
{
}

QString ExportImage::name()
{
    return "导出图像";
}

QString ExportImage::information()
{
    return "图像处理";
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
