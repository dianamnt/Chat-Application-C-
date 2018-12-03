#include "MyTextEdit.h"

void MyTextEdit::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Return)
	{
		emit enterPressed();
	}
	else
	{
		QTextEdit::keyPressEvent(event);
	}
}
