#pragma once
#include "Event.h"
#include <list>

class Observer;

class EventDispatcher {
public:
	static EventDispatcher& instance();
	void addObserver(Observer* o);
	void delObserver(Observer* o);

	void Notify(const Event& e);
private:
	std::list<Observer*> Observe;
};
