#include "stdafx.h"
#include "NumberPack.h"
#include "Number.h"
#include "ObjectManager.h"
NumberPack::NumberPack(int number) {
	if (number != 0) {
		int count = 0;
		for (int temp = number; temp != 0; temp /= 10)
			++count;
		float width = count * -16.0f;
		while (count--) {
			auto t = D_MANAGER.addObject<Number>(
				Vector3D{ 0.0f,0.0f,0.0f },
				color{ 1.0f,1.0f,1.0f,1.0f },
				Vector3D{ 64.0f,64.0f,1.0f },
				"Resources/numberAtlas.png"
				);
			t->setNumber(number % 10);
			t->setActive(true);
			t->setPosition(246.0f + (count * 32.0f) + width, 10.0f, 0.0f);
			number /= 10;
		}
	}
	else {
		auto t = D_MANAGER.addObject<Number>(
			Vector3D{ 0.0f,0.0f,0.0f },
			color{ 1.0f,1.0f,1.0f,1.0f },
			Vector3D{ 64.0f,64.0f,1.0f },
			"Resources/numberAtlas.png"
			);
		t->setNumber(0);
		t->setActive(true);
		t->setPosition(246.0f, 10.0f, 0.0f);
	}
}
