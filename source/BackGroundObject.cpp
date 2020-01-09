#include "stdafx.h"
#include "BackGroundObject.h"
void BackGroundObject::update(float deltaTime){
	frameTime += deltaTime;
	if (frameTime > 0.1f) {
		setCurrentClipX((getCurrentClipX() + 1) % getMaxClipX());
		frameTime = 0.0f;
	}
}
