#include "end.h"
#include "../Source/Objects/ColourBlock.h" //SYNTAX FIX - missing # infront of include
#include "../Source/EventHandler.h"

levelEnd::levelEnd() { // constructor
	SceneObjects = GameObjectsCollection();

	RectObject& Wall = SceneObjects.CreateRect();
	Wall.Color.Set(25, 25, 25);
	Wall.Size.Set(1280, 40);
	Wall.Position.Set(0, 0);

	RectObject& Wall2 = SceneObjects.CreateRect();
	Wall2.Color.Set(25, 25, 25);
	Wall2.Size.Set(1280, 40);
	Wall2.Position.Set(0, 680);

	Character& Jeff = SceneObjects.CreateCharacter("Jeff");
	Jeff.Body.Color.Set(0, 50, 6); // rgb(0, 127, 14)
	Jeff.Body.Size.Set(40, 40);
	Jeff.Body.Position.Set(50, 636);

	Character& John = SceneObjects.CreateCharacter("John");
	John.Body.Color.Set(0, 43, 74); // rgb(0, 127, 14)
	John.Body.Size.Set(40, 40);
	John.Body.Position.Set(1190, 636);

	Vector2 GatePos = Vector2(575, 663);
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
}
levelEnd::~levelEnd() {} // destructor

int levelEnd::Play() {
	// text, x, y, width, height, r, g, b 
	Graphics::DrawText("THE", 160, 75, 400, 300, 0, 50, 6);
	Graphics::DrawText("END", 720, 75, 400, 300, 0, 43, 74);

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

	RectObject& GatePad_1 = SceneObjects.GetRect("GatePad_1");
	RectObject& GatePad_2 = SceneObjects.GetRect("GatePad_2");
	if (PrimaryInput.Body.IsTouching(GatePad_1) || PrimaryInput.Body.IsTouching(GatePad_2)) {
		if (SecondaryInput.Body.IsTouching(GatePad_1) || SecondaryInput.Body.IsTouching(GatePad_2)) {
			PrimaryInput.Body.Size.x--;
			PrimaryInput.Body.Size.y--;
			SecondaryInput.Body.Size.x--;
			SecondaryInput.Body.Size.y--;
			if (PrimaryInput.Body.Size.x == 0) return scene::QUIT_GAME;
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