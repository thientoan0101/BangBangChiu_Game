#pragma once

#include "CommonFunction.h"


class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	void showObject(SDL_Surface* des);										// Show image object ra screen					
	bool loadImgObject(const char* file_name);								// Load anh cua Object.

	void setRect(const int &x, const int &y) { rect_.x = x; rect_.y = y;}	// Cai toa do (x,y)
	SDL_Rect getRect() const { return rect_; }
	SDL_Surface* getObject() { return p_object_; }


protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;

};