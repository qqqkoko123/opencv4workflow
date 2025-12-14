#include "QtWidgetsSaveLoad.h"
#include <QDebug>
#include <QFileInfo>
#include "datavar.h"

QtWidgetsSaveLoad::QtWidgetsSaveLoad()
{
}

void QtWidgetsSaveLoad::addQLabel(QLabel* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qLabel_text = w->text();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQLineEdit(QLineEdit* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qLineEdit_text = w->text();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQTextEdit(QTextEdit* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qTextEdit_text = w->toPlainText();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQCheckBox(QCheckBox* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qCheckBox_checked = w->checkState();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQRadioButton(QRadioButton* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qRadioButton_checked = w->isChecked();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQComboBox(QComboBox* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qComboBox_currentText = w->currentText();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQSpinBox(QSpinBox* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qSpinBox_value = w->value();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQDoubleSpinBox(QDoubleSpinBox* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	wi.qDoubleSpinBox_value = w->value();
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::addQTableWidget(QTableWidget* w)
{
	WidgetInfo wi;
	wi.control_name = w->objectName();
	for (int i = 0; i < w->rowCount(); i++) //取出每个格子的内容
	{
		for (int j = 0; j < w->columnCount(); j++)
		{
			if (w->item(i, j) != NULL)
			{
				wi.qTableWidget_text.append(w->item(i, j)->text());
			}
			else
			{
				wi.qTableWidget_text.append(QString());
			}
		}
	}
	widgetInfoList.append(wi);
}

void QtWidgetsSaveLoad::gatherChildrenWidgetInfo(QList<QWidget*> parent)
{
	//窗体界面控件序列化
	widgetInfoLists_save.clear();
	for (int k = 0; k < parent.size(); k++)
	{
		widgetInfoLists.clear();
		//收集QLabel控件信息，保存到QList<WidgetInfo>
		QList<QLabel*> listQLabel = parent[k]->findChildren<QLabel*>();
		for (int i = 0; i < listQLabel.size(); i++)
		{
			QLabel* le = listQLabel.at(i);
			if (le->objectName() == "")
				qDebug() << "QLabel no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qLabel_text = le->text();
				widgetInfoLists.append(wi);
			}
		}
		//收集QLineEdit控件信息，保存到QList<WidgetInfo>
		QList<QLineEdit*> listQLineEdit = parent[k]->findChildren<QLineEdit*>();
		for (int i = 0; i < listQLineEdit.size(); i++)
		{
			QLineEdit* le = listQLineEdit.at(i);
			if (le->objectName() == "")
				qDebug() << "QLineEdit no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qLineEdit_text = le->text();
				widgetInfoLists.append(wi);
			}
		}
		//收集QTextEdit控件信息，保存到QList<WidgetInfo>
		QList<QTextEdit*> listQTextEdit = parent[k]->findChildren<QTextEdit*>();
		for (int i = 0; i < listQTextEdit.size(); i++)
		{
			QTextEdit* le = listQTextEdit.at(i);
			if (le->objectName() == "")
				qDebug() << "QTextEdit no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qTextEdit_text = le->toPlainText();
				widgetInfoLists.append(wi);
			}
		}
		//收集QPlainTextEdit控件信息，保存到QList<WidgetInfo>
		QList<QPlainTextEdit*> listQPlainTextEdit = parent[k]->findChildren<QPlainTextEdit*>();
		for (int i = 0; i < listQPlainTextEdit.size(); i++)
		{
			QPlainTextEdit* le = listQPlainTextEdit.at(i);
			if (le->objectName() == "")
				qDebug() << "QPlainTextEdit no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qPlainTextEdit_text = le->toPlainText();
				widgetInfoLists.append(wi);
			}
		}
		//收集QCheckBox控件信息，保存到QList<WidgetInfo>
		QList<QCheckBox*> listQCheckBox = parent[k]->findChildren<QCheckBox*>();
		for (int i = 0; i < listQCheckBox.size(); i++)
		{
			QCheckBox* le = listQCheckBox.at(i);
			if (le->objectName() == "")
				qDebug() << "QCheckBox no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qCheckBox_checked = le->checkState();
				widgetInfoLists.append(wi);
			}
		}
		//收集QRadioButton控件信息，保存到QList<WidgetInfo>
		QList<QRadioButton*> listQRadioButton = parent[k]->findChildren<QRadioButton*>();
		for (int i = 0; i < listQRadioButton.size(); i++)
		{
			QRadioButton* le = listQRadioButton.at(i);
			if (le->objectName() == "")
				qDebug() << "QRadioButton no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qRadioButton_checked = le->isChecked();
				widgetInfoLists.append(wi);
			}
		}
		//收集QComboBox控件信息，保存到QList<WidgetInfo>
		QList<QComboBox*> listQComboBox = parent[k]->findChildren<QComboBox*>();
		for (int i = 0; i < listQComboBox.size(); i++)
		{
			QComboBox* le = listQComboBox.at(i);
			if (le->objectName() == "")
				qDebug() << "QComboBox no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qComboBox_currentText = le->currentText();
				widgetInfoLists.append(wi);
			}
		}
		//收集QSpinBox控件信息，保存到QList<WidgetInfo>
		QList<QSpinBox*> listQSpinBox = parent[k]->findChildren<QSpinBox*>();
		for (int i = 0; i < listQSpinBox.size(); i++)
		{
			QSpinBox* le = listQSpinBox.at(i);
			if (le->objectName() == "")
				qDebug() << "QSpinBox no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qSpinBox_value = le->value();
				widgetInfoLists.append(wi);
			}
		}
		//收集QDoubleSpinBox控件信息，保存到QList<WidgetInfo>
		QList<QDoubleSpinBox*> listQDoubleSpinBox = parent[k]->findChildren<QDoubleSpinBox*>();
		for (int i = 0; i < listQDoubleSpinBox.size(); i++)
		{
			QDoubleSpinBox* le = listQDoubleSpinBox.at(i);
			if (le->objectName() == "")
				qDebug() << "QDoubleSpinBox no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.qDoubleSpinBox_value = le->value();
				widgetInfoLists.append(wi);
			}
		}
		//收集QTableWidget控件信息，保存到QList<WidgetInfo>
		QList<QTableWidget*> listQTableWidget = parent[k]->findChildren<QTableWidget*>();
		for (int i = 0; i < listQTableWidget.size(); i++)
		{
			QTableWidget* le = listQTableWidget.at(i);
			if (le->objectName() == "")
				qDebug() << "QTableWidget no setting objectName!";
			else
			{
				WidgetInfo wi;
				wi.control_name = le->objectName();
				wi.row_count = le->rowCount();
				for (int i = 0; i < le->rowCount(); i++) //取出每个格子的内容
				{
					for (int j = 0; j < le->columnCount(); j++)
					{
						if (le->item(i, j) != NULL)
						{
							wi.qTableWidget_text.append(le->item(i, j)->text());
						}
						else
						{
							wi.qTableWidget_text.append(QString());
						}
					}
				}
				widgetInfoLists.append(wi);
			}
		}
		widgetInfoLists_save.append(widgetInfoLists);
	}
	//流程树列表序列化	
	dataInfoList.clear();
	for (int i = 0; i < dataVar::fProItemTab->treeItem.count(); i++)
	{
		if (dataVar::fProItemTab->treeItem[i] != nullptr)
		{
			WidgetInfo wi_dataInfoList;
			wi_dataInfoList.tree_text = dataVar::fProItemTab->treeItem[i]->text(0);
			wi_dataInfoList.tree_icon = dataVar::fProItemTab->treeItem[i]->icon(0);
			dataInfoList.append(wi_dataInfoList);
		}
		else
		{
			WidgetInfo wi_dataInfoList;
			wi_dataInfoList.tree_text = QString();
			dataInfoList.append(wi_dataInfoList);
		}
	}
	//流程工具列表序列化
	dataToolList.clear();
	for (int i = 0; i < dataVar::fProItemTab->treeItem.count(); i++)
	{
		if (dataVar::fProItemTab->treeItem[i] != nullptr)
		{
			WidgetInfo wi_dataToolList;
			wi_dataToolList.flowProItemList = QConfig::ToolBase[i]->m_FlowSortList;
			dataToolList.append(wi_dataToolList);
		}
		else
		{
			WidgetInfo wi_dataToolList;
			wi_dataToolList.flowProItemList = QVector<QString>();
			dataToolList.append(wi_dataToolList);
		}
	}
}

void QtWidgetsSaveLoad::saveParamToFileOne()
{
	//流程工具图标列表序列化	
	dataToolTitleList.clear();
	dataToolTitleList.resize(20);
	for (int i = 0; i < dataVar::fProItemTab->treeItem.count(); i++)
	{
		if (dataVar::fProItemTab->treeItem[i] != nullptr)
		{
			QList<QString> state_keys;  //激活/禁用状态
			QList<int> t_keys;
			switch (i) {
			case 0:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B1->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B1->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[0].append(wi_dataToolTitleList);
				}
				break;
			case 1:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B2->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B2->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[1].append(wi_dataToolTitleList);
				}
				break;
			case 2:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B3->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B3->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[2].append(wi_dataToolTitleList);
				}
				break;
			case 3:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B4->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B4->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[3].append(wi_dataToolTitleList);
				}
				break;
			case 4:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B5->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B5->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[4].append(wi_dataToolTitleList);
				}
				break;
			case 5:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B6->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B6->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[5].append(wi_dataToolTitleList);
				}
				break;
			case 6:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B7->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B7->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[6].append(wi_dataToolTitleList);
				}
				break;
			case 7:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B8->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B8->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[7].append(wi_dataToolTitleList);
				}
				break;
			case 8:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B9->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B9->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[8].append(wi_dataToolTitleList);
				}
				break;
			case 9:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B10->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B10->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[9].append(wi_dataToolTitleList);
				}
				break;
			case 10:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B11->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B11->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[10].append(wi_dataToolTitleList);
				}
				break;
			case 11:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B12->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B12->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[11].append(wi_dataToolTitleList);
				}
				break;
			case 12:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B13->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B13->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[12].append(wi_dataToolTitleList);
				}
				break;
			case 13:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B14->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B14->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[13].append(wi_dataToolTitleList);
				}
				break;
			case 14:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B15->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B15->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[14].append(wi_dataToolTitleList);
				}
				break;
			case 15:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B16->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B16->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[15].append(wi_dataToolTitleList);
				}
				break;
			case 16:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B17->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B17->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[16].append(wi_dataToolTitleList);
				}
				break;
			case 17:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B18->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B18->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[17].append(wi_dataToolTitleList);
				}
				break;
			case 18:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B19->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B19->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[18].append(wi_dataToolTitleList);
				}
				break;
			case 19:
				t_keys.clear();
				t_keys = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.uniqueKeys();
				state_keys.clear();
				state_keys = dataVar::fProItemTab->TempDragListWidget_B20->d->m_states.uniqueKeys();
				for (int p = 0; p < t_keys.length(); p++)
				{
					WidgetInfo wi_dataToolTitleList;
					int key = t_keys[p];
					wi_dataToolTitleList.m_index = key;
					wi_dataToolTitleList.m_nId = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_nId;
					wi_dataToolTitleList.m_pixmap = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_pixmap;
					wi_dataToolTitleList.m_strTitle = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_strTitle;
					wi_dataToolTitleList.m_strSubTitle = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_strSubTitle;
					wi_dataToolTitleList.m_strDescribeTitle = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_strDescribeTitle;
					wi_dataToolTitleList.m_rectItem = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_rectItem;
					wi_dataToolTitleList.m_rectSub = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_rectSub;
					wi_dataToolTitleList.m_subPixmap = dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.value(key).m_subPixmap;
					wi_dataToolTitleList.itemContent = dataVar::fProItemTab->TempDragListWidget_B20->d->ItemContent;
					wi_dataToolTitleList.m_states = state_keys;
					dataToolTitleList[19].append(wi_dataToolTitleList);
				}
				break;
			}
		}
	}
}

