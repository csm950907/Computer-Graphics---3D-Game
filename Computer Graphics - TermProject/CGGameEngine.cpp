#include "CGGameEngine.h"
#include "CGScene.h"
//constructor
CGGameEngine::CGGameEngine(){ }


CGGameEngine::~CGGameEngine(){ }

//private
void CGGameEngine::display() {
	this->_scene->Render();
}

void CGGameEngine::reshape(int width, int height) {
	float ratio = width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 100);
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
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(+1.0, +1.0, +1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

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