#include "CGScene.h"
#include <gl/glut.h>


CGScene::CGScene()
{
}


CGScene::~CGScene()
{
}

void CGScene::Initialize() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(+1.0, +1.0, +1.0);
	glEnable(GL_LIGHTING);
}

void CGScene::Release() {

}

void CGScene::Render(int width, int height) {
	float ratio = width / (float)height;

	//3D Object Render
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 100);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

	//2D Object Render
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void CGScene::Update() {

}