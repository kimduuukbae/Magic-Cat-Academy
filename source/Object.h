#pragma once
#include "structure.h"
#include <vector>

class IComponent;

class Object {
public:
	Object();
	virtual ~Object();

	void setPosition(float x, float y, float z);
	Vector3D getPosition();

	void setVolume(float x, float y, float z);
	Vector3D getVolume();

	void setColor(float r, float g, float b, float a);
	color getColor();

	virtual void update(float deltaTime);
	template <typename T>
	T* addComponent() {
		IComponent* comp = new T();
		components.push_back(comp);
		return static_cast<T*>(comp);
	}
	template <typename T>
	T* getComponent(){
		for (auto& i : components)
			if (typeid(T) == typeid(*i))
				return dynamic_cast<T*>(i);
		return nullptr;
	}

	void setPngIndex(int idx);
	int getPngIndex();

	void setActive(bool flag);
	bool getActive();

	void setDelete();
	bool getDelete();

	int getMaxClipX();
	int getMaxClipY();
	
	void setMaxClipX(int x);
	void setMaxClipY(int y);

	void setCurrentClipX(int x);
	void setCurrentClipY(int y);

	int getCurrentClipX();
	int getCurrentClipY();

	void setObjectType(const E_OBJECT_TYPE& e);
	E_OBJECT_TYPE getObjectType();

	void setDegree(float d);
	float getDegree();
	
protected:
	color objectColor;
private:
	Vector3D position;
	Vector3D volume;
	int pngIndex;
	std::vector<IComponent*> components;
	bool active;
	bool deleted;

	int maxClipX;
	int maxClipY;
	int currentClipX;
	int currentClipY;

	float degree;

	E_OBJECT_TYPE objectType;
};