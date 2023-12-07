#pragma once

#include "SDL.h" // Experimental ~ coded to learn, with guesswork by Kieran J
#include <vector>

class Image {
public:
	//drawing specific functions
	static void InitRenderer(SDL_Renderer* renderer);
	static void DrawPixel(int x, int y);
	static void DrawImage(const std::vector<std::vector<unsigned int>>& pixels, int offsetX, int offsetY);
private:
	// some SDL specific variables:
	static SDL_Renderer* renderer;
};