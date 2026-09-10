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
    return "目标检测";
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
