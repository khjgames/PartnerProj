#include "ColourBlock.h"

// processing events
#include "../EventHandler.h"
#include "../Graphics.h"

ColourBlock::ColourBlock()
{
	origColour.r = rand() % 255;
	origColour.g = rand() % 255;
	origColour.b = rand() % 255;

	colour = origColour;
}

ColourBlock::~ColourBlock()
{
}

void ColourBlock::SetColor(int r, int g, int b)
{
	colour.r = r;
	colour.g = g;
	colour.b = b;
}

void ColourBlock::Init(float x, float y, int width, int height)
{
	transform.position.x = x;
	transform.position.y = y;

	dimensions.x = width;
	dimensions.y = height;

}

void ColourBlock::Reset()
{
	colour = origColour;
}

void ColourBlock::Draw(bool filled)
{
	// create a bounding box based on the dimensions and position.
	Graphics::SetColor(colour);
	Graphics::DrawRect(transform, dimensions, filled);
}

void ColourBlock::Update()
{

}
