#include "Flatness.h"
#include "frmFlatness.h"

Flatness::Flatness()
{
}

QString Flatness::name()
{
    return "���ƽ��";
}

QString Flatness::information()
{
    return "��ά���";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmFlatness* ss = new frmFlatness(toolName, toolBase);
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