void QtWidgetsSaveLoad::saveParamToFileTwo()
{
	//仪器仪表序列化	
	QList<QString> g_keys;
	g_keys.reserve(200);
	dataIoLocalList.clear();  //通用I/O
	g_keys.clear();
	g_keys = dataVar::fInstrumentation->global_io_content.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.global_key = key;
		wi_dataIList.global_ip = dataVar::fInstrumentation->global_io_content.value(key).global_ip;
		wi_dataIList.global_port = dataVar::fInstrumentation->global_io_content.value(key).global_port;
		wi_dataIList.global_timeout = dataVar::fInstrumentation->global_io_content.value(key).global_timeout;
		wi_dataIList.global_remark = dataVar::fInstrumentation->global_io_content.value(key).global_remark;
		if (p == 0)
		{
			wi_dataIList.io_client_ip = dataVar::io_client_ip;
			wi_dataIList.io_client_port = dataVar::io_client_port;
		}
		dataIoLocalList.append(wi_dataIList);
	}
	dataPlcLocalList.clear();  //PLC通信
	g_keys.clear();
	g_keys = dataVar::fInstrumentation->global_plc_content.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.global_key = key;
		wi_dataIList.global_ip = dataVar::fInstrumentation->global_plc_content.value(key).global_ip;
		wi_dataIList.global_port = dataVar::fInstrumentation->global_plc_content.value(key).global_port;
		wi_dataIList.global_timeout = dataVar::fInstrumentation->global_plc_content.value(key).global_timeout;
		wi_dataIList.global_remark = dataVar::fInstrumentation->global_plc_content.value(key).global_remark;
		if (p == 0)
		{
			wi_dataIList.mit_plc_client_ip = dataVar::mit_plc_client_ip;
			wi_dataIList.mit_plc_client_port = dataVar::mit_plc_client_port;
		}
		dataPlcLocalList.append(wi_dataIList);
	}
	dataSerialportLocalList.clear();  //串口通信
	g_keys.clear();
	g_keys = dataVar::fInstrumentation->global_serialport_content.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.global_key = key;
		wi_dataIList.global_serial_port = dataVar::fInstrumentation->global_serialport_content.value(key).global_serial_port;
		wi_dataIList.global_baud_rate = dataVar::fInstrumentation->global_serialport_content.value(key).global_baud_rate;
		wi_dataIList.global_check_digit = dataVar::fInstrumentation->global_serialport_content.value(key).global_check_digit;
		wi_dataIList.global_data_bits = dataVar::fInstrumentation->global_serialport_content.value(key).global_data_bits;
		wi_dataIList.global_stop_bit = dataVar::fInstrumentation->global_serialport_content.value(key).global_stop_bit;
		wi_dataIList.global_flowcontrol = dataVar::fInstrumentation->global_serialport_content.value(key).global_flowcontrol;
		wi_dataIList.global_remark = dataVar::fInstrumentation->global_serialport_content.value(key).global_remark;
		dataSerialportLocalList.append(wi_dataIList);
	}
	dataTcpLocalList.clear();  //TCP/IP通信
	g_keys.clear();
	g_keys = dataVar::fInstrumentation->global_tcp_content.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.global_key = key;
		wi_dataIList.global_protocol = dataVar::fInstrumentation->global_tcp_content.value(key).global_protocol;
		wi_dataIList.global_ip = dataVar::fInstrumentation->global_tcp_content.value(key).global_ip;
		wi_dataIList.global_port = dataVar::fInstrumentation->global_tcp_content.value(key).global_port;
		wi_dataIList.global_remark = dataVar::fInstrumentation->global_tcp_content.value(key).global_remark;
		if (p == 0)
		{
			wi_dataIList.tcp_client_ip = dataVar::tcp_client_ip;
			wi_dataIList.tcp_client_port = dataVar::tcp_client_port;
		}
		dataTcpLocalList.append(wi_dataIList);
	}
	dataIoRemoteList.clear();  //通用I/O
	g_keys.clear();
	g_keys = gVariable::generalio_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.io_key_value = key;
		wi_dataIList.connect_state = gVariable::generalio_variable_link.value(key).connect_state;
		wi_dataIList.ip_value = gVariable::generalio_variable_link.value(key).ip_value;
		wi_dataIList.port_value = gVariable::generalio_variable_link.value(key).port_value;
		wi_dataIList.over_time_value = gVariable::generalio_variable_link.value(key).over_time_value;
		wi_dataIList.remark_value = gVariable::generalio_variable_link.value(key).remark_value;
		dataIoRemoteList.append(wi_dataIList);
	}
	dataPlcRemoteList.clear();  //PLC通信
	g_keys.clear();
	g_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.plc_key_value = key;
		wi_dataIList.connect_state = gVariable::plccommunicate_variable_link.value(key).connect_state;
		wi_dataIList.plc_type = gVariable::plccommunicate_variable_link.value(key).plc_type;
		wi_dataIList.mit_ip_value = gVariable::plccommunicate_variable_link.value(key).mit_ip_value;
		wi_dataIList.mit_port_value = gVariable::plccommunicate_variable_link.value(key).mit_port_value;
		wi_dataIList.mit_over_time_value = gVariable::plccommunicate_variable_link.value(key).mit_over_time_value;
		wi_dataIList.mit_remark_value = gVariable::plccommunicate_variable_link.value(key).mit_remark_value;
		dataPlcRemoteList.append(wi_dataIList);
	}
	dataSerialportRemoteList.clear();  //串口通信
	g_keys.clear();
	g_keys = gVariable::serialport_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.serialport_key_value = key;
		wi_dataIList.connect_state = gVariable::serialport_variable_link.value(key).connect_state;
		wi_dataIList.portname_value = gVariable::serialport_variable_link.value(key).portname_value;
		wi_dataIList.baudrate_value = gVariable::serialport_variable_link.value(key).baudrate_value;
		if (gVariable::serialport_variable_link.value(key).parity_value == QSerialPort::NoParity)
		{
			wi_dataIList.parity_value = "无";
		}
		else if (gVariable::serialport_variable_link.value(key).parity_value == QSerialPort::Parity::OddParity)
		{
			wi_dataIList.parity_value = "奇";
		}
		else if (gVariable::serialport_variable_link.value(key).parity_value == QSerialPort::Parity::EvenParity)
		{
			wi_dataIList.parity_value = "偶";
		}
		else if (gVariable::serialport_variable_link.value(key).parity_value == QSerialPort::Parity::MarkParity)
		{
			wi_dataIList.parity_value = "标志";
		}
		else if (gVariable::serialport_variable_link.value(key).parity_value == QSerialPort::Parity::SpaceParity)
		{
			wi_dataIList.parity_value = "空格";
		}
		if (gVariable::serialport_variable_link.value(key).databits_value == QSerialPort::Data5)
		{
			wi_dataIList.databits_value = "5";
		}
		else if (gVariable::serialport_variable_link.value(key).databits_value == QSerialPort::Data6)
		{
			wi_dataIList.databits_value = "6";
		}
		else if (gVariable::serialport_variable_link.value(key).databits_value == QSerialPort::Data7)
		{
			wi_dataIList.databits_value = "7";
		}
		else if (gVariable::serialport_variable_link.value(key).databits_value == QSerialPort::Data8)
		{
			wi_dataIList.databits_value = "8";
		}
		if (gVariable::serialport_variable_link.value(key).stopbits_value == QSerialPort::OneStop)
		{
			wi_dataIList.stopbits_value = "1";
		}
		else if (gVariable::serialport_variable_link.value(key).stopbits_value == QSerialPort::OneAndHalfStop)
		{
			wi_dataIList.stopbits_value = "1.5";
		}
		else if (gVariable::serialport_variable_link.value(key).stopbits_value == QSerialPort::TwoStop)
		{
			wi_dataIList.stopbits_value = "2";
		}
		if (gVariable::serialport_variable_link.value(key).flowcontrol_value == QSerialPort::FlowControl::NoFlowControl)
		{
			wi_dataIList.flowcontrol_value = "无";
		}
		if (gVariable::serialport_variable_link.value(key).flowcontrol_value == QSerialPort::FlowControl::HardwareControl)
		{
			wi_dataIList.flowcontrol_value = "硬件";
		}
		if (gVariable::serialport_variable_link.value(key).flowcontrol_value == QSerialPort::FlowControl::SoftwareControl)
		{
			wi_dataIList.flowcontrol_value = "软件";
		}
		wi_dataIList.remark_value = gVariable::serialport_variable_link.value(key).remark_value;
		dataSerialportRemoteList.append(wi_dataIList);
	}
	dataServerRemoteList.clear();  //TCP/IP服务器
	g_keys.clear();
	g_keys = gVariable::sockettcpserver_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.server_key_value = key;
		wi_dataIList.connect_state = gVariable::sockettcpserver_variable_link.value(key).connect_state;
		wi_dataIList.protocol_value = gVariable::sockettcpserver_variable_link.value(key).protocol_value;
		wi_dataIList.ip_value = gVariable::sockettcpserver_variable_link.value(key).ip_value;
		wi_dataIList.port_value = gVariable::sockettcpserver_variable_link.value(key).port_value;
		wi_dataIList.remark_value = gVariable::sockettcpserver_variable_link.value(key).remark_value;
		dataServerRemoteList.append(wi_dataIList);
	}
	dataClientRemoteList.clear();  //TCP/IP客户端
	g_keys.clear();
	g_keys = gVariable::sockettcpclient_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.client_key_value = key;
		wi_dataIList.connect_state = gVariable::sockettcpclient_variable_link.value(key).connect_state;
		wi_dataIList.protocol_value = gVariable::sockettcpclient_variable_link.value(key).protocol_value;
		wi_dataIList.ip_value = gVariable::sockettcpclient_variable_link.value(key).ip_value;
		wi_dataIList.port_value = gVariable::sockettcpclient_variable_link.value(key).port_value;
		wi_dataIList.remark_value = gVariable::sockettcpclient_variable_link.value(key).remark_value;
		dataClientRemoteList.append(wi_dataIList);
	}
	//相机序列化
	dataCameraLocalList.clear();  //相机
	g_keys.clear();
	g_keys = dataVar::fCameraSetUp->global_camera_content.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.global_key = key;
		wi_dataIList.ccd_index = dataVar::fCameraSetUp->global_camera_content.value(key).ccd_index;
		wi_dataIList.global_exposure = dataVar::fCameraSetUp->global_camera_content.value(key).global_exposure;
		wi_dataIList.global_gain = dataVar::fCameraSetUp->global_camera_content.value(key).global_gain;
		wi_dataIList.global_gamma = dataVar::fCameraSetUp->global_camera_content.value(key).global_gamma;
		wi_dataIList.global_contrast = dataVar::fCameraSetUp->global_camera_content.value(key).global_contrast;
		wi_dataIList.global_trigger_mode = dataVar::fCameraSetUp->global_camera_content.value(key).global_trigger_mode;
		wi_dataIList.global_timeout = dataVar::fCameraSetUp->global_camera_content.value(key).global_timeout;
		wi_dataIList.global_remark = dataVar::fCameraSetUp->global_camera_content.value(key).global_remark;
		if (p == 0)
		{
			wi_dataIList.camera_state = dataVar::camera_state;
		}
		dataCameraLocalList.append(wi_dataIList);
	}
	dataCameraRemoteList.clear();  //相机
	g_keys.clear();
	g_keys = gVariable::camera_variable_link.uniqueKeys();
	for (int p = 0; p < g_keys.length(); p++)
	{
		QString key = g_keys[p];
		WidgetInfo wi_dataIList;
		wi_dataIList.camera_key_value = key;
		wi_dataIList.time_out = gVariable::camera_variable_link.value(key).time_out;
		dataCameraRemoteList.append(wi_dataIList);
	}
}

