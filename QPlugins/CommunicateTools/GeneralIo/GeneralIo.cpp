#include "GeneralIo.h"
#include "frmGeneralIo.h"

GeneralIo::GeneralIo()
{
}

QString GeneralIo::name()
{
    return "ͨ��I/O";
}

QString GeneralIo::information()
{
    return "ͨѶ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmGeneralIo* ss = new frmGeneralIo(toolName, toolBase);
    return ss;
}
