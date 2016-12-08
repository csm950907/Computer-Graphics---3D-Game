#pragma once
#define NUM_OF_SYSTEMS 1
typedef enum {
	SOLAR,

}UniversalSystem;

class CGSystem;

class CGSystemManager
{
private:
	CGSystem* m_systems[NUM_OF_SYSTEMS];

public:
	CGSystemManager();
	~CGSystemManager();
};

