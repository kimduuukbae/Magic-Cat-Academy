#pragma once
#include <vector>
#include "structure.h"
// 화면에 그렸을 때, 그려질 포인트들을 관리할 매니저
// Unity3D 상에선, PointManager도 Object를 상속받아야함,
// 하지만 PointManager 는 그려지지 않을 것이기때문에, renderComponent 를
// 추가하지 않는 상황에선, 그냥 관리만 맡기기로 한다.

class Point;
class EventDispatcher;

class PointManager {
public:
	PointManager();
	~PointManager() = default;
	void update();

private:
	std::vector<Point*> pointCluster;
	Point* mainPoint;		//with draw Point
	float degreeAverage;
	color pointColor;
	void addPoint(float x, float y);

	enum E_DRAW_TYPE {
		E_LINE,
		E_UPPER,
		E_DOWN
	}drawType;
};