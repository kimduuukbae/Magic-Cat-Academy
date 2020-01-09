#include "stdafx.h"
#include "AttackSymbol.h"

AttackSymbol::AttackSymbol(){

}

EVENT_TYPE AttackSymbol::getEventType(){
	return event;
}

void AttackSymbol::setEventType(EVENT_TYPE e){
	event = e;
	setMaxClipX(4);
	setCurrentClipX(e);
}
