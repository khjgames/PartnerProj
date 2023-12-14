#include "Character.h"
#include "../Graphics.h"
// Making back-end game object classes for engine - Kieran

Character::Character() { // constructor 
	Body = RectObject();
}
Character::~Character() {} // destructor

void Character::Move(bool dir) {
	if (dir == false) {
		Body.Position.Set(Body.Position.x + 2, Body.Position.y);
		Body.Position.Set(Body.Position.x - 2, Body.Position.y);
	}
}

void Character::Jump() { //62.5fps
JumpState = JumpState + 1;
}
