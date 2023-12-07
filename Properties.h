#pragma once

// Making back-end game object classes for engine - Kieran

class Vector2 {
public:
	Vector2(); // constructor
	~Vector2(); // destructor
	int x = 0;
	int y = 0;
	void Set(int _x, int _y);
private:
}; 

class Color3 {
public:
	Color3(); // constructor
	~Color3(); // destructor
	int r = 0;
	int g = 0;
	int b = 0;
	void Set(int _r, int _g, int _b);
private:
};