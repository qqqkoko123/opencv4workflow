#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_frmPlateRecognition.h"
#include <opencv2/opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"
#include "plate_engine.h"

struct InitPlateRecognitionData
{
	int camera_index;
	QVector<QString> g_camera;
};
Q_DECLARE_METATYPE(InitPlateRecognitionData);

class frmPlateRecognition : public Toolnterface
{
	Q_OBJECT

public:
	frmPlateRecognition(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmPlateRecognition();

private:
	Ui::frmPlateRecognitionClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

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
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnDetectModel_clicked();
	void on_btnRecModel_clicked();

private:
	int RunToolPro();
	bool EnsureEngine();
	QImage Mat2QImage(const cv::Mat& mat);

private:
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	PlateEngine engine;
	std::vector<QString> plateCodes;
	QString loadedDetect;
	QString loadedRec;
};

class QConfig
{
public:
	static int nFormState;
};
