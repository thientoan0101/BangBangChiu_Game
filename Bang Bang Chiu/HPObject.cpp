#include"HPObject.h"

HP::HP() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = LIFE;
}

HP::~HP(){}

void HP::addPos(const int& pos) {
	_pos_list.push_back(pos);
}

void HP::addPos_boss(const int& pos) {
	_pos_list_boss.push_back(pos);
}

//void HP::addPos_threat(const int& pos) {
//	_pos_list_threat.push_back(pos);
//}

void HP::render(SDL_Surface* des) {
	if (_number == _pos_list.size()) {
		for (int i = 0; i < _pos_list.size(); i ++) {
			rect_.x = _pos_list.at(i);
			showObject(des);
		}
	}
}

void HP::render_boss(SDL_Surface* des) {
	if (_number_boss == _pos_list_boss.size()) {
		for (int i = 0; i < _pos_list_boss.size(); i++) {
			rect_.x = _pos_list_boss.at(i);
			showObject(des);
		}
	}
}

//void HP::render_threat(SDL_Surface* des) {
//	if (_number_threat == _pos_list_threat.size()) {
//		for (int i = 0; i < _pos_list_threat.size(); i++) {
//			rect_.x = _pos_list_threat.at(i);
//			showObject(des);
//		}
//	}
//}

void HP::init() {
	loadImgObject("HP.png");
	_number = LIFE;
	if (_pos_list.size() > 0) _pos_list.clear();

	int count = X_POS_HP_MAIN + 60; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
	for (int i = 0; i < LIFE; i ++) {
		addPos(count);
		count += 2;
	}
}

void HP::init_BOSS() {
	loadImgObject("HP_boss.png");
	_number_boss = LIFE_BOSS;
	if (_pos_list_boss.size() > 0) _pos_list_boss.clear();

	int count = X_POS_HP_BOSS + LIFE_BOSS * 2; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
	for (int i = 0; i < LIFE_BOSS; i++) {
		addPos_boss(count);
		count -= 2;
	}
}

//void HP::init_threat() {
//	loadImgObject("HP_threat.png");
//	_number_threat = LIFE_BOSS;
//	if (_pos_list_threat.size() > 0) _pos_list_threat.clear();
//
//	int count = 0; // CÁI NÀY NÓ CÓ Ý NGHĨA SẼ PUSH_BACK TỪNG VỊ TRÍ MÀ MỖI CỘT MÁU NHỎ SẼ XUẤT HIỆN SAU ĐÓ TẠO THÀNH 1 THANH MÁU TO
//	for (int i = 0; i < LIFE_OF_THREAT; i++) {
//		addPos_threat(count);
//		count += 2;
//	}
//}

//void HP::load_border(SDL_Surface* des) {
//	loadImg("HP_border.png");
//	rect_.x = 0;
//	rect_.y = 0;
//	show(des);
//}

void HP::decreaseHP(){
	_number--;
	if (_pos_list.size() >= 0) _pos_list.pop_back();
}

void HP::decreaseHP_BOSS() {
	_number_boss--;
	if (_pos_list_boss.size() >= 0) _pos_list_boss.pop_back();
}


//void HP::decreaseHP_threat() {
//	_number_threat--;
//	if (_pos_list_threat.size() >= 0) _pos_list_threat.pop_back();
//}