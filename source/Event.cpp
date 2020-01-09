#include "stdafx.h"
#include "Event.h"

Event::Event(const EVENT_TYPE& e){
	event = e;
}

EVENT_TYPE Event::getEvent() const{
	return event;
}
