#include "frmImageMorphology.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QMenu>
#include "QGraphicsScenes.h"
#include "BaseItem.h"
#include <opencv2/imgproc/types_c.h>

#define M_PI 3.14159265358979323846
cv::RNG rng(12345);

frmImageMorphology::frmImageMorphology(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/morphology.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//按钮菜单
	form_load();
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(350);
	//设置表格列宽	
	ui.tableWidgetType->setColumnWidth(0, 338);
	//设置表格行间距
	ui.tableWidgetType->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetType->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetType->verticalHeader()->setVisible(false);
	ui.tableWidgetType->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetType->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetType, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
	circle_item = new CircleItem(110, 110, 100);
	polygon_item = new PolygonItem();
}

frmImageMorphology::~frmImageMorphology()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	rectangler_item->deleteLater();
	circle_item->deleteLater();
	polygon_item->deleteLater();
	this->deleteLater();
}

void frmImageMorphology::form_load()
{
	QMenu* menu = new QMenu(this);
	//菜单样式
	QString menuStyle(
		"QMenu::item{"
		"color: rgb(0, 0, 0);"
		"}"
		"QMenu::item:hover{"
		"background-color: rgb(176, 190, 225);"
		"}"
		"QMenu::item:selected{"
		"background-color: rgb(176, 190, 225);"
		"}"
	);
	menu->setStyleSheet(menuStyle);
	auto* grayMenu = menu->addMenu(QIcon(":/resource/gray.png"), "图像操作");  //图像操作
	QAction* grayAc = new QAction("图像灰度化", this);
	connect(grayAc, &QAction::triggered, this, &frmImageMorphology::slot_grayAc);
	grayMenu->addAction(grayAc);
	QAction* channelAc = new QAction("颜色空间变换", this);
	connect(channelAc, &QAction::triggered, this, &frmImageMorphology::slot_channelAc);
	grayMenu->addAction(channelAc);
	QAction* fillUpAc = new QAction("fill_up", this);
	connect(fillUpAc, &QAction::triggered, this, &frmImageMorphology::slot_fillUpAc);
	grayMenu->addAction(fillUpAc);
	QAction* shapeTransAc = new QAction("shape_trans", this);
	connect(shapeTransAc, &QAction::triggered, this, &frmImageMorphology::slot_shapeTransAc);
	grayMenu->addAction(shapeTransAc);
	auto* threMenu = menu->addMenu(QIcon(":/resource/thre.png"), "阈值处理");  //阈值处理
	QAction* thresholdAc = new QAction("固定阈值", this);
	connect(thresholdAc, &QAction::triggered, this, &frmImageMorphology::slot_thresholdAc);
	threMenu->addAction(thresholdAc);
	QAction* iterationAc = new QAction("迭代阈值", this);
	connect(iterationAc, &QAction::triggered, this, &frmImageMorphology::slot_iterationAc);
	threMenu->addAction(iterationAc);
	QAction* entropySegAc = new QAction("最大熵阈值", this);
	connect(entropySegAc, &QAction::triggered, this, &frmImageMorphology::slot_entropySegAc);
	threMenu->addAction(entropySegAc);
	QAction* threshAc = new QAction("threshold", this);
	connect(threshAc, &QAction::triggered, this, &frmImageMorphology::slot_threshAc);
	threMenu->addAction(threshAc);
	QAction* connectionAc = new QAction("connection", this);
	connect(connectionAc, &QAction::triggered, this, &frmImageMorphology::slot_connectionAc);
	threMenu->addAction(connectionAc);
	QAction* adaptiveAc = new QAction("dyn_threshold", this);
	connect(adaptiveAc, &QAction::triggered, this, &frmImageMorphology::slot_adaptiveAc);
	threMenu->addAction(adaptiveAc);
	auto* filterMenu = menu->addMenu(QIcon(":/resource/filter.png"), "图像滤波");  //图像滤波
	QAction* meanAc = new QAction("均值滤波", this);
	connect(meanAc, &QAction::triggered, this, &frmImageMorphology::slot_meanAc);
	filterMenu->addAction(meanAc);
	QAction* medianAc = new QAction("中值滤波", this);
	connect(medianAc, &QAction::triggered, this, &frmImageMorphology::slot_medianAc);
	filterMenu->addAction(medianAc);
	QAction* gaussAc = new QAction("高斯滤波", this);
	connect(gaussAc, &QAction::triggered, this, &frmImageMorphology::slot_gaussAc);
	filterMenu->addAction(gaussAc);
	QAction* bilateralAc = new QAction("双边滤波", this);
	connect(bilateralAc, &QAction::triggered, this, &frmImageMorphology::slot_bilateralAc);
	filterMenu->addAction(bilateralAc);
	QAction* boxAc = new QAction("方框滤波", this);
	connect(boxAc, &QAction::triggered, this, &frmImageMorphology::slot_boxAc);
	filterMenu->addAction(boxAc);
	QAction* sobelAc = new QAction("sobel滤波", this);
	connect(sobelAc, &QAction::triggered, this, &frmImageMorphology::slot_sobelAc);
	filterMenu->addAction(sobelAc);
	QAction* cannyAc = new QAction("canny滤波", this);
	connect(cannyAc, &QAction::triggered, this, &frmImageMorphology::slot_cannyAc);
	filterMenu->addAction(cannyAc);
	QAction* scharrAc = new QAction("scharr滤波", this);
	connect(scharrAc, &QAction::triggered, this, &frmImageMorphology::slot_scharrAc);
	filterMenu->addAction(scharrAc);
	QAction* laplaceAc = new QAction("laplace滤波", this);
	connect(laplaceAc, &QAction::triggered, this, &frmImageMorphology::slot_laplaceAc);
	filterMenu->addAction(laplaceAc);
	auto* morphologyMenu = menu->addMenu(QIcon(":/resource/morph.png"), "形态运算");  //形态运算
	QAction* erodeAc = new QAction("腐蚀", this);
	connect(erodeAc, &QAction::triggered, this, &frmImageMorphology::slot_erodeAc);
	morphologyMenu->addAction(erodeAc);
	QAction* dilateAc = new QAction("膨胀", this);
	connect(dilateAc, &QAction::triggered, this, &frmImageMorphology::slot_dilateAc);
	morphologyMenu->addAction(dilateAc);
	QAction* openAc = new QAction("开运算", this);
	connect(openAc, &QAction::triggered, this, &frmImageMorphology::slot_openAc);
	morphologyMenu->addAction(openAc);
	QAction* closeAc = new QAction("闭运算", this);
	connect(closeAc, &QAction::triggered, this, &frmImageMorphology::slot_closeAc);
	morphologyMenu->addAction(closeAc);
	QAction* tophatAc = new QAction("顶帽", this);
	connect(tophatAc, &QAction::triggered, this, &frmImageMorphology::slot_tophatAc);
	morphologyMenu->addAction(tophatAc);
	QAction* bottomhatAc = new QAction("黑帽", this);
	connect(bottomhatAc, &QAction::triggered, this, &frmImageMorphology::slot_bottomhatAc);
	morphologyMenu->addAction(bottomhatAc);
	QAction* gradientAc = new QAction("梯度", this);
	connect(gradientAc, &QAction::triggered, this, &frmImageMorphology::slot_gradientAc);
	morphologyMenu->addAction(gradientAc);
	QAction* hitmissAc = new QAction("击中/击不中", this);
	connect(hitmissAc, &QAction::triggered, this, &frmImageMorphology::slot_hitmissAc);
	morphologyMenu->addAction(hitmissAc);
	auto* enhanceMenu = menu->addMenu(QIcon(":/resource/enhance.png"), "图像增强");  //图像增强	
	QAction* brightnessAc = new QAction("亮度", this);
	connect(brightnessAc, &QAction::triggered, this, &frmImageMorphology::slot_brightnessAc);
	enhanceMenu->addAction(brightnessAc);
	QAction* sharpenAc = new QAction("锐化", this);
	connect(sharpenAc, &QAction::triggered, this, &frmImageMorphology::slot_sharpenAc);
	enhanceMenu->addAction(sharpenAc);
	QAction* contrastAc = new QAction("对比度", this);
	connect(contrastAc, &QAction::triggered, this, &frmImageMorphology::slot_contrastAc);
	enhanceMenu->addAction(contrastAc);
	QAction* gammaCorrectionAc = new QAction("伽马校正", this);
	connect(gammaCorrectionAc, &QAction::triggered, this, &frmImageMorphology::slot_gammaCorrectionAc);
	enhanceMenu->addAction(gammaCorrectionAc);
	QAction* mulAc = new QAction("图像相乘", this);
	connect(mulAc, &QAction::triggered, this, &frmImageMorphology::slot_mulAc);
	enhanceMenu->addAction(mulAc);
	QAction* unevenLightAc = new QAction("均匀化亮度", this);
	connect(unevenLightAc, &QAction::triggered, this, &frmImageMorphology::slot_unevenLightAc);
	enhanceMenu->addAction(unevenLightAc);
	QAction* emphasizeAc = new QAction("emphasize", this);
	connect(emphasizeAc, &QAction::triggered, this, &frmImageMorphology::slot_emphasizeAc);
	enhanceMenu->addAction(emphasizeAc);
	QAction* histogramAc = new QAction("直方图均衡化", this);
	connect(histogramAc, &QAction::triggered, this, &frmImageMorphology::slot_histogramAc);
	enhanceMenu->addAction(histogramAc);
	QAction* whiteBalanceAc = new QAction("彩色图像白平衡", this);
	connect(whiteBalanceAc, &QAction::triggered, this, &frmImageMorphology::slot_whiteBalanceAc);
	enhanceMenu->addAction(whiteBalanceAc);
	ui.btnMenu->setMenu(menu);
}

