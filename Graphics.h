#pragma once

#include "SDL.h"
#include "../Source/Objects/ObjData.h"

class Graphics
{
public:
	// should be called only once on boot.
	static bool Init();

	// needs to be called once at the start and end of game loops rendering
	static void StartRender();
	static void EndRender();

	//drawing specific functions
	static void SetColor(Colour color);
	static void SetColor(int r, int g, int b);
	static void DrawRect(Transform2D transform, Vec2D dimensions, bool isFilled = false);
	static void DrawRect(int x, int y, int width, int height, bool isFilled = false);
	static void DrawLine(Transform2D transform, Vec2D dimensions);
	static void DrawLine(int x, int y, int width, int height);
	static void DrawText(const char* text, float x, float y, int width, int height);
	static void DrawText(const char* text, float x, float y, int width, int height, int r, int g, int b);

private:
	// some SDL specific variables:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
};

