#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include"BaseObject.h"
#include<string>
#include<SDL_ttf.h>

using namespace std;
class TextObject : public BaseObject
{
public:
	enum TextColor {
		BLUE_TEXT = 0,
		WHITE_TEXT = 1,
		RED_TEXT = 2,
	};

private:
	string _strVal;
	SDL_Color text_color;
public:
	TextObject();
	void setText(string text) { _strVal = text; }
	void setColor(const int& type);
	void CreateGameText(TTF_Font* font, SDL_Surface* des);
};


#endif

