#include "level5.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level5::level5() { // constructor
	SceneObjects = GameObjectsCollection();

	RectObject& Wall = SceneObjects.CreateRect();
	Wall.Color.Set(25, 25, 25);
	Wall.Size.Set(1280, 40);
	Wall.Position.Set(0, 0);

	RectObject& Wall2 = SceneObjects.CreateRect();
	Wall2.Color.Set(25, 25, 25);
	Wall2.Size.Set(1280, 40);
	Wall2.Position.Set(0, 680);

	RectObject& Jeff = SceneObjects.CreateRect("Jeff");
	Jeff.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Size.Set(40, 40);
	Jeff.Position.Set(100, 280);

	RectObject& John = SceneObjects.CreateRect("John");
	John.Color.Set(0, 43, 74); // rgb(0, 92, 127)
	John.Size.Set(40, 40);
	John.Position.Set(100, 560);
}
level5::~level5() {} // destructor

int level5::Play() {
	RectObject& Bullet = SceneObjects.GetRect("bullet");
	RectObject& Bullet2 = SceneObjects.GetRect("bullet_2");
	RectObject& Bullet3 = SceneObjects.GetRect("bullet_3");

	Bullet.Position.x += 8;

	if (Bullet.Position.x >= 990)
	{
		Bullet.Position.x = 320;
	}

	Bullet2.Position.x += 8;

	if (Bullet2.Position.x >= 1220)
	{
		Bullet2.Position.x = 320;
	}

	Bullet3.Position.x += 8;

	if (Bullet3.Position.x >= 1220)
	{
		Bullet3.Position.x = 320;
	}

	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP3_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	SceneObjects.Render();

	return scene::STAY_MENU;
}