#pragma once
#include "Observer.h"
#include "User.h"
#include "Message.h"
#include <string>

using namespace std;

class Session : public Subject
{
private:
	vector<pair<User, Message>> messages;

public:
	
	void addMessage(const User& u, const Message &m)
	{
		this->messages.push_back(pair<User, Message>(u, m));
		this->notify();
	}

	vector<pair<User, Message>> getMessages() const { return messages; }

};

