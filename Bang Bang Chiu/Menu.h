#pragma once
#include"TextObject.h"
#include"CommonFunction.h"
#include<iostream>

using namespace std;

//Main Menu
static SDL_Surface* g_img_menu = NULL;
const string local_img_bk = "menubk.jpg";
const int FIRST_COLOR = TextObject::RED_COLOR;
const int SECOND_COLOR = TextObject::BLUE_COLOR;
const int totalItem = 4;
const int totalItemOption = 5;
static TTF_Font* g_font_Menu = NULL;
const int font_size = 40;
const string font_local = "menu.ttf";

const int x_menu_pixel = 120;
const int y_menu_pixel = 90;

class Menu
{
public:
	static int showMenu(SDL_Surface* des);
	static bool CheckFocusWithRect(const int& x, const int& y, SDL_Rect& rect);
	static int showMenuOption(SDL_Surface* des);
};

