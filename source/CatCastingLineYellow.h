#pragma once

#include "CatState.h"

class CatCastingLineYellow : public ICatState {
public:
	void enter(Cat* t) override;
	void update(float deltaTime, Cat* t) override;
};