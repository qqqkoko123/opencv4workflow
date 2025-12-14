#pragma once

#include <QDialog>
#include "ui_frmExportImage.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "Toolnterface.h"

class frmExportImage : public Toolnterface
{
	Q_OBJECT

public:
	frmExportImage(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmExportImage();

private:
	Ui::frmExportImageClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();
	void timerEvent();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnStoragePath_clicked();
	void on_btnLinkFileName_clicked();
	void on_btnDelLinkFileName_clicked();

private:
	int RunToolPro();
	//删除N天前的文件夹；
	bool FindFolderForDelete(const QString path, const int day = 30);
	QImage Mat2QImage(const cv::Mat& mat);
	cv::Mat QImageToMat(const QImage& image);
	
private:	
	gVariable gvariable;
	QStringList strs;
	cv::Mat srcImage;
	QList<QString> keys;
	int image_index = 0;
	int tool_index = 0;
	const char* img_format;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
