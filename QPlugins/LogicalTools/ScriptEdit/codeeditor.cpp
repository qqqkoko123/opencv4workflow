#include "codeeditor.h"
#include <QPainter>
#include <QTextBlock>
#include <QCompleter>
#include <QKeyEvent>
#include <QString>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QAbstractItemView>
#include <QScrollBar>

QList<Brackets> bralist;
CodeEditor::CodeEditor(QWidget* parent) : QPlainTextEdit(parent)
{
	lineNumberArea = new LineNumberArea(this);
	connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberAreaWidth);
	connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumberArea);
	connect(this, &CodeEditor::cursorPositionChanged, this, &CodeEditor::highlightCurrentLine);
	connect(this, &CodeEditor::textChanged, this, &CodeEditor::change_qslist_f);
	updateLineNumberAreaWidth(0);
	highlightCurrentLine();
}

int CodeEditor::lineNumberAreaWidth()
{
	int digits = 1;
	int max = qMax(1, blockCount());
	while (max >= 10) {
		max /= 10;
		++digits;
	}
	int space = 5 + fontMetrics().width(QLatin1Char('9')) * digits;
	return space;
}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
	setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect& rect, int dy)
{
	if (dy) //当text发生了垂直的滚动
		lineNumberArea->scroll(0, dy);
	else //当text在水平和垂直上都进行了移动
		lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
	//在Qt返回到主事件循环时调度paint事件。
	if (rect.contains(viewport()->rect()))
		updateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent* e) //当widget resize事件发生时
{
	QPlainTextEdit::resizeEvent(e); //先执行其父类的resizeEvent
	QRect cr = contentsRect(); //返回一个在widget页边距的区域
	lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::highlightCurrentLine() //高亮当前行
{
	QList<QTextEdit::ExtraSelection> extraSelections;
	if (!isReadOnly())
	{
		QTextEdit::ExtraSelection selection;
		QColor lineColor = QColor(Qt::lightGray);
		selection.format.setBackground(lineColor);
		selection.format.setProperty(QTextFormat::FullWidthSelection, true);
		selection.cursor = textCursor();
		selection.cursor.clearSelection();
		extraSelections.append(selection);
	}
	setExtraSelections(extraSelections);
	QTextDocument* doc = this->document();
	QTextCursor cursor;
	QTextCursor cursor2(doc);
	QTextCharFormat color_format;
	color_format.setForeground(Qt::black);
	cursor = this->textCursor();
	int position = cursor.position(); //获取光标位置	
	if (!bralist.isEmpty()) {
		for (int i = 0; i < bralist.length(); i++)
		{
			if (bralist.at(i).pos == position)
			{
				if (bralist.at(i).ppos != -1)
				{
					cursor2.setPosition(bralist.at(i).ppos);					
					cursor2.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
					cursor2.mergeCharFormat(color_format);
					cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
					cursor.mergeCharFormat(color_format);
				}
			}
		}
	}
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent* event) //绘制显示行号区域
{
	QPainter painter(lineNumberArea);
	painter.save();
	painter.fillRect(event->rect(), Qt::lightGray);
	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
	int bottom = top + qRound(blockBoundingRect(block).height());
	while (block.isValid() && top <= event->rect().bottom())
	{
		if (block.isVisible() && bottom >= event->rect().top())
		{
			QString number = QString::number(blockNumber + 1);
			QFont font("Microsoft YaHei");
			font.setPixelSize(16);
			painter.setFont(font);
			painter.setPen(QColor(0, 0, 120));
			painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignCenter, number);
		}
		block = block.next();
		top = bottom;
		bottom = top + qRound(blockBoundingRect(block).height());
		++blockNumber;
	}
	painter.restore();
}

void CodeEditor::setCompleter(QCompleter* completer)
{
	if (c)
		c->disconnect(this);
	c = completer;
	if (!c)
		return;
	c->setWidget(this);
	c->setCompletionMode(QCompleter::PopupCompletion);
	c->setCaseSensitivity(Qt::CaseInsensitive);
	QObject::connect(c, QOverload<const QString&>::of(&QCompleter::activated), this, &CodeEditor::insertCompletion);
}

QCompleter* CodeEditor::completer() const
{
	return c;
}

void CodeEditor::insertCompletion(const QString& completion)
{
	if (c->widget() != this)
		return;
	QTextCursor tc = textCursor();
	int extra = completion.length() - c->completionPrefix().length();
	tc.movePosition(QTextCursor::Left);
	tc.movePosition(QTextCursor::EndOfWord);
	tc.insertText(completion.right(extra));
	setTextCursor(tc);
}

QString CodeEditor::textUnderCursor() const
{
	QTextCursor tc = textCursor();
	tc.select(QTextCursor::WordUnderCursor);
	return tc.selectedText();
}

void CodeEditor::focusInEvent(QFocusEvent* e)
{
	if (c)
		c->setWidget(this);
	QPlainTextEdit::focusInEvent(e);
}

