#include "frmClassifier.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <iostream>
#include <fstream>
#include "ImageItem.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "YOLO12.hpp" 
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <QScreen>
#include <algorithm> 
#include <iomanip>
#include "yolos/tasks/detection.hpp"
#include "yolos/tasks/pose.hpp"
#include "yolos/tasks/segmentation.hpp"
#include "yolos/tasks/obb.hpp"
#include "yolos/tasks/classification.hpp"
cv::Mat frmClassifier::GetYoloV13(std::string modelPath, std::string labelsPath, cv::Mat image, bool isGPU, std::string task_type, std::string yolo_type, std::string device_type)
{

        // Configuration parameters
        //const std::string labelsPath = "coco.names";       // Path to class labels
        //const std::string modelPath = "yolov13l.onnx";     // Path to YOLO12 model
        //const std::string imagePath = "data/dog.jpg";           // Path to input image
        //bool isGPU = false;                                           // Set to false for CPU processing
	try
	{
		if (task_type == "Detect") {
			//try
			//{
			//	YOLO12Detector detector(modelPath, labelsPath, isGPU);


			//	DWORD start_time = GetTickCount64();

			//	// Load an image
			//	/*cv::Mat image = cv::imread(imagePath);*/

			//	// Perform object detection to get bboxs
			//	std::vector<Detection> detections = detector.detect(image, 0.7);

			//	// Draw bounding boxes on the image
			//	detector.drawBoundingBoxMask(image, detections);
			//	bool isFullScreen = false;
			//	if (detections.size() > 0) {
			//		for (int i = 0; i < detections.size(); i++)
			//		{
			//			//检测到手机拍照立刻全屏遮挡
			//			if (QString::fromStdString(utils::getClassNames(labelsPath)[detections[i].classId]) == "phone")
			//			{
			//				//全屏遮挡
			//				emit sigShowFullScreen();
			//				isFullScreen = true;
			//				break;
			//			}
			//		}
			//		GetToolBase()->m_Tools[tool_index].PublicDetect.Category = QString::fromStdString(utils::getClassNames(labelsPath)[detections[0].classId]);
			//		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			//	}
			//	else
			//	{
			//		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			//	}
			//	if (!isFullScreen)
			//	{
			//		//撤销全屏遮挡
			//		emit sigEndFullScreen();
			//	}
			//	DWORD end_time = GetTickCount64();
			//}
			//catch (const std::exception e) {
			//	qDebug() << "发生报错：" << e.what();
			//}
			if (ui.comboType_4->currentText().QString::toStdString() == "GPU")
			{
				isGPU = true;
			}
			else if (ui.comboType_4->currentText().QString::toStdString() == "CPU")
			{
				isGPU = false;
			}
			if (ui.comboType_3->currentText().QString::toStdString() == "YOLOv4")
			{
				// 使用 OpenCV DNN 加载并推理 YOLOv4（支持 .cfg+.weights 或 .onnx）
				bool isFullScreen = false;
				try {
					// 阈值与输入大小（可调整或做成 UI 参数）
					const float confThreshold = 0.5f;
					const float nmsThreshold = 0.45f;
					const int inpWidth = 416;
					const int inpHeight = 416;

					// 选择 backend/target
					cv::dnn::Net net;

					// 辅助：判断后缀
					auto ends_with = [](const std::string& s, const std::string& suffix) {
						return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
						};

					// 首先尝试用户在界面中填写的路径（优先使用 txtLoadModel 与 txtLabels）
					std::string uiModel = ui.txtLoadModel->text().toStdString(); // 可能是 .weights 或 .onnx
					std::string uiLabels = ui.txtLabels->text().toStdString();   // 可能是 .cfg 或 .names

					// 优先处理 ONNX（通用）
					if (ends_with(uiModel, ".onnx") || ends_with(modelPath, ".onnx")) {
						std::string onnxPath = ends_with(uiModel, ".onnx") ? uiModel : modelPath;
						net = cv::dnn::readNet(onnxPath);
					}
					else {
						// 尝试使用 cfg + weights：按要求 uiModel 为 .weights，uiLabels 为 .names
						std::string cfgPath;
						std::string weightsPath;

						// 优先使用界面填写的 txtLoadModel (uiModel) 作为 .weights
						if (ends_with(uiModel, ".weights")) {
							weightsPath = uiModel;
							// 从 uiModel 替换尾部 .weights -> .cfg 作为 cfg 路径
							cfgPath = uiModel.substr(0, uiModel.size() - 8) + ".cfg";
							// 如果生成的 cfg 不存在，尝试用传入的 modelPath（如果是 .cfg）
							std::ifstream f(cfgPath);
							if (!f.good()) {
								if (ends_with(modelPath, ".cfg")) {
									cfgPath = modelPath;
								}
							}
							else {
								f.close();
							}
						}
						// 否则，如果传入的 modelPath 是 .weights，也同样处理
						else if (ends_with(modelPath, ".weights")) {
							weightsPath = modelPath;
							cfgPath = modelPath.substr(0, modelPath.size() - 8) + ".cfg";
							std::ifstream f(cfgPath);
							if (!f.good()) {
								// 无法找到自动生成的 cfg，留空以便后续回退处理
							}
							else {
								f.close();
							}
						}
						// 仍然尝试兼容少数旧用法：如果传入参数已经包含 cfg+weights，沿用之
						else if (ends_with(modelPath, ".cfg") && ends_with(labelsPath, ".weights")) {
							cfgPath = modelPath;
							weightsPath = labelsPath;
						}
						// 额外兼容：如果 uiLabels 意外被选为 .cfg，则把它作为 cfg，并尝试推断 weights
						else if (ends_with(uiLabels, ".cfg")) {
							cfgPath = uiLabels;
							weightsPath = uiLabels.substr(0, uiLabels.size() - 4) + ".weights";
							std::ifstream f(weightsPath);
							if (!f.good()) {
								weightsPath.clear();
							}
							else f.close();
						}

						// 最终加载：若 cfg 与 weights 都存在则用 Darknet 加载，否则尝试用传入的 modelPath 作为通用读取（如 .onnx）
						if (!cfgPath.empty() && !weightsPath.empty()) {
							net = cv::dnn::readNetFromDarknet(cfgPath, weightsPath);
						}
						else {
							// 回退：直接尝试用 modelPath（可能是 .onnx 或其它可识别格式）
							net = cv::dnn::readNet(modelPath);
						}
						// 如果都没有找到 cfg+weights，就尝试直接用 modelPath（可能是 .weights/.onnx）
						if (!cfgPath.empty() && !weightsPath.empty()) {
							net = cv::dnn::readNetFromDarknet(cfgPath, weightsPath);
						}
						else {
							// 兜底：尝试用 modelPath（可能是 .weights）直接读取（OpenCV 不直接支持仅 .weights）
							// 如果 modelPath 是 .weights，尝试找同名 .cfg
							if (ends_with(modelPath, ".weights")) {
								std::string candCfg = modelPath.substr(0, modelPath.size() - 8) + ".cfg";
								std::ifstream f(candCfg);
								if (f.good()) {
									net = cv::dnn::readNetFromDarknet(candCfg, modelPath);
									f.close();
								}
								else {
									// 直接读 weights 会失败；作为最后手段尝试 readNet(modelPath)
									net = cv::dnn::readNet(modelPath);
								}
							}
							else {
								// 直接尝试用传入的 modelPath
								net = cv::dnn::readNet(modelPath);
							}
						}
					}

					// 设置 backend/target
					if (isGPU) {
#ifdef CV_DNN_HAS_CUDA
						net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
						net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
#else
						net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
						net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
#endif
					}
					else {
						net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
						net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
					}

					// 预处理并前向推理
					cv::Mat blob;
					cv::dnn::blobFromImage(image, blob, 1.0 / 255.0, cv::Size(inpWidth, inpHeight), cv::Scalar(0, 0, 0), true, false);
					net.setInput(blob);

					std::vector<cv::Mat> outs;
					net.forward(outs, net.getUnconnectedOutLayersNames());

					// 解析输出（兼容 darknet 格式和常见 yolov4 onnx 输出）
					std::vector<int> classIds;
					std::vector<float> confidences;
					std::vector<cv::Rect> boxes;

					for (size_t i = 0; i < outs.size(); ++i) {
						// 每个 outs[i] 的每一行是一个检测向量
						for (int j = 0; j < outs[i].rows; ++j) {
							const float* data = outs[i].ptr<float>(j);
							// 常见格式：[center_x, center_y, width, height, obj_conf, class1, class2, ...]
							float obj_conf = data[4];
							if (obj_conf <= 0.0f) continue;

							// 找到类别分数最大值
							int numClasses = outs[i].cols - 5;
							const float* scores = data + 5;
							int bestClass = 0;
							float bestScore = scores[0];
							for (int c = 1; c < numClasses; ++c) {
								if (scores[c] > bestScore) {
									bestScore = scores[c];
									bestClass = c;
								}
							}
							float confidence = obj_conf * bestScore;
							if (confidence > confThreshold) {
								int centerX = static_cast<int>(data[0] * image.cols);
								int centerY = static_cast<int>(data[1] * image.rows);
								int width = static_cast<int>(data[2] * image.cols);
								int height = static_cast<int>(data[3] * image.rows);
								int left = centerX - width / 2;
								int top = centerY - height / 2;

								classIds.push_back(bestClass);
								confidences.push_back(confidence);
								boxes.push_back(cv::Rect(left, top, width, height));
							}
						}
					}

					// 非极大值抑制
					std::vector<int> indices;
					cv::dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);

					// 本地检测结果结构，初始化成员以消除静态分析警告
					struct LocalDet { int classId = 0; float confidence = 0.0f; cv::Rect box = cv::Rect(); std::string className = ""; };
					std::vector<LocalDet> localDetections;

					// 尝试获取类别名称列表（优先使用界面填写的 .names 文件）
					std::vector<std::string> classNames;
					std::string namesFile;
					// ui.txtLabels 可能是 .names 或 .cfg；优先查找 .names
					if (!ui.txtLabels->text().toStdString().empty() && ends_with(ui.txtLabels->text().toStdString(), ".names")) {
						namesFile = ui.txtLabels->text().toStdString();
					}
					else {
						// 若 ui.txtLabels 是 .cfg，则尝试同目录同名 .names
						if (!ui.txtLabels->text().toStdString().empty() && ends_with(ui.txtLabels->text().toStdString(), ".cfg")) {
							std::string cand = ui.txtLabels->text().toStdString();
							cand = cand.substr(0, cand.size() - 4) + ".names";
							std::ifstream f(cand);
							if (f.good()) {
								namesFile = cand;
								f.close();
							}
						}
						// 再尝试传入的 labelsPath 参数
						if (namesFile.empty() && !labelsPath.empty() && ends_with(labelsPath, ".names")) {
							namesFile = labelsPath;
						}
					}
					if (!namesFile.empty()) {
						try {
							classNames = utils::getClassNames(namesFile);
						}
						catch (...) {
							classNames.clear();
						}
					}

					for (int idx : indices) {
						LocalDet d;
						d.classId = classIds[idx];
						d.confidence = confidences[idx];
						d.box = boxes[idx];
						if (d.classId >= 0 && d.classId < (int)classNames.size()) d.className = classNames[d.classId];
						else d.className = std::to_string(d.classId);

						// 检测到 phone 触发全屏
						if (d.className == "phone") {
							emit sigShowFullScreen();
							isFullScreen = true;
						}

						localDetections.push_back(d);

						// 可视化：绘制 bbox 与标签
						cv::rectangle(image, d.box, cv::Scalar(0, 255, 0), 2);
						std::ostringstream label;
						label << d.className << ":" << std::fixed << std::setprecision(2) << d.confidence;
						int baseLine = 0;
						cv::Size labelSize = cv::getTextSize(label.str(), cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
						int top = std::max(d.box.y, static_cast<int>(labelSize.height));
						cv::putText(image, label.str(), cv::Point(d.box.x, top - 4), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1);
					}

					if (!isFullScreen) {
						emit sigEndFullScreen();
					}

					// 更新工具状态（与原分支保持一致）
					if (localDetections.size() > 0) {
						GetToolBase()->m_Tools[tool_index].PublicDetect.Category = QString::fromStdString(localDetections[0].className);
						GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
					}
					else {
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					}
				}
				catch (const std::exception& ex) {
					qDebug() << "YOLOv4 推理异常：" << ex.what();
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				}
			}
			else
			{
				bool isFullScreen = false;
				// Initialize
				yolos::det::YOLODetector detector(modelPath, labelsPath, /*gpu=*/isGPU);

				// Detect

				auto detections = detector.detect(image, /*conf=*/ui.doubleSpinBox_2->value(), /*iou=*/ui.doubleSpinBox->value());

				// Process results
				for (const auto& det : detections) {
					/*std::cout << "Class: " << det.className
						<< " Conf: " << det.confidence
						<< " Box: " << det.box << std::endl;*/
						//检测到手机拍照立刻全屏遮挡
					if (QString::fromStdString(utils::getClassNames(labelsPath)[det.classId]) == "phone")
					{
						//全屏遮挡
						emit sigShowFullScreen();
						isFullScreen = true;
						break;
					}
				}
				if (detections.size() > 0)
				{
					GetToolBase()->m_Tools[tool_index].PublicDetect.Category = QString::fromStdString(utils::getClassNames(labelsPath)[detections[0].classId]);
					GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
				}
				else
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				}
				// Visualize
				detector.drawDetections(image, detections);
				if (!isFullScreen)
				{
					//撤销全屏遮挡
					emit sigEndFullScreen();
				}
			}
		}
		else if (task_type == "Pose") {

			if (ui.comboType_4->currentText().QString::toStdString() == "GPU")
			{
				isGPU = true;
			}
			else if (ui.comboType_4->currentText().QString::toStdString() == "CPU")
			{
				isGPU = false;
			}
			yolos::pose::YOLOPoseDetector detector(modelPath, "", isGPU);
			auto poses = detector.detect(image);
			detector.drawPoses(image, poses);
		}
		else if (task_type == "OBB") {

			if (ui.comboType_4->currentText().QString::toStdString() == "GPU")
			{
				isGPU = true;
			}
			else if (ui.comboType_4->currentText().QString::toStdString() == "CPU")
			{
				isGPU = false;
			}
			yolos::obb::YOLOOBBDetector detector(modelPath, labelsPath, isGPU);
			auto boxes = detector.detect(image);
			detector.drawDetections(image, boxes);
		}
		else if (task_type == "Classify") {

			if (ui.comboType_4->currentText().QString::toStdString() == "GPU")
			{
				isGPU = true;
			}
			else if (ui.comboType_4->currentText().QString::toStdString() == "CPU")
			{
				isGPU = false;
			}
			yolos::cls::YOLOClassifier classifier(modelPath, labelsPath, isGPU);
			auto result = classifier.classify(image);
			std::cout << "Predicted: " << result.className << " (" << result.confidence * 100 << "%)" << std::endl;
			classifier.drawResult(image, result);
		}
		else if (task_type == "Segment") {

			if (ui.comboType_4->currentText().QString::toStdString() == "GPU")
			{
				isGPU = true;
			}
			else if (ui.comboType_4->currentText().QString::toStdString() == "CPU")
			{
				isGPU = false;
			}
			yolos::seg::YOLOSegDetector detector(modelPath, labelsPath, isGPU);
			auto segments = detector.segment(image);
			detector.drawSegmentations(image, segments, /*maskAlpha=*/0.5f);
		}
	}
	catch (const std::exception e) {
		qDebug() << "发生报错：" << e.what();
	}
        // Initialize the YOLO12 detector
	
	
	/*char* argv[] = { 
		"ONNXRuntime",
		task_type.c_str(),
		yolo_type.c_str(),
        device_type.c_str(),
		"FP32",
		labelsPath.c_str(),
	};
	Backend_Type backend;
	Task_Type task;
	Algo_Type algo;
	Device_Type device;
	Model_Type model;
	std::string model_path = modelPath;
	std::string images_path = imgList.QString::toStdString();

	try
	{
		backend = magic_enum::enum_cast<Backend_Type>(ONNXRuntime).value();
		task = magic_enum::enum_cast<Task_Type>(task_type).value();
		algo = magic_enum::enum_cast<Algo_Type>(yolo_type).value();
		device = magic_enum::enum_cast<Device_Type>(device_type).value();
		model = magic_enum::enum_cast<Model_Type>(FP32).value();
	}
	catch (const std::bad_optional_access& e)
	{
		std::cerr << "argv input error: " << e.what() << std::endl;
		return image;
	}

	std::unique_ptr<YOLO> yolo = CreateFactory::instance().create(backend, task);
	yolo->init(algo, device, model, model_path);
	yolo->infer(images_path, false, false, argv);
	yolo->release();*/



        // Display the annotated image
        //cv::imshow("YOLO12 Detections", image);
        //cv::waitKey(0); // Wait indefinitely until a key is pressed
		DWORD end_time = GetTickCount64();
        return image;

}
void frmClassifier::fullScreen()
{
	// 创建一个QLabel作为窗口
	QLabel* label = new QLabel("检测到您使用手机拍照行为异常");

	// 设置样式
	label->setAlignment(Qt::AlignCenter);
	label->setStyleSheet(
		"QLabel {"
		"  background-color: green;"
		"  color: white;"
		"  font-size: 48px;"
		"  font-weight: bold;"
		"  border: 5px solid white;"
		"  border-radius: 15px;"
		"}"
	);

	// 获取屏幕尺寸
	QScreen* screen = QGuiApplication::primaryScreen();
	QRect screenGeometry = screen->geometry();

	// 设置窗口属性
	label->setWindowFlags(
		Qt::FramelessWindowHint |
		Qt::WindowStaysOnTopHint |
		Qt::Tool |
		Qt::WindowTransparentForInput
	);

	// 设置窗口为全屏
	label->setGeometry(screenGeometry);

	// 调用Windows API确保覆盖任务栏
	HWND hwnd = (HWND)label->winId();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0,
		screenGeometry.width(), screenGeometry.height(),
		SWP_SHOWWINDOW);

	label->showFullScreen();
}
void frmClassifier::endFullScreen()
{
	// 获取所有顶层窗口
	QList<QWidget*> topLevelWidgets = QApplication::topLevelWidgets();
	// 遍历所有顶层窗口，查找并关闭全屏警告窗口
	for (QWidget* widget : topLevelWidgets) {
		if (QLabel* label = qobject_cast<QLabel*>(widget)) {
			if (label->text() == "检测到您使用手机拍照行为异常") {
				label->close();
				label->deleteLater();
			}
		}
	}
}
frmClassifier::frmClassifier(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/classifier.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽		
	connect(this, &frmClassifier::sig_ClassifierValue, view->item, &ImageItem::slot_ClassifierValue);
	connect(ui.comboType, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_CurrentIndexChanged(int)));
	connect(this, &frmClassifier::sigShowFullScreen, this, &frmClassifier::fullScreen);
	connect(this, &frmClassifier::sigEndFullScreen, this, &frmClassifier::endFullScreen);
	ui.comboType->setCurrentIndex(3);
	//初始化标题栏
	initTitleBar();
	imageSize = cv::Size(64, 64);
	svm = cv::ml::SVM::create();
	svm->setType(cv::ml::SVM::C_SVC);
	svm->setKernel(cv::ml::SVM::LINEAR);
	svm->setGamma(0.01);
	svm->setC(10.0);
	svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 10000, 1e-10));	
}

