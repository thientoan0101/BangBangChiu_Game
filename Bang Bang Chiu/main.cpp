#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"
#include "ExplosionObject.h"
#include "ThreatsObject.h"
#include "Audio.h"
#include"HPObject.h"
#include"Gift.h"
#include"Random.h"
#include"TextObject.h"
#include"Menu.h"


// toan them:
#include "Control.h"
#include"Background.h"
#include "WinLose.h"
#include <winuser.h>
#undef main

//bool create = false;
//// số lượng rocket
//int num_rocket = 0;
//int num_blood = 0;
//int DAME_OF_MAIN = 1;
//const int LIFE_OF_THREAT = DAME_OF_MAIN * 2; // mau cua threat


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



	//==================Font==================
	if (TTF_Init() == -1) {
		cout << "\nKhong the Init Font\n";
		return false;
	}
	//Import font to Programming
	g_font_text = TTF_OpenFont("BalsamiqSans-Regular.ttf", 20);
	if (g_font_text == NULL) {
		cout << "\n=================Loi font=================\n";
		return false;
	}
	
	AudioFunction::prepareAudioFile();										// khoi tao file audio

	return true;
}


int DisplayResourceNAMessageBox()
{
	int msgboxID = MessageBox(
		NULL,
		"Resource not available\nDo you want to try again?",
		"Account Details",
		MB_ICONQUESTION | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
	);

	switch (msgboxID)
	{
	case IDCANCEL:
		// TODO: add code
		break;
	case IDTRYAGAIN:
		// TODO: add code
		break;
	case IDCONTINUE:
		// TODO: add code
		break;
	}

	return msgboxID;
}

