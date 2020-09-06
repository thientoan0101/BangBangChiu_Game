#pragma once

#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include "MainObject.h"
#include "ThreatsObject.h"


extern const int EXP_WIDTH;;
extern const int EXP_HEIGHT;

extern const int BIG_EXP_WIDTH;
extern const int BIG_EXP_HEIGHT;

extern const int SMALL_EXP_WIDTH;
extern const int SMALL_EXP_HEIGHT;

extern const int UPGRADE_WIDTH;
extern const int UPGRADE_HEIGHT;

#define EAT_EXP_WIDTH 249
#define EAT_EXP_HEIGHT 256



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
	void set_clip_eat_item(); // đăng sửa 
	void showUpgrade(SDL_Surface* des);
	// moi them nua:
	




};



//-------------------------------------------------------------------------------------------//
extern ExplosionObject exp_subboss;
extern ExplosionObject explo_main;



namespace ExplosionFunc
{
	bool prepareExpSub();
	bool prepareExpMain();
}






