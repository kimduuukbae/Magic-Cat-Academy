#pragma once
#include "IComponent.h"
#include "structure.h"
#include <vector>

class Object;

class CollisionComponent : public IComponent{
public:
	CollisionComponent();
	void process(Object* o) override;
	void setCollisionBox(const CollisionBox& box);
	
	inline CollisionBox getCollisionBox() {
		return collisionBox;
	}

	const std::vector<Object*>& getCollideObjectList();
	void pushObject(Object* o);
	void clear();
private:
	CollisionBox collisionBox;
	std::vector<Object*> collideObjectList;
};