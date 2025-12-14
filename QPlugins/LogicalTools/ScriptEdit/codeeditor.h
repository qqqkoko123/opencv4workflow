#pragma once

#include <QPlainTextEdit>
#include <QCompleter>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;

class CodeEditor : public QPlainTextEdit
{
	Q_OBJECT

public:
	CodeEditor(QWidget* parent = nullptr);

	void lineNumberAreaPaintEvent(QPaintEvent* event);
	int lineNumberAreaWidth();
	void setCompleter(QCompleter* c);
	QCompleter* completer() const;
	bool shouldhide = false;  //当前文本是否处于隐藏注释状态
	QStringList qslist_f;  //保存文本的qstringlist

protected:
	void resizeEvent(QResizeEvent* event) override;
	void keyPressEvent(QKeyEvent* e) override;
	void focusInEvent(QFocusEvent* e) override;

private slots:
	void updateLineNumberAreaWidth(int newBlockCount);
	void highlightCurrentLine();
	void updateLineNumberArea(const QRect& rect, int dy);
	void insertCompletion(const QString& completion);
	void change_qslist_f();

private:
	QWidget* lineNumberArea;
	QCompleter* c = nullptr;

private:
	QString textUnderCursor() const;
};

class LineNumberArea : public QWidget
{
public:
	LineNumberArea(CodeEditor* editor) : QWidget(editor), codeEditor(editor)
	{}

	QSize sizeHint() const override
	{
		return QSize(codeEditor->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent* event) override
	{
		codeEditor->lineNumberAreaPaintEvent(event);
	}

private:
	CodeEditor* codeEditor = nullptr;
};

class Brackets
{
public:
	Brackets(int cpos, int cppos, int ctype)
	{
		pos = cpos;
		ppos = cppos;
		type = ctype;
	}
	int pos = 0;
	int ppos = 0;
	int type = 0;
};
