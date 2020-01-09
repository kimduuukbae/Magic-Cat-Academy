#pragma once
#include "Object.h"
#include "Event.h"

class AttackSymbol : public Object {
public:
	AttackSymbol();
	EVENT_TYPE getEventType();
	void setEventType(EVENT_TYPE e);
private:
	EVENT_TYPE event;
};