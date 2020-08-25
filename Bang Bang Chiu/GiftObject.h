#pragma once

#ifndef GIFT_OBJECT_H_
#define GIFT_OBJECT_H_

#include "BaseObject.h"

class GiftObject :public BaseObject {
public:
	virtual void handleInputAction(SDL_Event events) {}						// Xử lý các sự kiện (chưa cài đặt)
	virtual void handleMoveRightToLeft() {}									// Xử lý việc di chuyển

	void setXVal(const int& val) { x_val_ = val; }								// Đặt tốc độ di chuyển của vật phẩm theo chiều ngang
	int getXVal() const { return x_val_; }										// Lấy tốc độ di chuyển của vật phẩm theo chiều ngang
	void setYVal(const int& val) { y_val_ = val; }								// Đặt tốc độ di chuyển của vật phẩm theo chiều dọc
	int getYVal() const { return y_val_; }										// Lấy tốc độ di chuyển của vật phẩm theo chiều dọc
	bool getIsMove() { return is_move_; }										// Lấy giá trị có được phép di chuyển hay không: true - di chuyển được, false - không được phép di chuyển
	void setIsMove(const bool& val) { is_move_ = val; }							// Đặt giá trị có được phép di chuyển hay không
	virtual int type() { return -1; }														// Lấy giá trị của loại vật phẩm
	void setType(const int& type) { type_ = type; }								// Đặt kiểu của vật phẩm

	void setWidthHeight(int width, int height) { rect_.w = width; rect_.h = height; }

	virtual GiftObject* create() { return NULL; }											// Tạo đối tượng mới
	
	void destroy() { is_move_ = false; }										// Khi đụng vào các đối tượng khác thì biến mất (biến mất chứ chưa được hủy vùng nhớ)

protected:
	int x_val_, y_val_;															// Tốc độ của vật phẩm theo chiều ngang, dọc
	int type_;																	// Kiểu vật phẩm
	bool is_move_;																// Xác định có được phép di chuyển hay không
};

#endif