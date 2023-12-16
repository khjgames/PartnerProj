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

void GameObjectsCollection::Render(){

	for (unsigned c = 0; c < Characters.size(); ++c) {
		Characters[c].Body.Rays.up = 999; 
		Characters[c].Body.Rays.down = 999;
		Characters[c].Body.Rays.left = 999;
		Characters[c].Body.Rays.right = 999; 

		if (c == 0) {
			unsigned b = 1;

			if (Characters[b].Body.Position.x > Characters[c].Body.Position.x) { // Object is to the Right of character
				// Check if these two objects overlay vertically
				if ((Characters[c].Body.Position.y < Characters[b].Body.GetBottomRight().y) &&
					// if character top y position is above rect object bottom y position or
					(Characters[c].Body.GetBottomRight().y > Characters[b].Body.Position.y)) {
					// if character bottom y position is below rect object top y position then
					int dist = (Characters[b].Body.Position.x - Characters[c].Body.GetBottomRight().x);
					if (dist < Characters[c].Body.Rays.right) {
						Characters[c].Body.Rays.right = dist;
						Characters[c].Body.Rays.rightId = Characters[b].Body.ObjectId;
					}
					// Calculate overlap distance (can be negative or zero), for right distance it would be left position of object minus right position of character
					// if the left side of an object is < the right side of my character figure out by how much it is to the left of my right side, which should be 
					// 505(left-side-obj-x) - 500(right-side-char-x) = 5 to the right of me when positive 5 or 5 to the left of me when -5 and there is indeed a collision and its left side is overlapping my right and on the left side

				}
			}

			if (Characters[b].Body.Position.x < Characters[c].Body.Position.x) { // Object is to the Left of character
				// Check if these two objects overlay vertically
				if ((Characters[c].Body.Position.y < Characters[b].Body.GetBottomRight().y) &&
					// if character top y position is above rect object bottom y position or
					(Characters[c].Body.GetBottomRight().y > Characters[b].Body.Position.y)) {
					// if character bottom y position is below rect object top y position then 
					int dist = (Characters[c].Body.Position.x - Characters[b].Body.GetBottomRight().x);
					if (dist < Characters[c].Body.Rays.left) {
						Characters[c].Body.Rays.left = dist;
						Characters[c].Body.Rays.leftId = Characters[b].Body.ObjectId;
					}
				}
			}

			if (Characters[b].Body.Position.y < Characters[c].Body.Position.y) { // Object is Above the character 
				if ((Characters[c].Body.Position.x < Characters[b].Body.GetBottomRight().x) &&
					(Characters[c].Body.GetBottomRight().x > Characters[b].Body.Position.x)) {
					//
					int dist = (Characters[c].Body.Position.y - Characters[b].Body.GetBottomRight().y);
					if (dist < Characters[c].Body.Rays.up) {
						Characters[c].Body.Rays.up = dist;
						Characters[c].Body.Rays.upId = Characters[b].Body.ObjectId;
					}
					// 495(bottom-side-obj-y) - 500(top-side-char-y) = 5 above on y axis

				}
			}

			if (Characters[b].Body.Position.y > Characters[c].Body.Position.y) { // Object is Below the character 
				if ((Characters[c].Body.Position.x < Characters[b].Body.GetBottomRight().x) &&
					(Characters[c].Body.GetBottomRight().x > Characters[b].Body.Position.x)) {
					//
					int dist = (Characters[b].Body.Position.y - Characters[c].Body.GetBottomRight().y);
					if (dist < Characters[c].Body.Rays.down) {
						Characters[c].Body.Rays.down = dist;
						Characters[c].Body.Rays.downId = Characters[b].Body.ObjectId;
					}

					// 500(bottom-side-char-y) - 505(top-side-obj-y) = 5 below on y axis
				}
			} 
		
		}
		else if (c == 1){ 
			unsigned b = 0;

			if (Characters[b].Body.Position.x > Characters[c].Body.Position.x) { // Object is to the Right of character
				// Check if these two objects overlay vertically
				if ((Characters[c].Body.Position.y < Characters[b].Body.GetBottomRight().y) &&
					// if character top y position is above rect object bottom y position or
					(Characters[c].Body.GetBottomRight().y > Characters[b].Body.Position.y)) {
					// if character bottom y position is below rect object top y position then
					int dist = (Characters[b].Body.Position.x - Characters[c].Body.GetBottomRight().x);
					if (dist < Characters[c].Body.Rays.right) {
						Characters[c].Body.Rays.right = dist;
						Characters[c].Body.Rays.rightId = Characters[b].Body.ObjectId;
					};
					// Calculate overlap distance (can be negative or zero), for right distance it would be left position of object minus right position of character
					// if the left side of an object is < the right side of my character figure out by how much it is to the left of my right side, which should be 
					// 505(left-side-obj-x) - 500(right-side-char-x) = 5 to the right of me when positive 5 or 5 to the left of me when -5 and there is indeed a collision and its left side is overlapping my right and on the left side

				}
			}

			if (Characters[b].Body.Position.x < Characters[c].Body.Position.x) { // Object is to the Left of character
				// Check if these two objects overlay vertically
				if ((Characters[c].Body.Position.y < Characters[b].Body.GetBottomRight().y) &&
					// if character top y position is above rect object bottom y position or
					(Characters[c].Body.GetBottomRight().y > Characters[b].Body.Position.y)) {
					// if character bottom y position is below rect object top y position then
					int dist = (Characters[c].Body.Position.x - Characters[b].Body.GetBottomRight().x);
					if (dist < Characters[c].Body.Rays.left) {
						Characters[c].Body.Rays.left = dist;
						Characters[c].Body.Rays.leftId = Characters[b].Body.ObjectId;
					}
				}
			}

			if (Characters[b].Body.Position.y < Characters[c].Body.Position.y) { // Object is Above the character 
				if ((Characters[c].Body.Position.x < Characters[b].Body.GetBottomRight().x) &&
					(Characters[c].Body.GetBottomRight().x > Characters[b].Body.Position.x)) {
					//
					int dist = (Characters[c].Body.Position.y - Characters[b].Body.GetBottomRight().y);
					if (dist < Characters[c].Body.Rays.up) {
						Characters[c].Body.Rays.up = dist;
						Characters[c].Body.Rays.upId = Characters[b].Body.ObjectId;
					}
					// 495(bottom-side-obj-y) - 500(top-side-char-y) = 5 above on y axis

				}
			}

			if (Characters[b].Body.Position.y > Characters[c].Body.Position.y) { // Object is Below the character 
				if ((Characters[c].Body.Position.x < Characters[b].Body.GetBottomRight().x) &&
					(Characters[c].Body.GetBottomRight().x > Characters[b].Body.Position.x)) {
					//
					int dist = (Characters[b].Body.Position.y - Characters[c].Body.GetBottomRight().y);
					if (dist < Characters[c].Body.Rays.down) {
						Characters[c].Body.Rays.down = dist;
						Characters[c].Body.Rays.downId = Characters[b].Body.ObjectId;
					}
					// 500(bottom-side-char-y) - 505(top-side-obj-y) = 5 below on y axis
				}
			}
		}
	}

	for (unsigned i = 0; i < RectObjects.size(); ++i) {
		RectObjects[i].Update();
		RectObjects[i].Draw(CameraPosition);

		if (RectObjects[i].GetEnabled()) {
			for (unsigned c = 0; c < Characters.size(); ++c) {

				if (RectObjects[i].Position.x > Characters[c].Body.Position.x) { // Object is to the Right of character
					// Check if these two objects overlay vertically
					if ((Characters[c].Body.Position.y < RectObjects[i].GetBottomRight().y) &&
						// if character top y position is above rect object bottom y position or
						(Characters[c].Body.GetBottomRight().y > RectObjects[i].Position.y)) {
						// if character bottom y position is below rect object top y position then
						int dist = (RectObjects[i].Position.x - Characters[c].Body.GetBottomRight().x);
						if (dist < Characters[c].Body.Rays.right) {
							Characters[c].Body.Rays.right = dist;
							Characters[c].Body.Rays.rightId = RectObjects[i].ObjectId;
						}
						// Calculate overlap distance (can be negative or zero), for right distance it would be left position of object minus right position of character
						// if the left side of an object is < the right side of my character figure out by how much it is to the left of my right side, which should be 
						// 505(left-side-obj-x) - 500(right-side-char-x) = 5 to the right of me when positive 5 or 5 to the left of me when -5 and there is indeed a collision and its left side is overlapping my right and on the left side

					}
				}

				if (RectObjects[i].Position.x < Characters[c].Body.Position.x) { // Object is to the Left of character
					// Check if these two objects overlay vertically
					if ((Characters[c].Body.Position.y < RectObjects[i].GetBottomRight().y) &&
						// if character top y position is above rect object bottom y position or
						(Characters[c].Body.GetBottomRight().y > RectObjects[i].Position.y)) {
						// if character bottom y position is below rect object top y position then
						int dist = (Characters[c].Body.Position.x - RectObjects[i].GetBottomRight().x);
						if (dist < Characters[c].Body.Rays.left) {
							Characters[c].Body.Rays.left = dist;
							Characters[c].Body.Rays.leftId = RectObjects[i].ObjectId;
						}
					}
				}

				if (RectObjects[i].Position.y < Characters[c].Body.Position.y) { // Object is Above the character 
					if ((Characters[c].Body.Position.x < RectObjects[i].GetBottomRight().x) &&
						(Characters[c].Body.GetBottomRight().x > RectObjects[i].Position.x)) {
						//
						int dist = (Characters[c].Body.Position.y - RectObjects[i].GetBottomRight().y);
						if (dist < Characters[c].Body.Rays.up) {
							Characters[c].Body.Rays.up = dist;
							Characters[c].Body.Rays.upId = RectObjects[i].ObjectId;
						}
						// 495(bottom-side-obj-y) - 500(top-side-char-y) = 5 above on y axis

					}
				}

				if (RectObjects[i].Position.y > Characters[c].Body.Position.y) { // Object is Below the character 
					if ((Characters[c].Body.Position.x < RectObjects[i].GetBottomRight().x) &&
						(Characters[c].Body.GetBottomRight().x > RectObjects[i].Position.x)) {
						//
						int dist = (RectObjects[i].Position.y - Characters[c].Body.GetBottomRight().y);
						if (dist < Characters[c].Body.Rays.down) {
							Characters[c].Body.Rays.down = dist;
							Characters[c].Body.Rays.downId = RectObjects[i].ObjectId;
						}
						// 500(bottom-side-char-y) - 505(top-side-obj-y) = 5 below on y axis
					}
				}

			}
		}
	}
	for (unsigned i = 0; i < Characters.size(); ++i) {
		Characters[i].Body.Update();
		Characters[i].Body.Draw(CameraPosition);
	}
}

