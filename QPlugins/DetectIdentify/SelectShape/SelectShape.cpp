#include "SelectShape.h"
#include "frmSelectShape.h"

SelectShape::SelectShape()
{
}

QString SelectShape::name()
{
    return "��������ѡ��";
}

QString SelectShape::information()
{
    return "���ʶ��";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmSelectShape* ss = new frmSelectShape(toolName, toolBase);
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
