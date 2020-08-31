#include "TextObject.h"

void TextObject::setColor(const int& type)
{
	if (type == RED_TEXT) {
		SDL_Color color = { 255, 0, 0 };
		text_color = color;
	}
	else if (type == WHITE_TEXT) {
		SDL_Color color = { 255,255,255 };
		text_color = color;
	}
	else if (type == BLUE_TEXT) {
		SDL_Color color = { 5, 72, 255 };
		text_color = color;
	}
	else {
		SDL_Color color = { 0, 0, 0 };
		text_color = color;
	}
}

void TextObject::CreateGameText(TTF_Font* font, SDL_Surface* des) {
	p_object_ = TTF_RenderText_Solid(font, _strVal.c_str(), text_color);
	showObject(des); // thu nghiem. Nguyen mau phai la Show(des)
}

TextObject::TextObject() {
	rect_.x = 500;
	rect_.y = 500;
	text_color.r = 255;
	text_color.g = 255;
	text_color.b = 255;
}