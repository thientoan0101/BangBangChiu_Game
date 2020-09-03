#include "TextObject.h"

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
