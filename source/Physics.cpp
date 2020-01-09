#include "stdafx.h"
#include "Physics.h"
#include "Object.h"

bool Physics::isCollide(Object * lhs, Object * rhs){
	auto [lx,ly,lz] = lhs->getPosition();
	auto[lvx, lvy, lvz] = lhs->getVolume();

	auto[rx, ry, rz] = rhs->getPosition();
	auto[rvx, rvy, rvz] = rhs->getVolume();

	if (lx - lvx / 2 < rx + rvx / 2 &&
		lx + lvx / 2 > rx - rvx / 2 &&
		ly - lvy / 2 < ry + rvy / 2 &&
		ly + lvy / 2 > ry - rvy / 2)
		return true;
	return false;
}