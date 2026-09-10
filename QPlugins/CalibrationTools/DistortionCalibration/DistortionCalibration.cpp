#include "DistortionCalibration.h"
#include "frmDistortionCalibration.h"

DistortionCalibration::DistortionCalibration()
{
}

QString DistortionCalibration::name()
{
    return "畸变标定";
}

QString DistortionCalibration::information()
{
    return "标定工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmDistortionCalibration* ss = new frmDistortionCalibration(toolName, toolBase);
    return ss;
}
