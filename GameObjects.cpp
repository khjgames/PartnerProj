#include "GameObjects.h"

GameObjectsCollection::GameObjectsCollection(){
	CameraPosition = Vector2();
	NextObjectId = 0;
};

GameObjectsCollection::~GameObjectsCollection(){

}; 

RectObject& GameObjectsCollection::CreateRect() {
	RectObject NewRect = RectObject(NextObjectId);
	RectObjects.push_back(NewRect);
	NextObjectId++;
	return RectObjects.back();
}

RectObject& GameObjectsCollection::CreateRect(string name){
	RectObject NewRect = RectObject(NextObjectId); 
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

void GameObjectsCollection::Render(){
	for (unsigned i = 0; i < RectObjects.size(); ++i){
		RectObjects[i].Draw(CameraPosition);
	}
}

