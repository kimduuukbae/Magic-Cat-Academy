#pragma once
#include "GhostState.h"

class GhostDie : public IGhostState {
public:
	void enter(Ghost* t) override;
	void update(float deltaTime, Ghost* t) override;
};