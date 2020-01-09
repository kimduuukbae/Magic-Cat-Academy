#include "stdafx.h"
#include "MenuScene.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sound.h"

void MenuScene::init() {
	D_MANAGER.setBackGround("Resources/menuImage.png");
	D_MANAGER.generatePng("Resources/numberAtlas.png");
}

void MenuScene::update() {
	if (D_INPUT.getKeyDown(KeyCode::LEFT_BUTTON)) {
		auto [x,y] = D_INPUT.getMousePosition();
		auto box = CollisionBox{ -100, 100, -150, -220 };
		auto mouseBox = CollisionBox{ x,x,y,y };
		if (AABBCollision(box, mouseBox))
			D_SCENE->changeScene("Game");
	}
}

void MenuScene::destroy() {
	
}
