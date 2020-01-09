#pragma once

class Scene abstract {
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;
protected:
	Scene() = default;
};