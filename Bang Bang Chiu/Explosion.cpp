#include "ExplosionObject.h"


ExplosionObject::ExplosionObject()
{


}

ExplosionObject::~ExplosionObject()
{


}


void ExplosionObject::set_clip()
{
	clip_[0].x = 0;
	clip_[0].y = 0;
	clip_[0].w = EXP_WIDTH;
	clip_[0].h = EXP_HEIGHT;

	clip_[1].x = EXP_WIDTH;
	clip_[1].y = 0;
	clip_[1].w = EXP_WIDTH;
	clip_[1].h = EXP_HEIGHT;

	clip_[2].x = 2*EXP_WIDTH;
	clip_[2].y = 0;
	clip_[2].w = EXP_WIDTH;
	clip_[2].h = EXP_HEIGHT;

	clip_[3].x = 3*EXP_WIDTH;
	clip_[3].y = 0;
	clip_[3].w = EXP_WIDTH;
	clip_[3].h = EXP_HEIGHT;

}


void ExplosionObject::showEx(SDL_Surface *des)
{
	if (frame_ >= 4)
	{
		frame_ = 0;
	}
	 
	SDLCommonFunc::applySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y); 
}



void ExplosionObject::set_clip_big()
{
	for (int i = 0; i < 8; i++)
	{
		clipBig_[i].x = i * BIG_EXP_WIDTH;
		clipBig_[i].y = 0;
		clipBig_[i].w = BIG_EXP_WIDTH;
		clipBig_[i].h = BIG_EXP_HEIGHT;
	}
	

}


void ExplosionObject::showExBig(SDL_Surface *des)
{
	if (frame_ >= 8)
	{
		frame_ = 0;
	}

	SDLCommonFunc::applySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y);
}


void ExplosionObject::set_clip_small()
{
	/*for (int i = 0; i < 4; i++)
	{
		clip_[i].x = i * SMALL_EXP_WIDTH;
		clip_[i].y = 0;
		clip_[i].w = SMALL_EXP_WIDTH;
		clip_[i].h = SMALL_EXP_HEIGHT;
	}*/

	clip_[0].x = 0;
	clip_[0].y = 0;
	clip_[0].w = SMALL_EXP_WIDTH;
	clip_[0].h = SMALL_EXP_HEIGHT;

	clip_[1].x = SMALL_EXP_WIDTH;
	clip_[1].y = 0;
	clip_[1].w = SMALL_EXP_WIDTH;
	clip_[1].h = SMALL_EXP_HEIGHT;

	clip_[2].x = 2 * SMALL_EXP_WIDTH;
	clip_[2].y = 0;
	clip_[2].w = SMALL_EXP_WIDTH;
	clip_[2].h = SMALL_EXP_HEIGHT;

	clip_[3].x = 3 * SMALL_EXP_WIDTH;
	clip_[3].y = 0;
	clip_[3].w = SMALL_EXP_WIDTH;
	clip_[3].h = SMALL_EXP_HEIGHT;
}


void ExplosionObject::showExSmall(SDL_Surface *des)
{
	if (frame_ >= 4)
	{
		frame_ = 0;
	}

	SDLCommonFunc::applySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y);
}


void ExplosionObject::set_clip_upgrade()
{
	for (int i = 0; i < 4; i++)
	{
		clip_[i].x = i * UPGRADE_WIDTH;
		clip_[i].y = 0;
		clip_[i].w = UPGRADE_WIDTH;
		clip_[i].h = UPGRADE_HEIGHT;
	}


}


void ExplosionObject::showUpgrade(SDL_Surface *des)
{
	if (frame_ >= 4)
	{
		frame_ = 0;
	}

	SDLCommonFunc::applySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y);
}