void QtWidgetsSaveLoad::setChildrenWidgetValue(QList<QWidget*> parent)
{
	//窗体界面控件反序列化
	for (int k = 0; k < parent.size(); k++)
	{
		widgetInfoLists.clear();
		widgetInfoLists = widgetInfoLists_save[k];
		//设置QLabel控件信息
		QList<QLabel*> listQLabel = parent[k]->findChildren<QLabel*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQLabel.size(); j++)
			{
				QLabel* le = listQLabel.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setText(widgetInfoLists.at(i).qLabel_text);
			}
		}
		//设置QLineEdit控件信息
		QList<QLineEdit*> listQLineEdit = parent[k]->findChildren<QLineEdit*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQLineEdit.size(); j++)
			{
				QLineEdit* le = listQLineEdit.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setText(widgetInfoLists.at(i).qLineEdit_text);
			}
		}
		//设置QTextEdit控件信息
		QList<QTextEdit*> listQTextEdit = parent[k]->findChildren<QTextEdit*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQTextEdit.size(); j++)
			{
				QTextEdit* le = listQTextEdit.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setText(widgetInfoLists.at(i).qTextEdit_text);
			}
		}
		//设置QPlainTextEdit控件信息
		QList<QPlainTextEdit*> listQPlainTextEdit = parent[k]->findChildren<QPlainTextEdit*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQPlainTextEdit.size(); j++)
			{
				QPlainTextEdit* le = listQPlainTextEdit.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setPlainText(widgetInfoLists.at(i).qPlainTextEdit_text);
			}
		}
		//设置QCheckBox控件信息
		QList<QCheckBox*> listQCheckBox = parent[k]->findChildren<QCheckBox*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQCheckBox.size(); j++)
			{
				QCheckBox* le = listQCheckBox.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setChecked(widgetInfoLists.at(i).qCheckBox_checked);
			}
		}
		//设置QRadioButton控件信息
		QList<QRadioButton*> listQRadioButton = parent[k]->findChildren<QRadioButton*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQRadioButton.size(); j++)
			{
				QRadioButton* le = listQRadioButton.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setChecked(widgetInfoLists.at(i).qRadioButton_checked);
			}
		}
		//设置QComboBox控件信息
		QList<QComboBox*> listQComboBox = parent[k]->findChildren<QComboBox*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQComboBox.size(); j++)
			{
				QComboBox* le = listQComboBox.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setCurrentText(widgetInfoLists.at(i).qComboBox_currentText);
			}
		}
		//设置QSpinBox控件信息
		QList<QSpinBox*> listQSpinBox = parent[k]->findChildren<QSpinBox*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQSpinBox.size(); j++)
			{
				QSpinBox* le = listQSpinBox.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setValue(widgetInfoLists.at(i).qSpinBox_value);
			}
		}
		//设置QDoubleSpinBox控件信息
		QList<QDoubleSpinBox*> listQDoubleSpinBox = parent[k]->findChildren<QDoubleSpinBox*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQDoubleSpinBox.size(); j++)
			{
				QDoubleSpinBox* le = listQDoubleSpinBox.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
					le->setValue(widgetInfoLists.at(i).qDoubleSpinBox_value);
			}
		}
		//设置QTableWidget控件信息
		QList<QTableWidget*> listQTableWidget = parent[k]->findChildren<QTableWidget*>();
		for (int i = 0; i < widgetInfoLists.size(); i++) {
			for (int j = 0; j < listQTableWidget.size(); j++)
			{
				QTableWidget* le = listQTableWidget.at(j);
				if (le->objectName() == widgetInfoLists.at(i).control_name)
				{
					le->setRowCount(widgetInfoLists.at(i).row_count);  //设置行数
					for (int m = 0; m < le->rowCount(); m++) //取出每个格子的内容
					{
						for (int n = 0; n < le->columnCount(); n++)
						{
							QTableWidgetItem* newItem = new QTableWidgetItem(QString());
							le->setItem(m, n, newItem);
							le->item(m, n)->setText(widgetInfoLists.at(i).qTableWidget_text[m * le->columnCount() + n]);
						}
					}
				}
			}
		}
	}
}

void QtWidgetsSaveLoad::saveToolParam(int index, QString tool_name, QVariant var)
{
	if (tool_name == "获取图像")
	{
		InitImageSourceData init_data;
		init_data = var.value<InitImageSourceData>();
		WidgetInfo wi_dataList;
		wi_dataList.camera_index = init_data.camera_index;
		wi_dataList.g_camera = init_data.g_camera;
		dataImageSourceList[index].append(wi_dataList);
	}
	else if (tool_name == "裁切图像")
	{
		InitCropImageData init_data;
		init_data = var.value<InitCropImageData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.Lenth1 = init_data.Lenth1;
		wi_dataList.Lenth2 = init_data.Lenth2;
		wi_dataList.Pi = init_data.Pi;
		wi_dataList.R = init_data.R;
		wi_dataList.init_points = init_data.init_points;
		wi_dataList.list_ps = init_data.list_ps;
		dataCropImageList[index].append(wi_dataList);
	}
	else if (tool_name == "预处理")
	{
		InitImageMorphologyData init_data;
		init_data = var.value<InitImageMorphologyData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.Lenth1 = init_data.Lenth1;
		wi_dataList.Lenth2 = init_data.Lenth2;
		wi_dataList.Pi = init_data.Pi;
		wi_dataList.R = init_data.R;
		wi_dataList.init_points = init_data.init_points;
		wi_dataList.list_ps = init_data.list_ps;
		dataImageMorphologyList[index].append(wi_dataList);
	}
	else if (tool_name == "图像细化")
	{
		InitSkeletonData init_data;
		init_data = var.value<InitSkeletonData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.Lenth1 = init_data.Lenth1;
		wi_dataList.Lenth2 = init_data.Lenth2;
		wi_dataList.Pi = init_data.Pi;
		wi_dataList.R = init_data.R;
		wi_dataList.init_points = init_data.init_points;
		wi_dataList.list_ps = init_data.list_ps;
		dataSkeletonList[index].append(wi_dataList);
	}
	else if (tool_name == "斑点分析")
	{
		InitBlobDetectorData init_data;
		init_data = var.value<InitBlobDetectorData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.Lenth1 = init_data.Lenth1;
		wi_dataList.Lenth2 = init_data.Lenth2;
		wi_dataList.Pi = init_data.Pi;
		wi_dataList.R = init_data.R;
		wi_dataList.init_points = init_data.init_points;
		wi_dataList.list_ps = init_data.list_ps;
		wi_dataList.color = init_data.color;
		dataBlobDetectorList[index].append(wi_dataList);
	}
	else if (tool_name == "轮廓特征选择")
	{
		InitSelectShapeData init_data;
		init_data = var.value<InitSelectShapeData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.Lenth1 = init_data.Lenth1;
		wi_dataList.Lenth2 = init_data.Lenth2;
		wi_dataList.Pi = init_data.Pi;
		wi_dataList.R = init_data.R;
		wi_dataList.init_points = init_data.init_points;
		wi_dataList.list_ps = init_data.list_ps;
		wi_dataList.color = init_data.color;
		dataSelectShapeList[index].append(wi_dataList);
	}
	else if (tool_name == "图像显示")
	{
		InitImageViewData init_data;
		init_data = var.value<InitImageViewData>();
		WidgetInfo wi_dataList;
		wi_dataList.key = init_data.key;
		wi_dataList.global_pos_xy = init_data.global_pos_xy;
		wi_dataList.global_state = init_data.global_state;
		wi_dataList.global_content = init_data.global_content;
		wi_dataList.global_prefix = init_data.global_prefix;
		wi_dataList.global_OK_text = init_data.global_OK_text;
		wi_dataList.global_NG_text = init_data.global_NG_text;
		wi_dataList.global_ok_color = init_data.global_ok_color;
		wi_dataList.global_ng_color = init_data.global_ng_color;
		wi_dataList.contour_color = init_data.contour_color;
		dataImageViewList[index].append(wi_dataList);
	}
	else if (tool_name == "颜色识别")
	{
		InitColorIdentifyData init_data;
		init_data = var.value<InitColorIdentifyData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.color = init_data.color;
		wi_dataList.srcStandardImage = init_data.srcStandardImage;
		dataColorIdentifyList[index].append(wi_dataList);
	}
	else if (tool_name == "分类器")
	{
		InitClassifierData init_data;
		init_data = var.value<InitClassifierData>();
		WidgetInfo wi_dataList;
		wi_dataList.type_key = init_data.type_key;
		wi_dataList.type_names = init_data.type_names;
		wi_dataList.file_model = init_data.file_model;
		dataClassifierList[index].append(wi_dataList);
	}
	else if (tool_name == "目标跟踪")
	{
		InitCamShiftTrackData init_data;
		init_data = var.value<InitCamShiftTrackData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		dataCamShiftTrackList[index].append(wi_dataList);
	}
	else if (tool_name == "灰度匹配")
	{
		InitTemplateMatchData init_data;
		init_data = var.value<InitTemplateMatchData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.color = init_data.color;
		wi_dataList.srcModelImage = init_data.srcModelImage;
		wi_dataList.datum_center = init_data.datum_center;
		dataTemplateMatchList[index].append(wi_dataList);
	}
	else if (tool_name == "形状匹配")
	{
		InitShapeMatchData init_data;
		init_data = var.value<InitShapeMatchData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.color = init_data.color;
		wi_dataList.srcModelImage = init_data.srcModelImage;
		wi_dataList.datum_center = init_data.datum_center;
		wi_dataList.fileModelName = init_data.fileModelName;
		dataShapeMatchList[index].append(wi_dataList);
	}
	else if (tool_name == "YoloV13")
	{
		InitImageSourceData init_data;
		init_data = var.value<InitImageSourceData>();
		WidgetInfo wi_dataList;
		wi_dataList.camera_index = init_data.camera_index;
		wi_dataList.g_camera = init_data.g_camera;
		dataImageSourceList[index].append(wi_dataList);
	}
	else if (tool_name == "OCR")
	{
		InitImageSourceData init_data;
		init_data = var.value<InitImageSourceData>();
		WidgetInfo wi_dataList;
		wi_dataList.camera_index = init_data.camera_index;
		wi_dataList.g_camera = init_data.g_camera;
		dataImageSourceList[index].append(wi_dataList);
	}
}

