#pragma once

class Cat;

class ICatState abstract {
public:
	virtual void enter(Cat* t) = 0;
	virtual void update(float deltaTime, Cat* t) = 0;

protected:
	int frame;
	float frameTime;
};