#pragma once

#include "BaseObject.h"

#define WIDTH_POWER 64												// Kích thước chiều ngang của vật phẩm kiểu POWER
#define HEIGHT_POWER 64												// Kích thước chiều dọc của vật phẩm kiểu POWER

class Present :public BaseObject {
public:
	enum PresentType {												// Loại vật phẩm
		POWER,														// Cho năng lượng / máu,...
		UPGRADE_WEAPON,												// Nâng cấp vũ khí
		UPGRADE_SPACESHIP,											// Nâng cấp máy bay
	};

	Present();
	~Present();

	void handleInputAction(SDL_Event events);						// Xử lý các sự kiện (chưa cài đặt)
	void handleMove(const int& x_border, const int& y_border);		// Xử lý việc di chuyển

	void setXVal(const int& val) { x_val_ = val; }					// Đặt tốc độ di chuyển của vật phẩm theo chiều ngang
	int getXVal() const { return x_val_; }							// Lấy tốc độ di chuyển của vật phẩm theo chiều ngang
	void setYVal(const int& val) { y_val_ = val; }					// Đặt tốc độ di chuyển của vật phẩm theo chiều dọc
	int getYVal() const { return y_val_; }							// Lấy tốc độ di chuyển của vật phẩm theo chiều dọc
	bool getIsMove() { return is_move_; }							// Lấy giá trị có được phép di chuyển hay không: true - di chuyển được, false - không được phép di chuyển
	void setIsMove(const bool& val) { is_move_ = val; }				// Đặt giá trị có được phép di chuyển hay không
	int getType() { return type_; }									// Lấy giá trị của loại vật phẩm
	void setType(const int& type) { type_ = type; }					// Đặt kiểu của vật phẩm

protected:
	int x_val_, y_val_;												// Tốc độ của vật phẩm theo chiều ngang, dọc
	int type_;														// Kiểu vật phẩm
	bool is_move_;													// Xác định có được phép di chuyển hay không
};