#include <stdio.h>
#include "CGGameEngine.h"

int main(int argc, char** argv) {
	CGGameEngine* _gameEngine = CGGameEngine::GetInstance();
	_gameEngine->GLInit(argc, argv);
	_gameEngine->Run();
	_gameEngine->TearDownGL();
	CGGameEngine::DestroyInstance();
	return 0;
}