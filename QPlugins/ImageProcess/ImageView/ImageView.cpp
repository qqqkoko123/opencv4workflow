#include "ImageView.h"
#include "frmImageView.h"

ImageView::ImageView()
{
}

QString ImageView::name()
{
    return "图像显示";
}

QString ImageView::information()
{
    return "图像处理";
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
