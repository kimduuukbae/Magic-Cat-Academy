#include "stdafx.h"
#include "structure.h"
#include <cmath>

color::color(float r1, float g1, float b1, float a1) :
r{ r1 },
g{ g1 },
b{ b1 },
a{ a1 }
{}

Vector3D::Vector3D(float xpos, float ypos, float zpos) : 
x{xpos},
y{ypos},
z{zpos}
{}

Vector3D& Vector3D::normalize() {
	float len = length();
	x /= len;
	y /= len;
	z /= len;
	return *this;
}

float Vector3D::size() {
	return fabsf(x) + fabsf(y) + fabsf(z);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) {
	return Vector3D{ x - rhs.x, y - rhs.y, z - rhs.z };
}

Vector3D Vector3D::operator-() {
	return Vector3D{ -x, -y, -z };
}

Vector3D & Vector3D::operator=(const Vector3D& rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& rhs) {
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}

Vector3D & Vector3D::operator+=(const Vector3D & rhs) {
	return (*this = *this + rhs);
	
}

Vector3D Vector3D::operator*(float scalar) {
	return Vector3D{ x * scalar, y * scalar, z * scalar };
}
Vector3D Vector3D::operator*(const Vector3D & rhs) {
	return Vector3D(x * rhs.x, y * rhs.y, z * rhs.z);
}
Vector3D Vector3D::operator/(float scalar) {
	return Vector3D{ x / scalar, y / scalar, z / scalar };
}

float Vector3D::distance(const Vector3D & rhs) {
	return Vector3D{ x - rhs.x , y - rhs.y, z - rhs.z }.length();
}

float Vector3D::length() {
	return std::sqrtf((x * x) + (y * y) + (z * z));
}

float lerp(float start, float end, float amount){
	return start + ((end - start) * amount);
}

float smoothstep(float start, float end, float amount){
	amount = clamp((amount - start) / (end - start), 0.0f, 1.0f);
	return amount * amount * amount * (amount * (amount * 6 - 15) + 10);
}

bool circleCollision(Vector3D origin, Vector3D target, float radius){
	return (target - origin).length() < radius;
}

bool circleCollision(float originX, float originY, float targetX, float targetY, float radius){
	return std::sqrt((targetX - originX) * (targetX - originX) +
		(targetY - originY) * (targetY - originY)) < radius;
}

float radToDegree(float rad) {
	return rad * 180 / 3.141592f;
}

float degreeToRad(float degree) {
	return degree * 3.141592f / 180;
}

bool AABBCollision(const CollisionBox& lhs, const CollisionBox& rhs){
	return (lhs.left < rhs.right &&
		lhs.right > rhs.left &&
		lhs.bottom < rhs.top &&
		lhs.top > rhs.bottom);
}
