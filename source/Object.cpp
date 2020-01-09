#include "stdafx.h"
#include "Object.h"
#include "Define.h"
#include <cmath>
#include <limits>
#include "IComponent.h"

Object::Object(){
	position = { 0.0f,0.0f,0.0f };
	volume = { 0.0f,0.0f,0.0f };
	pngIndex = -1;
	active = false;
	deleted = false;

	maxClipX = 1;
	maxClipY = 1;
	currentClipX = 1;
	currentClipY = 1;
	degree = 0.0f;
}

Object::~Object(){
	for (auto& i : components)
		delete i;
}

void Object::setPosition(float x, float y, float z){
	position = { x, y, z };
}

void Object::setVolume(float x, float y, float z){
	volume = { x, y, z };
}

void Object::setColor(float r, float g, float b, float a){
	objectColor = { r, g, b, a };
}

color Object::getColor(){
	return objectColor;
}

Vector3D Object::getPosition(){
	return position;
}

Vector3D Object::getVolume(){
	return volume;
}

void Object::update(float deltaTime){
	for (auto& i : components) 
		i->process(this);
}

void Object::setPngIndex(int idx){
	pngIndex = idx;
}

int Object::getPngIndex(){
	return pngIndex;
}

void Object::setActive(bool flag){
	active = flag;
}

bool Object::getActive(){
	return active;
}

void Object::setDelete(){
	active = false;
	deleted = true;
}

bool Object::getDelete(){
	return deleted;
}

int Object::getMaxClipX(){
	return maxClipX;
}

int Object::getMaxClipY(){
	return maxClipY;
}

void Object::setMaxClipX(int x){
	maxClipX = x;
}

void Object::setMaxClipY(int y){
	maxClipY = y;
}

void Object::setCurrentClipX(int x){
	currentClipX = x;
}

void Object::setCurrentClipY(int y){
	currentClipY = y;
}

int Object::getCurrentClipX(){
	return currentClipX;
}

int Object::getCurrentClipY(){
	return currentClipY;
}

void Object::setObjectType(const E_OBJECT_TYPE & e){
	objectType = e;
}

E_OBJECT_TYPE Object::getObjectType(){
	return objectType;
}

void Object::setDegree(float d){
	degree = d;
}

float Object::getDegree(){
	return degree;
}
