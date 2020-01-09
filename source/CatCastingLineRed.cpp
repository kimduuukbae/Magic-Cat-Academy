#include "stdafx.h"
#include "CatCastingLineRed.h"
#include "Cat.h"
#include "InputManager.h"
void CatCastingLineRed::enter(Cat * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(4);

	frameTime = 0.0f;
	frame = 0;
}

void CatCastingLineRed::update(float deltaTime, Cat* t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		++frame;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
		if (frame == 5)
			t->changeState("Idle");
	}
}
