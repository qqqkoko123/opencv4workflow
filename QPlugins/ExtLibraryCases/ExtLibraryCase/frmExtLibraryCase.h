#pragma once

#include <QDialog>
#include "ui_frmExtLibraryCase.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

class frmExtLibraryCase : public Toolnterface
{
	Q_OBJECT

public:
	frmExtLibraryCase(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmExtLibraryCase();

private:
	Ui::frmExtLibraryCaseClass ui;

public:
	virtual int Execute(const QString toolname);	
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);		

private slots:
	void onButtonCloseClicked();

private slots:
	void on_btnExecute_clicked();	

protected:
	MyTitleBar* m_titleBar;

private:
	int RunToolPro();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;	
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;	
	int tool_index = 0;
	int image_index = 0;
	QString image_link;
};
