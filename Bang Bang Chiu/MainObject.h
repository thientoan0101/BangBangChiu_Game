#ifndef _MAINOBJECT_H_
#define _MAINOBJECT_H_

// include library
#include<vector>

#include"CommonFunction.h"
#include"BaseObject.h"
#include"AmoObject.h"


// define some const
#define WIDTH_MAIN_OBJECT 155
#define HEIGHT_MAIN_OBJECT 80

#define MAIN_SPEED 10

class MainObject :public BaseObject {
public:

	// constructor
	MainObject();
	// destructor
	~MainObject();

	// handle user input
	void handleInput(SDL_Event, int&, int&, int&);

	// handle moves of mainObject when user input from keyboard
	void handleMove();

	// an amolist ready for war
	void setAmoList(vector<AmoObject*>);

	// get list of amo after handled by using function (setAmoList)
	vector<AmoObject*> getAmoList() const;

	// create an amo
	void makeAmo(SDL_Surface*);

	// delete an amo
	void removeAmo(const int&);

private:
	int _xVal, _yVal;
	vector<AmoObject*> _pAmoList;
};

#endif // !_MAINOBJECT_H_
#pragma once