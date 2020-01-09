#include "stdafx.h"
#include "CatIdle.h"
#include "Cat.h"
#include "InputManager.h"
void CatIdle::enter(Cat * t){
	t->setCurrentClipX(0);
	t->setCurrentClipY(1);

	frameTime = 0.0f;
	frame = 0;
}

void CatIdle::update(float deltaTime, Cat* t){
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		frame = (frame + 1) % 20;
		t->setCurrentClipX(frame % 10);
		t->setCurrentClipY(frame / 10 + 1);
		frameTime = 0.0f;
	}
	if (D_INPUT.getKeyDown(KeyCode::LEFT_BUTTON))
		t->changeState("Casting");
}
