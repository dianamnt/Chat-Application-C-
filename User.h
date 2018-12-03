#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
	string nickname;
	string name;

public:
	User(const string &nn, const string &n) : nickname{ nn }, name{n} {}

	string getNickname() const { return nickname; }
	string getName() const { return name; }
	bool operator==(User u) { return this->nickname == u.nickname; }
};
