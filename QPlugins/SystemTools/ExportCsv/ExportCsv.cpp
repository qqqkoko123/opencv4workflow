#include "ExportCsv.h"
#include "frmExportCsv.h"

ExportCsv::ExportCsv()
{
}

QString ExportCsv::name()
{
    return "����CSV";
}

QString ExportCsv::information()
{
    return "ϵͳ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmExportCsv* ss = new frmExportCsv(toolName, toolBase);
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
