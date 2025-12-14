#include "frmFlatness.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <QPainter>
#include <opencv2/imgproc/types_c.h>
#include <QGraphicsOpacityEffect>

frmFlatness::frmFlatness(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/flatness.png"));
	//初始化标题栏
	initTitleBar();
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmFlatness::~frmFlatness()
{
	this->deleteLater();
}

void frmFlatness::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/flatness.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmFlatness::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
	return QWidget::paintEvent(event);
}

void frmFlatness::onButtonCloseClicked()
{
	this->close();
}

int frmFlatness::Execute(const QString toolname)
{	
	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
	{		
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
			//工具在工具数组中的索引
			tool_index = i;
		}
	}
	int result = RunToolPro();
	if (result == -1)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	return 0;
}

int frmFlatness::RunToolPro()
{
	try
	{
		keys.reserve(300);
		keys.clear();
		keys = gvariable.global_variable_link.uniqueKeys();
		for (int k = 0; k < keys.length(); k++)
		{
			QString key = keys[k];			
			if (key == ui.txtLinkPointsX->text())
			{
				array_double_x = gvariable.global_variable_link.value(key).global_array_double_value;
			}
			else if (key == ui.txtLinkPointsY->text())
			{
				array_double_y = gvariable.global_variable_link.value(key).global_array_double_value;
			}
			else if (key == ui.txtLinkPointsZ->text())
			{
				array_double_z = gvariable.global_variable_link.value(key).global_array_double_value;
			}
			else if (key == ui.txtLink3DPoint->text())
			{
				double_xyz = gvariable.global_variable_link.value(key).global_cvpoint3d_value;
			}
		}
		double plane[4] = { 0 };
		bool state = FitPlane(array_double_x, array_double_y, array_double_z, plane);
		if (ui.checkDist->isChecked() == true)
		{			
			state = CalculateDist(double_xyz, plane, dist);			
			GetToolBase()->m_Tools[tool_index].PublicThreeD.Distance = dist;
		}				
		GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness.clear();
		for (int m = 0; m < 4; m++)
		{
			GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness.push_back(plane[m]);
		}		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmFlatness::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		strs.reserve(100);
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Double[]")
				{
					if (key == str_link)
					{
						ui.txtLinkPointsX->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 2)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Double[]")
				{
					if (key == str_link)
					{
						ui.txtLinkPointsY->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 3)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Double[]")
				{
					if (key == str_link)
					{
						ui.txtLinkPointsZ->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 4)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point3d")
				{
					if (key == str_link)
					{
						ui.txtLink3DPoint->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmFlatness::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	try
	{
		gvariable.global_variable_link = g_variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmFlatness::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> A: " + QString::number(GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness[0]));
	ui.txtMsg->append("-> B: " + QString::number(GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness[1]));
	ui.txtMsg->append("-> C: " + QString::number(GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness[2]));
	ui.txtMsg->append("-> D: " + QString::number(GetToolBase()->m_Tools[tool_index].PublicThreeD.Flatness[3]));
	if (ui.checkDist->isChecked() == true)
	{
		ui.txtMsg->append("-> Distance: " + QString::number(GetToolBase()->m_Tools[tool_index].PublicThreeD.Distance));
	}	
	ui.btnExecute->setEnabled(true);
}

void frmFlatness::on_btnLinkPointsX_clicked()
{
	QConfig::nFormState = 1;
}

void frmFlatness::on_btnDelLinkPointsX_clicked()
{
	ui.txtLinkPointsX->clear();
}

void frmFlatness::on_btnLinkPointsY_clicked()
{
	QConfig::nFormState = 2;
}

void frmFlatness::on_btnDelLinkPointsY_clicked()
{
	ui.txtLinkPointsY->clear();
}

void frmFlatness::on_btnLinkPointsZ_clicked()
{
	QConfig::nFormState = 3;
}

void frmFlatness::on_btnDelLinkPointsZ_clicked()
{
	ui.txtLinkPointsZ->clear();
}

void frmFlatness::on_btnLink3DPoint_clicked()
{
	QConfig::nFormState = 4;
}

void frmFlatness::on_btnDelLink3DPoint_clicked()
{
	ui.txtLink3DPoint->clear();
}

//拟合平面
bool frmFlatness::FitPlane(const vector<double>dx, const vector<double>dy, const vector<double>dz, double* plane) const
{
	CvMat* points, * centroid, * points2, * A, * W, * V;
	try
	{
		//构建点集CvMat
		points = cvCreateMat(dx.size(), 3, CV_32FC1);
		for (int i = 0; i < dx.size(); ++i)
		{
			points->data.fl[i * 3 + 0] = dx[i];  //矩阵的值进行初始化   X的坐标值  
			points->data.fl[i * 3 + 1] = dy[i];  //Y的坐标值  
			points->data.fl[i * 3 + 2] = dz[i];  //Z的坐标值
		}
		//估计几何质心
		int nrows = points->rows;
		int ncols = points->cols;
		int type = points->type;
		centroid = cvCreateMat(1, ncols, type);
		cvSet(centroid, cvScalar(0));
		for (int c = 0; c < ncols; c++) {
			for (int r = 0; r < nrows; r++)
			{
				centroid->data.fl[c] += points->data.fl[ncols * r + c];
			}
			centroid->data.fl[c] /= nrows;
		}
		//每个点减去几何质心 
		points2 = cvCreateMat(nrows, ncols, type);
		for (int r = 0; r < nrows; r++)
			for (int c = 0; c < ncols; c++)
				points2->data.fl[ncols * r + c] = points->data.fl[ncols * r + c] - centroid->data.fl[c];
		//评估协方差矩阵的SVD  
		A = cvCreateMat(ncols, ncols, type);
		W = cvCreateMat(ncols, ncols, type);
		V = cvCreateMat(ncols, ncols, type);
		cvGEMM(points2, points, 1, NULL, 0, A, CV_GEMM_A_T);
		cvSVD(A, W, NULL, V, CV_SVD_V_T);
		//通过对应于最小奇异值的奇异向量分配平面系数  
		plane[ncols] = 0;
		for (int c = 0; c < ncols; c++) {
			plane[c] = V->data.fl[ncols * (ncols - 1) + c];
			plane[ncols] += plane[c] * centroid->data.fl[c];
		}
		//释放分配的资源
		cvReleaseMat(&points);
		cvReleaseMat(&centroid);
		cvReleaseMat(&points2);
		cvReleaseMat(&A);
		cvReleaseMat(&W);
		cvReleaseMat(&V);
		return true;
	}
	catch (...)
	{
		if (points != nullptr)
		{
			cvReleaseMat(&points);
		}
		if (centroid != nullptr)
		{
			cvReleaseMat(&centroid);
		}
		if (points2 != nullptr)
		{
			cvReleaseMat(&points2);
		}
		if (A != nullptr)
		{
			cvReleaseMat(&A);
		}
		if (W != nullptr)
		{
			cvReleaseMat(&W);
		}
		if (V != nullptr)
		{
			cvReleaseMat(&V);
		}
		return false;
	}
	
}

//计算点(a,b,c)到平面(Ax+By+Cz=D)的距离
bool frmFlatness::CalculateDist(const cv::Point3d point, const double* plane, double& dist)
{
	try
	{
		dist = 0.0;
		double mA, mB, mC, mD, mX, mY, mZ;
		mA = plane[0];
		mB = plane[1];
		mC = plane[2];
		mD = plane[3];
		mX = point.x;
		mY = point.y;
		mZ = point.z;
		dist = abs(mA * mX + mB * mY + mC * mZ + mD) / sqrt(mA * mA + mB * mB + mC * mC);		
		return true;
	}
	catch (...)
	{
		return false;
	}	
}

//全局变量控制
int QConfig::nFormState = 0;
