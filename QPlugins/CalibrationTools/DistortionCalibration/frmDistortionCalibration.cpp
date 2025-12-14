#include "frmDistortionCalibration.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <sstream>
#include <fstream>
#include <QGraphicsOpacityEffect>

frmDistortionCalibration::frmDistortionCalibration(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/distortion_calib.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽	
	connect(this, SIGNAL(sig_PathMessage()), this, SLOT(slot_PathMessage()));		
	connect(this, SIGNAL(sig_ErrorMessage()), this, SLOT(slot_ErrorMessage()));
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmDistortionCalibration::~frmDistortionCalibration()
{
	this->deleteLater();
}

void frmDistortionCalibration::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/distortion_calib.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmDistortionCalibration::paintEvent(QPaintEvent* event)
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

void frmDistortionCalibration::onButtonCloseClicked()
{
	this->close();
}

int frmDistortionCalibration::Execute(const QString toolname)
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

int frmDistortionCalibration::RunToolPro()
{
	try
	{
		QDir dir(imgsPath);
		if (imgsPath.isEmpty())
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;
		}
		//获取所有文件名		
		imgsPathBuf = dir.fromNativeSeparators(imgsPath);//  "\\"转为"/" 	
		imgsPathBuf = imgsPathBuf + "/";
		if (!dir.exists())
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;
		}
		dir.setFilter(QDir::Files);
		dir.setSorting(QDir::Name);
		dir.setNameFilters(QString("*.jpg;*.png;*.bmp;*.jpeg").split(";"));
		mImgNames.reserve(1000);
		mImgNames.clear();
		mImgNames = dir.entryList();
		if (mImgNames.size() == 0)
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;
		}
		//标定板行列数
		cv::Size boardSize = cv::Size(ui.spinCornersNx->value(), ui.spinCornersNy->value());
		//标定板圆直径
		cv::Size squareSize = cv::Size(ui.spinCircleD->value(), ui.spinCircleD->value());
		bool state = PlateCalibration(imgsPathBuf, imgSaveCalib.toStdString(), boardSize, squareSize);
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmDistortionCalibration::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmDistortionCalibration::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmDistortionCalibration::slot_PathMessage()
{
	QMessageBox::warning(this, "提示", "加载图像文件夹失败！", QMessageBox::Ok);
	return;
}

void frmDistortionCalibration::slot_ErrorMessage()
{
	QMessageBox::warning(this, "提示", "未找到圆点，标定失败！", QMessageBox::Ok);	
}

void frmDistortionCalibration::on_btnSelectPath_clicked()
{
	QString path_C = QDir::currentPath();
	QString dirPath = QFileDialog::getExistingDirectory(this, tr("打开图片文件夹"), path_C);
	if (false == dirPath.isEmpty())
	{
		imgIndex = 0;
		imgsPath = dirPath;
		ui.txtFolderPath->setText(dirPath);
	}
}

void frmDistortionCalibration::on_btnStoragePath_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("保存标定参数文件"), QDir::currentPath() + "/Parameters/Calib/", tr("Config Files (*.xml)"));
	if (!fileName.isNull())
	{
		imgSaveCalib = fileName;
		ui.txtFolderParamPath->setText(fileName);
	}
}

void frmDistortionCalibration::on_btnBlobParam_clicked()
{
	QDir dir(imgsPath);
	mImgNames.reserve(100);
	mImgNames.clear();
	if (imgsPath.isEmpty())
	{	
		emit sig_PathMessage();
		return;
	}
	//获取所有文件名		
	imgsPathBuf = dir.fromNativeSeparators(imgsPath);//  "\\"转为"/" 		
	if (!dir.exists())
	{		
		emit sig_PathMessage();
		return;
	}
	dir.setFilter(QDir::Files);
	dir.setSorting(QDir::Name);
	dir.setNameFilters(QString("*.jpg;*.png;*.jpeg;*.bmp").split(";"));
	mImgNames = dir.entryList();
	if (mImgNames.size() == 0)
	{		
		emit sig_PathMessage();
		return;
	}
	srcImage = cv::imread((imgsPathBuf + "/" + mImgNames[imgIndex]).toLocal8Bit().toStdString(), cv::IMREAD_UNCHANGED);
	imgIndex += 1;
	if (imgIndex == mImgNames.size())
	{
		imgIndex = 0;
	}	
	cv::SimpleBlobDetector::Params params;
	params.filterByCircularity = true;
	params.minCircularity = ui.spinMinCircularity->value();
	params.maxCircularity = ui.spinMaxCircularity->value();
	params.filterByArea = true;
	params.minArea = ui.spinMinArea->value();
	params.maxArea = ui.spinMaxArea->value();
	keypoints.reserve(1000000);
	keypoints.clear();
	//使用参数设置检测器		
	detector = cv::SimpleBlobDetector::create(params);
	//检测斑点
	detector->detect(srcImage, keypoints);
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 检测到的圆点个数为：" + QString::number(keypoints.size()));
	cv::drawKeypoints(srcImage, keypoints, dstImage);
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
}

