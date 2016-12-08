#include "CGScene.h"
#include "CGGameEngine.h"
#include "CGSystemManager.h"
#include <gl/glut.h>

CGScene::CGScene()
{
}

CGScene::~CGScene()
{
	this->Release();
}

void CGScene::Initialize() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	m_engineInstance = CGGameEngine::GetInstance();

	m_cameraPos = new Vector3(0, 0, 10);
	m_centerPos = new Vector3(0, 0, 0);
	m_system = new CGSystemManager();
}

void CGScene::Release() {
	delete m_cameraPos;
	delete m_centerPos;
	delete m_system;
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
	gluLookAt(m_cameraPos->x, m_cameraPos->y, m_cameraPos->z, m_centerPos->x, m_centerPos->y, m_centerPos->z, 0, 1, 0);
	glTranslatef(3, 0, 0);
	glutWireCube(3);

	//2D Object Render
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(width / 2, height / 2, 0);
	glTranslatef(0, 0, 0);
	glutWireCube(30);
	glFlush();
}

void CGScene::Update() {

}