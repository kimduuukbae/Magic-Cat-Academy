#include "stdafx.h"
#include "PointManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Point.h"
#include "Time.h"
#include "EventDispatcher.h"

PointManager::PointManager(){
	mainPoint = D_MANAGER.addObject<Point>(
			Vector3D(0.0f,0.0f, 0.0f),
			color(0.4f, 0.4f, 0.4f, 1.0f),
			Vector3D(25, 25, 1),
			"Resources/draw_elipse.png"
			);
	pointCluster.reserve(500);
	pointColor = color{ 1.0f,1.0f,1.0f,1.0f };
	drawType = E_LINE;
}


void PointManager::update(){
	if (D_INPUT.getKeyDown(KeyCode::LEFT_BUTTON)) {
		auto[x, y] = D_INPUT.getMousePosition();
		mainPoint->setActive(true);
		mainPoint->setPosition(x, y-12, 0.0f);
	}
	else if (D_INPUT.getKeyUp(KeyCode::LEFT_BUTTON)) {
		mainPoint->setActive(false);
		for (auto& i : pointCluster) 
			i->setDelete();
		degreeAverage = 0.0f;
		pointColor.r = pointColor.r < 0.0f ? 0.0f : pointColor.r;
		pointColor.g = pointColor.g < 0.0f ? 0.0f : pointColor.g;
		pointColor.b = pointColor.b < 0.0f ? 0.0f : pointColor.b;

		if (drawType == E_LINE) {
			if (pointColor.g + pointColor.b < 1.0f)
				EventDispatcher::instance().Notify(Event{ E_RED });
			else if (pointColor.r + pointColor.g < 1.0f)
				EventDispatcher::instance().Notify(Event{ E_BLUE });
		}
		else if (drawType == E_UPPER && (pointColor.r + pointColor.b) < 1.0f)
			EventDispatcher::instance().Notify(Event{ E_GREEN });
		else if (drawType == E_DOWN && pointColor.b < 0.3f)
			EventDispatcher::instance().Notify(Event{ E_YELLOW });

		pointColor = color{ 1.0f,1.0f,1.0f,1.0f };
		pointCluster.clear();
		drawType = E_LINE;
	}
	
	if (mainPoint->getActive()) {
		auto[x, y] = D_INPUT.getMousePosition();
		y -= 12;
		auto[px, py, pz] = mainPoint->getPosition();

		mainPoint->setPosition(
			lerp(px, x, Time::getDeltaTime() * 20.0f),
			lerp(py, y, Time::getDeltaTime() * 20.0f),
			0.0f
		);
		
		if (pointCluster.size()) {
			Point* back = pointCluster.back();
			auto[gx, gy, gz] = back->getPosition();
			if (!circleCollision(gx, gy, px, py, 8.0f)) {
				auto size = abs(px - gx) + abs(py - gy);
				for (float i = 8.0f; i < size; i += 8.0f) {
					auto t = i / size;
					auto x = (1 - t) * gx + t * px;
					auto y = (1 - t) * gy + t * py;

					auto[ax, ay, az] = pointCluster.back()->getPosition();
					addPoint(x, y);

					auto degTemp = radToDegree(std::atan2(y - ay, x - ax));

					if (drawType == E_LINE) {
						if (degTemp > 20.0f && degTemp < 70.0f)
							drawType = E_UPPER;
						else if (degTemp < -20.0f && degTemp > -70.0f)
							drawType = E_DOWN;
					}
					degreeAverage = degreeAverage + (degTemp - degreeAverage) / (pointCluster.size() - 1);
				}
				if (drawType == E_LINE) {
					if ((degreeAverage < 5.0f && degreeAverage > -5.0f) ||
						abs(degreeAverage) > 150.0f) {
						pointColor.b -= 0.1f;
						pointColor.g -= 0.1f;
					}
					else if ((degreeAverage > 80.0f && degreeAverage < 100.0f) ||
						(degreeAverage < -80.0f && degreeAverage > -100.0f)) {
						pointColor.r -= 0.1f;
						pointColor.g -= 0.1f;
					}
					else
						pointColor = color{ 1.0f,1.0f,1.0f,1.0f };
				}
				else {

					if ((degreeAverage < 40.0f && degreeAverage > -40.0f) ||
						degreeAverage > 170.0f) {
						if (drawType == E_UPPER) {
							pointColor.r -= 0.1f;
							pointColor.b -= 0.1f;
						}
						else
							pointColor.b -= 0.1f;
					}
					else
						pointColor = color{ 1.0f,1.0f,1.0f,1.0f };
				}
			}
		}
		else 
			addPoint(px, py);
		
	}
}

void PointManager::addPoint(float x, float y){
	pointCluster.push_back(
		D_MANAGER.addObject<Point>(
			Vector3D(x, y, 0.0f),
			color(1.0f, 1.0f, 1.0f, 1.0f),
			Vector3D(15, 15, 1),
			"Resources/draw_elipse.png"
			));
	pointCluster.back()->setActive(true);
	pointCluster.back()->bindingColor(pointColor);
}