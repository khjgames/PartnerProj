#include "level4.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

level4::level4() { // constructor
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
	Wall3.Size.Set(280, 40);
	Wall3.Position.Set(40, 600);

	RectObject& Wall4 = SceneObjects.CreateRect();
	Wall4.Color.Set(25, 25, 25);
	Wall4.Size.Set(280, 80);
	Wall4.Position.Set(1000, 600);

	RectObject& Wall5 = SceneObjects.CreateRect();
	Wall5.Color.Set(25, 25, 25);
	Wall5.Size.Set(40, 680);
	Wall5.Position.Set(0, 0);

	RectObject& Wall6 = SceneObjects.CreateRect();
	Wall6.Color.Set(25, 25, 25);
	Wall6.Size.Set(240, 40);
	Wall6.Position.Set(40, 640);

	RectObject& Wall7 = SceneObjects.CreateRect();
	Wall7.Color.Set(25, 25, 25);
	Wall7.Size.Set(1000, 40);
	Wall7.Position.Set(0, 400);

	RectObject& Wall8 = SceneObjects.CreateRect();
	Wall8.Color.Set(25, 25, 25);
	Wall8.Size.Set(280, 80);
	Wall8.Position.Set(40, 320);

	RectObject& Wall9 = SceneObjects.CreateRect();
	Wall9.Color.Set(25, 25, 25);
	Wall9.Size.Set(280, 40);
	Wall9.Position.Set(1000, 200);

	RectObject& Wall10 = SceneObjects.CreateRect();
	Wall10.Color.Set(25, 25, 25);
	Wall10.Size.Set(150, 40);
	Wall10.Position.Set(40, 160);

	RectObject& Wall11 = SceneObjects.CreateRect();
	Wall11.Color.Set(25, 25, 25);
	Wall11.Size.Set(40, 640);
	Wall11.Position.Set(1240, 40);

	RectObject& Gun = SceneObjects.CreateRect();
	Gun.Color.Set(50, 0, 0);
	Gun.Size.Set(40, 40);
	Gun.Position.Set(280, 640);

	RectObject& Bullet = SceneObjects.CreateRect("bullet");
	Bullet.Color.Set(100, 0, 0);
	Bullet.Size.Set(20, 20);
	Bullet.Position.Set(320, 650);

	RectObject& Gun2 = SceneObjects.CreateRect();
	Gun2.Color.Set(50, 0, 0);
	Gun2.Size.Set(40, 40);
	Gun2.Position.Set(280, 360);

	RectObject& Bullet2 = SceneObjects.CreateRect("bullet_2");
	Bullet2.Color.Set(100, 0, 0);
	Bullet2.Size.Set(20, 20);
	Bullet2.Position.Set(320, 370);

	RectObject& Gun3 = SceneObjects.CreateRect();
	Gun3.Color.Set(50, 0, 0);
	Gun3.Size.Set(40, 40);
	Gun3.Position.Set(280, 320);

	RectObject& Bullet3 = SceneObjects.CreateRect("bullet_3");
	Bullet3.Color.Set(100, 0, 0);
	Bullet3.Size.Set(20, 20);
	Bullet3.Position.Set(750, 330);

	RectObject& Jeff = SceneObjects.CreateRect("Jeff");
	Jeff.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Size.Set(40, 40);
	Jeff.Position.Set(100, 280);

	RectObject& John = SceneObjects.CreateRect("John");
	John.Color.Set(0, 43, 74); // rgb(0, 92, 127)
	John.Size.Set(40, 40);
	John.Position.Set(100, 560);
}
level4::~level4() {} // destructor

int level4::Play() {
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