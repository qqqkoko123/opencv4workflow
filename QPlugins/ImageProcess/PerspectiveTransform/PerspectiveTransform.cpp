#include "PerspectiveTransform.h"
#include "frmPerspectiveTransform.h"

PerspectiveTransform::PerspectiveTransform()
{
}

QString PerspectiveTransform::name()
{
    return "透视变换";
}

QString PerspectiveTransform::information()
{
    return "图像处理";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmPerspectiveTransform* ss = new frmPerspectiveTransform(toolName, toolBase);
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
