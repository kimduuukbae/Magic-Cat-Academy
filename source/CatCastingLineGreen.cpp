#include "stdafx.h"
#include "CatCastingLineGreen.h"
#include "Cat.h"
#include "InputManager.h"
void CatCastingLineGreen::enter(Cat * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(6);

	frameTime = 0.0f;
	frame = 0;
}

void CatCastingLineGreen::update(float deltaTime, Cat* t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		++frame;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
		if (frame == 5)
			t->changeState("Idle");
	}
}
