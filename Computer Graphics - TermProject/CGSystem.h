#pragma once
class CGSystem
{
private:

public:
	CGSystem();
	virtual ~CGSystem();

public:
	virtual void Initialize();
	virtual void Release();
	virtual void Render();
	virtual void Update();
};

