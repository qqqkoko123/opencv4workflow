#include "frmEdgeWidthMeasure.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>
#include <locate.h>
#include <autoMeasure/service/MeasureA4Service.h>
#include <autoMeasure/service/MeasureCoinService.h>
#include <autoMeasure/service/GrayService.h>
#include <rice.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#define M_PI 3.14159265358979323846

frmEdgeWidthMeasure::frmEdgeWidthMeasure(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/edge.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 0, 255)");
	color = QColor(0, 0, 255);
	caliper_item = new Caliper(10, 160, 200, 160, 300);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmEdgeWidthMeasure::~frmEdgeWidthMeasure()
{
	view->deleteLater();
	caliper_item->deleteLater();
	this->deleteLater();
}

void frmEdgeWidthMeasure::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/edge.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmEdgeWidthMeasure::paintEvent(QPaintEvent* event)
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

void frmEdgeWidthMeasure::onButtonCloseClicked()
{	
	this->close();
}

int frmEdgeWidthMeasure::Execute(const QString toolname)
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
		QString qs = GetToolBase()->m_Tools[i].PublicToolName;
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

// 检查候选圆下方是否可能存在圆柱体（含螺纹）
bool frmEdgeWidthMeasure::hasCylinderAndThread(const cv::Mat& gray, const cv::Mat& edges, const cv::Point& center, int radius, int bodyHeightFactor = 2) {
	// 定义圆柱体区域：圆下方，宽度与圆直径相当，高度为半径的 bodyHeightFactor 倍
	int bodyWidth = radius * 2;
	int bodyHeight = radius * bodyHeightFactor;
	int topY = center.y + radius;               // 圆柱体顶部（圆的下边缘）
	int bottomY = min(gray.rows - 1, topY + bodyHeight);
	int leftX = max(0, center.x - radius);
	int rightX = min(gray.cols - 1, center.x + radius);

	if (topY >= gray.rows || leftX >= rightX) return false;

	// 提取圆柱体区域的边缘
	cv::Mat roiEdges = edges(cv::Rect(leftX, topY, rightX - leftX, bottomY - topY));
	if (roiEdges.empty()) return false;

	// 统计区域内的边缘点数
	int edgeCount = countNonZero(roiEdges);
	float area = roiEdges.total();
	float edgeDensity = edgeCount / area;

	// 如果边缘点密度较低，说明没有明显的螺纹纹理或圆柱体边缘，拒绝
	if (edgeDensity < 0.05) return false;

	// 可选：检查垂直方向的投影，判断是否有周期性（螺纹）
	// 对 roiEdges 进行垂直投影（按列累加）
	vector<int> verticalProj(roiEdges.cols, 0);
	for (int y = 0; y < roiEdges.rows; ++y) {
		for (int x = 0; x < roiEdges.cols; ++x) {
			if (roiEdges.at<uchar>(y, x)) {
				verticalProj[x]++;
			}
		}
	}

	// 检查投影是否存在明显的周期性波动（螺纹）
	// 简单方法：计算投影序列的方差，若方差大则说明有纹理变化
	cv::Scalar mean, stddev;
	meanStdDev(verticalProj, mean, stddev);
	if (stddev[0] < 5.0) return false;  // 变化太小，可能没有螺纹

	// 也可进一步检测波峰数量，但此处简化，认为满足边缘密度和投影波动即可
	return true;
}
// 计算两点间距离
float frmEdgeWidthMeasure::distance(const cv::Point2f& a, const cv::Point2f& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// 计算轮廓的圆形度（0~1，越圆越接近1）
double frmEdgeWidthMeasure::circularity(const vector<cv::Point>& contour) {
	double area = contourArea(contour);
	double perimeter = arcLength(contour, true);
	if (perimeter <= 0) return 0.0;
	return 4 * CV_PI * area / (perimeter * perimeter);
}

// 计算轮廓内像素的灰度标准差（文字区域通常标准差大）
double frmEdgeWidthMeasure::grayStdDev(const cv::Mat& gray, const vector<cv::Point>& contour) {
	cv::Mat mask = cv::Mat::zeros(gray.size(), CV_8U);
	drawContours(mask, vector<vector<cv::Point>>{contour}, 0, cv::Scalar(255), -1);
	cv::Mat roi;
	gray.copyTo(roi, mask);
	cv::Scalar mean, stddev;
	meanStdDev(roi, mean, stddev, mask);
	return stddev[0];
}

// 判断轮廓是否为螺丝钉头部（增强版，加入更多筛选条件）
bool frmEdgeWidthMeasure::isScrewHead(const vector<cv::Point>& contour, const cv::Mat& gray,
	double& radius, cv::Point2f& center, double& circ,
	double minArea, double maxArea,
	double minCircularity, double minEllipseAspect,
	double maxGrayStdDev, double minConvexity) {
	// 1. 面积筛选
	double area = contourArea(contour);
	if (area < minArea || area > maxArea) return false;

	// 2. 轮廓点数足够拟合椭圆
	if (contour.size() < 5) return false;

	// 3. 圆形度（文字通常<0.4，螺丝头部>0.55）
	circ = circularity(contour);
	if (circ < minCircularity) return false;

	// 4. 凸包面积比（排除不规则形状，文字常<0.7）
	vector<cv::Point> hull;
	convexHull(contour, hull);
	double hullArea = contourArea(hull);
	double convexity = area / hullArea;
	if (convexity < minConvexity) return false;
	

	// 5. 外接矩形长宽比 (排除细长物体)
	cv::RotatedRect rect = minAreaRect(contour);
	float width = rect.size.width;
	float height = rect.size.height;
	if (width < height) swap(width, height);
	float aspect = height / width;
	if (aspect < 0.45) return false;
	// 6. 椭圆拟合验证
	cv::RotatedRect ellipseRect = fitEllipse(contour);
	cv::Size2f size = ellipseRect.size;
	float major = max(size.width, size.height);
	float minor = min(size.width, size.height);
	float ellipseAspect = minor / major;  // 椭圆短长轴比
	if (ellipseAspect < minEllipseAspect) return false;

	double ellipseArea = CV_PI * major / 2 * minor / 2;
	double areaRatio = area / ellipseArea;   // 轮廓与椭圆面积比
	if (areaRatio < 0.7) return false;       // 轮廓与椭圆偏差太大

	// 7. 灰度标准差（文字区域通常纹理复杂）
	double stddev = grayStdDev(gray, contour);
	if (stddev > maxGrayStdDev) return false;
	// 8. 中心十字槽灰度方差检测 (放宽阈值，兼容浅十字槽)
	cv::Rect centerRoiRect(
		cvRound(ellipseRect.center.x - minor * 0.25),
		cvRound(ellipseRect.center.y - minor * 0.25),
		cvRound(minor * 0.5),
		cvRound(minor * 0.5)
	);
	centerRoiRect = centerRoiRect & cv::Rect(0, 0, gray.cols, gray.rows);
	if (centerRoiRect.width <= 0 || centerRoiRect.height <= 0) return false;

	cv::Mat centerRoi(gray, centerRoiRect);
	cv::Scalar centerMean, centerStddev;
	meanStdDev(centerRoi, centerMean, centerStddev);
	if (centerStddev[0] < 2.5) return false;  // 从4.0降到2.5，减少漏检
	// 9. 过滤细长杆部 (新增：高度/宽度 > 2.0 判定为杆部)
	float hwRatio = max(height, width) / min(height, width);
	if (hwRatio > 2.0) return false;

	// 10. 扁平度约束 (排除过高轮廓)
	float flatAspect = min(height, width) / max(height, width);
	if (flatAspect > 0.6) return false;  // 从0.5放宽到0.6，兼容真实头部

	// 通过所有筛选
	radius = minor / 2.0;      // 使用短半轴作为半径，确保圆不大
	center = ellipseRect.center;
	return true;
}

// 非极大值抑制（合并重叠检测，解决重复问题）
vector<Screw> frmEdgeWidthMeasure::nmsScrews(const vector<Screw>& screws, float overlapThresh = 0.6f) {
	if (screws.empty()) return {};
	vector<Screw> sorted = screws;
	sort(sorted.begin(), sorted.end(),
		[](const Screw& a, const Screw& b) { return a.radius > b.radius; });
	vector<bool> keep(sorted.size(), true);
	for (size_t i = 0; i < sorted.size(); ++i) {
		if (!keep[i]) continue;
		for (size_t j = i + 1; j < sorted.size(); ++j) {
			if (!keep[j]) continue;
			float dist = norm(sorted[i].center - sorted[j].center);
			float r1 = sorted[i].radius, r2 = sorted[j].radius;
			if (dist < (r1 + r2) * overlapThresh) {
				keep[j] = false; // 保留半径大的
			}
			float minDist = max(r1, r2) * 1.2f;
			if (dist < minDist) keep[j] = false;
		}
	}
	vector<Screw> result;
	for (size_t i = 0; i < sorted.size(); ++i) {
		if (keep[i]) result.push_back(sorted[i]);
	}
	return result;
}
// 聚类合并重复检测的圆（核心解决重复标记）
vector<cv::Vec3f> frmEdgeWidthMeasure::clusterCircles(const vector<cv::Vec3f>& circles, float clusterRadius = 15.0f) {
	if (circles.empty()) return {};
	vector<bool> processed(circles.size(), false);
	vector<cv::Vec3f> result;

	for (size_t i = 0; i < circles.size(); ++i) {
		if (processed[i]) continue;

		// 收集同一聚类的所有圆
		vector<cv::Vec3f> cluster;
		cluster.push_back(circles[i]);
		processed[i] = true;

		for (size_t j = i + 1; j < circles.size(); ++j) {
			if (processed[j]) continue;
			float dx = circles[i][0] - circles[j][0];
			float dy = circles[i][1] - circles[j][1];
			float dist = sqrt(dx * dx + dy * dy);
			if (dist < clusterRadius) {
				cluster.push_back(circles[j]);
				processed[j] = true;
			}
		}

		// 计算聚类中心（取平均值）
		float cx = 0, cy = 0, r = 0;
		for (const auto& c : cluster) {
			cx += c[0];
			cy += c[1];
			r += c[2];
		}
		cx /= cluster.size();
		cy /= cluster.size();
		r /= cluster.size();
		result.push_back(cv::Vec3f(cx, cy, r));
	}
	return result;
}

// 过滤非螺丝头部（基于尺寸+位置+形状）
vector<cv::Vec3f> frmEdgeWidthMeasure::filterScrewHeads(const vector<cv::Vec3f>& circles, const cv::Mat& img) {
	vector<cv::Vec3f> valid;
	int topSkip = 220;  // 顶部文字区
	float minRadius = 3.0f;   // 最小头部半径
	float maxRadius = 12.0f;  // 最大头部半径

	for (const auto& c : circles) {
		float x = c[0], y = c[1], r = c[2];

		// 1. 过滤顶部文字区
		if (y < topSkip) continue;

		// 2. 过滤图像边缘
		if (x < r + 20 || x > img.cols - r - 20 || y < r + 20 || y > img.rows - r - 20) continue;

		// 3. 过滤尺寸异常（非头部）
		if (r < minRadius || r > maxRadius) continue;

		// 4. 验证头部灰度特征（十字槽）
		cv::Rect roiRect(cvRound(x - r * 0.5), cvRound(y - r * 0.5), cvRound(r), cvRound(r));
		roiRect = roiRect & cv::Rect(0, 0, img.cols, img.rows);
		cv::Mat roi(img, roiRect);
		cv::Scalar mean, stddev;
		meanStdDev(roi, mean, stddev);
		if (stddev[0] < 3.0) continue;  // 无十字槽纹理的排除

		valid.push_back(c);
	}
	return valid;
}

int frmEdgeWidthMeasure::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		k = 0;
		b = 0;
		Distance = 0;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
		srcImage.copyTo(dstImage);
		// 米粒计数
		if (ui.isActureDistance_5->isChecked()) {
			std::vector<int> result = on_btnStart(dstImage, 0.5, true, dstImage);
			//emit dataVar::fProItemTab->sig_InfoClick();
			//emit dataVar::fProItemTab->sig_Log("米粒总数：" + QString::number(result[0]) + " 优良米粒总数：" + QString::number(result[1]) + " 缺陷米粒总数：" + QString::number(result[2]));
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "信息", "米粒总数：" + QString::number(result[0])+" 优良米粒总数："+ QString::number(result[1])+" 缺陷米粒总数："+ QString::number(result[2]));
			msgBox.setWindowIcon(QIcon(":/resource/info.png"));
			msgBox.exec();
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			//GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
			//GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			return 0;
		}
		//螺丝钉计数
		if (ui.isActureDistance_7->isChecked())
		{
			/*Mat src = imread(argv[1]);
			if (src.empty()) {
				cout << "无法加载图像: " << argv[1] << endl;
				return -1;
			}*/

			// 缩放图像（若太大则缩小，加快处理）
			cv::Mat img;
			double scale = 1.0;
			const int maxWidth = 1200;
			if (dstImage.cols > maxWidth) {
				scale = (double)maxWidth / dstImage.cols;
				cv::resize(dstImage, img, cv::Size(), scale, scale);
			}
			else {
				img = dstImage.clone();
			}

			cv::Mat gray;
			cvtColor(img, gray, cv::COLOR_BGR2GRAY);

			// 增强对比度（CLAHE）
			cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.0, cv::Size(8, 8));
			cv::Mat enhanced;
			clahe->apply(gray, enhanced);

			// 高斯滤波
			cv::Mat blurred;
			GaussianBlur(enhanced, blurred, cv::Size(5, 5), 1.5);

			// 自适应阈值二值化
			cv::Mat binary;
			adaptiveThreshold(blurred, binary, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 11, 2);

			// 形态学操作优化 (保留小螺丝头部，同时抑制杆部噪点)
			cv::Mat kernel_close = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));
			cv::Mat kernel_open = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));  // 缩小开运算核
			morphologyEx(binary, binary, cv::MORPH_CLOSE, kernel_close);
			morphologyEx(binary, binary, cv::MORPH_OPEN, kernel_open);
			// Canny边缘检测强化头部轮廓
			cv::Mat edges;
			Canny(blurred, edges, 50, 150);
			binary = edges & binary;
			// ------------------- 可选：颜色辅助（金属高亮区域） -------------------
			// 将图像转换到 HSV 空间，提取高亮度区域（金属通常反射强）
			cv::Mat hsv;
			cvtColor(img, hsv, cv::COLOR_BGR2HSV);
			cv::Mat maskMetal;
			// 提取亮度 V 通道 > 200 的区域（可根据实际光照调整）
			vector<cv::Mat> channels;
			split(hsv, channels);
			cv::Mat V = channels[2];
			threshold(V, maskMetal, 200, 255, cv::THRESH_BINARY);
			// 与二值图取交集，只保留高亮区域
			cv::Mat binaryFiltered;
			bitwise_and(binary, maskMetal, binaryFiltered);

			// 也可以使用原二值图（如果金属亮度不明显，可注释上面代码，改用 binary）
			// 这里使用过滤后的二值图
			cv::Mat finalBinary = binaryFiltered.empty() ? binary : binaryFiltered;
			// 查找轮廓
			vector<vector<cv::Point>> contours;
			findContours(finalBinary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			// ==================== 可调参数（根据实际图片修改） ====================
			double minArea = 60.0;           // 最小面积（像素）
			double maxArea = 500.0;          // 最大面积（像素）—— 严格控制，避免包含身体
			double minCircularity = 0.72;    // 圆形度阈值（螺丝头部>0.7，数字<0.5）
			double minEllipseAspect = 0.68;  // 椭圆短长轴比（圆形>0.65）
			double maxGrayStdDev = 14.0;     // 灰度标准差上限（文字区域>30）
			double minConvexity = 0.93;      // 凸包面积比（螺丝头部>0.95，文字<0.85）
			int borderMargin = 50;           // 剔除靠近边界的检测（像素）
			int topSkip = 220;  // 新增：顶部文字区跳过
			float nmsMinDistRatio = 1.15f;     // NMS 重叠阈值（更积极合并）
			// ===========================================================

			//// 手动排除顶部和底部固定文字区域（根据图片中文字位置设置）
			//int topExclude = (int)(img.rows * 0.25);      // 顶部排除比例
			//int bottomExclude = (int)(img.rows * 0.10);   // 底部排除比例

			vector<Screw> screws;
			for (const auto& c : contours) {
				double radius, circ;
				cv::Point2f center;
				if (isScrewHead(c, gray, radius, center, circ,
					minArea, maxArea, minCircularity, minEllipseAspect,
					maxGrayStdDev, minConvexity)) {
					// 剔除靠近边界的检测（解决顶部文字误检）
					if (center.x < borderMargin || center.x > img.cols - borderMargin ||
						center.y < borderMargin || center.y > img.rows - borderMargin) {
						continue;
					}
					// 强化边界过滤：跳过顶部文字区
					if (center.y < topSkip ||
						center.x < borderMargin || center.x > img.cols - borderMargin ||
						center.y > img.rows - borderMargin) {
						continue;
					}
					screws.push_back({ center, (float)radius, 0, circ });
				}
			}

			// 霍夫圆检测作为补充（但需严格限制半径范围，避免误检）
			vector<cv::Vec3f> circles;
			int minRadius = (int)sqrt(minArea / CV_PI);
			int maxRadius = (int)sqrt(maxArea / CV_PI);
			HoughCircles(enhanced, circles, cv::HOUGH_GRADIENT, 1.5, 20, 100, 30, minRadius, maxRadius);
			for (const auto& c : circles) {
				cv::Point2f center(c[0], c[1]);
				float radius = c[2];
				// 简单过滤：若中心靠近边界则跳过
				if (center.x < borderMargin || center.x > img.cols - borderMargin ||
					center.y < borderMargin || center.y > img.rows - borderMargin) {
					continue;
				}
				screws.push_back({ center, radius, 0, 0.0 });
			}

			// 合并去重（NMS）
			// NMS 合并重复检测
			vector<Screw> finalScrews = nmsScrews(screws, nmsMinDistRatio);
			for (size_t i = 0; i < finalScrews.size(); ++i) {
				finalScrews[i].id = i + 1;
			}

			// 绘制结果
			//cv::Mat result = img.clone();
			dstImage = img.clone();
			for (const auto& s : finalScrews) {
				// 绘制头部圆圈（绿色）
				circle(dstImage, s.center, cvRound(s.radius), cv::Scalar(0, 255, 0), 2);
				// 绘制中心点（红色）
				circle(dstImage, s.center, 3, cv::Scalar(0, 0, 255), -1);
				// 标号位置（圆上方）
				string text = to_string(s.id);
				cv::Point textPos(s.center.x - 10, s.center.y - s.radius - 5);
				if (textPos.y < 0) textPos.y = s.center.y + s.radius + 15;
				putText(dstImage, text, textPos, cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 0, 0), 1);
			}
			//// 预处理：灰度+降噪+增强
			//cv::Mat gray, blurred, enhanced;
			//cvtColor(img, gray, cv::COLOR_BGR2GRAY);
			//GaussianBlur(gray, blurred, cv::Size(9,9), 2, 2);
   // 
			//// CLAHE增强对比度（突出头部十字槽）
			//cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.0, cv::Size(8,8));
			//clahe->apply(blurred, enhanced);

			//// 霍夫圆检测（专门定位圆形头部，核心修复！）
			//vector<cv::Vec3f> circles;
			//cv::HoughCircles(
			//	enhanced, circles, cv::HOUGH_GRADIENT,
			//	1,              // 累加器分辨率
			//	15,             // 圆心最小距离（关键：避免重复检测）
			//	100,            // Canny高阈值
			//	30,             // 累加器阈值（越高越严格）
			//	3,              // 最小半径
			//	12              // 最大半径
			//);
			//// 第一步过滤：只保留头部特征
			//vector<cv::Vec3f> filtered = filterScrewHeads(circles, gray);

			//// 第二步聚类：合并重复标记（核心解决多标记问题）
			//vector<cv::Vec3f> finalCircles = clusterCircles(filtered, 15.0f);

			//// 绘制结果
			//dstImage = img.clone();
			//for (size_t i = 0; i < finalCircles.size(); ++i) {
			//	cv::Point center(cvRound(finalCircles[i][0]), cvRound(finalCircles[i][1]));
			//	int radius = cvRound(finalCircles[i][2]);

			//	// 绘制头部轮廓
			//	cv::circle(dstImage, center, radius, cv::Scalar(0, 255, 0), 2);
			//	// 绘制中心红点
			//	cv::circle(dstImage, center, 3, cv::Scalar(0, 0, 255), -1);
			//	// 绘制编号
			//	string text = to_string(i + 1);
			//	cv::Point textPos(center.x - 10, center.y - radius - 5);
			//	if (textPos.y < 0) textPos.y = center.y + radius + 15;
			//	putText(dstImage, text, textPos, cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 0, 0), 1);
			//}
			//// 输出数量
			//int count = finalCircles.size();
			//cout << "检测到螺丝钉数量: " << count << endl;
			//putText(dstImage, "Count: " + to_string(count), cv::Point(30, 50),
			//	cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);


			cout << "检测到螺丝钉数量: " << finalScrews.size() << endl;
			putText(dstImage, "Count: " + to_string(finalScrews.size()), cv::Point(30, 50),
				cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "信息", "螺丝钉总数：" + QString::number(finalScrews.size()) );
			msgBox.setWindowIcon(QIcon(":/resource/info.png"));
			msgBox.exec();
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			//GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
			//GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			return 0;
		}
		if (ui.isActureDistance_2->isChecked() || ui.isActureDistance_3->isChecked() || ui.isActureDistance_4->isChecked()) {
			// 是否A4纸直接测量
			if (ui.isActureDistance_2->isChecked())
			{
				//中值滤波
				//cannyEdgeDetection(srcImage, dstImage, 3, 150, 100);
				std::unique_ptr<MeasureA4Service> service(new MeasureA4Service());
				service->processImage(dstImage);
			}
			// 是否圆形直接测量
			if (ui.isActureDistance_3->isChecked()) {
				std::unique_ptr<MeasureCoinService> service(new MeasureCoinService());
				service->processImage(dstImage);
			}
			// 是否圆形直接测量
			if (ui.isActureDistance_4->isChecked()) {
				std::unique_ptr<GrayService> service(new GrayService());
				service->processImage(dstImage);
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			//GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
			//GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			return 0;
		}
		//多个卡尺同时计算宽度
		int break_flag = 0;
		int return_flag = 0;
		DistanceList.clear();
		for (int i = 0; i < caliper_itemList.count(); i++)
		{
			caliper_item = caliper_itemList.at(i);
			if (caliper_item->caliper_init_state == false)
			{
				//return -1;
				break_flag++;
				break;
			}
			caliper_item->GetCaliper(caliper_p);
			for (int i = 0; i < caliper_item->line_small_points.size(); i++)
			{
				if (caliper_item->line_big_points[i].x() < 0 || caliper_item->line_small_points[i].x() < 0 || caliper_item->line_big_points[i].y() < 0 || caliper_item->line_small_points[i].y() < 0)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					//return -1;
					break_flag++;
					break;
				}
				if (caliper_item->line_big_points[i].x() > dstImage.cols || caliper_item->line_small_points[i].x() > dstImage.cols || caliper_item->line_big_points[i].y() > dstImage.rows || caliper_item->line_small_points[i].y() > dstImage.rows)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					//return -1;
					break_flag++;
					break;
				}
			}
			switch (ui.comboGrayDirection->currentIndex()) {
			case 0:
				direction = 0;
				break;
			case 1:
				direction = 1;
				break;
			}
			xy1.clear();
			xy2.clear();
			line_small_points.clear();
			line_big_points.clear();
			line_small_points = caliper_item->line_small_points;
			line_big_points = caliper_item->line_big_points;
			//位置跟随
			if (ui.checkUseFollow->isChecked() == true)
			{
				strs.clear();
				strs = ui.txtLinkFollow->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					//return -1;
					break_flag++;
					break;
				}
				bool link_state = false;
				int f_index = 0;
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
					//return -2;
					return_flag++;
					break;
				}
				if (strs[1] == "匹配基准中心")
				{
					if (GetToolBase()->m_Tools[f_index].PublicTPosition.Center.size() == 0)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						//return -1;
						break_flag++;
						break;
					}
					match_origin_point = GetToolBase()->m_Tools[f_index].PublicTPosition.DatumCenter;
					match_origin_angle = 0;
					match_current_point = GetToolBase()->m_Tools[f_index].PublicTPosition.Center[0];
					match_current_angle = GetToolBase()->m_Tools[f_index].PublicTPosition.Angle[0];
					for (int p = 0; p < line_small_points.size(); p++)
					{
						cv::Point2f point_small_buf = cv::Point2f(line_small_points[p].x(), line_small_points[p].y());
						cv::Point2f point_small = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_small_buf);
						line_small_points[p] = QPointF(point_small.x, point_small.y);
						cv::Point2f point_big_buf = cv::Point2f(line_big_points[p].x(), line_big_points[p].y());
						cv::Point2f point_big = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_big_buf);
						line_big_points[p] = QPointF(point_big.x, point_big.y);
					}
				}
				else
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					//return -2;
					return_flag++;
					break;
				}
			}
			int result = GetEdgeWidth(dstImage, line_small_points, line_big_points, xy1, xy2, ui.spinThreshold->value(), direction, ui.spinThreshold->value(), direction, ui.spinSegment->value());
			if (result == -1)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				//return -1;
				break_flag++;
				break;
			}
			//拟合直线1
			vector<cv::Point2f> new_xy1(xy1.size());
			for (int i = 0; i < xy1.size(); i++)
			{
				new_xy1[i].x = xy1[i].x();
				new_xy1[i].y = xy1[i].y();
			}
			int w = srcImage.cols;
			cv::Vec4f fitline1;
			cv::fitLine(new_xy1, fitline1, cv::DIST_L2, 0, 0.01, 0.01);
			float vx1 = fitline1[0];
			float vy1 = fitline1[1];
			float x1 = fitline1[2];
			float y1 = fitline1[3];
			double x1_1 = w - 1;
			double y1_1 = (w - x1) * vy1 / vx1 + y1;
			double x1_2 = 0;
			double y1_2 = (-x1 * vy1 / vx1) + y1;
			//剔除点1	
			select_xy1.clear();
			cull_xy1.clear();
			for (int i = 0; i < new_xy1.size(); i++)
			{
				//计算点到直线的距离
				double distance = GetDistP2L(new_xy1[i], cv::Point2f(x1_1, y1_1), cv::Point2f(x1_2, y1_2));
				if (distance > ui.spinCullDistance->value())
				{
					cull_xy1.push_back(new_xy1[i]);
				}
				else
				{
					select_xy1.push_back(new_xy1[i]);
				}
			}
			//剔除点后再次拟合直线1
			if (select_xy1.size() > 0)
			{
				cv::fitLine(select_xy1, fitline1, cv::DIST_L2, 0, 0.01, 0.01);
				vx1 = fitline1[0];
				vy1 = fitline1[1];
				x1 = fitline1[2];
				y1 = fitline1[3];
				x1_1 = w - 1;
				y1_1 = (w - x1) * vy1 / vx1 + y1;
				x1_2 = 0;
				y1_2 = (-x1 * vy1 / vx1) + y1;
			}		
			//拟合直线2
			vector<cv::Point2f> new_xy2(xy2.size());
			for (int i = 0; i < xy2.size(); i++)
			{
				new_xy2[i].x = xy2[i].x();
				new_xy2[i].y = xy2[i].y();
			}
			cv::Vec4f fitline2;
			cv::fitLine(new_xy2, fitline2, cv::DIST_L2, 0, 0.01, 0.01);
			float vx2 = fitline2[0];
			float vy2 = fitline2[1];
			float x2 = fitline2[2];
			float y2 = fitline2[3];
			double x2_1 = w - 1;
			double y2_1 = (w - x2) * vy2 / vx2 + y2;
			double x2_2 = 0;
			double y2_2 = (-x2 * vy2 / vx2) + y2;
			//剔除点2	
			select_xy2.clear();
			cull_xy2.clear();
			for (int i = 0; i < new_xy2.size(); i++)
			{
				//计算点到直线的距离
				double distance = GetDistP2L(new_xy2[i], cv::Point2f(x2_1, y2_1), cv::Point2f(x2_2, y2_2));
				if (distance > ui.spinCullDistance->value())
				{
					cull_xy2.push_back(new_xy2[i]);
				}
				else
				{
					select_xy2.push_back(new_xy2[i]);
				}
			}
			//输出结果
			vector<double> out_distances(select_xy2.size());
			for (int i = 0; i < select_xy2.size(); i++)
			{
				//计算点到直线的距离
				double distance = GetDistP2L(select_xy2[i], cv::Point2f(x1_1, y1_1), cv::Point2f(x1_2, y1_2));
				out_distances[i] = distance;
			}
			if (out_distances.size() == 0)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				//return -1;
				break_flag++;
				break;
			}
			if (ui.isActureDistance_6->isChecked())
			{
				//计算长度
				try 
				{
					// 1. 获取卡尺图像
					cv::Mat src = extractCaliperRegion(srcImage,caliper_p);
					// 2. 计算长度
					Distance = getLength(src);
				}
				catch (const cv::Exception& e)
				{
					std:string error = e.what();
					std::cerr << "OpenCV异常: " << error << std::endl;
				}				
			}
			else
			{
				//去除最大最小值求平均值
				Distance = Average(out_distances, out_distances.size());
			}
			if (ui.checkViewROI->isChecked() == true)
			{
				if(i == 0)
				{
					dstRoiImage = dstImage.clone();
				}
				if (dstRoiImage.channels() == 1)
				{
					cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_GRAY2BGR);
				}
				else if (dstRoiImage.channels() == 4)
				{
					cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_RGBA2BGR);
				}
				for (int i = 0; i < line_small_points.size(); i++)
				{
					cv::line(dstRoiImage, cv::Point(line_small_points[i].x(), line_small_points[i].y()), cv::Point(line_big_points[i].x(), line_big_points[i].y()), cv::Scalar(223, 231, 255), 1);
				}
				for (int n = 0; n < select_xy1.size(); n++)
				{
					cv::line(dstRoiImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy1.size(); n++)
				{
					cv::line(dstRoiImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				for (int n = 0; n < select_xy2.size(); n++)
				{
					cv::line(dstRoiImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy2.size(); n++)
				{
					cv::line(dstRoiImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(caliper_p.col, caliper_p.row), cv::Size2f(caliper_p.len1, caliper_p.len2), -(caliper_p.angle * 180 / M_PI));
				cv::Point2f vertices[4];
				rrect.points(vertices);
				if (ui.checkUseFollow->isChecked() == true)
				{
					cv::Point2f point_1 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[0]);
					cv::Point2f point_2 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[1]);
					cv::Point2f point_3 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[2]);
					cv::Point2f point_4 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[3]);
					cv::line(dstRoiImage, point_1, point_2, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, point_2, point_3, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, point_3, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, point_1, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				}
				else
				{
					cv::line(dstRoiImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[1].x, vertices[1].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(vertices[1].x, vertices[1].y), cv::Point(vertices[2].x, vertices[2].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstRoiImage, cv::Point(vertices[2].x, vertices[2].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				}
				GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			}
			else
			{
				if (dstImage.channels() == 1)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
				}
				else if (dstImage.channels() == 4)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
				}
				for (int n = 0; n < select_xy1.size(); n++)
				{
					cv::line(dstImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy1.size(); n++)
				{
					cv::line(dstImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				for (int n = 0; n < select_xy2.size(); n++)
				{
					cv::line(dstImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy2.size(); n++)
				{
					cv::line(dstImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(caliper_p.col, caliper_p.row), cv::Size2f(caliper_p.len1, caliper_p.len2), -(caliper_p.angle * 180 / M_PI));
				cv::Point2f vertices[4];
				rrect.points(vertices);
				if (ui.checkUseFollow->isChecked() == true)
				{
					cv::Point2f point_1 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[0]);
					cv::Point2f point_2 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[1]);
					cv::Point2f point_3 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[2]);
					cv::Point2f point_4 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[3]);
					cv::line(dstImage, point_1, point_2, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, point_2, point_3, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, point_3, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, point_1, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				}
				else
				{
					cv::line(dstImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[1].x, vertices[1].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(vertices[1].x, vertices[1].y), cv::Point(vertices[2].x, vertices[2].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(vertices[2].x, vertices[2].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				}
				GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
			}
			// 是否使用实际距离系数
			if (ui.isActureDistance->isChecked())
			{
				Distance = Distance * ui.spinActureDistance->value();
			}
			// 判断距离是否在上下限内
			if (Distance >= ui.spinLowDistance->value() && Distance <= ui.spinUpDistance->value())
			{
				GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
				GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
				GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
				GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
				DistanceList.push_back(Distance);
				GetToolBase()->m_Tools[tool_index].PublicGeometry.DistanceList = DistanceList;
			}
			else
			{
				GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
				GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
				GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				DistanceList.push_back(Distance);
				GetToolBase()->m_Tools[tool_index].PublicGeometry.DistanceList = DistanceList;
				//return -1;
				break_flag++;
				break;
			}
		}
		//返回值判断
		if (break_flag > 0)
		{
			return -1;
		}
		else if(return_flag > 0)
		{
			return -2;
		}
		
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmEdgeWidthMeasure::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmEdgeWidthMeasure::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmEdgeWidthMeasure::InitSetToolData(const QVariant data)
{
	int break_flag = 0;
	if (data != NULL)
	{
		//循环取所有卡尺
		for (int i = 0; i < data.toList().count(); i++)
		{
			try
			{
				InitEdgeWidthMeasureData init_data;
				init_data = data.toList()[i].value<InitEdgeWidthMeasureData>();
				if (init_data.use_roi == true)
				{
					//取消删除所有卡尺
					//view->ClearObj();
					if (init_data.type == "caliper_p")
					{
						caliper_item = new Caliper(init_data.x1, init_data.y1, init_data.x2, init_data.y2, init_data.height);
						caliper_item->caliper_init_state = true;
						caliper_item->segment_line_num = init_data.segment_line_num;
						view->AddItems(caliper_item);
						caliper_item->line_small_points.clear();
						caliper_item->line_big_points.clear();
						for (int i = 0; i < init_data.line_s_points.size(); i++)
						{
							caliper_item->line_small_points.push_back(init_data.line_s_points[i]);
							caliper_item->line_big_points.push_back(init_data.line_b_points[i]);
						}
						caliper_item->SetCaliper(init_data.pp1, init_data.pp2);
						caliper_itemList.append(caliper_item);
					}
					color = init_data.color;
					//设置按钮背景颜色
					QString style_color = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ")";
					ui.btnRoiColor->setStyleSheet(style_color);
				}			
			}
			catch (...)
			{
				break_flag++;
				//return -1;
			}
		}
	}
	if (break_flag > 0)
	{
		return -1;
	}
	return 0;
}

QVariant frmEdgeWidthMeasure::InitGetToolData()
{
	int break_flag = 0;
	QVariantList list = QVariantList();
	QVariant qvarient = QVariant();
	//循环取所有卡尺
	for (int i = 0; i < caliper_itemList.count(); i++)
	{
		caliper_item = caliper_itemList.at(i);
		InitEdgeWidthMeasureData init_data;
		if (ui.checkUseROI->isChecked() == true)
		{
			init_data.use_roi = true;
			if (ui.comboROIShape->currentIndex() == 0)
			{

				if (caliper_item->caliper_init_state == false)
				{
					//return -1;
					break_flag++;
					break;
				}
				caliper_item->GetCaliper(caliper_p);
				init_data.type = "caliper_p";
				init_data.x1 = caliper_p.x1;
				init_data.y1 = caliper_p.y1;
				init_data.x2 = caliper_p.x2;
				init_data.y2 = caliper_p.y2;
				init_data.height = caliper_p.height;
				init_data.row = caliper_p.row;
				init_data.col = caliper_p.col;
				init_data.len1 = caliper_p.len1;
				init_data.len2 = caliper_p.len2;
				init_data.angle = caliper_p.angle;
				init_data.pp1 = caliper_p.pp1;
				init_data.pp2 = caliper_p.pp2;
				init_data.segment_line_num = caliper_item->segment_line_num;
				init_data.color = color;
				for (int i = 0; i < caliper_item->line_small_points.size(); i++)
				{
					init_data.line_s_points.append(caliper_item->line_small_points[i]);
					init_data.line_b_points.append(caliper_item->line_big_points[i]);
				}
			}
		}
		else
		{
			init_data.use_roi = false;
		}
		list.append(QVariant::fromValue(init_data));
	}
	qvarient = list;
	return qvarient;
}

void frmEdgeWidthMeasure::on_btnExecute_clicked()
{	
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	//显示所有卡尺结果
	for (int i = 0; i < DistanceList.count(); i++)
	{
		ui.txtMsg->append("-> 边缘宽度为：" + QString::number(DistanceList[i]) + "\n");
	}	
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmEdgeWidthMeasure::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmEdgeWidthMeasure::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmEdgeWidthMeasure::on_btnLinkFollow_clicked()
{
	QConfig::nFormState = 2;
}

void frmEdgeWidthMeasure::on_btnDelLinkFollow_clicked()
{
	ui.txtLinkFollow->clear();
}

void frmEdgeWidthMeasure::on_btnAddROI_clicked()
{
	//无限添加卡尺
	//view->ClearObj();
	caliper_item = new Caliper(10, 160, 200, 160, 300);
	caliper_item->caliper_init_state = true;
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		caliper_item->segment_line_num = ui.spinSegment->value();
		view->AddItems(caliper_item);
		caliper_itemList.append(caliper_item);
		break;
	}
}

void frmEdgeWidthMeasure::on_btnDeleteROI_clicked()
{
	caliper_item->caliper_init_state = false;
	//删除当前卡尺
	view->ClearObj();
	//view->scene(caliper_item);
	caliper_itemList.clear();
}

void frmEdgeWidthMeasure::on_btnRoiColor_clicked()
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

void frmEdgeWidthMeasure::on_spinSegment_valueChanged(int value)
{
	caliper_item->segment_line_num = value;
}

//获取边缘宽度
//threshold_delta为阈值；direction的值为0时代表“从白到黑”寻找边界点，direction的值为1时代表“从黑到白”寻找边界点
//segment_num为分割线数量	
int frmEdgeWidthMeasure::GetEdgeWidth(const cv::Mat& src_mat, const std::vector<QPointF> line_small_points, const std::vector<QPointF> line_big_points, vector<QPointF>& edge_points1, vector<QPointF>& edge_points2, const int threshold_delta1, const int direction1, const int threshold_delta2, const int direction2, const int segment_num)
{
	try
	{
		cv::Mat gray;
		if (src_mat.channels() == 3)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_BGR2GRAY);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			src_mat.copyTo(gray);
		}
		int ww = gray.cols;
		int hh = gray.rows;
		int bytes = ww * hh;
		vector<unsigned char> rgbValues(bytes);
		QPixmap pixmap = QPixmap::fromImage(Mat2QImage(gray));
		QImage img = pixmap.toImage();
		unsigned char* pData = img.bits();
		for (int i = 0; i < ww * hh * 4; i += 4)
		{
			rgbValues[i / 4] = pData[i];
		}
		vector<unsigned char> buffer8(bytes);
		buffer8 = rgbValues;		
		//边界点                   
		vector<QPointF> backPoint1(segment_num);
		vector<QPointF> backOutPoint1(segment_num);
		vector<QPointF> backPoint2(segment_num);
		vector<QPointF> backOutPoint2(segment_num);
		//寻找边界点		
		int m1 = 0;
		int m2 = 0;
		//计算两点间的距离
		double distance;
		distance = pow((line_small_points[0].x() - line_big_points[0].x()), 2) + pow((line_small_points[0].y() - line_big_points[0].y()), 2);
		distance = sqrt(distance);
		//线图像上每一个点灰度颜色
		QList<float> temparrclor1 = QList<float>();
		temparrclor1.reserve(5000);
		QList<float> temparrclor2 = QList<float>();
		temparrclor2.reserve(5000);
		//线图像上每一个点坐标
		QList<QPointF> position1 = QList<QPointF>();
		position1.reserve(5000);
		QList<QPointF> position2 = QList<QPointF>();
		position2.reserve(5000);
		for (int k = 0; k < segment_num; k++)
		{
			temparrclor1.clear();
			position1.clear();
			float x_point1;
			float y_point1;
			//从line_small_points往line_big_points扫描
			for (int n = 0; n < (int)distance; n++)
			{
				x_point1 = (n * (line_big_points[k].x() - line_small_points[k].x())) / distance + line_small_points[k].x();
				y_point1 = (n * (line_big_points[k].y() - line_small_points[k].y())) / distance + line_small_points[k].y();
				float tempf = abs(y_point1 - (int)y_point1);
				QPointF tempPt = QPointF(x_point1, y_point1);
				float avgGrey = (float)buffer8[(int)y_point1 * ww + (int)x_point1];
				float avgGrey1 = (float)buffer8[(int)(y_point1 + 1) * ww + (int)x_point1];
				float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
				//插值灰度
				temparrclor1.push_back(grey);
				position1.push_back(tempPt);
			}
			//找穿越点
			QPointF return_point1 = FindCrosspointimprove(temparrclor1, position1, direction1, threshold_delta1);
			if (return_point1 != QPointF(0, 0))
			{
				backPoint1[m1] = return_point1;
				m1 += 1;
			}
			temparrclor2.clear();
			position2.clear();
			float x_point2;
			float y_point2;
			//从line_big_points往line_small_points扫描
			for (int n = 0; n < (int)distance; n++)
			{
				x_point2 = (n * (line_small_points[k].x() - line_big_points[k].x())) / distance + line_big_points[k].x();
				y_point2 = (n * (line_small_points[k].y() - line_big_points[k].y())) / distance + line_big_points[k].y();
				float tempf = abs(y_point2 - (int)y_point2);
				QPointF tempPt = QPointF(x_point2, y_point2);
				float avgGrey = (float)buffer8[(int)y_point2 * ww + (int)x_point2];
				float avgGrey1 = (float)buffer8[(int)(y_point2 + 1) * ww + (int)x_point2];
				float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
				//插值灰度
				temparrclor2.push_back(grey);
				position2.push_back(tempPt);
			}
			//找穿越点
			QPointF return_point2 = FindCrosspointimprove(temparrclor2, position2, direction2, threshold_delta2);
			if (return_point2 != QPointF(0, 0))
			{
				backPoint2[m2] = return_point2;
				m2 += 1;
			}
		}
		backOutPoint1.resize(m1);
		for (int n = 0; n < m1; n++)
		{
			backOutPoint1[n] = backPoint1[n];
		}
		edge_points1 = backOutPoint1;
		backOutPoint2.resize(m2);
		for (int n = 0; n < m2; n++)
		{
			backOutPoint2[n] = backPoint2[n];
		}
		edge_points2 = backOutPoint2;		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

//梯度和求穿越点
QPointF frmEdgeWidthMeasure::FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta)
{
	try
	{
		//梯度和求穿越点，使用五个一组
		QList<float> deltatemp = QList<float>();
		deltatemp.reserve(5000);
		deltatemp.clear();
		QList<float> fenzuaverage = QList<float>();
		fenzuaverage.reserve(5000);
		fenzuaverage.clear();
		for (int i = 0; i < lineTiDu.size() - 1; i++)
		{
			float grey1 = lineTiDu[i + 1];
			float delta = (lineTiDu[i] - grey1);
			if (abs(delta) < 5)
				delta = 0;
			deltatemp.push_back(delta);
		}
		int fenzuC = deltatemp.size() / 5;
		for (int i = 0; i < fenzuC * 5; i += 5)
		{
			float sum5 = deltatemp[i] + deltatemp[i + 1] + deltatemp[i + 2] + deltatemp[i + 3] + deltatemp[i + 4];
			float aver = sum5 / 5;
			if (abs(aver) < 5)
				aver = 0;
			fenzuaverage.push_back(aver);
		}
		if (fenzuaverage.size() == 0) return QPointF();
		int crosspoint = 0;
		int crosspoint1 = 0;
		//从白到黑寻找
		if (direction == 0)
		{
			for (int iii = fenzuaverage.size() - 1; iii >= 0; iii--) //排除起点和终点
			{
				if (fenzuaverage[iii] > 0)
				{
					crosspoint = 5 * (iii);
					break;
				}
			}
			float maxVar = deltatemp[crosspoint];
			for (int m = -5; m < 5; m++)
			{
				int tempint = crosspoint + m;
				if (crosspoint == 0)
					tempint = 0;
				if (deltatemp[tempint] >= maxVar)
				{
					maxVar = deltatemp[tempint];
					crosspoint1 = tempint;
				}
			}
		}
		//从黑到白寻找
		else if (direction == 1)
		{
			for (int iii = 0; iii <= fenzuaverage.size() - 1; iii++) //排除起点和终点
			{
				if (fenzuaverage[iii] < 0)
				{
					crosspoint = 5 * (iii);
					break;
				}
			}
			float minVar = deltatemp[crosspoint];
			for (int m = -5; m < 5; m++)
			{
				int tempint = crosspoint + m;
				if (crosspoint == 0)
					tempint = 0;
				if (deltatemp[tempint] <= minVar)
				{
					minVar = deltatemp[tempint];
					crosspoint1 = tempint;
				}
			}
		}
		//阈值判别
		if (fenzuaverage[crosspoint / 5] * 5 >= threshold_delta || fenzuaverage[crosspoint / 5] * 5 <= -threshold_delta)
		{
			//穿越点的index对应坐标(crosspoint1为线图像中穿越点index)
			return ijRecord[crosspoint1];
		}
		else
		{
			return QPointF(0, 0); //没有穿越点，返回（0,0）
		}
	}
	catch (...)
	{
		return QPointF(0, 0); //没有穿越点，返回（0,0）
	}
}

//计算点到直线的距离(P为线外一点，AB为线段两个端点)
double frmEdgeWidthMeasure::GetDistP2L(const cv::Point2f pointP, const cv::Point2f pointA, const cv::Point2f pointB)
{
	//求直线方程
	double A = 0, B = 0, C = 0;
	A = pointA.y - pointB.y;
	B = pointB.x - pointA.x;
	C = pointA.x * pointB.y - pointA.y * pointB.x;
	double distance = 0;
	distance = ((double)abs(A * pointP.x + B * pointP.y + C)) / ((double)sqrtf(A * A + B * B));
	return distance;
}

//去除最大最小值求平均值
double frmEdgeWidthMeasure::Average(const vector<double> arrays, const int n)
{
	double max = arrays[0];
	double min = arrays[0];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arrays[i];
		max = max < arrays[i] ? arrays[i] : max;
		min = min > arrays[i] ? arrays[i] : min;
	}
	return (sum - max - min) / (n - 2);
}

cv::Point2f frmEdgeWidthMeasure::AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point)
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

QImage frmEdgeWidthMeasure::Mat2QImage(const cv::Mat& mat)
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

double frmEdgeWidthMeasure::getLength(cv::Mat srcImage)
{
	// ... (加载图像、灰度化、二值化的代码保持不变) ...
	cv::Mat sourceMat = srcImage;//cv::imread(...);
	//cv::Mat binaryMat;
	// ... cv::threshold(...) ...

	//emit statusMessageChanged("预处理完成，开始寻找轮廓...");

	// --- 3. 轮廓发现 ---
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(sourceMat, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	// 假设最大轮廓就是我们的螺丝
	if (contours.empty()) {
		//emit statusMessageChanged("错误：未在图像中找到任何轮廓！");
		return 0;
	}

	// 寻找面积最大的轮廓
	double maxArea = 0;
	int maxAreaIdx = -1;
	for (int i = 0; i < contours.size(); i++) {
		double area = cv::contourArea(contours[i]);
		if (area > maxArea) {
			maxArea = area;
			maxAreaIdx = i;
		}
	}

	if (maxAreaIdx == -1) {
		// ... 错误处理
		return 0;
	}

	// --- 4. 尺寸测量 ---
	// 计算最大轮廓的最小外接矩形
	cv::RotatedRect rotatedRect = cv::minAreaRect(contours[maxAreaIdx]);

	// 获取矩形的尺寸。注意：width和height不一定是物理的长和宽
	cv::Size2f rectSize = rotatedRect.size;
	float width = std::min(rectSize.width, rectSize.height);
	float length = std::max(rectSize.width, rectSize.height);

	qDebug() << "Measured dimensions (pixels): Length =" << length << ", Width =" << width;
	QString resultMessage = QString("测量结果: 长度= %1 px, 宽度= %2 px").arg(length, 0, 'f', 2).arg(width, 0, 'f', 2);

	// --- 5. 结果可视化 ---
	// 为了直观展示，我们在原始彩色图上把轮廓和矩形画出来
	// 获取矩形的四个顶点
	cv::Point2f vertices[4];
	rotatedRect.points(vertices);
	// 将轮廓和矩形画在sourceMat上
	cv::drawContours(sourceMat, contours, maxAreaIdx, cv::Scalar(0, 255, 0), 2); // 绿色轮廓
	for (int i = 0; i < 4; i++) {
		cv::line(sourceMat, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 0, 255), 2); // 红色矩形
	}
	return length;
	// 将带有绘制结果的图像发送到UI
	/*QImage imageQ = matToQImage(sourceMat);
	m_imageProvider->updateImage(imageQ);
	emit imageReady("screw_processed");
	emit statusMessageChanged(resultMessage);*/
}
// 转换为3通道矩阵（4行3列）
cv::Mat frmEdgeWidthMeasure::convertTo3Channel(const CaliperP& caliper) {
	cv::Mat mat(4, 3, CV_32F);
	float* data = mat.ptr<float>(0);

	// 第一行：基础参数
	data[0] = caliper.row;
	data[1] = caliper.col;
	data[2] = caliper.angle;

	// 第二行：长度参数
	data[3] = caliper.len1;
	data[4] = caliper.len2;
	data[5] = caliper.height;

	// 第三行：坐标点1
	data[6] = caliper.x1;
	data[7] = caliper.y1;
	data[8] = caliper.pp1.x();

	// 第四行：坐标点2
	data[9] = caliper.x2;
	data[10] = caliper.y2;
	data[11] = caliper.pp1.y();

	return mat;
}
// 将CaliperP结构体转换为单通道cv::Mat（12行1列）
cv::Mat frmEdgeWidthMeasure::convertToMat(const CaliperP& caliper) {
	cv::Mat mat(12, 1, CV_32F); // 12个浮点参数的单通道矩阵
	float* data = mat.ptr<float>(0);

	data[0] = caliper.row;     // row
	data[1] = caliper.col;     // col
	data[2] = caliper.len1;    // len1
	data[3] = caliper.len2;    // len2
	data[4] = caliper.angle;   // angle
	data[5] = caliper.x1;      // x1
	data[6] = caliper.y1;      // y1
	data[7] = caliper.x2;      // x2
	data[8] = caliper.y2;      // y2
	data[9] = caliper.height;  // height
	data[10] = caliper.pp1.x(); // pp1.x
	data[11] = caliper.pp1.y(); // pp1.y

	return mat;
}

cv::Mat frmEdgeWidthMeasure::caliperToMat(const cv::Mat& srcImage, const CaliperP& caliper) {
	// 获取卡尺端点
	QPointF pp1 = caliper.pp1;
	QPointF pp2 = caliper.pp2;
	float height = caliper.height;

	// 计算线段向量和长度
	float dx = pp2.x() - pp1.x();
	float dy = pp2.y() - pp1.y();
	float length = std::sqrt(dx * dx + dy * dy);

	if (length < 1e-5) {
		return cv::Mat(); // 端点重合，返回空Mat
	}

	// 计算单位垂直向量（顺时针旋转90度）
	float nx = dy / length;  // 垂直分量x
	float ny = -dx / length; // 垂直分量y

	// 计算矩形四个顶点（按左上、右上、右下、左下顺序）
	std::vector<cv::Point2f> srcPoints;
	srcPoints.push_back(cv::Point2f(pp1.x() + nx * height / 2, pp1.y() + ny * height / 2)); // 左上
	srcPoints.push_back(cv::Point2f(pp2.x() + nx * height / 2, pp2.y() + ny * height / 2)); // 右上
	srcPoints.push_back(cv::Point2f(pp2.x() - nx * height / 2, pp2.y() - ny * height / 2)); // 右下
	srcPoints.push_back(cv::Point2f(pp1.x() - nx * height / 2, pp1.y() - ny * height / 2)); // 左下

	// 定义目标矩形的四个角点
	std::vector<cv::Point2f> dstPoints;
	dstPoints.push_back(cv::Point2f(0, 0));
	dstPoints.push_back(cv::Point2f(length, 0));
	dstPoints.push_back(cv::Point2f(length, height));
	dstPoints.push_back(cv::Point2f(0, height));

	// 计算透视变换矩阵
	cv::Mat transformMat = cv::getPerspectiveTransform(srcPoints, dstPoints);

	// 执行透视变换
	cv::Mat dstImage;
	cv::warpPerspective(
		srcImage, dstImage, transformMat,
		cv::Size(static_cast<int>(length), static_cast<int>(height))
	);

	return dstImage;
}
// 计算旋转卡尺区域并转换为 cv::Mat
cv::Mat frmEdgeWidthMeasure::extractCaliperRegion(const cv::Mat& srcImage, const CaliperP& caliper) {
	// 获取卡尺关键点
	QPointF center(caliper.col, caliper.row);
	QPointF pp1 = caliper.pp1;
	QPointF pp2 = caliper.pp2;
	float height = caliper.height;
	float angle = caliper.angle; // 旋转角度（弧度）

	// 计算卡尺方向向量
	float dx = pp2.x() - pp1.x();
	float dy = pp2.y() - pp1.y();
	float length = std::sqrt(dx * dx + dy * dy);

	if (length < 1e-5) {
		return cv::Mat(); // 端点重合，返回空Mat
	}

	// 计算单位方向向量
	float ux = dx / length;
	float uy = dy / length;

	// 计算垂直向量（顺时针旋转90度）
	float vx = uy;
	float vy = -ux;

	// 计算矩形的四个顶点（考虑旋转）
	std::vector<cv::Point2f> srcPoints;

	// 顶点1: pp1 + (height/2) * 垂直向量
	srcPoints.push_back(cv::Point2f(
		pp1.x() + vx * height / 2,
		pp1.y() + vy * height / 2
	));

	// 顶点2: pp2 + (height/2) * 垂直向量
	srcPoints.push_back(cv::Point2f(
		pp2.x() + vx * height / 2,
		pp2.y() + vy * height / 2
	));

	// 顶点3: pp2 - (height/2) * 垂直向量
	srcPoints.push_back(cv::Point2f(
		pp2.x() - vx * height / 2,
		pp2.y() - vy * height / 2
	));

	// 顶点4: pp1 - (height/2) * 垂直向量
	srcPoints.push_back(cv::Point2f(
		pp1.x() - vx * height / 2,
		pp1.y() - vy * height / 2
	));

	// 定义目标矩形的四个角点（考虑旋转）
	std::vector<cv::Point2f> dstPoints;
	dstPoints.push_back(cv::Point2f(0, 0));                   // 左上
	dstPoints.push_back(cv::Point2f(length, 0));              // 右上
	dstPoints.push_back(cv::Point2f(length, height));         // 右下
	dstPoints.push_back(cv::Point2f(0, height));             // 左下

	// 计算透视变换矩阵
	cv::Mat transformMat = cv::getPerspectiveTransform(srcPoints, dstPoints);

	// 执行透视变换
	cv::Mat dstImage;
	cv::warpPerspective(
		srcImage,
		dstImage,
		transformMat,
		cv::Size(static_cast<int>(length), static_cast<int>(height))
	);

	return dstImage;
}

//全局变量控制
int QConfig::nFormState = 0;
