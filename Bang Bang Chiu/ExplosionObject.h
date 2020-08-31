#pragma once

#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include "MainObject.h"
#include "ThreatsObject.h"
const int EXP_WIDTH = 165;
const int EXP_HEIGHT = 165;

const int BIG_EXP_WIDTH = 159;
const int BIG_EXP_HEIGHT = 208;

const int SMALL_EXP_WIDTH = 99;
const int SMALL_EXP_HEIGHT = 99;

const int UPGRADE_WIDTH = 150;
const int UPGRADE_HEIGHT = 125;


class ExplosionObject : public BaseObject
{
private:
	int frame_;
	SDL_Rect clip_[4];

	// moi them:
	SDL_Rect clipBig_[8];
public:
	ExplosionObject();
	~ExplosionObject();
	void set_clip();
	void set_frame(const int& fr) { frame_ = fr; }
	void showEx(SDL_Surface *des);
	
	
	// moi them
	void set_clip_big();
	void showExBig(SDL_Surface *des);

	void set_clip_small();
	void showExSmall(SDL_Surface *des);

	void set_clip_upgrade();
	void showUpgrade(SDL_Surface *des);
	// moi them nua:
	




};
