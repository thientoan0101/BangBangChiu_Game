#include "Menu.h"


//static SDL_Surface* g_img_menu = NULL;
SDL_Surface* g_img_menu = NULL;
const string local_img_bk = "menubk.jpg";
const int FIRST_COLOR = TextObject::RED_COLOR;
const int SECOND_COLOR = TextObject::BLUE_COLOR;
const int totalItem = 4;
const int totalItemOption = 5;
//static TTF_Font* g_font_Menu = NULL;
TTF_Font* g_font_Menu = NULL;
const int font_size = 40;
const string font_local = "menu.ttf";

const int x_menu_pixel = 120;
const int y_menu_pixel = 90;

int Menu::showMenu(SDL_Surface* des) {

	g_font_Menu = TTF_OpenFont(font_local.c_str(), font_size);
	if (g_font_Menu == NULL) {
		cout << "\n=================Loi font Menu=================\n";
		return 0;
	}

	g_img_menu = SDLCommonFunc::loadImage(local_img_bk);
	if (g_img_menu == NULL) {
		cout << "\n==============Khong the load anh Menu. Kiem tra lai ten file va duong dan==============\n";
		return 0;
	}



	Mix_PlayChannel(-1, g_music, 0);						// phat nhac nen:    Toan them 5/9 23h39'


	//const int kMenuItemNum = 2;
	int xMouse = 0;
	int yMouse = 0;

	//pos_arr luu giu vi tri
	SDL_Rect pos_arr[totalItem];

	pos_arr[0].x = x_menu_pixel;
	pos_arr[0].y = y_menu_pixel;

	pos_arr[1].x = x_menu_pixel;
	pos_arr[1].y = y_menu_pixel + font_size + 3 ;

	pos_arr[2].x = x_menu_pixel;
	pos_arr[2].y = pos_arr[1].y + font_size + 3;

	pos_arr[3].x = x_menu_pixel;
	pos_arr[3].y = pos_arr[2].y + font_size + 3;

	//text_menu luu giu string de hien thi text

	TextObject text_menu[totalItem];
	text_menu[0].setColor(FIRST_COLOR);       //Set mau
	text_menu[0].setText("Play Game");                  //Set text
	text_menu[0].setRect(pos_arr[0].x, pos_arr[0].y);   //Set vi tri

	text_menu[1].setColor(FIRST_COLOR);       //Set mau
	text_menu[1].setText("Load Game");                  //Set text
	text_menu[1].setRect(pos_arr[1].x, pos_arr[1].y);   //Set vi tri

	text_menu[2].setColor(FIRST_COLOR);       //Set mau
	text_menu[2].setText("Option");                  //Set text
	text_menu[2].setRect(pos_arr[2].x, pos_arr[2].y);   //Set vi tri

	text_menu[3].setColor(FIRST_COLOR);
	text_menu[3].setText("Exit");
	text_menu[3].setRect(pos_arr[3].x, pos_arr[3].y);



	bool selected[totalItem] = { 0,0 };
	SDL_Event m_event;
	while (true)
	{
		//Show man hinh menu
		SDLCommonFunc::applySurface(g_img_menu, des, 0, 0);
		//Hien thi text menu
		for (int i = 0; i < totalItem; i++) {
			text_menu[i].CreateGameText(g_font_Menu, des);
		}

		//Bat su kien
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
			{
				//Thoat khoi chuong trinh
				if (Mix_PlayingMusic())											// dung phat soundtrack
				{
					Mix_HaltMusic();
				}
				return totalItem - 1; // return totalItem vi EXIT luon o cuoi menu
			}
			case SDL_MOUSEMOTION:
			{
				//Lay toa do con chuot
				xMouse = m_event.motion.x;
				yMouse = m_event.motion.y;

				for (int i = 0; i < totalItem; i++) {
					SDL_Rect rectmenu = text_menu[i].getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						if (selected[i] == false) {
							selected[i] = 1;
							text_menu[i].setColor(SECOND_COLOR);
						}
					}
					else {
						if (selected[i] == true) {
							selected[i] = 0;
							text_menu[i].setColor(FIRST_COLOR);
						}
					}
				}

				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				xMouse = m_event.button.x;
				yMouse = m_event.button.y;
				for (int i = 0; i < totalItem; i++) {
					SDL_Rect rectmenu = text_menu[i].getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						return i;
					}
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				if (m_event.key.keysym.sym == SDLK_ESCAPE) return totalItem - 1;
				break;
			}
			default:
				break;
			}
			SDL_Flip(des);
		}


	}

	return 0;
}


