#include "PowerObject.h"

PowerObject::PowerObject() {
	y_val_ = 0;
	x_val_ = 5;																// Tốc độ di chuyển theo chiều ngang mặc định là 5
	rect_.x = rect_.y = 0;
	is_move_ = true;
	type_ = POWER;
}

PowerObject::~PowerObject() {
	// do something here
}

void PowerObject::handleInputAction(SDL_Event events) {
	// Do something here
}

void PowerObject::handleMoveRightToLeft() {
	if (is_move_) {
		if (rect_.x < -WIDTH_POWER)
			is_move_ = false;
		rect_.x -= x_val_;
	}
}

GiftObject* PowerObject::create() {
	GiftObject* newGift = new PowerObject();
	bool ret = newGift->loadImgObject("gift.png");
	if (!ret) exit(EXIT_FAILURE);
	newGift->setIsMove(true);
	newGift->setWidthHeight(WIDTH_POWER, HEIGHT_POWER);
	newGift->setType(POWER);
	return newGift;
}

int PowerObject::type() {
	return POWER;
}

void PowerObject::move(const int& x_limit, const int& y_limit) {
	this->showObject(g_screen);
}

void PowerObject::moveRightToLeft(const int& x_limit, const int& y_limit) {
	this->showObject(g_screen);
	this->handleMoveRightToLeft();
}