void QtWidgetsSaveLoad::saveToolParam2(int index, QString tool_name, QVariant var)
{
	if (tool_name == "测量标定")
	{
		InitMeasureCalibrationData init_data;
		init_data = var.value<InitMeasureCalibrationData>();
		WidgetInfo wi_dataList;
		wi_dataList.PixelEquivalentX = init_data.PixelEquivalentX;
		wi_dataList.PixelEquivalentY = init_data.PixelEquivalentY;
		dataMeasureCalibrationList[index].append(wi_dataList);
	}
	else if (tool_name == "获取边界点")
	{
		InitGetContourPointsData init_data;
		init_data = var.value<InitGetContourPointsData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.width = init_data.width;
		wi_dataList.height = init_data.height;
		wi_dataList.R = init_data.R;
		wi_dataList.color = init_data.color;
		dataGetContourPointsList[index].append(wi_dataList);
	}
	else if (tool_name == "寻找圆")
	{
		InitFindCircleData init_data;
		init_data = var.value<InitFindCircleData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.RadiusMin = init_data.RadiusMin;
		wi_dataList.RadiusMax = init_data.RadiusMax;
		wi_dataList.segment_line_num = init_data.segment_line_num;
		wi_dataList.ring_s_points = init_data.ring_s_points;
		wi_dataList.ring_b_points = init_data.ring_b_points;
		wi_dataList.color = init_data.color;
		dataFindCircleList[index].append(wi_dataList);
	}
	else if (tool_name == "查找圆缺角")
	{
		InitRoundedCornersData init_data;
		init_data = var.value<InitRoundedCornersData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x = init_data.x;
		wi_dataList.y = init_data.y;
		wi_dataList.RadiusMin = init_data.RadiusMin;
		wi_dataList.RadiusMax = init_data.RadiusMax;
		wi_dataList.segment_line_num = init_data.segment_line_num;
		wi_dataList.ring_s_points = init_data.ring_s_points;
		wi_dataList.ring_b_points = init_data.ring_b_points;
		wi_dataList.color = init_data.color;
		dataRoundedCornersList[index].append(wi_dataList);
	}
	else if (tool_name == "寻找直线")
	{
		InitFindLineData init_data;
		init_data = var.value<InitFindLineData>();
		WidgetInfo wi_dataList;
		wi_dataList.use_roi = init_data.use_roi;
		wi_dataList.type = init_data.type;
		wi_dataList.x1 = init_data.x1;
		wi_dataList.y1 = init_data.y1;
		wi_dataList.x2 = init_data.x2;
		wi_dataList.y2 = init_data.y2;
		wi_dataList.height = init_data.height;
		wi_dataList.row = init_data.row;
		wi_dataList.col = init_data.col;
		wi_dataList.len1 = init_data.len1;
		wi_dataList.len2 = init_data.len2;
		wi_dataList.angle = init_data.angle;
		wi_dataList.pp1 = init_data.pp1;
		wi_dataList.pp2 = init_data.pp2;
		wi_dataList.segment_line_num = init_data.segment_line_num;
		wi_dataList.line_s_points = init_data.line_s_points;
		wi_dataList.line_b_points = init_data.line_b_points;
		wi_dataList.color = init_data.color;
		dataFindLineList[index].append(wi_dataList);
	}
	else if (tool_name == "边缘宽度测量")
	{
		for (int i  = 0;i  < var.toList().size();i ++)
		{
			InitEdgeWidthMeasureData init_data;
			init_data = var.toList()[i].value<InitEdgeWidthMeasureData>();
			WidgetInfo wi_dataList;
			wi_dataList.use_roi = init_data.use_roi;
			wi_dataList.type = init_data.type;
			wi_dataList.x1 = init_data.x1;
			wi_dataList.y1 = init_data.y1;
			wi_dataList.x2 = init_data.x2;
			wi_dataList.y2 = init_data.y2;
			wi_dataList.height = init_data.height;
			wi_dataList.row = init_data.row;
			wi_dataList.col = init_data.col;
			wi_dataList.len1 = init_data.len1;
			wi_dataList.len2 = init_data.len2;
			wi_dataList.angle = init_data.angle;
			wi_dataList.pp1 = init_data.pp1;
			wi_dataList.pp2 = init_data.pp2;
			wi_dataList.segment_line_num = init_data.segment_line_num;
			wi_dataList.line_s_points = init_data.line_s_points;
			wi_dataList.line_b_points = init_data.line_b_points;
			wi_dataList.color = init_data.color;
			dataEdgeWidthMeasureList[index].append(wi_dataList);
		}		
	}
	else if (tool_name == "导出CSV")
	{
		InitExportCsvData init_data;
		init_data = var.value<InitExportCsvData>();
		WidgetInfo wi_dataList;
		wi_dataList.csv_key = init_data.csv_key;
		wi_dataList.csv_names = init_data.csv_names;
		wi_dataList.dirPath = init_data.dirPath;
		dataExportCsvList[index].append(wi_dataList);
	}
	else if (tool_name == "扩展库")
	{
		InitExtensionLibraryData init_data;
		init_data = var.value<InitExtensionLibraryData>();
		WidgetInfo wi_dataList;
		wi_dataList.image_link = init_data.image_link;
		wi_dataList.dirPath = init_data.dirPath;
		dataExtensionLibraryList[index].append(wi_dataList);
	}
	else if (tool_name == "跳转语句")
	{
		InitLogicGotoData init_data;
		init_data = var.value<InitLogicGotoData>();
		WidgetInfo wi_dataList;
		wi_dataList.goto_index = init_data.goto_index;
		wi_dataList.g_tools = init_data.g_tools;
		dataLogicGotoList[index].append(wi_dataList);
	}
}

void QtWidgetsSaveLoad::saveToolParam3(int index, QString tool_name, QVariant var)
{
	if (tool_name == "通用I/O")
	{
		InitGeneralIoData init_data;
		init_data = var.value<InitGeneralIoData>();
		WidgetInfo wi_dataList;
		wi_dataList.io_index = init_data.io_index;
		wi_dataList.io_tools = init_data.io_tools;
		dataGeneralIoList[index].append(wi_dataList);
	}
	else if (tool_name == "PLC通信")
	{
		InitPlcCommunicateData init_data;
		init_data = var.value<InitPlcCommunicateData>();
		WidgetInfo wi_dataList;
		wi_dataList.plc_index = init_data.plc_index;
		wi_dataList.plc_tools = init_data.plc_tools;
		wi_dataList.plc_key = init_data.plc_key;
		wi_dataList.mit_code = init_data.mit_code;
		wi_dataList.mit_state = init_data.mit_state;
		wi_dataList.mit_method = init_data.mit_method;
		wi_dataList.mit_address = init_data.mit_address;
		wi_dataList.mit_data = init_data.mit_data;
		dataPlcCommunicateList[index].append(wi_dataList);
	}
	else if (tool_name == "串口通信")
	{
		InitSerialPortData init_data;
		init_data = var.value<InitSerialPortData>();
		WidgetInfo wi_dataList;
		wi_dataList.sport_index = init_data.sport_index;
		wi_dataList.sport_tools = init_data.sport_tools;
		dataSerialPortList[index].append(wi_dataList);
	}
	else if (tool_name == "TCP/IP客户端")
	{
		InitSocketTcpClientData init_data;
		init_data = var.value<InitSocketTcpClientData>();
		WidgetInfo wi_dataList;
		wi_dataList.client_index = init_data.client_index;
		wi_dataList.client_tools = init_data.client_tools;
		dataSocketTcpClientList[index].append(wi_dataList);
	}
	else if (tool_name == "TCP/IP服务器")
	{
		InitSocketTcpServerData init_data;
		init_data = var.value<InitSocketTcpServerData>();
		WidgetInfo wi_dataList;
		wi_dataList.server_index = init_data.server_index;
		wi_dataList.server_tools = init_data.server_tools;
		dataSocketTcpServerList[index].append(wi_dataList);
	}
}

void  QtWidgetsSaveLoad::saveToFile(QList<QWidget*> parent)
{
	//收集控件信息，保存到QList<WidgetInfo>中
	gatherChildrenWidgetInfo(parent);
	saveParamToFileOne();
	saveParamToFileTwo();
	//把QList<WidgetInfo>序列化到文件中
	QString allpath = workPath + "\\" + filename;
	QFile file(allpath);
	if (file.exists())
	{
		file.remove();
	}
	if (file.open(QIODevice::ReadWrite))
	{
		QDataStream stream(&file);
		stream << widgetInfoLists_save << dataInfoList << dataToolList << dataToolTitleList << dataIoLocalList
			<< dataIoRemoteList << dataPlcLocalList << dataPlcRemoteList << dataSerialportLocalList << dataSerialportRemoteList
			<< dataTcpLocalList << dataServerRemoteList << dataClientRemoteList << dataCameraLocalList << dataCameraRemoteList
			<< dataImageSourceList << dataCropImageList << dataImageMorphologyList << dataSkeletonList << dataBlobDetectorList
			<< dataSelectShapeList << dataImageViewList << dataColorIdentifyList << dataClassifierList << dataCamShiftTrackList
			<< dataTemplateMatchList << dataShapeMatchList << dataMeasureCalibrationList << dataGetContourPointsList
			<< dataFindCircleList << dataRoundedCornersList << dataFindLineList << dataEdgeWidthMeasureList << dataExportCsvList
			<< dataExtensionLibraryList << dataLogicGotoList << dataGeneralIoList << dataPlcCommunicateList << dataSerialPortList
			<< dataSocketTcpClientList << dataSocketTcpServerList;
		file.close();
	}
	else
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(allpath + " save error!");
	}
}

void  QtWidgetsSaveLoad::loadFromFile(QList<QWidget*> parent)
{
	setChildrenWidgetValue(parent);
	dataVar::fGlobalVariable->onButtonCloseClicked();
	dataVar::fProcessSetUp->slot_SetProject(dataVar::projectName);
}

