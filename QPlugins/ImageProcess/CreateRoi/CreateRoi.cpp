#include "CreateRoi.h"
#include "frmCreateRoi.h"

CreateRoi::CreateRoi()
{
}

QString CreateRoi::name()
{
    return "����ROI";
}

QString CreateRoi::information()
{
    return "ͼ����";
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
