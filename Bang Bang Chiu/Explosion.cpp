#include "ExplosionObject.h"


ExplosionObject::ExplosionObject()
{


}

ExplosionObject::~ExplosionObject()
{


}


void ExplosionObject::set_clip()
{
	for (int i = 0; i < 4; i++)
	{
		clipBig_[i].x = i * BIG_EXP_WIDTH;
		clipBig_[i].y = 0;
		clipBig_[i].w = BIG_EXP_WIDTH;
		clipBig_[i].h = BIG_EXP_HEIGHT;
	}

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
	for (int i = 0; i < 4; i++)
	{
		clip_[i].x = i * SMALL_EXP_WIDTH;
		clip_[i].y = 0;
		clip_[i].w = SMALL_EXP_WIDTH;
		clip_[i].h = SMALL_EXP_HEIGHT;
	}
}

void ExplosionObject::set_clip_eat_item()
{
	for (int i = 0; i < 4; i++)
	{
		clip_[i].x = i * EAT_EXP_WIDTH;
		clip_[i].y = 0;
		clip_[i].w = EAT_EXP_WIDTH;
		clip_[i].h = EAT_EXP_HEIGHT;
	}
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


void ExplosionObject::showUpgrade(SDL_Surface* des)
{
	if (frame_ >= 4)
	{
		frame_ = 0;
	}

	SDLCommonFunc::applySurfaceClip(this->p_object_, des, &clip_[frame_], rect_.x, rect_.y);
}