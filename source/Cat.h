#pragma once
#include "Object.h"
#include "Observer.h"
#include <map>
#include <string>

class ICatState;
class CollisionComponent;
class Cat : public Object, Observer {
public:
	Cat();
	~Cat();

	void update(float deltaTime) override;
	void changeState(const std::string& name);
	void onNotify(const Event& e) override;
private:
	int frame;
	float frameTime;
	int soundNumber;

	std::map<std::string, ICatState*> eventQueue3;
	ICatState* currentState;
	CollisionComponent* collider;
};
