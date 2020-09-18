#pragma once
#include"TextObject.h"
#include"CommonFunction.h"
#include "Audio.h"
#include<iostream>

using namespace std;

//Main Menu
extern SDL_Surface* g_img_menu; 
extern const string local_img_bk;
extern const int FIRST_COLOR;
extern const int SECOND_COLOR;
extern const int totalItem; 
extern const int totalItemOption;
extern TTF_Font* g_font_Menu;
extern const int font_size;
extern const string font_local;

extern const int x_menu_pixel;
extern const int y_menu_pixel;

class Menu
{
public:
	static int showMenu(SDL_Surface* des);
	static bool CheckFocusWithRect(const int& x, const int& y, SDL_Rect& rect);
	static int showMenuOption(SDL_Surface* des);
	static int showGuide(SDL_Surface* des);
	static int showAuthor(SDL_Surface* des);
};