bool Menu::CheckFocusWithRect(const int& x, const int& y, SDL_Rect& rect) {
	if (x >= rect.x && x <= rect.x + rect.w &&
		y >= rect.y && y <= rect.y + rect.h) {
		return true;
	}
	return false;
}

int Menu::showMenuOption(SDL_Surface* des) {

	g_font_Menu = TTF_OpenFont(font_local.c_str(), font_size);
	if (g_font_Menu == NULL) {
		cout << "\n=================Loi font Menu=================\n";
		return 0;
	}

	g_img_menu = SDLCommonFunc::loadImage(local_img_bk);
	if (g_img_menu == NULL) {
		cout << "\n==============Khong the load anh Menu. Kiem tra lai ten file va duong dan==============\n";
		return 0;
	}

	//const int kMenuItemNum = 2;
	int xMouse = 0;
	int yMouse = 0;

	//pos_arr luu giu vi tri
	SDL_Rect pos_arr[totalItemOption];

	pos_arr[0].x = x_menu_pixel;
	pos_arr[0].y = y_menu_pixel;

	pos_arr[1].x = x_menu_pixel;
	pos_arr[1].y = y_menu_pixel + font_size + 3;

	pos_arr[2].x = x_menu_pixel;
	pos_arr[2].y = pos_arr[1].y + font_size + 3;

	pos_arr[3].x = x_menu_pixel;
	pos_arr[3].y = pos_arr[2].y + font_size + 3;

	pos_arr[4].x = x_menu_pixel;
	pos_arr[4].y = pos_arr[3].y + font_size + 3;

	//text_menu luu giu string de hien thi text

	TextObject text_menu[totalItemOption];
	text_menu[0].setColor(FIRST_COLOR);       //Set mau
	text_menu[0].setText("Level 1");                  //Set text
	text_menu[0].setRect(pos_arr[0].x, pos_arr[0].y);   //Set vi tri

	text_menu[1].setColor(FIRST_COLOR);       //Set mau
	text_menu[1].setText("Level 2");                  //Set text
	text_menu[1].setRect(pos_arr[1].x, pos_arr[1].y);   //Set vi tri

	text_menu[2].setColor(FIRST_COLOR);       //Set mau
	text_menu[2].setText("Level 3");                  //Set text
	text_menu[2].setRect(pos_arr[2].x, pos_arr[2].y);   //Set vi tri

	text_menu[3].setColor(FIRST_COLOR);
	text_menu[3].setText("Level 4");
	text_menu[3].setRect(pos_arr[3].x, pos_arr[3].y);

	text_menu[4].setColor(FIRST_COLOR);
	text_menu[4].setText("Back");
	text_menu[4].setRect(pos_arr[4].x, pos_arr[4].y);


	bool selected[totalItemOption] = { 0,0 };
	SDL_Event m_event;
	while (true)
	{
		//Show man hinh menu
		SDLCommonFunc::applySurface(g_img_menu, des, 0, 0);
		//Hien thi text menu
		for (int i = 0; i < totalItemOption; i++) {
			text_menu[i].CreateGameText(g_font_Menu, des);
		}

		//Bat su kien
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
			{
				//Thoat khoi chuong trinh
				if (Mix_PlayingMusic())											// dung phat soundtrack
				{
					Mix_HaltMusic();
				}
				return totalItemOption - 1; // return totalItem vi EXIT luon o cuoi menu
			}
			case SDL_MOUSEMOTION:
			{
				//Lay toa do con chuot
				xMouse = m_event.motion.x;
				yMouse = m_event.motion.y;

				for (int i = 0; i < totalItemOption; i++) {
					SDL_Rect rectmenu = text_menu[i].getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						if (selected[i] == false) {
							selected[i] = 1;
							text_menu[i].setColor(SECOND_COLOR);
						}
					}
					else {
						if (selected[i] == true) {
							selected[i] = 0;
							text_menu[i].setColor(FIRST_COLOR);
						}
					}
				}

				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				xMouse = m_event.button.x;
				yMouse = m_event.button.y;
				for (int i = 0; i < totalItemOption; i++) {
					SDL_Rect rectmenu = text_menu[i].getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						return i;
					}
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				if (m_event.key.keysym.sym == SDLK_ESCAPE) return totalItemOption - 1;
				break;
			}
			default:
				break;
			}
			SDL_Flip(des);
		}


	}

	return 0;
}