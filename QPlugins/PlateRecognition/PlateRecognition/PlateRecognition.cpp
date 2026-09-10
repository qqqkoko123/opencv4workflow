#include "PlateRecognition.h"
#include "frmPlateRecognition.h"

PlateRecognition::PlateRecognition()
{
}

QString PlateRecognition::name()
{
	return QString::fromUtf8("\xE8\xBD\xA6\xE7\x89\x8C\xE8\xAF\x86\xE5\x88\xAB");
}

QString PlateRecognition::information()
{
	return QString::fromUtf8("\xE8\xBD\xA6\xE7\x89\x8C\xE8\xAF\x86\xE5\x88\xAB");
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
	frmPlateRecognition* ss = new frmPlateRecognition(toolName, toolBase);
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