void frmDistortionCalibration::on_btnCorrectedImage_clicked()
{
	QDir dir(imgsPath);
	mImgNames.reserve(100);
	mImgNames.clear();
	if (imgsPath.isEmpty())
	{
		emit sig_PathMessage();
		return;
	}
	//获取所有文件名		
	imgsPathBuf = dir.fromNativeSeparators(imgsPath);//  "\\"转为"/" 		
	if (!dir.exists())
	{
		emit sig_PathMessage();
		return;
	}
	dir.setFilter(QDir::Files);
	dir.setSorting(QDir::Name);
	dir.setNameFilters(QString("*.jpg;*.png;*.jpeg;*.bmp").split(";"));
	mImgNames = dir.entryList();
	if (mImgNames.size() == 0)
	{
		emit sig_PathMessage();
		return;
	}
	srcImage = cv::imread((imgsPathBuf + "/" + mImgNames[imgIndex]).toLocal8Bit().toStdString(), cv::IMREAD_UNCHANGED);
	imgIndex += 1;
	if (imgIndex == mImgNames.size())
	{
		imgIndex = 0;
	}
	cv::Mat corrected_mat = PlateCorrectedImage(srcImage, imgSaveCalib);
	QImage img(Mat2QImage(corrected_mat));
	view->DispImage(img);
}

void frmDistortionCalibration::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());	
	ui.btnExecute->setEnabled(true);
}

