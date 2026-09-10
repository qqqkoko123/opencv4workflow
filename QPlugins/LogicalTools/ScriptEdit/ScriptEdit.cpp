#include "ScriptEdit.h"
#include "frmScriptEdit.h"

ScriptEdit::ScriptEdit()
{
}

QString ScriptEdit::name()
{
    return "脚本编辑";
}

QString ScriptEdit::information()
{
    return "逻辑工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmScriptEdit* ss = new frmScriptEdit(toolName, toolBase);
    return ss;
}
