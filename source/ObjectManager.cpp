#include "stdafx.h"
#include "ObjectManager.h"
#include "Renderer.h"
#include "Point.h"
#include "ICollisionComponent.h"
#include "structure.h"
#include "Time.h"

ObjectManager::ObjectManager(){
	renderer = new Renderer(1024, 600);
	backGroundIndex = 0;
	shakePower = 0.0f;
}

ObjectManager& ObjectManager::Instance(){
	static ObjectManager manager;
	return manager;
}

void ObjectManager::update(float deltaTime){
	for (auto it = objectList.begin(); it != objectList.end();) {
		if ((*it)->getDelete()) {
			delete (*it);
			it = objectList.erase(it);
		}
		else {
			(*it)->update(deltaTime);
			if (auto comp1 = (*it)->getComponent<CollisionComponent>();
				comp1 != nullptr) {
				comp1->clear();
				for (auto it2 = objectList.begin(); it2 != objectList.end(); ++it2) {
					if (auto comp2 = (*it2)->getComponent<CollisionComponent>();
						comp2 != nullptr && comp2 != comp1) {
						if (AABBCollision(comp1->getCollisionBox(), comp2->getCollisionBox())) 
							comp1->pushObject(*it2);
					}
				}
			}
			++it;
		}
	}
	if (shakePower > 0.0f) {
		float p = sinf((shakePower * 10.0f) * powf(0.5, shakePower)) * 2.0f;
		shakePower -= 1.0f;

		renderer->SetCameraPos(p, p);
		if (shakePower < 0.1f)
			renderer->SetCameraPos(0.0f, 0.0f);
	}
}

void ObjectManager::draw() {
	renderer->DrawGround(0.0f, 0.0f, 0.0f, 1024.0f, -600.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		backGroundIndex);

	for (auto& i : objectList) {
		if (!i->getActive())
			continue;

		auto [x,y,z] = i->getPosition();
		auto[vx, vy, vz] = i->getVolume();
		auto[r, g, b, a] = i->getColor();
		renderer->DrawTextureRectAnim(x, y, z, vx, vy, vz, r, g, b, a, i->getPngIndex()
			, i->getMaxClipX(), i->getMaxClipY()
			, i->getCurrentClipX(), i->getCurrentClipY(),
			i->getDegree(),
			false);
	}
}

void ObjectManager::clear(){
	for (auto& i : objectList)
		i->setDelete();
}

void ObjectManager::setBackGround(const char* texture){
	backGroundIndex = generatePng(texture);
}

void ObjectManager::addShakePower(int power){
	shakePower += power;
}

int ObjectManager::generatePng(const char * texture){
	if (!pngDictionary[texture]) 
		pngDictionary[texture] = renderer->GenPngTexture(const_cast<char*>(texture));
	
	return pngDictionary[texture];
}

void ObjectManager::initScore(){
	score = 0;
}

void ObjectManager::addScore(int add){
	score += add;
}

int ObjectManager::getScore(){
	return score;
}


