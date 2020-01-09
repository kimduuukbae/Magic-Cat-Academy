#pragma once

struct color {
	color() = default;
	color(float r1, float g1, float b1, float a1);
	float r, g, b, a;
};

struct Vector3D {
	Vector3D() = default;
	Vector3D(float xpos, float ypos, float zpos);
	Vector3D& normalize();

	Vector3D operator-(const Vector3D& rhs);
	Vector3D operator-();
	Vector3D& operator=(const Vector3D& rhs);
	Vector3D operator+(const Vector3D& rhs);
	Vector3D& operator+=(const Vector3D& rhs);
	Vector3D operator*(float scalar);
	Vector3D operator*(const Vector3D& rhs);
	Vector3D operator/(float scalar);

	float distance(const Vector3D& rhs);

	float size();
	float length();

	float x, y, z;
};

struct CollisionBox {
	int left, right, top, bottom;
};

template <typename T>
constexpr const T clamp(const T& low, const T& cent, const T& high) {
	return (cent < low) ? low : (cent > high) ? high : cent;
}

float lerp(float start, float end, float amount); 
float smoothstep(float start, float end, float amount);

namespace KeyCode {
	constexpr int LEFT_BUTTON = 0x0000;
	constexpr int RIGHT_BUTTON = 0x0001;
	constexpr int DOWN = 0x0000;
	constexpr int UP = 0x0001;
}

bool circleCollision(Vector3D origin, Vector3D target, float radius);
bool circleCollision(float originX, float originY, float targetX, float targetY, float radius);

float radToDegree(float rad);
float degreeToRad(float degree);

bool AABBCollision(const CollisionBox& lhs, const CollisionBox& rhs);


enum E_OBJECT_TYPE {
	E_OBJECT,
	E_GHOST,
	E_CAT
};