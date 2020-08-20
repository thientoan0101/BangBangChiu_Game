#include "AmoObject.h"

AmoObject::AmoObject() {
	y_val_ = 0;
	x_val_ = 5;																// Tốc độ di chuyển theo chiều ngang mặc định là 5
	rect_.x = rect_.y = 0;
	is_move_ = false;
	amo_type_ = AmoType::NONE;
}

AmoObject::~AmoObject() {
	// Do something here
}

void AmoObject::handleMove(const int& x_border, const int& y_border) {
	if (is_move_) {
		if (rect_.x > x_border + WIDTH_BULLET)
			is_move_ = false;
		rect_.x += x_val_;
	}
}

void AmoObject::handleInputAction(SDL_Event events) {
	// Do something here
}

void AmoObject::handleMoveRightToLeft() {
	if (is_move_) {
		if (rect_.x < -WIDTH_BULLET)
			is_move_ = false;
		rect_.x -= x_val_;
	}
}