frmClassifier::~frmClassifier()
{
	this->deleteLater();
}

void frmClassifier::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/classifier.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmClassifier::paintEvent(QPaintEvent* event)
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

void frmClassifier::onButtonCloseClicked()
{
	this->close();
}

int frmClassifier::Execute(const QString toolname)
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

int frmClassifier::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		//GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = srcImage;
		QString type;
		bool state = PredictionImage(srcImage, type);
		GetToolBase()->m_Tools[tool_index].PublicDetect.Category = type;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		QString workflowName = GetToolName();
		if (workflowName == "YoloV13")
		{
			std::string modelpath = ui.txtLoadModel->text().QString::toStdString();
			std::string labelpath = ui.txtLabels->text().QString::toStdString();
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = GetYoloV13(modelpath, labelpath, srcImage, false, ui.comboType_2->currentText().QString::toStdString(), ui.comboType_3->currentText().QString::toStdString(), ui.comboType_4->currentText().QString::toStdString());
		}
		
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmClassifier::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmClassifier::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmClassifier::InitSetToolData(const QVariant data)
{
	try
	{
		InitClassifierData init_data;
		init_data = data.value<InitClassifierData>();
		for (int m = 0; m < init_data.type_key.count(); m++)
		{			
			typeNames.insert(init_data.type_key[m], init_data.type_names[m]);
		}			
		QString str = init_data.file_model;
		QFile file(str);
		if (file.exists())
		{
			svm = cv::ml::SVM::load(str.toStdString().c_str());
		}		
		return 0;
	}
	catch (...)
	{		
		return -1;
	}
}

