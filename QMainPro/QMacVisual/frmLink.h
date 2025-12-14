#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmLink.h"
#include <QProxyStyle>
#include <QStandardItemModel>
#include <QTreeWidget>
#include "basemainwindow.h"
#include "QWorld.h"
#include "FlowListWidget.h"

class frmLink : public QDialog
{
	Q_OBJECT

public:
	frmLink(QWidget* parent = Q_NULLPTR);
	~frmLink();

private:
	Ui::frmLinkClass ui;

private:
	void form_load();
	void initTitleBar();
	void paintEvent(QPaintEvent* event);
	QString GetIconName(QString Name);
	QPixmap GetIcon(QString fileName);

private:	
	QTabWidget* objTabName;
	QTreeWidget* objTreeName;
	QTableWidget* objTableName;
	int flow_index;
	QtDragListWidget* TempDragListWidget;
	QTreeWidgetItem* cItem;
	QStandardItemModel* ItemModel;	
	int index_process_modify;
	QString tool_name, tool_name_buf;
	QTableWidgetItem* item_number;
	QTableWidgetItem* item_variable_name;
	QTableWidgetItem* item_variable_value;
	QTableWidgetItem* item_variable_type;
	int row_count;

public slots:
	void slot_CreateList();

private slots:
	void onButtonCloseClicked();
	void slot_ListClick(QModelIndex);
	void slot_DoubleClicked(int, int);

signals:
	void sig_UpdateQTreeWidget(QString, QString);
};
