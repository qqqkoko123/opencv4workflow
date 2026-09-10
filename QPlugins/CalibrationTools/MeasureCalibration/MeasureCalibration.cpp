#include "MeasureCalibration.h"
#include "frmMeasureCalibration.h"

MeasureCalibration::MeasureCalibration()
{
}

QString MeasureCalibration::name()
{
    return "测量标定";
}

QString MeasureCalibration::information()
{
    return "标定工具";
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
