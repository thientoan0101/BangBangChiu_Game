<<<<<<< Updated upstream
#ifndef _MAIN_OBJECT_H_
#define _MAIN_OBJECT_H_
=======
#ifndef _MAINOBJECT_H_
#define _MAINOBJECT_H_
>>>>>>> Stashed changes

// include library
#include<vector>

#include"CommonFunction.h"
#include"BaseObject.h"
#include"AmoObject.h"


<<<<<<< Updated upstream
// define main's width and height
#define WIDTH_MAIN_OBJECT 146
#define HEIGHT_MAIN_OBJECT 70

=======
// define some const
#define WIDTH_MAIN_OBJECT 146
#define HEIGHT_MAIN_OBJECT 70

#define MAIN_SPEED 20

>>>>>>> Stashed changes
class MainObject :public BaseObject {
public:

	// constructor
	MainObject();
	// destructor
	~MainObject();

<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes

	// delete an amo
	void removeAmo(const int&);

<<<<<<< Updated upstream
void createMainObject(MainObject& mainObject);
=======
private:
	int _xVal, _yVal;
	vector<AmoObject*> _pAmoList;
};
>>>>>>> Stashed changes

#endif // !_MAINOBJECT_H_
#pragma once