QVariant frmClassifier::InitGetToolData()
{
	InitClassifierData init_data;
	QList<int> text_keys;
	text_keys.reserve(100);
	text_keys.clear();
	text_keys = typeNames.uniqueKeys();
	for (int m = 0; m < text_keys.count(); m++)
	{
		int key = text_keys[m];
		init_data.type_key.append(key);		
		init_data.type_names.append(typeNames.value(key));
	}
	init_data.file_model = ui.txtLoadModel->text();
	return QVariant::fromValue(init_data);
}


void frmClassifier::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QString msg = GetToolBase()->m_Tools[tool_index].PublicDetect.Category;
	emit sig_ClassifierValue(msg);
	std::string modelpath = ui.txtLoadModel->text().QString::toStdString();
	std::string labelpath = ui.txtLabels->text().QString::toStdString();
	QImage img(Mat2QImage(srcImage));//GetYoloV13(modelpath, labelpath, srcImage, false)
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmClassifier::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmClassifier::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmClassifier::on_btnLabels_clicked()
{
	QString filter = "Names Files (*.names)";
	QString dirPath = QFileDialog::getOpenFileName(this, tr("打开图像标签文件"), QDir::currentPath() + "/Parameters/Model/", filter);
	if (!dirPath.isEmpty())
	{
		imgLabels = dirPath;
		ui.txtLabels->setText(dirPath);
	}
}

