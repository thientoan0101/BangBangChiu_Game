#include"HPObject.h"

HP::HP(){}

HP::~HP(){}

void HP::addPos(const int& pos) {
	_pos_list.push_back(pos);
}

void HP::render(SDL_Surface* des) {
	if (_number == _pos_list.size()) {
		for (int i = 0; i < _pos_list.size(); i ++) {
			rect_.x = _pos_list.at(i);
			showObject(des);
		}
	}
}

void HP::init() {
	loadImgObject("HP.png");
	_number = LIFE;
	if (_pos_list.size() > 0) _pos_list.clear();

	int count = 0;
	for (int i = 0; i < LIFE; i ++) {
		addPos(count);
		count += 2;
	}
}

//void HP::load_border(SDL_Surface* des) {
//	loadImg("HP_border.png");
//	rect_.x = 0;
//	rect_.y = 0;
//	show(des);
//}

void HP::decreaseHP(){
	_number--;
	_pos_list.pop_back();
}