#include "Properties.h"

// Making back-end game object classes for engine - Kieran

Vector2::Vector2(){} // constructor
Vector2::~Vector2(){} // destructor

void Vector2::Set(int _x, int _y){
	x = _x; y = _y;
}

Color3::Color3(){} // constructor
Color3::~Color3(){} // destructor

void Color3::Set(int _r, int _g, int _b) {
	r = _r; g = _g; b = _b;
}