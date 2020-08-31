#pragma once


#include <Windows.h>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <ctime>
<<<<<<< Updated upstream
#undef main
using namespace std;

const int WIDTH_LONG_BACKGROUND = 1900;					// background lon
=======
#include <SDL_ttf.h>


#undef main
using namespace std;
const int outmenu = 2;
const int WIDTH_LONG_BACKGROUND = 4800;					// background lon
>>>>>>> Stashed changes
const int WIDTH_SHORT_BACKGROUND = 1200;				// background nho
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;								// chi so bit per pixel
const int NUM_THREAT = 3;


static SDL_Surface* g_screen = NULL;					//quan ly man hinh
static SDL_Surface* g_bkground = NULL;					//quan ly background
static SDL_Event	g_event;	
static SDL_Surface* g_img_menu = NULL;                  // Background


namespace SDLCommonFunc
{
	SDL_Surface* loadImage(string file);
	SDL_Rect applySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void applySurfaceClip(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	void cleanUp();
	bool checkCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int ShowMenu(SDL_Surface* des, TTF_Font* font);
	bool CheckFocusWithRect(const int& x,const int& y,const SDL_Rect& rect);
}