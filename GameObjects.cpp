#include "GameObjects.h"

GameObjectsCollection::GameObjectsCollection(){
	CameraPosition = Vector2();
	NextObjectId = 0;
};

GameObjectsCollection::~GameObjectsCollection(){

}; 

RectObject& GameObjectsCollection::CreateRect() {
	RectObject NewRect = RectObject();
	NewRect.ObjectId = NextObjectId;
	RectObjects.push_back(NewRect);
	NextObjectId++;
	return RectObjects.back();
}

RectObject& GameObjectsCollection::CreateRect(string name){
	RectObject NewRect = RectObject(); 
	NewRect.ObjectId = NextObjectId;
	NewRect.Name = name;
	RectObjects.push_back(NewRect);
	NextObjectId++;
	return RectObjects.back();
}

RectObject& GameObjectsCollection::GetRect(string name) {
	for (unsigned i = 0; i < RectObjects.size(); ++i) {
		if (RectObjects[i].Name == name){
			return RectObjects[i];
		}
	}
}

Character& GameObjectsCollection::CreateCharacter() {
	Character NewCharacter = Character();
	NewCharacter.Body.ObjectId = NextObjectId;
	Characters.push_back(NewCharacter);
	NextObjectId++;
	return Characters.back();
}

Character& GameObjectsCollection::CreateCharacter(string name) {
	Character NewCharacter = Character();
	NewCharacter.Body.ObjectId = NextObjectId;
	NewCharacter.Body.Name = name;
	Characters.push_back(NewCharacter);
	NextObjectId++;
	return Characters.back();
}

Character& GameObjectsCollection::GetCharacter(string name) {
	for (unsigned i = 0; i < Characters.size(); ++i) {
		if (Characters[i].Body.Name == name) {
			return Characters[i];
		}
	}
}

struct Gate {
	Vector2 Position;
	Gate(GameObjectsCollection SceneObjects) {
		Position = Vector2();
		RectObject& Rect_1 = SceneObjects.CreateRect();
			Rect_1.Filled = false;
			Rect_1.Color.Set(0, 50, 5);
			Rect_1.Size.Set(17, 17);
			Rect_1.Position.Set(Position.x, Position.y);
		RectObject& Rect_2 = SceneObjects.CreateRect();
			Rect_2.Filled = false;
			Rect_2.Color.Set(0, 50, 5);
			Rect_2.Size.Set(50, 4);
			Rect_2.Position.Set(Position.x + 17, Position.y + 13);
		RectObject& Rect_3 = SceneObjects.CreateRect();
			Rect_3.Filled = false;
			Rect_3.Color.Set(0, 43, 74);
			Rect_3.Size.Set(17, 17);
			Rect_3.Position.Set(Position.x + 67, Position.y);
		RectObject& Rect_4 = SceneObjects.CreateRect();
			Rect_4.Filled = false;
			Rect_4.Color.Set(0, 43, 74);
			Rect_4.Size.Set(50, 4);
			Rect_4.Position.Set(Position.x + 17 + 67, Position.y + 13);
	}; // constructor
	~Gate() {}; // destructor
};

void GameObjectsCollection::Render(){
	for (unsigned i = 0; i < RectObjects.size(); ++i){
		RectObjects[i].Draw(CameraPosition);
	}
}

