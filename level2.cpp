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

	// platforms are 2 pixels shorter than usual to prevent the final step from clipping into floor
	for (int i = 0; i < 5; i++) // right stairs
	{
		RectObject& Stair = SceneObjects.CreateRect();
		Stair.Color.Set(25, 25, 25);
		Stair.Size.Set(100, 39);
		Stair.Position.Set(880 + 100 * i, 380 + 38 * i);
	}

	for (int i = 0; i < 5; i++) // left stairs
	{
		RectObject& Stair = SceneObjects.CreateRect();
		Stair.Color.Set(25, 25, 25);
		Stair.Size.Set(100, 38);
		Stair.Position.Set(0 + 100 * i, 490 + 38 * i);
	}

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