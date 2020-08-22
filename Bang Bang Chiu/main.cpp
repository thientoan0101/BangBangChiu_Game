#include "CommonFunction.h"

#undef main

int main(int arc, char* argv[])
{
	bool is_quit = false;
	if (SDLCommonFunc::Init() == false)
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