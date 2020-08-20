#pragma once

#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_

#include "BaseObject.h"

#define WIDTH_BULLET 67																		// Kích thước theo chiều ngang của loại đạn dược
#define HEIGHT_BULLET 67																	// Kích thước theo chiều dọc của loại đạn dược

class AmoObject :public BaseObject {
public:
	enum AmoType {																			// Kiểu đạn dược
		NONE = 0,																			// Không có kiểu nào
		BULLET = 1,																			// Kiểu đạn
	};

	AmoObject();
	~AmoObject();

	void handleInputAction(SDL_Event events);												// Xử lý các sự kiện (chưa cài đặt)
	void handleMove(const int& x_border, const int& y_border);								// Xử lý việc đạn dược di chuyển từ trái sang phải (được dùng cho nhân vật chính), có biên để biết khi nào nên dừng
	void handleMoveRightToLeft();															// Xử lý việc đạn dược di chuyển từ phải sang trái (được dùng cho thread)

	int getType() { return amo_type_; }														// Lấy kiểu của đạn dược
	void setType(const int& val) { amo_type_ = val; }										// Đặt kiểu của đạn dược

	bool getIsMove() { return is_move_; }													// Lấy giá trị có cho phép di chuyển hay không
	void setIsMove(const bool& val) { is_move_ = val; }										// Đặt giá trị có được phép di chuyển hay không
	void setXVal(const int& val) { x_val_ = val; }											// Đặt tốc độ di chuyển của đạn dược theo chiều ngang
	void setYVal(const int& val) { y_val_ = val; }											// Đặt tốc độ di chuyển của đạn dược theo chiều dọc
	int getXVal(const int& val) { return x_val_; }											// Lấy tốc độ di chuyển của đạn dược theo chiều ngang
	int getYVal(const int& val) { return y_val_; }											// Lấy tốc độ di chuyển của đạn dược theo chiều ngang
	
	void setWidthHeight(int width, int height) { rect_.w = width; rect_.h = height; }		// Đặt kích thước chiều dài và rộng cho kiểu đạn dược

private:
	int x_val_, y_val_;																		// Giá trị tốc độ di chuyển của đạn dược
	bool is_move_;																			// Giá trị cho biết có được phép di chuyển hay không
	int amo_type_;																			// Kiểu của đạn dược
};

#endif