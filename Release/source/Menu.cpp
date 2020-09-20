#include "Menu.h"


//static SDL_Surface* g_img_menu = NULL;
SDL_Surface* g_img_menu = NULL;
const string local_img_bk = "./image/menubk2.png";
const int FIRST_COLOR = TextObject::RED_COLOR;
const int SECOND_COLOR = TextObject::BLUE_COLOR;
const int totalItem = 4;
const int totalItemOption = 5;
//static TTF_Font* g_font_Menu = NULL;
TTF_Font* g_font_Menu = NULL;
const int font_size = 40;
const string font_local = "./font/menu.ttf";

const int x_menu_pixel = 520;
const int y_menu_pixel = 200;

const int x_level_pixel = 535;
const int y_level_pixel = 170;

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

	pos_arr[1].x = x_menu_pixel + 15;
	pos_arr[1].y = y_menu_pixel + font_size + 3 ;

	pos_arr[2].x = x_menu_pixel + 30;
	pos_arr[2].y = pos_arr[1].y + font_size + 3;

	pos_arr[3].x = x_menu_pixel + 45;
	pos_arr[3].y = pos_arr[2].y + font_size + 3;

	//text_menu luu giu string de hien thi text

	TextObject text_menu[totalItem];
	text_menu[0].setColor(FIRST_COLOR);       //Set mau
	text_menu[0].setText("New Game");                  //Set text
	text_menu[0].setRect(pos_arr[0].x, pos_arr[0].y);   //Set vi tri

	text_menu[1].setColor(FIRST_COLOR);       //Set mau
	text_menu[1].setText("Resume");                  //Set text
	text_menu[1].setRect(pos_arr[1].x, pos_arr[1].y);   //Set vi tri

	text_menu[2].setColor(FIRST_COLOR);       //Set mau
	text_menu[2].setText("Guide");                  //Set text
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

	pos_arr[0].x = x_level_pixel;
	pos_arr[0].y = y_level_pixel;

	pos_arr[1].x = x_level_pixel;
	pos_arr[1].y = y_level_pixel + font_size + 3;

	pos_arr[2].x = x_level_pixel;
	pos_arr[2].y = pos_arr[1].y + font_size + 3;

	pos_arr[3].x = x_level_pixel;
	pos_arr[3].y = pos_arr[2].y + font_size + 3;

	pos_arr[4].x = x_level_pixel + 22;
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

