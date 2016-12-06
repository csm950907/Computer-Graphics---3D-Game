#pragma once
#include "CGMath.h"

class CGGameEngine;

class CGScene
{
private:
	CGGameEngine* m_engineInstance;

private:
	Vector3* m_cameraPos;
	Vector3* m_centerPos;

public:
	CGScene();
	~CGScene();

public:
	void Initialize();
	void Release();
	void Render(int width, int height);
	void Update();
};

