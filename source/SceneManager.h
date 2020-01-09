#pragma once
#include "structure.h"
#include <vector>
#include <string_view>

class ObjectManager;
class Scene;

class SceneManager {
public:
	static SceneManager* instance();
	
	~SceneManager();
	void draw();
	void update(float deltaTime);

	void commit(Scene* scene, const std::string_view& name);
	void changeScene(const std::string_view& name);
	Scene* getCurrentScene();

private:
	SceneManager();
	ObjectManager* objectManager;
	
	std::vector<std::pair<Scene*, std::string_view>> sceneCluster;
	Scene* currentScene;
	// Problem, SceneManager�� ObjectManager�� ������ �ȵ�,
	// ������ ������ �ʿ��� GameEngine ����...
};

#define D_SCENE SceneManager::instance()