#include "DistortionCalibration.h"
#include "frmDistortionCalibration.h"

DistortionCalibration::DistortionCalibration()
{
}

QString DistortionCalibration::name()
{
    return "����궨";
}

QString DistortionCalibration::information()
{
    return "�궨����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmDistortionCalibration* ss = new frmDistortionCalibration(toolName, toolBase);
    return ss;
}
