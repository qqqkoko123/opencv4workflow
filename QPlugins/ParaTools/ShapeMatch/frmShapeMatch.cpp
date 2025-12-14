#include "frmShapeMatch.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>
#include <omp.h>
#include <QGraphicsOpacityEffect>
#include <opencv2/imgproc/imgproc_c.h>
#include "qmutex.h"

frmShapeMatch::frmShapeMatch(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/shape_match.png"));
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	ui.comboViewMode->setCurrentIndex(1);	
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmShapeMatch::~frmShapeMatch()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	this->deleteLater();
}

void frmShapeMatch::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/shape_match.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmShapeMatch::paintEvent(QPaintEvent* event)
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

void frmShapeMatch::onButtonCloseClicked()
{
	this->close();
}

int frmShapeMatch::Execute(const QString toolname)
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

int frmShapeMatch::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
		if (ui.checkUseROI->isChecked() == true)
		{
			if (rectangle_item->rect_init_state == false)
			{
				return -1;
			}
			rectangle_item->GetRect(m_rectangle);
			rect = cv::Rect(m_rectangle.col, m_rectangle.row, m_rectangle.width, m_rectangle.height);
			dst = cv::Mat();
			dst = srcImage(rect);
			use_roi = true;
		}
		else
		{
			dst = cv::Mat();
			srcImage.copyTo(dst);
			use_roi = false;
		}
		srcImage.copyTo(dstImage);
		model_buf = model.clone();
		int num_matches;
		if (ui.comboNumMatches->currentIndex() == 0)
		{
			num_matches = 1;
		}
		else
		{
			num_matches = 2000;
		}
		//形状匹配
		center.clear();
		angle.clear();
		out_score.clear();
		int result = MatchTemplate(dst, model_buf, dstImage, use_roi, m_rectangle, center, angle, out_score, ui.spinPyramid->value(), ui.spinRAngle->value(), num_matches, ui.spinMaxOverlap->value(), ui.spinFeatureNum->value(), ui.spinScore->value(), contour_view, ui.spinThickness->value());
		if (result == -1)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		if (ui.checkUseROI->isChecked() == true && ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = dstImage.clone();
			if (dstRoiImage.channels() == 1)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstRoiImage.channels() == 4)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_RGBA2BGR);
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			cv::rectangle(dstRoiImage, rect, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.Center = center;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.Angle = angle;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.OutScore = out_score;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.DatumCenter = DatumCenter;
		if (center.size() == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
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

int frmShapeMatch::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmShapeMatch::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmShapeMatch::InitSetToolData(const QVariant data)
{
	try
	{
		InitShapeMatchData init_data;
		init_data = data.value<InitShapeMatchData>();
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
		model = QImageToMat(init_data.srcModelImage);
		DatumCenter = cv::Point2f(init_data.datum_center.x(), init_data.datum_center.y());
		ids.clear();
		ids.push_back("test");
		detector.readClasses(ids, init_data.fileModelName.toStdString());
		string infoPath = init_data.fileModelName.toStdString().substr(0, init_data.fileModelName.toStdString().find_last_of(".")) + "_info.yaml";
		infos = shape_based_matching::shapeInfo_producer::load_infos(infoPath);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmShapeMatch::InitGetToolData()
{
	InitShapeMatchData init_data;
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
	init_data.srcModelImage = Mat2QImage(model);
	init_data.datum_center = QPointF(DatumCenter.x, DatumCenter.y);
	init_data.fileModelName = ui.txtSaveModel->text();
	return QVariant::fromValue(init_data);
}

void frmShapeMatch::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	int count = center.size();
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 匹配的个数为: " + QString::number(count));
			ui.txtMsg->append("-> 匹配的中心为: ");
		}
		ui.txtMsg->append(QString::number(center[i].x, 'f', 3) + "," + QString::number(center[i].y, 'f', 3));
	}
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 匹配的角度为: ");
		}
		ui.txtMsg->append(QString::number(angle[i]));
	}
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 匹配的分数为: ");
		}
		ui.txtMsg->append(QString::number(out_score[i]));
	}
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmShapeMatch::on_comboViewMode_currentIndexChanged(int index)
{
	try
	{
		if (ui.comboViewMode->currentIndex() == 0)
		{
			contour_view = false;
		}
		else if (ui.comboViewMode->currentIndex() == 1)
		{
			contour_view = true;
		}
	}
	catch (std::exception& ex)
	{
		QMessageBox::critical(this, "error", ex.what());
	}
}

