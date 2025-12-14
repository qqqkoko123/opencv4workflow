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
#include <Windows.h>
#include <QScreen>
cv::Mat frmClassifier::GetYoloV13(std::string modelPath, std::string labelsPath, cv::Mat image, bool isGPU)
{

        // Configuration parameters
        //const std::string labelsPath = "coco.names";       // Path to class labels
        //const std::string modelPath = "yolov13l.onnx";     // Path to YOLO12 model
        //const std::string imagePath = "data/dog.jpg";           // Path to input image
        //bool isGPU = false;                                           // Set to false for CPU processing

        // Initialize the YOLO12 detector
	try 
	{
		YOLO12Detector detector(modelPath, labelsPath, isGPU);


		DWORD start_time = GetTickCount64();

		// Load an image
		/*cv::Mat image = cv::imread(imagePath);*/

		// Perform object detection to get bboxs
		std::vector<Detection> detections = detector.detect(image);

		// Draw bounding boxes on the image
		detector.drawBoundingBoxMask(image, detections);
		bool isFullScreen = false;
		if (detections.size() > 0) {
			for (int i = 0; i < detections.size(); i++)
			{
				//检测到手机拍照立刻全屏遮挡
				if(QString::fromStdString(utils::getClassNames(labelsPath)[detections[i].classId]) == "phone")
				{
					//全屏遮挡
					emit sigShowFullScreen();
					isFullScreen = true;
					break;
				}
			}
			GetToolBase()->m_Tools[tool_index].PublicDetect.Category = QString::fromStdString(utils::getClassNames(labelsPath)[detections[0].classId]);
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		}
		if (!isFullScreen)
		{
			//撤销全屏遮挡
			emit sigEndFullScreen();
		}
		DWORD end_time = GetTickCount64();
	}
	catch (const std::exception e) {
		qDebug() << "发生报错：" << e.what();
	}
        



        // Display the annotated image
        //cv::imshow("YOLO12 Detections", image);
        //cv::waitKey(0); // Wait indefinitely until a key is pressed

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
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = GetYoloV13(modelpath, labelpath, srcImage, false);
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
	QString dirPath = QFileDialog::getOpenFileName(this, tr("打开图像标签文件"), QDir::currentPath() + "/Parameters/Model/", "*.names");
	if (false == dirPath.isEmpty())
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
	QString dirPath = QFileDialog::getOpenFileName(this, tr("打开模型文件"), QDir::currentPath() + "/Parameters/Model/", "*.onnx");
	if (false == dirPath.isEmpty())
	{
		imgLoadModel = dirPath;
		//svm = cv::ml::SVM::load(dirPath.toStdString().c_str());
		QString msg = "Open the model to complete...";
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
