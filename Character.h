#pragma once

#include "Properties.h" // Making back-end game object classes for engine - Kieran
#include "RectObject.h"

class Character {
public:
	Character(); // constructor
	~Character(); // destructor
	RectObject Body;
	Vector2 RespawnPosition;
	int JumpState = 0; 
	void Move(bool dir);
	void Jump();
private:
	bool Visible = true;
};