void frmShapeMatch::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmShapeMatch::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmShapeMatch::on_btnAddROI_2_clicked()
{
	view->ClearObj();
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangle_item->rect_init_state = true;
	view->AddItems(rectangle_item);
}

void frmShapeMatch::on_btnDeleteROI_2_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

void frmShapeMatch::on_btnCreateROI_clicked()
{
	if (rectangle_item->rect_init_state == false)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "创建模板失败！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this, tr("保存模板文件"), QDir::currentPath() + "/Parameters/Model/", tr("Config Files (*.yaml)"));
	if (!fileName.isNull())
	{
		try
		{
			rectangle_item->GetRect(m_rectangle);
			rect = cv::Rect(m_rectangle.col, m_rectangle.row, m_rectangle.width, m_rectangle.height);
			cv::Mat roi = srcImage(rect);
			Save_Mat(fileName.toStdString(), "serialization_mat", roi);
			ui.txtSaveModel->setText(fileName);
			model = Load_Mat(fileName, "serialization_mat");
			rectangle_item->rect_init_state = false;
			view->ClearObj();
			if (model.channels() == 3)
			{
				cv::cvtColor(model, model, cv::COLOR_BGR2GRAY);
			}
			else if (model.channels() == 4)
			{
				cv::cvtColor(model, model, cv::COLOR_RGBA2GRAY);
			}
			float scale = 1.0;
			if (ui.spinPyramid->value() == 1)
			{
				scale = 1.0f;
			}
			else if (ui.spinPyramid->value() == 2)
			{
				scale = 0.5f;
			}
			else if (ui.spinPyramid->value() == 3)
			{
				scale = 0.25f;
			}
			else if (ui.spinPyramid->value() == 4)
			{
				scale = 0.125f;
			}
			else if (ui.spinPyramid->value() == 5)
			{
				scale = 0.0625f;
			}
			else if (ui.spinPyramid->value() == 6)
			{
				scale = 0.03125f;
			}
			cv::Mat temp_X = cv::Mat();
			cv::resize(model, temp_X, cv::Size(scale * model.cols, scale * model.rows), 0, 0, cv::INTER_AREA);
			cv::Mat mask = cv::Mat(temp_X.size(), CV_8UC1, { 255 });
			num_feature = ui.spinFeatureNum->value();
			detector = line2Dup::Detector(num_feature, { 4, 8 }, ui.spinWeakThresh->value(), ui.spinStrongThreash->value());
			cv::Mat padded_img = cv::Mat(temp_X.rows, temp_X.cols, temp_X.type(), cv::Scalar::all(0));
			temp_X.copyTo(padded_img(cv::Rect(0, 0, temp_X.cols, temp_X.rows)));
			cv::Mat padded_mask = cv::Mat(mask.rows, mask.cols, mask.type(), cv::Scalar::all(0));
			mask.copyTo(padded_mask(cv::Rect(0, 0, temp_X.cols, temp_X.rows)));
			shape_based_matching::shapeInfo_producer shapes(padded_img, padded_mask);
			shapes.angle_range = { float(0 - ui.spinRAngle->value()), float(ui.spinRAngle->value()) };  	//旋转
			shapes.angle_step = 0.1f;
			shapes.scale_range = { 1 };  //缩放
			shapes.produce_infos();
			std::vector<shape_based_matching::shapeInfo_producer::Info> infos_have_templ;
			ids.clear();
			ids.push_back("test");
			string class_id = "test";
			bool use_rot = true;
			bool is_first = true;
			int first_id = 0;
			float first_angle = 0;
			for (auto& info : shapes.infos)
			{
				int templ_id;
				if (is_first)
				{
					templ_id = detector.addTemplate(shapes.src_of(info), class_id, shapes.mask_of(info));
					first_id = templ_id;
					first_angle = info.angle;
					if (use_rot) is_first = false;
				}
				else
				{
					templ_id = detector.addTemplate_rotate(class_id, first_id,
						info.angle - first_angle,
						{ shapes.src.cols / 2.0f, shapes.src.rows / 2.0f });
				}
				auto templ = detector.getTemplates("test", templ_id);
				if (templ_id != -1) {
					infos_have_templ.push_back(info);
				}
			}			
			detector.writeClasses(fileName.toStdString());
			string infoPath = fileName.toStdString().substr(0, fileName.toStdString().find_last_of(".")) + "_info.yaml";
			if (FILE* file = fopen(infoPath.c_str(), "r"))
			{
				fclose(file);
				remove(infoPath.c_str());
			}
			shapes.save_infos(infos_have_templ, infoPath);
			infos = shape_based_matching::shapeInfo_producer::load_infos(infoPath);
			//通过匹配获取基准中心
			cv::Mat out_source = srcImage.clone();
			cv::Point2f center;
			double angle;
			int get_result = GetTemplate(srcImage, model, out_source, center, angle, num_feature);
			if (get_result == -1)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "获取基准中心失败！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return;
			}
			QImage img(Mat2QImage(out_source));
			view->DispImage(img);
			//写入匹配基准中心						
			DatumCenter = center;
			GetToolBase()->m_Tools[tool_index].PublicTPosition.DatumCenter = center;
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "创建模板完成！");
			msgBox.setWindowIcon(QIcon(":/resource/info.png"));
			msgBox.exec();

		}
		catch (...)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "创建模板失败或设定金字塔层数太大！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
		}
	}
}

