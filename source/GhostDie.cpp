#include "stdafx.h"
#include "GhostDie.h"
#include "Ghost.h"
#include "IRigidBodyComponent.h"

void GhostDie::enter(Ghost * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(1);
	if (auto comp = t->getComponent<RigidbodyComponent>();
		comp != nullptr)
		comp->setVelocity(0.0f, 0.0f, 0.0f);
	frameTime = 0.0f;
	frame = 0;
}

void GhostDie::update(float deltaTime, Ghost* t) {
	frameTime += deltaTime;
	if (frameTime > 0.2f) {
		frame = (frame + 1) % 4;
		t->setCurrentClipX(frame);
		if (frame == 3)
			t->setDelete();
	}
}
