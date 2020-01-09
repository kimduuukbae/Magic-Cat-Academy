#include "stdafx.h"
#include "CatCastingLineBlue.h"
#include "Cat.h"
#include "InputManager.h"
void CatCastingLineBlue::enter(Cat * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(5);

	frameTime = 0.0f;
	frame = 0;
}

void CatCastingLineBlue::update(float deltaTime, Cat* t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		++frame;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
		if (frame == 5)
			t->changeState("Idle");
	}
}
