#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"
#include "ExplosionObject.h"
#include "ThreatsObject.h"
#include "Audio.h"
#include"HPObject.h"
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
	int level;
	cout << "chon level: ";	cin >> level;		// 1->4

	//int level = 4;

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

	// create main HP
	HP hp;
	hp.init();

	// tao MainObject:
	MainObject mainObject;

	mainObject.setRect(100, SCREEN_HEIGHT / 2);

	//bool ret = human_object.LoadImg("plane80.png");					//helicopter
	bool ret = mainObject.loadImgObject("main.png");					//main
	if (!ret)
	{
		return 0;
	}


	

	// tao nhieu enermy:
	int numThreats;

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
	
	//this is for subBoss
	ExplosionObject exp_subboss;
	ret = exp_subboss.loadImgObject("expo_small.png");
	exp_subboss.set_clip_small();
	if (ret == false)	return false;

	//this for main
	ExplosionObject explo_main;
	ret = explo_main.loadImgObject("expo_small.png");
	explo_main.set_clip_small();
	
	if (!ret) return 0;

	Mix_PlayChannel(-1, g_sound_ready, 0);

	// biến đếm số lần main trúng đạn
	unsigned int die_num = 0;

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
			mainObject.handleInput(g_event);
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

		// show hp
		hp.render(g_screen);

		// Implement main object:
		mainObject.handleMove();
		mainObject.showObject(g_screen);
		mainObject.makeAmo(g_screen);




		// nhieu threat:
	
		for (int i = 0; i < listThreats.size(); i++)
		{
			listThreats[i]->Move();
			// Xử lý amo của threat tới main:

			vector<AmoObject*> amoList1 = listThreats[i]->GetAmoList();
			for (int k = 0; k < amoList1.size(); k++) {
				AmoObject* p_amo = amoList1.at(k);
				if (p_amo) {
					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), mainObject.getRect());
					if (ret_col) {
						for (int ex = 0; ex < 4; ex++) {

							int x_explo = (mainObject.getRect().x + mainObject.getRect().w * 0.5) - EXP_WIDTH * 0.5;
							int y_explo = (mainObject.getRect().y + mainObject.getRect().h * 0.5) - EXP_HEIGHT * 0.5;

							//upload explosion
							explo_main.set_frame(ex);
							explo_main.setRect(x_explo, y_explo);
							//explo_main.showEx(g_screen);
							explo_main.showUpgrade(g_screen);
							//update screen
							if (SDL_Flip(g_screen) == -1) return 0;
						}

						// check hp
						die_num += DAME_OF_THREAT;
						if (die_num >= LIFE) {
							if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
								//free memory
								SDL_Quit();
								return 1;
							}
						}
						else {
							for (int i = 0; i < DAME_OF_THREAT; i++) hp.decreaseHP();
							hp.render(g_screen);
							if (SDL_Flip(g_screen) == -1) {
								//free memory
								SDL_Quit();
								return 1;
							}
							// delete threat_amo when it collision main
						
							listThreats[i]->ResetAmo(p_amo);
						}//===============HP==================
					}
				}
			}
			//------------------------------------------------------------------------



			// Xu ly main va cham voi threat
			//check collision
			bool isColi = SDLCommonFunc::checkCollision(mainObject.getRect(), listThreats[i]->getRect());
			if (isColi) {
				/*score_value += 100;*/
				for (int ex = 0; ex < 4; ex++) {
					//main explosion animation
					int x_explo_main = (mainObject.getRect().x + mainObject.getRect().w * 0.5) - EXP_WIDTH * 0.5;
					int y_explo_main = (mainObject.getRect().y + mainObject.getRect().h * 0.5) - EXP_HEIGHT * 0.5;
					explo_main.set_frame(ex);
					explo_main.setRect(x_explo_main, y_explo_main);
					explo_main.showEx(g_screen);

					//threat explosion animation
					int x_explo_threat = (listThreats[i]->getRect().x + listThreats[i]->getRect().w * 0.5) - EXP_WIDTH * 0.5;
					int y_explo_threat = (listThreats[i]->getRect().y + listThreats[i]->getRect().h * 0.5) - EXP_HEIGHT * 0.5;

					//upload explosion
					exp_subboss.set_frame(ex);
					exp_subboss.setRect(x_explo_threat, y_explo_threat);
					exp_subboss.showEx(g_screen);

					//update screen
					if (SDL_Flip(g_screen) == -1) return 0;
				}

				// check hp
				die_num += DAME_OF_THREAT;;
				if (die_num >= LIFE) {
					if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
						//free memory
						SDL_Quit();
						return 1;
					}
				}
				else {
					for (int i = 0; i < DAME_OF_THREAT; i++) hp.decreaseHP();
					hp.render(g_screen);
					if (SDL_Flip(g_screen) == -1) {
						//free memory
						SDL_Quit();
						return 1;
					}
					int rng_y = rand() % SCREEN_HEIGHT;
					listThreats[i]->Reset(SCREEN_WIDTH + i * rng_y);
				}//=========hp===========
			}

	
			//------------------------------------------------------------------------
			// Xu ly amo cua Main vs Threat:
			vector<AmoObject*> amo_list = mainObject.getAmoList();
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
						mainObject.removeAmo(im);
					}
				}
			}
		}

		// kich hoat boss:
		if (activeBoss)
		{
			pBoss->Move();
			pBoss->showObject(g_screen);
			pBoss->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			activeSubBoss = true;

			MainObject* pMain = &mainObject;


			//main vs đạn boss ở cuối trận	   
			vector<AmoObject*> amoList3 = pBoss->GetAmoList();
			for (int k = 0; k < amoList3.size(); k++) {
				AmoObject* p_amo = amoList3.at(k);
				if (p_amo) {
					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), pMain->getRect());
					if (ret_col) {
						for (int ex = 0; ex < 4; ex++) {

							int x_explo = (pMain->getRect().x + pMain->getRect().w * 0.5) - EXP_WIDTH * 0.5;
							int y_explo = (pMain->getRect().y + pMain->getRect().h * 0.5) - EXP_HEIGHT * 0.5;

							//upload explosion
							explo_main.set_frame(ex);
							explo_main.setRect(x_explo, y_explo);
							explo_main.showEx(g_screen);

							//update screen
							if (SDL_Flip(g_screen) == -1) return 0;
						}

						// check hp
						die_num += DAME_OF_BOSS;
						if (die_num >= LIFE) {
							if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
								//free memory
								SDL_Quit();
								return 1;
							}
						}
						else {
							for (int i = 0; i < DAME_OF_BOSS; i++) hp.decreaseHP();
							hp.render(g_screen);
							if (SDL_Flip(g_screen) == -1) {
								//free memory
								SDL_Quit();
								return 1;
							}
							// delete threat_amo when it collision main
							//pBoss->Reset(pBoss->getRect().x);
							pBoss->ResetAmo(p_amo);
						}//===============HP==================
					}
				}
			}

		}


		// xu ly Sub Boss:
		if (activeSubBoss)
		{
			for (int i = 0; i < listSub.size(); i++)
			{
				listSub[i]->HandleMoveSub(pBoss);
				listSub[i]->showObject(g_screen);
				listSub[i]->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			
				
				MainObject* pMain = &mainObject;
				//main vs đạn subboss ở cuối trận	   
				
				vector<AmoObject*> amoList2 = listSub[i]->GetAmoList();
				for (int k = 0; k < amoList2.size(); k++) {
					AmoObject* p_amo = amoList2.at(k);
					if (p_amo) {
						bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), pMain->getRect());
						if (ret_col) {
							for (int ex = 0; ex < 4; ex++) {

								int x_explo = (pMain->getRect().x + pMain->getRect().w * 0.5) - EXP_WIDTH * 0.5;
								int y_explo = (pMain->getRect().y + pMain->getRect().h * 0.5) - EXP_HEIGHT * 0.5;

								//upload explosion
								explo_main.set_frame(ex);
								explo_main.setRect(x_explo, y_explo);
								explo_main.showEx(g_screen);

								//update screen
								if (SDL_Flip(g_screen) == -1) return 0;
							}

							// check hp
							die_num += DAME_OF_BOSS;
							if (die_num >= LIFE) {
								if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
									//free memory
									SDL_Quit();
									return 1;
								}
							}
							else {
								for (int i = 0; i < DAME_OF_BOSS; i++) hp.decreaseHP();
								hp.render(g_screen);
								if (SDL_Flip(g_screen) == -1) {
									//free memory
									SDL_Quit();
									return 1;
								}
								// delete threat_amo when it collision main
								//listSub[i]->Reset(listSub[i]->getRect().x);
								listSub[i]->ResetAmo(p_amo);
								
							}//===============HP==================
						}
					}
				}

			// Xu ly amo cua Main vs subBoss:
				vector<AmoObject*> amo_list = pMain->getAmoList();
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
							pMain->removeAmo(im);
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