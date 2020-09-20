#include "TextObject.h"


TTF_Font* g_font_text = NULL;




void TextObject::setColor(const int& type) {
	if (type == RED_COLOR) {
		SDL_Color temp = { 255,0,0 };
		text_color_ = temp;
	}
	else if (type == WHITE_COLOR) {
		SDL_Color temp = { 255,255,255 };
		text_color_ = temp;
	}
	else if (type == BLUE_COLOR) {
		SDL_Color temp = { 0,0,255 };
		text_color_ = temp;
	}
	else {
		SDL_Color temp = { 0,0,0 };
		text_color_ = temp;
	}
}
void TextObject::CreateGameText(TTF_Font* font, SDL_Surface* des) {
	p_object_ = TTF_RenderText_Solid(font, str_val_.c_str(), text_color_);
	showObject(des);
}

int TextObject::InitFont() {
	//==================Font==================
	if (TTF_Init() == -1) {
		cout << "\n=================Khong the Init Font=================\n";
		return false;
	}
	//Import font to Programming
	g_font_text = TTF_OpenFont("./font/BalsamiqSans-Regular.ttf", 20);
	if (g_font_text == NULL) {
		cout << "\n=================Loi font=================\n";
		return false;
	}
}
