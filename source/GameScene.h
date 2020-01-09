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

	float makeMonster; //���� ������ �ð�
	
	float levelTime; // ���� ���� ���� �ð�
	int level;	// ���� ����

	int monsterNum;	//���� ���� ����
};