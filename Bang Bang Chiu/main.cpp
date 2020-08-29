#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"
#include "ExplosionObject.h"
#include "ThreatsObject.h"
#include "Audio.h"
#undef main


bool Init()	// wait bo vao mot class nao do :)			// Khoi tao che do su dung thu vien SDL voi kieu la: SDL_INIT_EVEYTHNG
{														// Sau nay, nhung ham khoi tao font, audio se duoc tao o day.

	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);		// Thiet lap che do dinh dang video SDL trong windows.

	if (g_screen == NULL)
		return false;

	AudioFunction::prepareAudioFile();

	


	return true;
}


int main(int arc, char* argv[])
{
	bool activeBoss = false;
	bool activeSubBoss = false;
	int bkgn_x = 0;
	bool is_run_screen = true;
	bool is_quit = false;
	if (Init() == false)
		return 0;


	

	g_bkground = SDLCommonFunc::loadImage("bg4800.png");
	if (g_bkground == NULL)
	{
		cout << "ko load background dc" << endl;
		return 0;
	}
	SDLCommonFunc::applySurface(g_bkground, g_screen, 0, 0);


	// tao MainObject:
	MainObject planeMain_object;

	planeMain_object.setRect(100, 200);

	//bool ret = human_object.LoadImg("plane80.png");					//helicopter
	bool ret = planeMain_object.loadImgObject("plane_fly.png");					//plane_fly
	if (!ret)
	{
		return 0;
	}


	

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

	// Init Explosion Object:
	ExplosionObject exp_subboss;
	ret = exp_subboss.loadImgObject("expo_small.png");
	exp_subboss.set_clip_small();
	if (ret == false)	return false;



	Mix_PlayChannel(-1, g_sound_ready, 0);



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
			planeMain_object.HandleInputAction(g_event);
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


		// Implement main object:
		planeMain_object.HandleMove();
		planeMain_object.showObject(g_screen);
		planeMain_object.MakeAmo(g_screen);




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
			listThreats[i]->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);							// moi them 





			//------------------------------------------------------------------------
			// Xu ly amo cua Main vs Threat:
			vector<AmoObject*> amo_list = planeMain_object.GetAmoList();
			for (int im = 0; im < amo_list.size(); im++)
			{
				AmoObject* p_amo = amo_list.at(im);
				if (p_amo != NULL)
				{
					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), listThreats[i]->getRect());
					if (ret_col)
					{
						// moi them:

						Mix_PlayChannel(-1, g_sound_injured, 0);

						for (int ex = 0; ex < 4; ex++)
						{
							int x_pos = (listThreats[i]->getRect().x + listThreats[i]->getRect().w*0.5) - SMALL_EXP_WIDTH * 0.5;
							int y_pos = (listThreats[i]->getRect().y + listThreats[i]->getRect().h*0.5) - SMALL_EXP_HEIGHT * 0.5;

							exp_subboss.set_frame(ex);
							exp_subboss.setRect(x_pos, y_pos);
							exp_subboss.showExSmall(g_screen);
							SDL_Delay(1);

							if (SDL_Flip(g_screen) == -1)
								return 0;
						}
													   						 					 
						int rng_y = rand() % SCREEN_HEIGHT;
						listThreats[i]->Reset(SCREEN_WIDTH + im * rng_y);
						planeMain_object.RemoveAmo(im);
					}
				}
			}
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
			pBoss->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
		}


		// xu ly Sub Boss:
		if (activeSubBoss)
		{
			for (int i = 0; i < listSub.size(); i++)
			{
				listSub[i]->HandleMoveSub(pBoss);
				listSub[i]->showObject(g_screen);
				listSub[i]->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
				
				//-------------------------------------------------------------------------   draft:
				MainObject* pMain = &planeMain_object;
				//listSub[i]->MakeAmoSpecial(g_screen, pMain);
							   

			// Xu ly amo cua Main vs subBoss:
				vector<AmoObject*> amo_list = planeMain_object.GetAmoList();
				for (int im = 0; im < amo_list.size(); im++)
				{
					AmoObject* p_amo = amo_list.at(im);
					if (p_amo != NULL)
					{
						bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), listSub[i]->getRect());
						if (ret_col)
						{
							// moi them:

							Mix_PlayChannel(-1, g_sound_injured, 0);

							for (int ex = 0; ex < 4; ex++)
							{
								int x_pos = (listSub[i]->getRect().x + listSub[i]->getRect().w*0.5) - SMALL_EXP_WIDTH * 0.5;
								int y_pos = (listSub[i]->getRect().y + listSub[i]->getRect().h*0.5) - SMALL_EXP_HEIGHT * 0.5;

								exp_subboss.set_frame(ex);
								exp_subboss.setRect(x_pos, y_pos);
								exp_subboss.showExSmall(g_screen);
								SDL_Delay(1);

								if (SDL_Flip(g_screen) == -1)
									return 0;
							}

							SDL_Rect tempRect = pBoss->getRect();
							listSub[i]->setRect(tempRect.x - tempRect.w / 5, tempRect.y + tempRect.h / 2);
							planeMain_object.RemoveAmo(im);
						}
					}
				}


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


	// SDL_Delay(10000);
	
	SDLCommonFunc::cleanUp();	
	SDL_Quit();
	return 1;
}