void CodeEditor::keyPressEvent(QKeyEvent* e)
{
	//处理键盘事件
	if (c && c->popup()->isVisible())
	{
		//使以下快捷键优先作用于widget而非PlainTextEdit
		switch (e->key()) {
		case Qt::Key_Enter:
		case Qt::Key_Return:
		case Qt::Key_Escape:
		case Qt::Key_Tab:
		case Qt::Key_Backtab:
			e->ignore();
			return;
		default:
			break;
		}
	}
	if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_H)
	{
		//当按下CTRL+H时,隐藏(显示)注释
		QStringList::Iterator it;
		QStringList qslist_h;
		if (shouldhide == false)
		{
			shouldhide = true;
			qslist_f.clear();
			bool has_found_begin = false, has_found_end = false;
			QTextDocument* doc = this->document(); //文本对象
			int row_num = doc->blockCount(); //回车符是一个block
			for (int i = 0; i < row_num; i++) {
				QTextBlock textLine = doc->findBlockByNumber(i); //文本中的一段
				QString str = textLine.text(); //将该段转换为QString         
				qslist_f.append(str);
				if (!has_found_begin)
				{
					int m = str.indexOf("//");
					int n = str.indexOf("/*");
					if (m != -1 && n != -1 && m < n)
					{
						if (m > 0 && str.at(m - 1) == '\"')
						{
							;
						}
						else
						{
							str.truncate(m);
							qslist_h.append(str);
							continue;
						}
					}
					else if (m != -1 && n == -1)
					{
						str.truncate(m);
						qslist_h.append(str);
						continue;
					}
					else if ((n != -1 && m == -1) || (n != -1 && m != -1 && m > n))
					{
						has_found_begin = true;
						if (n > 0)
						{
							str.truncate(n);
							qslist_h.append(str);
						}
					}
					else if (m == -1 && n == -1)
					{
						qslist_h.append(str);
					}
				}
				if (!has_found_end && has_found_begin)
				{
					int p = str.indexOf("*/");
					if (p != -1)
					{
						has_found_end = true;
						has_found_begin = false;
						qslist_h.append(str.right(str.length() - p - 2));
					}
					else {
						continue;
					}
				}
			}
			for (it = qslist_h.begin(); it != qslist_h.end(); it++)
			{
				if (it == qslist_h.begin())
				{
					this->setPlainText(*it);
				}
				else
				{
					this->appendPlainText(*it);
				}
			}
		}
		else
		{
			shouldhide = false;
			for (it = qslist_f.begin(); it != qslist_f.end(); it++)
			{
				if (it == qslist_f.begin())
				{
					this->setPlainText(*it);
				}
				else
				{
					this->appendPlainText(*it);
				}
			}
		}
	}
	const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E);
	if (!c || !isShortcut)
		QPlainTextEdit::keyPressEvent(e);
	const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) || e->modifiers().testFlag(Qt::ShiftModifier);
	if (!c || (ctrlOrShift && e->text().isEmpty()))
		return;
	static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-=");
	const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
	QString completionPrefix = textUnderCursor();
	if (!isShortcut && (hasModifier || e->text().isEmpty() || completionPrefix.length() < 1
		|| eow.contains(e->text().right(1))))
	{
		c->popup()->hide();
		return;
	}
	if (completionPrefix != c->completionPrefix())
	{
		c->setCompletionPrefix(completionPrefix);
		c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
	}
	QRect cr = cursorRect();
	cr.setWidth(c->popup()->sizeHintForColumn(0)
		+ c->popup()->verticalScrollBar()->sizeHint().width());
	c->complete(cr);
}

void CodeEditor::change_qslist_f()
{
	//当进入注释隐藏状态时修改文本的处理
	if (shouldhide) 
	{
		QTextCursor cursor;
		cursor = this->textCursor();
		int row = cursor.blockNumber();
		QTextBlock textline = this->document()->findBlockByNumber(row);
		QString str_c = textline.text();
		QString str = qslist_f.at(row);
		if (str.indexOf("//") == -1 && str.indexOf("/*") == -1)
		{
			//修改的行没有注释
			qslist_f.replace(row, str_c);
		}
		else if (str.indexOf("//") == -1 && str.indexOf("/*") != -1)
		{
			//修改的行存在//
			qslist_f.insert(row, str_c);
		}
		else if (str.indexOf("//") != -1 && str.indexOf("/*") == -1)
		{
			//修改的行存在/*
			int len = str.length();
			int n = str.indexOf("//");
			QString right = str.right(len - n);
			str_c.append(right);
			qslist_f.replace(row, str_c);
		}
	}
	int current_length = 0;
	QStringList text;
	QList<Brackets> stack;
	QTextDocument* document = this->document();
	int allrow = document->blockCount();
	bralist.clear();
	for (int i = 0; i < allrow; i++)
	{
		QTextBlock line = this->document()->findBlockByNumber(i);
		QString string = line.text();
		for (int j = 0; j < string.length(); j++)
		{
			switch (string.at(j).unicode())
			{
			case '{':
				if (j < string.indexOf("//") || string.indexOf("//") == -1)
				{
					stack.append(Brackets(current_length + j, -1, 1));
				}
				break;
			case '(':
				if (j < string.indexOf("//") || string.indexOf("//") == -1)
				{
					stack.append(Brackets(current_length + j, -1, 2));
				}
				break;
			case '}':
				if (stack.isEmpty()) {
					bralist.append(Brackets(current_length + j, -1, 1));
				}
				else if (stack.last().type == 1)
				{
					bralist.append(Brackets(current_length + j, stack.last().pos, 1));
					bralist.append(Brackets(stack.last().pos, current_length + j, 1));
					stack.removeLast();
				}
				else {
					bralist.append(Brackets(current_length + j, -1, 1));
				}
				break;
			case ')':
				if (stack.isEmpty())
				{
					bralist.append(Brackets(current_length + j, -1, 2));
				}
				else if (stack.last().type == 2)
				{
					bralist.append(Brackets(current_length + j, stack.last().pos, 2));
					bralist.append(Brackets(stack.last().pos, current_length + j, 2));
					stack.removeLast();
				}
				else
				{
					bralist.append(Brackets(current_length + j, -1, 2));
				}
				break;
			default:
				break;
			}
		}
		current_length += string.length() + 1;
	}
	stack.clear();
}
