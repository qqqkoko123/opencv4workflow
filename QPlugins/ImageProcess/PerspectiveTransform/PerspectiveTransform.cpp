#include "PerspectiveTransform.h"
#include "frmPerspectiveTransform.h"

PerspectiveTransform::PerspectiveTransform()
{
}

QString PerspectiveTransform::name()
{
    return "͸�ӱ任";
}

QString PerspectiveTransform::information()
{
    return "ͼ����";
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
