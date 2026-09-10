#include "QWorld.h"

#pragma region XML
#pragma region 创建5个参数的Xml文件
//创建5个参数的Xml文件
bool XML::CreateXml5(QString key, QString file_name, QString value1, QString value2, QString value3, QString value4, QString value5)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		//以读写方式打开指定目录的.xml文件，若该文件不存在则会自动创建
		QFile file(file_name);
		if (!file.open(QFile::WriteOnly | QFile::Truncate))
		{
			return false;
		}
		//使用QDomDocument对象	
		QDomDocument doc;
		//写入xml头部
		QDomProcessingInstruction instruction; //添加处理命令
		instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
		doc.appendChild(instruction);
		//添加根节点
		QDomElement root = doc.createElement("Parameters");
		doc.appendChild(root);
		//添加第一个子节点及其子元素
		QDomElement book = doc.createElement("ParamSetting");
		QDomElement param = doc.createElement("Parameter1"); //创建子元素
		QDomText text; //设置括号标签中间的值
		text = doc.createTextNode(value1);
		book.appendChild(param);
		param.appendChild(text);
		param = doc.createElement("Parameter2"); //创建子元素
		text = doc.createTextNode(value2);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter3"); //创建子元素
		text = doc.createTextNode(value3);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter4"); //创建子元素
		text = doc.createTextNode(value4);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter5"); //创建子元素
		text = doc.createTextNode(value5);
		param.appendChild(text);
		book.appendChild(param);		
		root.appendChild(book);
		//输出到文件
		QTextStream out_stream(&file);
		doc.save(out_stream, 4); //缩进4格
		file.close();
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 创建9个参数的Xml文件
//创建9个参数的Xml文件
bool XML::CreateXml9(QString key, QString file_name, QString value1, QString value2, QString value3, QString value4, QString value5, QString value6, QString value7, QString value8, QString value9)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		//以读写方式打开指定目录的.xml文件，若该文件不存在则会自动创建
		QFile file(file_name);
		if (!file.open(QFile::WriteOnly | QFile::Truncate))
		{
			return false;
		}
		//使用QDomDocument对象	
		QDomDocument doc;
		//写入xml头部
		QDomProcessingInstruction instruction; //添加处理命令
		instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
		doc.appendChild(instruction);
		//添加根节点
		QDomElement root = doc.createElement("Parameters");
		doc.appendChild(root);
		//添加第一个子节点及其子元素
		QDomElement book = doc.createElement("ParamSetting");
		QDomElement param = doc.createElement("Parameter1"); //创建子元素
		QDomText text; //设置括号标签中间的值
		text = doc.createTextNode(value1);
		book.appendChild(param);
		param.appendChild(text);
		param = doc.createElement("Parameter2"); //创建子元素
		text = doc.createTextNode(value2);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter3"); //创建子元素
		text = doc.createTextNode(value3);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter4"); //创建子元素
		text = doc.createTextNode(value4);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter5"); //创建子元素
		text = doc.createTextNode(value5);
		param.appendChild(text);
		book.appendChild(param);		
		param = doc.createElement("Parameter6"); //创建子元素
		text = doc.createTextNode(value6);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter7"); //创建子元素
		text = doc.createTextNode(value7);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter8"); //创建子元素
		text = doc.createTextNode(value8);
		param.appendChild(text);
		book.appendChild(param);
		param = doc.createElement("Parameter9"); //创建子元素
		text = doc.createTextNode(value9);
		param.appendChild(text);
		book.appendChild(param);
		root.appendChild(book);
		//输出到文件
		QTextStream out_stream(&file);
		doc.save(out_stream, 4); //缩进4格
		file.close();
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 修改Xml文件的参数
//修改Xml文件的参数
bool XML::ModifyXml(QString key, QString file_name, vector<string> parameter, vector<string> value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		//以读方式打开指定目录的.xml文件
		QFile file(file_name);
		if (!file.open(QFile::ReadOnly))
		{
			return false;
		}
		//使用QDomDocument对象	
		QDomDocument doc;
		if (!doc.setContent(&file))
		{
			file.close();
			return false;
		}
		file.close();
		for (int i = 0; i < parameter.size(); i++)
		{
			QDomElement root = doc.documentElement();
			QDomNodeList list = root.elementsByTagName(QString::fromStdString(parameter[i]));
			QDomNode node = list.at(0);
			QDomNode oldnode = node.firstChild();
			node.firstChild().setNodeValue(QString::fromStdString(value[i]));
			QDomNode newnode = node.firstChild();
			node.replaceChild(newnode, oldnode);
		}
		if (!file.open(QFile::WriteOnly | QFile::Truncate))
			return false;
		//输出到文件
		QTextStream out_stream(&file);
		doc.save(out_stream, 4); //缩进4格
		file.close();
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 读取Xml文件的参数
//读取Xml文件的参数
bool XML::ReadXml(QString key, QString file_name, QString parameter, QString &value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		//以读方式打开指定目录的.xml文件
		QFile file(file_name);
		if (!file.open(QFile::ReadOnly))
		{
			return false;
		}
		QDomDocument doc;
		if (!doc.setContent(&file))
		{
			file.close();
			return false;
		}
		file.close();
		QDomElement root = doc.documentElement(); //返回根节点	
		QDomNode node = root.firstChild(); //获得第一个子节点
		while (!node.isNull())  //如果节点不空
		{
			if (node.isElement()) //如果节点是元素
			{
				QDomElement e = node.toElement(); //转换为元素，注意元素和节点是两个数据结构		
				QDomNodeList list = e.childNodes();
				for (int i = 0; i < list.count(); i++) //遍历子元素
				{
					QDomNode n = list.at(i);
					if (node.isElement())
					{
						if (n.nodeName() == parameter)
						{
							value = n.toElement().text();
						}
					}
				}
			}
			node = node.nextSibling();
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion
#pragma endregion
