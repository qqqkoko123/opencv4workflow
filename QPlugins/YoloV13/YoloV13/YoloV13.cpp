//#include "YoloV13.h"
//
//
//// Include necessary headers
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <string>
//#include "YOLO12.hpp" 
//#include <Windows.h>
//
////YoloV13::YoloV13(QWidget *parent)
////    : QWidget(parent)
////{
////
////        // Configuration parameters
////        const std::string labelsPath = "coco.names";       // Path to class labels
////        const std::string modelPath = "yolov13l.onnx";     // Path to YOLO12 model
////        const std::string imagePath = "data/dog.jpg";           // Path to input image
////        bool isGPU = false;                                           // Set to false for CPU processing
////
////        // Initialize the YOLO12 detector
////        YOLO12Detector detector(modelPath, labelsPath, isGPU);
////
////        while (1)
////        {
////            DWORD start_time = GetTickCount();
////
////            // Load an image
////            cv::Mat image = cv::imread(imagePath);
////
////            // Perform object detection to get bboxs
////            std::vector<Detection> detections = detector.detect(image);
////
////            // Draw bounding boxes on the image
////            detector.drawBoundingBoxMask(image, detections);
////
////            DWORD end_time = GetTickCount();
////            printf("The run time is:%dms\n", end_time - start_time);
////        }
////
////
////        // Display the annotated image
////        //cv::imshow("YOLO12 Detections", image);
////        cv::waitKey(0); // Wait indefinitely until a key is pressed
////
////        return;
////
////}
//
//#include "YoloV13.h"
//#include <QFileDialog>
//#include <QMessageBox>
//#include <QDesktopWidget>
//#include <QThread>
//#include <QElapsedTimer>
//
//
//Q_INTERFACES(Toolnterface2)
//Q_PLUGIN_METADATA(IID MainInterface_iid)
//
////QDialog* showDialog(QString toolName, QToolBase2* toolBase, QWidget* parent)
////{
////	YoloV13* ss = new YoloV13(toolName, toolBase, parent);
////	return ss;
////}
//Q_DECL_EXPORT QDialog* showDialog(QString toolName, QToolBase2* toolBase, QWidget* parent)
//{
//	YoloV13* ss = new YoloV13(toolName, toolBase, parent);
//	return ss;
//}
//int ShowFormState()
//{
//	return QConfig2::nFormState;
//}
//
//void SetFormState()
//{
//	QConfig2::nFormState = 0;
//}
//
//
//YoloV13::YoloV13(QString toolName, QToolBase2* toolBase, QWidget* parent)
//	: Toolnterface2(toolName, toolBase, parent)
//{
//	ui.setupUi(this);
//	toolTitleName = toolName;
//	//FramelessWindowHint�������ô���ȥ���߿�
//	//WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����
//	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
//	//���ô�������Ļ�м�λ��
//	QDesktopWidget* desktop = QApplication::desktop();
//	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
//	//���ô��ڱ���͸��
//	setAttribute(Qt::WA_TranslucentBackground);
//	this->setWindowIcon(QIcon(":/resource/image_source.png"));
//	//�����ź����
//	connect(this, SIGNAL(sig_Message()), this, SLOT(slot_Message()));
//	connect(this, SIGNAL(sig_PathMessage()), this, SLOT(slot_PathMessage()));
//	//��ʼ��������
//	initTitleBar();
//	//ͼ����ʾ
//	view = new QGraphicsViews;
//	ui.imageLayout->addWidget(view);
//	//ѡ�ť
//	btnGroupRadio = new QButtonGroup(this);
//	btnGroupRadio->addButton(ui.radioImage, 0);
//	connect(ui.radioImage, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
//	ui.radioImage->click();
//	btnGroupRadio->addButton(ui.radioFolder, 1);
//	connect(ui.radioFolder, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
//	btnGroupRadio->addButton(ui.radioCamera, 2);
//	connect(ui.radioCamera, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
//	btnCalibGroupRadio = new QButtonGroup(this);
//	btnCalibGroupRadio->addButton(ui.radioLinkParam, 0);
//	connect(ui.radioLinkParam, SIGNAL(toggled(bool)), this, SLOT(onCalibRadioClick(bool)));
//	ui.radioLinkParam->click();
//	btnCalibGroupRadio->addButton(ui.radioCalibFile, 1);
//	connect(ui.radioCalibFile, SIGNAL(toggled(bool)), this, SLOT(onCalibRadioClick(bool)));
//	imgIndex = 0;
//}
//
//YoloV13::~YoloV13()
//{
//	this->deleteLater();
//}
//
//YoloV13::YoloV13(QWidget* parent)
//{
//
//
//}
//
//void YoloV13::initTitleBar()
//{
//	m_titleBar = new MyTitleBar(this);
//	m_titleBar->move(0, 0);
//	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
//	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
//	m_titleBar->setTitleIcon(":/resource/image_source.png");
//	m_titleBar->setTitleContent(toolTitleName);
//	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
//	m_titleBar->setTitleWidth(this->width());
//}
//
//void YoloV13::paintEvent(QPaintEvent* event)
//{
//	//���ñ���ɫ
//	QPainter painter(this);
//	QPainterPath pathBack;
//	pathBack.setFillRule(Qt::WindingFill);
//	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
//	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
//	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
//	return QWidget::paintEvent(event);
//}
//
//void YoloV13::onButtonCloseClicked()
//{
//	this->close();
//}
//
//void YoloV13::onRadioClick(bool state)
//{
//	switch (btnGroupRadio->checkedId())
//	{
//	case 0:
//		ui.groupImage->setEnabled(true);
//		ui.groupFolder->setEnabled(false);
//		ui.groupCamera->setEnabled(false);
//		break;
//	case 1:
//		ui.groupImage->setEnabled(false);
//		ui.groupFolder->setEnabled(true);
//		ui.groupCamera->setEnabled(false);
//		break;
//	case 2:
//		ui.groupImage->setEnabled(false);
//		ui.groupFolder->setEnabled(false);
//		ui.groupCamera->setEnabled(true);
//		break;
//	}
//}
//
//void YoloV13::onCalibRadioClick(bool state)
//{
//	switch (btnCalibGroupRadio->checkedId())
//	{
//	case 0:
//		init_param_buf = 0;
//		ui.groupC->setEnabled(true);
//		ui.groupC2->setEnabled(false);
//		break;
//	case 1:
//		init_param_buf = 0;
//		ui.groupC->setEnabled(false);
//		ui.groupC2->setEnabled(true);
//		break;
//	}
//}
//
//int YoloV13::Execute(const QString toolname)
//{
//	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
//	{
//		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
//		{
//			//�����ڹ��������е�����
//			tool_index = i;
//		}
//	}
//	int result = 0;
//	switch (btnGroupRadio->checkedId())
//	{
//	case 0:
//		result = RunToolPro(ui.txtImagePath->text(), 0);
//		break;
//	case 1:
//		result = RunToolPro(ui.txtFolderPath->text(), 1);
//		break;
//	case 2:
//		result = RunToolPro(ui.txtCalibPath->text(), 2);
//		break;
//	}
//	if (-1 == result)
//	{
//		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//		return -1;
//	}
//	else if (-2 == result)
//	{
//		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//		return -2;
//	}
//	GetToolBase()->m_Tools[tool_index].PublicToolName = toolname;
//	GetToolBase()->m_Tools[tool_index].PublicImage.InputImage = srcImage;
//	GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
//	GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
//	return 0;
//}
//
//int YoloV13::RunToolPro(QString image_path, const int index)
//{
//	QDir dir(image_path);
//	strs.reserve(100);
//	mImgNames.reserve(10000);
//	mImgNames.clear();
//	switch (index)
//	{
//	case 0:
//		srcImage = cv::imread(image_path.toLocal8Bit().data(), cv::IMREAD_UNCHANGED);
//		if (true == srcImage.empty())
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_Message();
//			return -2;
//		}
//		strs.clear();
//		strs = image_path.split(".");
//		if (strs.size() != 1)
//		{
//			int i_type = strs.size() - 1;
//			if (strs[i_type] == "bmp")
//			{
//				if (srcImage.cols <= 1280)
//				{
//					QThread::msleep(15);
//				}
//				else if (srcImage.cols > 1280 && srcImage.cols < 2048)
//				{
//					QThread::msleep(30);
//				}
//				else if (srcImage.cols >= 2048 && srcImage.cols < 4000)
//				{
//					QThread::msleep(50);
//				}
//				else if (srcImage.cols >= 4000 && srcImage.cols < 6000)
//				{
//					QThread::msleep(80);
//				}
//				else if (srcImage.cols >= 6000 && srcImage.cols < 20000)
//				{
//					QThread::msleep(150);
//				}
//			}
//		}
//		//ʹ�û���궨У��ͼ��
//		if (ui.checkUseCalib->isChecked() == true)
//		{
//			if (ui.radioLinkParam->isChecked() == true)
//			{
//				bool link_state = false;
//				param_index = 0;
//				QString str = ui.txtLinkCameraMatrix->text();
//				strs.reserve(100);
//				strs.clear();
//				strs = str.split(".");
//				if (strs.size() == 1)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -1;
//				}
//				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
//				{
//					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
//					{
//						//��ȡ�Ĳ����ڹ��������е�����
//						param_index = i;
//						link_state = true;
//					}
//				}
//				if (link_state == false)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -2;
//				}
//				cv::undistort(srcImage, dstImage, GetToolBase()->m_Tools[param_index].PublicCalib.CameraMatrix, GetToolBase()->m_Tools[param_index].PublicCalib.DistCoeffs);
//			}
//			else if (ui.radioCalibFile->isChecked() == true)
//			{
//				if (init_param_buf == 0)
//				{
//					cv::FileStorage fs(ui.txtCalibPath->text().toStdString(), cv::FileStorage::READ);
//					fs["cameraMatrix"] >> cameraMatrixRead;
//					fs["distCoeffs"] >> distCoeffsRead;
//					fs.release();
//					init_param_buf = 1;
//				}
//				else
//				{
//					cv::undistort(srcImage, dstImage, cameraMatrixRead, distCoeffsRead);
//				}
//			}
//		}
//		else
//		{
//			srcImage.copyTo(dstImage);
//		}
//		return 0;
//		break;
//	case 1:
//		if (image_path.isEmpty())
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_PathMessage();
//			return -2;
//		}
//		//��ȡ�����ļ���		
//		image_path = dir.fromNativeSeparators(image_path);//  "\\"תΪ"/" 		
//		if (!dir.exists())
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_PathMessage();
//			return -1;
//		}
//		dir.setFilter(QDir::Files);
//		dir.setSorting(QDir::Name);
//		dir.setNameFilters(QString("*.jpg;*.png;*.jpeg;*.bmp").split(";"));
//		mImgNames = dir.entryList();
//		if (mImgNames.size() == 0)
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_PathMessage();
//			return -1;
//		}
//		srcImage = cv::imread((image_path + "/" + mImgNames[imgIndex]).toLocal8Bit().data(), cv::IMREAD_UNCHANGED);
//		imgIndex += 1;
//		if (imgIndex == mImgNames.size())
//		{
//			imgIndex = 0;
//		}
//		if (true == srcImage.empty())
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_Message();
//			return -1;
//		}
//		strs.clear();
//		strs = (image_path + "/" + mImgNames[imgIndex]).split(".");
//		if (strs.size() != 1)
//		{
//			int i_type = strs.size() - 1;
//			if (strs[i_type] == "bmp")
//			{
//				if (srcImage.cols <= 1280)
//				{
//					QThread::msleep(15);
//				}
//				else if (srcImage.cols > 1280 && srcImage.cols < 2048)
//				{
//					QThread::msleep(30);
//				}
//				else if (srcImage.cols >= 2048 && srcImage.cols < 4000)
//				{
//					QThread::msleep(50);
//				}
//				else if (srcImage.cols >= 4000 && srcImage.cols < 6000)
//				{
//					QThread::msleep(80);
//				}
//				else if (srcImage.cols >= 6000 && srcImage.cols < 20000)
//				{
//					QThread::msleep(150);
//				}
//			}
//		}
//		//ʹ�û���궨У��ͼ��
//		if (ui.checkUseCalib->isChecked() == true)
//		{
//			if (ui.radioLinkParam->isChecked() == true)
//			{
//				bool link_state = false;
//				param_index = 0;
//				QString str = ui.txtLinkCameraMatrix->text();
//				strs.clear();
//				strs = str.split(".");
//				if (strs.size() == 1)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -1;
//				}
//				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
//				{
//					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
//					{
//						//��ȡ�Ĳ����ڹ��������е�����
//						param_index = i;
//						link_state = true;
//					}
//				}
//				if (link_state == false)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -2;
//				}
//				cv::undistort(srcImage, dstImage, GetToolBase()->m_Tools[param_index].PublicCalib.CameraMatrix, GetToolBase()->m_Tools[param_index].PublicCalib.DistCoeffs);
//			}
//			else if (ui.radioCalibFile->isChecked() == true)
//			{
//				if (init_param_buf == 0)
//				{
//					cv::FileStorage fs(ui.txtCalibPath->text().toStdString(), cv::FileStorage::READ);
//					fs["cameraMatrix"] >> cameraMatrixRead;
//					fs["distCoeffs"] >> distCoeffsRead;
//					fs.release();
//					cv::undistort(srcImage, dstImage, cameraMatrixRead, distCoeffsRead);
//					init_param_buf = 1;
//				}
//				else
//				{
//					cv::undistort(srcImage, dstImage, cameraMatrixRead, distCoeffsRead);
//				}
//			}
//		}
//		else
//		{
//			srcImage.copyTo(dstImage);
//		}
//		return 0;
//		break;
//	case 2:
//		//���ȡ��		
//		if (cam_state == 1)
//		{
//			keys.reserve(300);
//			keys.clear();
//			keys = gvariable.camera_variable_link.uniqueKeys();
//			for (int p = 0; p < keys.length(); p++)
//			{
//				QString key = keys[p];
//				int cam_count = 0;
//				if (gvariable.camera_variable_link.value(key).camera_type == "MindVision")
//				{
//				loop:
//					CameraSoftTrigger(mindvision_haldle);  //ִ��һ������					
//					if (CameraGetImageBuffer(mindvision_haldle, &sFrameInfo_A, &pbyBuffer_A, time_out) == CAMERA_STATUS_SUCCESS)
//					{
//						//����õ����ԭʼ���ͼ�����ݽ��д������ӱ��Ͷȡ���ɫ�����У��������ȴ���Ч�������õ�RGB888��ʽ��ͼ������
//						status_A = CameraImageProcess(mindvision_haldle, pbyBuffer_A, mindvision_framebuffer, &sFrameInfo_A);
//						//�ֱ��ʸı䣬��ˢ�±���
//						if (m_sFrInfo_A.iWidth != sFrameInfo_A.iWidth || m_sFrInfo_A.iHeight != sFrameInfo_A.iHeight)
//						{
//							m_sFrInfo_A.iWidth = sFrameInfo_A.iWidth;
//							m_sFrInfo_A.iHeight = sFrameInfo_A.iHeight;
//						}
//						if (status_A == CAMERA_STATUS_SUCCESS)
//						{
//							//����SDK��װ�õ���ʾ�ӿ�����ʾͼ��
//							CameraImageOverlay(mindvision_haldle, mindvision_framebuffer, &sFrameInfo_A);
//							//����SDK���������Ĭ���Ǵӵ׵�����ת��ΪOpenCVͼƬ��Ҫ��һ�´�ֱ����
//							CameraFlipFrameBuffer(mindvision_framebuffer, &sFrameInfo_A, 1);
//							srcImage = cv::Mat(cv::Size(sFrameInfo_A.iWidth, sFrameInfo_A.iHeight), sFrameInfo_A.uiMediaType == CAMERA_MEDIA_TYPE_MONO8 ? CV_8UC1 : CV_8UC3, mindvision_framebuffer);
//						}
//						//�ڳɹ�����CameraGetImageBuffer�󣬱������CameraReleaseImageBuffer���ͷŻ�õ�buffer		
//						CameraReleaseImageBuffer(mindvision_haldle, pbyBuffer_A);
//						memcpy(&m_sFrInfo_A, &sFrameInfo_A, sizeof(tSdkFrameHead));
//						break;
//					}
//					else
//					{
//						++cam_count;
//						if (cam_count > 20)
//						{
//							GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//							return -2;
//						}
//						else
//						{
//							QElapsedTimer t;
//							t.start();
//							while (t.elapsed() < 50);
//							goto loop;
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//			return -1;
//		}
//		if (choose_num == 1 && cam_state == 0)
//		{
//			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//			return -1;
//		}
//		if (true == srcImage.empty())
//		{
//			//���߳��в���GUIҪ���ź����
//			emit sig_Message();
//			return -2;
//		}
//		//ʹ�û���궨У��ͼ��
//		if (ui.checkUseCalib->isChecked() == true)
//		{
//			if (ui.radioLinkParam->isChecked() == true)
//			{
//				bool link_state = false;
//				param_index = 0;
//				QString str = ui.txtLinkCameraMatrix->text();
//				strs.reserve(100);
//				strs.clear();
//				strs = str.split(".");
//				if (strs.size() == 1)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -1;
//				}
//				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
//				{
//					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
//					{
//						//��ȡ�Ĳ����ڹ��������е�����
//						param_index = i;
//						link_state = true;
//					}
//				}
//				if (link_state == false)
//				{
//					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
//					return -2;
//				}
//				cv::undistort(srcImage, dstImage, GetToolBase()->m_Tools[param_index].PublicCalib.CameraMatrix, GetToolBase()->m_Tools[param_index].PublicCalib.DistCoeffs);
//			}
//			else if (ui.radioCalibFile->isChecked() == true)
//			{
//				if (init_param_buf == 0)
//				{
//					cv::FileStorage fs(ui.txtCalibPath->text().toStdString(), cv::FileStorage::READ);
//					fs["cameraMatrix"] >> cameraMatrixRead;
//					fs["distCoeffs"] >> distCoeffsRead;
//					fs.release();
//					init_param_buf = 1;
//				}
//				else
//				{
//					cv::undistort(srcImage, dstImage, cameraMatrixRead, distCoeffsRead);
//				}
//			}
//		}
//		else
//		{
//			srcImage.copyTo(dstImage);
//		}
//		return 0;
//		break;
//	}
//	return 0;
//}
//
//void YoloV13::slot_Message()
//{
//	QMessageBox::warning(this, "��ʾ", "����ͼ��ʧ�ܣ�", QMessageBox::Ok);
//	return;
//}
//
//void YoloV13::slot_PathMessage()
//{
//	QMessageBox::warning(this, "��ʾ", "����ͼ���ļ���ʧ�ܣ�", QMessageBox::Ok);
//	return;
//}
//
//int YoloV13::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable2::Global_Var2> variable_link)
//{
//	try
//	{
//		gvariable.global_variable_link = variable_link;
//		if (int_link == 1)
//		{
//			strs.clear();
//			strs = str_link.split(".");
//			if (strs.size() == 1 || strs[1] != "�ڲ�K")
//			{
//				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "����", "��������Ӵ���");
//				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
//				msgBox.exec();
//				return -1;
//			}
//			ui.txtLinkCameraMatrix->setText(str_link);
//		}
//		else if (int_link == 2)
//		{
//			strs.clear();
//			strs = str_link.split(".");
//			if (strs.size() == 1 || strs[1] != "����ϵ��")
//			{
//				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "����", "��������Ӵ���");
//				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
//				msgBox.exec();
//				return -1;
//			}
//			ui.txtLinkDistCoeffs->setText(str_link);
//		}
//		return 0;
//	}
//	catch (...)
//	{
//		return -1;
//	}
//}
//
//int YoloV13::ExecuteAllLink(const QMap<QString, gVariable2::Global_Var2> g_variable_link)
//{
//	try
//	{
//		gvariable.global_variable_link = g_variable_link;
//		return 0;
//	}
//	catch (...)
//	{
//		return -1;
//	}
//}
//
//int YoloV13::ExecuteCameraLink(const QMap<QString, gVariable2::Camera_Var2> camera_var_link)
//{
//	try
//	{
//		gvariable.camera_variable_link = camera_var_link;
//		if (choose_index >= 0)
//		{
//			cam_state = 0;
//			choose_num = 0;
//			keys.reserve(300);
//			keys.clear();
//			keys = gvariable.camera_variable_link.uniqueKeys();
//			if (keys.length() != ui.comboCamera->count())
//			{
//				choose_num = 1;
//				return -1;
//			}
//			for (int p = 0; p < keys.length(); p++)
//			{
//				QString key = keys[p];
//				if (gvariable.camera_variable_link.value(key).camera_type == "MindVision")
//				{
//					if (key == ui.comboCamera->itemText(choose_index))
//					{
//						mindvision_haldle = gvariable.camera_variable_link.value(key).mindvision_haldle_value;
//						mindvision_framebuffer = gvariable.camera_variable_link.value(key).mindvision_framebuffer_value;
//						time_out = gvariable.camera_variable_link.value(key).time_out;
//						cam_state = 1;
//						return 0;
//					}
//				}
//			}
//		}
//		return 0;
//	}
//	catch (...)
//	{
//		return -1;
//	}
//}
//
//int YoloV13::InitSetToolData(const QVariant data)
//{
//	try
//	{
//		InitImageSourceData init_data;
//		init_data = data.value<InitImageSourceData>();
//		ui.comboCamera->clear();
//		for (int i = 0; i < init_data.g_camera.count(); i++)
//		{
//			ui.comboCamera->addItem(init_data.g_camera[i]);
//		}
//		ui.comboCamera->setCurrentIndex(init_data.camera_index);
//		return 0;
//	}
//	catch (...)
//	{
//		return -1;
//	}
//}
//
//QVariant YoloV13::InitGetToolData()
//{
//	InitImageSourceData init_data;
//	init_data.camera_index = ui.comboCamera->currentIndex();
//	for (int i = 0; i < ui.comboCamera->count(); i++)
//	{
//		init_data.g_camera.append(ui.comboCamera->itemText(i));
//	}
//	return QVariant::fromValue(init_data);
//}
//
//void YoloV13::on_comboCamera_currentIndexChanged(int index)
//{
//	cam_state = 0;
//	keys.reserve(300);
//	keys.clear();
//	keys = gvariable.camera_variable_link.uniqueKeys();
//	for (int p = 0; p < keys.length(); p++)
//	{
//		QString key = keys[p];
//		if (gvariable.camera_variable_link.value(key).camera_type == "MindVision")
//		{
//			if (key == ui.comboCamera->itemText(index))
//			{
//				mindvision_haldle = gvariable.camera_variable_link.value(key).mindvision_haldle_value;
//				mindvision_framebuffer = gvariable.camera_variable_link.value(key).mindvision_framebuffer_value;
//				time_out = gvariable.camera_variable_link.value(key).time_out;
//				cam_state = 1;
//				choose_index = index;
//				return;
//			}
//		}
//	}
//}
//
//void YoloV13::on_btnLinkCameraMatrix_clicked()
//{
//	QConfig2::nFormState = 1;
//}
//
//void YoloV13::on_btnDelLinkCameraMatrix_clicked()
//{
//	ui.txtLinkCameraMatrix->clear();
//}
//
//void YoloV13::on_btnLinkDistCoeffs_clicked()
//{
//	QConfig2::nFormState = 2;
//}
//
//void YoloV13::on_btnDelLinkDistCoeffs_clicked()
//{
//	ui.txtLinkDistCoeffs->clear();
//}
//
//void YoloV13::on_btnSelectImage_clicked()
//{
//	QString path_C = QDir::currentPath();
//	QString dirPath = QFileDialog::getOpenFileName(this, tr("��ͼƬ"), path_C, "*.bmp *png *jpg *.jpeg");
//	if (false == dirPath.isEmpty())
//	{
//		ui.txtImagePath->setText(dirPath);
//	}
//}
//
//void YoloV13::on_btnSelectPath_clicked()
//{
//	QString path_C = QDir::currentPath();
//	QString dirPath = QFileDialog::getExistingDirectory(this, tr("��ͼƬ�ļ���"), path_C);
//	if (false == dirPath.isEmpty())
//	{
//		imgIndex = 0;
//		ui.txtFolderPath->setText(dirPath);
//	}
//}
//
//void YoloV13::on_btnSelectCalibPath_clicked()
//{
//	QString path_C = QDir::currentPath();
//	QString dirPath = QFileDialog::getOpenFileName(this, tr("�򿪱궨�ļ�"), path_C, "*.xml");
//	if (false == dirPath.isEmpty())
//	{
//		init_param_buf = 0;
//		ui.txtCalibPath->setText(dirPath);
//	}
//}
//
//void YoloV13::on_btnExecute_clicked()
//{
//	ui.btnExecute->setEnabled(false);
//	QApplication::processEvents();
//	Execute(GetToolName());
//	QImage img(Mat2QImage(dstImage));
//	view->DispImage(img);
//	ui.btnExecute->setEnabled(true);
//}
//
//void YoloV13::on_btnUpdata_clicked()
//{
//	ui.comboCamera->clear();
//	QList<QString> tool_keys;
//	tool_keys.reserve(100);
//	tool_keys.clear();
//	tool_keys = gvariable.camera_variable_link.uniqueKeys();
//	for (int i = 0; i < tool_keys.count(); i++)
//	{
//		QString key = tool_keys[i];
//		ui.comboCamera->addItem(key);
//	}
//}
//
//QImage YoloV13::Mat2QImage(const cv::Mat& mat)
//{
//	if (mat.empty())
//	{
//		return QImage();
//	}
//	if (mat.type() == CV_8UC1)
//	{
//		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
//		image.setColorCount(256);
//		for (int i = 0; i < 256; i++)
//		{
//			image.setColor(i, qRgb(i, i, i));
//		}
//		uchar* pSrc = mat.data;
//		for (int row = 0; row < mat.rows; row++)
//		{
//			uchar* pDest = image.scanLine(row);
//			memcpy(pDest, pSrc, mat.cols);
//			pSrc += mat.step;
//		}
//		return image;
//	}
//	else if (mat.type() == CV_8UC3)
//	{
//		const uchar* pSrc = (const uchar*)mat.data;
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
//		return image.rgbSwapped();
//	}
//	else if (mat.type() == CV_8UC4)
//	{
//		const uchar* pSrc = (const uchar*)mat.data;
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
//		return image.copy();
//	}
//	else
//	{
//		return QImage();
//	}
//}
//
////ȫ�ֱ�������
//int QConfig2::nFormState = 0;
//
////Q_DECL_EXPORT void YoloV13(QString toolName, QToolBase2* toolBase, QWidget* parent)
////{
////
////	return Q_DECL_EXPORT void();
////}
//
//
//#include "ImageSource.h"
#include "YoloV13.h"
#include "frmClassifier.h"

