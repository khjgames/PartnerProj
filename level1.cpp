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
	Wall4.Size.Set(600, 40);
	Wall4.Position.Set(700, 340);

	Character &Jeff = SceneObjects.CreateCharacter("Jeff");
	Jeff.Body.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Body.Size.Set(40, 40);
	Jeff.Body.Position.Set(50, 295);

	Character& John = SceneObjects.CreateCharacter("John");
	John.Body.Color.Set(0, 43, 74); // rgb(0, 127, 14)
	John.Body.Size.Set(40, 40);
	John.Body.Position.Set(1190, 636);

	Vector2 GatePos = Vector2(400,663);
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

	Vector2 PPlatePos = Vector2(800, 671);
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
		Platform_1.Size.Set(200, 20);
		Platform_1.Position.Set(500, 350);
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

	if ((EventHandler::events[GameEvents::J_PRESSED] == true) && (JPressedStateLastFrame == false)){
		JPressedStateLastFrame = true; SwappedChars = !SwappedChars;
	}
	if ((EventHandler::events[GameEvents::J_PRESSED] == false) && (JPressedStateLastFrame == true)){
		JPressedStateLastFrame = false;
	}
	Character& SecondaryInput = (SwappedChars) ? SceneObjects.GetCharacter("Jeff") : SceneObjects.GetCharacter("John");
	Character& PrimaryInput = (SwappedChars) ? SceneObjects.GetCharacter("John") : SceneObjects.GetCharacter("Jeff");


	RectObject& Platform_1 = SceneObjects.GetRect("Platform_1");
	RectObject& PPlateBtn_1 = SceneObjects.GetRect("PPlateBtn_1");
	if ( ( PPlateBtn_1.GetEnabled() ) && ( ( PPlateBtn_1.IsTouching(PrimaryInput.Body) ) || ( PPlateBtn_1.IsTouching(SecondaryInput.Body) ) ) ) {
		PPlateBtn_1.SetEnabled(false);
		Platform_1.SetEnabled(false);
	}

	RectObject& GatePad_1 = SceneObjects.GetRect("GatePad_1");
	RectObject& GatePad_2 = SceneObjects.GetRect("GatePad_2");
	if (PrimaryInput.Body.IsTouching(GatePad_1) || PrimaryInput.Body.IsTouching(GatePad_2)){
		if (SecondaryInput.Body.IsTouching(GatePad_1) || SecondaryInput.Body.IsTouching(GatePad_2)) {
			PrimaryInput.Body.Size.x--;
			PrimaryInput.Body.Size.y--;
			SecondaryInput.Body.Size.x--;
			SecondaryInput.Body.Size.y--;
			if (PrimaryInput.Body.Size.x == 0) return scene::START_LV_2;
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