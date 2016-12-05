#pragma once
#include <gl/glut.h>

class CGScene;

class CGGameEngine
{
	
private:
	CGScene* _scene;
	bool _isKeyDown[256] = { 0, };
	int _width;
	int _height;

	static CGGameEngine* _instance;

public:
	CGGameEngine();
	~CGGameEngine();

	static CGGameEngine* GetInstance() {
		if (_instance == nullptr) _instance = new CGGameEngine();
		return _instance;
	}

	static void DestroyInstance() {
		if (_instance) {
			delete _instance;
			_instance = nullptr;
		}
	}

private:
	void initGame();

public:
	void GLInit(int argc, char** argv);
	void Run();
	void TearDownGL();

	void Display();
	void Reshape(int, int);
	void Update();
	void KeyDown(unsigned char key, int x, int y);
	void KeyUp(unsigned char key, int x, int y);
};

