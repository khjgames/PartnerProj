#include "Character.h"
#include "../Graphics.h"
// Making back-end game object classes for engine - Kieran

Character::Character() { // constructor 
	Body = RectObject();
	Body.SetGravity(true);
}
Character::~Character() {} // destructor
