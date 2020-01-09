#include "stdafx.h"
#include "GhostFade.h"
#include "Ghost.h"

void GhostFade::enter(Ghost * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(0);
	frameTime = 0.0f;
}

void GhostFade::update(float deltaTime, Ghost* t) {
	frameTime += deltaTime;
	if (frameTime > 0.05f) {
		auto [r,g,b,a] = t->getColor();
		t->setColor(r, g, b, a + 0.05f);
		frameTime = 0.0f;
		if (a > 0.8f)
			t->changeState("Idle");
	}
}
