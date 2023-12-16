#pragma once

#include "Properties.h" // Making back-end game object classes for engine - Kieran
#include "RectObject.h"

class Character {
public:
	Character(); // constructor
	~Character(); // destructor
	RectObject Body;
private:
	Vector2 RespawnPosition;
};