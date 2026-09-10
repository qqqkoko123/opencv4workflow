#include "ExportCsv.h"
#include "frmExportCsv.h"

ExportCsv::ExportCsv()
{
}

QString ExportCsv::name()
{
    return "导出CSV";
}

QString ExportCsv::information()
{
    return "系统工具";
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
