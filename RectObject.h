#pragma once

#include "Properties.h" // Making back-end game object classes for engine - Kieran

class RectObject {
public:
	RectObject(); // constructor
	~RectObject(); // destructor

	RayDists Rays;
	Color3 Color;
	Vector2 Position;
	Vector2 Size;
	string Name;
	int ObjectId;

	bool Filled = true;
	void Update();
	void Draw( Vector2 CamPos ); // handled by engine to display object.
	void Move(bool dir);
	bool IsTouching(RectObject b);
	void Jump(int power);

	Vector2 GetBottomRight();
	void SetEnabled(bool b);
	bool GetEnabled(); 
	void SetGravity(bool enabled);
	bool GetGravity();
private:
	bool Enabled = true;
	int JumpState = 0;
	int FallState = 1;
	bool HasGravity = false;
};