//#pragma once
#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "ui_ChatWindow.h"
#include "Session.h"

class ChatWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ChatWindow(const User &u, Session &s, QWidget *parent = Q_NULLPTR);
	~ChatWindow();

	void update() override;
	void sendMessage();


private:
	Ui::ChatWindow ui;
	User user;
	Session &session;
};
#endif
