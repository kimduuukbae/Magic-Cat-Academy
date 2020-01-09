#pragma once
#include <list>
#include "Event.h"
class AttackSymbol;
class Ghost;

class AttackPack{
public:
	~AttackPack();
	AttackPack(int count);
	void setPackPosition(Ghost* t);
	void checkSymbol(EVENT_TYPE e);
	int getSymbolCount();
private:
	std::list<AttackSymbol*> symbolList;
};