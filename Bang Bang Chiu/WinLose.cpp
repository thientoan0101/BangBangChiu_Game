#include "WinLose.h"

const int SCREEN_HEIGHT_SMALL = 350;
const int SCREEN_WIDTH_SMALL = 500;

SDL_Surface* smallScreen = NULL;					//quan ly man hinh
SDL_Surface* smallBkground = NULL;					//quan ly background




bool WinLoseFunc::initWinLoseBox()
{
	smallScreen = SDL_SetVideoMode(SCREEN_WIDTH_SMALL, SCREEN_HEIGHT_SMALL, SCREEN_BPP, SDL_SWSURFACE);		// Thiet lap che do dinh dang video SDL trong windows.

	if (smallScreen == NULL)
		return false;
}