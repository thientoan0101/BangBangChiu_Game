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
	TextObject::InitFont();
	
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
	int ret_author = Menu::showAuthor(g_screen);
	if (ret_author == -1) {
		return 0;
	}
	

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
		ControlFunc::endGame();
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
	else if (ret_menu == 2) {//Guide
		int ret_menu_guide = Menu::showGuide(g_screen);
		if (ret_menu_guide == 6 - 1) {
			goto Menu;
		}
		else {
			return 0;
		}
	}



	Prepare:

	if (ControlFunc::prepareGame() == false)
	{
		ControlFunc::endGame();
		return 0;
	}


	Play:

	int resultGame = ControlFunc::playCampaign();
	int catchMess, msgboxID;
 	switch (resultGame)
	{
	case -1:
		msgboxID = MessageBox(NULL, "Do you want to play again?", "GAME OVER", MB_ICONQUESTION | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);

		switch (msgboxID)
		{
		case IDCANCEL:
			ControlFunc::endGame();
			return 0;
			break;
		case IDTRYAGAIN:
			ControlFunc::setup(level);
			goto Prepare;

			break;
		case IDCONTINUE:
			goto Menu;
			break;
		}
		break;
	case 2: // win

		catchMess = ::MessageBox(hWnd, "Play Next level?", "YOU WIN", MB_YESNO);
		switch (catchMess)
		{
		case IDYES:
			if (level == 4) level = 1;
			else level++;
			ControlFunc::setup(level);
			goto Prepare;
		case IDNO:
			goto Menu;
		default:
			ControlFunc::endGame();
			return 0;
		}
		break;
	default:
		ControlFunc::endGame();
		return 0;
	}
	
	
	return 1;
}