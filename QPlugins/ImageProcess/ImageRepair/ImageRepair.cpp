#include "ImageRepair.h"
#include "frmImageRepair.h"

ImageRepair::ImageRepair()
{
}

QString ImageRepair::name()
{
    return "图像修复";
}

QString ImageRepair::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageRepair* ss = new frmImageRepair(toolName, toolBase);
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
