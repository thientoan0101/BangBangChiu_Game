#include "Menu.h"


int Menu::showMenu(SDL_Surface* des, TTF_Font* font) {
	g_img_menu = SDLCommonFunc::loadImage(local_img_bk);
	if (g_img_menu == NULL) {
		cout << "\n==============Khong the load anh Menu. Kiem tra lai ten file va duong dan==============\n";
		return 0;
	}

	//const int kMenuItemNum = 2;
	int xMouse = 0;
	int yMouse = 0;

	//pos_arr luu giu vi tri
	SDL_Rect pos_arr[totalItem];

	pos_arr[0].x = 200;
	pos_arr[0].y = 300;

	pos_arr[1].x = 200;
	pos_arr[1].y = 400;

	//text_menu luu giu string de hien thi text

	TextObject text_menu[totalItem];
	text_menu[0].setColor(FIRST_COLOR);       //Set mau
	text_menu[0].setText("Play game");                  //Set text
	text_menu[0].setRect(pos_arr[0].x, pos_arr[0].y);   //Set vi tri

	text_menu[1].setColor(FIRST_COLOR);
	text_menu[1].setText("Exit");
	text_menu[1].setRect(pos_arr[1].x, pos_arr[1].y);



	bool selected[totalItem] = { 0,0 };
	SDL_Event m_event;
	while (true)
	{
		//Show man hinh menu
		SDLCommonFunc::applySurface(g_img_menu, des, 0, 0);
		//Hien thi text menu
		for (int i = 0; i < totalItem; i++) {
			text_menu[i].CreateGameText(font, des);
		}

		//Bat su kien
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
			{
				//Thoat khoi chuong trinh
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