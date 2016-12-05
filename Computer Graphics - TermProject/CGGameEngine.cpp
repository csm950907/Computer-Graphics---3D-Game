#include "CGGameEngine.h"
#include "CGScene.h"
//constructor
CGGameEngine::CGGameEngine(){ }


CGGameEngine::~CGGameEngine(){ }

//private
void CGGameEngine::display() {
	this->_scene->Render(this->_width, this->_height);
}

void CGGameEngine::reshape(int width, int height) {
	this->_width = width; this->_height = height;

	glViewport(0, 0, width, height);
}

void CGGameEngine::update() {
	this->_scene->Update();
	glutPostRedisplay();
}

void CGGameEngine::keyDown(unsigned char key, int x, int y) {
	this->_isKeyDown[key] = true;
}

void CGGameEngine::keyUp(unsigned char key, int x, int y) {
	this->_isKeyDown[key] = false;
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

	glutDisplayFunc(this->display);
	glutReshapeFunc(this->reshape);
	glutIdleFunc(this->update);
	glutKeyboardFunc(this->keyDown);
	glutKeyboardUpFunc(this->keyUp);
}

void CGGameEngine::Run() {
	initGame();
	glutMainLoop();
}

void CGGameEngine::TearDownGL() {
	//write release gl code in this.
}