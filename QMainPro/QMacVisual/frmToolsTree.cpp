#include "frmToolsTree.h"
#include <QHeaderView>
#include <QStyleFactory>
#include <QDir>
#include <QPluginLoader>
#include "GlobalVariable.h"

QString ThemeColor = "#20B2AA";

frmToolsTree::frmToolsTree(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	ToolsTreeWidgetInit();
}

//工具列表初始化
void frmToolsTree::ToolsTreeWidgetInit()
{
	ToolTreeWidget = new QtTreeWidget(this);
	QGridLayout* ToolGLayout = new QGridLayout(ui.ToolTreeFrame);
	ToolGLayout->setContentsMargins(0, 0, 0, 0);
	ToolGLayout->setSpacing(5);
	ToolGLayout->addWidget(ToolTreeWidget, 0, 0);
	ToolTreeWidget->setIconSize(QSize(24, 24));
	//显示虚线
	ToolTreeWidget->setStyle(QStyleFactory::create("windows"));
	//更换系统默认图标
	ToolTreeWidget->setStyleSheet("QTreeWidget::branch:has-children:!has-siblings:closed,\
	QWidget{border: 1px;border-style: solid;border-color: #d9d9d9}\
	QTreeWidget::item{color: #363636}\
	QTreeWidget::item{height: 30px}\
    QTreeView::item::selected{background-color:#96B5A8}\
	QTreeWidget::branch:closed:has-children:!has-siblings{border-style: none; border-image: none; image: url(:/res/ico/unfold.png);}\
	QTreeWidget::branch:closed:has-children:has-siblings{border-image: none; image: url(:/res/ico/unfold.png);}\
	QTreeWidget::branch:open:has-children:!has-siblings{border-image: none; image: url(:/res/ico/fold.png);}\
	QTreeWidget::branch:open:has-children:has-siblings{border-image: none; image: url(:/res/ico/fold.png);}"
	"QScrollBar:vertical{" //设置滚动条样式
	"background:#FFFFF2;"  //背景色  
	"padding-top:20px;"    //上预留位置(放置向上箭头）  
	"padding-bottom:20px;" //下预留位置(放置向下箭头）  
	"padding-left:2px;"    //左预留位置 
	"padding-right:2px;"   //右预留位置 
	"border-left:1px solid #d7d7d7;}" //左分割线  
	"QScrollBar::handle:vertical{" //滑块样式  
	"background:#dbdbdb;"  //滑块颜色  
	"border-radius:6px;"   //边角圆
	"min-height:20px;}"    //滑块最小高度
	"QScrollBar::handle:vertical:hover{" //鼠标触及滑块样式  
	"background:#d0d0d0;}" //滑块颜色  
	"QScrollBar::add-line:vertical{" //向下箭头样式  
	"background:url(:/res/ico/down.png) center no-repeat;}"
	"QScrollBar::sub-line:vertical{" //向上箭头样式
	"background:url(:/res/ico/up.png) center no-repeat;}");
	//设置字体及字体大小
	QFont font("Microsoft YaHei");
	font.setPixelSize(16.5);
	ToolTreeWidget->setFont(font);
	ToolTreeWidget->header()->setVisible(false);
	ToolTreeWidget->clear();
	this->setAcceptDrops(false);
	//工具列表
	ToolsPair toolPair;	
	//图像处理
	LoadPlugins("图像处理");  //加载图像处理	
	toolPair.first = "图像处理";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//检测识别
	LoadPlugins("检测识别");  //加载检测识别		
	toolPair.first = "检测识别";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//标定工具
	LoadPlugins("标定工具");  //加载标定工具	
	toolPair.first = "标定工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//对位工具
	LoadPlugins("对位工具");  //加载对位工具		
	toolPair.first = "对位工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//几何工具
	LoadPlugins("几何工具");  //加载几何工具
	toolPair.first = "几何工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//几何测量
	LoadPlugins("几何测量");  //加载几何测量	
	toolPair.first = "几何测量";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//三维检测	
	LoadPlugins("三维检测");  //加载三维检测
	toolPair.first = "三维检测";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//逻辑工具
	LoadPlugins("逻辑工具");  //加载逻辑工具	
	toolPair.first = "逻辑工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//通讯工具
	LoadPlugins("通讯工具");  //加载通讯工具	
	toolPair.first = "通讯工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//系统工具
	LoadPlugins("系统工具");  //加载系统工具	
	toolPair.first = "系统工具";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//YoloV13
	LoadPlugins("目标检测");  //加载YoloV13目标检测	
	toolPair.first = "目标检测";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//OCR
	LoadPlugins("OCR识别");  //加载OCR识别	
	toolPair.first = "OCR识别";
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//循环处理图标	
	for (int i = 0; i < ToolNamesVec.size(); i++)
	{
		QString toolBoxName = ToolNamesVec[i].first;
		QStringList toolList = QStringList::fromStdList(ToolNamesVec[i].second);
		QTreeWidgetItem* itemParent = new QTreeWidgetItem(ToolTreeWidget);
		itemParent->setText(0, toolBoxName);
		itemParent->setIcon(0, QIcon(":/res/ico/tool.ico"));
		itemParent->setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled);
		for (int j = 0; j < toolList.count(); j++)
		{
			QTreeWidgetItem* treeItem = new QTreeWidgetItem(itemParent, QStringList(toolList[j]));
			QPixmap pixmap = GetIcon(GetIconName(toolList[j]));
			treeItem->setIcon(0, pixmap);
		}
	}
}

