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

void RectObject::Draw( Vector2 CamPos ){ // handled by engine to display object.
	if (Visible == true){
		Graphics::SetColor(Color.r, Color.g, Color.b); 
		Graphics::DrawRect(Position.x - CamPos.x, Position.y - CamPos.y, Size.x, Size.y, Filled); // x,y, width, height, filled?
	}
};

void RectObject::SetVisible(bool b) {
	Visible = b;
};

bool RectObject::GetVisible() {
	return Visible;
}