#pragma once
#include "SDL.h"

enum GameEvents
{
	W_PRESSED,
	A_PRESSED,
	S_PRESSED,
	D_PRESSED,
	UP_PRESSED,
	DOWN_PRESSED,
	LEFT_PRESSED,
	RIGHT_PRESSED,
	KP1_PRESSED,

	NUM_GAME_EVENTS

};

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	static bool Update();

	static const int NUM_EVENTS = 10;
 
	static bool events[GameEvents::NUM_GAME_EVENTS];
private:

	static void SetButton(GameEvents eventNum, bool pressed);
};