/*
 * @function PluginsApp::LoadPlugins 加载插件、插件放在Plugins文件夹下
 * @return 返回插件的个数
 */
int frmToolsTree::LoadPlugins(QString str)
{
	int count = 0;
	QDir pluginsDir = QDir(qApp->applicationDirPath());
	if (!pluginsDir.cd("Plugins")) return -1;
	QStringList filters;
	filters << "*.dll"; //可以多种格式或者单个格式
	pluginsDir.setFilter(QDir::Files | QDir::NoSymLinks); //设置类型过滤器，只为文件格式
	pluginsDir.setNameFilters(filters);  //设置文件名称过滤器
	foreach(QString fileName, pluginsDir.entryList())
	{
		QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
		QObject* plugin = pluginLoader.instance();
		if (plugin)
		{
			auto treeInterface = qobject_cast<MainInterface*>(plugin);
			if (treeInterface)
			{
				++count;
				//加载插件后生成Tree
				PopulateTree(str, plugin, treeInterface);
			}
		}
		else {
			//std::cout << "加载插件失败:" << pluginLoader.errorString() << "\n" << std::endl; // 关键：打印错误详情
			const QString errorStr = pluginLoader.errorString();
			/*printf("加载插件失败:", errorStr);*/
			qDebug() << "加载插件失败:" << pluginLoader.errorString();
		}

	}
	return count;
}

/*
 * @function PluginsApp::PopulateTree 根据插件生成Tree
 * @param pluginInterface 插件
 * @param i 插件实现的接口
 */
void frmToolsTree::PopulateTree(QString str, QObject* pluginInterface, MainInterface* i)
{
	try
	{
		QString info = i->information();
		if (info == str)
		{
			ToolNameList.push_back(i->name());
		}
	}
	catch(...){}	
}

// 获取图标
QPixmap frmToolsTree::GetIcon(QString fileName)
{
	return IconHelper::Instance()->getPixmap(fileName);
}

