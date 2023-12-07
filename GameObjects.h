#pragma once
// File to include all game objects and dependencies
#include "RectObject.h"
#include "../Graphics.h"
#include <vector> // how to use -> https://en.cppreference.com/w/cpp/container/vector

class GameObjectsCollection {
public:
	GameObjectsCollection();
	~GameObjectsCollection();
	Vector2 CameraPosition;
private:
};