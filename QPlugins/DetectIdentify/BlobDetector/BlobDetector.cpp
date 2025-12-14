#include "BlobDetector.h"
#include "frmBlobDetector.h"

BlobDetector::BlobDetector()
{
}

QString BlobDetector::name()
{
    return "斑点分析";
}

QString BlobDetector::information()
{
    return "检测识别";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmBlobDetector* ss = new frmBlobDetector(toolName, toolBase);
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
