#include "ImageRepair.h"
#include "frmImageRepair.h"

ImageRepair::ImageRepair()
{
}

QString ImageRepair::name()
{
    return "ͼ���޸�";
}

QString ImageRepair::information()
{
    return "ͼ����";
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
