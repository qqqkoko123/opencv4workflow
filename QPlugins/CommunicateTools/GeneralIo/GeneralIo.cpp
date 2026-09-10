#include "GeneralIo.h"
#include "frmGeneralIo.h"

GeneralIo::GeneralIo()
{
}

QString GeneralIo::name()
{
    return "通用I/O";
}

QString GeneralIo::information()
{
    return "通讯工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmGeneralIo* ss = new frmGeneralIo(toolName, toolBase);
    return ss;
}
