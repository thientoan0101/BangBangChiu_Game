#include "Gift.h"

Gift* gift_rocket;
Gift* gift_hp;


bool create = false;

int num_rocket = 0;					// số lượng rocket
int num_blood = 0;					// số lượng hồi máu



Gift::Gift() {
	rect_.x = rect_.y = 0;												// Tọa độ xuất hiện mặc định là gốc tọa độ
	x_val_ = y_val_ = 0;												// Tốc độ di chuyển mặc định là 0 theo cả chiều dọc va chiều ngang
	rect_.w = GIFT_WIDTH;
	rect_.h = GIFT_HEIGHT;
	type_ = Gift::NONE;													// Mặc định là có kiểu POWER
	is_move_ = true;													// Mặc định được phép di chuyển
}

Gift::~Gift() {
	// Do something here
}

void Gift::handleInputAction(SDL_Event events) {
	// Do something here
}

void Gift::handleMove(const int& x_border, const int& y_border) {
	if (is_move_) {
		rect_.x -= x_val_;
		if (rect_.x < 0)
			is_move_ = false;
	}
}




//------------------------------------------------------------------------//

void GiftFunc::prepareGiftRocket()
{
	gift_rocket = new Gift();

	gift_rocket->loadImgObject("gift.png");
	gift_rocket->setIsMove(true);
	gift_rocket->setXVal(GIFT_SPEED);
	gift_rocket->setType(Gift::UPGRADE_AMO);
	gift_rocket->setRect(rand() % 400 + SCREEN_WIDTH, rand() % (SCREEN_HEIGHT - 200));
}



void GiftFunc::prepareGiftHP()
{
	gift_hp = new Gift();

	gift_hp->loadImgObject("HP_gift.png");
	gift_hp->setIsMove(true);
	gift_hp->setXVal(GIFT_SPEED);
	gift_hp->setType(Gift::HP);
	gift_hp->setRect(rand() % 400 + SCREEN_WIDTH, rand() % (SCREEN_HEIGHT - 200)); 
}