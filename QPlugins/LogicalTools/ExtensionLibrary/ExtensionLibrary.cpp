#include "ExtensionLibrary.h"
#include "frmExtensionLibrary.h"

ExtensionLibrary::ExtensionLibrary()
{
}

QString ExtensionLibrary::name()
{
    return "��չ��";
}

QString ExtensionLibrary::information()
{
    return "�߼�����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmExtensionLibrary* ss = new frmExtensionLibrary(toolName, toolBase);
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
