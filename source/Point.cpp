#include "stdafx.h"
#include "Point.h"
void Point::update(float deltaTime){
	auto[r, g, b, a] = *bindedColor;
	setColor(r,g,b,a);
}

void Point::bindingColor(color& c){
	bindedColor = &c;
}

