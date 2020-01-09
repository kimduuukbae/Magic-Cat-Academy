#include "stdafx.h"
#include "GameScene.h"
#include "Time.h"
#include "ObjectManager.h"
#include "Cat.h"
#include "BackGroundObject.h"
#include "Ghost.h"
#include "Sound.h"

void GameScene::init(){
	D_MANAGER.initScore();
	D_MANAGER.setBackGround("Resources/level1/level1_stage.png");

	D_MANAGER.addObject<Cat>(Vector3D{ 0.0f,0.0f,-100.0f },
		color{ 1.0f,1.0f,1.0f,1.0f },
		Vector3D{ 160.0f,160.0f,1.0f },
		"Resources/magic_cat_atlas.png")->setActive(true);
	candle = D_MANAGER.addObject<BackGroundObject>(Vector3D{ -400.0f, -200.0f, -100.0f },
		color{ 1.0f,1.0f,1.0f,1.0f },
		Vector3D{ 240.0f,240.0f,1.0f },
		"Resources/level1/candle.png");

	candle->setActive(true);
	candle->setMaxClipX(4);

	Sound::instance().PlayBGSound(1, true, 100.0f);
	makeMonster = 0.0f;
	monsterNum = 1;
	level = 1;
	point = PointManager();
}

void GameScene::update(){
	point.update();
	makeMonster += Time::getDeltaTime();
	levelTime += Time::getDeltaTime();
	if (makeMonster > 3.0f) {
		for (int i = 0; i < monsterNum; ++i) {
			int x = 0;
			int y = 1 + rand() % 300;
			if (y > 0 && y < 250)
				x = 350 + rand() % 200;
			else
				x = rand() % 400;
			//x ¿Í y ÁÂÇ¥°áÁ¤

			x = rand() % 2 ? -x : x;
			y = rand() % 2 ? -y : y;

			auto t = D_MANAGER.addObject<Ghost>(Vector3D{ static_cast<float>(x),static_cast<float>(y),-150.0f },
				color{ 1.0f,1.0f,1.0f,0.0f },
				Vector3D{ 160.0f, 160.0f, 1.0f },
				"Resources/ghost.png");
			t->setActive(true);
			t->addSymbol(rand()%level + 1);
			if (x < 0)
				t->setDegree(180.0f);
		}
		makeMonster = 0.0f;
	}
	if (levelTime > 15.0f) {
		++level;
		levelTime = 0.0f;
		monsterNum = rand() % level + 1;
		monsterNum = monsterNum > 4 ? 3 : monsterNum;
	}
	
}

void GameScene::destroy(){
	D_MANAGER.clear();
	Sound::instance().StopBGSound(1);
}
