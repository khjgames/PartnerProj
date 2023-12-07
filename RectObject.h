#pragma once

#include "Properties.h" // Making back-end game object classes for engine - Kieran

class RectObject {
public:
	RectObject(); // constructor
	~RectObject(); // destructor
	Color3 Color;
	Vector2 Position;
	Vector2 Size;
	bool Filled = true;
	void Draw(); // handled by engine to display object.
	void SetVisible(bool b);
	bool GetVisible();
private:
	bool Visible = true;
};