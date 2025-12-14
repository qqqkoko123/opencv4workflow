#include "frmColorIdentify.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>
#include "QGraphicsScenes.h"
#include "ImageItem.h"

frmColorIdentify::frmColorIdentify(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/color_r.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽		
	connect(this, SIGNAL(sig_Message()), this, SLOT(slot_Message()));
	connect(this, &frmColorIdentify::sig_ScoreValue, view->item, &ImageItem::slot_ScoreValue);
	connect(ui.checkStandardImage, SIGNAL(clicked()), this, SLOT(slot_StandardImage()));
	//初始化标题栏
	initTitleBar();
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);
	rectangle_item = new RectangleItem(10, 10, 200, 200);
}

frmColorIdentify::~frmColorIdentify()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	this->deleteLater();
}

void frmColorIdentify::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/color_r.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmColorIdentify::paintEvent(QPaintEvent* event)
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

void frmColorIdentify::onButtonCloseClicked()
{
	this->close();
}

int frmColorIdentify::Execute(const QString toolname)
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

int frmColorIdentify::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
		if (!srcStandardImage.empty())
		{
			if (rectangle_item->rect_init_state == false)
			{
				return -1;
			}
			rectangle_item->GetRect(m_rectangle);
			rect = cv::Rect(m_rectangle.col, m_rectangle.row, m_rectangle.width, m_rectangle.height);
			mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
			if (ui.checkUseFollow->isChecked() == true)
			{
				strs.clear();
				strs = ui.txtLinkFollow->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				int f_index = 0;
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						f_index = i;
						link_state = true;
					}
				}	
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "匹配基准中心")
				{
					if (GetToolBase()->m_Tools[f_index].PublicTPosition.Center.size() == 0)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					cv::Point2f match_origin_point = GetToolBase()->m_Tools[f_index].PublicTPosition.DatumCenter;
					double match_origin_angle = 0;								
					cv::Point2f match_current_point = GetToolBase()->m_Tools[f_index].PublicTPosition.Center[0];
					double match_current_angle = GetToolBase()->m_Tools[f_index].PublicTPosition.Angle[0];
					cv::Point2f vertices[4];  //定义矩形的4个顶点坐标
					vertices[0] = cv::Point2f(rect.x, rect.y);
					vertices[1] = cv::Point2f(rect.x + rect.width, rect.y);
					vertices[2] = cv::Point2f(rect.x + rect.width, rect.y + rect.height);
					vertices[3] = cv::Point2f(rect.x, rect.y + rect.height);
					cv::Point2f point_1 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[0]);
					cv::Point2f point_2 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[1]);
					cv::Point2f point_3 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[2]);
					cv::Point2f point_4 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[3]);
					cv::Point root_points[1][4];
					root_points[0][0] = cv::Point(point_1.x, point_1.y);
					root_points[0][1] = cv::Point(point_2.x, point_2.y);
					root_points[0][2] = cv::Point(point_3.x, point_3.y);
					root_points[0][3] = cv::Point(point_4.x, point_4.y);
					pts.clear();
					pts.push_back(cv::Point(point_1.x, point_1.y));
					pts.push_back(cv::Point(point_2.x, point_2.y));
					pts.push_back(cv::Point(point_3.x, point_3.y));
					pts.push_back(cv::Point(point_4.x, point_4.y));
					const cv::Point* ppt[1] = { root_points[0] };
					int npt[] = { 4 };
					cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
				}
				else
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
			}
			else
			{
				mask(rect).setTo(255);
			}			
			srcImage.copyTo(dstImage, mask);
			srcStandardImage.copyTo(dstStandardImage, mask);
		}
		else
		{
			//子线程中操作GUI要用信号与槽
			emit sig_Message();
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		//颜色直方图比较相似性
		double score = 0;
		bool state = ColorIdentifyCheck(dstStandardImage, dstImage, score);
		if (state == false)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		if (ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = srcImage.clone();
			if (dstRoiImage.channels() == 1)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstRoiImage.channels() == 4)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_RGBA2BGR);
			}			
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			if (ui.checkUseFollow->isChecked() == true)
			{
				cv::line(dstRoiImage, pts[0], pts[1], cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, pts[1], pts[2], cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, pts[2], pts[3], cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, pts[0], pts[3], cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else
			{
				cv::rectangle(dstRoiImage, rect, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}			
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = srcImage;
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Score = score;
		if (score < ui.spinMinScore->value())
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		}
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmColorIdentify::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			if (strs.size() == 1 || strs[1] != "匹配基准中心")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkFollow->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmColorIdentify::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmColorIdentify::InitSetToolData(const QVariant data)
{
	try
	{
		InitColorIdentifyData init_data;
		init_data = data.value<InitColorIdentifyData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			rectangle_item = new RectangleItem(init_data.x, init_data.y, init_data.width, init_data.height);
			rectangle_item->rect_init_state = true;
			view->AddItems(rectangle_item);
			color = init_data.color;
			//设置按钮背景颜色
			QString style_color = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ")";
			ui.btnRoiColor->setStyleSheet(style_color);			
		}		
		srcStandardImage = QImageToMat(init_data.srcStandardImage);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmColorIdentify::InitGetToolData()
{
	InitColorIdentifyData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (rectangle_item->rect_init_state == false)
		{
			return -1;
		}
		rectangle_item->GetRect(m_rectangle);		
		init_data.x = m_rectangle.col;
		init_data.y = m_rectangle.row;
		init_data.width = m_rectangle.width;
		init_data.height = m_rectangle.height;
		init_data.color = color;		
	}
	else
	{
		init_data.use_roi = false;
	}
	init_data.srcStandardImage = Mat2QImage(srcStandardImage);
	return QVariant::fromValue(init_data);
}

void frmColorIdentify::slot_StandardImage()
{
	if (ui.checkStandardImage->isChecked() == true)
	{
		if (!srcImage.empty())
		{
			srcStandardImage = srcImage.clone();
		}
		else
		{
			QMessageBox::warning(this, "提示", "输入图像为空！", QMessageBox::Ok);
			ui.checkStandardImage->setChecked(false);
		}
	}
}

void frmColorIdentify::slot_Message()
{
	QMessageBox::warning(this, "提示", "标准图像为空！", QMessageBox::Ok);
	return;
}

void frmColorIdentify::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QString msg = "颜色相似度分数为：" + QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.Score, 'f', 2);
	emit sig_ScoreValue(msg);
	QImage img(Mat2QImage(srcImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmColorIdentify::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmColorIdentify::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmColorIdentify::on_btnLinkFollow_clicked()
{
	QConfig::nFormState = 2;
}

void frmColorIdentify::on_btnDelLinkFollow_clicked()
{
	ui.txtLinkFollow->clear();
}

void frmColorIdentify::on_btnAddROI_clicked()
{
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		rectangle_item = new RectangleItem(10, 10, 200, 200);
		rectangle_item->rect_init_state = true;
		view->AddItems(rectangle_item);
		break;
	}
}

void frmColorIdentify::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

void frmColorIdentify::on_btnRoiColor_clicked()
{
	QColorDialog dlg(this);
	dlg.setMinimumSize(547, 393);
	dlg.setWindowTitle("Color Editor");
	dlg.setCurrentColor(QColor(100, 111, 222));
	dlg.setWindowIcon(QIcon(":/resource/color_edit.png"));
	if (dlg.exec() == QColorDialog::Accepted)
	{
		color = dlg.selectedColor();
		//设置按钮背景颜色
		ui.btnRoiColor->setAutoFillBackground(true);
		ui.btnRoiColor->setFlat(true);
		QPalette palette = ui.btnRoiColor->palette();
		palette.setColor(QPalette::Button, color);
		ui.btnRoiColor->setPalette(palette);
	}
}

//颜色直方图比较相似性
bool frmColorIdentify::ColorIdentifyCheck(const cv::Mat src_ori, const cv::Mat src_mat, double& score)
{
	try
	{
		if (src_ori.channels() == 1 || src_mat.channels() == 1)
		{
			return false;
		}
		cv::Mat ori_hsv, mat_hsv;
		cv::cvtColor(src_ori, ori_hsv, cv::COLOR_BGR2HSV);
		cv::cvtColor(src_mat, mat_hsv, cv::COLOR_BGR2HSV);
		//把h,s,v分成N份分别统计每一份中的像素数		
		int histSize[] = { 50,60 };
		float h_ranges[] = { 0,(float)ui.spinMaxH->value() };
		float s_ranges[] = { 0,(float)ui.spinMaxS->value() };		
		const float* ranges[] = { h_ranges,s_ranges };
		//计算了h,s两个通道
		int channels[] = { 0,1 };
		//MatND类型的容器用于存储calcHist计算出的直方图
		cv::MatND oriHist;
		cv::MatND matHist;
		cv::calcHist(&ori_hsv, 1, channels, mask, oriHist, 2, histSize, ranges, true, false);
		cv::normalize(oriHist, oriHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
		cv::calcHist(&mat_hsv, 1, channels, mask, matHist, 2, histSize, ranges, true, false);
		cv::normalize(matHist, matHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
		//直方图比较
		score = cv::compareHist(oriHist, matHist, 0);
		if (score < 0)
		{
			score = 0;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

cv::Point2f frmColorIdentify::AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point)
{
	try
	{
		//获取旋转矩阵
		cv::Mat rotMat = cv::getRotationMatrix2D(match_origin_point, (match_current_angle - match_origin_angle), 1.0);
		//转换成3*3矩阵
		cv::Mat rotMat2 = cv::Mat::zeros(3, 3, CV_32FC1);
		rotMat2.at<float>(0, 0) = (float)rotMat.at<double>(0, 0);
		rotMat2.at<float>(0, 1) = (float)rotMat.at<double>(0, 1);
		rotMat2.at<float>(0, 2) = (float)rotMat.at<double>(0, 2);
		rotMat2.at<float>(1, 0) = (float)rotMat.at<double>(1, 0);
		rotMat2.at<float>(1, 1) = (float)rotMat.at<double>(1, 1);
		rotMat2.at<float>(1, 2) = (float)rotMat.at<double>(1, 2);
		rotMat2.at<float>(2, 2) = 1;
		//平移矩阵
		cv::Mat t_mat = cv::Mat::zeros(3, 3, CV_32FC1);
		t_mat.at<float>(0, 0) = 1;
		t_mat.at<float>(0, 2) = match_current_point.x - match_origin_point.x;
		t_mat.at<float>(1, 1) = 1;
		t_mat.at<float>(1, 2) = match_current_point.y - match_origin_point.y;
		t_mat.at<float>(2, 2) = 1;
		//平移矩阵*旋转矩阵，得到仿射变换阵
		cv::Mat resMat = t_mat * rotMat2;
		double a11 = (double)resMat.at<float>(0, 0);
		double a12 = (double)resMat.at<float>(0, 1);
		double a13 = (double)resMat.at<float>(0, 2);
		double a21 = (double)resMat.at<float>(1, 0);
		double a22 = (double)resMat.at<float>(1, 1);
		double a23 = (double)resMat.at<float>(1, 2);
		cv::Point2f out_point;
		out_point = cv::Point2f((input_point.x * a11 + input_point.y * a12 + a13), (input_point.x * a21 + input_point.y * a22 + a23));
		return out_point;
	}
	catch (...)
	{
		return cv::Point2f(0, 0);
	}
}

QImage frmColorIdentify::Mat2QImage(const cv::Mat& mat)
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
cv::Mat frmColorIdentify::QImageToMat(const QImage& image)
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
	case QImage::Format_RGB32:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, cv::COLOR_BGRA2RGB);
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

//全局变量控制
int QConfig::nFormState = 0;
