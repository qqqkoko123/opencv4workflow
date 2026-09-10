#include "ShapeMatch.h"
#include "frmShapeMatch.h"

ShapeMatch::ShapeMatch()
{
}

QString ShapeMatch::name()
{
    return "形状匹配";
}

QString ShapeMatch::information()
{
    return "对位工具";
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
