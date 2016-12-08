#pragma once
#include "CGSystem.h"
class CGSolarSystem : public CGSystem
{
private:

public:
	CGSolarSystem();
	~CGSolarSystem();

public:
	void Initialize();
	void Release();
	void Render();
	void Update();
};

