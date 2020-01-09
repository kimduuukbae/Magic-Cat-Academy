#pragma once

class Ghost;

class IGhostState abstract {
public:
	IGhostState() = default;
	virtual void enter(Ghost* t) = 0;
	virtual void update(float deltaTime, Ghost* t) = 0;
protected:
	int frame;
	float frameTime;
};