#pragma once
class CGScene
{
public:
	CGScene();
	~CGScene();

public:
	void Initialize();
	void Release();
	void Render(int width, int height);
	void Update();
};

