#include "stdafx.h"
#include "Cat.h"
#include "CatDie.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "EventDispatcher.h"
void CatDie::enter(Cat * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(8);
	frameTime = 0.0f;
	frame = 0;
}

void CatDie::update(float deltaTime, Cat * t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f && frame < 9) {
		frame = (frame + 1) % 10;
		t->setCurrentClipX(frame);
		frameTime = 0.0f;
	}
	else if (frame == 9 && frameTime > 1.0f) {
		D_SCENE->changeScene("End");
		frameTime = 0.0f;
	}
}
