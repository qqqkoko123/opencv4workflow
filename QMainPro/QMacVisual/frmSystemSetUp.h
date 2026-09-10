#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmSystemSetUp.h"
#include <QProxyStyle>
#include "basemainwindow.h"
#include "QWorld.h"

class frmSystemSetUp : public BaseWindow
{
	Q_OBJECT

public:
	frmSystemSetUp(QWidget*parent = Q_NULLPTR);
	~frmSystemSetUp();

private:
	Ui::frmSystemSetUpClass ui;

private:			
	void initTitleBar();
	void paintEvent(QPaintEvent* event);
	void SetProcessAutoRunSelf(const QString& appPath);
	void RemoveProcessAutoRunSelf(const QString& appPath);

private slots:
	void slot_ProgramSelfStart(bool);
	void slot_ProcessSelfStart(bool);
	void slot_SignOutTime(bool);
};
