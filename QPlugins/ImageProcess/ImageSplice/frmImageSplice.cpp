#include "frmImageSplice.h"
#include <QMessageBox>
#include <QDesktopWidget>

frmImageSplice::frmImageSplice(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/image_splice.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//设置表格列宽	
	ui.tableWidgetImage->setColumnWidth(0, 339);
	//设置表格行间距
	ui.tableWidgetImage->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetImage->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetImage->verticalHeader()->setVisible(false);
	ui.tableWidgetImage->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetImage->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetImage, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
}

frmImageSplice::~frmImageSplice()
{
	this->deleteLater();
}

void frmImageSplice::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/image_splice.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmImageSplice::paintEvent(QPaintEvent* event)
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

void frmImageSplice::onButtonCloseClicked()
{
	this->close();
}

int frmImageSplice::Execute(const QString toolname)
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
		return -1;
	}
	return 0;
}

int frmImageSplice::RunToolPro()
{
	try
	{
		imglist.reserve(10);
		imglist.clear();
		int table_contour_count = ui.tableWidgetImage->rowCount();
		for (int m = 0; m < table_contour_count; m++)
		{
			strs.clear();
			strs = ui.tableWidgetImage->item(m, 0)->text().split(".");
			if (strs.size() == 1)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			if (strs[1] == "图像")
			{
				bool link_state = false;
				for (int n = 0; n < GetToolBase()->m_Tools.size(); n++)
				{
					if (GetToolBase()->m_Tools[n].PublicToolName == strs[0])
					{
						//获取的图像在工具数组中的索引
						image_index = n;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				srcImage = cv::Mat();
				srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
				imglist.push_back(srcImage);
			}
		}
		//拼接   
		dstImage = cv::Mat();
		cv::Stitcher stitcher = *cv::Stitcher::create(cv::Stitcher::Mode::SCANS);
		stitcher.setRegistrationResol(ui.spinRegistrationResol->value()); //值越小拼接速度越快，但匹配点变少
		stitcher.setPanoConfidenceThresh(1);		
		stitcher.setWaveCorrection(false); //默认是true，加速选false，表示跳过WaveCorrection步骤		
		int state = stitcher.stitch(imglist, dstImage);
		imglist.clear();
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		if (state == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		}
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmImageSplice::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{			
			int table_count = ui.tableWidgetImage->rowCount();
			for (int m = 0; m < table_count; m++)
			{
				strs.reserve(100);
				strs.clear();
				strs = str_link.split(".");
				if (strs.size() == 1 || strs[1] != "图像")
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}				
				if (str_link == ui.tableWidgetImage->item(m, 0)->text())
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该图像对象！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}
			}
			ui.tableWidgetImage->item(image_index_row, 0)->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmImageSplice::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmImageSplice::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmImageSplice::slot_DoubleClicked(int row, int column)
{
	QConfig::nFormState = 1;
	image_index_row = row;
}

void frmImageSplice::on_btnAddImage_clicked()
{
	int count = ui.tableWidgetImage->rowCount();
	if (count >= 10)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "图像对象超过10个！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	ui.tableWidgetImage->setRowCount(count + 1);  //设置行数	
	QTableWidgetItem* item_name = new QTableWidgetItem("图像链接地址" + QString::number(count + 1));
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetImage->setItem(count, 0, item_name);
}

void frmImageSplice::on_btnDeleteImage_clicked()
{
	int rowIndex = ui.tableWidgetImage->currentRow();
	if (rowIndex != -1)
	{
		ui.tableWidgetImage->removeRow(rowIndex);
	}
}

QImage frmImageSplice::Mat2QImage(const cv::Mat& mat)
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
