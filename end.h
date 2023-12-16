#pragma once
#include "scene.h"
class levelEnd {
public:
	levelEnd(); // constructor
	~levelEnd(); // destructor 
	GameObjectsCollection SceneObjects;
	int Play(); // Returns scene return codes - Kieran
private:
	bool JPressedStateLastFrame = false;
	bool SwappedChars = false;
};