#include "frmImageView.h"
#include "datavar.h"
#include "qmutex.h"

FrmImageView::FrmImageView(QWidget *parent)
    : QWidget(parent)
{	
    ui.setupUi(this);		
	//连接信号与槽函数
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image1, this, &FrmImageView::slot_Image1);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image2, this, &FrmImageView::slot_Image2);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image3, this, &FrmImageView::slot_Image3);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image4, this, &FrmImageView::slot_Image4);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image6A, this, &FrmImageView::slot_Image6A);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image6B, this, &FrmImageView::slot_Image6B);
	connect(dataVar::fImageLayout, &frmImageLayout::sig_Image9, this, &FrmImageView::slot_Image9);	
	dataVar::img_view1 = new QGraphicsViews();
	dataVar::img_view2 = new QGraphicsViews();
	dataVar::img_view3 = new QGraphicsViews();
	dataVar::img_view4 = new QGraphicsViews();
	dataVar::img_view5 = new QGraphicsViews();
	dataVar::img_view6 = new QGraphicsViews();
	dataVar::img_view7 = new QGraphicsViews();
	dataVar::img_view8 = new QGraphicsViews();
	dataVar::img_view9 = new QGraphicsViews();
	//1图像
	hlay = new QHBoxLayout(this);
	//2图像	
	vlay2_1 = new QVBoxLayout();
	vlay2_2 = new QVBoxLayout();
	//3图像
	vlay3_1 = new QVBoxLayout();
	vlay3_2 = new QVBoxLayout();
	hlay3_2_1 = new QHBoxLayout();
	hlay3_2_2 = new QHBoxLayout();
	//4图像	
	vlay4 = new QVBoxLayout();
	hlay4_1 = new QHBoxLayout();
	hlay4_1_1 = new QHBoxLayout();
	hlay4_1_2 = new QHBoxLayout();
	hlay4_2 = new QHBoxLayout();
	hlay4_2_1 = new QHBoxLayout();
	hlay4_2_2 = new QHBoxLayout();
	//6图像A	
	vlay6_1 = new QVBoxLayout();
	vlay6_1_1 = new QVBoxLayout();
	vlay6_1_2 = new QVBoxLayout();
	vlay6_2 = new QVBoxLayout();
	vlay6_2_1 = new QVBoxLayout();
	vlay6_2_2 = new QVBoxLayout();
	vlay6_3 = new QVBoxLayout();
	vlay6_3_1 = new QVBoxLayout();
	vlay6_3_2 = new QVBoxLayout();
	//6图像B			
	vlay6B = new QVBoxLayout();
	hlay6B_1 = new QHBoxLayout();
	vlay6B_1_1 = new QVBoxLayout();
	vlay6B_1_2 = new QVBoxLayout();
	hlay6B_1_2_1 = new QHBoxLayout();
	hlay6B_1_2_2 = new QHBoxLayout();
	hlay6B_2 = new QHBoxLayout();
	vlay6B_2_1 = new QVBoxLayout();
	vlay6B_2_2 = new QVBoxLayout();
	vlay6B_2_3 = new QVBoxLayout();
	//9图像
	vlay9 = new QVBoxLayout();
	hlay9_1 = new QHBoxLayout();
	vlay9_1_1 = new QVBoxLayout();
	vlay9_1_2 = new QVBoxLayout();
	vlay9_1_3 = new QVBoxLayout();
	hlay9_2 = new QHBoxLayout();
	vlay9_2_1 = new QVBoxLayout();
	vlay9_2_2 = new QVBoxLayout();
	vlay9_2_3 = new QVBoxLayout();
	hlay9_3 = new QHBoxLayout();
	vlay9_3_1 = new QVBoxLayout();
	vlay9_3_2 = new QVBoxLayout();
	vlay9_3_3 = new QVBoxLayout();	
	h_this = QThread::currentThread();
	connect(this, &FrmImageView::sig_Show_B1, this, &FrmImageView::slot_Show_B1, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B2, this, &FrmImageView::slot_Show_B2, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B3, this, &FrmImageView::slot_Show_B3, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B4, this, &FrmImageView::slot_Show_B4, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B5, this, &FrmImageView::slot_Show_B5, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B6, this, &FrmImageView::slot_Show_B6, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B7, this, &FrmImageView::slot_Show_B7, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B8, this, &FrmImageView::slot_Show_B8, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B9, this, &FrmImageView::slot_Show_B9, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B10, this, &FrmImageView::slot_Show_B10, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B11, this, &FrmImageView::slot_Show_B11, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B12, this, &FrmImageView::slot_Show_B12, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B13, this, &FrmImageView::slot_Show_B13, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B14, this, &FrmImageView::slot_Show_B14, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B15, this, &FrmImageView::slot_Show_B15, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B16, this, &FrmImageView::slot_Show_B16, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B17, this, &FrmImageView::slot_Show_B17, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B18, this, &FrmImageView::slot_Show_B18, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B19, this, &FrmImageView::slot_Show_B19, Qt::BlockingQueuedConnection);
	connect(this, &FrmImageView::sig_Show_B20, this, &FrmImageView::slot_Show_B20, Qt::BlockingQueuedConnection);
}

