#include "frmPerspectiveTransform.h"
#include <QMessageBox>
#include <QDesktopWidget>

frmPerspectiveTransform::frmPerspectiveTransform(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/perspective.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
}

frmPerspectiveTransform::~frmPerspectiveTransform()
{
	this->deleteLater();
}

void frmPerspectiveTransform::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/perspective.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmPerspectiveTransform::paintEvent(QPaintEvent* event)
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

void frmPerspectiveTransform::onButtonCloseClicked()
{
	this->close();
}

int frmPerspectiveTransform::Execute(const QString toolname)
{
	bool link_state = false;
	image_index = 0;
	QString str = ui.txtLinkImage->text();
	strs.reserve(100);
	strs.clear();
	strs = str.split(".");
	if (strs.size() == 1)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
	{
		if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
		{
			//获取的图像在工具数组中的索引
			image_index = i;
			link_state = true;
		}
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
			//工具在工具数组中的索引
			tool_index = i;
		}
	}
	if (link_state == false)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -2;
	}
	int result = RunToolPro();
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmPerspectiveTransform::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		keys.reserve(300);
		keys.clear();
		keys = gvariable.global_variable_link.uniqueKeys();
		for (int k = 0; k < keys.length(); k++)
		{
			QString key = keys[k];
			//输入点
			if (key == ui.txtInPutPos1->text())
			{
				input_point1 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtInPutPos2->text())
			{
				input_point2 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtInPutPos3->text())
			{
				input_point3 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtInPutPos4->text())
			{
				input_point4 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			//输出点
			if (key == ui.txtOutPutPos1->text())
			{
				output_point1 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtOutPutPos2->text())
			{
				output_point2 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtOutPutPos3->text())
			{
				output_point3 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
			else if (key == ui.txtOutPutPos4->text())
			{
				output_point4 = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
			}
		}
		//创建用于输入透视的四个点坐标
		std::vector<cv::Point2f> src =
		{
			input_point1,
			input_point2,
			input_point3,
			input_point4
		};
		//创建用于输出透视的四个点坐标
		std::vector<cv::Point2f> dst =
		{
			output_point1,
			output_point2,
			output_point3,
			output_point4
		};
		//获取透视矩阵
		cv::Mat data = cv::getPerspectiveTransform(src, dst);
		//进行透视操作
		cv::warpPerspective(srcImage, dstImage, data, srcImage.size());
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmPerspectiveTransform::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 1 || strs[1] != "图像")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkImage->setText(str_link);
		}
		else if (int_link == 2)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtInPutPos1->setText(str_link);
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
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtInPutPos2->setText(str_link);
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
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtInPutPos3->setText(str_link);
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
		else if (int_link == 5)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtInPutPos4->setText(str_link);
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
		else if (int_link == 6)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtOutPutPos1->setText(str_link);
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
		else if (int_link == 7)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtOutPutPos2->setText(str_link);
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
		else if (int_link == 8)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtOutPutPos3->setText(str_link);
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
		else if (int_link == 9)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量cv::Point2f类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtOutPutPos4->setText(str_link);
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

int frmPerspectiveTransform::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmPerspectiveTransform::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmPerspectiveTransform::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmPerspectiveTransform::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmPerspectiveTransform::on_btnLinkInPutPos1_clicked()
{
	QConfig::nFormState = 2;
}

void frmPerspectiveTransform::on_btnLinkInPutPos2_clicked()
{
	QConfig::nFormState = 3;
}

void frmPerspectiveTransform::on_btnLinkInPutPos3_clicked()
{
	QConfig::nFormState = 4;
}

void frmPerspectiveTransform::on_btnLinkInPutPos4_clicked()
{
	QConfig::nFormState = 5;
}

void frmPerspectiveTransform::on_btnDelLinkInPutPos1_clicked()
{
	ui.txtInPutPos1->clear();
}

void frmPerspectiveTransform::on_btnDelLinkInPutPos2_clicked()
{
	ui.txtInPutPos2->clear();
}

void frmPerspectiveTransform::on_btnDelLinkInPutPos3_clicked()
{
	ui.txtInPutPos3->clear();
}

void frmPerspectiveTransform::on_btnDelLinkInPutPos4_clicked()
{
	ui.txtInPutPos4->clear();
}

void frmPerspectiveTransform::on_btnLinkOutPutPos1_clicked()
{
	QConfig::nFormState = 6;
}

void frmPerspectiveTransform::on_btnLinkOutPutPos2_clicked()
{
	QConfig::nFormState = 7;
}

void frmPerspectiveTransform::on_btnLinkOutPutPos3_clicked()
{
	QConfig::nFormState = 8;
}

void frmPerspectiveTransform::on_btnLinkOutPutPos4_clicked()
{
	QConfig::nFormState = 9;
}

void frmPerspectiveTransform::on_btnDelLinkOutPutPos1_clicked()
{
	ui.txtOutPutPos1->clear();
}

void frmPerspectiveTransform::on_btnDelLinkOutPutPos2_clicked()
{
	ui.txtOutPutPos2->clear();
}

void frmPerspectiveTransform::on_btnDelLinkOutPutPos3_clicked()
{
	ui.txtOutPutPos3->clear();
}

void frmPerspectiveTransform::on_btnDelLinkOutPutPos4_clicked()
{
	ui.txtOutPutPos4->clear();
}

QImage frmPerspectiveTransform::Mat2QImage(const cv::Mat& mat)
{
	if (mat.empty())
	{
		return QImage();
	}
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		uchar* pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar* pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	else if (mat.type() == CV_8UC3)
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}

//全局变量控制
int QConfig::nFormState = 0;
