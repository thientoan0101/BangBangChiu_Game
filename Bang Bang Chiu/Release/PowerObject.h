#pragma once

#ifndef BULLET_H_
#define BULLET_H_

#include "GiftObject.h"

#define WIDTH_POWER 64
#define HEIGHT_POWER 64

class PowerObject :public GiftObject {
public:
	PowerObject();
	~PowerObject();

	virtual void handleInputAction(SDL_Event events);												// Xử lý các sự kiện (chưa cài đặt)
	virtual void handleMoveRightToLeft();
	virtual int type();
	virtual GiftObject* create();

	void move(const int& x_limit, const int& y_limit);
	void moveRightToLeft(const int& x_limit, const int& y_limit);
};

#endif