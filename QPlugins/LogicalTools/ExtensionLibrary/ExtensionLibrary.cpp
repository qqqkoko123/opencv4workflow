#include "ExtensionLibrary.h"
#include "frmExtensionLibrary.h"

ExtensionLibrary::ExtensionLibrary()
{
}

QString ExtensionLibrary::name()
{
    return "扩展库";
}

QString ExtensionLibrary::information()
{
    return "逻辑工具";
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
