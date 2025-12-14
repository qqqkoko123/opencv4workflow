#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmProcessSetUp.h"
#include <QProxyStyle>
#include <QStandardItemModel>
#include <QTreeWidget>
#include "basemainwindow.h"
#include "QWorld.h"

class frmProcessSetUp : public QDialog
{
	Q_OBJECT

public:
	frmProcessSetUp(QWidget* parent = Q_NULLPTR);
	~frmProcessSetUp();

private:
	Ui::frmProcessSetUpClass ui;

private:
	void form_load();
	void initTitleBar();
	void paintEvent(QPaintEvent* event);

private:	
	QTabWidget* objTabName;
	QTreeWidget* objTreeName;
	QTreeWidgetItem* cItem;
	QStandardItemModel* ItemModel;	
	int index_process_modify;
	QString str_name;

public slots:
	void slot_CreateList();
	void slot_SetProject(QString str_name);

private slots:
	void onButtonCloseClicked();
	void slot_ListClick(QModelIndex);	
	void on_btnProjectModify_clicked();
	void on_btnProcessModify_clicked();

signals:
	void sig_UpdateQTreeWidget(QString, QString);
};
