#pragma once

#ifndef BULLET_H_
#define BULLET_H_

#include "GiftObject.h"

#define WIDTH_POWER 64														// Kích thước vật phẩm
#define HEIGHT_POWER 64

class PowerObject :public GiftObject {
public:
	PowerObject();
	~PowerObject();

	virtual void handleInputAction(SDL_Event events);						// Xử lý các sự kiện (chưa cài đặt)
	virtual void handleMoveRightToLeft();									// Di chuyển từ phải sang trái	
	virtual int type();														// Trả về kiểu của vật phẩm
	virtual GiftObject* create();											// Tạo vật phẩm

	void move(const int& x_limit, const int& y_limit);						// Di chuyển, có in ra màn hình
	void moveRightToLeft(const int& x_limit, const int& y_limit);			// Di chuyển như trên nhưng theo chiều từ phải sang trái
};

#endif