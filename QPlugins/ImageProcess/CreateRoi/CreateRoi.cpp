#include "CreateRoi.h"
#include "frmCreateRoi.h"

CreateRoi::CreateRoi()
{
}

QString CreateRoi::name()
{
    return "创建ROI";
}

QString CreateRoi::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmCreateRoi* ss = new frmCreateRoi(toolName, toolBase);
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
