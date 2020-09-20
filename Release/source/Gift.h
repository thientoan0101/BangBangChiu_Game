#pragma once

#include "BaseObject.h"

#define GIFT_SPEED 3
#define GIFT_WIDTH 80
#define GIFT_HEIGHT 53
#define GIFT_HP_WIDTH 55
#define GIFT_HP_HEIGHT 46
#define GIFT_UPGRADE_WIDTH 60
#define GIFT_UPGRADE_HEIGHT 44
#define DELTA_DROP_HP 4000
#define DELTA_DROP_ROCKET 10000
#define DELTA_DROP_UPGRADE 15000


extern bool create;

extern int num_rocket;				 // số lượng rocket
extern int num_blood;
extern int time_of_lv2;



class Gift :public BaseObject {
public:
	enum GiftType {												// Loại vật phẩm
		NONE,
		HP,															// Cho năng lượng / máu,...
		UPGRADE_AMO,												// Nâng cấp vũ khí
		UPGRADE_SPACESHIP,											// Nâng cấp máy bay
		UPGRADE_SPACESHIP_AMO
	};

	Gift();
	~Gift();

	void handleInputAction(SDL_Event events);						// Xử lý các sự kiện (chưa cài đặt)
	void handleMove(const int& x_border, const int& y_border);		// Xử lý việc di chuyển

	void setXVal(const int& val) { x_val_ = val; }					// Đặt tốc độ di chuyển của vật phẩm theo chiều ngang
	int getXVal() const { return x_val_; }							// Lấy tốc độ di chuyển của vật phẩm theo chiều ngang
	void setYVal(const int& val) { y_val_ = val; }					// Đặt tốc độ di chuyển của vật phẩm theo chiều dọc
	int getYVal() const { return y_val_; }							// Lấy tốc độ di chuyển của vật phẩm theo chiều dọc
	bool getIsMove() { return is_move_; }							// Lấy giá trị có được phép di chuyển hay không: true - di chuyển được, false - không được phép di chuyển
	void setIsMove(const bool& val) { is_move_ = val; }				// Đặt giá trị có được phép di chuyển hay không
	int getType() { return type_; }									// Lấy giá trị của loại vật phẩm
	void setType(const int& type) { type_ = type; }
	bool getIsCreate() { return is_create_; }
	void setIsCreate(const bool& is_create) { is_create_ = is_create; }// Đặt kiểu của vật phẩm

protected:
	int x_val_, y_val_;												// Tốc độ của vật phẩm theo chiều ngang, dọc
	int type_;														// Kiểu vật phẩm
	bool is_move_;													// Xác định có được phép di chuyển hay không
	bool is_create_;
};



// bien toan cuc : toan them
extern Gift* gift_rocket;
extern Gift* gift_hp;
extern Gift* gift_upgr_main;


void createGift(const char* name, Gift*& gift, const int& type);
namespace GiftFunc
{
	void prepareGiftRocket();
	void prepareGiftHP();
	void prepareGiftUpgrade();
}