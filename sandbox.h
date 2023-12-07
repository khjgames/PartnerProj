#pragma once
#include "scene.h"
class sandbox {
public:
	sandbox() {};
	~sandbox() {};
	int Play(); // Returns scene return codes - Kieran
private:
	int x = 0;
	int y = 100;
};