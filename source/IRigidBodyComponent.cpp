#include "stdafx.h"
#include "Object.h"
#include "IRigidBodyComponent.h"
#include "Time.h"

void RigidbodyComponent::process(Object * o){
	Vector3D v = velocity;
	auto [x, y, z] = o->getPosition() + velocity * Time::getDeltaTime();
	o->setPosition(x, y, z);
}

void RigidbodyComponent::setMass(float m){
	mass = m;
}

void RigidbodyComponent::setVelocity(float x, float y, float z){
	velocity = { x,y,z };
}
