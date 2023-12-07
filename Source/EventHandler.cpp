#include "EventHandler.h"
#include <stdio.h>
#include <string.h>

bool EventHandler::events[];

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

bool EventHandler::Update()
{
	bool success = true;

	SDL_Event currEvents;

	while(	SDL_PollEvent(&currEvents))
	{
		switch (currEvents.key.keysym.sym)
		{
		case SDLK_a: {
			SetButton(GameEvents::A_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_b: {
			SetButton(GameEvents::B_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_c: {
			SetButton(GameEvents::C_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_d: {
			SetButton(GameEvents::D_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_e: {
			SetButton(GameEvents::E_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_f: {
			SetButton(GameEvents::F_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_g: {
			SetButton(GameEvents::G_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_h: {
			SetButton(GameEvents::H_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_i: {
			SetButton(GameEvents::I_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_j: {
			SetButton(GameEvents::J_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_k: {
			SetButton(GameEvents::K_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_l: {
			SetButton(GameEvents::L_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_m: {
			SetButton(GameEvents::M_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_n: {
			SetButton(GameEvents::N_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_o: {
			SetButton(GameEvents::O_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_p: {
			SetButton(GameEvents::P_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_q: {
			SetButton(GameEvents::Q_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_r: {
			SetButton(GameEvents::R_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_s: {
			SetButton(GameEvents::S_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_t: {
			SetButton(GameEvents::T_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_u: {
			SetButton(GameEvents::U_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_v: {
			SetButton(GameEvents::V_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_w: {
			SetButton(GameEvents::W_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_x: {
			SetButton(GameEvents::X_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_y: {
			SetButton(GameEvents::Y_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_z: {
			SetButton(GameEvents::Z_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_UP:
		{
			SetButton(GameEvents::UP_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_DOWN:
		{
			SetButton(GameEvents::DOWN_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_LEFT:
		{
			SetButton(GameEvents::LEFT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_RIGHT:
		{
			SetButton(GameEvents::RIGHT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_0:
		{
			SetButton(GameEvents::KP0_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_1:
		{
			SetButton(GameEvents::KP1_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_2:
		{
			SetButton(GameEvents::KP2_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_3:
		{
			SetButton(GameEvents::KP3_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_4:
		{
			SetButton(GameEvents::KP4_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_5:
		{
			SetButton(GameEvents::KP5_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_6:
		{
			SetButton(GameEvents::KP6_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_7:
		{
			SetButton(GameEvents::KP7_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_8:
		{
			SetButton(GameEvents::KP8_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		case SDLK_KP_9:
		{
			SetButton(GameEvents::KP9_PRESSED, currEvents.key.type == SDL_KEYDOWN);
			break;
		}
		}
	}
	return success;
}

void EventHandler::SetButton(GameEvents eventNum, bool pressed)
{
	events[eventNum] = pressed;
}