void frmImageMorphology::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/morphology.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmImageMorphology::paintEvent(QPaintEvent* event)
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

void frmImageMorphology::onButtonCloseClicked()
{
	if (ui.checkRealTime->isChecked() == true)
	{
		ui.checkRealTime->setChecked(false);
	}
	this->close();
}

void frmImageMorphology::timerEvent()
{
	try
	{
		if (ui.checkRealTime->isChecked() == true)
		{
			Execute(GetToolName());
			QImage img(Mat2QImage(dstImage));
			view->DispImage(img);
			QApplication::processEvents();
		}
	}
	catch (...) {}
}

void frmImageMorphology::slot_grayAc()
{
	ui.lblType->setText("图像灰度化");
}

void frmImageMorphology::slot_channelAc()
{
	ui.lblType->setText("颜色空间变换");
}

void frmImageMorphology::slot_fillUpAc()
{
	ui.lblType->setText("fill_up");
}

void frmImageMorphology::slot_shapeTransAc()
{
	ui.lblType->setText("shape_trans");
}

void frmImageMorphology::slot_thresholdAc()
{
	ui.lblType->setText("固定阈值");
}

void frmImageMorphology::slot_entropySegAc()
{
	ui.lblType->setText("最大熵阈值");
}

void frmImageMorphology::slot_iterationAc()
{
	ui.lblType->setText("迭代阈值");
}

void frmImageMorphology::slot_threshAc()
{
	ui.lblType->setText("threshold");
}

void frmImageMorphology::slot_connectionAc()
{
	ui.lblType->setText("connection");
}

void frmImageMorphology::slot_adaptiveAc()
{
	ui.lblType->setText("dyn_threshold");
}

void frmImageMorphology::slot_meanAc()
{
	ui.lblType->setText("均值滤波");
}

void frmImageMorphology::slot_medianAc()
{
	ui.lblType->setText("中值滤波");
}

void frmImageMorphology::slot_gaussAc()
{
	ui.lblType->setText("高斯滤波");
}

void frmImageMorphology::slot_bilateralAc()
{
	ui.lblType->setText("双边滤波");
}

void frmImageMorphology::slot_boxAc()
{
	ui.lblType->setText("方框滤波");
}

void frmImageMorphology::slot_scharrAc()
{
	ui.lblType->setText("scharr滤波");
}

void frmImageMorphology::slot_cannyAc()
{
	ui.lblType->setText("canny滤波");
}

void frmImageMorphology::slot_laplaceAc()
{
	ui.lblType->setText("laplace滤波");
}

void frmImageMorphology::slot_sobelAc()
{
	ui.lblType->setText("sobel滤波");
}

void frmImageMorphology::slot_erodeAc()
{
	ui.lblType->setText("腐蚀");
}

void frmImageMorphology::slot_dilateAc()
{
	ui.lblType->setText("膨胀");
}

