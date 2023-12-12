#include "level2.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level2::level2() { // constructor
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
	Wall3.Size.Set(880, 40);
	Wall3.Position.Set(0, 340);

	RectObject& Stair = SceneObjects.CreateRect();
	Stair.Color.Set(25, 25, 25);
	Stair.Size.Set(100, 40);
	Stair.Position.Set(880, 380);

	RectObject& Stair2 = SceneObjects.CreateRect();
	Stair2.Color.Set(25, 25, 25);
	Stair2.Size.Set(100, 40);
	Stair2.Position.Set(980, 420);

	RectObject& Stair3 = SceneObjects.CreateRect();
	Stair3.Color.Set(25, 25, 25);
	Stair3.Size.Set(100, 40);
	Stair3.Position.Set(1080, 460);

	RectObject& Stair4 = SceneObjects.CreateRect();
	Stair4.Color.Set(25, 25, 25);
	Stair4.Size.Set(100, 40);
	Stair4.Position.Set(1200, 500);

	RectObject& Stair5 = SceneObjects.CreateRect();
	Stair5.Color.Set(25, 25, 25);
	Stair5.Size.Set(100, 40);
	Stair5.Position.Set(1180, 500);

	RectObject& Stair6 = SceneObjects.CreateRect();
	Stair6.Color.Set(25, 25, 25);
	Stair6.Size.Set(100, 40);
	Stair6.Position.Set(0, 500);

	RectObject& Stair7 = SceneObjects.CreateRect();
	Stair7.Color.Set(25, 25, 25);
	Stair7.Size.Set(100, 40);
	Stair7.Position.Set(100, 540);

	RectObject& Stair8 = SceneObjects.CreateRect();
	Stair8.Color.Set(25, 25, 25);
	Stair8.Size.Set(100, 40);
	Stair8.Position.Set(200, 580);

	RectObject& Stair9 = SceneObjects.CreateRect();
	Stair9.Color.Set(25, 25, 25);
	Stair9.Size.Set(100, 40);
	Stair9.Position.Set(300, 620);

	RectObject& Stair10 = SceneObjects.CreateRect();
	Stair10.Color.Set(25, 25, 25);
	Stair10.Size.Set(100, 40);
	Stair10.Position.Set(400, 660);

	RectObject& Jeff = SceneObjects.CreateRect("Jeff");
	Jeff.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Size.Set(40, 40);
	Jeff.Position.Set(50, 300);

	RectObject& John = SceneObjects.CreateRect("John");
	John.Color.Set(0, 43, 74); // rgb(0, 92, 127)
	John.Size.Set(40, 40);
	John.Position.Set(1190, 640);
}
level2::~level2() {} // destructor

int level2::Play() {
	Graphics::DrawText("Keypad 3 to QUIT GAME!", 20, 640, 250, 30, 50, 50, 50);

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP3_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	SceneObjects.Render();

	return scene::STAY_MENU;
}