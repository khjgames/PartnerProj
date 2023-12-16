// processing events
#include "EventHandler.h"
#include <ctime>
// creating a basic gameobject
#include "Objects/ColourBlock.h"
#include "../Graphics.h"
#include "../RectObject.h" 
// VV loading game levels - Kieran VV // 
#include "../sandbox.h"
#include "../level1.h" 
#include "../level2.h"
#include "../level3.h"
#include "../level4.h"
#include "../end.h"
// ^^ loading game levels - Kieran ^^ //

using namespace std; // so I don't have to type std::vector

// GameState
bool GameRunning = true;

// argc and argv here are command line parameters passed to the program when running the program. 
// we won't actually use them but our 2D Graphics Library requires the main setup like this.
// Argc: the number of arguments pass
// argv[] : a char array of each of the params passed in ( each space is a new param)
int main( int argc, char *argv[] ) {
	srand(time(NULL));

	if (!Graphics::Init()) {
		return false;
	}

	sandbox MenuArea = sandbox(); 
	level1 PlayArea1 = level1(); 
	level2 PlayArea2 = level2();
	level3 PlayArea3 = level3();
	level4 PlayArea4 = level4();
	levelEnd EndScreen = levelEnd();
	 
	enum GameStates {AT_MENU, PLAY_LV_1, PLAY_LV_2, PLAY_LV_3, PLAY_LV_4, PLAY_END, SHUTTING_DOWN};
	int GameState = AT_MENU; 
	
	// Main game loop
	while (GameRunning) {
		Graphics::StartRender();

		// handle button events
		GameRunning = EventHandler::Update();

		// - VV menu functionality - //
		switch (GameState){
			case AT_MENU: {
				int MenuState = MenuArea.Play();
				switch (MenuState){
					case scene::ReturnCodes::QUIT_GAME:{
						GameState = SHUTTING_DOWN; 
						break;
					}
					case scene::ReturnCodes::START_GAME: {
						GameState = PLAY_LV_1;
						break;
					}
					case scene::ReturnCodes::START_LV_2: {
						GameState = PLAY_LV_2;
						break;
					}
					case scene::ReturnCodes::START_LV_3: {
						GameState = PLAY_LV_3;
						break;
					}
					case scene::ReturnCodes::START_LV_4: {
						GameState = PLAY_LV_4;
						break;
					}
					case scene::ReturnCodes::START_END: {
						GameState = PLAY_END;
						break;
					}
				} 
				break;
			}
			case PLAY_LV_1: {
				int PlayState = PlayArea1.Play();
				switch (PlayState) {
				case scene::ReturnCodes::QUIT_GAME: {
					GameState = SHUTTING_DOWN;
					break;
				}
				case scene::ReturnCodes::START_GAME: {
					GameState = PLAY_LV_1;
					break;
				}
				case scene::ReturnCodes::START_LV_2: {
					GameState = PLAY_LV_2;
					break;
				}
				case scene::ReturnCodes::START_LV_3: {
					GameState = PLAY_LV_3;
					break;
				}
				case scene::ReturnCodes::START_LV_4: {
					GameState = PLAY_LV_4;
					break;
				}
				case scene::ReturnCodes::START_END: {
					GameState = PLAY_END;
					break;
				}
				}
				break;
			}
			case PLAY_LV_2: {
				int PlayState = PlayArea2.Play();
				switch (PlayState) {
				case scene::ReturnCodes::QUIT_GAME: {
					GameState = SHUTTING_DOWN;
					break;
				}
				case scene::ReturnCodes::START_GAME: {
					GameState = PLAY_LV_1;
					break;
				}
				case scene::ReturnCodes::START_LV_2: {
					GameState = PLAY_LV_2;
					break;
				}
				case scene::ReturnCodes::START_LV_3: {
					GameState = PLAY_LV_3;
					break;
				}
				case scene::ReturnCodes::START_LV_4: {
					GameState = PLAY_LV_4;
					break;
				}
				case scene::ReturnCodes::START_END: {
					GameState = PLAY_END;
					break;
				}
				}
				break;
			}
			case PLAY_LV_3: {
				int PlayState = PlayArea3.Play();
				switch (PlayState) {
				case scene::ReturnCodes::QUIT_GAME: {
					GameState = SHUTTING_DOWN;
					break;
				}
				case scene::ReturnCodes::START_GAME: {
					GameState = PLAY_LV_1;
					break;
				}
				case scene::ReturnCodes::START_LV_2: {
					GameState = PLAY_LV_2;
					break;
				}
				case scene::ReturnCodes::START_LV_3: {
					GameState = PLAY_LV_3;
					break;
				}
				case scene::ReturnCodes::START_LV_4: {
					GameState = PLAY_LV_4;
					break;
				}
				case scene::ReturnCodes::START_END: {
					GameState = PLAY_END;
					break;
				}
				}
				break;
			}
			case PLAY_LV_4: {
				int PlayState = PlayArea4.Play();
				switch (PlayState) {
				case scene::ReturnCodes::QUIT_GAME: {
					GameState = SHUTTING_DOWN;
					break;
				}
				case scene::ReturnCodes::START_GAME: {
					GameState = PLAY_LV_1;
					break;
				}
				case scene::ReturnCodes::START_LV_2: {
					GameState = PLAY_LV_2;
					break;
				}
				case scene::ReturnCodes::START_LV_3: {
					GameState = PLAY_LV_3;
					break;
				}
				case scene::ReturnCodes::START_LV_4: {
					GameState = PLAY_LV_4;
					break;
				}
				case scene::ReturnCodes::START_END: {
					GameState = PLAY_END;
					break;
				}
				}
				break;
			}
			case PLAY_END: {
				int PlayState = EndScreen.Play();
				switch (PlayState) {
				case scene::ReturnCodes::QUIT_GAME: {
					GameState = SHUTTING_DOWN;
					break;
				}
				case scene::ReturnCodes::START_GAME: {
					GameState = PLAY_LV_1;
					break;
				}
				case scene::ReturnCodes::START_LV_2: {
					GameState = PLAY_LV_2;
					break;
				}
				case scene::ReturnCodes::START_LV_3: {
					GameState = PLAY_LV_3;
					break;
				}
				case scene::ReturnCodes::START_LV_4: {
					GameState = PLAY_LV_4;
					break;
				}
				case scene::ReturnCodes::START_END: {
					GameState = PLAY_END;
					break;
				}
				}
				break;
			}
		}
		// - ^^ menu functionality - //

		// apply the changes to the screen 
		Graphics::EndRender();

		SDL_Delay(16); // around 62.5 fps 
		
		if (GameState == SHUTTING_DOWN) break;
	}

	//close off the SDL window
	SDL_Quit();

	return true;
}