void frmClassifier::on_btnList_clicked()
{
	QString dirPath = QFileDialog::getOpenFileName(this, tr("打开图像列表文件"), QDir::currentPath() + "/Parameters/Model/", "*.txt");
	if (false == dirPath.isEmpty())
	{
		imgList = dirPath;
		ui.txtList->setText(dirPath);
	}
}

void frmClassifier::on_btnSaveModel_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("保存模型文件"), QDir::currentPath() + "/Parameters/Model/", tr("Config Files (*.onnx)"));
	if (!fileName.isNull())
	{
		imgSaveModel = fileName;
		ui.txtSaveModel->setText(fileName);
	}
}

void frmClassifier::on_btnTrainModel_clicked()
{
	TrainModel(imgLabels, imgList, imgSaveModel);
}

void frmClassifier::on_btnLoadModel_clicked()
{
	QString filter;
	// 当选择 YOLOv4 时，允许选择 .weights 或 .onnx；否则仅允许 .onnx
	if (ui.comboType_3->currentText() == "YOLOv4") {
		filter = tr("模型文件 (*.weights *.onnx);;Weights Files (*.weights);;ONNX Files (*.onnx)");
	}
	else {
		filter = tr("ONNX Files (*.onnx)");
	}

	QString dirPath = QFileDialog::getOpenFileName(this, tr("打开模型文件"), QDir::currentPath() + "/Parameters/Model/", filter);
	if (!dirPath.isEmpty())
	{
		imgLoadModel = dirPath;
		QString msg = tr("Open the model to complete...");
		emit sig_ClassifierValue(msg);
		ui.txtLoadModel->setText(dirPath);
	}
}

