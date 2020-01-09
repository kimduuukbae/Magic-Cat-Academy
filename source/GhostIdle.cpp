#include "stdafx.h"
#include "GhostIdle.h"
#include "Ghost.h"
#include "IRigidBodyComponent.h"
#include "ICollisionComponent.h"
#include "Cat.h"
void GhostIdle::enter(Ghost * t) {
	t->setCurrentClipX(0);
	t->setCurrentClipY(0);
	auto rigidbody = t->addComponent<RigidbodyComponent>();
	auto [x,y,z] = t->getPosition();
	Vector3D v{ 0.0f - x, 0.0f - y, 0.0f };
	v.normalize();	// ¹æÇâº¤ÅÍ 
	rigidbody->setVelocity(v.x * 50.0f, v.y * 50.0f, v.z);

	collider = t->getComponent<CollisionComponent>();
}

void GhostIdle::update(float deltaTime, Ghost* t) {
	for (auto& i : collider->getCollideObjectList()) {
		if (i->getObjectType() == E_CAT && i->getCurrentClipY() < 8) {
			t->changeState("Attack");
			static_cast<Cat*>(i)->changeState("Die");
		}

	}
}
