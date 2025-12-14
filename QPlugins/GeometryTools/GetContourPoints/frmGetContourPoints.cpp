#include "frmGetContourPoints.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include "ImageItem.h"
#include <QColorDialog>
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmGetContourPoints::frmGetContourPoints(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/border_point.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//初始化标题栏
	initTitleBar();
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	circle_item = new CircleItem(110, 110, 100);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmGetContourPoints::~frmGetContourPoints()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	circle_item->deleteLater();
	this->deleteLater();
}

void frmGetContourPoints::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/border_point.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmGetContourPoints::paintEvent(QPaintEvent* event)
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

void frmGetContourPoints::onButtonCloseClicked()
{
	view_contour = false;
	this->close();
}

int frmGetContourPoints::Execute(const QString toolname)
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

int frmGetContourPoints::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		dstRoiImage = cv::Mat();
		BorderPoints.clear();
		out_Contours.clear();
		xy.clear();
		if (ui.checkUseROI->isChecked() == true)
		{
			if (ui.comboROIShape->currentIndex() == 0)
			{
				if (rectangle_item->rect_init_state == false)
				{
					return -1;
				}
				rectangle_item->GetRect(m_rectangle);
				rect = cv::Rect(m_rectangle.col, m_rectangle.row, m_rectangle.width, m_rectangle.height);
				dst = cv::Mat();
				dst = srcImage(rect);
				xy = GetContourPoints(dst, out_Contours, ui.spinSigma->value(), ui.spinMinThreshold->value(), ui.spinMaxThreshold->value());
				BorderPoints.resize(xy.size());
				int x1_buf = (int)(m_rectangle.col + m_rectangle.width * 0.5);
				int y1_buf = (int)(m_rectangle.row + m_rectangle.height * 0.5);
				int x2_buf = (int)(dst.cols * 0.5);
				int y2_buf = (int)(dst.rows * 0.5);
				for (int i = 0; i < xy.size(); i++)
				{
					BorderPoints[i].x = xy[i].x + (x1_buf - x2_buf);
					BorderPoints[i].y = xy[i].y + (y1_buf - y2_buf);
				}
			}
			else if (ui.comboROIShape->currentIndex() == 1)
			{
				if (circle_item->circle_init_state == false)
				{
					return -1;
				}
				circle_item->GetCircle(m_circle);
				//创建一个包含圆的最小矩形
				rect = cv::Rect((int)(m_circle.col - m_circle.radius), (int)(m_circle.row - m_circle.radius), (int)m_circle.radius * 2, (int)m_circle.radius * 2);
				dst = cv::Mat();
				dst = srcImage(rect);
				xy = GetContourPoints(dst, out_Contours, ui.spinSigma->value(), ui.spinMinThreshold->value(), ui.spinMaxThreshold->value());
				BorderPoints.resize(xy.size());
				int x1 = (int)(m_circle.col);
				int y1 = (int)(m_circle.row);
				int x2 = (int)(dst.cols * 0.5);
				int y2 = (int)(dst.rows * 0.5);
				for (int i = 0; i < xy.size(); i++)
				{
					BorderPoints[i].x = xy[i].x + (x1 - x2);
					BorderPoints[i].y = xy[i].y + (y1 - y2);
				}
			}
		}
		//剔除比例
		int ratio_count = BorderPoints.size();
		int ratio = (int)(BorderPoints.size() * ui.spinCullRatio->value() * 0.01);
		int i_count = 0;
		for (int i = 0; i < ratio_count; i++)
		{
			if (i % 2 == 0)  //偶数
			{
				BorderPoints.erase(BorderPoints.begin() + i_count);
				++i_count;
				if (i_count >= ratio)
				{
					break;
				}
			}
		}
		if (view_contour == true)
		{
			if (dstImage.channels() == 1)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstImage.channels() == 4)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
			}
			for (int n = 0; n < BorderPoints.size(); n++)
			{
				cv::circle(dstImage, cv::Point(BorderPoints[n].x, BorderPoints[n].y), 1, cv::Scalar(211, 0, 141), ui.spinRoiW->value());
			}
		}
		if (ui.checkUseROI->isChecked() == true && ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = dstImage.clone();
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			if (ui.comboROIShape->currentIndex() == 0)
			{
				cv::rectangle(dstRoiImage, rect, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else if (ui.comboROIShape->currentIndex() == 1)
			{
				cv::circle(dstRoiImage, cv::Point((int)m_circle.col, (int)m_circle.row), (int)m_circle.radius, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.BorderPoints = BorderPoints;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmGetContourPoints::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmGetContourPoints::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmGetContourPoints::InitSetToolData(const QVariant data)
{
	try
	{
		InitGetContourPointsData init_data;
		init_data = data.value<InitGetContourPointsData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			if (init_data.type == "rectangle")
			{
				rectangle_item = new RectangleItem(init_data.x, init_data.y, init_data.width, init_data.height);
				rectangle_item->rect_init_state = true;
				view->AddItems(rectangle_item);
			}			
			else if (init_data.type == "circle")
			{
				circle_item = new CircleItem(init_data.x, init_data.y, init_data.R);
				circle_item->circle_init_state = true;
				view->AddItems(circle_item);
			}			
			color = init_data.color;
			//设置按钮背景颜色
			QString style_color = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ")";
			ui.btnRoiColor->setStyleSheet(style_color);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmGetContourPoints::InitGetToolData()
{
	InitGetContourPointsData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (ui.comboROIShape->currentIndex() == 0)
		{
			if (rectangle_item->rect_init_state == false)
			{
				return -1;
			}
			rectangle_item->GetRect(m_rectangle);
			init_data.type = "rectangle";
			init_data.x = m_rectangle.col;
			init_data.y = m_rectangle.row;
			init_data.width = m_rectangle.width;
			init_data.height = m_rectangle.height;
			init_data.color = color;
		}		
		else if (ui.comboROIShape->currentIndex() == 1)
		{
			if (circle_item->circle_init_state == false)
			{
				return -1;
			}
			circle_item->GetCircle(m_circle);
			init_data.type = "circle";
			init_data.x = m_circle.col;
			init_data.y = m_circle.row;
			init_data.R = m_circle.radius;
			init_data.color = color;
		}		
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmGetContourPoints::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_contour = true;
	Execute(GetToolName());
	ui.txtMsg->clear();
	for (int i = 0; i < BorderPoints.size(); i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 边界点集个数为：" + QString::number(BorderPoints.size()));
			ui.txtMsg->append("-> 边界点集如下所示：");
		}
		ui.txtMsg->append(QString::number(BorderPoints[i].x, 'f', 3) + "," + QString::number(BorderPoints[i].y, 'f', 3));
	}
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmGetContourPoints::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmGetContourPoints::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmGetContourPoints::on_btnAddROI_clicked()
{
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		rectangle_item = new RectangleItem(10, 10, 200, 200);
		rectangle_item->rect_init_state = true;
		view->AddItems(rectangle_item);
		break;
	case 1:
		circle_item = new CircleItem(110, 110, 100);
		circle_item->circle_init_state = true;
		view->AddItems(circle_item);
		break;
	}
}

void frmGetContourPoints::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	circle_item->circle_init_state = false;
	view->ClearObj();
}

void frmGetContourPoints::on_btnRoiColor_clicked()
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

#pragma region 获取轮廓边界点
struct Contour
{
	std::vector<cv::Point2f> points;
	std::vector<float> direction;
	std::vector<float> response;
};

const double scale = 128.0;

static void getCannyKernel(const cv::OutputArray _d, const double alpha)
{
	int r = cvRound(alpha * 3);
	int ksize = 2 * r + 1;
	_d.create(ksize, 1, CV_16S, -1, true);
	cv::Mat k = _d.getMat();
	vector<float> kerF(ksize, 0.0f);
	kerF[r] = 0.0f;
	double a2 = alpha * alpha;
	float sum = 0.0f;
	for (int x = 1; x <= r; ++x)
	{
		float v = (float)(-x * std::exp(-x * x / (2 * a2)));
		sum += v;
		kerF[r + x] = v;
		kerF[r - x] = -v;
	}
	float scale = 128 / sum;
	for (int i = 0; i < ksize; ++i)
	{
		kerF[i] *= scale;
	}
	cv::Mat temp(ksize, 1, CV_32F, &kerF[0]);
	temp.convertTo(k, CV_16S);
}

static inline  double getAmplitude(cv::Mat& dx, cv::Mat& dy, int i, int j)
{
	cv::Point2d mag(dx.at<short>(i, j), dy.at<short>(i, j));
	return norm(mag);
}

static inline void getMagNeighbourhood(cv::Mat& dx, cv::Mat& dy, cv::Point& p, int w, int h, vector<double>& mag)
{
	int top = p.y - 1 >= 0 ? p.y - 1 : p.y;
	int down = p.y + 1 < h ? p.y + 1 : p.y;
	int left = p.x - 1 >= 0 ? p.x - 1 : p.x;
	int right = p.x + 1 < w ? p.x + 1 : p.x;
	mag[0] = getAmplitude(dx, dy, top, left);
	mag[1] = getAmplitude(dx, dy, top, p.x);
	mag[2] = getAmplitude(dx, dy, top, right);
	mag[3] = getAmplitude(dx, dy, p.y, left);
	mag[4] = getAmplitude(dx, dy, p.y, p.x);
	mag[5] = getAmplitude(dx, dy, p.y, right);
	mag[6] = getAmplitude(dx, dy, down, left);
	mag[7] = getAmplitude(dx, dy, down, p.x);
	mag[8] = getAmplitude(dx, dy, down, right);
}

static inline void get2ndFacetModelIn3x3(vector<double>& mag, vector<double>& a)
{
	a[0] = (-mag[0] + 2.0 * mag[1] - mag[2] + 2.0 * mag[3] + 5.0 * mag[4] + 2.0 * mag[5] - mag[6] + 2.0 * mag[7] - mag[8]) / 9.0;
	a[1] = (-mag[0] + mag[2] - mag[3] + mag[5] - mag[6] + mag[8]) / 6.0;
	a[2] = (mag[6] + mag[7] + mag[8] - mag[0] - mag[1] - mag[2]) / 6.0;
	a[3] = (mag[0] - 2.0 * mag[1] + mag[2] + mag[3] - 2.0 * mag[4] + mag[5] + mag[6] - 2.0 * mag[7] + mag[8]) / 6.0;
	a[4] = (-mag[0] + mag[2] + mag[6] - mag[8]) / 4.0;
	a[5] = (mag[0] + mag[1] + mag[2] - 2.0 * (mag[3] + mag[4] + mag[5]) + mag[6] + mag[7] + mag[8]) / 6.0;
}

static inline void eigenvals(vector<double>& a, double eigval[2], double eigvec[2][2])
{
	double dfdrc = a[4];
	double dfdcc = a[3] * 2.0;
	double dfdrr = a[5] * 2.0;
	double theta, t, c, s, e1, e2, n1, n2; /* , phi; */
	if (dfdrc != 0.0) {
		theta = 0.5 * (dfdcc - dfdrr) / dfdrc;
		t = 1.0 / (fabs(theta) + sqrt(theta * theta + 1.0));
		if (theta < 0.0) t = -t;
		c = 1.0 / sqrt(t * t + 1.0);
		s = t * c;
		e1 = dfdrr - t * dfdrc;
		e2 = dfdcc + t * dfdrc;
	}
	else {
		c = 1.0;
		s = 0.0;
		e1 = dfdrr;
		e2 = dfdcc;
	}
	n1 = c;
	n2 = -s;
	if (fabs(e1) > fabs(e2)) {
		eigval[0] = e1;
		eigval[1] = e2;
		eigvec[0][0] = n1;
		eigvec[0][1] = n2;
		eigvec[1][0] = -n2;
		eigvec[1][1] = n1;
	}
	else if (fabs(e1) < fabs(e2)) {
		eigval[0] = e2;
		eigval[1] = e1;
		eigvec[0][0] = -n2;
		eigvec[0][1] = n1;
		eigvec[1][0] = n1;
		eigvec[1][1] = n2;
	}
	else {
		if (e1 < e2) {
			eigval[0] = e1;
			eigval[1] = e2;
			eigvec[0][0] = n1;
			eigvec[0][1] = n2;
			eigvec[1][0] = -n2;
			eigvec[1][1] = n1;
		}
		else {
			eigval[0] = e2;
			eigval[1] = e1;
			eigvec[0][0] = -n2;
			eigvec[0][1] = n1;
			eigvec[1][0] = n1;
			eigvec[1][1] = n2;
		}
	}
}

static inline double vector2angle(const double x, const double y)
{
	double a = std::atan2(y, x);
	return a >= 0.0 ? a : a + CV_2PI;
}

void ExtractSubPixPoints(cv::Mat& dx, cv::Mat& dy, vector<vector<cv::Point> >& contoursInPixel, vector<Contour>& contours)
{
	int w = dx.cols;
	int h = dx.rows;
	contours.resize(contoursInPixel.size());
	for (size_t i = 0; i < contoursInPixel.size(); ++i)
	{
		vector<cv::Point>& icontour = contoursInPixel[i];
		Contour& contour = contours[i];
		contour.points.resize(icontour.size());
		contour.response.resize(icontour.size());
		contour.direction.resize(icontour.size());
#if defined(_OPENMP) && defined(NDEBUG)
#pragma omp parallel for
#endif
		for (int j = 0; j < (int)icontour.size(); ++j)
		{
			vector<double> magNeighbour(9);
			getMagNeighbourhood(dx, dy, icontour[j], w, h, magNeighbour);
			vector<double> a(9);
			get2ndFacetModelIn3x3(magNeighbour, a);
			double eigvec[2][2], eigval[2];
			eigenvals(a, eigval, eigvec);
			double t = 0.0;
			double ny = eigvec[0][0];
			double nx = eigvec[0][1];
			if (eigval[0] < 0.0)
			{
				double rx = a[1], ry = a[2], rxy = a[4], rxx = a[3] * 2.0, ryy = a[5] * 2.0;
				t = -(rx * nx + ry * ny) / (rxx * nx * nx + 2.0 * rxy * nx * ny + ryy * ny * ny);
			}
			double px = nx * t;
			double py = ny * t;
			float x = (float)icontour[j].x;
			float y = (float)icontour[j].y;
			if (fabs(px) <= 0.5 && fabs(py) <= 0.5)
			{
				x += (float)px;
				y += (float)py;
			}
			contour.points[j] = cv::Point2f(x, y);
			contour.response[j] = (float)(a[0] / scale);
			contour.direction[j] = (float)vector2angle(ny, nx);
		}
	}
}

//获取轮廓边界点(亚像素)
std::vector<cv::Point2f> frmGetContourPoints::GetContourPoints(cv::Mat& gray_img, vector<vector<cv::Point2f>>& outContours, const double alpha, const int low_thresh, const int high_thresh) const
{
	try
	{
		if (gray_img.channels() == 3)
		{
			cv::cvtColor(gray_img, gray_img, cv::COLOR_BGR2GRAY);
		}
		else if (gray_img.channels() == 4)
		{
			cv::cvtColor(gray_img, gray_img, cv::COLOR_RGBA2GRAY);
		}
		std::vector<Contour> contours;
		cv::Mat blur;
		cv::GaussianBlur(gray_img, blur, cv::Size(0, 0), alpha, alpha);
		cv::Mat d;
		getCannyKernel(d, alpha);
		cv::Mat one = cv::Mat::ones(cv::Size(1, 1), CV_16S);
		cv::Mat dx, dy;
		cv::sepFilter2D(blur, dx, CV_16S, d, one);
		cv::sepFilter2D(blur, dy, CV_16S, one, d);
		cv::Mat edge = cv::Mat::zeros(gray_img.size(), CV_8UC1);
		cv::Canny(gray_img, edge, low_thresh, high_thresh, 3);
		vector<vector<cv::Point> > contoursInPixel;
		vector<cv::Vec4i> hierarchy;
		cv::findContours(edge, contoursInPixel, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
		//选取最大面积轮廓		
		vector<vector<cv::Point>> feature_contours;
		double max_area = 0;
		int index = 0;
		//获取连通区域的个数
		int ksize = contoursInPixel.size();
		//遍历每个连通轮廓
		for (int i = 0; i < ksize; i++)
		{
			//选取最大的面积轮廓
			if (cv::contourArea(contoursInPixel[i]) > max_area)
			{
				max_area = cv::contourArea(contoursInPixel[i]);
				index = i;
			}
		}
		//添加筛选后的连通轮廓
		feature_contours.push_back(contoursInPixel[index]);
		ExtractSubPixPoints(dx, dy, feature_contours, contours);
		for (size_t i = 0; i < contours.size(); ++i)
		{
			cv::Mat pts(contours[i].points);
			vector<cv::Point2f> c;
			pts.convertTo(c, CV_32F);
			outContours.push_back(std::move(c));
		}
		std::vector<cv::Point2f> xy(outContours[0].size());
		for (int i = 0; i < outContours[0].size(); i++)
		{
			xy[i].x = outContours[0][i].x;
			xy[i].y = outContours[0][i].y;
		}
		return xy;
	}
	catch (...)
	{
		return std::vector<cv::Point2f>();
	}
}
#pragma endregion

QImage frmGetContourPoints::Mat2QImage(const cv::Mat& mat)
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
