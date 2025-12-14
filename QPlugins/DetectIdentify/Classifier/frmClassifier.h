#pragma once

#include <QDialog>
#include "ui_frmClassifier.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitClassifierData
{
	QVector<int> type_key;
	QVector<QString> type_names;
	QString file_model;
};
Q_DECLARE_METATYPE(InitClassifierData);

class frmClassifier : public Toolnterface
{
	Q_OBJECT

public:
	frmClassifier(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmClassifier();

private:
	Ui::frmClassifierClass ui;

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
	void on_btnLabels_clicked();
	void on_btnList_clicked();
	void on_btnSaveModel_clicked();
	void on_btnTrainModel_clicked();
	void on_btnLoadModel_clicked();
	void on_btnWrite_clicked();
	void slot_CurrentIndexChanged(int);
	void on_comboTypeBuf_currentIndexChanged(int);

signals:
	void sig_ClassifierValue(QString InfoVal);

private:
	int RunToolPro();
	void coumputeHog(const cv::Mat& src, vector<float>& descriptors);
	bool TrainModel(const QString imgLabels, const QString imgList, const QString imgSaveModel);
	bool PredictionImage(const cv::Mat src, QString& type);
	QImage Mat2QImage(const cv::Mat& mat);	

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;	
	int image_index = 0;
	int tool_index = 0;
	QString imgLabels, imgList, imgSaveModel, imgLoadModel;
	cv::Size imageSize;
	string imageName;
	signed imageLabel;
	vector<cv::Mat> vecImages;
	vector<int> vecLabels;
	cv::Ptr<cv::ml::SVM> svm;
	vector<float> vecDescriptors;
	QMap<int, QString> typeNames;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
