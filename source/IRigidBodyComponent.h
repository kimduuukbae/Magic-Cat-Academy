#pragma once
#include "IComponent.h"
#include "structure.h"

class RigidbodyComponent : public IComponent {
public:
	RigidbodyComponent() = default;
	void process(Object* o) override;
	
	void setMass(float m);
	void setVelocity(float x, float y, float z);

private:
	Vector3D velocity;
	float mass;
};
