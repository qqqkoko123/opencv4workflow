#include "ScriptEdit.h"
#include "frmScriptEdit.h"

ScriptEdit::ScriptEdit()
{
}

QString ScriptEdit::name()
{
    return "�ű��༭";
}

QString ScriptEdit::information()
{
    return "�߼�����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmScriptEdit* ss = new frmScriptEdit(toolName, toolBase);
    return ss;
}