int main(int arc, char* argv[])
{
	

	//int a = DisplayResourceNAMessageBox();





	//int level = 1;
	//cout << "chon level: ";	cin >> level;		// 1->4



	// khởi tạo thời gian thực
	srand(time(NULL));

	//bool activeBoss = false;
	//bool activeSubBoss = false;
	//int bkgn_x = 0;
	//bool is_run_screen = true;
	//bool is_quit = false;
	
	
	
	
	
	
	if (Init() == false)
		return 0;

/*
	g_bkground = SDLCommonFunc::loadImage("galaxybk_7680x600.png");
	if (g_bkground == NULL)
	{
		cout << "ko load background dc" << endl;
		return 0;
	}
	SDLCommonFunc::applySurface(g_bkground, g_screen, 0, 0);*/
//	BackgroundFunc::prepareBackground(level);							//moi comment 5/9




	// create main HP
	//HP hp;
	/*hp.init();
	hp.setRect(X_POS_HP_MAIN , Y_POS_HP_MAIN);*/
//	HpFunc::prepareHpMain();											//moi comment 5/9




	//SDL_Surface * hp_border = SDLCommonFunc::loadImage("HP_border.png");
	//if (hp_border == NULL)
	//{
	//	cout << "ko load background dc" << endl;
	//	return 0;
	//}
//	HpFunc::prepareMainHpBorder();										//moi comment 5/9

	
	/*SDLCommonFunc::applySurface(hp_border, g_screen, X_POS_HP_MAIN, Y_POS_HP_MAIN);*/   //ko co



	// create BOSS HP											
	//HP hp_boss;
	/*hp_boss.init_BOSS();
	hp_boss.setRect(X_POS_HP_BOSS, Y_POS_HP_BOSS + 1);*/
//	HpFunc::prepareHpBoss();												//moi comment 5/9




	//// create THREAT HP
	//HP hp_threat;
	//hp_threat.init_threat();
	//hp_threat.setRect(X_POS_HP_BOSS, Y_POS_HP_BOSS);//++++++++++++++++++++++++++++++
	

	/*SDL_Surface* hp_border_boss = SDLCommonFunc::loadImage("HP_border_boss.png");
	if (hp_border_boss == NULL)
	{
		cout << "ko load background dc" << endl;
		return 0;
	}*/
//	HpFunc::prepareBossHpBorder();												//moi comment 5/9



	// tao MainObject:
	//MainObject mainObject;

	//mainObject.setRect(100, SCREEN_HEIGHT / 2);
	//bool ret = mainObject.loadImgObject("main.png");					//main
	//if (!ret)
	//{
	//	return 0;
	//}

//	MainFunc::prepareMain();														//moi comment 5/9



	

	//// tao nhieu enermy:
	////int numThreats;
	///*vector<ThreatObject*> listThreats;
	//ThreatObject* pBoss = new ThreatObject;*/
	//pBoss = new ThreatObject;



	//createListThreatObjects(listThreats, level, numThreats);
	//createBoss(pBoss, level);

	////vector<ThreatObject*> listSub(2);

	//for (int i = 0; i < listSub.size(); i++)
	//{
	//	listSub[i] = new ThreatObject;
	//	createSubBoss(listSub[i], pBoss);
	//}

//	ThreatFunc::prepareThreats();						// setup threat, boss, subboss.				//moi comment 5/9


	// Init Explosion Object:
	
	//this is for subBoss
	//ExplosionObject exp_subboss;
	/*bool	ret = exp_subboss.loadImgObject("expo_small.png");
	exp_subboss.set_clip_small();
	if (ret == false)	return false;*/

//ExplosionFunc::prepareExpSub();																//moi comment 5/9





	//this for main
	//ExplosionObject explo_main;
	/*bool ret = explo_main.loadImgObject("expo_small.png");
	explo_main.set_clip_small();
	if (!ret) return 0;*/
//	ExplosionFunc::prepareExpMain();															// moi comment 5/9


	//Mix_PlayChannel(-1, g_sound_ready, 0);

	//// biến đếm số lần main trúng đạn
	//unsigned int die_num = 0;
	//unsigned int die_num_boss = 0;

	Menu:
	//Truoc khi choi game => can show menu

	ControlFunc::setup();
	int ret_menu = Menu::showMenu(g_screen);

	if (ret_menu == totalItem - 1) {//Vi trong ham showMenu, quy dinh totalItem la exit
		if (Mix_Playing(-1))																		// dung phat soundtrack
		{
			Mix_HaltChannel(-1);
		}
		//is_quit = true;
		return 0;
	}
	else if (ret_menu == 0) {//Play game
		level = 1; // Khi bam Play Game mac dinh se choi level 1
		if (Mix_Playing(-1))																		// tam dung phat soundtrack
		{	
			Mix_Pause(-1);
		}
	}
	else if (ret_menu == 1) {//Load game
		//todo
		if (Mix_Playing(-1))																		// tam dung phat soundtrack
		{
			Mix_Pause(-1);
		}
	}
	else if (ret_menu == 2) {//Options
		int ret_menu_option = Menu::showMenuOption(g_screen);
		if (ret_menu_option == totalItemOption - 1) {
			goto Menu;
		}
		else if (ret_menu_option == 0) level = 1;
		else if (ret_menu_option == 1) level = 2;
		else if (ret_menu_option == 2) level = 3;
		else if (ret_menu_option == 3) level = 4;
		if (Mix_Playing(-1))																		// tam dung phat soundtrack
		{
			Mix_Paused(-1);
		}
	}

	

	if (ControlFunc::prepareGame() == false)
	{
		ControlFunc::endGame();
		return 0;
	}









	//-----------------------------------------
//	WinLoseFunc::initWinLoseBox();















	
	


	Play:

	int resultGame = ControlFunc::playCampaign();
	int catchMess, msgboxID;
	switch (resultGame)
	{
	case -1:	// lose
		//if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
		//catchMess = ::MessageBox(NULL, "Play Again?", "GAME OVER", MB_YESNOCANCEL);
		msgboxID = MessageBox(NULL,	"Do you want to play again?", "GAMEvv OVER",	MB_ICONQUESTION | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		);

		switch (msgboxID)
		{
		case IDCANCEL:
			ControlFunc::endGame();
			return 0;
			break;
		case IDTRYAGAIN:
			// TODO: add code
			goto Play;
			break;
		case IDCONTINUE:
			// TODO: add code
			goto Menu;
			break;
		
		}
			//free memory
			//SDL_Quit();
			//return 0;
			//goto EndGame;
		cout << "case 1";
		break;
	case 2: // win
		//if (MessageBox(NULL, "", "YOU WIN", MB_OK) == IDOK) {
		catchMess = ::MessageBox(hWnd, "Play Next level?", "YOU WIN", MB_YESNO);
		switch (catchMess)
		{
		case IDYES:
			// play again
			if (level == 4) level = 1;
			else level++;
			goto Play;
		case IDNO:
			goto Menu;
		default:
			ControlFunc::endGame();
			return 0;
			
		}
			
			//free memory
			//SDL_Quit();
			//return 1;
			
		break;
	default:
		ControlFunc::endGame();
		return 0;
		
	}



	// Trong luc play game:
	//
	//while (!is_quit)
	//{
	//	while (SDL_PollEvent(&g_event))
	//	{
	//		if (g_event.type == SDL_QUIT)
	//		{
	//			is_quit = true;
	//			break;
	//		}
	//		mainObject.handleInput(g_event, num_rocket, num_blood, DAME_OF_MAIN);
	//	}





	//	// cap nhat lai background:
	//	if (is_run_screen == true)
	//	{

	//		bkgn_x -= SPEED_BACKGROUND;
	//		if (bkgn_x <= -(WIDTH_LONG_BACKGROUND - SCREEN_WIDTH))
	//		{
	//			is_run_screen = false;
	//			activeBoss = true;			
	//		}
	//		else {
	//			SDLCommonFunc::applySurface(g_bkground, g_screen, bkgn_x, 0);
	//			SDLCommonFunc::applySurface(hp_border, g_screen, X_POS_HP_BORDER_MAIN, Y_POS_HP_BORDER_MAIN);
	//		}
	//	}
	//	else
	//	{
	//		SDLCommonFunc::applySurface(g_bkground, g_screen, bkgn_x, 0);
	//		SDLCommonFunc::applySurface(hp_border, g_screen, X_POS_HP_BORDER_MAIN, Y_POS_HP_BORDER_MAIN);
	//	}

	//	if (is_run_screen == false)
	//	{
	//		destroyThreatObjects(listThreats);
	//	}







	//	// --------------------------- THEM GIFT ---------------------------

	//// Tao Gift rocket
	//	if (create && rand() % 200 == 0) {
	//		gift_rocket->setIsMove(true);
	//		gift_rocket->setType(rand() % 4);
	//		gift_rocket->setRect(rand() % 400 + SCREEN_WIDTH, rand() % (SCREEN_HEIGHT - 200));
	//		create = false;
	//	}
	//	if (gift_rocket->getIsMove()) {
	//		gift_rocket->showObject(g_screen);
	//		gift_rocket->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
	//	}
	//	else
	//		create = true;

	//	// Tao Gift hp
	//	if (create && rand() % 400 == 0) {
	//		gift_hp->setIsMove(true);
	//		gift_hp->setType(rand() % 4);
	//		gift_hp->setRect(rand() % 400 + SCREEN_WIDTH, rand() % (SCREEN_HEIGHT - 200));
	//		create = false;
	//	}
	//	if (gift_hp->getIsMove()) {
	//		gift_hp->showObject(g_screen);
	//		gift_hp->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
	//	}
	//	else create = true;




	//	bool ret;

	//	// hiệu ứng ăn item rocket
	//	if (SDLCommonFunc::checkCollision(mainObject.getRect(), gift_rocket->getRect())) {
	//		//this for main
	//		ExplosionObject main_eat_item;

	//		// ăn item được rocket
	//		num_rocket++;
	//		if (num_rocket > NUM_ROCKET) num_rocket--;
	//		ret = main_eat_item.loadImgObject("eat_item.png");

	//		
	//		main_eat_item.set_clip_eat_item();
	//		if (!ret) return 0;

	//		for (int ex = 0; ex < 4; ex++) {

	//			int x_explo = (mainObject.getRect().x + mainObject.getRect().w * 0.5) - EXP_WIDTH * 0.5;
	//			int y_explo = (mainObject.getRect().y + mainObject.getRect().h * 0.5) - EXP_HEIGHT * 0.5;

	//			//upload explosion
	//			main_eat_item.set_frame(ex);
	//			main_eat_item.setRect(x_explo, y_explo);
	//			main_eat_item.showEx(g_screen);
	//			//update screen
	//			if (SDL_Flip(g_screen) == -1) return 0;
	//		}
	//		gift_rocket->setRect(rand() % GIFT_HP_WIDTH + SCREEN_WIDTH + DELTA_DROP_ROCKET, rand() % (SCREEN_HEIGHT - GIFT_HEIGHT));

	//	}




	//	// hiệu ứng ăn item hp
	//	if (SDLCommonFunc::checkCollision(mainObject.getRect(), gift_hp->getRect())) {
	//		//this for main
	//		ExplosionObject main_eat_item;

	//		// ăn quà hồi máu
	//		die_num = 0;
	//		hp.init();
	//		hp.render(g_screen);
	//		ret = main_eat_item.loadImgObject("exp_main.png");

	//		main_eat_item.set_clip_small();
	//		if (!ret) return 0;

	//		for (int ex = 0; ex < 4; ex++) {

	//			int x_explo = (mainObject.getRect().x + mainObject.getRect().w * 0.5) - EXP_WIDTH * 0.5;
	//			int y_explo = (mainObject.getRect().y + mainObject.getRect().h * 0.5) - EXP_HEIGHT * 0.5;

	//			//upload explosion
	//			main_eat_item.set_frame(ex);
	//			main_eat_item.setRect(x_explo, y_explo);
	//			main_eat_item.showEx(g_screen);

	//			//update screen	
	//			if (SDL_Flip(g_screen) == -1) return 0;
	//		}
	//		gift_hp->setRect(rand() % GIFT_HP_WIDTH + SCREEN_WIDTH + DELTA_DROP_HP, rand() % (SCREEN_HEIGHT - GIFT_HP_HEIGHT));

	//	}


	//	// show hp
	//	hp.render(g_screen);


	//	// Implement main object:
	//	mainObject.handleMove();
	//	mainObject.showObject(g_screen);
	//	mainObject.makeAmo(g_screen);




	//	// nhieu threat:
	//	// có thẻ tao thành ham Move():
	//	for (int i = 0; i < listThreats.size(); i++)
	//	{
	//		
	//		// moi them 

	//		listThreats[i]->Move();


	//		// đạn của threat va chạm main
	//		vector<AmoObject*> amoList1 = listThreats[i]->GetAmoList();
	//		for (int k = 0; k < amoList1.size(); k++) {
	//			AmoObject* p_amo = amoList1.at(k);
	//			if (p_amo) {
	//				bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), mainObject.getRect());
	//				if (ret_col) {
	//					for (int ex = 0; ex < 4; ex++) {

	//						int x_explo = (p_amo->getRect().x);
	//						int y_explo = (p_amo->getRect().y);

	//						//upload explosion
	//						explo_main.set_frame(ex);
	//						explo_main.setRect(x_explo, y_explo);
	//						/*explo_main.showEx(g_screen);*/
	//						explo_main.showUpgrade(g_screen);

	//						//update screen
	//						if (SDL_Flip(g_screen) == -1) return 0;
	//					}

	//					// check hp
	//					die_num += DAME_OF_THREAT;
	//					if (die_num >= LIFE) {
	//						Mix_PlayChannel(-1, g_sound_ex_main, 0);
	//						


	//						WinLoseFunc::initWinLoseBox();





	//						if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
	//							//free memory
	//							SDL_Quit();
	//							return 1;
	//						}
	//					}
	//					else {
	//						for (int i = 0; i < DAME_OF_THREAT; i++) hp.decreaseHP();
	//						hp.render(g_screen);
	//						if (SDL_Flip(g_screen) == -1) {
	//							//free memory
	//							SDL_Quit();
	//							return 1;
	//						}
	//						// delete threat_amo when it collision main
	//						listThreats[i]->ResetAmo(p_amo);
	//					}//===============HP==================
	//				}
	//			}
	//		}
	//		//------------------------------------------------------------------------








	//		// Xu ly main va cham voi subBoss
	//		//check collision
	//		bool isColi = SDLCommonFunc::checkCollision(mainObject.getRect(), listThreats[i]->getRect());
	//		if (isColi) {
	//			/*score_value += 100;*/
	//			for (int ex = 0; ex < NUM_THREAT; ex++) {
	//				//main explosion animation
	//				int x_explo_main = (mainObject.getRect().x + mainObject.getRect().w * 0.5) - EXP_WIDTH * 0.5;
	//				int y_explo_main = (mainObject.getRect().y + mainObject.getRect().h * 0.5) - EXP_HEIGHT * 0.5;
	//				explo_main.set_frame(ex);
	//				explo_main.setRect(x_explo_main, y_explo_main);
	//				explo_main.showEx(g_screen);

	//				//threat explosion animation
	//				int x_explo_threat = (listThreats[i]->getRect().x + listThreats[i]->getRect().w * 0.5) - EXP_WIDTH * 0.5;
	//				int y_explo_threat = (listThreats[i]->getRect().y + listThreats[i]->getRect().h * 0.5) - EXP_HEIGHT * 0.5;

	//				//upload explosion
	//				exp_subboss.set_frame(ex);
	//				exp_subboss.setRect(x_explo_threat, y_explo_threat);
	//				exp_subboss.showEx(g_screen);

	//				//update screen
	//				if (SDL_Flip(g_screen) == -1) return 0;
	//			}

	//			// check hp
	//			die_num += DAME_COLLISION;
	//			if (die_num >= LIFE) {
	//				Mix_PlayChannel(-1, g_sound_ex_main, 0);



	//				WinLoseFunc::initWinLoseBox();







	//				if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
	//					//free memory
	//					SDL_Quit();
	//					return 1;
	//				}
	//			}
	//			else {
	//				for (int i = 0; i < DAME_COLLISION; i++) hp.decreaseHP();
	//				hp.render(g_screen);
	//				if (SDL_Flip(g_screen) == -1) {
	//					//free memory
	//					SDL_Quit();
	//					return 1;
	//				}
	//				listThreats[i]->Reset(SCREEN_WIDTH + i * 100 * 2);
	//			}//=========hp===========
	//		}









	//		//------------------------------------------------------------------------
	//		// Xu ly đạn cua Main vs Threat:
	//		vector<AmoObject*> amo_list = mainObject.getAmoList();
	//		for (int im = 0; im < amo_list.size(); im++)
	//		{
	//			AmoObject* p_amo = amo_list.at(im);
	//			if (p_amo != NULL)
	//			{
	//				bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), listThreats[i]->getRect());
	//				if (ret_col)
	//				{
	//					// Audio:

	//					Mix_PlayChannel(-1, g_sound_injured, 0);

	//					for (int ex = 0; ex < 4; ex++)
	//					{
	//						int x_pos = (p_amo->getRect().x);
	//						int y_pos = (p_amo->getRect().y);

	//						exp_subboss.set_frame(ex);
	//						exp_subboss.setRect(x_pos, y_pos);
	//						exp_subboss.showExSmall(g_screen);

	//						if (SDL_Flip(g_screen) == -1)
	//							return 0;
	//					}
	//												   						 					 
	//					int rng_y = rand() % SCREEN_HEIGHT;
	//					listThreats[i]->Reset(SCREEN_WIDTH + im * rng_y);
	//					if(p_amo->getType() != AmoObject::ROCKET) mainObject.removeAmo(im);
	//				}
	//			}
	//		}
	//	}





	//	// kich hoat boss:
	//	if (activeBoss)
	//	{
	//		pBoss->Move();
	//		pBoss->showObject(g_screen);
	//		pBoss->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
	//		activeSubBoss = true;
	//		SDLCommonFunc::applySurface(hp_border_boss, g_screen, X_POS_HP_BORDER_BOSS, Y_POS_HP_BORDER_BOSS);
	//		hp_boss.render_boss(g_screen);
	//	}







	//	// xu ly Sub Boss:
	//	if (activeSubBoss)
	//	{
	//		for (int i = 0; i < listSub.size(); i++)
	//		{
	//			listSub[i]->HandleMoveSub(pBoss);
	//			listSub[i]->showObject(g_screen);
	//			listSub[i]->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
	//			
	//			//-------------------------------------------------------------------------   draft:
	//			MainObject* pMain = &mainObject;
	//			




	//			//main vs đạn subboss ở cuối trận	   
	//			vector<AmoObject*> amoList2 = listSub[i]->GetAmoList();
	//			for (int k = 0; k < amoList2.size(); k++) {
	//				AmoObject* p_amo = amoList2.at(k);
	//				if (p_amo) {
	//					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), pMain->getRect());
	//					if (ret_col) {
	//						for (int ex = 0; ex < 4; ex++) {

	//							int x_explo = (p_amo->getRect().x);
	//							int y_explo = (p_amo->getRect().y);

	//							//upload explosion
	//							explo_main.set_frame(ex);
	//							explo_main.setRect(x_explo, y_explo);
	//							explo_main.showEx(g_screen);

	//							//update screen
	//							if (SDL_Flip(g_screen) == -1) return 0;
	//						}

	//						// check hp
	//						die_num += DAME_OF_THREAT;
	//						if (die_num >= LIFE) {
	//							Mix_PlayChannel(-1, g_sound_ex_main, 0);



	//							WinLoseFunc::initWinLoseBox();




	//							if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//						}
	//						else {
	//							for (int i = 0; i < DAME_OF_THREAT; i++) hp.decreaseHP();
	//							hp.render(g_screen);
	//							if (SDL_Flip(g_screen) == -1) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//							// delete threat_amo when it collision main
	//							listSub[i]->ResetAmo(p_amo);
	//						}//===============HP==================
	//					}
	//				}
	//			}




	//			//main vs đạn boss ở cuối trận	   
	//			vector<AmoObject*> amoList3 = pBoss->GetAmoList();
	//			for (int k = 0; k < amoList3.size(); k++) {
	//				AmoObject* p_amo = amoList3.at(k);
	//				if (p_amo) {
	//					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), pMain->getRect());
	//					if (ret_col) {
	//						for (int ex = 0; ex < 4; ex++) {

	//							int x_explo = (p_amo->getRect().x);
	//							int y_explo = (p_amo->getRect().y);

	//							//upload explosion
	//							explo_main.set_frame(ex);
	//							explo_main.setRect(x_explo, y_explo);
	//							explo_main.showEx(g_screen);

	//							//update screen
	//							if (SDL_Flip(g_screen) == -1) return 0;
	//						}

	//						// check hp
	//						die_num += DAME_OF_BOSS;
	//						if (die_num >= LIFE) {
	//							Mix_PlayChannel(-1, g_sound_ex_main, 0);



	//							WinLoseFunc::initWinLoseBox();






	//							if (MessageBox(NULL, "", "GAME OVER", MB_OK) == IDOK) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//						}
	//						else {
	//							for (int i = 0; i < DAME_OF_BOSS; i++) hp.decreaseHP();
	//							hp.render(g_screen);
	//							if (SDL_Flip(g_screen) == -1) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//							// delete threat_amo when it collision main
	//							pBoss->ResetAmo(p_amo);
	//						}//===============HP==================
	//					}
	//				}
	//			}




	//		// Xu ly amo cua Main vs subBoss:
	//			vector<AmoObject*> amo_list = pMain->getAmoList();
	//			for (int im = 0; im < amo_list.size(); im++)
	//			{
	//				AmoObject* p_amo = amo_list.at(im);
	//				if (p_amo != NULL)
	//				{
	//					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), listSub[i]->getRect());
	//					if (ret_col)
	//					{
	//						// moi them:

	//						Mix_PlayChannel(-1, g_sound_injured, 0);

	//						for (int ex = 0; ex < 4; ex++)
	//						{
	//							int x_pos = (p_amo->getRect().x);
	//							int y_pos = (p_amo->getRect().y);

	//							exp_subboss.set_frame(ex);
	//							exp_subboss.setRect(x_pos, y_pos);
	//							exp_subboss.showExSmall(g_screen);

	//							if (SDL_Flip(g_screen) == -1)
	//								return 0;
	//						}

	//						SDL_Rect tempRect = pBoss->getRect();
	//						listSub[i]->setRect(tempRect.x - tempRect.w / 5, tempRect.y + tempRect.h / 2);
	//						if (p_amo->getType() != AmoObject::ROCKET) pMain->removeAmo(im);
	//					}
	//				}
	//			}


	//			// Xu ly amo cua Main vs Boss:
	//			vector<AmoObject*> amo_list_2 = pMain->getAmoList();
	//			for (int im = 0; im < amo_list_2.size(); im++)
	//			{
	//				AmoObject* p_amo = amo_list_2.at(im);
	//				if (p_amo != NULL)
	//				{
	//					bool ret_col = SDLCommonFunc::checkCollision(p_amo->getRect(), pBoss->getRect());
	//					if (ret_col)
	//					{
	//						// moi them:
	//						die_num_boss += DAME_OF_MAIN;

	//						

	//						for (int ex = 0; ex < 4; ex++)
	//						{
	//							int x_pos = (p_amo->getRect().x);
	//							int y_pos = (p_amo->getRect().y);

	//							exp_subboss.set_frame(ex);
	//							exp_subboss.setRect(x_pos, y_pos);
	//							exp_subboss.showExSmall(g_screen);

	//							if (SDL_Flip(g_screen) == -1)
	//								return 0;
	//						}
	//						if (p_amo->getType() != AmoObject::ROCKET) pMain->removeAmo(im);

	//						if (die_num_boss >= LIFE_BOSS) {
	//							Mix_PlayChannel(-1, g_sound_ex_boss, 0);
	//							if (MessageBox(NULL, "", "YOU WIN", MB_OK) == IDOK) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//						}
	//						else {
	//							for (int i = 0; i < DAME_OF_MAIN; i++) hp_boss.decreaseHP_BOSS();
	//							hp_boss.render_boss(g_screen);
	//							if (SDL_Flip(g_screen) == -1) {
	//								//free memory
	//								SDL_Quit();
	//								return 1;
	//							}
	//							Mix_PlayChannel(-1, g_sound_injured, 0);
	//						}//===============HP==================
	//					}
	//				}
	//			}



	//		}
	//	}


	//	if (SDL_Flip(g_screen) == -1)
	//		return 0;
	//}
	//


	//EndGame:
	//	for (int i = 0; i < listThreats.size(); i++)
	//	{
	//		delete listThreats[i];
	//	}
	//	cout << "test goto" << endl;
	//	for (int i = 0; i < listSub.size(); i++)
	//	{
	//		delete listSub[i];
	//	}
	//	delete pBoss;


	//	Mix_CloseAudio();												// giai phong SDL_mixer	
	//	SDLCommonFunc::cleanUp();	
	//	SDL_Quit();
		return 1;
}