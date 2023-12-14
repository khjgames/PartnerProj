#include "level3.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level3::level3() { // constructor
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
	Wall3.Size.Set(850, 40);
	Wall3.Position.Set(0, 500);

	RectObject& Wall4 = SceneObjects.CreateRect();
	Wall4.Color.Set(25, 25, 25);
	Wall4.Size.Set(500, 40);
	Wall4.Position.Set(0, 330);

	RectObject& Wall5 = SceneObjects.CreateRect();
	Wall5.Color.Set(25, 25, 25);
	Wall5.Size.Set(40, 200);
	Wall5.Position.Set(460, 330);

	RectObject& Wall6 = SceneObjects.CreateRect();
	Wall6.Color.Set(25, 25, 25);
	Wall6.Size.Set(280, 200);
	Wall6.Position.Set(1000, 500);

	RectObject& Wall7 = SceneObjects.CreateRect();
	Wall7.Color.Set(25, 25, 25);
	Wall7.Size.Set(40, 200);
	Wall7.Position.Set(0, 500);

	RectObject& Wall8 = SceneObjects.CreateRect();
	Wall8.Color.Set(25, 25, 25);
	Wall8.Size.Set(40, 200);
	Wall8.Position.Set(1000, 330);

	RectObject& Wall9 = SceneObjects.CreateRect();
	Wall9.Color.Set(25, 25, 25);
	Wall9.Size.Set(350, 40);
	Wall9.Position.Set(650, 330);

	RectObject& Wall10 = SceneObjects.CreateRect();
	Wall10.Color.Set(25, 25, 25);
	Wall10.Size.Set(100, 40);
	Wall10.Position.Set(1180, 330);

	RectObject& Jeff = SceneObjects.CreateRect("Jeff");
	Jeff.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Size.Set(40, 40);
	Jeff.Position.Set(100, 460);

	RectObject& John = SceneObjects.CreateRect("John");
	John.Color.Set(0, 43, 74); // rgb(0, 92, 127)
	John.Size.Set(40, 40);
	John.Position.Set(100, 640);
}
level3::~level3() {} // destructor

int level3::Play() {
	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP3_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	SceneObjects.Render();

	return scene::STAY_MENU;
}