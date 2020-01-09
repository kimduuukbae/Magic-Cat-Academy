#pragma once
#include "Scene.h"


class MenuScene : public Scene {
public:
	MenuScene() = default;		//Awake

	void init() override;
	void update() override;
	void destroy() override;
};