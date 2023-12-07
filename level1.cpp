#include "level1.h"
#include "../Graphics.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

int level1::Play() {
	// Examples:
	// to draw text:
	Graphics::DrawText("Level 1 map", 40, 0, 200, 50, 90, 20, 20); // text, x,y,width,height,r,g,b //SYNTAX FIX - missing " after Programming

	Graphics::DrawText("Keypad 1 to start!", 40, 200, 200, 50, 20, 90, 20); // text, x,y,width,height,r,g,b 

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP1_PRESSED] == true) {
		return scene::START_GAME;
	}

	Graphics::DrawText("Right Arrow to QUIT GAME!", 40, 300, 200, 50, 20, 20, 90); // text, x,y,width,height,r,g,b 

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::RIGHT_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	return scene::STAY_MENU;
}