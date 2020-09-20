#pragma once
#ifndef _HP_OBJECT_
#define _HP_OBJECT_

#include"BaseObject.h"
#include<vector>

#define LIFE 135
#define LIFE_BOSS 135
#define DAME_OF_THREAT 1
#define DAME_OF_BOSS 10
#define X_POS_HP_MAIN 13// X CỦA THANH MÁU MAIN
#define Y_POS_HP_MAIN 11 // Y CUA THANH MAU MAIN
#define X_POS_HP_BORDER_MAIN 0// X CỦA THANH MÁU MAIN
#define Y_POS_HP_BORDER_MAIN 0 // Y CUA THANH MAU MAIN
#define DAME_COLLISION 5
#define Y_POS_HP_BORDER_BOSS 0 // Y CUA THANH MAU BOSS


extern const int X_POS_HP_BORDER_BOSS;					// X CỦA THANH MÁU BOSS
extern const int X_POS_HP_BOSS;						    // X CỦA THANH MÁU BOSS
extern const int Y_POS_HP_BOSS;							// Y CUA THANH MAU BOSS
	
extern unsigned int die_num;							// biến đếm số lần main trúng đạn
extern unsigned int die_num_boss;

extern int DAME_OF_MAIN;
extern const int LIFE_OF_THREAT;						// mau cua threat

class HP :public BaseObject {
public:
	HP();
	~HP();
	void setNumber(const int& num) { _number = num; }
	void addPos(const int&);
	void addPos_boss(const int&);
	void addPos_threat(const int&);

	void render(SDL_Surface*);
	void render_boss(SDL_Surface*);
	void render_threat(SDL_Surface*);

	void init(int n = 0);
	void init_BOSS(int n = 0);
	void init_threat();

	void decreaseHP();
	void decreaseHP_BOSS();
	void decreaseHP_threat();

	//void load_border(SDL_Surface*);

private:
	int _number;
	vector<int> _pos_list;

	int _number_boss;
	vector<int> _pos_list_boss;

	int _number_threat;
	vector<int> _pos_list_threat;
};

#endif // !_HP_OBJECT_



//-------------------------------------------------------------------------------------//
extern HP hp;
extern HP hp_boss;
extern SDL_Surface * hp_border;
extern SDL_Surface* hp_border_boss;


namespace HpFunc
{
	void prepareHpMain();
	void prepareHpBoss();
	
	bool prepareMainHpBorder();
	bool prepareBossHpBorder();
}












