#include "Classifier.h"
#include "frmClassifier.h"

Classifier::Classifier()
{
}

QString Classifier::name()
{
    return "分类器";
}

QString Classifier::information()
{
    return "检测识别";
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
