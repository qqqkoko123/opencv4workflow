#include "ExtLibraryCase.h"
#include "frmExtLibraryCase.h"

ExtLibraryCase::ExtLibraryCase()
{
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmExtLibraryCase* ss = new frmExtLibraryCase(toolName, toolBase);
    return ss;
}
