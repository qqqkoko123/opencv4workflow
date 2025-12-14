#include "ScriptEdit.h"
#include "frmScriptEdit.h"

ScriptEdit::ScriptEdit()
{
}

QString ScriptEdit::name()
{
    return "½Å±¾±à¼­";
}

QString ScriptEdit::information()
{
    return "Âß¼­¹¤¾ß";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmScriptEdit* ss = new frmScriptEdit(toolName, toolBase);
    return ss;
}
