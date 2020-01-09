#include "stdafx.h"
#include "InputManager.h"
#include "structure.h"

InputManager input;

InputManager& InputManager::instance(){
	return input;
}

bool InputManager::getKeyOverlap(const int type) const{
	return mouseButton[type];
}

bool InputManager::getKeyDown(const int type){
	if (!keyState[type] && mouseButton[type])
		return true;
	return false;
}

bool InputManager::getKeyUp(const int type){
	if (keyState[type] && !mouseButton[type])
		return true;
	return false;
}



MouseInfo InputManager::getMousePosition() const{
	return mousePosition;
}

void InputManager::setMouseInfo(int button, int x, int y){
	mouseButton[button] ^= 1;
	mousePosition = MouseInfo{ x - 512, -y + 300 };
}

void InputManager::setMouseInfo(int x, int y){
	mousePosition = MouseInfo{ x - 512, -y + 300 };
}

void InputManager::updateKeyState(){
	keyState[0] = mouseButton[0];
	keyState[1] = mouseButton[1];
}


