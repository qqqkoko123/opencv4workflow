#include "EdgeWidthMeasure.h"
#include "frmEdgeWidthMeasure.h"

EdgeWidthMeasure::EdgeWidthMeasure()
{
}

QString EdgeWidthMeasure::name()
{
    return "��Ե��Ȳ���";
}

QString EdgeWidthMeasure::information()
{
    return "���β���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmEdgeWidthMeasure* ss = new frmEdgeWidthMeasure(toolName, toolBase);
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
