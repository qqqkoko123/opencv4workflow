#include "frmExportImage.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QDateTime>

#define QDATETIMS qPrintable(QDateTime::currentDateTime().toString("hhmmss.zzz"))
#define QDATE qPrintable(QDate::currentDate().toString("yyyyMMdd"))

frmExportImage::frmExportImage(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/export_image.png"));
	//初始化标题栏
	initTitleBar();	
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(10 * 60 * 1000);  //10分钟
}

frmExportImage::~frmExportImage()
{
	this->deleteLater();
}

void frmExportImage::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");	
	m_titleBar->setTitleIcon(":/resource/export_image.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmExportImage::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor("#bcc2bc")));
	return QWidget::paintEvent(event);
}

void frmExportImage::onButtonCloseClicked()
{
	this->close();
}

void frmExportImage::timerEvent()
{
	int day = 0;
	day = ui.spinImageTime->value();
	FindFolderForDelete(ui.txtStoragePath->toPlainText(), day);
}

int frmExportImage::Execute(const QString toolname)
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
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
	return 0;
}

int frmExportImage::RunToolPro()
{
	try
	{		
		QString format_name = ".bmp";
		img_format = "bmp";
		switch (ui.comboImageFormat->currentIndex()) {
		case 0:
			format_name = ".bmp";
			img_format = "bmp";
			break;
		case 1:
			format_name = ".jpg";
			img_format = "jpg";
			break;
		case 2:
			format_name = ".png";
			img_format = "png";
			break;
		}
		QString file_name;
		QString directory_name = ui.txtStoragePath->toPlainText() + "/" + QDATE;
		QDir dir(directory_name);
		if (!dir.exists())
		{
			dir.mkdir(directory_name);
		}		
		if (ui.checkUseTime->isChecked() == true)
		{
			if (ui.txtFileName->text() != QString())
			{
				file_name = directory_name + "/" + ui.txtFileName->text() + "_" + QDATETIMS + format_name;
			}
			else
			{
				file_name = directory_name + "/" + QDATETIMS + format_name;
			}
		}
		else
		{
			if (ui.txtFileName->text() != QString())
			{
				file_name = directory_name + "/" + ui.txtFileName->text() + format_name;
			}
			else
			{
				file_name = directory_name + "/" + QDATETIMS + format_name;
			}
		}				
		if (strs[0].mid(0,4) == "图像显示")
		{
			if (img_format == "png")
			{
				QImage out_img = GetToolBase()->m_Tools[image_index].PublicImage.OutputViewImage;
				srcImage = QImageToMat(out_img);
				cv::imwrite(file_name.toLocal8Bit().toStdString(), srcImage);	
			}
			else
			{
				QImage out_img = GetToolBase()->m_Tools[image_index].PublicImage.OutputViewImage;
				out_img.save(file_name, img_format);
			}			
		}
		else
		{
			cv::imwrite(file_name.toLocal8Bit().toStdString(), GetToolBase()->m_Tools[image_index].PublicImage.OutputImage);			
		}	
		return 0;
	}
	catch (...)
	{		
		return -1;
	}
}

int frmExportImage::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量QString类型！");
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
				if (gvariable.global_variable_link.value(key).global_type == "QString")
				{
					if (key == str_link)
					{
						ui.txtFileName->setText(str_link);
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

int frmExportImage::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmExportImage::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.btnExecute->setEnabled(true);
}

void frmExportImage::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmExportImage::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmExportImage::on_btnStoragePath_clicked()
{
	QString path_Image = QDir::currentPath();
	QString dirPath = QFileDialog::getExistingDirectory(this, tr("打开存储路径"), path_Image);
	if (false == dirPath.isEmpty())
	{				
		ui.txtStoragePath->setText(dirPath);
	}
}

void frmExportImage::on_btnLinkFileName_clicked()
{
	QConfig::nFormState = 2;
}

void frmExportImage::on_btnDelLinkFileName_clicked()
{
	ui.txtFileName->clear();
}

#pragma region 删除N天前的文件夹
//删除N天前的文件夹
bool frmExportImage::FindFolderForDelete(const QString path, const int day)
{	
	try
	{
		QList<QString> dirs;
		dirs.reserve(1000);
		dirs.clear();
		QDir dir(path);
		dir.setFilter(QDir::Dirs);
		for (auto fullDir : dir.entryInfoList())
		{
			if (fullDir.fileName() == "." || fullDir.fileName() == "..")
				continue;
			dirs.push_back(fullDir.absoluteFilePath());
		}
		if (dirs.size() < day)
		{
			return false;
		}
		else
		{
			QList<quint64> times = QList<quint64>();
			times.reserve(1000);
			times.clear();
			QList<QString> folder = QList<QString>();
			folder.reserve(1000);
			folder.clear();
			for (auto dir : dirs)
			{
				QFileInfo fl(dir);
				QDateTime DT = fl.created();
				QDateTime dt0(QDate(1970, 1, 1));
				quint64 time = DT.toTime_t() - dt0.toTime_t();
				times.append(time);
				folder.append(dir);
			}
			//获取数组中最小值的索引
			int index = -1;
			QVector<quint64> max_and_min(2);
			if (times.size() != 0)
			{
				max_and_min[1] = times[0];
				index = 0;
				for (int i = 0; i < times.size(); i++)
				{
					if (max_and_min[1] > times[i])
					{
						index = i;
						max_and_min[1] = times[i];
					}
				}
			}
			QDir dir_x;
			if (dir_x.exists(folder[index]))
			{
				dir_x.setPath(folder[index]);
				dir_x.removeRecursively();
			}
			return true;
		}
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region QImage与Mat相互转换
//将Mat转化为QImage
QImage frmExportImage::Mat2QImage(const cv::Mat& mat)
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

//将QImage转化为Mat
cv::Mat frmExportImage::QImageToMat(const QImage& image)
{
	cv::Mat mat;
	if (image.isNull())
	{
		return cv::Mat();
	}
	switch (image.format())
	{
	case QImage::Format_ARGB32_Premultiplied:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	case QImage::Format_RGB888:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
		break;
	}
	case QImage::Format_Indexed8:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	case QImage::Format_Grayscale8:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), static_cast<size_t>(image.bytesPerLine()));
		break;
	}
	}
	return mat;
}
#pragma endregion

//全局变量控制
int QConfig::nFormState = 0;