void frmImageMorphology::slot_openAc()
{
	ui.lblType->setText("开运算");
}

void frmImageMorphology::slot_closeAc()
{
	ui.lblType->setText("闭运算");
}

void frmImageMorphology::slot_tophatAc()
{
	ui.lblType->setText("顶帽");
}

void frmImageMorphology::slot_bottomhatAc()
{
	ui.lblType->setText("黑帽");
}

void frmImageMorphology::slot_gradientAc()
{
	ui.lblType->setText("梯度");
}

void frmImageMorphology::slot_hitmissAc()
{
	ui.lblType->setText("击中/击不中");
}

void frmImageMorphology::slot_contrastAc()
{
	ui.lblType->setText("对比度");
}

void frmImageMorphology::slot_brightnessAc()
{
	ui.lblType->setText("亮度");
}

void frmImageMorphology::slot_sharpenAc()
{
	ui.lblType->setText("锐化");
}

void frmImageMorphology::slot_gammaCorrectionAc()
{
	ui.lblType->setText("伽马校正");
}

void frmImageMorphology::slot_histogramAc()
{
	ui.lblType->setText("直方图均衡化");
}

void frmImageMorphology::slot_whiteBalanceAc()
{
	ui.lblType->setText("彩色图像白平衡");
}

void frmImageMorphology::slot_emphasizeAc()
{
	ui.lblType->setText("emphasize");
}

void frmImageMorphology::slot_mulAc()
{
	ui.lblType->setText("图像相乘");
}

void frmImageMorphology::slot_unevenLightAc()
{
	ui.lblType->setText("均匀化亮度");
}

int frmImageMorphology::Execute(const QString toolname)
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

int frmImageMorphology::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
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
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				mask(rect).setTo(255);
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 1)
			{
				if (rectangler_item->rrect_init_state == false)
				{
					return -1;
				}
				rectangler_item->GetRotatedRect(m_rotatedrect);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(m_rotatedrect.col, m_rotatedrect.row), cv::Size2f(m_rotatedrect.lenth1 * 2, m_rotatedrect.lenth2 * 2), -m_rotatedrect.phi * 180 / M_PI);
				cv::Point2f vertices[4];
				rrect.points(vertices);
				cv::Point root_points[1][4];
				root_points[0][0] = cv::Point(vertices[0].x, vertices[0].y);
				root_points[0][1] = cv::Point(vertices[1].x, vertices[1].y);
				root_points[0][2] = cv::Point(vertices[2].x, vertices[2].y);
				root_points[0][3] = cv::Point(vertices[3].x, vertices[3].y);
				const cv::Point* ppt[1] = { root_points[0] };
				int npt[] = { 4 };
				cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 2)
			{
				if (circle_item->circle_init_state == false)
				{
					return -1;
				}
				circle_item->GetCircle(m_circle);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				cv::circle(mask, cv::Point((int)m_circle.col, (int)m_circle.row), (int)m_circle.radius, cv::Scalar(255), -1);
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 3)
			{
				if (polygon_item->polygon_init_state == false)
				{
					return -1;
				}
				polygon_item->GetPolygon(m_polygon);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				int listp_count = m_polygon.list_p.count();
				cv::Point** root_points = new cv::Point * [1];
				root_points[0] = new cv::Point[listp_count];
				for (int i = 0; i < listp_count; i++)
				{
					root_points[0][i] = cv::Point(m_polygon.list_p[i].x(), m_polygon.list_p[i].y());
				}
				const cv::Point* ppt[1] = { root_points[0] };
				int npt[] = { listp_count };
				cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
				delete[] root_points[0];
				root_points[0] = nullptr;
				delete[] root_points;
				root_points = nullptr;
			}
		}
		else
		{
			dst = cv::Mat();
			srcImage.copyTo(dst);
		}
		int table_count = ui.tableWidgetType->rowCount();
		if (table_count == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		QString m_ToolNames;
		bool state = false;
		for (int m = 0; m < table_count; m++)
		{
			m_ToolNames = ui.tableWidgetType->item(m, 0)->text();
			if (m == 0)
			{
				state = Preprocess(m_ToolNames, dst, dstImage);
			}
			else
			{
				state = Preprocess(m_ToolNames, dstImage, dstImage);
			}
			if (state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
		}
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

int frmImageMorphology::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmImageMorphology::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmImageMorphology::InitSetToolData(const QVariant data)
{
	try
	{
		InitImageMorphologyData init_data;
		init_data = data.value<InitImageMorphologyData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			if (init_data.type == "rectangle")
			{
				rectangle_item = new RectangleItem(init_data.x, init_data.y, init_data.width, init_data.height);
				rectangle_item->rect_init_state = true;
				view->AddItems(rectangle_item);
			}
			else if (init_data.type == "rotate_rectangle")
			{
				rectangler_item = new RectangleRItem(init_data.x, init_data.y, init_data.Lenth1 * 2, init_data.Lenth2 * 2, init_data.Pi);
				rectangler_item->rrect_init_state = true;
				view->AddItems(rectangler_item);
			}
			else if (init_data.type == "circle")
			{
				circle_item = new CircleItem(init_data.x, init_data.y, init_data.R);
				circle_item->circle_init_state = true;
				view->AddItems(circle_item);
			}
			else if (init_data.type == "polygon")
			{
				view->scene->startCreate();
				polygon_item = new PolygonItem();
				polygon_item->polygon_init_state = true;
				view->scene->addItem(polygon_item);
				connect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)), Qt::DirectConnection);
				region_buf = 1;
				for (int i = 0; i <= init_data.list_ps.size(); i++)
				{
					if (i == init_data.list_ps.size())
					{
						emit view->scene->updatePoint(init_data.init_points[i - 1], init_data.list_ps[i - 1], true);
					}
					else
					{
						emit view->scene->updatePoint(init_data.init_points[i], init_data.list_ps[i], false);
					}
				}
			}
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmImageMorphology::InitGetToolData()
{
	InitImageMorphologyData init_data;
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
		}
		else if (ui.comboROIShape->currentIndex() == 1)
		{
			if (rectangler_item->rrect_init_state == false)
			{
				return -1;
			}
			rectangler_item->GetRotatedRect(m_rotatedrect);
			init_data.type = "rotate_rectangle";
			init_data.x = m_rotatedrect.col;
			init_data.y = m_rotatedrect.row;
			init_data.Lenth1 = m_rotatedrect.lenth1;
			init_data.Lenth2 = m_rotatedrect.lenth2;
			init_data.Pi = m_rotatedrect.phi;
		}
		else if (ui.comboROIShape->currentIndex() == 2)
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
		}
		else if (ui.comboROIShape->currentIndex() == 3)
		{
			if (polygon_item->polygon_init_state == false)
			{
				return -1;
			}
			polygon_item->GetPolygon(m_polygon);
			init_data.type = "polygon";
			init_data.init_points = m_polygon.points;
			init_data.list_ps = m_polygon.list_ps;
		}
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmImageMorphology::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	if (ui.checkRealTime->isChecked() == false)
	{
		Execute(GetToolName());
		QImage img(Mat2QImage(dstImage));
		view->DispImage(img);		
	}
	ui.btnExecute->setEnabled(true);
}

