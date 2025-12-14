/*  使用并发处理的方法
1. 使用Visual Studio时，在“属性”→“C/C++”→“OpenMP支持”，选择是；
2. 使用Qt Creator时，在“.pro”文件添加“QMAKE_CXXFLAGS+=/openmp”；
*/

#include "frmTemplateMatch.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>
#include <omp.h>
#include <QGraphicsOpacityEffect>
#include <opencv2/imgproc/imgproc_c.h>
#include "qmutex.h"

#define D2R (CV_PI / 180.0)
#define R2D (180.0 / CV_PI)
#define MATCH_CANDIDATE_NUM 1
#define SUBITEM_INDEX 0
#define SUBITEM_SCORE 1
#define SUBITEM_ANGLE 2
#define SUBITEM_POS_X 3
#define SUBITEM_POS_Y 4

bool compareScoreBig2Small(const s_MatchParameter& lhs, const s_MatchParameter& rhs)
{	
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	return  lhs.dMatchScore > rhs.dMatchScore;
}

bool comparePtWithAngle(const pair<cv::Point2f, double> lhs, const pair<cv::Point2f, double> rhs)
{	
	static QMutex mutex2;
	QMutexLocker locker(&mutex2);
	return lhs.second < rhs.second;
}

bool compareMatchResultByPos(const s_SingleTargetMatch& lhs, const s_SingleTargetMatch& rhs)
{	
	static QMutex mutex3;
	QMutexLocker locker(&mutex3);
	double dTol = 2;
	if (fabs(lhs.ptCenter.y - rhs.ptCenter.y) <= dTol)
		return lhs.ptCenter.x < rhs.ptCenter.x;
	else
		return lhs.ptCenter.y < rhs.ptCenter.y;
};

bool compareMatchResultByScore(const s_SingleTargetMatch& lhs, const s_SingleTargetMatch& rhs)
{	
	static QMutex mutex4;
	QMutexLocker locker(&mutex4);
	return lhs.dMatchScore > rhs.dMatchScore;
}

bool compareMatchResultByPosX(const s_SingleTargetMatch& lhs, const s_SingleTargetMatch& rhs)
{	
	static QMutex mutex5;
	QMutexLocker locker(&mutex5);
	return lhs.ptCenter.x < rhs.ptCenter.x;
}

frmTemplateMatch::frmTemplateMatch(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	m_vecSingleTargetData.clear();
	m_TemplData.clear();
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/match.png"));
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	ui.comboViewMode->setCurrentIndex(1);
	ui.comboMode->setCurrentIndex(1);	
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmTemplateMatch::~frmTemplateMatch()
{
	m_vecSingleTargetData.clear();
	m_TemplData.clear();
	view->deleteLater();
	rectangle_item->deleteLater();
	this->deleteLater();
}

void frmTemplateMatch::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/match.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmTemplateMatch::paintEvent(QPaintEvent* event)
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

void frmTemplateMatch::onButtonCloseClicked()
{
	calcDatumCenter = false;
	this->close();
}

int frmTemplateMatch::Execute(const QString toolname)
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
	int result = 0;
	if (calcDatumCenter == false)
	{
		result = RunToolPro();
	}
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmTemplateMatch::RunToolPro()
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
		//模板匹配
		center.clear();
		angle.clear();
		out_score.clear();
		int result = MatchTemplate(dst, model_buf, dstImage, use_roi, m_rectangle, center, angle, out_score, ui.spinPyramid->value(), match_mode, ui.spinRAngle->value(), ui.spinNumMatches->value(), ui.spinMaxOverlap->value(), ui.spinScore->value(), contour_view, ui.spinThickness->value());
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

int frmTemplateMatch::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmTemplateMatch::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmTemplateMatch::InitSetToolData(const QVariant data)
{
	try
	{
		InitTemplateMatchData init_data;
		init_data = data.value<InitTemplateMatchData>();	
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
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmTemplateMatch::InitGetToolData()
{
	InitTemplateMatchData init_data;
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
	return QVariant::fromValue(init_data);
}

void frmTemplateMatch::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);	
	QApplication::processEvents();
	calcDatumCenter = false;
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

void frmTemplateMatch::on_comboMode_currentIndexChanged(int index)
{
	try
	{
		if (ui.comboMode->currentIndex() == 0)
		{
			match_mode = cv::TM_CCORR;
		}
		else if (ui.comboMode->currentIndex() == 1)
		{
			match_mode = cv::TM_CCORR_NORMED;
		}
		else if (ui.comboMode->currentIndex() == 2)
		{
			match_mode = cv::TM_CCOEFF_NORMED;
		}
	}
	catch (std::exception& ex)
	{
		QMessageBox::critical(this, "error", ex.what());
	}
}

void frmTemplateMatch::on_comboViewMode_currentIndexChanged(int index)
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

void frmTemplateMatch::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmTemplateMatch::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmTemplateMatch::on_btnAddROI_2_clicked()
{
	view->ClearObj();
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangle_item->rect_init_state = true;
	view->AddItems(rectangle_item);
}

void frmTemplateMatch::on_btnDeleteROI_2_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

void frmTemplateMatch::on_btnCreateROI_clicked()
{
	if (rectangle_item->rect_init_state == false)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "创建模板失败！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this, tr("保存模板文件"), QDir::currentPath() + "/Parameters/Model/", tr("Config Files (*.xml)"));
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
			//写入匹配基准中心
			calcDatumCenter = true;
			Execute(GetToolName());
			DatumCenter = cv::Point2f(rect.x + 0.5 * rect.width, rect.y + 0.5 * rect.height);
			GetToolBase()->m_Tools[tool_index].PublicTPosition.DatumCenter = DatumCenter;
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "创建模板完成！");
			msgBox.setWindowIcon(QIcon(":/resource/info.png"));
			msgBox.exec();
		}
		catch (...)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "创建模板失败！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
		}
	}
}

