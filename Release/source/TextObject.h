#pragma once
#include"BaseObject.h"
#include<string>
#include<SDL_ttf.h>

using namespace std;

//static TTF_Font* g_font_text = NULL;
extern TTF_Font* g_font_text;


/*Class show font to screen*/
class TextObject : public BaseObject
{
private:
	string str_val_;
	SDL_Color text_color_;
public:
	enum TEXTCOLOR {
		RED_COLOR,
		BLUE_COLOR,
		WHITE_COLOR,
	};
	void setText(const string& text) { str_val_ = text; }
	void setColor(const int& type);
	void CreateGameText(TTF_Font* font, SDL_Surface* des);
	static int InitFont();

};