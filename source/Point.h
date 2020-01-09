#pragma once
#include "Object.h"
#include "structure.h"

class Point : public Object {
public:
	Point() : bindedColor{&objectColor}{}
	~Point() = default;

	void update(float deltaTime) override;
	void bindingColor(color& c);

private:
	color* bindedColor;
};
