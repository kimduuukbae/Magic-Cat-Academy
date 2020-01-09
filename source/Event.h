#pragma once

enum EVENT_TYPE {
	E_BLUE,
	E_YELLOW,
	E_RED,
	E_GREEN
};

class Event {
public:
	Event(const EVENT_TYPE& e);
	EVENT_TYPE getEvent() const;
private:
	EVENT_TYPE event;
};