void frmClassifier::slot_CurrentIndexChanged(int index)
{	
	typeNames.clear();
	ui.comboTypeBuf->clear();
	switch (index) {
	case 0:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		break;
	case 1:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		break;
	case 2:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		break;
	case 3:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		break;
	case 4:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		break;
	case 5:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		break;
	case 6:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		break;
	case 7:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		break;
	case 8:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		break;
	case 9:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		ui.comboTypeBuf->addItem("第11种类别名称");
		break;
	case 10:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		ui.comboTypeBuf->addItem("第11种类别名称");
		ui.comboTypeBuf->addItem("第12种类别名称");
		break;
	case 11:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		ui.comboTypeBuf->addItem("第11种类别名称");
		ui.comboTypeBuf->addItem("第12种类别名称");
		ui.comboTypeBuf->addItem("第13种类别名称");
		break;	
	case 12:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		ui.comboTypeBuf->addItem("第11种类别名称");
		ui.comboTypeBuf->addItem("第12种类别名称");
		ui.comboTypeBuf->addItem("第13种类别名称");
		ui.comboTypeBuf->addItem("第14种类别名称");
		break;
	case 13:
		ui.comboTypeBuf->addItem("第1种类别名称");
		ui.comboTypeBuf->addItem("第2种类别名称");
		ui.comboTypeBuf->addItem("第3种类别名称");
		ui.comboTypeBuf->addItem("第4种类别名称");
		ui.comboTypeBuf->addItem("第5种类别名称");
		ui.comboTypeBuf->addItem("第6种类别名称");
		ui.comboTypeBuf->addItem("第7种类别名称");
		ui.comboTypeBuf->addItem("第8种类别名称");
		ui.comboTypeBuf->addItem("第9种类别名称");
		ui.comboTypeBuf->addItem("第10种类别名称");
		ui.comboTypeBuf->addItem("第11种类别名称");
		ui.comboTypeBuf->addItem("第12种类别名称");
		ui.comboTypeBuf->addItem("第13种类别名称");
		ui.comboTypeBuf->addItem("第14种类别名称");
		ui.comboTypeBuf->addItem("第15种类别名称");
		break;
	}
}

