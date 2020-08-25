#ifndef _MAIN_OBJECT_H_
#define _MAIN_OBJECT_H_

// include library
#include<vector>

#include"CommonFunction.h"
#include"BaseObject.h"
#include"AmoObject.h"


// define main's width and height
#define WIDTH_MAIN_OBJECT 146
#define HEIGHT_MAIN_OBJECT 70

class MainObject :public BaseObject {
public:

	// constructor
	MainObject();
	// destructor
	~MainObject();

	// main status
	enum MainStatus {
		STATUS_1,
		STATUS_2,
		STATUS_3
	};

	// set type of main
	void setType(const int&);

	// handle user input
	void handleInput(SDL_Event);

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
	unsigned int _mainType;
	vector<AmoObject*> _pAmoList;
};


void createMainObject(MainObject& mainObject);

#endif // !_MAINOBJECT_H_
#pragma once