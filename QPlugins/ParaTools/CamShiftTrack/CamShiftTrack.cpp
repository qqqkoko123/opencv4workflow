#include "CamShiftTrack.h"
#include "frmCamShiftTrack.h"

CamShiftTrack::CamShiftTrack()
{
}

QString CamShiftTrack::name()
{
    return "Ŀ�����";
}

QString CamShiftTrack::information()
{
    return "��λ����";
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
