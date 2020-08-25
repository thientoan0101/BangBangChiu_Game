#pragma once

#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include "BaseObject.h"


class AmoObject :public BaseObject {
public:
	virtual void handleInputAction(SDL_Event events) {}									// Xử lý các sự kiện (chưa cài đặt)
	virtual void handleMove(const int& x_border, const int& y_border) {}				// Xử lý việc đạn dược di chuyển từ trái sang phải (được dùng cho nhân vật chính), có biên để biết khi nào nên dừng
	virtual void handleMoveRightToLeft() {}												// Xử lý việc đạn dược di chuyển từ phải sang trái (được dùng cho thread)

	virtual int type() { return -1; }																	// Lấy kiểu của đạn dược
	void setType(const int& val) { type_ = val; }											// Đặt kiểu của đạn dược

	bool isMove() { return is_move_; }														// Lấy giá trị có cho phép di chuyển hay không
	void setIsMove(const bool& val) { is_move_ = val; }										// Đặt giá trị có được phép di chuyển hay không
	void setXVal(const int& val) { x_val_ = val; }											// Đặt tốc độ di chuyển của đạn dược theo chiều ngang
	void setYVal(const int& val) { y_val_ = val; }											// Đặt tốc độ di chuyển của đạn dược theo chiều dọc
	int xVal() { return x_val_; }															// Lấy tốc độ di chuyển của đạn dược theo chiều ngang
	int yVal() { return y_val_; }															// Lấy tốc độ di chuyển của đạn dược theo chiều ngang
	
	void setWidthHeight(int width, int height) { rect_.w = width; rect_.h = height; }		// Đặt kích thước chiều dài và rộng cho kiểu đạn dược

	virtual AmoObject* create() { return NULL; }														// Tạo đối tượng mới

	void destroy() { is_move_ = false; }													// Khi đụng vào các đối tượng khác thì biến mất (biến mất chứ chưa được hủy vùng nhớ)

protected:
	int x_val_, y_val_;																		// Giá trị tốc độ di chuyển của đạn dược
	bool is_move_;																			// Giá trị cho biết có được phép di chuyển hay không
	int type_;																				// Kiểu của đạn dược
};

#endif