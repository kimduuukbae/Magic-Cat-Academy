#pragma once
#include "Object.h"
// BackGround ����, �ִϸ��̼� �� ������Ʈ���� �ۼ��մϴ�.

class BackGroundObject : public Object {
public:
	BackGroundObject() = default;
	~BackGroundObject() = default;

	void update(float deltaTime) override;
private:
	float frameTime;
};