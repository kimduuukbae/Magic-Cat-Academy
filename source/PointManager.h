#pragma once
#include <vector>
#include "structure.h"
// ȭ�鿡 �׷��� ��, �׷��� ����Ʈ���� ������ �Ŵ���
// Unity3D �󿡼�, PointManager�� Object�� ��ӹ޾ƾ���,
// ������ PointManager �� �׷����� ���� ���̱⶧����, renderComponent ��
// �߰����� �ʴ� ��Ȳ����, �׳� ������ �ñ��� �Ѵ�.

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