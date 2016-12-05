#pragma once
#include <gl/glut.h>

class CGScene;

class CGGameEngine
{
private:
	CGScene* _scene;

public:
	CGGameEngine();
	~CGGameEngine();

private:
	void display();
	void reshape(int, int);
	void update();
	void initGame();

public:
	void GLInit(int argc, char** argv);
	void Run();
	void TearDownGL();
};