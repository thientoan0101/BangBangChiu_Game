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
#include "Control.h"
#include"Background.h"
#include <winuser.h>
#undef main


int main(int arc, char* argv[])
{

	if (ControlFunc::Init() == false)		return 0;
	
	int ret_author = Menu::showAuthor(g_screen);
	if (ret_author == -1) return 0;
	

	Menu:
	//Truoc khi choi game => can show menu

	ControlFunc::setup(level);

	int ret_menu = Menu::showMenu(g_screen);
	if (ret_menu == totalItem - 1) {//Vi trong ham showMenu, quy dinh totalItem la exit
		if (Mix_Playing(-1)) //dung phat soundtrack
		{
			Mix_HaltChannel(-1);
		}
		ControlFunc::endGame();
		return 0;
	}
	else if (ret_menu == 0) {//Play game
		newGame = true;
		if (Mix_Playing(-1))																		// tam dung phat soundtrack
		{
			Mix_Pause(-1);
		}
	}
	else if (ret_menu == 1) {//Load game
		resume = true;
		if (Mix_Playing(-1))																		// tam dung phat soundtrack
		{
			Mix_Pause(-1);
		}
	}
	else if (ret_menu == 2) {//Guide
		int ret_menu_guide = Menu::showGuide(g_screen);
		if (ret_menu_guide == 10) {
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
			score.setScore(0);
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
	case 1:
		goto Menu;

	default:
		ControlFunc::endGame();
		return 0;
	}

	return 1;
}