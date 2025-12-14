#include "GetContourPoints.h"
#include "frmGetContourPoints.h"

GetContourPoints::GetContourPoints()
{
}

QString GetContourPoints::name()
{
    return "获取边界点";
}

QString GetContourPoints::information()
{
    return "几何工具";
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