void  QtWidgetsSaveLoad::loadFromFileFirst()
{
	//反序列化读取文件中信息到QList<WidgetInfo>
	QString allpath = workPath + "\\" + filename;
	QFile file(allpath);
	if (file.open(QIODevice::ReadOnly)) {
		QDataStream stream(&file);
		stream >> widgetInfoLists_save >> dataInfoList >> dataToolList >> dataToolTitleList >> dataIoLocalList
			>> dataIoRemoteList >> dataPlcLocalList >> dataPlcRemoteList >> dataSerialportLocalList >> dataSerialportRemoteList
			>> dataTcpLocalList >> dataServerRemoteList >> dataClientRemoteList >> dataCameraLocalList >> dataCameraRemoteList
			>> dataImageSourceList >> dataCropImageList >> dataImageMorphologyList >> dataSkeletonList >> dataBlobDetectorList
			>> dataSelectShapeList >> dataImageViewList >> dataColorIdentifyList >> dataClassifierList >> dataCamShiftTrackList
			>> dataTemplateMatchList >> dataShapeMatchList >> dataMeasureCalibrationList >> dataGetContourPointsList
			>> dataFindCircleList >> dataRoundedCornersList >> dataFindLineList >> dataEdgeWidthMeasureList >> dataExportCsvList
			>> dataExtensionLibraryList >> dataLogicGotoList >> dataGeneralIoList >> dataPlcCommunicateList >> dataSerialPortList
			>> dataSocketTcpClientList >> dataSocketTcpServerList;
		file.close();
	}
	else
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(allpath + " load error!");
	}
	//反序列化流程树列表
	int tree_count = -1;
	dataVar::fProItemTab->treeItem.clear();
	dataVar::fProItemTab->treeItem.resize(20);
	for (int i = 0; i < dataInfoList.size(); i++)
	{
		if (dataInfoList.at(i).tree_text != QString())
		{
			++tree_count;
			dataVar::fProItemTab->treeItem[tree_count] = new QTreeWidgetItem();
			dataVar::fProItemTab->treeItem[tree_count]->setText(0, dataInfoList.at(i).tree_text);
			dataVar::fProItemTab->treeItem[tree_count]->setIcon(0, dataInfoList.at(i).tree_icon);
			dataVar::fProItemTab->itemParent->insertChild(tree_count, dataVar::fProItemTab->treeItem[tree_count]);
			//反序列化记录流程对应的索引值	
			dataVar::fProItemTab->m_pro_value.insert(dataVar::fProItemTab->treeItem[tree_count], tree_count);
		}
	}
	//反序列化初始化流程
	dataVar::fProItemTab->DeserializeInitProcess();
	//反序列化流程工具列表
	int tool_count = -1;
	for (int i = 0; i < dataToolList.size(); i++)
	{
		if (dataToolList.at(i).flowProItemList.size() != 0)
		{
			++tool_count;
			QConfig::ToolBase[tool_count]->m_FlowSortList = dataToolList.at(i).flowProItemList;
			for (int j = 0; j < dataToolList.at(i).flowProItemList.size(); j++)
			{
				QString itemName = dataToolList.at(i).flowProItemList[j];
				QConfig::ToolBase[tool_count]->AddTool(itemName);
				QConfig::ToolBase[tool_count]->AddToolDlg(itemName, dataVar::fProItemTab->GetNewToolDlg(tool_count, itemName, dataVar::fProItemTab->GetProcessItemNum(itemName)));
			}
			gVariable::ScriptEditVar.flow_pro_item_list = QConfig::ToolBase[tool_count]->m_FlowSortList;
			gVariable::ScriptEditVar.item_id = tool_count;
			gVariable::scriptedit_variable_link.insert(QConfig::ToolBase[tool_count], gVariable::ScriptEditVar);
			QConfig::ToolBase[tool_count]->RunScriptEditToolLink();
		}
	}
	//反序列化流程工具图标列表
	int tool_title_count = -1;
	for (int i = 0; i < dataToolTitleList.size(); i++)
	{
		if (dataToolTitleList.at(i).size() != 0)
		{
			QList<QString> m_states_read;
			++tool_title_count;
			switch (tool_title_count) {
			case 0:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B1->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B1->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B1->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B1);
				}
				break;
			case 1:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B2->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B2->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B2->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B2);
				}
				break;
			case 2:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B3->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B3->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B3->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B3);
				}
				break;
			case 3:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B4->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B4->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B4->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B4);
				}
				break;
			case 4:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B5->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B5->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B5->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B5);
				}
				break;
			case 5:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B6->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B6->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B6->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B6);
				}
				break;
			case 6:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B7->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B7->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B7->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B7);
				}
				break;
			case 7:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B8->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B8->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B8->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B8);
				}
				break;
			case 8:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B9->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B9->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B9->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B9);
				}
				break;
			case 9:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B10->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B10->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B10->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B10);
				}
				break;
			case 10:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B11->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B11->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B11->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B11);
				}
				break;
			case 11:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B12->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B12->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B12->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B12);
				}
				break;
			case 12:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B13->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B13->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B13->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B13);
				}
				break;
			case 13:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B14->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B14->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B14->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B14);
				}
				break;
			case 14:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B15->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B15->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B15->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B15);
				}
				break;
			case 15:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B16->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B16->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B16->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B16);
				}
				break;
			case 16:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B17->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B17->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B17->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B17);
				}
				break;
			case 17:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B18->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B18->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B18->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B18);
				}
				break;
			case 18:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B19->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B19->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B19->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B19);
				}
				break;
			case 19:
				for (int j = 0; j < dataToolTitleList.at(i).size(); j++)
				{
					DragListItem dragListItem;
					dragListItem.m_nId = dataToolTitleList.at(i).at(j).m_nId;
					dragListItem.m_pixmap = dataToolTitleList.at(i).at(j).m_pixmap;
					dragListItem.m_strTitle = dataToolTitleList.at(i).at(j).m_strTitle;
					dragListItem.m_strSubTitle = dataToolTitleList.at(i).at(j).m_strSubTitle;
					dragListItem.m_strDescribeTitle = dataToolTitleList.at(i).at(j).m_strDescribeTitle;
					dragListItem.m_rectItem = dataToolTitleList.at(i).at(j).m_rectItem;
					dragListItem.m_rectSub = dataToolTitleList.at(i).at(j).m_rectSub;
					dragListItem.m_subPixmap = dataToolTitleList.at(i).at(j).m_subPixmap;
					dataVar::fProItemTab->TempDragListWidget_B20->d->m_items.insert(dataToolTitleList.at(i).at(j).m_index, dragListItem);
					dataVar::fProItemTab->TempDragListWidget_B20->d->ItemContent = dataToolTitleList.at(i).at(j).itemContent;
					if (j == 0)
					{
						m_states_read.clear();
						m_states_read = dataToolTitleList.at(i).at(j).m_states;
					}
				}
				for (int j = 0; j < m_states_read.size(); j++)
				{
					dataVar::fProItemTab->TempDragListWidget_B20->d->m_states.insert(m_states_read[j], dataVar::fProItemTab->TempDragListWidget_B20);
				}
				break;
			}
		}
	}
	//反序列化仪器仪表
	for (int i = 0; i < dataIoLocalList.size(); i++)  //通用I/O	
	{
		if (i == 0)
		{
			dataVar::io_client_ip = dataIoLocalList.at(i).io_client_ip;
			dataVar::io_client_port = dataIoLocalList.at(i).io_client_port;
		}
		dataVar::fInstrumentation->IoContent.global_ip = dataIoLocalList.at(i).global_ip;
		dataVar::fInstrumentation->IoContent.global_port = dataIoLocalList.at(i).global_port;
		dataVar::fInstrumentation->IoContent.global_timeout = dataIoLocalList.at(i).global_timeout;
		dataVar::fInstrumentation->IoContent.global_remark = dataIoLocalList.at(i).global_remark;
		dataVar::fInstrumentation->global_io_content.insert(dataIoLocalList.at(i).global_key, dataVar::fInstrumentation->IoContent);
	}
	for (int i = 0; i < dataPlcLocalList.size(); i++)  //PLC通信	
	{
		if (i == 0)
		{
			dataVar::mit_plc_client_ip = dataPlcLocalList.at(i).mit_plc_client_ip;
			dataVar::mit_plc_client_port = dataPlcLocalList.at(i).mit_plc_client_port;
		}
		dataVar::fInstrumentation->PlcContent.global_ip = dataPlcLocalList.at(i).global_ip;
		dataVar::fInstrumentation->PlcContent.global_port = dataPlcLocalList.at(i).global_port;
		dataVar::fInstrumentation->PlcContent.global_timeout = dataPlcLocalList.at(i).global_timeout;
		dataVar::fInstrumentation->PlcContent.global_remark = dataPlcLocalList.at(i).global_remark;
		dataVar::fInstrumentation->global_plc_content.insert(dataPlcLocalList.at(i).global_key, dataVar::fInstrumentation->PlcContent);
	}
	for (int i = 0; i < dataSerialportLocalList.size(); i++)  //串口通信	
	{
		dataVar::fInstrumentation->SerialPortContent.global_serial_port = dataSerialportLocalList.at(i).global_serial_port;
		dataVar::fInstrumentation->SerialPortContent.global_baud_rate = dataSerialportLocalList.at(i).global_baud_rate;
		dataVar::fInstrumentation->SerialPortContent.global_check_digit = dataSerialportLocalList.at(i).global_check_digit;
		dataVar::fInstrumentation->SerialPortContent.global_data_bits = dataSerialportLocalList.at(i).global_data_bits;
		dataVar::fInstrumentation->SerialPortContent.global_stop_bit = dataSerialportLocalList.at(i).global_stop_bit;
		dataVar::fInstrumentation->SerialPortContent.global_flowcontrol = dataSerialportLocalList.at(i).global_flowcontrol;
		dataVar::fInstrumentation->SerialPortContent.global_remark = dataSerialportLocalList.at(i).global_remark;
		dataVar::fInstrumentation->global_serialport_content.insert(dataSerialportLocalList.at(i).global_key, dataVar::fInstrumentation->SerialPortContent);
	}
	for (int i = 0; i < dataTcpLocalList.size(); i++)  //TCP/IP通信	
	{
		if (i == 0)
		{
			dataVar::tcp_client_ip = dataTcpLocalList.at(i).tcp_client_ip;
			dataVar::tcp_client_port = dataTcpLocalList.at(i).tcp_client_port;
		}
		dataVar::fInstrumentation->TcpContent.global_protocol = dataTcpLocalList.at(i).global_protocol;
		dataVar::fInstrumentation->TcpContent.global_ip = dataTcpLocalList.at(i).global_ip;
		dataVar::fInstrumentation->TcpContent.global_port = dataTcpLocalList.at(i).global_port;
		dataVar::fInstrumentation->TcpContent.global_remark = dataTcpLocalList.at(i).global_remark;
		dataVar::fInstrumentation->global_tcp_content.insert(dataTcpLocalList.at(i).global_key, dataVar::fInstrumentation->TcpContent);
	}
	for (int i = 0; i < dataIoRemoteList.size(); i++)  //通用I/O	
	{
		gVariable::GeneralIoVar.connect_state = dataIoRemoteList.at(i).connect_state;
		gVariable::GeneralIoVar.ip_value = dataIoRemoteList.at(i).ip_value;
		gVariable::GeneralIoVar.port_value = dataIoRemoteList.at(i).port_value;
		gVariable::GeneralIoVar.over_time_value = dataIoRemoteList.at(i).over_time_value;
		gVariable::GeneralIoVar.remark_value = dataIoRemoteList.at(i).remark_value;
		gVariable::generalio_variable_link.insert(dataIoRemoteList.at(i).io_key_value, gVariable::GeneralIoVar);
		//初始化通用I/O连接
		dataVar::fInstrumentation->InitIoConnect(dataIoRemoteList.at(i).io_key_value, dataIoRemoteList.at(i).ip_value, dataIoRemoteList.at(i).port_value, dataIoRemoteList.at(i).over_time_value);
	}
	for (int i = 0; i < dataPlcRemoteList.size(); i++)  //PLC通信	
	{
		gVariable::PlcCommunicateVar.connect_state = dataPlcRemoteList.at(i).connect_state;
		gVariable::PlcCommunicateVar.plc_type = dataPlcRemoteList.at(i).plc_type;
		gVariable::PlcCommunicateVar.mit_ip_value = dataPlcRemoteList.at(i).mit_ip_value;
		gVariable::PlcCommunicateVar.mit_port_value = dataPlcRemoteList.at(i).mit_port_value;
		gVariable::PlcCommunicateVar.mit_over_time_value = dataPlcRemoteList.at(i).mit_over_time_value;
		gVariable::PlcCommunicateVar.mit_remark_value = dataPlcRemoteList.at(i).mit_remark_value;
		gVariable::plccommunicate_variable_link.insert(dataPlcRemoteList.at(i).plc_key_value, gVariable::PlcCommunicateVar);
		//初始化PLC通信连接
		dataVar::fInstrumentation->InitPlcConnect(dataPlcRemoteList.at(i).plc_key_value, dataPlcRemoteList.at(i).mit_ip_value, dataPlcRemoteList.at(i).mit_port_value, dataPlcRemoteList.at(i).mit_over_time_value);
	}
	for (int i = 0; i < dataSerialportRemoteList.size(); i++)  //串口通信	
	{
		gVariable::SerialPortVar.connect_state = dataSerialportRemoteList.at(i).connect_state;
		gVariable::SerialPortVar.portname_value = dataSerialportRemoteList.at(i).portname_value;
		gVariable::SerialPortVar.baudrate_value = dataSerialportRemoteList.at(i).baudrate_value;
		QSerialPort::Parity parity;   //校验位
		if (dataSerialportRemoteList.at(i).parity_value == "无")
		{
			parity = QSerialPort::NoParity;
		}
		else if (dataSerialportRemoteList.at(i).parity_value == "奇")
		{
			parity = QSerialPort::Parity::OddParity;
		}
		else if (dataSerialportRemoteList.at(i).parity_value == "偶")
		{
			parity = QSerialPort::Parity::EvenParity;
		}
		else if (dataSerialportRemoteList.at(i).parity_value == "标志")
		{
			parity = QSerialPort::Parity::MarkParity;
		}
		else if (dataSerialportRemoteList.at(i).parity_value == "空格")
		{
			parity = QSerialPort::Parity::SpaceParity;
		}
		gVariable::SerialPortVar.parity_value = parity;
		QSerialPort::DataBits dataBits;  //数据位
		if (dataSerialportRemoteList.at(i).databits_value == "5")
		{
			dataBits = QSerialPort::Data5;
		}
		else if (dataSerialportRemoteList.at(i).databits_value == "6")
		{
			dataBits = QSerialPort::Data6;
		}
		else if (dataSerialportRemoteList.at(i).databits_value == "7")
		{
			dataBits = QSerialPort::Data7;
		}
		else if (dataSerialportRemoteList.at(i).databits_value == "8")
		{
			dataBits = QSerialPort::Data8;
		}
		gVariable::SerialPortVar.databits_value = dataBits;
		QSerialPort::StopBits stopBits;  //停止位
		if (dataSerialportRemoteList.at(i).stopbits_value == "1")
		{
			stopBits = QSerialPort::OneStop;
		}
		else if (dataSerialportRemoteList.at(i).stopbits_value == "1.5")
		{
			stopBits = QSerialPort::OneAndHalfStop;
		}
		else if (dataSerialportRemoteList.at(i).stopbits_value == "2")
		{
			stopBits = QSerialPort::TwoStop;
		}
		gVariable::SerialPortVar.stopbits_value = stopBits;
		QSerialPort::FlowControl flowControl;  //流控制
		if (dataSerialportRemoteList.at(i).flowcontrol_value == "无")
		{
			flowControl = QSerialPort::FlowControl::NoFlowControl;
		}
		else if (dataSerialportRemoteList.at(i).flowcontrol_value == "硬件")
		{
			flowControl = QSerialPort::FlowControl::HardwareControl;
		}
		else if (dataSerialportRemoteList.at(i).flowcontrol_value == "软件")
		{
			flowControl = QSerialPort::FlowControl::SoftwareControl;
		}
		gVariable::SerialPortVar.flowcontrol_value = flowControl;
		gVariable::SerialPortVar.remark_value = dataSerialportRemoteList.at(i).remark_value;
		gVariable::serialport_variable_link.insert(dataSerialportRemoteList.at(i).serialport_key_value, gVariable::SerialPortVar);
		//初始化串口通信连接
		dataVar::fInstrumentation->InitSerialportConnect(dataSerialportRemoteList.at(i).serialport_key_value, dataSerialportRemoteList.at(i).portname_value, dataSerialportRemoteList.at(i).baudrate_value, dataSerialportRemoteList.at(i).parity_value, dataSerialportRemoteList.at(i).databits_value, dataSerialportRemoteList.at(i).stopbits_value, dataSerialportRemoteList.at(i).flowcontrol_value);
	}
	for (int i = 0; i < dataServerRemoteList.size(); i++)  //TCP/IP服务器	
	{
		gVariable::SocketTcpServerVar.connect_state = dataServerRemoteList.at(i).connect_state;
		gVariable::SocketTcpServerVar.protocol_value = dataServerRemoteList.at(i).protocol_value;
		gVariable::SocketTcpServerVar.ip_value = dataServerRemoteList.at(i).ip_value;
		gVariable::SocketTcpServerVar.port_value = dataServerRemoteList.at(i).port_value;
		gVariable::SocketTcpServerVar.remark_value = dataServerRemoteList.at(i).remark_value;
		gVariable::sockettcpserver_variable_link.insert(dataServerRemoteList.at(i).server_key_value, gVariable::SocketTcpServerVar);
		//初始化TCP/IP服务器连接
		dataVar::fInstrumentation->InitServerConnect(dataServerRemoteList.at(i).server_key_value, dataServerRemoteList.at(i).port_value);
	}
	for (int i = 0; i < dataClientRemoteList.size(); i++)  //TCP/IP客户端	
	{
		gVariable::SocketTcpClientVar.connect_state = dataClientRemoteList.at(i).connect_state;
		gVariable::SocketTcpClientVar.protocol_value = dataClientRemoteList.at(i).protocol_value;
		gVariable::SocketTcpClientVar.ip_value = dataClientRemoteList.at(i).ip_value;
		gVariable::SocketTcpClientVar.port_value = dataClientRemoteList.at(i).port_value;
		gVariable::SocketTcpClientVar.remark_value = dataClientRemoteList.at(i).remark_value;
		gVariable::sockettcpclient_variable_link.insert(dataClientRemoteList.at(i).client_key_value, gVariable::SocketTcpClientVar);
		//初始化TCP/IP客户端连接
		dataVar::fInstrumentation->InitClientConnect(dataClientRemoteList.at(i).client_key_value, dataClientRemoteList.at(i).ip_value, dataClientRemoteList.at(i).port_value);
	}
	//反序列化相机
	for (int i = 0; i < dataCameraLocalList.size(); i++)  //相机	
	{
		if (i == 0)
		{
			dataVar::camera_state = dataCameraLocalList.at(i).camera_state;
		}
		dataVar::fCameraSetUp->CameraContent.ccd_index = dataCameraLocalList.at(i).ccd_index;
		dataVar::fCameraSetUp->CameraContent.global_exposure = dataCameraLocalList.at(i).global_exposure;
		dataVar::fCameraSetUp->CameraContent.global_gain = dataCameraLocalList.at(i).global_gain;
		dataVar::fCameraSetUp->CameraContent.global_gamma = dataCameraLocalList.at(i).global_gamma;
		dataVar::fCameraSetUp->CameraContent.global_contrast = dataCameraLocalList.at(i).global_contrast;
		dataVar::fCameraSetUp->CameraContent.global_trigger_mode = dataCameraLocalList.at(i).global_trigger_mode;
		dataVar::fCameraSetUp->CameraContent.global_timeout = dataCameraLocalList.at(i).global_timeout;
		dataVar::fCameraSetUp->CameraContent.global_remark = dataCameraLocalList.at(i).global_remark;
		dataVar::fCameraSetUp->global_camera_content.insert(dataCameraLocalList.at(i).global_key, dataVar::fCameraSetUp->CameraContent);
	}
	for (int i = 0; i < dataCameraRemoteList.size(); i++)  //相机	
	{
		//gVariable::CameraVar.time_out = dataCameraRemoteList.at(i).time_out;
		//gVariable::camera_variable_link.insert(dataCameraRemoteList.at(i).camera_key_value, gVariable::CameraVar);
		//初始化相机连接
		dataVar::fCameraSetUp->InitCameraConnect(dataCameraRemoteList.at(i).camera_key_value);
	}
	//反序列工具的特定参数
	for (int m = 0; m < 20; m++)
	{
		if (QConfig::ToolBase[m] != nullptr)
		{
			int image_source_count = -1;
			int crop_image_count = -1;
			int image_morphology_count = -1;
			int skeleton_count = -1;
			int blob_detector_count = -1;
			int select_shape_count = -1;
			int image_view_count = -1;
			int color_identify_count = -1;
			int classifier_count = -1;
			int camshift_track_count = -1;
			int template_match_count = -1;
			int shape_match_count = -1;
			int measure_calibration_count = -1;
			int get_contour_points_count = -1;
			int find_circle_count = -1;
			int rounded_corners_count = -1;
			int find_line_count = -1;
			int edge_width_measure_count = -1;
			int export_csv_count = -1;
			int extension_library_count = -1;
			int logic_goto_count = -1;
			int general_io_count = -1;
			int plc_communicate_count = -1;
			int serial_port_count = -1;
			int socket_tcp_client_count = -1;
			int socket_tcp_server_count = -1;
			for (int n = 0; n < QConfig::ToolBase[m]->m_Tools.size(); n++)
			{
				int str_count = 0;  //提取不含数字字符串
				for (int k = 0; k < QConfig::ToolBase[m]->m_Tools[n].PublicToolName.length(); k++)
				{
					if (!(QConfig::ToolBase[m]->m_Tools[n].PublicToolName[k] > '0' && QConfig::ToolBase[m]->m_Tools[n].PublicToolName[k] < '9'))
					{
						++str_count;
					}
				}
				QString str_name_buf = QConfig::ToolBase[m]->m_Tools[n].PublicToolName.mid(0, str_count);
				if (str_name_buf == "获取图像")
				{
					++image_source_count;
					for (int s = 0; s < dataImageSourceList[m].size(); s++)
					{
						InitImageSourceData init_data;
						init_data.camera_index = dataImageSourceList[m].at(image_source_count).camera_index;
						init_data.g_camera = dataImageSourceList[m].at(image_source_count).g_camera;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "裁切图像")
				{
					++crop_image_count;
					for (int s = 0; s < dataCropImageList[m].size(); s++)
					{
						InitCropImageData init_data;
						init_data.use_roi = dataCropImageList[m].at(crop_image_count).use_roi;
						init_data.type = dataCropImageList[m].at(crop_image_count).type;
						init_data.x = dataCropImageList[m].at(crop_image_count).x;
						init_data.y = dataCropImageList[m].at(crop_image_count).y;
						init_data.width = dataCropImageList[m].at(crop_image_count).width;
						init_data.height = dataCropImageList[m].at(crop_image_count).height;
						init_data.Lenth1 = dataCropImageList[m].at(crop_image_count).Lenth1;
						init_data.Lenth2 = dataCropImageList[m].at(crop_image_count).Lenth2;
						init_data.Pi = dataCropImageList[m].at(crop_image_count).Pi;
						init_data.R = dataCropImageList[m].at(crop_image_count).R;
						init_data.init_points = dataCropImageList[m].at(crop_image_count).init_points;
						init_data.list_ps = dataCropImageList[m].at(crop_image_count).list_ps;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "预处理")
				{
					++image_morphology_count;
					for (int s = 0; s < dataImageMorphologyList[m].size(); s++)
					{
						InitImageMorphologyData init_data;
						init_data.use_roi = dataImageMorphologyList[m].at(image_morphology_count).use_roi;
						init_data.type = dataImageMorphologyList[m].at(image_morphology_count).type;
						init_data.x = dataImageMorphologyList[m].at(image_morphology_count).x;
						init_data.y = dataImageMorphologyList[m].at(image_morphology_count).y;
						init_data.width = dataImageMorphologyList[m].at(image_morphology_count).width;
						init_data.height = dataImageMorphologyList[m].at(image_morphology_count).height;
						init_data.Lenth1 = dataImageMorphologyList[m].at(image_morphology_count).Lenth1;
						init_data.Lenth2 = dataImageMorphologyList[m].at(image_morphology_count).Lenth2;
						init_data.Pi = dataImageMorphologyList[m].at(image_morphology_count).Pi;
						init_data.R = dataImageMorphologyList[m].at(image_morphology_count).R;
						init_data.init_points = dataImageMorphologyList[m].at(image_morphology_count).init_points;
						init_data.list_ps = dataImageMorphologyList[m].at(image_morphology_count).list_ps;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "图像细化")
				{
					++skeleton_count;
					for (int s = 0; s < dataSkeletonList[m].size(); s++)
					{
						InitSkeletonData init_data;
						init_data.use_roi = dataSkeletonList[m].at(skeleton_count).use_roi;
						init_data.type = dataSkeletonList[m].at(skeleton_count).type;
						init_data.x = dataSkeletonList[m].at(skeleton_count).x;
						init_data.y = dataSkeletonList[m].at(skeleton_count).y;
						init_data.width = dataSkeletonList[m].at(skeleton_count).width;
						init_data.height = dataSkeletonList[m].at(skeleton_count).height;
						init_data.Lenth1 = dataSkeletonList[m].at(skeleton_count).Lenth1;
						init_data.Lenth2 = dataSkeletonList[m].at(skeleton_count).Lenth2;
						init_data.Pi = dataSkeletonList[m].at(skeleton_count).Pi;
						init_data.R = dataSkeletonList[m].at(skeleton_count).R;
						init_data.init_points = dataSkeletonList[m].at(skeleton_count).init_points;
						init_data.list_ps = dataSkeletonList[m].at(skeleton_count).list_ps;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "斑点分析")
				{
					++blob_detector_count;
					for (int s = 0; s < dataBlobDetectorList[m].size(); s++)
					{
						InitBlobDetectorData init_data;
						init_data.use_roi = dataBlobDetectorList[m].at(blob_detector_count).use_roi;
						init_data.type = dataBlobDetectorList[m].at(blob_detector_count).type;
						init_data.x = dataBlobDetectorList[m].at(blob_detector_count).x;
						init_data.y = dataBlobDetectorList[m].at(blob_detector_count).y;
						init_data.width = dataBlobDetectorList[m].at(blob_detector_count).width;
						init_data.height = dataBlobDetectorList[m].at(blob_detector_count).height;
						init_data.Lenth1 = dataBlobDetectorList[m].at(blob_detector_count).Lenth1;
						init_data.Lenth2 = dataBlobDetectorList[m].at(blob_detector_count).Lenth2;
						init_data.Pi = dataBlobDetectorList[m].at(blob_detector_count).Pi;
						init_data.R = dataBlobDetectorList[m].at(blob_detector_count).R;
						init_data.init_points = dataBlobDetectorList[m].at(blob_detector_count).init_points;
						init_data.list_ps = dataBlobDetectorList[m].at(blob_detector_count).list_ps;
						init_data.color = dataBlobDetectorList[m].at(blob_detector_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "轮廓特征选择")
				{
					++select_shape_count;
					for (int s = 0; s < dataSelectShapeList[m].size(); s++)
					{
						InitSelectShapeData init_data;
						init_data.use_roi = dataSelectShapeList[m].at(select_shape_count).use_roi;
						init_data.type = dataSelectShapeList[m].at(select_shape_count).type;
						init_data.x = dataSelectShapeList[m].at(select_shape_count).x;
						init_data.y = dataSelectShapeList[m].at(select_shape_count).y;
						init_data.width = dataSelectShapeList[m].at(select_shape_count).width;
						init_data.height = dataSelectShapeList[m].at(select_shape_count).height;
						init_data.Lenth1 = dataSelectShapeList[m].at(select_shape_count).Lenth1;
						init_data.Lenth2 = dataSelectShapeList[m].at(select_shape_count).Lenth2;
						init_data.Pi = dataSelectShapeList[m].at(select_shape_count).Pi;
						init_data.R = dataSelectShapeList[m].at(select_shape_count).R;
						init_data.init_points = dataSelectShapeList[m].at(select_shape_count).init_points;
						init_data.list_ps = dataSelectShapeList[m].at(select_shape_count).list_ps;
						init_data.color = dataSelectShapeList[m].at(select_shape_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "图像显示")
				{
					++image_view_count;
					for (int s = 0; s < dataImageViewList[m].size(); s++)
					{
						InitImageViewData init_data;
						init_data.key = dataImageViewList[m].at(image_view_count).key;
						init_data.global_pos_xy = dataImageViewList[m].at(image_view_count).global_pos_xy;
						init_data.global_state = dataImageViewList[m].at(image_view_count).global_state;
						init_data.global_content = dataImageViewList[m].at(image_view_count).global_content;
						init_data.global_prefix = dataImageViewList[m].at(image_view_count).global_prefix;
						init_data.global_OK_text = dataImageViewList[m].at(image_view_count).global_OK_text;
						init_data.global_NG_text = dataImageViewList[m].at(image_view_count).global_NG_text;
						init_data.global_ok_color = dataImageViewList[m].at(image_view_count).global_ok_color;
						init_data.global_ng_color = dataImageViewList[m].at(image_view_count).global_ng_color;
						init_data.contour_color = dataImageViewList[m].at(image_view_count).contour_color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "颜色识别")
				{
					++color_identify_count;
					for (int s = 0; s < dataColorIdentifyList[m].size(); s++)
					{
						InitColorIdentifyData init_data;
						init_data.use_roi = dataColorIdentifyList[m].at(color_identify_count).use_roi;
						init_data.x = dataColorIdentifyList[m].at(color_identify_count).x;
						init_data.y = dataColorIdentifyList[m].at(color_identify_count).y;
						init_data.width = dataColorIdentifyList[m].at(color_identify_count).width;
						init_data.height = dataColorIdentifyList[m].at(color_identify_count).height;
						init_data.color = dataColorIdentifyList[m].at(color_identify_count).color;
						init_data.srcStandardImage = dataColorIdentifyList[m].at(color_identify_count).srcStandardImage;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "分类器")
				{
					++classifier_count;
					for (int s = 0; s < dataClassifierList[m].size(); s++)
					{
						InitClassifierData init_data;
						init_data.type_key = dataClassifierList[m].at(classifier_count).type_key;
						init_data.type_names = dataClassifierList[m].at(classifier_count).type_names;
						init_data.file_model = dataClassifierList[m].at(classifier_count).file_model;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "目标跟踪")
				{
					++camshift_track_count;
					for (int s = 0; s < dataCamShiftTrackList[m].size(); s++)
					{
						InitCamShiftTrackData init_data;
						init_data.use_roi = dataCamShiftTrackList[m].at(camshift_track_count).use_roi;
						init_data.x = dataCamShiftTrackList[m].at(camshift_track_count).x;
						init_data.y = dataCamShiftTrackList[m].at(camshift_track_count).y;
						init_data.width = dataCamShiftTrackList[m].at(camshift_track_count).width;
						init_data.height = dataCamShiftTrackList[m].at(camshift_track_count).height;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "灰度匹配")
				{
					++template_match_count;
					for (int s = 0; s < dataTemplateMatchList[m].size(); s++)
					{
						InitTemplateMatchData init_data;
						init_data.use_roi = dataTemplateMatchList[m].at(template_match_count).use_roi;
						init_data.x = dataTemplateMatchList[m].at(template_match_count).x;
						init_data.y = dataTemplateMatchList[m].at(template_match_count).y;
						init_data.width = dataTemplateMatchList[m].at(template_match_count).width;
						init_data.height = dataTemplateMatchList[m].at(template_match_count).height;
						init_data.color = dataTemplateMatchList[m].at(template_match_count).color;
						init_data.srcModelImage = dataTemplateMatchList[m].at(template_match_count).srcModelImage;
						init_data.datum_center = dataTemplateMatchList[m].at(template_match_count).datum_center;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "形状匹配")
				{
					++shape_match_count;
					for (int s = 0; s < dataShapeMatchList[m].size(); s++)
					{
						InitShapeMatchData init_data;
						init_data.use_roi = dataShapeMatchList[m].at(shape_match_count).use_roi;
						init_data.x = dataShapeMatchList[m].at(shape_match_count).x;
						init_data.y = dataShapeMatchList[m].at(shape_match_count).y;
						init_data.width = dataShapeMatchList[m].at(shape_match_count).width;
						init_data.height = dataShapeMatchList[m].at(shape_match_count).height;
						init_data.color = dataShapeMatchList[m].at(shape_match_count).color;
						init_data.srcModelImage = dataShapeMatchList[m].at(shape_match_count).srcModelImage;
						init_data.datum_center = dataShapeMatchList[m].at(shape_match_count).datum_center;
						init_data.fileModelName = dataShapeMatchList[m].at(shape_match_count).fileModelName;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "测量标定")
				{
					++measure_calibration_count;
					for (int s = 0; s < dataMeasureCalibrationList[m].size(); s++)
					{
						InitMeasureCalibrationData init_data;
						init_data.PixelEquivalentX = dataMeasureCalibrationList[m].at(measure_calibration_count).PixelEquivalentX;
						init_data.PixelEquivalentY = dataMeasureCalibrationList[m].at(measure_calibration_count).PixelEquivalentY;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "获取边界点")
				{
					++get_contour_points_count;
					for (int s = 0; s < dataGetContourPointsList[m].size(); s++)
					{
						InitGetContourPointsData init_data;
						init_data.use_roi = dataGetContourPointsList[m].at(get_contour_points_count).use_roi;
						init_data.type = dataGetContourPointsList[m].at(get_contour_points_count).type;
						init_data.x = dataGetContourPointsList[m].at(get_contour_points_count).x;
						init_data.y = dataGetContourPointsList[m].at(get_contour_points_count).y;
						init_data.width = dataGetContourPointsList[m].at(get_contour_points_count).width;
						init_data.height = dataGetContourPointsList[m].at(get_contour_points_count).height;
						init_data.R = dataGetContourPointsList[m].at(get_contour_points_count).R;
						init_data.color = dataGetContourPointsList[m].at(get_contour_points_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "寻找圆")
				{
					++find_circle_count;
					for (int s = 0; s < dataFindCircleList[m].size(); s++)
					{
						InitFindCircleData init_data;
						init_data.use_roi = dataFindCircleList[m].at(find_circle_count).use_roi;
						init_data.type = dataFindCircleList[m].at(find_circle_count).type;
						init_data.x = dataFindCircleList[m].at(find_circle_count).x;
						init_data.y = dataFindCircleList[m].at(find_circle_count).y;
						init_data.RadiusMin = dataFindCircleList[m].at(find_circle_count).RadiusMin;
						init_data.RadiusMax = dataFindCircleList[m].at(find_circle_count).RadiusMax;
						init_data.segment_line_num = dataFindCircleList[m].at(find_circle_count).segment_line_num;
						init_data.ring_s_points = dataFindCircleList[m].at(find_circle_count).ring_s_points;
						init_data.ring_b_points = dataFindCircleList[m].at(find_circle_count).ring_b_points;
						init_data.color = dataFindCircleList[m].at(find_circle_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "查找圆缺角")
				{
					++rounded_corners_count;
					for (int s = 0; s < dataRoundedCornersList[m].size(); s++)
					{
						InitRoundedCornersData init_data;
						init_data.use_roi = dataRoundedCornersList[m].at(rounded_corners_count).use_roi;
						init_data.type = dataRoundedCornersList[m].at(rounded_corners_count).type;
						init_data.x = dataRoundedCornersList[m].at(rounded_corners_count).x;
						init_data.y = dataRoundedCornersList[m].at(rounded_corners_count).y;
						init_data.RadiusMin = dataRoundedCornersList[m].at(rounded_corners_count).RadiusMin;
						init_data.RadiusMax = dataRoundedCornersList[m].at(rounded_corners_count).RadiusMax;
						init_data.segment_line_num = dataRoundedCornersList[m].at(rounded_corners_count).segment_line_num;
						init_data.ring_s_points = dataRoundedCornersList[m].at(rounded_corners_count).ring_s_points;
						init_data.ring_b_points = dataRoundedCornersList[m].at(rounded_corners_count).ring_b_points;
						init_data.color = dataRoundedCornersList[m].at(rounded_corners_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "寻找直线")
				{
					++find_line_count;
					for (int s = 0; s < dataFindLineList[m].size(); s++)
					{
						InitFindLineData init_data;
						init_data.use_roi = dataFindLineList[m].at(find_line_count).use_roi;
						init_data.type = dataFindLineList[m].at(find_line_count).type;
						init_data.x1 = dataFindLineList[m].at(find_line_count).x1;
						init_data.y1 = dataFindLineList[m].at(find_line_count).y1;
						init_data.x2 = dataFindLineList[m].at(find_line_count).x2;
						init_data.y2 = dataFindLineList[m].at(find_line_count).y2;
						init_data.height = dataFindLineList[m].at(find_line_count).height;
						init_data.row = dataFindLineList[m].at(find_line_count).row;
						init_data.col = dataFindLineList[m].at(find_line_count).col;
						init_data.len1 = dataFindLineList[m].at(find_line_count).len1;
						init_data.len2 = dataFindLineList[m].at(find_line_count).len2;
						init_data.angle = dataFindLineList[m].at(find_line_count).angle;
						init_data.pp1 = dataFindLineList[m].at(find_line_count).pp1;
						init_data.pp2 = dataFindLineList[m].at(find_line_count).pp2;
						init_data.segment_line_num = dataFindLineList[m].at(find_line_count).segment_line_num;
						init_data.line_s_points = dataFindLineList[m].at(find_line_count).line_s_points;
						init_data.line_b_points = dataFindLineList[m].at(find_line_count).line_b_points;
						init_data.color = dataFindLineList[m].at(find_line_count).color;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "边缘宽度测量")
				{
					++edge_width_measure_count;
					QVariantList varList = QVariantList();
					for (int s = 0; s < dataEdgeWidthMeasureList[m].size(); s++)
					{
						InitEdgeWidthMeasureData init_data;
						init_data.use_roi = dataEdgeWidthMeasureList[m].at(s).use_roi;
						init_data.type = dataEdgeWidthMeasureList[m].at(s).type;
						init_data.x1 = dataEdgeWidthMeasureList[m].at(s).x1;
						init_data.y1 = dataEdgeWidthMeasureList[m].at(s).y1;
						init_data.x2 = dataEdgeWidthMeasureList[m].at(s).x2;
						init_data.y2 = dataEdgeWidthMeasureList[m].at(s).y2;
						init_data.height = dataEdgeWidthMeasureList[m].at(s).height;
						init_data.row = dataEdgeWidthMeasureList[m].at(s).row;
						init_data.col = dataEdgeWidthMeasureList[m].at(s).col;
						init_data.len1 = dataEdgeWidthMeasureList[m].at(s).len1;
						init_data.len2 = dataEdgeWidthMeasureList[m].at(s).len2;
						init_data.angle = dataEdgeWidthMeasureList[m].at(s).angle;
						init_data.pp1 = dataEdgeWidthMeasureList[m].at(s).pp1;
						init_data.pp2 = dataEdgeWidthMeasureList[m].at(s).pp2;
						init_data.segment_line_num = dataEdgeWidthMeasureList[m].at(s).segment_line_num;
						init_data.line_s_points = dataEdgeWidthMeasureList[m].at(s).line_s_points;
						init_data.line_b_points = dataEdgeWidthMeasureList[m].at(s).line_b_points;
						init_data.color = dataEdgeWidthMeasureList[m].at(s).color;
						QVariant var = QVariant::fromValue(init_data);
						varList.append(var);
					}
					QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(varList);
				}
				else if (str_name_buf == "导出CSV")
				{
					++export_csv_count;
					for (int s = 0; s < dataExportCsvList[m].size(); s++)
					{
						InitExportCsvData init_data;
						init_data.csv_key = dataExportCsvList[m].at(export_csv_count).csv_key;
						init_data.csv_names = dataExportCsvList[m].at(export_csv_count).csv_names;
						init_data.dirPath = dataExportCsvList[m].at(export_csv_count).dirPath;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "扩展库")
				{
					++extension_library_count;
					for (int s = 0; s < dataExtensionLibraryList[m].size(); s++)
					{
						InitExtensionLibraryData init_data;
						init_data.image_link = dataExtensionLibraryList[m].at(extension_library_count).image_link;
						init_data.dirPath = dataExtensionLibraryList[m].at(extension_library_count).dirPath;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "跳转语句")
				{
					++logic_goto_count;
					for (int s = 0; s < dataLogicGotoList[m].size(); s++)
					{
						InitLogicGotoData init_data;
						init_data.goto_index = dataLogicGotoList[m].at(logic_goto_count).goto_index;
						init_data.g_tools = dataLogicGotoList[m].at(logic_goto_count).g_tools;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "通用I/O")
				{
					++general_io_count;
					for (int s = 0; s < dataGeneralIoList[m].size(); s++)
					{
						InitGeneralIoData init_data;
						init_data.io_index = dataGeneralIoList[m].at(general_io_count).io_index;
						init_data.io_tools = dataGeneralIoList[m].at(general_io_count).io_tools;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "PLC通信")
				{
					++plc_communicate_count;
					for (int s = 0; s < dataPlcCommunicateList[m].size(); s++)
					{
						InitPlcCommunicateData init_data;
						init_data.plc_index = dataPlcCommunicateList[m].at(plc_communicate_count).plc_index;
						init_data.plc_tools = dataPlcCommunicateList[m].at(plc_communicate_count).plc_tools;
						init_data.plc_key = dataPlcCommunicateList[m].at(plc_communicate_count).plc_key;
						init_data.mit_code = dataPlcCommunicateList[m].at(plc_communicate_count).mit_code;
						init_data.mit_state = dataPlcCommunicateList[m].at(plc_communicate_count).mit_state;
						init_data.mit_method = dataPlcCommunicateList[m].at(plc_communicate_count).mit_method;
						init_data.mit_address = dataPlcCommunicateList[m].at(plc_communicate_count).mit_address;
						init_data.mit_data = dataPlcCommunicateList[m].at(plc_communicate_count).mit_data;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "串口通信")
				{
					++serial_port_count;
					for (int s = 0; s < dataSerialPortList[m].size(); s++)
					{
						InitSerialPortData init_data;
						init_data.sport_index = dataSerialPortList[m].at(serial_port_count).sport_index;
						init_data.sport_tools = dataSerialPortList[m].at(serial_port_count).sport_tools;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "TCP/IP客户端")
				{
					++socket_tcp_client_count;
					for (int s = 0; s < dataSocketTcpClientList[m].size(); s++)
					{
						InitSocketTcpClientData init_data;
						init_data.client_index = dataSocketTcpClientList[m].at(socket_tcp_client_count).client_index;
						init_data.client_tools = dataSocketTcpClientList[m].at(socket_tcp_client_count).client_tools;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "TCP/IP服务器")
				{
					++socket_tcp_server_count;
					for (int s = 0; s < dataSocketTcpServerList[m].size(); s++)
					{
						InitSocketTcpServerData init_data;
						init_data.server_index = dataSocketTcpServerList[m].at(socket_tcp_server_count).server_index;
						init_data.server_tools = dataSocketTcpServerList[m].at(socket_tcp_server_count).server_tools;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "YoloV13")
				{
					++image_source_count;
					for (int s = 0; s < dataImageSourceList[m].size(); s++)
					{
						InitImageSourceData init_data;
						init_data.camera_index = dataImageSourceList[m].at(image_source_count).camera_index;
						init_data.g_camera = dataImageSourceList[m].at(image_source_count).g_camera;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
				}
				else if (str_name_buf == "OCR")
				{
					++image_source_count;
					for (int s = 0; s < dataImageSourceList[m].size(); s++)
					{
						InitImageSourceData init_data;
						init_data.camera_index = dataImageSourceList[m].at(image_source_count).camera_index;
						init_data.g_camera = dataImageSourceList[m].at(image_source_count).g_camera;
						QVariant var = QVariant::fromValue(init_data);
						QConfig::ToolBase[m]->m_Tools[n].PublicToolDlg->InitSetToolData(var);
					}
					}
			}
		}
	}
}

void QtWidgetsSaveLoad::setFilenameWithPath(const QString& filenameWithPath)
{
	QFileInfo fileinfo = QFileInfo(filenameWithPath);
	filename = fileinfo.fileName();
	workPath = fileinfo.absolutePath();
}