#pragma region 标定板标定
//标定板标定
//cornersNx为X方向的角点数量(boardSize.width)，cornersNy为Y方向的角点数量(boardSize.height)，squareSize.width和squareSize.height为圆直径
bool frmDistortionCalibration::PlateCalibration(const QString imagesPath, const string outputFilename, const cv::Size boardSize, const cv::Size squareSize)
{
	try
	{
		//图像尺寸
		cv::Size image_size;
		cv::Mat view_gray;
		vector<vector<cv::Point2f>> imagePoints;
		//循环处理图像
		for (int j = 0; j < mImgNames.size(); j++)
		{
			cv::String file_name = imgsPathBuf.toLocal8Bit().toStdString() + mImgNames[j].toLocal8Bit().toStdString();
			cv::Mat imageInput = cv::imread(file_name, cv::ImreadModes::IMREAD_ANYCOLOR);
			image_size.width = imageInput.cols;
			image_size.height = imageInput.rows;
			if (imageInput.channels() == 3)
			{
				cv::cvtColor(imageInput, view_gray, cv::COLOR_BGR2GRAY);
			}
			else if (imageInput.channels() == 4)
			{
				cv::cvtColor(imageInput, view_gray, cv::COLOR_RGBA2GRAY);
			}			
			else
			{
				imageInput.copyTo(view_gray);				
			}
			bool found;
			cv::SimpleBlobDetector::Params params;
			params.filterByCircularity = true;
			params.minCircularity = ui.spinMinCircularity->value();
			params.maxCircularity = ui.spinMaxCircularity->value();
			params.filterByArea = true;
			params.minArea = ui.spinMinArea->value();
			params.maxArea = ui.spinMaxArea->value();
			cv::Ptr<cv::FeatureDetector> blobDetector = cv::SimpleBlobDetector::create(params);
			vector<cv::Point2f> pointbuf;
			switch (ui.comboType->currentIndex()) {
			case 0:
				found = cv::findCirclesGrid(view_gray, boardSize, pointbuf, cv::CALIB_CB_SYMMETRIC_GRID | cv::CALIB_CB_CLUSTERING, blobDetector);
				break;
			case 1:
				found = cv::findCirclesGrid(view_gray, boardSize, pointbuf, cv::CALIB_CB_ASYMMETRIC_GRID, blobDetector);
				break;
			}			
			if (found)
			{
				imagePoints.push_back(pointbuf);
				//三通道图像需要转换颜色空间
				cv::Mat rgb_image;
				if (imageInput.channels() == 3)
				{
					cv::cvtColor(imageInput, rgb_image, cv::COLOR_BGR2RGB);
				}
				else if (imageInput.channels() == 4)
				{
					cv::cvtColor(imageInput, rgb_image, cv::COLOR_RGBA2RGB);
				}
				else
				{
					cv::cvtColor(imageInput, rgb_image, cv::COLOR_GRAY2RGB);
				}
				//用于在图片中标记角点
				cv::drawChessboardCorners(rgb_image, boardSize, pointbuf, true);
				QImage img(Mat2QImage(rgb_image));
				view->DispImage(img);				
				cv::waitKey(500);
			}	
			else
			{
				emit sig_ErrorMessage();
				return false;
			}
		}
		//相机标定
		cv::Mat cameraMatrix;
		cv::Mat distCoeffs;
		if (imagePoints.size() > 0)
		{
			//保存标定板上角点的三维坐标	
			vector<vector<cv::Point3f>> object_points;
			//摄像机内参数矩阵
			cameraMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0));
			//每幅图像中角点的数量
			vector<int> point_counts;
			//摄像机的5个畸变系数：k1,k2,p1,p2,k3
			distCoeffs = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0));
			//每幅图像的旋转向量
			vector<cv::Mat> tvecsMat;
			//每幅图像的平移向量
			vector<cv::Mat> rvecsMat;
			//初始化标定板上角点的三维坐标
			int i, j, t;
			for (t = 0; t < mImgNames.size(); t++)
			{
				vector<cv::Point3f> tempPointSet;
				for (i = 0; i < boardSize.height; i++)
				{
					for (j = 0; j < boardSize.width; j++)
					{
						cv::Point3f realPoint;
						//假设标定板放在世界坐标系中z=0的平面上
						realPoint.x = i * squareSize.width;
						realPoint.y = j * squareSize.height;
						realPoint.z = 0;
						tempPointSet.push_back(realPoint);
					}
				}
				object_points.push_back(tempPointSet);
			}
			//初始化每幅图像中的角点数量，假定每幅图像中都可以看到完整的标定板
			for (i = 0; i < mImgNames.size(); i++)
			{
				point_counts.push_back(boardSize.width * boardSize.height);
			}
			//开始标定
			cv::calibrateCamera(object_points, imagePoints, image_size, cameraMatrix, distCoeffs, rvecsMat, tvecsMat, 0);
			string outputFilename_buf = outputFilename.substr(0, outputFilename.size() - 4);
			//保存标定结果的文件
			ofstream fout(outputFilename_buf + ".txt");
			//所有图像的平均误差的总和			
			double total_err = 0.0;
			//每幅图像的平均误差
			double err = 0.0;
			//保存重新计算得到的投影点
			vector<cv::Point2f> image_points2;
			ui.txtMsg->clear();
			fout << "每幅图像的标定误差：\n";
			ui.txtMsg->append("每幅图像的标定误差：");
			for (i = 0; i < mImgNames.size(); i++)
			{
				vector<cv::Point3f> tempPointSet = object_points[i];
				//通过得到的摄像机内外参数，对空间的三维点进行重新投影计算，得到新的投影点
				cv::projectPoints(tempPointSet, rvecsMat[i], tvecsMat[i], cameraMatrix, distCoeffs, image_points2);
				//计算新的投影点和旧的投影点之间的误差
				vector<cv::Point2f> tempImagePoint = imagePoints[i];
				cv::Mat tempImagePointMat = cv::Mat(1, tempImagePoint.size(), CV_32FC2);
				cv::Mat image_points2Mat = cv::Mat(1, image_points2.size(), CV_32FC2);
				for (int j = 0; j < tempImagePoint.size(); j++)
				{
					image_points2Mat.at<cv::Vec2f>(0, j) = cv::Vec2f(image_points2[j].x, image_points2[j].y);
					tempImagePointMat.at<cv::Vec2f>(0, j) = cv::Vec2f(tempImagePoint[j].x, tempImagePoint[j].y);
				}
				err = cv::norm(image_points2Mat, tempImagePointMat, cv::NORM_L2);
				total_err += err /= point_counts[i];
				fout << "第" << i + 1 << "幅图像的平均误差：" << err << "像素" << endl;
				ui.txtMsg->append("第" + QString::number(i + 1) + "幅图像的平均误差：" + QString::number(err) + "像素");
			}
			fout << "总体平均误差：" << total_err / mImgNames.size() << "像素" << endl << endl;
			ui.txtMsg->append("总体平均误差：" + QString::number(total_err / mImgNames.size()) + "像素" + "\n");
			//保存每幅图像的内参数矩阵和畸变系数			
			fout << "摄像机内参数矩阵(cameraMatrix)：" << endl;
			ui.txtMsg->append("摄像机内参数矩阵(cameraMatrix)：");
			fout << cameraMatrix << endl << endl;
			stringstream stream_c;
			stream_c << cameraMatrix;
			ui.txtMsg->append(QString::fromStdString(stream_c.str()) + "\n");
			fout << "摄像机的畸变系数(distCoeffs)：\n";
			ui.txtMsg->append("摄像机的畸变系数(distCoeffs)：");
			fout << distCoeffs << endl << endl;
			stringstream stream_d;
			stream_d << distCoeffs;
			ui.txtMsg->append(QString::fromStdString(stream_d.str()) + "\n");
			//保存每幅图像的内参数矩阵和畸变系数为.xml文件			
			cv::FileStorage fs(outputFilename, cv::FileStorage::WRITE);
			fs << "cameraMatrix" << cameraMatrix;
			fs << "distCoeffs" << distCoeffs;
			fs.release();
			cv::Mat rotation_matrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0));
			for (int i = 0; i < mImgNames.size(); i++)
			{
				fout << "第" << i + 1 << "幅图像的旋转向量：" << endl;
				ui.txtMsg->append("第" + QString::number(i + 1) + "幅图像的旋转向量：");
				fout << tvecsMat[i] << endl;
				stringstream stream_tvecs;
				stream_tvecs << tvecsMat[i];
				ui.txtMsg->append(QString::fromStdString(stream_tvecs.str()));
				//将旋转向量转换为相对应的旋转矩阵
				cv::Rodrigues(tvecsMat[i], rotation_matrix);
				fout << "第" << i + 1 << "幅图像的旋转矩阵：" << endl;
				ui.txtMsg->append("第" + QString::number(i + 1) + "幅图像的旋转矩阵：");
				fout << rotation_matrix << endl;
				stringstream stream_rotation;
				stream_rotation << rotation_matrix;
				ui.txtMsg->append(QString::fromStdString(stream_rotation.str()));
				fout << "第" << i + 1 << "幅图像的平移向量：" << endl;
				ui.txtMsg->append("第" + QString::number(i + 1) + "幅图像的平移向量：");
				fout << rvecsMat[i] << endl << endl;
				stringstream stream_rvecs;
				stream_rvecs << rvecsMat[i];
				ui.txtMsg->append(QString::fromStdString(stream_rvecs.str()) + "\n");
			}
			fout << endl;
		}
		else
		{
			return false;
		}
		GetToolBase()->m_Tools[tool_index].PublicCalib.CameraMatrix = cameraMatrix;
		GetToolBase()->m_Tools[tool_index].PublicCalib.DistCoeffs = distCoeffs;
		return true;
	}
	catch (std::exception& ex)
	{
		QMessageBox::critical(this, "error", ex.what());
		return false;
	}
}
#pragma endregion

#pragma region 标定板标定后校正图像
//标定板标定后校正图像
cv::Mat frmDistortionCalibration::PlateCorrectedImage(const cv::Mat src_mat, const QString inputFilename)
{
	try
	{
		cv::FileStorage fs(inputFilename.toStdString(), cv::FileStorage::READ);
		cv::Mat cameraMatrixRead, distCoeffsRead;
		fs["cameraMatrix"] >> cameraMatrixRead;
		fs["distCoeffs"] >> distCoeffsRead;
		fs.release();
		cv::Mat corrected_mat;
		cv::undistort(src_mat, corrected_mat, cameraMatrixRead, distCoeffsRead);
		return corrected_mat;
	}
	catch (...)
	{
		return cv::Mat();
	}
}
#pragma endregion

QImage frmDistortionCalibration::Mat2QImage(const cv::Mat& mat)
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
