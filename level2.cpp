#include "level2.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level2::level2() { // constructor
	SceneObjects = GameObjectsCollection();

	for (int i = 1; i < 10; i++) {
		RectObject& BgRect = SceneObjects.CreateRect();
		BgRect.Color.Set(0, 50, 50);
		BgRect.Size.Set(10, 10);
		BgRect.Position.Set(30 * i, 35 * i / 3 + 50);
	}

	RectObject& Red = SceneObjects.CreateRect("red");
	Red.Color.Set(100, 0, 0);
	Red.Size.Set(40, 40);
	Red.Position.Set(50, 150);
	//

	RectObject& Green = SceneObjects.CreateRect("green");
	Green.Color.Set(0, 100, 0);
	Green.Size.Set(70, 40);
	Green.Position.Set(350, 175);
}
level2::~level2() {} // destructor

int level2::Play() {

	// Examples:
	// to draw text:
	Graphics::DrawText("Level 2 map", 40, 0, 200, 50, 90, 20, 20); // text, x,y,width,height,r,g,b //SYNTAX FIX - missing " after Programming

	Graphics::DrawText("Keypad 3 to QUIT GAME!", 40, 300, 200, 50, 20, 20, 90); // text, x,y,width,height,r,g,b 

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP3_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	RectObject& Red = SceneObjects.GetRect("red");

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::W_PRESSED] == true) {
		Red.Position.y -= 3;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::A_PRESSED] == true) {
		Red.Position.x -= 3;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::S_PRESSED] == true) {
		Red.Position.y += 3;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::D_PRESSED] == true) {
		Red.Position.x += 3;
	}





	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::UP_PRESSED] == true) {
		SceneObjects.CameraPosition.y -= 2;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::LEFT_PRESSED] == true) {
		SceneObjects.CameraPosition.x -= 2;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::DOWN_PRESSED] == true) {
		SceneObjects.CameraPosition.y += 2;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::RIGHT_PRESSED] == true) {
		SceneObjects.CameraPosition.x += 2;
	}

	SceneObjects.Render();

	return scene::STAY_MENU;
}