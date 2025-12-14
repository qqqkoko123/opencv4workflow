#include "CamShiftTrack.h"
#include "frmCamShiftTrack.h"

CamShiftTrack::CamShiftTrack()
{
}

QString CamShiftTrack::name()
{
    return "目标跟踪";
}

QString CamShiftTrack::information()
{
    return "对位工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmCamShiftTrack* ss = new frmCamShiftTrack(toolName, toolBase);
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
