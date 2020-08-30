#ifndef _MAINOBJECT_H_
#define _MAINOBJECT_H_

// include library
#include<vector>

#include"CommonFunction.h"
#include"BaseObject.h"
#include"AmoObject.h"


// define some const
#define WIDTH_MAIN_OBJECT 146
#define HEIGHT_MAIN_OBJECT 70

#define MAIN_SPEED 20

class MainObject :public BaseObject {
public:

	// constructor
	MainObject();
	// destructor
	~MainObject();

	// handle user input
	void handleInput(SDL_Event/*, Mix_Chunk* bullet_sound[NUM_AUDIO_EXPLOSION]*/);

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