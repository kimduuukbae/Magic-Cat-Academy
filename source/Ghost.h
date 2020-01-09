#pragma once
#include "Object.h"
#include "Observer.h"
#include <map>
#include <string_view>

class IGhostState;
class AttackPack;

class Ghost : public Object, Observer {
public:
	Ghost();
	~Ghost();

	void update(float deltaTime) override;
	void onNotify(const Event& e) override;
	void changeState(const std::string_view& name);
	void addSymbol(int count);
private:
	int frame;
	float frameTime;

	std::map<std::string_view, IGhostState*> eventQueue2;
	IGhostState* currentState;
	AttackPack* symbolList;
};
