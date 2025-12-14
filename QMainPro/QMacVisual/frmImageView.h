#pragma once

#include <QtWidgets/QWidget>
#include "ui_frmImageView.h"
#include "QGraphicsViews.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

class FrmImageView : public QWidget
{
    Q_OBJECT

public:
    FrmImageView(QWidget *parent = Q_NULLPTR);	
	~FrmImageView();

private:
	Ui::ImageViewClass ui;

public:
	void ImageShow_B1(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B2(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B3(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B4(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B5(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B6(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B7(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B8(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B9(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B10(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B11(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B12(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B13(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B14(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B15(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B16(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B17(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B18(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B19(QGraphicsViews* img_view, const QImage img);
	void ImageShow_B20(QGraphicsViews* img_view, const QImage img);

public slots:
	void slot_Image1();
	void slot_Image2();
	void slot_Image3();
	void slot_Image4();
	void slot_Image6A();
	void slot_Image6B();
	void slot_Image9();	

public:
	const void removeLayout();

private:
	QThread* h_this, * h_B1, * h_B2, * h_B3, * h_B4, * h_B5, * h_B6, * h_B7, * h_B8, * h_B9, * h_B10;
	QThread* h_B11, * h_B12, * h_B13, * h_B14, * h_B15, * h_B16, * h_B17, * h_B18, * h_B19, * h_B20;

signals:
	void sig_Show_B1(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B2(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B3(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B4(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B5(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B6(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B7(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B8(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B9(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B10(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B11(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B12(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B13(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B14(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B15(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B16(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B17(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B18(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B19(QGraphicsViews* img_view, const QImage img);
	void sig_Show_B20(QGraphicsViews* img_view, const QImage img);	

private slots:
	void slot_Show_B1(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B2(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B3(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B4(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B5(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B6(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B7(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B8(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B9(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B10(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B11(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B12(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B13(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B14(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B15(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B16(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B17(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B18(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B19(QGraphicsViews* img_view, const QImage img);
	void slot_Show_B20(QGraphicsViews* img_view, const QImage img);

private:		
	//1Í¼Ïñ
	QHBoxLayout* hlay = nullptr;
	//2Í¼Ïñ
	QVBoxLayout* vlay2_1 = nullptr;
	QVBoxLayout* vlay2_2 = nullptr;
	//3Í¼Ïñ
	QVBoxLayout* vlay3_1 = nullptr;
	QVBoxLayout* vlay3_2 = nullptr;
	QHBoxLayout* hlay3_2_1 = nullptr;
	QHBoxLayout* hlay3_2_2 = nullptr;
	//4Í¼Ïñ
	QVBoxLayout* vlay4 = nullptr;
	QHBoxLayout* hlay4_1 = nullptr;
	QHBoxLayout* hlay4_1_1 = nullptr;
	QHBoxLayout* hlay4_1_2 = nullptr;
	QHBoxLayout* hlay4_2 = nullptr;
	QHBoxLayout* hlay4_2_1 = nullptr;
	QHBoxLayout* hlay4_2_2 = nullptr;
	//6Í¼ÏñA	
	QVBoxLayout* vlay6_1 = nullptr;
	QVBoxLayout* vlay6_1_1 = nullptr;
	QVBoxLayout* vlay6_1_2 = nullptr;
	QVBoxLayout* vlay6_2 = nullptr;
	QVBoxLayout* vlay6_2_1 = nullptr;
	QVBoxLayout* vlay6_2_2 = nullptr;
	QVBoxLayout* vlay6_3 = nullptr;
	QVBoxLayout* vlay6_3_1 = nullptr;
	QVBoxLayout* vlay6_3_2 = nullptr;	
	//6Í¼ÏñB				
	QVBoxLayout* vlay6B = nullptr;
	QHBoxLayout* hlay6B_1 = nullptr;
	QVBoxLayout* vlay6B_1_1 = nullptr;
	QVBoxLayout* vlay6B_1_2 = nullptr;
	QHBoxLayout* hlay6B_1_2_1 = nullptr;
	QHBoxLayout* hlay6B_1_2_2 = nullptr;
	QHBoxLayout* hlay6B_2 = nullptr;
	QVBoxLayout* vlay6B_2_1 = nullptr;
	QVBoxLayout* vlay6B_2_2 = nullptr;
	QVBoxLayout* vlay6B_2_3 = nullptr;
	//9Í¼Ïñ
	QVBoxLayout* vlay9 = nullptr;
	QHBoxLayout* hlay9_1 = nullptr;
	QVBoxLayout* vlay9_1_1 = nullptr;
	QVBoxLayout* vlay9_1_2 = nullptr;
	QVBoxLayout* vlay9_1_3 = nullptr;
	QHBoxLayout* hlay9_2 = nullptr;
	QVBoxLayout* vlay9_2_1 = nullptr;
	QVBoxLayout* vlay9_2_2 = nullptr;
	QVBoxLayout* vlay9_2_3 = nullptr;
	QHBoxLayout* hlay9_3 = nullptr;
	QVBoxLayout* vlay9_3_1 = nullptr;
	QVBoxLayout* vlay9_3_2 = nullptr;
	QVBoxLayout* vlay9_3_3 = nullptr;
};