FrmImageView::~FrmImageView()
{
	this->deleteLater();
}

void FrmImageView::ImageShow_B1(QGraphicsViews* img_view, const QImage img)
{			
	h_B1 = QThread::currentThread();
	if (h_this != h_B1)
	{
		emit sig_Show_B1(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}	
}

void FrmImageView::slot_Show_B1(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B2(QGraphicsViews* img_view, const QImage img)
{		
	h_B2 = QThread::currentThread();
	if (h_this != h_B2)
	{
		emit sig_Show_B2(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B2(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B3(QGraphicsViews* img_view, const QImage img)
{	
	h_B3 = QThread::currentThread();
	if (h_this != h_B3)
	{
		emit sig_Show_B3(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B3(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B4(QGraphicsViews* img_view, const QImage img)
{	
	h_B4 = QThread::currentThread();
	if (h_this != h_B4)
	{
		emit sig_Show_B4(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B4(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B5(QGraphicsViews* img_view, const QImage img)
{	
	h_B5 = QThread::currentThread();
	if (h_this != h_B5)
	{
		emit sig_Show_B5(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B5(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B6(QGraphicsViews* img_view, const QImage img)
{	
	h_B6 = QThread::currentThread();
	if (h_this != h_B6)
	{
		emit sig_Show_B6(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B6(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B7(QGraphicsViews* img_view, const QImage img)
{	
	h_B7 = QThread::currentThread();
	if (h_this != h_B7)
	{
		emit sig_Show_B7(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B7(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B8(QGraphicsViews* img_view, const QImage img)
{	
	h_B8 = QThread::currentThread();
	if (h_this != h_B8)
	{
		emit sig_Show_B8(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B8(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B9(QGraphicsViews* img_view, const QImage img)
{	
	h_B9 = QThread::currentThread();
	if (h_this != h_B9)
	{
		emit sig_Show_B9(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B9(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B10(QGraphicsViews* img_view, const QImage img)
{	
	h_B10 = QThread::currentThread();
	if (h_this != h_B10)
	{
		emit sig_Show_B10(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B10(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B11(QGraphicsViews* img_view, const QImage img)
{
	h_B11 = QThread::currentThread();
	if (h_this != h_B11)
	{
		emit sig_Show_B11(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B11(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B12(QGraphicsViews* img_view, const QImage img)
{	
	h_B12 = QThread::currentThread();
	if (h_this != h_B12)
	{
		emit sig_Show_B12(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B12(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B13(QGraphicsViews* img_view, const QImage img)
{	
	h_B13 = QThread::currentThread();
	if (h_this != h_B13)
	{
		emit sig_Show_B13(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B13(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B14(QGraphicsViews* img_view, const QImage img)
{	
	h_B14 = QThread::currentThread();
	if (h_this != h_B14)
	{
		emit sig_Show_B14(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B14(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B15(QGraphicsViews* img_view, const QImage img)
{	
	h_B15 = QThread::currentThread();
	if (h_this != h_B15)
	{
		emit sig_Show_B15(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B15(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B16(QGraphicsViews* img_view, const QImage img)
{	
	h_B16 = QThread::currentThread();
	if (h_this != h_B16)
	{
		emit sig_Show_B16(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B16(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B17(QGraphicsViews* img_view, const QImage img)
{	
	h_B17 = QThread::currentThread();
	if (h_this != h_B17)
	{
		emit sig_Show_B17(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B17(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B18(QGraphicsViews* img_view, const QImage img)
{	
	h_B18 = QThread::currentThread();
	if (h_this != h_B18)
	{
		emit sig_Show_B18(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B18(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B19(QGraphicsViews* img_view, const QImage img)
{	
	h_B19 = QThread::currentThread();
	if (h_this != h_B19)
	{
		emit sig_Show_B19(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B19(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::ImageShow_B20(QGraphicsViews* img_view, const QImage img)
{	
	h_B20 = QThread::currentThread();
	if (h_this != h_B20)
	{
		emit sig_Show_B20(img_view, img);
	}
	else
	{
		img_view->DispImage(img);
		img_view->viewport()->update();
	}
}

void FrmImageView::slot_Show_B20(QGraphicsViews* img_view, const QImage img)
{
	img_view->DispImage(img);
	img_view->viewport()->update();
}

void FrmImageView::slot_Image1()
{		
	removeLayout();
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);	
	hlay->addWidget(dataVar::img_view1);
}

void FrmImageView::slot_Image2()
{	
	removeLayout();	
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);	
	vlay2_1->setSpacing(0);	
	vlay2_1->addWidget(dataVar::img_view1);	
	vlay2_2->setSpacing(0);	
	vlay2_2->addWidget(dataVar::img_view2);
	hlay->addLayout(vlay2_1);
	hlay->addLayout(vlay2_2);
}

void FrmImageView::slot_Image3()
{
	removeLayout();	
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);
	vlay3_1->setSpacing(0);
	vlay3_1->addWidget(dataVar::img_view1);
	vlay3_2->setSpacing(0);
	hlay3_2_1->setSpacing(0);	
	hlay3_2_1->addWidget(dataVar::img_view2);
	hlay3_2_2->setSpacing(0);	
	hlay3_2_2->addWidget(dataVar::img_view3);
	vlay3_2->addLayout(hlay3_2_1);
	vlay3_2->addLayout(hlay3_2_2);
	hlay->addLayout(vlay3_1);
	hlay->addLayout(vlay3_2);	
}

void FrmImageView::slot_Image4()
{
	removeLayout();	
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);	
	vlay4->setSpacing(0);		
	hlay4_1->setSpacing(0);		
	hlay4_1_1->setSpacing(0);
	hlay4_1_1->addWidget(dataVar::img_view1);
	hlay4_1->addLayout(hlay4_1_1);	
	hlay4_1_2->setSpacing(0);	
	hlay4_1_2->addWidget(dataVar::img_view2);
	hlay4_1->addLayout(hlay4_1_2);
	vlay4->addLayout(hlay4_1);	
	hlay4_2->setSpacing(0);		
	hlay4_2_1->setSpacing(0);	
	hlay4_2_1->addWidget(dataVar::img_view3);
	hlay4_2->addLayout(hlay4_2_1);	
	hlay4_2_2->setSpacing(0);
	hlay4_2_2->addWidget(dataVar::img_view4);
	hlay4_2->addLayout(hlay4_2_2);
	vlay4->addLayout(hlay4_2);
	hlay->addLayout(vlay4);	
}

void FrmImageView::slot_Image6A()
{
	removeLayout();
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);	
	vlay6_1->setSpacing(0);
	vlay6_1_1->setSpacing(0);
	vlay6_1_2->setSpacing(0);
	vlay6_2->setSpacing(0);
	vlay6_2_1->setSpacing(0);
	vlay6_2_2->setSpacing(0);
	vlay6_3->setSpacing(0);
	vlay6_3_1->setSpacing(0);
	vlay6_3_2->setSpacing(0);
	vlay6_1_2->addWidget(dataVar::img_view1);
	vlay6_2_1->addWidget(dataVar::img_view2);
	vlay6_3_1->addWidget(dataVar::img_view3);
	vlay6_1_1->addWidget(dataVar::img_view4);
	vlay6_2_2->addWidget(dataVar::img_view5);
	vlay6_3_2->addWidget(dataVar::img_view6);
	vlay6_1->addLayout(vlay6_1_2);	
	vlay6_1->addLayout(vlay6_1_1);	
	vlay6_2->addLayout(vlay6_2_1);
	vlay6_2->addLayout(vlay6_2_2);	
	vlay6_3->addLayout(vlay6_3_1);		
	vlay6_3->addLayout(vlay6_3_2);	
	hlay->addLayout(vlay6_1);
	hlay->addLayout(vlay6_2);
	hlay->addLayout(vlay6_3);
}

void FrmImageView::slot_Image6B()
{
	removeLayout();	
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);		
	vlay6B->setSpacing(0);	
	hlay6B_1->setSpacing(0);
	vlay6B_1_1->setSpacing(0);	
	vlay6B_1_1->addWidget(dataVar::img_view1);
	hlay6B_1->addLayout(vlay6B_1_1);	
	vlay6B_1_2->setSpacing(0);	
	hlay6B_1_2_1->setSpacing(0);	
	hlay6B_1_2_1->addWidget(dataVar::img_view2);
	vlay6B_1_2->addLayout(hlay6B_1_2_1);
	hlay6B_1_2_2->setSpacing(0);	
	hlay6B_1_2_2->addWidget(dataVar::img_view3);
	vlay6B_1_2->addLayout(hlay6B_1_2_2);
	hlay6B_1->addLayout(vlay6B_1_2);
	hlay6B_1->setStretchFactor(vlay6B_1_1, 2);
	hlay6B_1->setStretchFactor(vlay6B_1_2, 1);
	vlay6B->addLayout(hlay6B_1);	
	hlay6B_2->setSpacing(0);	
	vlay6B_2_1->setSpacing(0);	
	vlay6B_2_1->addWidget(dataVar::img_view4);
	hlay6B_2->addLayout(vlay6B_2_1);	
	vlay6B_2_2->setSpacing(0);
	vlay6B_2_2->addWidget(dataVar::img_view5);
	hlay6B_2->addLayout(vlay6B_2_2);	
	vlay6B_2_3->setSpacing(0);
	vlay6B_2_3->addWidget(dataVar::img_view6);
	hlay6B_2->addLayout(vlay6B_2_3);
	vlay6B->addLayout(hlay6B_2);
	vlay6B->setStretchFactor(hlay6B_1, 2);
	vlay6B->setStretchFactor(hlay6B_2, 1);
	hlay->addLayout(vlay6B);	
}

void FrmImageView::slot_Image9()
{
	removeLayout();
	hlay->setContentsMargins(0, 0, 0, 0);
	hlay->setSpacing(0);	
	vlay9->setSpacing(0);	
	hlay9_1->setSpacing(0);	
	vlay9_1_1->setSpacing(0);
	vlay9_1_1->addWidget(dataVar::img_view1);
	hlay9_1->addLayout(vlay9_1_1);	
	vlay9_1_2->setSpacing(0);
	vlay9_1_2->addWidget(dataVar::img_view2);
	hlay9_1->addLayout(vlay9_1_2);	
	vlay9_1_3->setSpacing(0);
	vlay9_1_3->addWidget(dataVar::img_view3);
	hlay9_1->addLayout(vlay9_1_3);
	vlay9->addLayout(hlay9_1);	
	hlay9_2->setSpacing(0);
	vlay9_2_1->setSpacing(0);
	vlay9_2_1->addWidget(dataVar::img_view4);
	hlay9_2->addLayout(vlay9_2_1);	
	vlay9_2_2->setSpacing(0);
	vlay9_2_2->addWidget(dataVar::img_view5);
	hlay9_2->addLayout(vlay9_2_2);	
	vlay9_2_3->setSpacing(0);
	vlay9_2_3->addWidget(dataVar::img_view6);
	hlay9_2->addLayout(vlay9_2_3);
	vlay9->addLayout(hlay9_2);	
	hlay9_3->setSpacing(0);	
	vlay9_3_1->setSpacing(0);
	vlay9_3_1->addWidget(dataVar::img_view7);
	hlay9_3->addLayout(vlay9_3_1);	
	vlay9_3_2->setSpacing(0);
	vlay9_3_2->addWidget(dataVar::img_view8);
	hlay9_3->addLayout(vlay9_3_2);	
	vlay9_3_3->setSpacing(0);
	vlay9_3_3->addWidget(dataVar::img_view9);
	hlay9_3->addLayout(vlay9_3_3);
	vlay9->addLayout(hlay9_3);
	hlay->addLayout(vlay9);
}

const void FrmImageView::removeLayout()
{
	//1图像
	hlay->removeWidget(dataVar::img_view1);
	//2图像
	vlay2_1->removeWidget(dataVar::img_view1);
	hlay->removeItem(vlay2_1);
	vlay2_2->removeWidget(dataVar::img_view2);
	hlay->removeItem(vlay2_2);
	//3图像
	vlay3_1->removeWidget(dataVar::img_view1);
	hlay->removeItem(vlay3_1);
	hlay3_2_1->removeWidget(dataVar::img_view2);
	vlay3_2->removeItem(hlay3_2_1);
	hlay3_2_2->removeWidget(dataVar::img_view3);
	vlay3_2->removeItem(hlay3_2_2);	
	hlay->removeItem(vlay3_2);
	//4图像
	hlay4_1_1->removeWidget(dataVar::img_view1);
	hlay4_1->removeItem(hlay4_1_1);
	hlay4_1_2->removeWidget(dataVar::img_view2);
	hlay4_1->removeItem(hlay4_1_2);
	vlay4->removeItem(hlay4_1);
	hlay4_2_1->removeWidget(dataVar::img_view3);
	hlay4_2->removeItem(hlay4_2_1);
	hlay4_2_2->removeWidget(dataVar::img_view4);
	hlay4_2->removeItem(hlay4_2_2);	
	vlay4->removeItem(hlay4_2);
	hlay->removeItem(vlay4);	
	//6图像A
	vlay6_1_2->removeWidget(dataVar::img_view1);
	vlay6_2_1->removeWidget(dataVar::img_view2);
	vlay6_3_1->removeWidget(dataVar::img_view3);
	vlay6_1_1->removeWidget(dataVar::img_view4);
	vlay6_2_2->removeWidget(dataVar::img_view5);
	vlay6_3_2->removeWidget(dataVar::img_view6);
	vlay6_1->removeItem(vlay6_1_2);
	vlay6_1->removeItem(vlay6_1_1);
	vlay6_2->removeItem(vlay6_2_1);
	vlay6_2->removeItem(vlay6_2_2);
	vlay6_3->removeItem(vlay6_3_1);
	vlay6_3->removeItem(vlay6_3_2);
	hlay->removeItem(vlay6_1);
	hlay->removeItem(vlay6_2);
	hlay->removeItem(vlay6_3);	
	//6图像B
	vlay6B_1_1->removeWidget(dataVar::img_view1);
	hlay6B_1->removeItem(vlay6B_1_1);
	hlay6B_1_2_1->removeWidget(dataVar::img_view2);
	vlay6B_1_2->removeItem(hlay6B_1_2_1);
	hlay6B_1_2_2->removeWidget(dataVar::img_view3);
	vlay6B_1_2->removeItem(hlay6B_1_2_2);
	hlay6B_1->removeItem(vlay6B_1_2);
	vlay6B->removeItem(hlay6B_1);
	vlay6B_2_1->removeWidget(dataVar::img_view4);
	hlay6B_2->removeItem(vlay6B_2_1);
	vlay6B_2_2->removeWidget(dataVar::img_view5);
	hlay6B_2->removeItem(vlay6B_2_2);
	vlay6B_2_3->removeWidget(dataVar::img_view6);
	hlay6B_2->removeItem(vlay6B_2_3);
	vlay6B->removeItem(hlay6B_2);
	hlay->removeItem(vlay6B);
	//9图像
	vlay9_1_1->removeWidget(dataVar::img_view1);
	hlay9_1->removeItem(vlay9_1_1);
	vlay9_1_2->removeWidget(dataVar::img_view2);
	hlay9_1->removeItem(vlay9_1_2);
	vlay9_1_3->removeWidget(dataVar::img_view3);
	hlay9_1->removeItem(vlay9_1_3);
	vlay9->removeItem(hlay9_1);
	vlay9_2_1->removeWidget(dataVar::img_view4);
	hlay9_2->removeItem(vlay9_2_1);
	vlay9_2_2->removeWidget(dataVar::img_view5);
	hlay9_2->removeItem(vlay9_2_2);
	vlay9_2_3->removeWidget(dataVar::img_view6);
	hlay9_2->removeItem(vlay9_2_3);
	vlay9->removeItem(hlay9_2);
	vlay9_3_1->removeWidget(dataVar::img_view7);
	hlay9_3->removeItem(vlay9_3_1);
	vlay9_3_2->removeWidget(dataVar::img_view8);
	hlay9_3->removeItem(vlay9_3_2);
	vlay9_3_3->removeWidget(dataVar::img_view9);
	hlay9_3->removeItem(vlay9_3_3);	
	vlay9->removeItem(hlay9_3);
	hlay->removeItem(vlay9);		
	dataVar::img_view1->setParent(nullptr);
	dataVar::img_view2->setParent(nullptr);
	dataVar::img_view3->setParent(nullptr);
	dataVar::img_view4->setParent(nullptr);
	dataVar::img_view5->setParent(nullptr);
	dataVar::img_view6->setParent(nullptr);
	dataVar::img_view7->setParent(nullptr);
	dataVar::img_view8->setParent(nullptr);
	dataVar::img_view9->setParent(nullptr);
}
