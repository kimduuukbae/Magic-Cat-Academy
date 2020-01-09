#pragma once
#include "Scene.h"
#include "PointManager.h"

class Object;
class Sound;

class GameScene : public Scene {
public:
	GameScene() = default;		//Awake

	void init() override;
	void update() override;
	void destroy() override;
private:
	PointManager point;
	Object* candle;

	float makeMonster; //몬스터 만들어내는 시간
	
	float levelTime; // 게임 수준 관리 시간
	int level;	// 게임 수준

	int monsterNum;	//만들어낼 몬스터 갯수
};