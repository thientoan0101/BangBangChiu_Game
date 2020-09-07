#pragma once

#include "CommonFunction.h"
#include "Menu.h"

extern const int SCREEN_HEIGHT_SMALL;
extern const int SCREEN_WIDTH_SMALL; 




extern SDL_Surface* smallScreen;					//quan ly man hinh
extern SDL_Surface* smallBkground;					//quan ly background



namespace WinLoseFunc
{
	bool initWinLoseBox();
}