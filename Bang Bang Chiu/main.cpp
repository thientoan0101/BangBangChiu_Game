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

<<<<<<< Updated upstream
	g_bkground = SDLCommonFunc::loadImage("background.png");
=======
	g_bkground = SDLCommonFunc::loadImage("galaxybk.png");
>>>>>>> Stashed changes
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




<<<<<<< Updated upstream
=======
	// main cua Toan:
	// mo ra de chay thu:

	
	 // tao 1 enermy:
	 ThreatObject enermy;
	 enermy.setWidthHeight(WIDTH_THREAT_0, HEIGHT_THREAT_0);
	 enermy.loadImgObject("af1.png");
	 enermy.setType(ThreatObject::TYPE_2);

	 int rng_y = rand() % SCREEN_HEIGHT;
	 
	 enermy.setRect(SCREEN_WIDTH + rng_y, rng_y);
	 enermy.set_x_delta(8);
	

	

	// tao nhieu enermy:
	int numThreats;
	int level = 4;
	vector<ThreatObject*> listThreats;
	ThreatObject* pBoss = new ThreatObject;
	
	createListThreatObjects(listThreats, level, numThreats);
	createBoss(pBoss, 4);

	vector<ThreatObject*> listSub(2);

	for (int i = 0; i < listSub.size(); i++)
	{
		listSub[i] = new ThreatObject;
		createSubBoss(listSub[i], pBoss);
	}

	// Trong luc play game:
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


		// cap nhat lai background:
	
		if (is_run_screen == true)
		{
			bkgn_x -= SPEED_BACKGROUND;
			if (bkgn_x <= -(WIDTH_LONG_BACKGROUND - SCREEN_WIDTH))
			{
				is_run_screen = false;
				activeBoss = true;
			
			}
			else SDLCommonFunc::applySurface(g_bkground, g_screen, bkgn_x, 0);
		}
		else
		{
			SDLCommonFunc::applySurface(g_bkground, g_screen, bkgn_x, 0);
	 	}

		if (is_run_screen == false)
		{
			destroyThreatObjects(listThreats);
		}
	


		// nhieu threat:

		// có thẻ tao thành ham Move():
		for (int i = 0; i < listThreats.size(); i++)
		{
			bool checkOscillation = listThreats[i]->getOscillation();
			if (checkOscillation)
			{
				listThreats[i]->HandleMoveOscilate(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else {				
				listThreats[i]->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}		
			listThreats[i]->showObject(g_screen);
		}

		// kich hoat boss:

		if (activeBoss)
		{
			bool checkOscillation = pBoss->getOscillation();
			if (checkOscillation)
			{
				pBoss->HandleMoveOscilate(SCREEN_WIDTH, SCREEN_HEIGHT);
				activeSubBoss = true;
			}
			else {
				pBoss->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			pBoss->showObject(g_screen);
		}


		// xu ly Sub Boss:
		if (activeSubBoss)
		{
			for (int i = 0; i < listSub.size(); i++)
			{
				listSub[i]->HandleMoveSub(pBoss);
				listSub[i]->showObject(g_screen);
			}
		}

		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	for (int i = 0; i < listThreats.size(); i++)
	{
		delete listThreats[i];
	}

	for (int i = 0; i < listSub.size(); i++)
	{
		delete listSub[i];
	}
	delete pBoss;


	{														//NEU KO CHAY CAI DAM O TREN THI MO DONG NAY RA DE CHAY BACKGROUND.
		if (SDL_Flip(g_screen) == -1)						//Neu chay, dong cai dam ben nay lai.
			return 0;
		SDL_Delay(10000);					
	}
>>>>>>> Stashed changes



	// SDL_Delay(10000);
	SDLCommonFunc::cleanUp();	
	SDL_Quit();
	return 1;
}