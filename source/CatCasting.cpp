#include "stdafx.h"
#include "Cat.h"
#include "CatCasting.h"
#include "InputManager.h"
void CatCasting::enter(Cat * t){
	t->setCurrentClipX(0);
	t->setCurrentClipY(3);
	frameTime = 0.0f;
	frame = 0;
	
}

void CatCasting::update(float deltaTime, Cat * t){
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		frame = (frame + 1) % 6;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
	}
	if (D_INPUT.getKeyUp(KeyCode::LEFT_BUTTON)) 
		t->changeState("Idle");
}
