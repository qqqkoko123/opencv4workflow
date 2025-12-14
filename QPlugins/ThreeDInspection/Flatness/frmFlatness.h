#pragma once

#include <QDialog>
#include "ui_frmFlatness.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "Toolnterface.h"

class frmFlatness : public Toolnterface
{
	Q_OBJECT

public:
	frmFlatness(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmFlatness();

private:
	Ui::frmFlatnessClass ui;

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
	void on_btnLinkPointsX_clicked();
	void on_btnDelLinkPointsX_clicked();
	void on_btnLinkPointsY_clicked();
	void on_btnDelLinkPointsY_clicked();
	void on_btnLinkPointsZ_clicked();
	void on_btnDelLinkPointsZ_clicked();
	void on_btnLink3DPoint_clicked();
	void on_btnDelLink3DPoint_clicked();

private:
	int RunToolPro();
	bool FitPlane(const vector<double>dx, const vector<double>dy, const vector<double>dz, double* plane) const;
	bool CalculateDist(const cv::Point3d point, const double* plane, double& dist);

private:		
	gVariable gvariable;
	int tool_index = 0;
	QStringList strs;
	QList<QString> keys;
	std::vector<double> array_double_x, array_double_y, array_double_z;
	cv::Point3d double_xyz;
	double dist;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
