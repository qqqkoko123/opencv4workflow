#include "TemplateMatch.h"
#include "frmTemplateMatch.h"

TemplateMatch::TemplateMatch()
{
}

QString TemplateMatch::name()
{
    return "�Ҷ�ƥ��";
}

QString TemplateMatch::information()
{
    return "��λ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmTemplateMatch* ss = new frmTemplateMatch(toolName, toolBase);
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
