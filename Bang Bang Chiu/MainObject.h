#pragma once


#include "CommonFunction.h"
#include "Audio.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include <vector>


//soldier
//#define WIDTH_MAIN_OBJECT 64	
//#define HEIGHT_MAIN_OBJECT 91

//helicopter
//#define WIDTH_MAIN_OBJECT 80
//#define HEIGHT_MAIN_OBJECT 46

//fly_plane
#define WIDTH_MAIN_OBJECT 77
#define HEIGHT_MAIN_OBJECT 52

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove();
	void SetAmoList(vector<AmoObject*> amo_list) { p_amo_list = amo_list; }
	vector<AmoObject*> GetAmoList() const { return p_amo_list; }
	void MakeAmo(SDL_Surface* des);
	void RemoveAmo(const int &idx);
private:
	int x_val_;
	int y_val_;
	vector<AmoObject*> p_amo_list;
};




























