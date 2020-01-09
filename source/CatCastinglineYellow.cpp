#include "stdafx.h"
#include "CatCastingLineYellow.h"
#include "Cat.h"
#include "InputManager.h"
void CatCastingLineYellow::enter(Cat * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(7);

	frameTime = 0.0f;
	frame = 0;
}

void CatCastingLineYellow::update(float deltaTime, Cat* t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		++frame;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
		if (frame == 5)
			t->changeState("Idle");
	}
}
