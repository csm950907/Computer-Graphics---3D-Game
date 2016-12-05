#pragma once
#include <gl/glut.h>

class CGScene;

class CGGameEngine
{
private:
	CGScene* _scene;
	bool _isKeyDown[256] = { 0, };
public:
	CGGameEngine();
	~CGGameEngine();

private:
	void display();
	void reshape(int, int);
	void update();
	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void initGame();

public:
	void GLInit(int argc, char** argv);
	void Run();
	void TearDownGL();
};