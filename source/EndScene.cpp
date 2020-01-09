#include "stdafx.h"
#include "EndScene.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Sound.h"
#include "NumberPack.h"

void EndScene::init() {
	D_MANAGER.setBackGround("Resources/endtitle.png");
	//titleimage->setActive(true);
	NumberPack(D_MANAGER.getScore());
}

void EndScene::update() {
	if (D_INPUT.getKeyDown(KeyCode::LEFT_BUTTON)) 
			D_SCENE->changeScene("Menu");
	
}

void EndScene::destroy() {
	D_MANAGER.clear();
}