// 获取图标路径
QString frmToolsTree::GetIconName(QString Name)
{
	QString IconName;
	if (Name.contains("获取图像")) IconName = ":/res/ico/image_source.png";
	if (Name.contains("图像显示")) IconName = ":/res/ico/image_view.ico";
	if (Name.contains("导出图像")) IconName = ":/res/ico/export_image.png";	
	if (Name.contains("预处理")) IconName = ":/res/ico/morphology.png";
	if (Name.contains("图像拼接")) IconName = ":/res/ico/image_splice.png";	
	if (Name.contains("图像修复")) IconName = ":/res/ico/repair.png";	
	if (Name.contains("图像细化")) IconName = ":/res/ico/skeleton.png";
	if (Name.contains("图像翻转")) IconName = ":/res/ico/flip.png";
	if (Name.contains("图像旋转")) IconName = ":/res/ico/rotate.png";
	if (Name.contains("透视变换")) IconName = ":/res/ico/perspective.png";	
	if (Name.contains("裁切图像")) IconName = ":/res/ico/crop.png";
	if (Name.contains("创建ROI")) IconName = ":/res/ico/roi.png";
	if (Name.contains("条形码识别")) IconName = ":/res/ico/barcode.png";
	if (Name.contains("斑点分析")) IconName = ":/res/ico/blob.png";
	if (Name.contains("二维码识别")) IconName = ":/res/ico/qrcode.png";
	if (Name.contains("字符识别")) IconName = ":/res/ico/ocr.png";
	if (Name.contains("分类器")) IconName = ":/res/ico/classifier.png";
	if (Name.contains("颜色识别")) IconName = ":/res/ico/color_r.png";	
	if (Name.contains("亮度检测")) IconName = ":/res/ico/brightness.png";
	if (Name.contains("图像清晰度")) IconName = ":/res/ico/clarity.png";		
	if (Name.contains("轮廓特征选择")) IconName = ":/res/ico/shape.png";
	if (Name.contains("N点标定")) IconName = ":/res/ico/ert_calib.png";
	if (Name.contains("畸变标定")) IconName = ":/res/ico/distortion_calib.png";
	if (Name.contains("测量标定")) IconName = ":/res/ico/measure_calib.png";
	if (Name.contains("灰度匹配")) IconName = ":/res/ico/match.png";	
	if (Name.contains("形状匹配")) IconName = ":/res/ico/shape_match.png";
	if (Name.contains("目标跟踪")) IconName = ":/res/ico/track.png";
	if (Name.contains("线性计算")) IconName = ":/res/ico/affine.png";
	if (Name.contains("寻找圆")) IconName = ":/res/ico/find_circle.png";
	if (Name.contains("寻找直线")) IconName = ":/res/ico/find_line.png";
	if (Name.contains("拟合圆")) IconName = ":/res/ico/fit_circle.png";
	if (Name.contains("拟合椭圆")) IconName = ":/res/ico/fit_ellipse.png";
	if (Name.contains("拟合直线")) IconName = ":/res/ico/fit_line.png";
	if (Name.contains("获取边界点")) IconName = ":/res/ico/border_point.png";
	if (Name.contains("线圆交点")) IconName = ":/res/ico/line_circle.png";
	if (Name.contains("点+点")) IconName = ":/res/ico/point_point.png";
	if (Name.contains("点+线")) IconName = ":/res/ico/point_l.png";
	if (Name.contains("线线交点")) IconName = ":/res/ico/intersection.png";
	if (Name.contains("查找圆缺角")) IconName = ":/res/ico/rounded_c.png";	
	if (Name.contains("边缘宽度测量")) IconName = ":/res/ico/edge.png";
	if (Name.contains("拟合平面")) IconName = ":/res/ico/flatness.png";	
	if (Name.contains("扩展库")) IconName = ":/res/ico/extension_library.png";
	if (Name.contains("跳转语句")) IconName = ":/res/ico/goto.png";
	if (Name.contains("判断语句")) IconName = ":/res/ico/logic_judge.png";
	if (Name.contains("结束语句")) IconName = ":/res/ico/end.png";
	if (Name.contains("脚本编辑")) IconName = ":/res/ico/script_edit.png";
	if (Name.contains("TCP/IP服务器")) IconName = ":/res/ico/server.png";	
	if (Name.contains("TCP/IP客户端")) IconName = ":/res/ico/client.png";
	if (Name.contains("PLC通信")) IconName = ":/res/ico/plc_communicate.png";
	if (Name.contains("串口通信")) IconName = ":/res/ico/serial_port.png";
	if (Name.contains("通用I/O")) IconName = ":/res/ico/general_io.png";
	if (Name.contains("延时")) IconName = ":/res/ico/delay.png";	
	if (Name.contains("导出CSV")) IconName = ":/res/ico/export_csv.png";
	if (Name.contains("YoloV13")) IconName = ":/res/ico/classifier.png";
	if (Name.contains("OCR")) IconName = ":/res/ico/ocr.png";
	if (Name.contains("二维码生成")) IconName = ":/res/ico/qrcode.png";
	if (Name.contains("自动打印")) IconName = ":/res/ico/print.png";
	return IconName;
}
