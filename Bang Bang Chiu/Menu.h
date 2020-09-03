#pragma once
#include"TextObject.h"
#include"CommonFunction.h"
#include<iostream>

using namespace std;

//Main Menu
static SDL_Surface* g_img_menu = NULL;
const string local_img_bk = "menubk.png";
const int FIRST_COLOR = TextObject::RED_COLOR;
const int SECOND_COLOR = TextObject::BLUE_COLOR;
const int totalItem = 2;

class Menu
{
public:
	static int showMenu(SDL_Surface* des, TTF_Font* font);
	static bool CheckFocusWithRect(const int& x, const int& y, SDL_Rect& rect);
};

