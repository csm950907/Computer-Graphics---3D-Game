#include "CGGameEngine.h"
#include "CGScene.h"
//constructor
CGGameEngine::CGGameEngine(){ }


CGGameEngine::~CGGameEngine(){ }

//private
void CGGameEngine::display() {

}

void CGGameEngine::reshape(int width, int height) {

}

void CGGameEngine::update() {

}

void CGGameEngine::initGame() {

}

//public
void CGGameEngine::GLInit(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("test");

	glutDisplayFunc(this->display);
	glutReshapeFunc(this->reshape);
	glutIdleFunc(this->update);
}

void CGGameEngine::Run() {
	initGame();
	glutMainLoop();
}

void CGGameEngine::TearDownGL() {
	//write release gl code in this.
}