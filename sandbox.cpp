#include "sandbox.h"
#include "../Graphics.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

int sandbox::Play(){
	// Examples:
	// to draw text:
	Graphics::DrawText("SLC Game Programming", 40, 0, 200, 50, 90, 20, 20); // text, x,y,width,height,r,g,b //SYNTAX FIX - missing " after Programming

	// green line:
	Graphics::SetColor(40, 100, 40); // r,g,b
	Graphics::DrawLine(0, 52, 300, 78); // x-start,y-start, x-end, y-end

	// blue line:
	Graphics::SetColor(55, 55, 100); //SYNTAX FIX - missing , 100 for blue after 55
	Graphics::DrawLine(0, 50, 300, 50);

	// Pink filled square
	Graphics::SetColor(100, 0, 100); //SYNTAX FIX - missing ; end of statement
	Graphics::DrawRect(150, 100, 32, 32, true); // x,y, width, height, filled?

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

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::D_PRESSED] == true) { // other options are: W,A,S, UP, DOWN, LEFT, RIGHT, KP1 (keypad 1) //SYNTAX FIX - missing second equals in comparison
		x = x + 3; // x is a member variable. this means it holds a value and this line is changing to be +1 it every time it draws //SYNTAX FIX - change x == to x = 
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::S_PRESSED] == true) {// other options are: W,A,S, UP, DOWN, LEFT, RIGHT, KP1 (keypad 1)
		y = y + 3; // x is a member variable. this means it holds a value and this line is changing to be +1 it every time it draws //SYNTAX FIX - change y++ to y+
	}

	// Green unfilled square
	Graphics::SetColor(40, 100, 40);
	Graphics::DrawRect(x, y, 32, 32, false);

	return scene::STAY_MENU;
}