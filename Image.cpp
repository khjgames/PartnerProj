#include "Image.h" // Experimental ~ coded to learn, with guesswork by Kieran J
//#include <SDL_ttf.h> Will I need this... Maybe???

SDL_Renderer* Image::renderer;

void Image::InitRenderer(SDL_Renderer* rend){
	renderer = rend;
}

void Image::DrawPixel(int x, int y){
	SDL_RenderDrawPoint(renderer, x, y);
}

void Image::DrawImage(const std::vector<std::vector<unsigned int>>& pixels, int offsetX, int offsetY) {
    for (size_t x = 0; x < pixels.size(); ++x) {
        for (size_t y = 0; y < pixels[x].size(); ++y) { 
            Image::DrawPixel(static_cast<int>(x) + offsetX, static_cast<int>(y) + offsetY);
        }
    }
}