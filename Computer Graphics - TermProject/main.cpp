#include <stdio.h>
#include "CGGameEngine.h"

CGGameEngine _gameEngine;
int main(int argc, char** argv) {
	_gameEngine.GLInit(argc, argv);
	_gameEngine.Run();
	_gameEngine.TearDownGL();
	return 0;
}