void frmImageMorphology::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmImageMorphology::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmImageMorphology::on_btnAddType_clicked()
{
	if (ui.lblType->text() == QString())
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "预处理类型不能为空！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	int table_count = ui.tableWidgetType->rowCount();
	for (int m = 0; m < table_count; m++)
	{
		if (ui.lblType->text() == ui.tableWidgetType->item(m, 0)->text())
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "预处理类型不能重复！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
			return;
		}
	}
	int count = ui.tableWidgetType->rowCount();
	ui.tableWidgetType->setRowCount(count + 1);  //设置行数	
	QTableWidgetItem* item_name = new QTableWidgetItem(ui.lblType->text());
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetType->setItem(count, 0, item_name);
}

void frmImageMorphology::on_btnDeleteType_clicked()
{
	int rowIndex = ui.tableWidgetType->currentRow();
	if (rowIndex != -1)
	{
		ui.tableWidgetType->removeRow(rowIndex);
	}
}

void frmImageMorphology::on_btnMoveUp_clicked()
{
	int nRow = ui.tableWidgetType->currentRow();
	moveRow(ui.tableWidgetType, nRow, nRow - 1);
}

void frmImageMorphology::on_btnMoveDown_clicked()
{
	int nRow = ui.tableWidgetType->currentRow();
	moveRow(ui.tableWidgetType, nRow, nRow + 2);
}

void frmImageMorphology::moveRow(QTableWidget* pTable, int nFrom, int nTo) const
{
	if (pTable == NULL) return;
	pTable->setFocus();
	if (nFrom == nTo) return;
	if (nFrom < 0 || nTo < 0) return;
	int nRowCount = pTable->rowCount();
	if (nFrom >= nRowCount || nTo > nRowCount) return;
	if (nTo < nFrom) nFrom++; pTable->insertRow(nTo);
	int nCol = pTable->columnCount();
	for (int i = 0; i < nCol; i++)
	{
		pTable->setItem(nTo, i, pTable->takeItem(nFrom, i));
	}
	if (nFrom < nTo)
	{
		nTo--;
	}
	pTable->removeRow(nFrom); pTable->selectRow(nTo);
}

void frmImageMorphology::on_btnThresholdBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnAdaptiveBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnBlurBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnMedianBlurBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnGaussianBlurBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnBilateralBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnBoxBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnSobelBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnCannyBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnLaplaceBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnErodeBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnDilateBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnOpenBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnCloseBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnTophatBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnBlackhatBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnGradientBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnHitmissBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnLightBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnLaplacianBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnContrastBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnGammaBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnMulBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnEmphasizeBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnUnevenLightBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnFillUpBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnShapeTransBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnThreshBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::on_btnChannelBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageMorphology::slot_DoubleClicked(int row, int column)
{
	QString m_ToolNames_buf = ui.tableWidgetType->item(row, 0)->text();
	//图像操作
	if (m_ToolNames_buf == "颜色空间变换")
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
	else if (m_ToolNames_buf == "fill_up")
	{
		ui.stackedWidget->setCurrentIndex(2);
	}
	else if (m_ToolNames_buf == "shape_trans")
	{
		ui.stackedWidget->setCurrentIndex(3);
	}
	//阈值处理
	else if (m_ToolNames_buf == "固定阈值")
	{
		ui.stackedWidget->setCurrentIndex(4);
	}
	else if (m_ToolNames_buf == "threshold")
	{
		ui.stackedWidget->setCurrentIndex(5);
	}
	else if (m_ToolNames_buf == "dyn_threshold")
	{
		ui.stackedWidget->setCurrentIndex(6);
	}
	//滤波
	else if (m_ToolNames_buf == "均值滤波")
	{
		ui.stackedWidget->setCurrentIndex(7);
	}
	else if (m_ToolNames_buf == "中值滤波")
	{
		ui.stackedWidget->setCurrentIndex(8);
	}
	else if (m_ToolNames_buf == "高斯滤波")
	{
		ui.stackedWidget->setCurrentIndex(9);
	}
	else if (m_ToolNames_buf == "双边滤波")
	{
		ui.stackedWidget->setCurrentIndex(10);
	}
	else if (m_ToolNames_buf == "方框滤波")
	{
		ui.stackedWidget->setCurrentIndex(11);
	}
	else if (m_ToolNames_buf == "sobel滤波")
	{
		ui.stackedWidget->setCurrentIndex(12);
	}
	else if (m_ToolNames_buf == "canny滤波")
	{
		ui.stackedWidget->setCurrentIndex(13);
	}
	else if (m_ToolNames_buf == "laplace滤波")
	{
		ui.stackedWidget->setCurrentIndex(14);
	}
	//形态运算
	else if (m_ToolNames_buf == "腐蚀")
	{
		ui.stackedWidget->setCurrentIndex(15);
	}
	else if (m_ToolNames_buf == "膨胀")
	{
		ui.stackedWidget->setCurrentIndex(16);
	}
	else if (m_ToolNames_buf == "开运算")
	{
		ui.stackedWidget->setCurrentIndex(17);
	}
	else if (m_ToolNames_buf == "闭运算")
	{
		ui.stackedWidget->setCurrentIndex(18);
	}
	else if (m_ToolNames_buf == "顶帽")
	{
		ui.stackedWidget->setCurrentIndex(19);
	}
	else if (m_ToolNames_buf == "黑帽")
	{
		ui.stackedWidget->setCurrentIndex(20);
	}
	else if (m_ToolNames_buf == "梯度")
	{
		ui.stackedWidget->setCurrentIndex(21);
	}
	else if (m_ToolNames_buf == "击中/击不中")
	{
		ui.stackedWidget->setCurrentIndex(22);
	}
	//图像增强
	else if (m_ToolNames_buf == "亮度")
	{
		ui.stackedWidget->setCurrentIndex(23);
	}
	else if (m_ToolNames_buf == "锐化")
	{
		ui.stackedWidget->setCurrentIndex(24);
	}
	else if (m_ToolNames_buf == "对比度")
	{
		ui.stackedWidget->setCurrentIndex(25);
	}
	else if (m_ToolNames_buf == "伽马校正")
	{
		ui.stackedWidget->setCurrentIndex(26);
	}
	else if (m_ToolNames_buf == "图像相乘")
	{
		ui.stackedWidget->setCurrentIndex(27);
	}
	else if (m_ToolNames_buf == "emphasize")
	{
		ui.stackedWidget->setCurrentIndex(28);
	}
	else if (m_ToolNames_buf == "均匀化亮度")
	{
		ui.stackedWidget->setCurrentIndex(29);
	}
}

