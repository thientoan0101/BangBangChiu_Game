#include "CommonFunction.h"
#include"TextObject.h"

void SDLCommonFunc::applySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)			// Load image vao screen.
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::applySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, clip, des, &offset);
}

void SDLCommonFunc::cleanUp()									// Giai phong cac doi tuong bien Global
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}


SDL_Surface* SDLCommonFunc::loadImage(string file)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	load_image = IMG_Load(file.c_str());

	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);

		if (optimize_image != NULL)
		{
			//UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);	// ma mau xanh lam: 0,255,255
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0x00, 0x00);	// ma mau xanh lam: 0,255,255
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}
	}

	return optimize_image;
}


bool SDLCommonFunc::checkCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
	int left_a = object1.x;
	int right_a = object1.x + object1.w;
	int top_a = object1.y;
	int bottom_a = object1.y + object1.h;

	int left_b = object2.x;
	int right_b = object2.x + object2.w;
	int top_b = object2.y;
	int bottom_b = object2.y + object2.h;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}

//Ham check vi tri duoc chon o menu
bool SDLCommonFunc::CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect) {
	if (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.w) {
		return true;
	}

	return false;
}

int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font) {
	g_img_menu = SDLCommonFunc::loadImage("galaxybk.png");
	if (g_img_menu == NULL) {
		return outmenu;
	}

	const int kMenuItemNum = 3;
	SDL_Rect pos_arr[kMenuItemNum];
	pos_arr[0].x = 200;
	pos_arr[0].y = 300;
	pos_arr[1].x = 200;
	pos_arr[1].y = 400;
	pos_arr[2].x = 200;
	pos_arr[2].y = 500;

	TextObject text_menu[kMenuItemNum];

	text_menu[0].setText("Play Game");
	text_menu[0].setColor(TextObject::BLUE_TEXT);
	text_menu[0].setRect(pos_arr[0].x, pos_arr[0].y);

	text_menu[1].setText("Setting");
	text_menu[1].setColor(TextObject::BLUE_TEXT);
	text_menu[1].setRect(pos_arr[1].x, pos_arr[1].y);

	text_menu[2].setText("Exit");
	text_menu[2].setColor(TextObject::BLUE_TEXT);
	text_menu[2].setRect(pos_arr[2].x, pos_arr[2].y);

	bool selected[kMenuItemNum] = { 0,0 };
	int xm = 0;
	int ym = 0;
	SDL_Event m_event;
	while (true)
	{
		SDLCommonFunc::applySurface(g_img_menu, des, 0, 0);
		for (int i = 0; i < kMenuItemNum; i++) {
			text_menu[i].CreateGameText(font, des);
		}

		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				return outmenu;
				break;
			case SDL_MOUSEMOTION:
			{
				xm = m_event.motion.x;
				ym = m_event.motion.y;

				for (int i = 0; i < kMenuItemNum; i++) {
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect())) {
						if (selected[i] == false) {
							selected[i] = 1;
							text_menu[i].setColor(TextObject::WHITE_TEXT);
						}
					}
					else {
						if (selected[i] == true) {
							selected[i] = 0;
							text_menu[i].setColor(TextObject::BLUE_TEXT);
						}
					}
				}

				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = m_event.button.x;
				ym = m_event.button.y;

				for (int i = 0; i < kMenuItemNum; i++) {
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect())) {
						return i;
					}
				}

				break;
			}
			case SDL_KEYDOWN: {
				if (m_event.key.keysym.sym == SDLK_ESCAPE) {
					return outmenu;
				}
				break;
			}
			default:
				break;
			}
		}
		SDL_Flip(des);
	}

	return outmenu;
}