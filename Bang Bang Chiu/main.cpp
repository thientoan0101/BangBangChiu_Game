#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"
#undef main


bool Init()	// wait bo vao mot class nao do :)			// Khoi tao che do su dung thu vien SDL voi kieu la: SDL_INIT_EVEYTHNG
{														// Sau nay, nhung ham khoi tao font, audio se duoc tao o day.
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);		// Thiet lap che do dinh dang video SDL trong windows.

	if (g_screen == NULL)
		return false;

	return true;
}


int main(int arc, char* argv[])
{
	bool is_quit = false;
	if (Init() == false)
		return 0;

	g_bkground = SDLCommonFunc::loadImage("background.png");
	if (g_bkground == NULL)
	{
		cout << "ko load background dc" << endl;
		return 0;
	}

	SDLCommonFunc::applySurface(g_bkground, g_screen, 0, 0);

	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
		}
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}







	// SDL_Delay(10000);
	SDLCommonFunc::cleanUp();	
	SDL_Quit();
	return 1;
}