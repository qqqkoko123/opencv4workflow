#include "Skeleton.h"
#include "frmSkeleton.h"

Skeleton::Skeleton()
{
}

QString Skeleton::name()
{
    return "ͼ��ϸ��";
}

QString Skeleton::information()
{
    return "ͼ����";
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
