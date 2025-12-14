#include "ImageView.h"
#include "frmImageView.h"

ImageView::ImageView()
{
}

QString ImageView::name()
{
    return "ÕºœÒœ‘ æ";
}

QString ImageView::information()
{
    return "ÕºœÒ¥¶¿Ì";
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
