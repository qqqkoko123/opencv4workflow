#include "GetContourPoints.h"
#include "frmGetContourPoints.h"

GetContourPoints::GetContourPoints()
{
}

QString GetContourPoints::name()
{
    return "��ȡ�߽��";
}

QString GetContourPoints::information()
{
    return "���ι���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmGetContourPoints* ss = new frmGetContourPoints(toolName, toolBase);
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
