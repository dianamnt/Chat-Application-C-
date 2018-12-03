#pragma once
#include <iostream>
#include <string>

using namespace std;

class Message
{
private:
	string message;

public:
	Message(const string &msg): message{msg} {}

	string getMessage() { return message; }

};