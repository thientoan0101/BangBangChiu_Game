#pragma once

#ifndef BULLET_OBJECT_H_
#define BULLET__OBJECT_H_

#include "AmoObject.h"

#define WIDTH_BULLET 67															// Kích thước đạn dược
#define HEIGHT_BULLET 67

class BulletObject :public AmoObject {
public:
	BulletObject();
	~BulletObject();

	virtual void handleInputAction(SDL_Event events);							// Xử lý các sự kiện (chưa cài đặt)
	virtual void handleMove(const int& x_border, const int& y_border);			// Xử lý việc đạn dược di chuyển từ trái sang phải (được dùng cho nhân vật chính), có biên để biết khi nào nên dừng
	virtual void handleMoveRightToLeft();										// Xử lý di chuyển từ phải sang trái				
	virtual int type();															// Trả về kiểu của đạn dược
	virtual AmoObject* create();												// Tạo đạn dược

	void move(const int& x_limit, const int& y_limit);							// Di chuyển, khác với handleMove, hàm nãy vừa di chuyển vừa in ra màn hình
	void moveRightToLeft(const int& x_limit, const int& y_limit);				// Tương tự như trên nhưng đi theo chiều từ phải sang trái
};

#endif