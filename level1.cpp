#include "level1.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level1::level1(){ // constructor
	SceneObjects = GameObjectsCollection();

	RectObject& Wall = SceneObjects.CreateRect();
	Wall.Color.Set(25, 25, 25);
	Wall.Size.Set(1280, 40);
	Wall.Position.Set(0, 0);

	RectObject& Wall2 = SceneObjects.CreateRect();
	Wall2.Color.Set(25, 25, 25);
	Wall2.Size.Set(1280, 40);
	Wall2.Position.Set(0, 680);

	RectObject& Wall3 = SceneObjects.CreateRect();
	Wall3.Color.Set(25, 25, 25);
	Wall3.Size.Set(500, 40);
	Wall3.Position.Set(0, 340);

	RectObject& Wall4 = SceneObjects.CreateRect();
	Wall4.Color.Set(25, 25, 25);
	Wall4.Size.Set(500, 40);
	Wall4.Position.Set(780, 340);

	/*
	Character &Jeff = SceneObjects.CreateCharacter("Jeff");
	Jeff.Body.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Body.Size.Set(40, 40);
	Jeff.Body.Position.Set(50, 300);

	Character& John = SceneObjects.CreateCharacter("John");
	John.Body.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	John.Body.Size.Set(40, 40);
	John.Body.Position.Set(50, 300);
	*/
}
level1::~level1(){} // destructor

int level1::Play() {

	Graphics::DrawText("WASD -> PRIMARY CHARACTER", 60, 60, 260, 40, 85, 85, 85);
	Graphics::DrawText("ARROW KEYS -> SECONDARY CHARACTER", 60, 150, 300, 40, 85, 85, 85);
	Graphics::DrawText("J -> SWAP PRIMARY & SECONDARY", 60, 240, 280, 40, 85, 85, 85);

	// text, x, y, width, height, r, g, b 
	Graphics::DrawText("JEFF &", 460, 75, 200, 60, 0, 50, 6);
	Graphics::DrawText("JOHN", 680, 75, 140, 60, 0, 43, 74);

	Graphics::DrawText("Keypad 3 to QUIT GAME!", 20, 640, 250, 30, 50, 50, 50);

	if (EventHandler::events[GameEvents::J_PRESSED] == true) {
		 
	}
	if (EventHandler::events[GameEvents::J_PRESSED] == false) {
 
	}

	/*
	Character& Jeff = SceneObjects.GetCharacter("Jeff");
	Character& John = SceneObjects.GetCharacter("John");

	if (EventHandler::events[GameEvents::W_PRESSED] == true) { 
		Jeff.Jump();
	}
	if (EventHandler::events[GameEvents::A_PRESSED] == true) {
		Jeff.Move(true);
	}
	if (EventHandler::events[GameEvents::D_PRESSED] == true) {
		Jeff.Move(false);
	}

	if (EventHandler::events[GameEvents::UP_PRESSED] == true) {
		John.Jump();
	}
	if (EventHandler::events[GameEvents::LEFT_PRESSED] == true) {
		John.Move(true);
	}
	if (EventHandler::events[GameEvents::RIGHT_PRESSED] == true) {
		John.Move(false);
	}*/


	SceneObjects.Render();

	return scene::STAY_MENU;
}