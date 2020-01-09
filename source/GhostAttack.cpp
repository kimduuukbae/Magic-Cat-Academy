#include "stdafx.h"
#include "GhostAttack.h"
#include "Ghost.h"
#include "IRigidBodyComponent.h"

void GhostAttack::enter(Ghost * t) {
	t->setCurrentClipX(1);
	t->setCurrentClipY(0);
	frame = 0;
	frameTime = 0.0f;
	if (auto comp = t->getComponent<RigidbodyComponent>();
		comp != nullptr)
		comp->setVelocity(0.0f, 0.0f, 0.0f);
}

void GhostAttack::update(float deltaTime, Ghost* t) {
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		++frame;
		t->setCurrentClipX(frame);
		if (frame == 4)
			t->setDelete();
		frameTime = 0.0f;
	}
}
