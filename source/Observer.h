#pragma once
#include "Event.h"

class Observer {
public:	
	virtual void onNotify(const Event& e) = 0;
};