#include "stdafx.h"
#include "Define.h"
#include "Dependencies/glew.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "structure.h"
#include "Scene.h"
#include <algorithm>
#include "InputManager.h"
static SceneManager* inst = NULL;

SceneManager* SceneManager::instance(){
	if (inst == NULL)
		inst = new SceneManager();
	return inst;
}

SceneManager::SceneManager(){
	objectManager = &ObjectManager::Instance();
}

SceneManager::~SceneManager(){
	delete objectManager;
	delete this;
}
void SceneManager::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	objectManager->draw();
}

void SceneManager::update(float deltaTime) {
	currentScene->update();
	objectManager->update(deltaTime);
	D_INPUT.updateKeyState();
	// getKeyDown, Up 을 업데이트 해주기 위해서 사용
}

void SceneManager::commit(Scene * scene, const std::string_view& name){
	if (!sceneCluster.size()) {
		currentScene = scene;
		currentScene->init();
	}
	sceneCluster.push_back(std::move(std::make_pair(scene, name)));
	
}

void SceneManager::changeScene(const std::string_view & name){
	currentScene->destroy();
	auto it = std::find_if(sceneCluster.begin(), sceneCluster.end(), [&name](auto&& pair) {
		auto[scene, sname] = pair;
		return (sname == name);
	});
	currentScene = it->first;
	currentScene->init();
}



Scene * SceneManager::getCurrentScene(){
	return currentScene;
}
