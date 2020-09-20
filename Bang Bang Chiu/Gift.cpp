#include "Gift.h"

Gift* gift_rocket;
Gift* gift_hp;
Gift* gift_upgr_main;


bool create = false;

int num_rocket = 0;					// số lượng rocket
int num_blood = 0;				// số lượng hồi máu
int time_of_lv2 = 0;



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


void createGift(const char* name, Gift*& gift, const int& type) {
	gift->loadImgObject(name);
	gift->setIsMove(true);
	gift->setXVal(GIFT_SPEED);
	gift->setType(type);
	gift->setRect(rand() % 400 + SCREEN_WIDTH, rand() % (SCREEN_HEIGHT - 100));
}



//------------------------------------------------------------------------//

void GiftFunc::prepareGiftRocket()
{
	gift_rocket = new Gift();
	createGift("./image/gift.png", gift_rocket, Gift::UPGRADE_AMO);
}



void GiftFunc::prepareGiftHP()
{
	gift_hp = new Gift();
	createGift("./image/HP_gift.png", gift_hp, Gift::HP);
}

void GiftFunc::prepareGiftUpgrade()
{
	gift_upgr_main = new Gift();
	createGift("./image/gift_up_main.png", gift_upgr_main, Gift::UPGRADE_SPACESHIP);
}
