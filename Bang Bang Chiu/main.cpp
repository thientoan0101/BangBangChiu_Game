#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"
#include"MainObject.h"
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

	g_bkground = SDLCommonFunc::loadImage("bkgr.png");
	if (g_bkground == NULL)
	{
		cout << "ko load background dc" << endl;
		return 0;
	}

	// create mainObject===========================
	MainObject mainObject;
	createMainObject(mainObject);
	//=============================================

	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			} 
			//handle when user input========
			mainObject.handleInput(g_event);
			//==============================
		}
		
		SDLCommonFunc::applySurface(g_bkground, g_screen, 0, 0);

		// load mainObject to screen============================
		mainObject.handleMove();

		mainObject.showObject(g_screen);

		// load amo 
		mainObject.makeAmo(g_screen);
		//======================================================

		if (SDL_Flip(g_screen) == -1)
			return 0;

	}







	// SDL_Delay(10000);
	SDLCommonFunc::cleanUp();	
	SDL_Quit();
	return 1;
}