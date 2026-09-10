#include "frmPlateRecognition.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QGraphicsOpacityEffect>
#include <QCoreApplication>
#include <QApplication>
#include "QGraphicsScenes.h"

frmPlateRecognition::frmPlateRecognition(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/plate.png"));
	initTitleBar();
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);

	QString appDir = QCoreApplication::applicationDirPath();
	ui.txtDetectModel->setText(appDir + "/models/plate/yolo26s-plate-detect.onnx");
	ui.txtRecModel->setText(appDir + "/models/plate/plate_rec_color.onnx");
}

frmPlateRecognition::~frmPlateRecognition()
{
	this->deleteLater();
}

void frmPlateRecognition::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/plate.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmPlateRecognition::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
	return QWidget::paintEvent(event);
}

void frmPlateRecognition::onButtonCloseClicked()
{
	this->close();
}

int frmPlateRecognition::Execute(const QString toolname)
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
	for (int i = 0; i < (int)GetToolBase()->m_Tools.size(); i++)
	{
		if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
		{
			image_index = i;
			link_state = true;
		}
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
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

bool frmPlateRecognition::EnsureEngine()
{
	QString det = ui.txtDetectModel->text();
	QString rec = ui.txtRecModel->text();
	bool gpu = ui.chkGpu->isChecked();
	if (engine.isReady() && loadedDetect == det && loadedRec == rec)
	{
		return true;
	}
	if (!engine.init(det.toStdString(), rec.toStdString(), gpu))
	{
		return false;
	}
	loadedDetect = det;
	loadedRec = rec;
	return true;
}

int frmPlateRecognition::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		plateCodes.clear();
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (dstImage.empty())
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		if (!EnsureEngine())
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		float score = (float)ui.spinScore->value();
		std::vector<PlateDet> dets = engine.infer(dstImage, score);
		engine.drawResults(dstImage, dets);
		for (const auto& d : dets)
		{
			QString line = QString::fromUtf8(d.plate_license.c_str());
			if (!d.plate_color.empty())
				line += " " + QString::fromUtf8(d.plate_color.c_str());
			if (d.plate_type == 1)
				line += QString::fromUtf8(" \xE5\x8F\x8C\xE5\xB1\x82");
			plateCodes.push_back(line);
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Code = plateCodes;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Quantity = (int)plateCodes.size();
		GetToolBase()->m_Tools[tool_index].PublicResult.State = !plateCodes.empty();
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmPlateRecognition::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 1 || strs[1] != QString::fromUtf8("\xE5\x9B\xBE\xE5\x83\x8F"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, QString::fromUtf8("\xE9\x94\x99\xE8\xAF\xAF"), QString::fromUtf8("\xE8\xBE\x93\xE5\x85\xA5\xE7\x9A\x84\xE9\x93\xBE\xE6\x8E\xA5\xE9\x94\x99\xE8\xAF\xAF\xEF\xBC\x81"));
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

int frmPlateRecognition::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

QVariant frmPlateRecognition::InitGetToolData()
{
	QStringList list;
	list << ui.txtDetectModel->text()
		<< ui.txtRecModel->text()
		<< ui.txtLinkImage->text()
		<< QString::number(ui.spinScore->value())
		<< (ui.chkGpu->isChecked() ? "1" : "0");
	return QVariant(list);
}

int frmPlateRecognition::InitSetToolData(const QVariant data)
{
	QStringList list = data.toStringList();
	if (list.size() >= 5)
	{
		ui.txtDetectModel->setText(list[0]);
		ui.txtRecModel->setText(list[1]);
		ui.txtLinkImage->setText(list[2]);
		ui.spinScore->setValue(list[3].toDouble());
		ui.chkGpu->setChecked(list[4] == "1");
	}
	return 0;
}

void frmPlateRecognition::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	if (!EnsureEngine())
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, QString::fromUtf8("\xE9\x94\x99\xE8\xAF\xAF"),
			QString::fromUtf8("\xE6\xA8\xA1\xE5\x9E\x8B\xE5\x8A\xA0\xE8\xBD\xBD\xE5\xA4\xB1\xE8\xB4\xA5\xEF\xBC\x8C\xE8\xAF\xB7\xE6\xA3\x80\xE6\x9F\xA5\xE6\xA3\x80\xE6\xB5\x8B/\xE8\xAF\x86\xE5\x88\xAB ONNX \xE8\xB7\xAF\xE5\xBE\x84\xE3\x80\x82\n") + QString::fromStdString(engine.lastError())
			+ QString::fromUtf8("\n\xE8\xAF\xB7\xE5\xB0\x86 yolo26s-plate-detect.onnx \xE4\xB8\x8E plate_rec_color.onnx \xE6\x94\xBE\xE5\x85\xA5 models/plate"));
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		ui.btnExecute->setEnabled(true);
		return;
	}
	Execute(GetToolName());
	ui.txtMsg->clear();
	if (plateCodes.empty())
	{
		ui.txtMsg->append(QString::fromUtf8("-> \xE6\x9C\xAA\xE8\xAF\x86\xE5\x88\xAB\xE5\x88\xB0\xE8\xBD\xA6\xE7\x89\x8C"));
	}
	else
	{
		ui.txtMsg->append(QString::fromUtf8("-> \xE8\xAF\x86\xE5\x88\xAB\xE7\xBB\x93\xE6\x9E\x9C"));
		for (int i = 0; i < (int)plateCodes.size(); i++)
		{
			ui.txtMsg->append(plateCodes[i]);
		}
	}
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmPlateRecognition::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmPlateRecognition::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmPlateRecognition::on_btnDetectModel_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("\xE9\x80\x89\xE6\x8B\xA9\xE6\xA3\x80\xE6\xB5\x8B\xE6\xA8\xA1\xE5\x9E\x8B"),
		ui.txtDetectModel->text(), "ONNX (*.onnx);;Engine (*.engine);;All (*.*)");
	if (!fileName.isEmpty())
	{
		ui.txtDetectModel->setText(fileName);
		loadedDetect.clear();
	}
}

void frmPlateRecognition::on_btnRecModel_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("\xE9\x80\x89\xE6\x8B\xA9\xE8\xAF\x86\xE5\x88\xAB\xE6\xA8\xA1\xE5\x9E\x8B"),
		ui.txtRecModel->text(), "ONNX (*.onnx);;Engine (*.engine);;All (*.*)");
	if (!fileName.isEmpty())
	{
		ui.txtRecModel->setText(fileName);
		loadedRec.clear();
	}
}

QImage frmPlateRecognition::Mat2QImage(const cv::Mat& mat)
{
	if (mat.empty()) return QImage();
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);
		for (int i = 0; i < 256; i++) image.setColor(i, qRgb(i, i, i));
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
		QImage image(pSrc, mat.cols, mat.rows, (int)mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, (int)mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	return QImage();
}

int QConfig::nFormState = 0;
