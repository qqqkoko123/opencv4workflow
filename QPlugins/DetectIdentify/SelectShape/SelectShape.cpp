#include "SelectShape.h"
#include "frmSelectShape.h"

SelectShape::SelectShape()
{
}

QString SelectShape::name()
{
    return "轮廓特征选择";
}

QString SelectShape::information()
{
    return "检测识别";
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