void frmImageMorphology::on_btnAddROI_clicked()
{
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		rectangle_item = new RectangleItem(10, 10, 200, 200);
		rectangle_item->rect_init_state = true;
		view->AddItems(rectangle_item);
		break;
	case 1:
		rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
		rectangler_item->rrect_init_state = true;
		view->AddItems(rectangler_item);
		break;
	case 2:
		circle_item = new CircleItem(110, 110, 100);
		circle_item->circle_init_state = true;
		view->AddItems(circle_item);
		break;
	case 3:
		if (region_buf == 1)
		{
			disconnect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		}
		view->scene->startCreate();
		polygon_item = new PolygonItem();
		polygon_item->polygon_init_state = true;
		view->scene->addItem(polygon_item);
		connect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		region_buf = 1;
		break;
	}
}

void frmImageMorphology::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	rectangler_item->rrect_init_state = false;
	circle_item->circle_init_state = false;
	polygon_item->polygon_init_state = false;
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 3:
		region_buf = 0;
		disconnect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		break;
	}
}

bool frmImageMorphology::Preprocess(const QString m_ToolNames, cv::Mat src_mat, cv::Mat& dst_mat) const
{
	try
	{
		//图像操作
		if (m_ToolNames == "图像灰度化")
		{
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, dst_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, dst_mat, cv::COLOR_RGBA2GRAY);
			}
			else
			{
				src_mat.copyTo(dst_mat);
			}
		}
		if (m_ToolNames == "颜色空间变换")
		{
			if (src_mat.channels() == 1)
			{
				return false;
			}
			else
			{
				switch (ui.comboChannel->currentIndex()) {
				case(0):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2HSV);
					break;
				case(1):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2HLS);
					break;
				case(2):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2Lab);
					break;
				case(3):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2Luv);
					break;
				case(4):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2XYZ);
					break;
				case(5):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2YUV);
					break;
				case(6):
					cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2YCrCb);
					break;
				}
				//通道分离
				vector<cv::Mat> channels;
				cv::split(src_mat, channels);
				//获得第一通道图像
				cv::Mat channel1 = channels[0];
				//获得第二通道图像
				cv::Mat channel2 = channels[1];
				//获得第三通道图像
				cv::Mat channel3 = channels[2];
				if (ui.radioImage->isChecked() == true)
				{
					src_mat.copyTo(dst_mat);
				}
				else if (ui.radioImageC1->isChecked() == true)
				{
					channel1.copyTo(dst_mat);
				}
				else if (ui.radioImageC2->isChecked() == true)
				{
					channel2.copyTo(dst_mat);
				}
				else if (ui.radioImageC3->isChecked() == true)
				{
					channel3.copyTo(dst_mat);
				}
			}
		}
		else if (m_ToolNames == "fill_up")
		{
			int value = 0;
			switch (ui.comboFillUp->currentIndex()) {
			case(0):
				value = 255;
				break;
			case(1):
				value = 0;
				break;
			}
			dst_mat = cv::Mat(src_mat.size(), CV_8UC1, cv::Scalar(255 - value));
			vector<vector<cv::Point>> contours;
			cv::findContours(src_mat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			cv::drawContours(dst_mat, contours, -1, cv::Scalar(value), cv::FILLED);
		}
		else if (m_ToolNames == "shape_trans")
		{
			QString type;
			switch (ui.comboShapeTrans->currentIndex()) {
			case(0):
				type = "rectangle";
				break;
			case(1):
				type = "circle";
				break;
			case(2):
				type = "conver";
				break;
			}
			int value = 0;
			switch (ui.comboSTColor->currentIndex()) {
			case(0):
				value = 255;
				break;
			case(1):
				value = 0;
				break;
			}
			dst_mat = cv::Mat(src_mat.size(), CV_8UC1, cv::Scalar(255 - value));
			vector<vector<cv::Point>> contours;
			cv::findContours(src_mat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			int n = contours.size();
			for (int i = 0; i < n; i++)
			{
				if (type == "rectangle")
				{
					cv::Rect rect = cv::boundingRect(contours[i]);
					cv::rectangle(dst_mat, rect, cv::Scalar(value), cv::FILLED);
				}
				else if (type == "circle")
				{
					cv::Point2f center;
					float radius;
					cv::minEnclosingCircle(contours[i], center, radius);
					cv::circle(dst_mat, center, radius, cv::Scalar(value), cv::FILLED);
				}
				else if (type == "conver")
				{
					vector<cv::Point> conver;
					cv::convexHull(contours[i], conver);
					vector<vector<cv::Point>> pconver = vector<vector<cv::Point>>(10000);
					pconver.clear();
					pconver.push_back(conver);
					cv::fillPoly(dst_mat, pconver, cv::Scalar(value));
				}
			}
		}
		//阈值处理
		else if (m_ToolNames == "固定阈值")
		{
			int type = 0;
			switch (ui.comboThreshold->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 3;
				break;
			case(3):
				type = 4;
				break;
			case(4):
				type = 2;
				break;
			case(5):
				type = 8;
				break;
			case(6):
				type = 16;
				break;
			}
			cv::threshold(src_mat, dst_mat, ui.spinMinThreshold->value(), ui.spinMaxThreshold->value(), type);
		}
		else if (m_ToolNames == "迭代阈值")
		{
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2GRAY);
			}
			int width = src_mat.cols;
			int height = src_mat.rows;
			int hisData[256] = { 0 };
			for (int j = 0; j < height; j++)
			{
				uchar* data = src_mat.ptr<uchar>(j);
				for (int i = 0; i < width; i++)
				{
					hisData[data[i]]++;
				}
			}
			int T0 = 0;
			for (int i = 0; i < 256; i++)
			{
				T0 += i * hisData[i];
			}
			T0 /= width * height;
			int T1 = 0, T2 = 0;
			int num1 = 0, num2 = 0;
			int T = 0;
			while (1)
			{
				for (int i = 0; i < T0 + 1; i++)
				{
					T1 += i * hisData[i];
					num1 += hisData[i];
				}
				if (num1 == 0)
				{
					continue;
				}
				for (int i = T0 + 1; i < 256; i++)
				{
					T2 += i * hisData[i];
					num2 += hisData[i];
				}
				if (num2 == 0)
				{
					continue;
				}
				T = (T1 / num1 + T2 / num2) / 2;
				if (T == T0)
				{
					break;
				}
				else
				{
					T0 = T;
				}
			}
			cv::threshold(src_mat, dst_mat, T, 255, cv::THRESH_BINARY);
		}
		else if (m_ToolNames == "最大熵阈值")
		{
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2GRAY);
			}
			int tbHist[256] = { 0 };
			int index = 0;
			double Property = 0.0;
			double maxEntropy = -1.0;
			double frontEntropy = 0.0;
			double backEntropy = 0.0;
			int TotalPixel = 0;
			int nCol = src_mat.cols * src_mat.channels();
			for (int i = 0; i < src_mat.rows; i++)
			{
				uchar* pData = src_mat.ptr<uchar>(i);
				for (int j = 0; j < nCol; j++)
				{
					++TotalPixel;
					tbHist[pData[j]] += 1;
				}
			}
			for (int i = 0; i < 256; i++)
			{
				double backTotal = 0;
				for (int j = 0; j < i; j++)
				{
					backTotal += tbHist[j];
				}
				for (int j = 0; j < i; j++)
				{
					if (tbHist[j] != 0)
					{
						Property = tbHist[j] / backTotal;
						backEntropy += -Property * logf((float)Property);
					}
				}
				for (int k = i; k < 256; k++)
				{
					if (tbHist[k] != 0)
					{
						Property = tbHist[k] / (TotalPixel - backTotal);
						frontEntropy += -Property * logf((float)Property);
					}
				}
				if (frontEntropy + backEntropy > maxEntropy)
				{
					maxEntropy = frontEntropy + backEntropy;
					index = i;
				}
				frontEntropy = 0.0;
				backEntropy = 0.0;
			}
			cv::threshold(src_mat, dst_mat, index, 255, cv::THRESH_BINARY);
		}
		else if (m_ToolNames == "threshold")
		{
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2GRAY);
			}
			cv::Mat thresh1;
			cv::Mat thresh2;
			cv::threshold(src_mat, thresh1, ui.spinMinThresh->value(), 255, cv::THRESH_BINARY);
			cv::threshold(src_mat, thresh2, ui.spinMaxThresh->value(), 255, cv::THRESH_BINARY_INV);
			cv::bitwise_and(thresh1, thresh2, dst_mat);
		}
		else if (m_ToolNames == "connection")
		{
			dst_mat = cv::Mat::zeros(src_mat.rows, src_mat.cols, CV_8UC3);
			vector<vector<cv::Point>>contours;
			cv::findContours(src_mat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
			for (int i = 0; i < contours.size(); i++)
			{
				cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
				cv::drawContours(dst_mat, contours, i, color, -1);
			}
		}
		else if (m_ToolNames == "dyn_threshold")
		{
			cv::Mat srcMean;
			int ksize = ui.spinAdaptiveKSize->value();
			int offset = ui.spinAdaptiveOffset->value();
			cv::blur(src_mat, srcMean, cv::Size(ksize, ksize));
			int r = src_mat.rows; //高
			int c = src_mat.cols; //宽
			int value = 0;
			dst_mat = cv::Mat::zeros(src_mat.size(), CV_8UC1);
			for (int i = 0; i < r; i++)
			{
				uchar* dataSrc = src_mat.ptr<uchar>(i); //指针访问图像像素
				uchar* dataSrcMean = srcMean.ptr<uchar>(i);
				uchar* dataResult = dst_mat.ptr<uchar>(i);
				for (int j = 0; j < c; j++)
				{
					switch (ui.comboAdaptiveType->currentIndex())
					{
					case 0:
						value = dataSrc[j] - dataSrcMean[j];
						if (value >= offset)
						{
							dataResult[j] = 255;
						}
						break;
					case 1:
						value = dataSrcMean[j] - dataSrc[j];
						if (value >= offset)
						{
							dataResult[j] = 255;
						}
						break;
					case 2:
						value = dataSrc[j] - dataSrcMean[j];
						if (value >= -offset && value <= offset)
						{
							dataResult[j] = 255;
						}
						break;
					case 3:
						value = dataSrc[j] - dataSrcMean[j];
						if (value < -offset || value > offset)
						{
							dataResult[j] = 255;
						}
						break;
					default:
						break;
					}
				}
			}
		}
		//滤波
		else if (m_ToolNames == "均值滤波")
		{
			int ksize = ui.spinBlurKSize->value();
			cv::blur(src_mat, dst_mat, cv::Size(ksize, ksize), cv::Point(-1, -1));
		}
		else if (m_ToolNames == "中值滤波")
		{
			int ksize = ui.spinMedianBlurKSize->value();
			cv::medianBlur(src_mat, dst_mat, (2 * ksize - 1));
		}
		else if (m_ToolNames == "高斯滤波")
		{
			int ksize = ui.spinGaussianBlurKSize->value();
			cv::GaussianBlur(src_mat, dst_mat, cv::Size((2 * ksize - 1), (2 * ksize - 1)), 0, 0);
		}
		else if (m_ToolNames == "双边滤波")
		{
			int dsize = ui.spinBilateralDSize->value();
			int sigma = ui.spinBilateralSigma->value();
			cv::bilateralFilter(src_mat, dst_mat, dsize, sigma, sigma);
		}
		else if (m_ToolNames == "方框滤波")
		{
			int ksize = ui.spinBoxKSize->value();
			boxFilter(src_mat, dst_mat, CV_8U, cv::Size(ksize, ksize), cv::Point(-1, -1));
		}
		else if (m_ToolNames == "sobel滤波")
		{
			int ksize = ui.spinSobelKSize->value();
			cv::Mat g_sobelGradient_X = cv::Mat();
			cv::Mat g_sobelAbsGradient_X = cv::Mat();
			cv::Mat g_sobelGradient_Y = cv::Mat();
			cv::Mat g_sobelAbsGradient_Y = cv::Mat();
			//求X方向梯度
			cv::Sobel(src_mat, g_sobelGradient_X, CV_16S, 1, 0, (2 * ksize - 1), 1, 0);
			cv::convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X, 1, 0); //计算绝对值，并将结果转换为8位
			//求Y方向梯度
			cv::Sobel(src_mat, g_sobelGradient_Y, CV_16S, 0, 1, (2 * ksize - 1), 1, 0);
			cv::convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y, 1, 0); //计算绝对值，并将结果转换为8位
			//合并梯度
			cv::addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, dst_mat);
		}
		else if (m_ToolNames == "canny滤波")
		{
			int ksize = ui.spinCannyKSize->value();
			cv::Canny(src_mat, dst_mat, ui.spinCannyMinThreshold->value(), ui.spinCannyMaxThreshold->value(), (2 * ksize - 3));
		}
		else if (m_ToolNames == "scharr滤波")
		{
			cv::Mat g_scharrGradient_X = cv::Mat();
			cv::Mat g_scharrAbsGradient_X = cv::Mat();
			cv::Mat g_scharrGradient_Y = cv::Mat();
			cv::Mat g_scharrAbsGradient_Y = cv::Mat();
			//求X方向梯度
			cv::Scharr(src_mat, g_scharrGradient_X, CV_16S, 1, 0);
			cv::convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X, 1, 0); //计算绝对值，并将结果转换为8位
			//求Y方向梯度
			cv::Scharr(src_mat, g_scharrGradient_Y, CV_16S, 0, 1);
			cv::convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y, 1, 0); //计算绝对值，并将结果转换为8位
			//合并梯度
			cv::addWeighted(g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, dst_mat);
		}
		else if (m_ToolNames == "laplace滤波")
		{
			int ksize = ui.spinLaplaceKSize->value();
			//将原图像转换为灰度图像
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2GRAY);
			}
			cv::GaussianBlur(src_mat, src_mat, cv::Size(5, 5), 0, 0);
			cv::Mat g_dstImage = cv::Mat();
			//使用Laplace函数
			cv::Laplacian(src_mat, g_dstImage, CV_16S, (2 * ksize - 1));
			//计算绝对值，并将结果转换为8位
			cv::convertScaleAbs(g_dstImage, dst_mat, 1, 0);
		}
		//形态运算
		else if (m_ToolNames == "腐蚀")
		{
			int type = 0;
			switch (ui.comboErodeType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinErodeSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//腐蚀
			cv::erode(src_mat, dst_mat, structElementKernel, cv::Point(-1, -1), ui.spinErodeIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "膨胀")
		{
			int type = 0;
			switch (ui.comboDilateType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinDilateSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//膨胀
			cv::dilate(src_mat, dst_mat, structElementKernel, cv::Point(-1, -1), ui.spinDilateIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "开运算")
		{
			int type = 0;
			switch (ui.comboOpenType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinOpenSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_OPEN, structElementKernel, cv::Point(-1, -1), ui.spinOpenIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "闭运算")
		{
			int type = 0;
			switch (ui.comboCloseType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinCloseSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_CLOSE, structElementKernel, cv::Point(-1, -1), ui.spinCloseIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "顶帽")
		{
			int type = 0;
			switch (ui.comboTophatType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinTophatSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_TOPHAT, structElementKernel, cv::Point(-1, -1), ui.spinTophatIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "黑帽")
		{
			int type = 0;
			switch (ui.comboBlackhatType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinBlackhatSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_BLACKHAT, structElementKernel, cv::Point(-1, -1), ui.spinBlackhatIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "梯度")
		{
			int type = 0;
			switch (ui.comboGradientType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinGradientSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_GRADIENT, structElementKernel, cv::Point(-1, -1), ui.spinGradientIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		else if (m_ToolNames == "击中/击不中")
		{
			int type = 0;
			switch (ui.comboHitmissType->currentIndex()) {
			case(0):
				type = 0;
				break;
			case(1):
				type = 1;
				break;
			case(2):
				type = 2;
				break;
			}
			int size = ui.spinHitmissSize->value();
			//定义结构元
			cv::Mat structElementKernel = cv::getStructuringElement(type, cv::Size(size, size), cv::Point(-1, -1));
			//形态学变换
			cv::morphologyEx(src_mat, dst_mat, cv::MorphTypes::MORPH_HITMISS, structElementKernel, cv::Point(-1, -1), ui.spinHitmissIterations->value(), cv::BORDER_REFLECT101, cv::Scalar(0, 0, 0));
		}
		//图像增强
		else if (m_ToolNames == "亮度")
		{
			int brightness = ui.spinLightValue->value();
			src_mat.convertTo(dst_mat, CV_8U, 1, brightness);
		}
		else if (m_ToolNames == "锐化")
		{
			int ksize = ui.spinLaplacianKSize->value();
			//拉普拉斯处理
			cv::Laplacian(src_mat, dst_mat, CV_16S, (2 * ksize - 1), 1.0, 0.0);
			cv::Mat abs = cv::Mat();
			//计算绝对值
			cv::convertScaleAbs(dst_mat, abs, 1, 0);
			//加权叠加
			cv::addWeighted(abs, 1, src_mat, 1, 0, dst_mat);
		}
		else if (m_ToolNames == "对比度")
		{
			int contrast = ui.spinContrastValue->value();
			src_mat.convertTo(dst_mat, CV_8U, 1 + contrast / 100.0, 0);
		}
		else if (m_ToolNames == "伽马校正")
		{
			float fGamma = (float)ui.spinGammaValue->value();
			//创建查找表
			unsigned char lut[256];
			for (int i = 0; i < 256; i++) {
				lut[i] = cv::saturate_cast<uchar>(pow((float)(i / 255.0), \
					fGamma) * 255.0f);
			}
			src_mat.copyTo(dst_mat);
			const int channels = dst_mat.channels();
			switch (channels)
			{
			case 1:
				for (int j = 0; j < dst_mat.rows; j++)
				{
					for (int i = 0; i < dst_mat.cols; i++)
					{
						unsigned char val = dst_mat.at<uchar>(j, i);
						dst_mat.at<uchar>(j, i) = lut[val];
					}
				}
				break;
			case 3:
				cv::MatIterator_<cv::Vec3b> it;
				for (it = dst_mat.begin<cv::Vec3b>(); it != dst_mat.end<cv::Vec3b>(); it++)
				{
					(*it)[0] = lut[((*it)[0])];
					(*it)[1] = lut[((*it)[1])];
					(*it)[2] = lut[((*it)[2])];
				}
				break;
			}
		}
		else if (m_ToolNames == "图像相乘")
		{
			double mul_scale = ui.spinMulValue->value();
			dst_mat = src_mat.mul(src_mat, mul_scale);
		}
		else if (m_ToolNames == "emphasize")
		{
			int ksize = ui.spinEmphasizeKSize->value();
			double factor = ui.spinEmphasizeValue->value();
			cv::Mat mean;
			cv::blur(src_mat, mean, cv::Size(ksize, ksize));
			dst_mat.create(src_mat.size(), src_mat.type());
			if (src_mat.type() == CV_8UC1)
			{
				for (int i = 0; i < src_mat.rows; i++)
				{
					const uchar* rptr = src_mat.ptr<uchar>(i);
					uchar* mptr = mean.ptr<uchar>(i);
					uchar* optr = dst_mat.ptr<uchar>(i);
					for (int j = 0; j < src_mat.cols; j++)
					{
						optr[j] = cv::saturate_cast<uchar>(round((rptr[j] - mptr[j]) * factor) + rptr[j] * 1.0f);
					}
				}
			}
			else if (src_mat.type() == CV_8UC3)
			{
				for (int i = 0; i < src_mat.rows; i++)
				{
					const uchar* rptr = src_mat.ptr<uchar>(i);
					uchar* mptr = mean.ptr<uchar>(i);
					uchar* optr = dst_mat.ptr<uchar>(i);
					for (int j = 0; j < src_mat.cols; j++)
					{
						optr[j * 3] = cv::saturate_cast<uchar>(round((rptr[j * 3] - mptr[j * 3]) * factor) + rptr[j * 3] * 1.0f);
						optr[j * 3 + 1] = cv::saturate_cast<uchar>(round((rptr[j * 3 + 1] - mptr[j * 3 + 1]) * factor) + rptr[j * 3 + 1] * 1.0f);
						optr[j * 3 + 2] = cv::saturate_cast<uchar>(round((rptr[j * 3 + 2] - mptr[j * 3 + 2]) * factor) + rptr[j * 3 + 2] * 1.0f);
					}
				}
			}
		}
		else if (m_ToolNames == "直方图均衡化")
		{
			if (src_mat.channels() == 1)
			{
				cv::equalizeHist(src_mat, dst_mat);
			}
			else if (src_mat.channels() == 3)
			{
				cv::Mat matArray[3];
				cv::split(src_mat, matArray);
				//直方图均衡化
				for (int i = 0; i < 3; i++)
				{
					cv::equalizeHist(matArray[i], matArray[i]);
				}
				cv::merge(matArray, 3, dst_mat);
			}
		}
		else if (m_ToolNames == "彩色图像白平衡")
		{
			if (src_mat.channels() == 1)
			{
				dst_mat = cv::Mat();
				return false;
			}
			vector<cv::Mat> imageRGB;
			vector<int> a(2, 0);
			//RGB三通道分离
			cv::split(src_mat, imageRGB);
			a[0] = 1;
			a[1] = 2;
			//求原始图像的RGB分量的均值
			double R, G, B;
			G = cv::mean(imageRGB[1])[0];
			R = cv::mean(imageRGB[2])[0];
			cv::Scalar sca = cv::mean(imageRGB[0]);
			B = sca[0];
			//需要调整的RGB分量的增益
			double KR, KG, KB;
			KB = (R + G + B) / (3 * B);
			KG = (R + G + B) / (3 * G);
			KR = (R + G + B) / (3 * R);
			//调整RGB三个通道各自的值
			imageRGB[0] = imageRGB[0] * KB;
			imageRGB[1] = imageRGB[1] * KG;
			imageRGB[2] = imageRGB[2] * KR;
			//RGB三通道图像合并
			cv::merge(imageRGB, dst_mat);
		}
		else if (m_ToolNames == "均匀化亮度")
		{
			int blockSize = ui.spinUnevenLightSize->value();
			if (src_mat.channels() == 3)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_BGR2GRAY);
			}
			else if (src_mat.channels() == 4)
			{
				cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2GRAY);
			}
			double average = mean(src_mat)[0];
			int rows_new = ceil(double(src_mat.rows) / double(blockSize));
			int cols_new = ceil(double(src_mat.cols) / double(blockSize));
			cv::Mat blockImage;
			blockImage = cv::Mat::zeros(rows_new, cols_new, CV_32FC1);
			for (int i = 0; i < rows_new; i++)
			{
				for (int j = 0; j < cols_new; j++)
				{
					int rowmin = i * blockSize;
					int rowmax = (i + 1) * blockSize;
					if (rowmax > src_mat.rows) rowmax = src_mat.rows;
					int colmin = j * blockSize;
					int colmax = (j + 1) * blockSize;
					if (colmax > src_mat.cols) colmax = src_mat.cols;
					cv::Mat imageROI = src_mat(cv::Range(rowmin, rowmax), cv::Range(colmin, colmax));
					double temaver = cv::mean(imageROI)[0];
					blockImage.at<float>(i, j) = temaver;
				}
			}
			blockImage = blockImage - average;
			cv::Mat blockImage2;
			cv::resize(blockImage, blockImage2, src_mat.size(), (0, 0), (0, 0), cv::INTER_CUBIC);
			cv::Mat image2;
			src_mat.convertTo(image2, CV_32FC1);
			cv::Mat dst_out = image2 - blockImage2;
			dst_mat.create(src_mat.size(), src_mat.type());
			dst_out.convertTo(dst_mat, CV_8UC1);
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

QImage frmImageMorphology::Mat2QImage(const cv::Mat& mat)
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
