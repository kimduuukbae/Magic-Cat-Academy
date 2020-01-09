#pragma once
struct MouseInfo {
	int x, y;
};

class InputManager {
public:
	static InputManager& instance();
	InputManager() = default;
	bool getKeyOverlap(const int type) const;
	bool getKeyDown(const int type);
	bool getKeyUp(const int type);

	MouseInfo getMousePosition() const;
	void setMouseInfo(int button, int x, int y);
	void setMouseInfo(int x, int y);
	void updateKeyState();
private:
	bool mouseButton[2];
	bool keyState[2];
	MouseInfo mousePosition;
};

#define D_INPUT InputManager::instance()