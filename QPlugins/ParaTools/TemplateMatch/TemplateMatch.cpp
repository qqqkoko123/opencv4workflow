#include "TemplateMatch.h"
#include "frmTemplateMatch.h"

TemplateMatch::TemplateMatch()
{
}

QString TemplateMatch::name()
{
    return "灰度匹配";
}

QString TemplateMatch::information()
{
    return "对位工具";
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
