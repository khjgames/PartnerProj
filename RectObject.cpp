#include "RectObject.h"
#include "../Graphics.h"
// Making back-end game object classes for engine - Kieran

RectObject::RectObject() { // constructor 
	Color = Color3();
	Position = Vector2();
	Size = Vector2();
	Name = "";
}
RectObject::~RectObject(){} // destructor

void RectObject::Update(){
	if (HasGravity){
		if ((JumpState > 17) || (JumpState == 0)){
			if (Rays.down >= 10) { // fall faster when high up
				Position.y += 3;
			}
			if (Rays.down >= 1) { // Check if we can fall at least 1 pixel and apply linear fall velocity
				Position.y++;
				if (Rays.down >= 2) {
					Position.y++;
					if (Rays.down >= 3) {
						Position.y++;
					}
				}
			}
		}
		if (JumpState >= 23) JumpState = 0;
		//
		if (JumpState > 0) { // apply force for 200 ms & 62.5 fps
			if (Rays.up >= 1) { // Check if we can go up at least 2 pixel and apply velocity with occasional boosts
				JumpState++;
				for (int a = 0; a < 4; a++) {
					if (JumpState % 2 == 0 && Rays.up >= (a+5)) Position.y--;
					else if (JumpState % 5 == 0 && Rays.up >= (a+5)) Position.y--;
				}

				for (int a = 0; a < 3; a++) {
					if (Rays.up >= (a + 2)) Position.y--;
				}
				Position.y--;
			}
			else { JumpState = 0; }
		}
	}
}

void RectObject::Draw( Vector2 CamPos ){ // handled by engine to display object.
	if (Enabled == true){
		Graphics::SetColor(Color.r, Color.g, Color.b); 
		Graphics::DrawRect(Position.x - CamPos.x, Position.y - CamPos.y, Size.x, Size.y, Filled); // x,y, width, height, filled?
	}
};

bool RectObject::IsTouching(RectObject b){
	// Used to check if position changes will be valid or interrupted
	if (GetEnabled() && b.GetEnabled()) {
		if (((b.Position.x >= Position.x) && (b.Position.x <= GetBottomRight().x)) || ((Position.x >= b.Position.x) && (Position.x <= b.GetBottomRight().x))) {
			if (((b.Position.y >= Position.y) && (b.Position.y <= GetBottomRight().y)) || ((Position.y >= b.Position.y) && (Position.y <= b.GetBottomRight().y))) {
				return true;
			}
		}
	}
	return false;
}

void RectObject::Move(bool dir) {
	if (dir == false) {
		for (int a = 0; a < 3; a++) {
			if (Rays.right >= (a + 1)) Position.x++;
			if (Position.x >= 1280) Position.x = -19;
		} 
	}
	else {
		for (int a = 0; a < 3; a++) {
			if (Rays.left >= (a + 1)) Position.x--;
			if (Position.x <= -Size.x) Position.x = 1279;
		}
	}
}

void RectObject::Jump(int power) { // 62.5fps
	if (Rays.down <= 0 && JumpState == 0){ // If there is no pixel gap found in the ray downwards we are on or sinking in the ground.
		JumpState = 1;
	}
}

Vector2 RectObject::GetBottomRight(){
	return Vector2(Position.x + Size.x, Position.y + Size.y);
}

void RectObject::SetEnabled(bool b) { Enabled = b; }
bool RectObject::GetEnabled() { return Enabled; }

void RectObject::SetGravity(bool enabled) { HasGravity = enabled; }
bool RectObject::GetGravity() { return HasGravity; }