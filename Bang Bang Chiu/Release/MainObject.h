#ifndef _MAINOBJECT_H_
#define _MAINOBJECT_H_

// include library
#include<vector>

#include"CommonFunction.h"
#include"BaseObject.h"
#include"AmoObject.h"
#include "Audio.h"
#include"HPObject.h"

// define some const
#define WIDTH_MAIN_OBJECT 155
#define HEIGHT_MAIN_OBJECT 80
#define WIDTH_MAIN_OBJECT_LV2 200
#define HEIGHT_MAIN_OBJECT_LV2 78
#define WIDTH_ULTI_LV2 608
#define HEIGHT_ULTI_LV2 140
#define LIMIT_TIME_LV2 1000

#define MAIN_SPEED 10

class MainObject :public BaseObject {
public:

	// constructor
	MainObject();
	// destructor
	~MainObject();

	enum Type {
		LEVEL_1, LEVEL_2
	};


	// handle user input
	void handleInput(SDL_Event&, int&, int&, int&);

	// handle moves of mainObject when user input from keyboard
	void handleMove();

	// an amolist ready for war
	void setAmoList(vector<AmoObject*>);

	// set xVal, yVal:
	void setXY_Val(const int & x_Val, const int& y_Val)
	{
		_xVal = x_Val;	_yVal = y_Val;
	}

	// get list of amo after handled by using function (setAmoList)
	vector<AmoObject*> getAmoList() const;

	// create an amo
	void makeAmo(SDL_Surface*);

	// delete an amo
	void removeAmo(const int&);

	// type of main
	void setType(const int& type) { _type = type; }
	int getType() { return _type; }

	bool isDead() { return die_num >= LIFE; }

private:
	int _type;
	int _xVal, _yVal;
	vector<AmoObject*> _pAmoList;
};

#endif // !_MAINOBJECT_H_
#pragma once



//--------------------------------------------------------------------------//
extern MainObject mainObject;



namespace MainFunc
{
	bool prepareMain();
}