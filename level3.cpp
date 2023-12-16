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

	Character& Jeff = SceneObjects.CreateCharacter("Jeff");
	Jeff.Body.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Body.Size.Set(40, 40);
	Jeff.Body.Position.Set(100, 460);

	Character& John = SceneObjects.CreateCharacter("John");
	John.Body.Color.Set(0, 43, 74); // rgb(0, 127, 14)
	John.Body.Size.Set(40, 40);
	John.Body.Position.Set(100, 640);

	Vector2 GatePos = Vector2(100, 315);
	RectObject& GateEdge_1 = SceneObjects.CreateRect();
		GateEdge_1.Filled = false;
		GateEdge_1.Color.Set(0, 50, 5);
		GateEdge_1.Size.Set(17, 17);
		GateEdge_1.Position.Set(GatePos.x, GatePos.y);
	RectObject& GatePad_1 = SceneObjects.CreateRect("GatePad_1");
		GatePad_1.Color.Set(0, 50, 5);
		GatePad_1.Size.Set(50, 4);
		GatePad_1.Position.Set(GatePos.x + 17, GatePos.y + 13);
	RectObject& GatePad_2 = SceneObjects.CreateRect("GatePad_2");
		GatePad_2.Color.Set(0, 43, 74);
		GatePad_2.Size.Set(50, 4);
		GatePad_2.Position.Set(GatePos.x + 67, GatePos.y + 13);
	RectObject& GateEdge_2 = SceneObjects.CreateRect();
		GateEdge_2.Filled = false;
		GateEdge_2.Color.Set(0, 43, 74);
		GateEdge_2.Size.Set(17, 17);
		GateEdge_2.Position.Set(GatePos.x + 117, GatePos.y);

	Vector2 PPlatePos = Vector2(300, 492);
	RectObject& PPlateBtn_1 = SceneObjects.CreateRect("PPlateBtn_1");
		PPlateBtn_1.Color.Set(74, 40, 0);
		PPlateBtn_1.Size.Set(40, 6);
		PPlateBtn_1.Position.Set(PPlatePos.x + 10, PPlatePos.y);
	RectObject& PPlate_1 = SceneObjects.CreateRect();
		PPlate_1.Color.Set(74, 40, 0);
		PPlate_1.Size.Set(60, 3);
		PPlate_1.Position.Set(PPlatePos.x, PPlatePos.y+6);

	RectObject& Platform_1 = SceneObjects.CreateRect("Platform_1");
		Platform_1.Filled = false;
		Platform_1.Color.Set(74, 40, 0);
		Platform_1.Size.Set(150, 20);
		Platform_1.Position.Set(850, 510);

	PPlatePos = Vector2(700, 492);
	RectObject& PPlateBtn_2 = SceneObjects.CreateRect("PPlateBtn_2");
		PPlateBtn_2.Color.Set(4, 48, 19); // rgb(9, 121, 49)
		PPlateBtn_2.Size.Set(40, 6);
		PPlateBtn_2.Position.Set(PPlatePos.x + 10, PPlatePos.y);
	RectObject& PPlate_2 = SceneObjects.CreateRect();
		PPlate_2.Color.Set(4, 48, 19);
		PPlate_2.Size.Set(60, 3);
		PPlate_2.Position.Set(PPlatePos.x, PPlatePos.y+6);

	RectObject& Platform_2 = SceneObjects.CreateRect("Platform_2");
		Platform_2.Filled = false;
		Platform_2.Color.Set(4, 48, 19);
		Platform_2.Size.Set(140, 20);
		Platform_2.Position.Set(1040, 340);
}
level3::~level3() {} // destructor

int level3::Play() {
	// this is an if statement. it checks if the d key is pressed and does what's inside the { } if it is
	if (EventHandler::events[GameEvents::KP3_PRESSED] == true) {
		return scene::QUIT_GAME;
	}

	if ((EventHandler::events[GameEvents::J_PRESSED] == true) && (JPressedStateLastFrame == false)) {
		JPressedStateLastFrame = true; SwappedChars = !SwappedChars;
	}
	if ((EventHandler::events[GameEvents::J_PRESSED] == false) && (JPressedStateLastFrame == true)) {
		JPressedStateLastFrame = false;
	}

	Character& SecondaryInput = (SwappedChars) ? SceneObjects.GetCharacter("Jeff") : SceneObjects.GetCharacter("John");
	Character& PrimaryInput = (SwappedChars) ? SceneObjects.GetCharacter("John") : SceneObjects.GetCharacter("Jeff");

	RectObject& Platform_1 = SceneObjects.GetRect("Platform_1");
	RectObject& PPlateBtn_1 = SceneObjects.GetRect("PPlateBtn_1");
	if ((PPlateBtn_1.GetEnabled()) && ((PPlateBtn_1.IsTouching(PrimaryInput.Body)) || (PPlateBtn_1.IsTouching(SecondaryInput.Body)))) {
		PPlateBtn_1.SetEnabled(false);
		Platform_1.SetEnabled(false);
	}

	RectObject& Platform_2 = SceneObjects.GetRect("Platform_2");
	RectObject& PPlateBtn_2 = SceneObjects.GetRect("PPlateBtn_2");
	if ((PPlateBtn_2.GetEnabled()) && ((PPlateBtn_2.IsTouching(PrimaryInput.Body)) || (PPlateBtn_2.IsTouching(SecondaryInput.Body)))) {
		PPlateBtn_2.SetEnabled(false);
		Platform_2.SetEnabled(false);
	}

	RectObject& GatePad_1 = SceneObjects.GetRect("GatePad_1");
	RectObject& GatePad_2 = SceneObjects.GetRect("GatePad_2");
	if (PrimaryInput.Body.IsTouching(GatePad_1) || PrimaryInput.Body.IsTouching(GatePad_2)) {
		if (SecondaryInput.Body.IsTouching(GatePad_1) || SecondaryInput.Body.IsTouching(GatePad_2)) {
			PrimaryInput.Body.Size.x--;
			PrimaryInput.Body.Size.y--;
			SecondaryInput.Body.Size.x--;
			SecondaryInput.Body.Size.y--;
			if (PrimaryInput.Body.Size.x == 0) return scene::START_LV_4;
		}
	}

	if (EventHandler::events[GameEvents::W_PRESSED] == true) {
		PrimaryInput.Body.Jump(10);
	}
	if (EventHandler::events[GameEvents::A_PRESSED] == true) {
		PrimaryInput.Body.Move(true);
	}
	if (EventHandler::events[GameEvents::D_PRESSED] == true) {
		PrimaryInput.Body.Move(false);
	}

	if (EventHandler::events[GameEvents::UP_PRESSED] == true) {
		SecondaryInput.Body.Jump(10);
	}
	if (EventHandler::events[GameEvents::LEFT_PRESSED] == true) {
		SecondaryInput.Body.Move(true);
	}
	if (EventHandler::events[GameEvents::RIGHT_PRESSED] == true) {
		SecondaryInput.Body.Move(false);
	}

	SceneObjects.Render();

	return scene::STAY_MENU;
}