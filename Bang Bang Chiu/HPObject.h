#pragma once
#ifndef _HP_OBJECT_
#define _HP_OBJECT_

#include"BaseObject.h"
#include<vector>

#define LIFE 150
#define DAME_OF_THREAT 2   
#define DAME_OF_BOSS 10

class HP :public BaseObject {
public:
	HP();
	~HP();
	void setNumber(const int& num) { _number = num; }
	void addPos(const int&);
	void render(SDL_Surface*);
	void init();
	void decreaseHP();

	//void load_border(SDL_Surface*);

private:
	int _number;
	vector<int> _pos_list;
};

#endif // !_HP_OBJECT_
