#include "RectObject.h"
#include "../Graphics.h"
// Making back-end game object classes for engine - Kieran

RectObject::RectObject(){ // constructor
	Color = Color3();
	Position = Vector2();
	Size = Vector2();
}
RectObject::~RectObject(){} // destructor

void RectObject::Draw(){ // handled by engine to display object.
	if (Visible == true){
		Graphics::SetColor(100, 0, 100); 
		Graphics::DrawRect(Position.x, Position.y, Size.x, Size.y, Filled); // x,y, width, height, filled?
	}
};

void RectObject::SetVisible(bool b) {
	Visible = b;
};

bool RectObject::GetVisible() {
	return Visible;
}