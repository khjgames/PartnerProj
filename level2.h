#pragma once
#include "scene.h"
class level2 {
public:
	level2(); // constructor
	~level2(); // destructor 
	GameObjectsCollection SceneObjects;
	int Play(); // Returns scene return codes - Kieran
private:
	bool JPressedStateLastFrame = false;
	bool SwappedChars = false;
};