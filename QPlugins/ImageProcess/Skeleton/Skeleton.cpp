#include "Skeleton.h"
#include "frmSkeleton.h"

Skeleton::Skeleton()
{
}

QString Skeleton::name()
{
    return "图像细化";
}

QString Skeleton::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmSkeleton* ss = new frmSkeleton(toolName, toolBase);
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