void frmClassifier::on_comboTypeBuf_currentIndexChanged(int)
{	
	ui.txtTypeName->clear();
}

void frmClassifier::on_btnWrite_clicked()
{	
	switch (ui.comboTypeBuf->currentIndex()) {
	case 0:		
		typeNames.insert(0, ui.txtTypeName->text());
		emit sig_ClassifierValue("第1种类别写入完成...");
		break;
	case 1:		
		typeNames.insert(1, ui.txtTypeName->text());
		emit sig_ClassifierValue("第2种类别写入完成...");
		break;
	case 2:		
		typeNames.insert(2, ui.txtTypeName->text());
		emit sig_ClassifierValue("第3种类别写入完成...");
		break;
	case 3:		
		typeNames.insert(3, ui.txtTypeName->text());
		emit sig_ClassifierValue("第4种类别写入完成...");
		break;
	case 4:		
		typeNames.insert(4, ui.txtTypeName->text());
		emit sig_ClassifierValue("第5种类别写入完成...");
		break;
	case 5:
		typeNames.insert(5, ui.txtTypeName->text());
		emit sig_ClassifierValue("第6种类别写入完成...");
		break;
	case 6:
		typeNames.insert(6, ui.txtTypeName->text());
		emit sig_ClassifierValue("第7种类别写入完成...");
		break;
	case 7:
		typeNames.insert(7, ui.txtTypeName->text());
		emit sig_ClassifierValue("第8种类别写入完成...");
		break;
	case 8:
		typeNames.insert(8, ui.txtTypeName->text());
		emit sig_ClassifierValue("第9种类别写入完成...");
		break;
	case 9:
		typeNames.insert(9, ui.txtTypeName->text());
		emit sig_ClassifierValue("第10种类别写入完成...");
		break;
	case 10:
		typeNames.insert(10, ui.txtTypeName->text());
		emit sig_ClassifierValue("第11种类别写入完成...");
		break;
	case 11:
		typeNames.insert(11, ui.txtTypeName->text());
		emit sig_ClassifierValue("第12种类别写入完成...");
		break;
	case 12:
		typeNames.insert(12, ui.txtTypeName->text());
		emit sig_ClassifierValue("第13种类别写入完成...");
		break;
	case 13:
		typeNames.insert(13, ui.txtTypeName->text());
		emit sig_ClassifierValue("第14种类别写入完成...");
		break;
	case 14:
		typeNames.insert(14, ui.txtTypeName->text());
		emit sig_ClassifierValue("第15种类别写入完成...");
		break;
	}	
}

