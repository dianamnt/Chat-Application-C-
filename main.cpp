#include "chat.h"
#include <QtWidgets/QApplication>
#include "ChatWindow.h"
#include "Session.h"
#include "User.h"
#include "Message.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Session session;

	vector<ChatWindow*> b;

	User teacher1{ "user1.mail","User1" };
	User teacher2{ "user2.mail","User2" };
	User teacher4{ "user3.mail","User3" };
	User teacher5{ "user4.mail","User4" };

	//vector<pair<User, int>> users;

	vector<User> users;
	users.push_back(teacher1);
	users.push_back(teacher2);
	//ausers.push_back(teacher3);
	users.push_back(teacher4);
	users.push_back(teacher5);


	for (auto t : users)
	{
		//ChatWindow c{ t,session };
		b.push_back(new ChatWindow{t, session});
	}

	for (auto &cw: b)
	{
		cw->show();
	}


	//ChatWindow user1{ User{"suzan.otay", "Suzan"},session };
	//ChatWindow user2{ User{"diana.mnt", "Diana"},session };

	//user1.show();
	//user2.show();

	return a.exec();
}
