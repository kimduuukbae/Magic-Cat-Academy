#pragma once
#include "Scene.h"

class EndScene : public Scene {
public:
	EndScene() = default;		//Awake

	void init() override;
	void update() override;
	void destroy() override;
};