void frmClassifier::coumputeHog(const cv::Mat& src, vector<float>& descriptors)
{
	cv::HOGDescriptor myHog = cv::HOGDescriptor(imageSize, cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9);
	myHog.compute(src.clone(), descriptors, cv::Size(1, 1), cv::Size(0, 0));
}

bool frmClassifier::TrainModel(const QString imgLabels, const QString imgList, const QString imgSaveModel)
{
	try
	{
		ifstream inLabels(imgLabels.toStdString()), inImages(imgList.toStdString());
		vecImages.reserve(30000);
		vecImages.clear();
		vecLabels.reserve(30000);
		vecLabels.clear();
		vecDescriptors.reserve(30000);
		vecDescriptors.clear();
		while ((inImages >> imageName) && (inLabels >> imageLabel))
		{
			cv::Mat src = cv::imread(imageName, 0);
			cv::resize(src, src, imageSize);
			vecImages.push_back(src);
			vecLabels.push_back(imageLabel);
		}
		inLabels.close();
		inImages.close();
		cv::Mat dataDescriptors;
		cv::Mat dataResponse = (cv::Mat)vecLabels;
		for (size_t i = 0; i < vecImages.size(); i++)
		{
			cv::Mat src = vecImages[i];
			cv::Mat tempRow;
			coumputeHog(src, vecDescriptors);
			if (i == 0)
			{
				dataDescriptors = cv::Mat::zeros(vecImages.size(), vecDescriptors.size(), CV_32FC1);
			}
			tempRow = ((cv::Mat)vecDescriptors).t();
			tempRow.row(0).copyTo(dataDescriptors.row(i));
		}
		svm->train(dataDescriptors, cv::ml::SampleTypes::ROW_SAMPLE, dataResponse);
		svm->save(imgSaveModel.toStdString().c_str());
		QString msg = "Model training completed...";
		emit sig_ClassifierValue(msg);
		return true;
	}
	catch (...)
	{
		emit sig_ClassifierValue(QString());
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "训练模型异常！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return false;
	}
}

