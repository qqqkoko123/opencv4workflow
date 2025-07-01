﻿#pragma once

#include <QDialog>
#include "ui_frmImageSplice.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmImageSplice : public Toolnterface
{
	Q_OBJECT

public:
	frmImageSplice(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmImageSplice();

private:
	Ui::frmImageSpliceClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();
	void on_btnAddImage_clicked();
	void on_btnDeleteImage_clicked();
	void slot_DoubleClicked(int, int);

private:
	int RunToolPro();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	std::vector<cv::Mat> imglist;
	cv::Mat srcImage;
	cv::Mat dstImage;	
	int tool_index = 0;
	int image_index = 0;
	int image_index_row;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
