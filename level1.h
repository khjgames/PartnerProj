#pragma once
#include "scene.h"
class level1 {
public:
	level1(); // constructor
	~level1(); // destructor 
	GameObjectsCollection SceneObjects;
	int Play(); // Returns scene return codes - Kieran
private:
	bool SwappedChars = false;
};