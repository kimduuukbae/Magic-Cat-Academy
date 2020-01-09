#include "stdafx.h"
#include "AttackPack.h"
#include "Ghost.h"
#include "EventDispatcher.h"
#include "GhostIdle.h"
#include "GhostFade.h"
#include "GhostAttack.h"
#include "GhostDie.h"
#include "ICollisionComponent.h"
#include "AttackPack.h"
#include "Sound.h"
#include "ObjectManager.h"

Ghost::Ghost(){
	using namespace std::string_view_literals;
	setMaxClipX(4);
	setMaxClipY(2);
	setCurrentClipX(0);
	setCurrentClipY(0);

	eventQueue2.insert(std::make_pair("Fade"sv, new GhostFade));
	eventQueue2.insert(std::make_pair("Idle"sv, new GhostIdle));
	eventQueue2.insert(std::make_pair("Attack"sv, new GhostAttack));
	eventQueue2.insert(std::make_pair("Die"sv, new GhostDie));
	changeState("Fade");
	
	auto [x,y,z] = getPosition();
	auto[vx, vy, vz] = getVolume();
	addComponent<CollisionComponent>()->setCollisionBox(CollisionBox{
		
		});
	setObjectType(E_GHOST);
	EventDispatcher::instance().addObserver(this);
}

Ghost::~Ghost(){
	for (auto& i : eventQueue2)
		delete i.second;
	eventQueue2.clear();
	EventDispatcher::instance().delObserver(this);
	delete symbolList;
}

void Ghost::update(float deltaTime){
	if (!getDelete()) {
		currentState->update(deltaTime, this);
		symbolList->setPackPosition(this);
		Object::update(deltaTime);
	}
}


void Ghost::onNotify(const Event& e){
	if (!this->getDelete()) {
		symbolList->checkSymbol(e.getEvent());
		if (!symbolList->getSymbolCount()) {
			changeState("Die");
			Sound::instance().PlayShortSound(5, false, 100.0f);
			D_MANAGER.addShakePower(5);
			D_MANAGER.addScore(100);
		}
	}
}

void Ghost::changeState(const std::string_view& name){
	currentState = eventQueue2[name];
	currentState->enter(this);
}

void Ghost::addSymbol(int count){
	symbolList = new AttackPack(count);
}
