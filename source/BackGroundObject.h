#pragma once
#include "Object.h"
// BackGround 에서, 애니메이션 될 오브젝트들을 작성합니다.

class BackGroundObject : public Object {
public:
	BackGroundObject() = default;
	~BackGroundObject() = default;

	void update(float deltaTime) override;
private:
	float frameTime;
};