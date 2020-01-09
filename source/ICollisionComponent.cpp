#include "stdafx.h"
#include "ICollisionComponent.h"
#include "Object.h"

CollisionComponent::CollisionComponent(){
	collideObjectList.reserve(20);
}

void CollisionComponent::process(Object * o){
	auto [x,y,z] = o->getPosition();
	auto [vx, vy, vz] = o->getVolume();
	collisionBox.left = x - vx / 2;
	collisionBox.right = x + vx / 2;
	collisionBox.top = y + vy / 2 - 45.0f;
	collisionBox.bottom = y - vy / 2;
}

void CollisionComponent::setCollisionBox(const CollisionBox & box) {
	collisionBox = box;
}

const std::vector<Object*>& CollisionComponent::getCollideObjectList(){
	return collideObjectList;
}

void CollisionComponent::pushObject(Object* o){
	collideObjectList.push_back(o);
}

void CollisionComponent::clear(){
	collideObjectList.clear();
}



