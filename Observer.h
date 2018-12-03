#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	vector<Observer*> observers;
public:
	virtual ~Subject() {}

	void registerObserver(Observer* obs)
	{
		this->observers.push_back(obs);
	}

	void unregisterObservers(Observer * obs)
	{
		this->observers.erase(find(this->observers.begin(), this->observers.end(), obs));
	}

	void notify()
	{
		for (auto o : this->observers)
		{
			o->update();
		}
	}
};