#include "stdafx.h"
#include "Cat.h"
#include "CatIdle.h"
#include "CatCasting.h"
#include "CatCastingLineRed.h"
#include "CatCastingLineBlue.h"
#include "CatCastingLineYellow.h"
#include "CatCastingLineGreen.h"
#include "EventDispatcher.h"
#include "ICollisionComponent.h"
#include "Sound.h"
#include "CatDie.h"

Cat::Cat(){
	using namespace std::string_literals;
	EventDispatcher::instance().addObserver(this);
	setMaxClipX(10);
	setMaxClipY(10);
	frame = 10;
	frameTime = 0.0f;
	eventQueue3.insert(std::make_pair("Idle"s, new CatIdle));
	eventQueue3.insert(std::make_pair("Casting"s, new CatCasting));
	eventQueue3.insert(std::make_pair("Red"s, new CatCastingLineRed));
	eventQueue3.insert(std::make_pair("Blue"s, new CatCastingLineBlue));
	eventQueue3.insert(std::make_pair("Green"s, new CatCastingLineGreen));
	eventQueue3.insert(std::make_pair("Yellow"s, new CatCastingLineYellow));
	eventQueue3.insert(std::make_pair("Die"s, new CatDie));
	changeState("Idle");
	collider = addComponent<CollisionComponent>();
	setObjectType(E_CAT);
	soundNumber = 1;
}

Cat::~Cat(){
	for (auto& i : eventQueue3)
		delete i.second;
	eventQueue3.clear();
	EventDispatcher::instance().delObserver(this);
}

void Cat::update(float deltaTime){
	currentState->update(deltaTime, this);
}

void Cat::changeState(const std::string& name){
	if (eventQueue3.size()) {
		auto it = eventQueue3.find(name);
		if (it != eventQueue3.end()) {
			currentState = it->second;
			currentState->enter(this);
		}
	}
}

void Cat::onNotify(const Event& e){
	if (getCurrentClipY() != 8) {
		Sound::instance().PlayShortSound(soundNumber, false, 100.0f);
		soundNumber = (soundNumber + 1) % 5;
		soundNumber = !soundNumber ? 1 : soundNumber;
		switch (e.getEvent()) {
		case E_RED:
			changeState("Red");
			break;
		case E_BLUE:
			changeState("Blue");
			break;
		case E_YELLOW:
			changeState("Yellow");
			break;
		case E_GREEN:
			changeState("Green");
			break;
		}
	}
}



