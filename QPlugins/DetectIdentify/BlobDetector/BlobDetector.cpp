#include "BlobDetector.h"
#include "frmBlobDetector.h"

BlobDetector::BlobDetector()
{
}

QString BlobDetector::name()
{
    return "�ߵ����";
}

QString BlobDetector::information()
{
    return "���ʶ��";
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
