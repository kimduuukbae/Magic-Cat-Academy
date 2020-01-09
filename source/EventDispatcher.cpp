#include "stdafx.h"
#include "Observer.h"
#include "EventDispatcher.h"

EventDispatcher& EventDispatcher::instance(){
	static EventDispatcher dispatcher;
	return dispatcher;
}

void EventDispatcher::addObserver(Observer * o){
	Observe.push_back(o);
}

void EventDispatcher::delObserver(Observer * o){
	for (auto it = Observe.begin(); it != Observe.end(); ++it) {
		if ((*it) == o) {
			Observe.erase(it);
			break;
		}
	}
}

void EventDispatcher::Notify(const Event& e) {
	for (auto& i : Observe)
		i->onNotify(e);
}