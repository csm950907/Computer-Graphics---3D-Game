#include "CGGameEngine.h"
#include "CGScene.h"
#include <stdio.h>

CGGameEngine* CGGameEngine::m_instance = nullptr;

//constructor
CGGameEngine::CGGameEngine(){ }


CGGameEngine::~CGGameEngine(){ }

//private
void display() {
	CGGameEngine::GetInstance()->Display();
}

void reshape(int width, int height) {
	CGGameEngine::GetInstance()->Reshape(width, height);
}

void update() {
	CGGameEngine::GetInstance()->Update();
}

void keyDown(unsigned char key, int x, int y) {
	CGGameEngine::GetInstance()->KeyDown(key, x, y);
}

void keyUp(unsigned char key, int x, int y) {
	CGGameEngine::GetInstance()->KeyUp(key, x, y);
}

void mouseInput(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {  }
		else if(state == GLUT_UP){	}
		else {	}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) {	}
		else if (state == GLUT_UP) {	}
		else {  }
	}
	else if(button == GLUT_MIDDLE_BUTTON){
		if (state == GLUT_DOWN) {	}
		else if (state == GLUT_UP) {	}
		else {  }
	}
	else {
		printf("Error : Invalid mouse button\n");
	}
}

void CGGameEngine::initGame() {
	this->_scene = new CGScene();
	this->_scene->Initialize();
}

//public
void CGGameEngine::GLInit(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Computer Graphics - 3D Game");
}

void CGGameEngine::Run() {
	initGame();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(update);
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutMouseFunc(mouseInput);
	glutMainLoop();
}

void CGGameEngine::TearDownGL() {
	//write release gl code in this.
}

void CGGameEngine::Display() {
	this->_scene->Render(this->_width, this->_height);
}

void CGGameEngine::Reshape(int width, int height) {
	this->_width = width; this->_height = height;
	
	glViewport(0, 0, width, height);
}

void CGGameEngine::Update() {
	if ((timeGetTime() - this->_elapsedTime) > 16) {
		this->_elapsedTime = timeGetTime();
		this->_scene->Update();
		glutPostRedisplay();
	}
	else {
	
	}
}

void CGGameEngine::KeyDown(unsigned char key, int x, int y) {
	this->_isKeyDown[key] = true;
}

void CGGameEngine::KeyUp(unsigned char key, int x, int y) {
	this->_isKeyDown[key] = false;
}

bool CGGameEngine::IsKeyDown(unsigned char key) {
	return this->_isKeyDown[key];
}