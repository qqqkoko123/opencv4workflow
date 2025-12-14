#include "ExtensionLibrary.h"
#include "frmExtensionLibrary.h"

ExtensionLibrary::ExtensionLibrary()
{
}

QString ExtensionLibrary::name()
{
    return "À©Õ¹¿â";
}

QString ExtensionLibrary::information()
{
    return "Âß¼­¹¤¾ß";
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