bool frmClassifier::PredictionImage(const cv::Mat src, QString& type)
{
	try
	{
		cv::Mat dstImage;
		cv::resize(src, dstImage, imageSize);
		vector<float> imageDescriptor;
		imageDescriptor.reserve(1000);
		imageDescriptor.clear();
		coumputeHog(dstImage, imageDescriptor);
		cv::Mat testDescriptor = cv::Mat::zeros(1, imageDescriptor.size(), CV_32FC1);
		for (size_t i = 0; i < imageDescriptor.size(); i++)
		{
			testDescriptor.at<float>(0, i) = imageDescriptor[i];
		}
		cv::Mat resultDescriptor;
		
		float label = svm->predict(testDescriptor);		
		switch (int(label))
		{
		case 1:
			type = typeNames[0];
			break;
		case 2:
			type = typeNames[1];
			break;
		case 3:
			type = typeNames[2];
			break;
		case 4:
			type = typeNames[3];
			break;
		case 5:
			type = typeNames[4];
			break;
		case 6:
			type = typeNames[5];
			break;
		case 7:
			type = typeNames[6];
			break;
		case 8:
			type = typeNames[7];
			break;
		case 9:
			type = typeNames[8];
			break;
		case 10:
			type = typeNames[9];
			break;
		case 11:
			type = typeNames[10];
			break;
		case 12:
			type = typeNames[11];
			break;
		case 13:
			type = typeNames[12];
			break;
		case 14:
			type = typeNames[13];
			break;
		case 15:
			type = typeNames[14];
			break;
		}		
		return true;
	}
	catch (...)
	{		
		return false;
	}
}

QImage frmClassifier::Mat2QImage(const cv::Mat& mat)
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
