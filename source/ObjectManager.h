#pragma once

#include "Object.h"
#include "Point.h"
#include <list>
#include <unordered_map>


class Renderer;

class ObjectManager {
public:
	
	static ObjectManager& Instance();
	void update(float deltaTime);
	void draw();
	void clear();

	template <typename T>
	decltype(auto) addObject(const Vector3D& pos, const color& c,
				   const Vector3D& volume, const char* texture) {
		Object* o = new T();
		o->setPosition(pos.x, pos.y, pos.z);
		o->setColor(c.r, c.g, c.b, c.a);
		o->setVolume(volume.x, volume.y, volume.z);
		o->setPngIndex(generatePng(texture));
		objectList.push_back(o);
		return static_cast<T*>(o);
	}
	void setBackGround(const char* texture);
	void addShakePower(int power);
	int generatePng(const char* texture);

	void initScore();
	void addScore(int add);
	int getScore();
private:
	ObjectManager();
	std::list<Object*> objectList;
	std::unordered_map<std::string, int> pngDictionary;
	Renderer* renderer;
	int score;

	int backGroundIndex;
	float shakePower;
};

#define D_MANAGER ObjectManager::Instance()