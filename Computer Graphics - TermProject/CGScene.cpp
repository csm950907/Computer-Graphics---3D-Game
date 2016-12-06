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
	glEnable(GL_DEPTH_TEST);
}

void CGScene::Release() {

}

void CGScene::Render(int width, int height) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float ratio = width / (float)height;
	
	//3D Object Render
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	glTranslatef(3, 0, 0);
	glutWireSphere(1, 20, 20);
	
	//2D Object Render
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(width / 2, height / 2, 0);
	glutSolidCube(30);
	glFlush();
}

void CGScene::Update() {

}