void frmShapeMatch::on_btnDeleteModel_clicked()
{
	ui.txtSaveModel->clear();
	model = cv::Mat();
}

void frmShapeMatch::on_btnAddROI_clicked()
{
	view->ClearObj();
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangle_item->rect_init_state = true;
	view->AddItems(rectangle_item);
}

void frmShapeMatch::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

void frmShapeMatch::on_btnRoiColor_clicked()
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

QImage frmShapeMatch::Mat2QImage(const cv::Mat& mat)
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
cv::Mat frmShapeMatch::QImageToMat(const QImage& image)
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

#pragma region 保存Mat图像到文件
//保存Mat图像到文件
//path的示例参数为：QDir::currentPath() + "/CalibImg/mat_param.xml"，需要将QString转string
//mat_name的示例参数为："serialization_mat"
bool frmShapeMatch::Save_Mat(const string path, const string mat_name, const cv::Mat src_mat)
{
	try
	{
		//保存Mat图像到.xml文件			
		cv::FileStorage fs(path, cv::FileStorage::WRITE);
		fs << mat_name << src_mat;
		fs.release();
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 从文件导入Mat图像
//从文件导入Mat图像
//path的示例参数为：QDir::currentPath() + "/CalibImg/mat_param.xml"
//mat_name的示例参数为："serialization_mat"
cv::Mat frmShapeMatch::Load_Mat(const QString path, const string mat_name)
{
	try
	{
		cv::FileStorage fs(path.toStdString(), cv::FileStorage::READ);
		cv::Mat dst_mat;
		fs[mat_name] >> dst_mat;
		fs.release();
		return dst_mat;
	}
	catch (...)
	{
		return cv::Mat();
	}
}
#pragma endregion

int frmShapeMatch::GetTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, cv::Point2f& center, double& angle, int num_feature)
{
	try
	{
		if (source.empty() || model.empty() || (model.size().area() > source.size().area()))
		{
			return -1;
		}
		if ((model.cols < source.cols && model.rows > source.rows) || (model.cols > source.cols && model.rows < source.rows))
		{
			return -1;
		}
		cv::Mat gray_source;
		if (source.channels() == 3)
		{
			cv::cvtColor(source, gray_source, cv::COLOR_BGR2GRAY);
		}
		else if (source.channels() == 4)
		{
			cv::cvtColor(source, gray_source, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			source.copyTo(gray_source);
		}
		float scale = 1.0;
		if (ui.spinPyramid->value() == 1)
		{
			scale = 1.0f;
		}
		else if (ui.spinPyramid->value() == 2)
		{
			scale = 0.5f;
		}
		else if (ui.spinPyramid->value() == 3)
		{
			scale = 0.25f;
		}
		else if (ui.spinPyramid->value() == 4)
		{
			scale = 0.125f;
		}
		else if (ui.spinPyramid->value() == 5)
		{
			scale = 0.0625f;
		}
		else if (ui.spinPyramid->value() == 6)
		{
			scale = 0.03125f;
		}
		cv::Mat source_X = cv::Mat();
		cv::resize(gray_source, source_X, cv::Size(scale * gray_source.cols, scale * gray_source.rows), 0, 0, cv::INTER_AREA);
		cv::Mat padded_img = cv::Mat(source_X.rows, source_X.cols, source_X.type(), cv::Scalar::all(0));
		source_X.copyTo(padded_img(cv::Rect(0, 0, source_X.cols, source_X.rows)));
		int stride = 16;
		int n = padded_img.rows / stride;
		int m = padded_img.cols / stride;
		cv::Rect roi(0, 0, stride * m, stride * n);
		cv::Mat img = padded_img(roi).clone();
		assert(img.isContinuous());
		auto matches = detector.match(img, 90, ids);
		if (img.channels() == 1) cvtColor(img, img, cv::COLOR_GRAY2BGR);
		size_t top5 = 1;
		if (top5 > matches.size()) top5 = matches.size();
		if (matches.size() < 1)
		{
			return -1;
		}
		//将匹配到的最小外接矩形装入容器
		vector<cv::RotatedRect> vRects;
		vRects.reserve(10000);
		vRects.clear();
		vector<float> vScores;
		vScores.reserve(10000);
		vScores.clear();
		vector<bool> vDeleteIndexs;
		vDeleteIndexs.reserve(10000);
		vDeleteIndexs.clear();
		for (size_t i = 0; i < top5; i++)
		{
			auto match = matches[i];
			auto templ = detector.getTemplates("test", match.template_id);
			float c_scaled = model.cols / 2.0f * infos[match.template_id].scale;
			float r_scaled = model.rows / 2.0f * infos[match.template_id].scale;
			float train_img_half_width = scale * model.cols / 2.0f;
			float train_img_half_height = scale * model.rows / 2.0f;
			float scale_x = match.x - templ[0].tl_x + train_img_half_width;
			float scale_y = match.y - templ[0].tl_y + train_img_half_height;
			double factor_x = (double)gray_source.cols / (double)source_X.cols;
			double factor_y = (double)gray_source.rows / (double)source_X.rows;
			float x = factor_x * scale_x;
			float y = factor_y * scale_y;
			cv::RotatedRect rotatedRectangle({ x, y }, { 2 * c_scaled, 2 * r_scaled }, -infos[match.template_id].angle);
			vRects.push_back(rotatedRectangle);
			vScores.push_back(match.similarity);
			vDeleteIndexs.push_back(false);
		}
		//剔除重复最小外接矩形
		cv::RotatedRect rect1, rect2;
		for (int i = 0; i < vRects.size() - 1; i++)
		{
			if (vDeleteIndexs[i])
				continue;
			for (int j = i + 1; j < vRects.size(); j++)
			{
				if (vDeleteIndexs[j])
					continue;
				rect1 = vRects[i];
				rect2 = vRects[j];
				vector<cv::Point2f> vecInterSec;
				int iInterSecType = cv::rotatedRectangleIntersection(rect1, rect2, vecInterSec);
				if (iInterSecType == cv::INTERSECT_NONE)  //无交集
					continue;
				else if (iInterSecType == cv::INTERSECT_FULL) //一个矩形包含另一个
				{
					int iDeleteIndex = (vScores[i] <= vScores[j] ? i : j); //匹配分数低的被剔除
					vDeleteIndexs[iDeleteIndex] = true;
				}
				else  //交点 > 0
				{
					if (vecInterSec.size() < 3)
						continue;
					else
					{
						int iDeleteIndex;
						//求面积与交叠比例
						double dArea = cv::contourArea(vecInterSec);
						double dRatio = dArea / rect1.size.area();
						//若大于最大交叠比例，选高分数
						if (dRatio >= 0.3)
						{
							int iDeleteIndex = (vScores[i] <= vScores[j] ? i : j); //匹配分数低的被剔除
							vDeleteIndexs[iDeleteIndex] = true;
						}
					}
				}
			}
		}
		int matchCount = 0;
		//绘制剔除后的匹配结果
		int thick = 0;
		int cross_len = 0;
		if (out_source.cols <= 2000)
		{
			thick = 2;
			cross_len = 8;
		}
		else if (out_source.cols > 2000 && out_source.cols <= 3500)
		{
			thick = 3;
			cross_len = 10;
		}
		else if (out_source.cols > 3500 && out_source.cols <= 5000)
		{
			thick = 5;
			cross_len = 16;
		}
		else if (out_source.cols > 5000)
		{
			thick = 7;
			cross_len = 20;
		}
		if (out_source.channels() == 1)
		{
			cv::cvtColor(out_source, out_source, cv::COLOR_GRAY2BGR);
		}
		else if (out_source.channels() == 4)
		{
			cv::cvtColor(out_source, out_source, cv::COLOR_RGBA2BGR);
		}
		for (size_t i = 0; i < top5; i++)
		{
			if (vDeleteIndexs[i])
				continue;
			if (matchCount == 1)
				break;
			auto match = matches[i];
			auto templ = detector.getTemplates("test", match.template_id);
			float c_scaled = model.cols / 2.0f * infos[match.template_id].scale;
			float r_scaled = model.rows / 2.0f * infos[match.template_id].scale;
			float train_img_half_width = scale * model.cols / 2.0f;
			float train_img_half_height = scale * model.rows / 2.0f;
			float scale_x = match.x - templ[0].tl_x + train_img_half_width;
			float scale_y = match.y - templ[0].tl_y + train_img_half_height;
			double factor_x = (double)gray_source.cols / (double)source_X.cols;
			double factor_y = (double)gray_source.rows / (double)source_X.rows;
			float x = factor_x * scale_x;
			float y = factor_y * scale_y;
			for (int i = 0; i < templ[0].features.size(); i++)
			{
				auto feat = templ[0].features[i];
				cv::circle(out_source, { (int)((feat.x + match.x) * factor_x), (int)((feat.y + match.y) * factor_y) }, gray_source.cols / 300, cv::Scalar(0, 0, 255), -1);
			}
			cv::RotatedRect rotatedRectangle({ x, y }, { 2 * c_scaled, 2 * r_scaled }, -infos[match.template_id].angle);
			angle = infos[match.template_id].angle;
			center = cv::Point2f(x, y);
			cv::Point2f vertices[4];
			rotatedRectangle.points(vertices);
			for (int i = 0; i < 4; i++) {
				int next = (i + 1 == 4) ? 0 : (i + 1);
				cv::line(out_source, vertices[i], vertices[next], cv::Scalar(0, 255, 0), thick);
			}
			cv::Point ptDis1, ptDis2;
			cv::Point ptLT = cv::Point(vertices[1].x, vertices[1].y);
			cv::Point ptLB = cv::Point(vertices[0].x, vertices[0].y);
			cv::Point ptRT = cv::Point(vertices[2].x, vertices[2].y);
			if (model.cols > model.rows)
			{
				ptDis1 = (ptLB - ptLT) / 3;
				ptDis2 = (ptRT - ptLT) / 3 * (model.rows / (float)model.cols);
			}
			else
			{
				ptDis1 = (ptLB - ptLT) / 3 * (model.cols / (float)model.rows);
				ptDis2 = (ptRT - ptLT) / 3;
			}
			cv::line(out_source, ptLT + ptDis1, ptLT + ptDis2, cv::Scalar(230, 10, 10), thick, CV_AA);
			DrawMarkCross(out_source, x, y, cross_len, cv::Scalar(10, 230, 10), thick);
			matchCount++;
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmShapeMatch::MatchTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, const bool use_roi, const MRectangle m_rectangle, vector<cv::Point2f>& center, vector<double>& angle, vector<double>& out_score, const int num_levels, const int angle_start_end, const int num_matches, const double max_overlap, const int num_feature, const double int_score, const bool show_result, const int thickness)
{
	try
	{
		if (source.empty() || model.empty() || (model.size().area() > source.size().area()))
		{
			return -1;
		}
		if ((model.cols < source.cols && model.rows > source.rows) || (model.cols > source.cols && model.rows < source.rows))
		{
			return -1;
		}
		cv::Mat gray_source;
		if (source.channels() == 3)
		{
			cv::cvtColor(source, gray_source, cv::COLOR_BGR2GRAY);
		}
		else if (source.channels() == 4)
		{
			cv::cvtColor(source, gray_source, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			source.copyTo(gray_source);
		}
		float scale = 1.0;
		if (ui.spinPyramid->value() == 1)
		{
			scale = 1.0f;
		}
		else if (ui.spinPyramid->value() == 2)
		{
			scale = 0.5f;
		}
		else if (ui.spinPyramid->value() == 3)
		{
			scale = 0.25f;
		}
		else if (ui.spinPyramid->value() == 4)
		{
			scale = 0.125f;
		}
		else if (ui.spinPyramid->value() == 5)
		{
			scale = 0.0625f;
		}
		else if (ui.spinPyramid->value() == 6)
		{
			scale = 0.03125f;
		}
		cv::Mat source_X = cv::Mat();
		cv::resize(gray_source, source_X, cv::Size(scale * gray_source.cols, scale * gray_source.rows), 0, 0, cv::INTER_AREA);
		cv::Mat padded_img = cv::Mat(source_X.rows, source_X.cols, source_X.type(), cv::Scalar::all(0));
		source_X.copyTo(padded_img(cv::Rect(0, 0, source_X.cols, source_X.rows)));
		int stride = 16;
		int n = padded_img.rows / stride;
		int m = padded_img.cols / stride;
		cv::Rect roi(0, 0, stride * m, stride * n);
		cv::Mat img = padded_img(roi).clone();
		assert(img.isContinuous());
		auto matches = detector.match(img, int_score * 100, ids);
		size_t top5 = num_matches;
		if (top5 > matches.size()) top5 = matches.size();
		if (matches.size() < 1)
		{
			return -1;
		}
		//将匹配到的最小外接矩形装入容器
		vector<cv::RotatedRect> vRects;
		vRects.reserve(10000);
		vRects.clear();
		vector<float> vScores;
		vScores.reserve(10000);
		vScores.clear();
		vector<bool> vDeleteIndexs;
		vDeleteIndexs.reserve(10000);
		vDeleteIndexs.clear();
		for (size_t i = 0; i < top5; i++)
		{
			auto match = matches[i];
			auto templ = detector.getTemplates("test", match.template_id);
			float c_scaled = model.cols / 2.0f * infos[match.template_id].scale;
			float r_scaled = model.rows / 2.0f * infos[match.template_id].scale;
			float train_img_half_width = scale * model.cols / 2.0f;
			float train_img_half_height = scale * model.rows / 2.0f;
			float scale_x = match.x - templ[0].tl_x + train_img_half_width;
			float scale_y = match.y - templ[0].tl_y + train_img_half_height;
			double factor_x = (double)gray_source.cols / (double)source_X.cols;
			double factor_y = (double)gray_source.rows / (double)source_X.rows;
			float x = factor_x * scale_x;
			float y = factor_y * scale_y;
			cv::RotatedRect rotatedRectangle({ x, y }, { 2 * c_scaled, 2 * r_scaled }, -infos[match.template_id].angle);
			vRects.push_back(rotatedRectangle);
			vScores.push_back(match.similarity);
			vDeleteIndexs.push_back(false);
		}
		//剔除重复最小外接矩形
		cv::RotatedRect rect1, rect2;
		for (int i = 0; i < vRects.size() - 1; i++)
		{
			if (vDeleteIndexs[i])
				continue;
			for (int j = i + 1; j < vRects.size(); j++)
			{
				if (vDeleteIndexs[j])
					continue;
				rect1 = vRects[i];
				rect2 = vRects[j];
				vector<cv::Point2f> vecInterSec;
				int iInterSecType = cv::rotatedRectangleIntersection(rect1, rect2, vecInterSec);
				if (iInterSecType == cv::INTERSECT_NONE)  //无交集
					continue;
				else if (iInterSecType == cv::INTERSECT_FULL) //一个矩形包含另一个
				{
					int iDeleteIndex = (vScores[i] <= vScores[j] ? i : j); //匹配分数低的被剔除
					vDeleteIndexs[iDeleteIndex] = true;
				}
				else  //交点 > 0
				{
					if (vecInterSec.size() < 3)
						continue;
					else
					{
						int iDeleteIndex;
						//求面积与交叠比例
						double dArea = cv::contourArea(vecInterSec);
						double dRatio = dArea / rect1.size.area();
						//若大于最大交叠比例，选高分数
						if (dRatio >= max_overlap)
						{
							int iDeleteIndex = (vScores[i] <= vScores[j] ? i : j); //匹配分数低的被剔除
							vDeleteIndexs[iDeleteIndex] = true;
						}
					}
				}
			}
		}
		int matchCount = 0;
		//绘制剔除后的匹配结果
		int thick = 0;
		int cross_len = 0;
		if (out_source.cols <= 2000)
		{
			thick = 2;
			cross_len = 8;
		}
		else if (out_source.cols > 2000 && out_source.cols <= 3500)
		{
			thick = 3;
			cross_len = 10;
		}
		else if (out_source.cols > 3500 && out_source.cols <= 5000)
		{
			thick = 5;
			cross_len = 16;
		}
		else if (out_source.cols > 5000)
		{
			thick = 7;
			cross_len = 20;
		}
		int i_index = -1;
		for (size_t i = 0; i < top5; i++)
		{
			if (vDeleteIndexs[i])
				continue;
			if (matchCount == num_matches)
				break;
			auto match = matches[i];
			auto templ = detector.getTemplates("test", match.template_id);
			float c_scaled = model.cols / 2.0f * infos[match.template_id].scale;
			float r_scaled = model.rows / 2.0f * infos[match.template_id].scale;
			float train_img_half_width = scale * model.cols / 2.0f;
			float train_img_half_height = scale * model.rows / 2.0f;
			float scale_x = match.x - templ[0].tl_x + train_img_half_width;
			float scale_y = match.y - templ[0].tl_y + train_img_half_height;
			double factor_x = (double)gray_source.cols / (double)source_X.cols;
			double factor_y = (double)gray_source.rows / (double)source_X.rows;
			float x = factor_x * scale_x;
			float y = factor_y * scale_y;
			//坐标转换
			if (use_roi == true)
			{
				int x1_buf = (int)(m_rectangle.col + m_rectangle.width * 0.5);
				int y1_buf = (int)(m_rectangle.row + m_rectangle.height * 0.5);
				int x2_buf = (int)(gray_source.cols * 0.5);
				int y2_buf = (int)(gray_source.rows * 0.5);
				++i_index;
				center.push_back(cv::Point2f(x + (x1_buf - x2_buf), y + (y1_buf - y2_buf)));
				angle.push_back(infos[match.template_id].angle);
				out_score.push_back(0.01 * match.similarity);
			}
			else
			{
				++i_index;
				center.push_back(cv::Point2f(x, y));
				angle.push_back(infos[match.template_id].angle);
				out_score.push_back(0.01 * match.similarity);
			}
			if (show_result)
			{
				if (out_source.channels() == 1)
				{
					cv::cvtColor(out_source, out_source, cv::COLOR_GRAY2BGR);
				}
				else if (out_source.channels() == 4)
				{
					cv::cvtColor(out_source, out_source, cv::COLOR_RGBA2BGR);
				}
				cv::RotatedRect rotatedRectangle({ center[i_index].x, center[i_index].y }, { 2 * c_scaled, 2 * r_scaled }, -infos[match.template_id].angle);
				cv::Point2f vertices[4];
				rotatedRectangle.points(vertices);
				for (int n = 0; n < 4; n++)
				{
					int next = (n + 1 == 4) ? 0 : (n + 1);
					cv::line(out_source, vertices[n], vertices[next], cv::Scalar(0, 255, 0), thickness);
				}
				cv::Point ptDis1, ptDis2;
				cv::Point ptLT = cv::Point(vertices[1].x, vertices[1].y);
				cv::Point ptLB = cv::Point(vertices[0].x, vertices[0].y);
				cv::Point ptRT = cv::Point(vertices[2].x, vertices[2].y);
				if (model.cols > model.rows)
				{
					ptDis1 = (ptLB - ptLT) / 3;
					ptDis2 = (ptRT - ptLT) / 3 * (model.rows / (float)model.cols);
				}
				else
				{
					ptDis1 = (ptLB - ptLT) / 3 * (model.cols / (float)model.rows);
					ptDis2 = (ptRT - ptLT) / 3;
				}
				cv::line(out_source, ptLT + ptDis1, ptLT + ptDis2, cv::Scalar(230, 10, 10), thickness, CV_AA);
				DrawMarkCross(out_source, center[i_index].x, center[i_index].y, cross_len, cv::Scalar(10, 230, 10), thick);
			}
			matchCount++;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmShapeMatch::DrawMarkCross(const cv::Mat& matDraw, const int iX, const int iY, const int iLength, const cv::Scalar color, const int iThickness)
{
	if (matDraw.empty())
		return;
	cv::Point ptC(iX, iY);
	cv::line(matDraw, ptC - cv::Point(iLength, 0), ptC + cv::Point(iLength, 0), color, iThickness);
	cv::line(matDraw, ptC - cv::Point(0, iLength), ptC + cv::Point(0, iLength), color, iThickness);
}

//全局变量控制
int QConfig::nFormState = 0;
