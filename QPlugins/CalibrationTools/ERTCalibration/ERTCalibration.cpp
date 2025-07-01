#include "ERTCalibration.h"
#include "frmERTCalibration.h"

ERTCalibration::ERTCalibration()
{
}

QString ERTCalibration::name()
{
    return "N��궨";
}

QString ERTCalibration::information()
{
    return "�궨����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmERTCalibration* ss = new frmERTCalibration(toolName, toolBase);
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
