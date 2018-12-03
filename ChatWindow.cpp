#include "ChatWindow.h"
#include "MyTextEdit.h"

ChatWindow::ChatWindow(const User &u, Session &s, QWidget *parent)
	: user(u), session(s), QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(QString::fromStdString(u.getName()));

	this->session.registerObserver(this);

	QObject::connect(ui.sendButton, &QPushButton::clicked, this, [this] {
		this->sendMessage();
	});
	
	//QObject::connect(ui.messageTextEdit, &MyTextEdit::enterPressed, this, [this] {
		//this->sendMessage();
	//});

	//QObject::connect(this->ui.messageTextEdit, &MyTextEdit::enterPressed, this, [&]() { this->sendMessage(); });
}

ChatWindow::~ChatWindow()
{
	this->session.unregisterObservers(this);
}

void ChatWindow::update()
{
	ui.messageListWidget->clear();

	for (auto m : this->session.getMessages())
	{
		QListWidgetItem* item = new QListWidgetItem{};
		item->setToolTip(QString::fromStdString(m.second.getMessage()));

		if (m.first.getNickname() == this->user.getNickname())
		{
			item->setText(QString::fromStdString(m.second.getMessage()));
			item->setForeground(QBrush{ QColor{ Qt::darkMagenta } });
			item->setTextAlignment(Qt::AlignRight);
		}
		else
		{
			item->setText(QString::fromStdString("[ " + m.first.getName() + " ]: " + m.second.getMessage()));
		}
		ui.messageListWidget->addItem(item);
	}
}

void ChatWindow::sendMessage()
{
	string str = ui.messageTextEdit->toPlainText().toStdString();
	Message m{ str };
	this->session.addMessage(this->user, m);
	ui.messageTextEdit->clear();
}