int Menu::showGuide(SDL_Surface* des) {
	int x_value = 200;
	int y_value = 10;
	const int totalItemGuide = 11;
	int xMouse = 0;
	int yMouse = 0;
	TextObject::InitFont();
	SDL_Surface* img_guide;
	img_guide = SDLCommonFunc::loadImage("./image/guide.png");
	if (img_guide == NULL) {
		cout << "\n==============Khong the load anh Menu. Kiem tra lai ten file va duong dan==============\n";
		return 0;
	}

	TextObject guide[totalItemGuide];
	guide[0].setText("Sub Boss: 100 point | Boss: 100 points | Super Boss: 1000 points");
	guide[0].setColor(TextObject::RED_COLOR);
	guide[0].setRect(x_value + 110, y_value);

	guide[1].setText("Restore full HP");
	guide[1].setColor(TextObject::RED_COLOR);
	guide[1].setRect(x_value + 110, y_value + 50);

	guide[2].setText("Increase one SupperSkill. You only have maximum 3 SupperSkill");
	guide[2].setColor(TextObject::RED_COLOR);
	guide[2].setRect(x_value + 110, y_value + 100);

	guide[3].setText("300 dame point and through any boss");
	guide[3].setColor(TextObject::RED_COLOR);
	guide[3].setRect(x_value + 110, y_value + 190);

	guide[4].setText("You are become Superman, the bullet increase dame point. Lasted for 13s");
	guide[4].setColor(TextObject::RED_COLOR);
	guide[4].setRect(x_value + 110, y_value + 145);

	guide[5].setText("Pause Game");
	guide[5].setColor(TextObject::RED_COLOR);
	guide[5].setRect(x_value + 110, y_value + 250);

	guide[6].setText("Save game");
	guide[6].setColor(TextObject::RED_COLOR);
	guide[6].setRect(x_value + 110, y_value + 297);

	guide[7].setText("Supper Skill");
	guide[7].setColor(TextObject::RED_COLOR);
	guide[7].setRect(x_value + 110, y_value + 340);

	guide[8].setText("Move:");
	guide[8].setColor(TextObject::RED_COLOR);
	guide[8].setRect(x_value + 570, y_value + 250);

	guide[9].setText("Shoot:");
	guide[9].setColor(TextObject::RED_COLOR);
	guide[9].setRect(x_value + 570, y_value + 330);

	guide[10].setText("BACK");
	guide[10].setColor(TextObject::RED_COLOR);
	guide[10].setRect(x_value - 190, y_value);

	bool selected[totalItemGuide] = { 0,0 };
	SDL_Event m_event;
	SDL_Surface* icon_subboss;
	SDL_Surface* icon_heart;
	SDL_Surface* icon_gift;
	SDL_Surface* icon_superSkill;
	SDL_Surface* icon_superman;
	SDL_Surface* icon_phim;
	SDL_Surface* icon_space;
	SDL_Surface* icon_s;
	SDL_Surface* icon_esc;
	SDL_Surface* icon_e;
	icon_subboss = SDLCommonFunc::loadImage("./image/subboss_icon.png");
	icon_heart = SDLCommonFunc::loadImage("./image/HPgift_icon.png");
	icon_gift = SDLCommonFunc::loadImage("./image/gift_icon.png");
	icon_superSkill = SDLCommonFunc::loadImage("./image/rocket_icon.png");
	icon_superman = SDLCommonFunc::loadImage("./image/giftupmain_icon.png");
	icon_phim = SDLCommonFunc::loadImage("./image/phim.png");
	icon_space = SDLCommonFunc::loadImage("./image/space.png");
	icon_s = SDLCommonFunc::loadImage("./image/button_s_icon.png");
	icon_esc = SDLCommonFunc::loadImage("./image/button_esc_icon.png");
	icon_e = SDLCommonFunc::loadImage("./image/button_e_icon.png");
	while (true)
	{
		//Show man hinh menu
		SDLCommonFunc::applySurface(img_guide, des, 0, 0);
		//Hien thi text menu
		for (int i = 0; i < totalItemGuide; i++) {
			guide[i].CreateGameText(g_font_text, des);
		}
		//340
		//Show icon
		SDLCommonFunc::applySurface(icon_subboss, des, x_value - 20, y_value);
		SDLCommonFunc::applySurface(icon_heart, des, x_value, y_value + 50);
		SDLCommonFunc::applySurface(icon_gift, des, x_value, y_value + 100);
		SDLCommonFunc::applySurface(icon_superman, des, x_value, y_value + 140);
		SDLCommonFunc::applySurface(icon_superSkill, des, x_value, y_value + 180);
		SDLCommonFunc::applySurface(icon_phim, des, x_value + 750, y_value + 230);
		SDLCommonFunc::applySurface(icon_space, des, x_value + 650, y_value + 310);
		SDLCommonFunc::applySurface(icon_s, des, x_value + 250, y_value + 290);
		SDLCommonFunc::applySurface(icon_esc, des, x_value + 250, y_value + 240);
		SDLCommonFunc::applySurface(icon_e, des, x_value + 250, y_value + 340);



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
				return 0; // return totalItem vi EXIT luon o cuoi menu
			}
			case SDL_MOUSEMOTION:
			{
				//Lay toa do con chuot
				xMouse = m_event.motion.x;
				yMouse = m_event.motion.y;

				SDL_Rect rectmenu = guide[totalItemGuide - 1].getRect();
				if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
					if (selected[totalItemGuide - 1] == false) {
						selected[totalItemGuide - 1] = 1;
						guide[totalItemGuide - 1].setColor(SECOND_COLOR);
					}
				}
				else {
					if (selected[totalItemGuide - 1] == true) {
						selected[totalItemGuide - 1] = 0;
						guide[totalItemGuide - 1].setColor(FIRST_COLOR);
					}
				}

				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				xMouse = m_event.button.x;
				yMouse = m_event.button.y;
				SDL_Rect rectmenu = guide[totalItemGuide - 1].getRect();
				if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
					return totalItemGuide - 1;
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				if (m_event.key.keysym.sym == SDLK_ESCAPE) return totalItemGuide - 1;
				break;
			}
			default:
				break;
			}
			SDL_Flip(des);
		}
	}
}

int Menu::showAuthor(SDL_Surface* des) {
	Mix_PlayChannel(-1, g_music, 0);
	int xMouse = 0;
	int yMouse = 0;
	/*TTF_Font* author_font = NULL;
	author_font = TTF_OpenFont("calibri.ttf", 20);
	if (author_font == NULL) {
		cout << "\n=================Loi font Menu=================\n";
		return 0;
	}*/
	TextObject::InitFont();

	SDL_Surface* img_author;
	img_author = SDLCommonFunc::loadImage("./image/author.jpg");
	if (img_author == NULL) {
		cout << "\n==============Khong the load anh Menu. Kiem tra lai ten file va duong dan==============\n";
		return 0;
	}

	TextObject author;
	author.setColor(TextObject::RED_COLOR);
	author.setText("LET'S GO");
	author.setRect(550, 480);
	bool selected = { 0, };
	SDL_Event m_event;
	while (true)
	{
		//Show man hinh menu
		SDLCommonFunc::applySurface(img_author, des, 0, 0);

		author.CreateGameText(g_font_text, des);

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
				return -1; // return totalItem vi EXIT luon o cuoi menu
			}
			case SDL_MOUSEMOTION:
			{
				//Lay toa do con chuot
				xMouse = m_event.motion.x;
				yMouse = m_event.motion.y;

					SDL_Rect rectmenu = author.getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						if (selected == false) {
							selected = 1;
							author.setColor(SECOND_COLOR);
						}
					}
					else {
						if (selected == true) {
							selected = 0;
							author.setColor(FIRST_COLOR);
						}
					}
				}

				break;
			
			case SDL_MOUSEBUTTONDOWN:
			{
				xMouse = m_event.button.x;
				yMouse = m_event.button.y;
					SDL_Rect rectmenu = author.getRect();
					if (CheckFocusWithRect(xMouse, yMouse, rectmenu)) {
						return 0;
					}
				}
				break;
			
			case SDL_KEYDOWN:
			{
				if (m_event.key.keysym.sym == SDLK_ESCAPE) return - 1;
				break;
			}
			default:
				break;
			}
			SDL_Flip(des);
		}


	}
}