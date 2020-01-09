#include "stdafx.h"
#include "AttackPack.h"
#include <random>
#include "ObjectManager.h"
#include "AttackSymbol.h"
#include "Ghost.h"

AttackPack::~AttackPack(){
	for (auto&i : symbolList)
		i->setDelete();
	symbolList.clear();
}

AttackPack::AttackPack(int count){
	for (int i = 0; i < count; ++i) {
		symbolList.push_back(D_MANAGER.addObject<AttackSymbol>(
			Vector3D{ 0.0f,0.0f,0.0f },
			color{ 1.0f,1.0f,1.0f,1.0f },
			Vector3D{ 64.0f,64.0f,1.0f },
			"Resources/attackPack.png"
			));
		symbolList.back()->setActive(true);
		symbolList.back()->setEventType(static_cast<EVENT_TYPE>(rand() % 4));
	}
}

void AttackPack::setPackPosition(Ghost * t){
	auto [x,y,z] = t->getPosition();
	auto it = symbolList.begin();
	auto d = t->getDegree() < 90.0f ? 0 : -10;
	for (int i = 0; i < symbolList.size(); ++i, ++it) 
		(*it)->setPosition(x + (i* 20.0f) + d, y - 20.0f, 0.0f);
}

void AttackPack::checkSymbol(EVENT_TYPE e){
	if (symbolList.size() && e == symbolList.front()->getEventType()) {
		symbolList.front()->setDelete();
		symbolList.pop_front();
		D_MANAGER.addScore(20);
	}
}

int AttackPack::getSymbolCount(){
	return symbolList.size();
}
