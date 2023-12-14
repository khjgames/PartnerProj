#pragma once
// File to include all game objects and dependencies
#include "Character.h"
#include "../Graphics.h"
#include <iostream>
#include <string>
#include <vector> // how to use -> https://en.cppreference.com/w/cpp/container/vector

using namespace std; // to avoid std::vector types

class GameObjectsCollection {
public:
	GameObjectsCollection();
	~GameObjectsCollection();
	Vector2 CameraPosition;
	vector<RectObject> RectObjects;
	RectObject& CreateRect(); // func to create a rect and add it to rect objects
	RectObject& CreateRect(string name); // func to create a rect and add it to rect objects
	RectObject& GetRect(string name); // func to get a rect from rect objects by its name
	vector<Character> Characters;
	Character& CreateCharacter(); // func to create a rect and add it to rect objects
	Character& CreateCharacter(string name); // func to create a rect and add it to rect objects
	Character& GetCharacter(string name); // func to get a rect from rect objects by its name
	void Render();
private:
	int NextObjectId;
};