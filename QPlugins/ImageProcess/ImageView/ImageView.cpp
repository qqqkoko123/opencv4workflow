#include "ImageView.h"
#include "frmImageView.h"

ImageView::ImageView()
{
}

QString ImageView::name()
{
    return "ͼ����ʾ";
}

QString ImageView::information()
{
    return "ͼ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
    frmImageView* ss = new frmImageView(toolName, toolBase);
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
