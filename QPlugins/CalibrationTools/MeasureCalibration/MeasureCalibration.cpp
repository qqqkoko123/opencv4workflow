#include "MeasureCalibration.h"
#include "frmMeasureCalibration.h"

MeasureCalibration::MeasureCalibration()
{
}

QString MeasureCalibration::name()
{
    return "�����궨";
}

QString MeasureCalibration::information()
{
    return "�궨����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmMeasureCalibration* ss = new frmMeasureCalibration(toolName, toolBase);
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
