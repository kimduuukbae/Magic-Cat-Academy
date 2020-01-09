#pragma once
class Object;

class IComponent abstract {
public:
	virtual void process(Object* o) = 0;
	virtual ~IComponent() = default;
};