#pragma once
#include <gl/glut.h>
#include <Windows.h>
class CGScene;

class CGGameEngine
{
	
private:
	CGScene* _scene;
	bool _isKeyDown[256] = { 0, };
	bool _isMouseDown[3] = { 0, };
	int _width;
	int _height;

	DWORD _elapsedTime = 0;
	static CGGameEngine* m_instance;

public:
	CGGameEngine();
	~CGGameEngine();

	static CGGameEngine* GetInstance() {
		if (m_instance == nullptr) m_instance = new CGGameEngine();
		return m_instance;
	}

	static void DestroyInstance() {
		if (m_instance) {
			delete m_instance;
			m_instance = nullptr;
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
	bool IsKeyDown(unsigned char key);
};

