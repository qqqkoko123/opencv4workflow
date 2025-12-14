#include "LinearCalculation.h"
#include "frmLinearCalculation.h"

LinearCalculation::LinearCalculation()
{
}

QString LinearCalculation::name()
{
	return "线性计算";
}

QString LinearCalculation::information()
{
	return "对位工具";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
	frmLinearCalculation* ss = new frmLinearCalculation(toolName, toolBase);
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
