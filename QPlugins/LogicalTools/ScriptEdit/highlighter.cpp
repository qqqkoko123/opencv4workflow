#include "highlighter.h"

Highlighter::Highlighter(QTextDocument* parent)
	: QSyntaxHighlighter(parent)
{
	HighlightingRule rule;
	keywordFormat.setForeground(QColor(255, 0, 0)); //关键字
	const QString keywordPatterns[] = {
		QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bdelete\\b"),
		QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
		QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
		QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
		QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
		QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
		QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
		QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
		QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
		QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b"),
		QStringLiteral("\\bexport\\b"), QStringLiteral("\\bextern\\b"),	QStringLiteral("\\busing\\b"),
		QStringLiteral("\\bmutable\\b"), QStringLiteral("\\bfloat\\b"), QStringLiteral("\\bregister\\b"),
		QStringLiteral("\\bnew\\b"),QStringLiteral("\\bsizeof\\b")
	};
	for (const QString& pattern : keywordPatterns)
	{
		rule.pattern = QRegularExpression(pattern);
		rule.format = keywordFormat;
		highlightingRules.append(rule);
	}
	keywordFormat.setForeground(QColor(150, 20, 150)); //关键字
	const QString keywordPatterns2[] = {
		QStringLiteral("\\bauto\\b"), QStringLiteral("\\bbreak\\b"), QStringLiteral("\\bfor\\b"),
		QStringLiteral("\\bcase\\b"), QStringLiteral("\\bcatch\\b"), QStringLiteral("\\bcontinue\\b"),
		QStringLiteral("\\bdefault\\b"), QStringLiteral("\\bdo\\b"), QStringLiteral("\\belse\\b"),
		QStringLiteral("\\bgoto\\b"), QStringLiteral("\\breturn\\b"), QStringLiteral("\\bswitch\\b"),
		QStringLiteral("\\bthrow\\b"), QStringLiteral("\\btry\\b"), QStringLiteral("\\bif\\b"),
		QStringLiteral("\\bwhile\\b")
	};
	for (const QString& pattern : keywordPatterns2)
	{
		rule.pattern = QRegularExpression(pattern);
		rule.format = keywordFormat;
		highlightingRules.append(rule);
	}
	keywordFormat.setForeground(QColor(20, 20, 220)); //关键字
	const QString keywordPatterns3[] = {
		QStringLiteral("\\bconst\\b"), QStringLiteral("\\bthis\\b"),QStringLiteral("\\btrue\\b"),
		QStringLiteral("\\bfalse\\b"),QStringLiteral("\\bvar\\b")
	};
	for (const QString& pattern : keywordPatterns3)
	{
		rule.pattern = QRegularExpression(pattern);
		rule.format = keywordFormat;
		highlightingRules.append(rule);
	}	
	preprocessorFormat.setForeground(QColor(0, 160, 0)); //预处理命令
	const QString preprocessorPatterns[] = {
		QStringLiteral("#.*>"), QStringLiteral("#\\binclude\\b")
	};
	for (const QString& pattern : preprocessorPatterns) {
		rule.pattern = QRegularExpression(pattern);
		rule.format = preprocessorFormat;
		highlightingRules.append(rule);
	}
	quotationFormat.setForeground(Qt::darkGreen);  //字符串
	rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
	rule.format = quotationFormat;
	highlightingRules.append(rule);
	QFont font("Microsoft YaHei");    //函数名
	font.setPixelSize(16);
	font.setBold(true);
	functionFormat.setFont(font);
	//functionFormat.setFontItalic(true);   //倾斜
	functionFormat.setForeground(QColor(148, 0, 211));
	rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
	rule.format = functionFormat;
	highlightingRules.append(rule);
	singleLineCommentFormat.setForeground(Qt::darkGreen);   //单行注释
	rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
	rule.format = singleLineCommentFormat;
	highlightingRules.append(rule);
	multiLineCommentFormat.setForeground(Qt::darkGreen);    //多行注释
	commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
	commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}

void Highlighter::highlightBlock(const QString& text)
{
	for (const HighlightingRule& rule : qAsConst(highlightingRules))
	{
		QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
		while (matchIterator.hasNext())
		{
			QRegularExpressionMatch match = matchIterator.next();
			setFormat(match.capturedStart(), match.capturedLength(), rule.format);
		}
	}
	setCurrentBlockState(0);
	int startIndex = 0;
	if (previousBlockState() != 1)
		startIndex = text.indexOf(commentStartExpression);
	while (startIndex >= 0)
	{
		QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
		int endIndex = match.capturedStart();
		int commentLength = 0;
		if (endIndex == -1)
		{
			setCurrentBlockState(1);
			commentLength = text.length() - startIndex;
		}
		else
		{
			commentLength = endIndex - startIndex + match.capturedLength();
		}
		setFormat(startIndex, commentLength, multiLineCommentFormat);
		startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
	}
}