void frmTemplateMatch::on_btnDeleteModel_clicked()
{
	ui.txtSaveModel->clear();
	model = cv::Mat();
}

void frmTemplateMatch::on_btnAddROI_clicked()
{
	view->ClearObj();
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangle_item->rect_init_state = true;
	view->AddItems(rectangle_item);
}

void frmTemplateMatch::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

void frmTemplateMatch::on_btnRoiColor_clicked()
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

QImage frmTemplateMatch::Mat2QImage(const cv::Mat& mat)
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
cv::Mat frmTemplateMatch::QImageToMat(const QImage& image)
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
bool frmTemplateMatch::Save_Mat(const string path, const string mat_name, const cv::Mat src_mat)
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
cv::Mat frmTemplateMatch::Load_Mat(const QString path, const string mat_name)
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

int frmTemplateMatch::MatchTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, const bool use_roi, const MRectangle m_rectangle, vector<cv::Point2f>& center, vector<double>& angle, vector<double>& out_score, const int num_levels, const int match_mode, const int angle_start_end, const int num_matches, const double max_overlap, const double int_score, const bool show_result, const int thickness)
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
		cv::Mat gray_source, gray_model;
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
		if (model.channels() == 3)
		{
			cv::cvtColor(model, gray_model, cv::COLOR_BGR2GRAY | cv::COLOR_RGB2GRAY);
		}
		else if (model.channels() == 4)
		{
			cv::cvtColor(model, gray_model, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			model.copyTo(gray_model);
		}
		LearnPattern(gray_model, num_levels);
		vector<cv::Mat> vecMatSrcPyr = vector<cv::Mat>(100);
		vecMatSrcPyr.clear();
		cv::buildPyramid(gray_source, vecMatSrcPyr, num_levels);
		s_TemplData* pTemplData = &m_TemplData;
		double dAngleStep = atan(2.0 / max(pTemplData->vecPyramid[num_levels].cols, pTemplData->vecPyramid[num_levels].rows)) * R2D;
		vector<double> vecAngles = vector<double>(360);
		vecAngles.clear();
		for (double dAngle = 0; dAngle < angle_start_end + dAngleStep; dAngle += dAngleStep)
		{
			vecAngles.push_back(dAngle);
		}
		for (double dAngle = -dAngleStep; dAngle > -angle_start_end - dAngleStep; dAngle -= dAngleStep)
		{
			vecAngles.push_back(dAngle);
		}
		int iTopSrcW = vecMatSrcPyr[num_levels].cols, iTopSrcH = vecMatSrcPyr[num_levels].rows;
		cv::Point2f ptCenter((iTopSrcW - 1) / 2.0f, (iTopSrcH - 1) / 2.0f);
		int iSize = (int)vecAngles.size();
		vector<s_MatchParameter> vecMatchParameter(iSize * (num_matches + MATCH_CANDIDATE_NUM));
		vector<double> vecLayerScore(num_levels + 1, int_score);
		for (int iLayer = 1; iLayer <= num_levels; iLayer++)
			vecLayerScore[iLayer] = vecLayerScore[iLayer - 1] * 0.9;
#pragma omp parallel for  //并发处理
		for (int i = 0; i < iSize; i++)
		{
			cv::Mat matRotatedSrc, matR = cv::getRotationMatrix2D(ptCenter, vecAngles[i], 1);
			cv::Mat matResult;
			cv::Point ptMaxLoc;
			double dValue, dMaxVal;
			cv::Size sizeBest = GetBestRotationSize(vecMatSrcPyr[num_levels].size(), pTemplData->vecPyramid[num_levels].size(), vecAngles[i]);
			float fTranslationX = (sizeBest.width - 1) / 2.0f - ptCenter.x;
			float fTranslationY = (sizeBest.height - 1) / 2.0f - ptCenter.y;
			matR.at<double>(0, 2) += fTranslationX;
			matR.at<double>(1, 2) += fTranslationY;
			cv::warpAffine(vecMatSrcPyr[num_levels], matRotatedSrc, matR, sizeBest);
			Template(matRotatedSrc, pTemplData, matResult, num_levels);
			cv::minMaxLoc(matResult, 0, &dMaxVal, 0, &ptMaxLoc);
			vecMatchParameter[i * (num_matches + MATCH_CANDIDATE_NUM)] = s_MatchParameter(cv::Point2f(ptMaxLoc.x - fTranslationX, ptMaxLoc.y - fTranslationY), dMaxVal, vecAngles[i]);
			for (int j = 0; j < num_matches + MATCH_CANDIDATE_NUM - 1; j++)
			{
				ptMaxLoc = GetNextMaxLoc(matResult, ptMaxLoc, -1, pTemplData->vecPyramid[num_levels].cols, pTemplData->vecPyramid[num_levels].rows, dValue, max_overlap);
				vecMatchParameter[i * (num_matches + MATCH_CANDIDATE_NUM) + j + 1] = s_MatchParameter(cv::Point2f(ptMaxLoc.x - fTranslationX, ptMaxLoc.y - fTranslationY), dValue, vecAngles[i]);
			}
		}
		FilterWithScore(&vecMatchParameter, int_score - 0.05 * num_levels);
		int iMatchSize = (int)vecMatchParameter.size();
		int iDstW = pTemplData->vecPyramid[num_levels].cols, iDstH = pTemplData->vecPyramid[num_levels].rows;
		int iStopLayer = 0;
		vector<s_MatchParameter> vecAllResult = vector<s_MatchParameter>(500000);
		vecAllResult.clear();
#pragma omp parallel for  //并发处理
		for (int i = 0; i < (int)vecMatchParameter.size(); i++)
		{
			double dRAngle = -vecMatchParameter[i].dMatchAngle * D2R;
			cv::Point2f ptLT = ptRotatePt2f(vecMatchParameter[i].pt, ptCenter, dRAngle);
			double dAngleStep = atan(2.0 / max(iDstW, iDstH)) * R2D;
			vecMatchParameter[i].dAngleStart = vecMatchParameter[i].dMatchAngle - dAngleStep;
			vecMatchParameter[i].dAngleEnd = vecMatchParameter[i].dMatchAngle + dAngleStep;
			if (num_levels <= iStopLayer)
			{
				vecMatchParameter[i].pt = cv::Point2d(ptLT * ((num_levels == 0) ? 1 : 2));
				vecAllResult.push_back(vecMatchParameter[i]);
			}
			else
			{
				for (int iLayer = num_levels - 1; iLayer >= iStopLayer; iLayer--)
				{
					dAngleStep = atan(2.0 / max(pTemplData->vecPyramid[iLayer].cols, pTemplData->vecPyramid[iLayer].rows)) * R2D;
					vector<double> vecAngles = vector<double>(1000);
					vecAngles.clear();
					double dMatchedAngle = vecMatchParameter[i].dMatchAngle;
					for (int i = -1; i <= 1; i++)
						vecAngles.push_back(dMatchedAngle + dAngleStep * i);
					cv::Point2f ptSrcCenter((vecMatSrcPyr[iLayer].cols - 1) / 2.0f, (vecMatSrcPyr[iLayer].rows - 1) / 2.0f);
					iSize = (int)vecAngles.size();
					vector<s_MatchParameter> vecNewMatchParameter(iSize);
					int iMaxScoreIndex = 0;
					double dBigValue = -1;
					for (int j = 0; j < iSize; j++)
					{
						cv::Mat matResult, matRotatedSrc;
						double dMaxValue = 0;
						cv::Point ptMaxLoc;
						GetRotatedROI(vecMatSrcPyr[iLayer], pTemplData->vecPyramid[iLayer].size(), ptLT * 2, vecAngles[j], matRotatedSrc);
						Template(matRotatedSrc, pTemplData, matResult, iLayer);
						cv::minMaxLoc(matResult, 0, &dMaxValue, 0, &ptMaxLoc);
						vecNewMatchParameter[j] = s_MatchParameter(ptMaxLoc, dMaxValue, vecAngles[j]);
						if (vecNewMatchParameter[j].dMatchScore > dBigValue)
						{
							iMaxScoreIndex = j;
							dBigValue = vecNewMatchParameter[j].dMatchScore;
						}
						//次像素估计
						if (ptMaxLoc.x == 0 || ptMaxLoc.y == 0 || ptMaxLoc.x == matResult.cols - 1 || ptMaxLoc.y == matResult.rows - 1)
							vecNewMatchParameter[j].bPosOnBorder = true;
						if (!vecNewMatchParameter[j].bPosOnBorder)
						{
							for (int y = -1; y <= 1; y++)
								for (int x = -1; x <= 1; x++)
									vecNewMatchParameter[j].vecResult[x + 1][y + 1] = matResult.at<float>(ptMaxLoc + cv::Point(x, y));
						}
					}
					if (vecNewMatchParameter[iMaxScoreIndex].dMatchScore < vecLayerScore[iLayer])
						break;
					//次像素估计
					if (iLayer == 0
						&& (!vecNewMatchParameter[iMaxScoreIndex].bPosOnBorder)
						&& iMaxScoreIndex != 0
						&& iMaxScoreIndex != 2)
					{
						double dNewX = 0, dNewY = 0, dNewAngle = 0;
						SubPixEsimation(&vecNewMatchParameter, &dNewX, &dNewY, &dNewAngle, dAngleStep, iMaxScoreIndex);
						vecNewMatchParameter[iMaxScoreIndex].pt = cv::Point2d(dNewX, dNewY);
						vecNewMatchParameter[iMaxScoreIndex].dMatchAngle = dNewAngle;
					}
					//次像素估计
					double dNewMatchAngle = vecNewMatchParameter[iMaxScoreIndex].dMatchAngle;
					//坐标系回到旋转时(GetRotatedROI)的(0, 0)
					cv::Point2f ptPaddingLT = ptRotatePt2f(ptLT * 2, ptSrcCenter, dNewMatchAngle * D2R) - cv::Point2f(3, 3);
					cv::Point2f pt(vecNewMatchParameter[iMaxScoreIndex].pt.x + ptPaddingLT.x, vecNewMatchParameter[iMaxScoreIndex].pt.y + ptPaddingLT.y);
					//再旋转
					pt = ptRotatePt2f(pt, ptSrcCenter, -dNewMatchAngle * D2R);
					if (iLayer == iStopLayer)
					{
						vecNewMatchParameter[iMaxScoreIndex].pt = pt * (iStopLayer == 0 ? 1 : 2);
						vecAllResult.push_back(vecNewMatchParameter[iMaxScoreIndex]);
					}
					else
					{
						//更新MatchAngle ptLT
						vecMatchParameter[i].dMatchAngle = dNewMatchAngle;
						vecMatchParameter[i].dAngleStart = vecMatchParameter[i].dMatchAngle - dAngleStep / 2;
						vecMatchParameter[i].dAngleEnd = vecMatchParameter[i].dMatchAngle + dAngleStep / 2;
						ptLT = pt;
					}
				}
			}
		}
		FilterWithScore(&vecAllResult, int_score);
		//最后再次滤掉重叠
		iDstW = pTemplData->vecPyramid[iStopLayer].cols, iDstH = pTemplData->vecPyramid[iStopLayer].rows;
		for (int i = 0; i < (int)vecAllResult.size(); i++)
		{
			cv::Point2f ptLT, ptRT, ptRB, ptLB;
			double dRAngle = -vecAllResult[i].dMatchAngle * D2R;
			ptLT = vecAllResult[i].pt;
			ptRT = cv::Point2f(ptLT.x + iDstW * (float)cos(dRAngle), ptLT.y - iDstW * (float)sin(dRAngle));
			ptLB = cv::Point2f(ptLT.x + iDstH * (float)sin(dRAngle), ptLT.y + iDstH * (float)cos(dRAngle));
			ptRB = cv::Point2f(ptRT.x + iDstH * (float)sin(dRAngle), ptRT.y + iDstH * (float)cos(dRAngle));
			cv::Point2f ptRectCenter = cv::Point2f((ptLT.x + ptRT.x + ptLB.x + ptRB.x) / 4.0f, (ptLT.y + ptRT.y + ptLB.y + ptRB.y) / 4.0f);
			vecAllResult[i].rectR = cv::RotatedRect(ptRectCenter, pTemplData->vecPyramid[iStopLayer].size(), (float)vecAllResult[i].dMatchAngle);
		}
		FilterWithRotatedRect(&vecAllResult, CV_TM_CCOEFF_NORMED, max_overlap);
		//根据分数排序
		std::sort(vecAllResult.begin(), vecAllResult.end(), compareScoreBig2Small);
		m_vecSingleTargetData.clear();
		iMatchSize = (int)vecAllResult.size();
		if (vecAllResult.size() == 0)
			return false;
		int iW = pTemplData->vecPyramid[0].cols, iH = pTemplData->vecPyramid[0].rows;
		for (int i = 0; i < iMatchSize; i++)
		{
			s_SingleTargetMatch sstm;
			double dRAngle = -vecAllResult[i].dMatchAngle * D2R;
			sstm.ptLT = vecAllResult[i].pt;
			sstm.ptRT = cv::Point2d(sstm.ptLT.x + iW * cos(dRAngle), sstm.ptLT.y - iW * sin(dRAngle));
			sstm.ptLB = cv::Point2d(sstm.ptLT.x + iH * sin(dRAngle), sstm.ptLT.y + iH * cos(dRAngle));
			sstm.ptRB = cv::Point2d(sstm.ptRT.x + iH * sin(dRAngle), sstm.ptRT.y + iH * cos(dRAngle));
			sstm.ptCenter = cv::Point2d((sstm.ptLT.x + sstm.ptRT.x + sstm.ptRB.x + sstm.ptLB.x) / 4, (sstm.ptLT.y + sstm.ptRT.y + sstm.ptRB.y + sstm.ptLB.y) / 4);
			sstm.dMatchedAngle = -vecAllResult[i].dMatchAngle;
			sstm.dMatchScore = vecAllResult[i].dMatchScore;
			if (sstm.dMatchedAngle < -180)
				sstm.dMatchedAngle += 360;
			if (sstm.dMatchedAngle > 180)
				sstm.dMatchedAngle -= 360;
			m_vecSingleTargetData.push_back(sstm);
			if (i + 1 == num_matches)
				break;
		}
		center_buf.clear();
		for (int i = 0; i < (int)m_vecSingleTargetData.size(); i++)
		{
			//坐标转换
			if (use_roi == true)
			{
				int x1_buf = (int)(m_rectangle.col + m_rectangle.width * 0.5);
				int y1_buf = (int)(m_rectangle.row + m_rectangle.height * 0.5);
				int x2_buf = (int)(gray_source.cols * 0.5);
				int y2_buf = (int)(gray_source.rows * 0.5);
				m_vecSingleTargetData[i].ptCenter.x = m_vecSingleTargetData[i].ptCenter.x + (x1_buf - x2_buf);
				m_vecSingleTargetData[i].ptCenter.y = m_vecSingleTargetData[i].ptCenter.y + (y1_buf - y2_buf);
				m_vecSingleTargetData[i].ptLT.x = m_vecSingleTargetData[i].ptLT.x + (x1_buf - x2_buf);
				m_vecSingleTargetData[i].ptLT.y = m_vecSingleTargetData[i].ptLT.y + (y1_buf - y2_buf);
				m_vecSingleTargetData[i].ptLB.x = m_vecSingleTargetData[i].ptLB.x + (x1_buf - x2_buf);
				m_vecSingleTargetData[i].ptLB.y = m_vecSingleTargetData[i].ptLB.y + (y1_buf - y2_buf);
				m_vecSingleTargetData[i].ptRB.x = m_vecSingleTargetData[i].ptRB.x + (x1_buf - x2_buf);
				m_vecSingleTargetData[i].ptRB.y = m_vecSingleTargetData[i].ptRB.y + (y1_buf - y2_buf);
				m_vecSingleTargetData[i].ptRT.x = m_vecSingleTargetData[i].ptRT.x + (x1_buf - x2_buf);
				m_vecSingleTargetData[i].ptRT.y = m_vecSingleTargetData[i].ptRT.y + (y1_buf - y2_buf);
				center.push_back(cv::Point2f(m_vecSingleTargetData[i].ptCenter.x, m_vecSingleTargetData[i].ptCenter.y));
				angle.push_back(m_vecSingleTargetData[i].dMatchedAngle);
				out_score.push_back(m_vecSingleTargetData[i].dMatchScore);
			}
			else
			{
				s_SingleTargetMatch sstm = m_vecSingleTargetData[i];
				center.push_back(cv::Point2f(sstm.ptCenter.x, sstm.ptCenter.y));
				angle.push_back(sstm.dMatchedAngle);
				out_score.push_back(sstm.dMatchScore);
			}
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
#pragma omp parallel for  //并发处理
			for (int i = 0; i < (int)m_vecSingleTargetData.size(); i++)
			{
				cv::Point ptLT(m_vecSingleTargetData[i].ptLT * 1.0);
				cv::Point ptLB(m_vecSingleTargetData[i].ptLB * 1.0);
				cv::Point ptRB(m_vecSingleTargetData[i].ptRB * 1.0);
				cv::Point ptRT(m_vecSingleTargetData[i].ptRT * 1.0);
				cv::Point ptC(m_vecSingleTargetData[i].ptCenter * 1.0);
				cv::Point ptDis1, ptDis2;
				if (gray_model.cols > gray_model.rows)
				{
					ptDis1 = (ptLB - ptLT) / 3;
					ptDis2 = (ptRT - ptLT) / 3 * (gray_model.rows / (float)gray_model.cols);
				}
				else
				{
					ptDis1 = (ptLB - ptLT) / 3 * (gray_model.cols / (float)gray_model.rows);
					ptDis2 = (ptRT - ptLT) / 3;
				}
				cv::line(out_source, ptLT, ptRT, cv::Scalar(10, 230, 10), thickness, CV_AA);
				cv::line(out_source, ptLT, ptLB, cv::Scalar(10, 230, 10), thickness, CV_AA);
				cv::line(out_source, ptRT, ptRB, cv::Scalar(10, 230, 10), thickness, CV_AA);
				cv::line(out_source, ptLB, ptRB, cv::Scalar(10, 230, 10), thickness, CV_AA);
				cv::line(out_source, ptLT + ptDis1, ptLT + ptDis2, cv::Scalar(230, 10, 10), 1, CV_AA);
				string str = cv::format("%d", i);
				int font_cross_size = 0;
				int cross_len = 0;
				int font_thickness = 0;
				if (out_source.cols <= 2000)
				{
					font_cross_size = 2;
					cross_len = 8;
					font_thickness = 2;
				}
				else if (out_source.cols > 2000 && out_source.cols <= 3500)
				{
					font_cross_size = 3;
					cross_len = 10;
					font_thickness = 3;
				}
				else if (out_source.cols > 3500 && out_source.cols <= 5000)
				{
					font_cross_size = 5;
					cross_len = 16;
					font_thickness = 5;
				}
				else if (out_source.cols > 5000)
				{
					font_cross_size = 7;
					cross_len = 20;
					font_thickness = 7;
				}
				DrawMarkCross(out_source, ptC.x, ptC.y, cross_len, cv::Scalar(10, 230, 10), font_cross_size);
			}
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmTemplateMatch::LearnPattern(const cv::Mat model, const int num_levels)
{
	m_TemplData.clear();
	cv::buildPyramid(model, m_TemplData.vecPyramid, num_levels);
	s_TemplData* templData = &m_TemplData;
	int iSize = templData->vecPyramid.size();
	templData->resize(iSize);
	for (int i = 0; i < iSize; i++)
	{
		double invArea = 1. / ((double)templData->vecPyramid[i].rows * templData->vecPyramid[i].cols);
		cv::Scalar templMean, templSdv;
		double templNorm = 0, templSum2 = 0;
		cv::meanStdDev(templData->vecPyramid[i], templMean, templSdv);
		templNorm = templSdv[0] * templSdv[0] + templSdv[1] * templSdv[1] + templSdv[2] * templSdv[2] + templSdv[3] * templSdv[3];
		if (templNorm < DBL_EPSILON)
		{
			templData->vecResultEqual1[i] = true;
		}
		templSum2 = templNorm + templMean[0] * templMean[0] + templMean[1] * templMean[1] + templMean[2] * templMean[2] + templMean[3] * templMean[3];
		templSum2 /= invArea;
		templNorm = std::sqrt(templNorm);
		templNorm /= std::sqrt(invArea);
		templData->vecInvArea[i] = invArea;
		templData->vecTemplMean[i] = templMean;
		templData->vecTemplNorm[i] = templNorm;
	}
	templData->bIsPatternLearned = true;
}

cv::Size frmTemplateMatch::GetBestRotationSize(const cv::Size sizeSrc, const cv::Size sizeDst, double dRAngle) const
{
	double dRAngle_radian = dRAngle * D2R;
	cv::Point ptLT(0, 0), ptLB(0, sizeSrc.height - 1), ptRB(sizeSrc.width - 1, sizeSrc.height - 1), ptRT(sizeSrc.width - 1, 0);
	cv::Point2f ptCenter((sizeSrc.width - 1) / 2.0f, (sizeSrc.height - 1) / 2.0f);
	cv::Point2f ptLT_R = ptRotatePt2f(cv::Point2f(ptLT), ptCenter, dRAngle_radian);
	cv::Point2f ptLB_R = ptRotatePt2f(cv::Point2f(ptLB), ptCenter, dRAngle_radian);
	cv::Point2f ptRB_R = ptRotatePt2f(cv::Point2f(ptRB), ptCenter, dRAngle_radian);
	cv::Point2f ptRT_R = ptRotatePt2f(cv::Point2f(ptRT), ptCenter, dRAngle_radian);
	float fTopY = max(max(ptLT_R.y, ptLB_R.y), max(ptRB_R.y, ptRT_R.y));
	float fRightestX = max(max(ptLT_R.x, ptLB_R.x), max(ptRB_R.x, ptRT_R.x));
	if (fabs(fabs(dRAngle) - 90) < 0.0000001 || fabs(fabs(dRAngle) - 270) < 0.0000001)
	{
		return cv::Size(sizeSrc.height, sizeSrc.width);
	}
	else if (fabs(dRAngle) < 0.0000001 || fabs(fabs(dRAngle) - 180) < 0.0000001)
	{
		return sizeSrc;
	}
	if (dRAngle > 360)
		dRAngle -= 360;
	else if (dRAngle < 0)
		dRAngle += 360;
	double dAngle = dRAngle;
	if (dAngle > 0 && dAngle < 90)
	{
	}
	else if (dAngle > 90 && dAngle < 180)
	{
		dAngle -= 90;
	}
	else if (dAngle > 180 && dAngle < 270)
	{
		dAngle -= 180;
	}
	else if (dAngle > 270 && dAngle < 360)
	{
		dAngle -= 270;
	}
	float fH1 = sizeDst.width * sin(dAngle * D2R) * cos(dAngle * D2R);
	float fH2 = sizeDst.height * sin(dAngle * D2R) * cos(dAngle * D2R);
	int iHalfHeight = (int)ceil(fTopY - ptCenter.y - fH1);
	int iHalfWidth = (int)ceil(fRightestX - ptCenter.x - fH2);
	return cv::Size(iHalfWidth * 2, iHalfHeight * 2);
}

cv::Point2f frmTemplateMatch::ptRotatePt2f(const cv::Point2f ptInput, const cv::Point2f ptOrg, const double dAngle) const
{
	double dWidth = ptOrg.x * 2;
	double dHeight = ptOrg.y * 2;
	double dY1 = dHeight - ptInput.y, dY2 = dHeight - ptOrg.y;
	double dX = (ptInput.x - ptOrg.x) * cos(dAngle) - (dY1 - ptOrg.y) * sin(dAngle) + ptOrg.x;
	double dY = (ptInput.x - ptOrg.x) * sin(dAngle) + (dY1 - ptOrg.y) * cos(dAngle) + dY2;
	dY = -dY + dHeight;
	return cv::Point2f((float)dX, (float)dY);
}

cv::Point frmTemplateMatch::GetNextMaxLoc(const cv::Mat& matResult, const cv::Point ptMaxLoc, const double dMinValue, const int iTemplateW, const int iTemplateH, double& dMaxValue, const double dMaxOverlap)
{
	try
	{
		//比对到的区域需考慮重叠比例
		int iStartX = ptMaxLoc.x - iTemplateW * (1 - dMaxOverlap);
		int iStartY = ptMaxLoc.y - iTemplateH * (1 - dMaxOverlap);
		int iEndX = ptMaxLoc.x + iTemplateW * (1 - dMaxOverlap);
		int iEndY = ptMaxLoc.y + iTemplateH * (1 - dMaxOverlap);
		cv::rectangle(matResult, cv::Rect(iStartX, iStartY, 2 * iTemplateW * (1 - dMaxOverlap), 2 * iTemplateH * (1 - dMaxOverlap)), cv::Scalar(dMinValue), CV_FILLED);
		//得到下一个最大值
		cv::Point ptNewMaxLoc;
		cv::minMaxLoc(matResult, 0, &dMaxValue, 0, &ptNewMaxLoc);
		return ptNewMaxLoc;
	}
	catch (...)
	{
		return cv::Point();
	}
}

bool frmTemplateMatch::SubPixEsimation(vector<s_MatchParameter>* vec, double* dNewX, double* dNewY, double* dNewAngle, double dAngleStep, int iMaxScoreIndex) const
{
	cv::Mat matA(27, 10, CV_64F);
	cv::Mat matZ(10, 1, CV_64F);
	cv::Mat matS(27, 1, CV_64F);
	double dX_maxScore = (*vec)[iMaxScoreIndex].pt.x;
	double dY_maxScore = (*vec)[iMaxScoreIndex].pt.y;
	double dTheata_maxScore = (*vec)[iMaxScoreIndex].dMatchAngle;
	int iRow = 0;
	for (int theta = 0; theta <= 2; theta++)
	{
		for (int y = -1; y <= 1; y++)
		{
			for (int x = -1; x <= 1; x++)
			{
				double dX = dX_maxScore + x;
				double dY = dY_maxScore + y;
				double dT = (dTheata_maxScore + (theta - 1) * dAngleStep) * D2R;
				matA.at<double>(iRow, 0) = dX * dX;
				matA.at<double>(iRow, 1) = dY * dY;
				matA.at<double>(iRow, 2) = dT * dT;
				matA.at<double>(iRow, 3) = dX * dY;
				matA.at<double>(iRow, 4) = dX * dT;
				matA.at<double>(iRow, 5) = dY * dT;
				matA.at<double>(iRow, 6) = dX;
				matA.at<double>(iRow, 7) = dY;
				matA.at<double>(iRow, 8) = dT;
				matA.at<double>(iRow, 9) = 1.0;
				matS.at<double>(iRow, 0) = (*vec)[iMaxScoreIndex + (theta - 1)].vecResult[x + 1][y + 1];
				iRow++;
			}
		}
	}
	matZ = (matA.t() * matA).inv() * matA.t() * matS;
	cv::Mat matZ_t;
	cv::transpose(matZ, matZ_t);
	double* dZ = matZ_t.ptr<double>(0);
	cv::Mat matK1 = (cv::Mat_<double>(3, 3) <<
		(2 * dZ[0]), dZ[3], dZ[4],
		dZ[3], (2 * dZ[1]), dZ[5],
		dZ[4], dZ[5], (2 * dZ[2]));
	cv::Mat matK2 = (cv::Mat_<double>(3, 1) << -dZ[6], -dZ[7], -dZ[8]);
	cv::Mat matDelta = matK1.inv() * matK2;
	*dNewX = matDelta.at<double>(0, 0);
	*dNewY = matDelta.at<double>(1, 0);
	*dNewAngle = matDelta.at<double>(2, 0) * R2D;
	return true;
}

inline int frmTemplateMatch::_mm_hsum_epi32(const __m128i V) const
{
	__m128i T = _mm_add_epi32(V, _mm_srli_si128(V, 8));
	T = _mm_add_epi32(T, _mm_srli_si128(T, 4));
	return _mm_cvtsi128_si32(T);
}

inline int frmTemplateMatch::IM_Conv_SIMD(const unsigned char* pCharKernel, const unsigned char* pCharConv, const int iLength) const
{
	const int iBlockSize = 16, Block = iLength / iBlockSize;
	__m128i SumV = _mm_setzero_si128();
	__m128i Zero = _mm_setzero_si128();
	for (int Y = 0; Y < Block * iBlockSize; Y += iBlockSize)
	{
		__m128i SrcK = _mm_loadu_si128((__m128i*)(pCharKernel + Y));
		__m128i SrcC = _mm_loadu_si128((__m128i*)(pCharConv + Y));
		__m128i SrcK_L = _mm_unpacklo_epi8(SrcK, Zero);
		__m128i SrcK_H = _mm_unpackhi_epi8(SrcK, Zero);
		__m128i SrcC_L = _mm_unpacklo_epi8(SrcC, Zero);
		__m128i SrcC_H = _mm_unpackhi_epi8(SrcC, Zero);
		__m128i SumT = _mm_add_epi32(_mm_madd_epi16(SrcK_L, SrcC_L), _mm_madd_epi16(SrcK_H, SrcC_H));
		SumV = _mm_add_epi32(SumV, SumT);
	}
	int Sum = _mm_hsum_epi32(SumV);
	for (int Y = Block * iBlockSize; Y < iLength; Y++)
	{
		Sum += pCharKernel[Y] * pCharConv[Y];
	}
	return Sum;
}

int frmTemplateMatch::Template(cv::Mat& matSrc, s_TemplData* pTemplData, cv::Mat& matResult, const int iLayer) const
{
	try
	{
		//使用SIMD
		matResult.create(matSrc.rows - pTemplData->vecPyramid[iLayer].rows + 1,
			matSrc.cols - pTemplData->vecPyramid[iLayer].cols + 1, CV_32FC1);
		matResult.setTo(0);
		cv::Mat& matTemplate = pTemplData->vecPyramid[iLayer];
		int  t_r_end = matTemplate.rows, t_r = 0;
		for (int r = 0; r < matResult.rows; r++)
		{
			float* r_matResult = matResult.ptr<float>(r);
			uchar* r_source = matSrc.ptr<uchar>(r);
			uchar* r_template, * r_sub_source;
			for (int c = 0; c < matResult.cols; ++c, ++r_matResult, ++r_source)
			{
				r_template = matTemplate.ptr<uchar>();
				r_sub_source = r_source;
				for (t_r = 0; t_r < t_r_end; ++t_r, r_sub_source += matSrc.cols, r_template += matTemplate.cols)
				{
					*r_matResult = *r_matResult + IM_Conv_SIMD(r_template, r_sub_source, matTemplate.cols);
				}
			}
		}
		//cv::matchTemplate(matSrc, pTemplData->vecPyramid[iLayer], matResult, CV_TM_CCORR);  //不使用SIMD时
		CCOEFF_Denominator(matSrc, pTemplData, matResult, iLayer);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmTemplateMatch::CCOEFF_Denominator(cv::Mat& matSrc, s_TemplData* pTemplData, cv::Mat& matResult, const int iLayer) const
{
	if (pTemplData->vecResultEqual1[iLayer])
	{
		matResult = cv::Scalar::all(1);
		return;
	}
	double* q0 = 0, * q1 = 0, * q2 = 0, * q3 = 0;
	cv::Mat sum, sqsum;
	cv::integral(matSrc, sum, sqsum, CV_32F, CV_64F);
	q0 = (double*)sqsum.data;
	q1 = q0 + pTemplData->vecPyramid[iLayer].cols;
	q2 = (double*)(sqsum.data + pTemplData->vecPyramid[iLayer].rows * sqsum.step);
	q3 = q2 + pTemplData->vecPyramid[iLayer].cols;
	float* p0 = (float*)sum.data;
	float* p1 = p0 + pTemplData->vecPyramid[iLayer].cols;
	float* p2 = (float*)(sum.data + pTemplData->vecPyramid[iLayer].rows * sum.step);
	float* p3 = p2 + pTemplData->vecPyramid[iLayer].cols;
	int sumstep = sum.data ? (int)(sum.step / sizeof(float)) : 0;
	int sqstep = sqsum.data ? (int)(sqsum.step / sizeof(double)) : 0;
	double dTemplMean0 = pTemplData->vecTemplMean[iLayer][0];
	double dTemplNorm = pTemplData->vecTemplNorm[iLayer];
	double dInvArea = pTemplData->vecInvArea[iLayer];
	int i, j;
	for (i = 0; i < matResult.rows; i++)
	{
		float* rrow = matResult.ptr<float>(i);
		int idx = i * sumstep;
		int idx2 = i * sqstep;
		for (j = 0; j < matResult.cols; j += 1, idx += 1, idx2 += 1)
		{
			double num = rrow[j], t;
			double wndMean2 = 0, wndSum2 = 0;
			t = p0[idx] - p1[idx] - p2[idx] + p3[idx];
			wndMean2 += t * t;
			num -= t * dTemplMean0;
			wndMean2 *= dInvArea;
			t = q0[idx2] - q1[idx2] - q2[idx2] + q3[idx2];
			wndSum2 += t;
			t = std::sqrt(MAX(wndSum2 - wndMean2, 0)) * dTemplNorm;
			if (fabs(num) < t)
				num /= t;
			else if (fabs(num) < t * 1.125)
				num = num > 0 ? 1 : -1;
			else
				num = 0;
			rrow[j] = (float)num;
		}
	}
}

void frmTemplateMatch::FilterWithScore(vector<s_MatchParameter>* vec, double dScore) const
{
	std::sort(vec->begin(), vec->end(), compareScoreBig2Small);
	int iSize = vec->size(), iIndexDelete = iSize + 1;
	for (int i = 0; i < iSize; i++)
	{
		if ((*vec)[i].dMatchScore < dScore)
		{
			iIndexDelete = i;
			break;
		}
	}
	if (iIndexDelete == iSize + 1)
		return;
	vec->erase(vec->begin() + iIndexDelete, vec->end());
	return;
	//删除小于比对分数的元素
	vector<s_MatchParameter>::iterator it;
	for (it = vec->begin(); it != vec->end();)
	{
		if (((*it).dMatchScore < dScore))
			it = vec->erase(it);
		else
			++it;
	}
}

void frmTemplateMatch::GetRotatedROI(cv::Mat& matSrc, cv::Size size, cv::Point2f ptLT, double dAngle, cv::Mat& matROI) const
{
	double dAngle_radian = dAngle * D2R;
	cv::Point2f ptC((matSrc.cols - 1) / 2.0f, (matSrc.rows - 1) / 2.0f);
	cv::Point2f ptLT_rotate = ptRotatePt2f(ptLT, ptC, dAngle_radian);
	cv::Size sizePadding(size.width + 6, size.height + 6);
	cv::Mat rMat = cv::getRotationMatrix2D(ptC, dAngle, 1);
	rMat.at<double>(0, 2) -= ptLT_rotate.x - 3;
	rMat.at<double>(1, 2) -= ptLT_rotate.y - 3;
	cv::warpAffine(matSrc, matROI, rMat, sizePadding);
}

void frmTemplateMatch::FilterWithRotatedRect(vector<s_MatchParameter>* vec, int iMethod, double dMaxOverLap) const
{
	int iMatchSize = (int)vec->size();
	cv::RotatedRect rect1, rect2;
	for (int i = 0; i < iMatchSize - 1; i++)
	{
		if (vec->at(i).bDelete)
			continue;
		for (int j = i + 1; j < iMatchSize; j++)
		{
			if (vec->at(j).bDelete)
				continue;
			rect1 = vec->at(i).rectR;
			rect2 = vec->at(j).rectR;
			vector<cv::Point2f> vecInterSec;
			int iInterSecType = cv::rotatedRectangleIntersection(rect1, rect2, vecInterSec);
			if (iInterSecType == cv::INTERSECT_NONE)  //无交集
				continue;
			else if (iInterSecType == cv::INTERSECT_FULL) //一个矩形包含另一个
			{
				int iDeleteIndex;
				if (iMethod == CV_TM_SQDIFF)
					iDeleteIndex = (vec->at(i).dMatchScore <= vec->at(j).dMatchScore) ? j : i;
				else
					iDeleteIndex = (vec->at(i).dMatchScore >= vec->at(j).dMatchScore) ? j : i;
				vec->at(iDeleteIndex).bDelete = true;
			}
			else
			{
				if (vecInterSec.size() < 3)
					continue;
				else
				{
					int iDeleteIndex;
					//求面积与交叠比例
					SortPtWithCenter(vecInterSec);
					double dArea = cv::contourArea(vecInterSec);
					double dRatio = dArea / rect1.size.area();
					//若大于最大交叠比例，选高分数
					if (dRatio > dMaxOverLap)
					{
						if (iMethod == CV_TM_SQDIFF)
							iDeleteIndex = (vec->at(i).dMatchScore <= vec->at(j).dMatchScore) ? j : i;
						else
							iDeleteIndex = (vec->at(i).dMatchScore >= vec->at(j).dMatchScore) ? j : i;
						vec->at(iDeleteIndex).bDelete = true;
					}
				}
			}
		}
	}
	vector<s_MatchParameter>::iterator it;
	for (it = vec->begin(); it != vec->end();)
	{
		if ((*it).bDelete)
			it = vec->erase(it);
		else
			++it;
	}
}

void frmTemplateMatch::SortPtWithCenter(vector<cv::Point2f>& vecSort) const
{
	int iSize = (int)vecSort.size();
	cv::Point2f ptCenter;
	for (int i = 0; i < iSize; i++)
		ptCenter += vecSort[i];
	ptCenter /= iSize;
	cv::Point2f vecX(1, 0);
	vector<pair<cv::Point2f, double>> vecPtAngle(iSize);
	for (int i = 0; i < iSize; i++)
	{
		vecPtAngle[i].first = vecSort[i];
		cv::Point2f vec1(vecSort[i].x - ptCenter.x, vecSort[i].y - ptCenter.y);
		float fNormVec1 = vec1.x * vec1.x + vec1.y * vec1.y;
		float fDot = vec1.x;
		if (vec1.y < 0) //若点在中心的上方
		{
			vecPtAngle[i].second = acos(fDot / fNormVec1) * R2D;
		}
		else if (vec1.y > 0) //下方
		{
			vecPtAngle[i].second = 360 - acos(fDot / fNormVec1) * R2D;
		}
		else
		{
			if (vec1.x - ptCenter.x > 0)
				vecPtAngle[i].second = 0;
			else
				vecPtAngle[i].second = 180;
		}

	}
	std::sort(vecPtAngle.begin(), vecPtAngle.end(), comparePtWithAngle);
	for (int i = 0; i < iSize; i++)
		vecSort[i] = vecPtAngle[i].first;
}

void frmTemplateMatch::DrawMarkCross(const cv::Mat& matDraw, const int iX, const int iY, const int iLength, const cv::Scalar color, const int iThickness)
{
	if (matDraw.empty())
		return;
	cv::Point ptC(iX, iY);
	cv::line(matDraw, ptC - cv::Point(iLength, 0), ptC + cv::Point(iLength, 0), color, iThickness);
	cv::line(matDraw, ptC - cv::Point(0, iLength), ptC + cv::Point(0, iLength), color, iThickness);
}

//全局变量控制
int QConfig::nFormState = 0;
