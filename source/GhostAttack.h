#pragma once
#include "GhostState.h"

class GhostAttack : public IGhostState {
public:
	void enter(Ghost* t) override;
	void update(float deltaTime, Ghost* t) override;
};