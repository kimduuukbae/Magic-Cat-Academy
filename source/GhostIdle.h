#pragma once
#include "GhostState.h"

class CollisionComponent;

class GhostIdle : public IGhostState {
public:
	void enter(Ghost* t) override;
	void update(float deltaTime, Ghost* t) override;

private:
	CollisionComponent* collider;
};