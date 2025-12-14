#include "Classifier.h"
#include "frmClassifier.h"

Classifier::Classifier()
{
}

QString Classifier::name()
{
    return "YoloV13";
}

QString Classifier::information()
{
    return "Ä¿±ê¼ì²â";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmClassifier* ss = new frmClassifier(toolName, toolBase);
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
