#pragma once


#include <Windows.h>
#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_image.h>
#include <ctime>

#undef main
using namespace std;

const int WIDTH_LONG_BACKGROUND = 7680;					// background lon
const int WIDTH_SHORT_BACKGROUND = 1200;				// background nho
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_BPP = 32;								// chi so bit per pixel
const int NUM_THREAT = 3;
const int SPEED_BACKGROUND = 2;

extern SDL_Surface* g_screen;					//quan ly man hinh
extern SDL_Surface* g_bkground;					//quan ly background
extern SDL_Event	g_event;

namespace SDLCommonFunc
{
	SDL_Surface* loadImage(string file);
	SDL_Rect applySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void applySurfaceClip(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	void cleanUp();
	bool checkCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}