#include "ShapeMatch.h"
#include "frmShapeMatch.h"

ShapeMatch::ShapeMatch()
{
}

QString ShapeMatch::name()
{
    return "��״ƥ��";
}

QString ShapeMatch::information()
{
    return "��λ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmShapeMatch* ss = new frmShapeMatch(toolName, toolBase);
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
