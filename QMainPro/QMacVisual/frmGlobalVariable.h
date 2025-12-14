#pragma once

#include <QDialog>
#include "ui_frmGlobalVariable.h"
#include <QButtonGroup>
#include "mytitlebar.h"
#include <QItemDelegate>

class frmGlobalVariable : public QDialog
{
	Q_OBJECT

public:
	frmGlobalVariable(QWidget* parent = Q_NULLPTR);
	~frmGlobalVariable();

private:
	Ui::frmGlobalVariableClass ui;

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	
	void moveRow(QTableWidget* pTable, int nFrom, int nTo);

public slots:
	void onButtonCloseClicked();

private slots:	
	void on_btnAdd_clicked();
	void on_btnDelete_clicked();
	void on_btnMoveUp_clicked();
	void on_btnMoveDown_clicked();
	QString slot_GlobalValue(const QString strVar, const QString value, const int flowIndex);

public slots:
	QString slot_SetGlobalValue(const QString strVar, const QString value, const int flowIndex);

signals:
	QString sig_GlobalValue(const QString strVar, const QString value, const int flowIndex);

private:
	QThread* h1, * h2;
};

class ReadOnlyDelegate : public QItemDelegate
{
public:
	ReadOnlyDelegate(QWidget* parent = NULL) :QItemDelegate(parent)
	{}

	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override
	{
		Q_UNUSED(parent)
			Q_UNUSED(option)
			Q_UNUSED(index)
			return NULL;
	}
};
