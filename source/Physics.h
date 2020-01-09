#pragma once
class Object;
class Physics {
public:
	Physics() = default;
	~Physics() = default;
	bool isCollide(Object* lhs, Object* rhs);
	bool processCollision(Object* A, Object* B);
private:
};