YoloV13::YoloV13()
{
   //YoloV13

	//QLibrary mylib("./Plugins/YoloV13.dll");   //�������õ���dll�ļ�
	//if (mylib.load())    //�ж��Ƿ���ȷ����
	//{
	//	QFunctionPointer getYoloV13 = mylib.resolve("ShowFormState");
	//	QFunctionPointer setYoloV13 = mylib.resolve("SetFormState");
	//	Funs open = (Funs)mylib.resolve("showDialog");
	//	if (open)
	//	{
	//		int nYoloV13State_buf = 1;
	//		Toolnterface2* frmPage = open("YoloV13", QConfig::ToolBase[0]);
	//		frmPage->setObjectName("YoloV13");
	//	}
	//}
	//QLibrary mylib("./Plugins/YoloV13.dll");   //�������õ���dll�ļ�
	//if (mylib.load())    //�ж��Ƿ���ȷ����
	//{
	//	Funs open = (Funs)mylib.resolve("showDialog");
	//	if (open)
	//	{
	//		Toolnterface2* frmPage = open("YoloV13", QConfig::ToolBase[0]);
	//		frmPage->setObjectName("YoloV13");
	//	}
	//}
}

QString YoloV13::name()
{
    return "YoloV13";
}

QString YoloV13::information()
{
    return "Ŀ����";
}

QDialog* showDialog(QString toolName, QToolBase* toolBase)
{
	frmClassifier* ss = new frmClassifier(toolName, toolBase);
    return ss;
}

int ShowFormState()
{
    return QConfig::nFormState;
}

void SetFormState()
{
    QConfig::nFormState = 0;
}
