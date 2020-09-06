#include "Control.h"


int level = 1;
bool is_quit = false;



bool ControlFunc::prepareGame()
{
	bool isSuccess = true;

	bool ret;
	ret = BackgroundFunc::prepareBackground(level);							// load background theo man
	if (ret == 0)	isSuccess = false;	
	
	HpFunc::prepareHpMain();												// khoi tao HP cua main
	
	ret = HpFunc::prepareMainHpBorder();									// load thanh mau cua main
	if (ret == 0)	isSuccess = false;
	
	HpFunc::prepareHpBoss();												// khoi tao HP cua Boss

	ret = HpFunc::prepareBossHpBorder();									// load thanh mau cua Boss
	if (ret == 0)	isSuccess = false;

	ret = MainFunc::prepareMain();											// khoi tao MainObject
	if (ret == 0)	isSuccess = false;

	ThreatFunc::prepareThreats();											// khoi tao list Threat
	
	ret = ExplosionFunc::prepareExpSub();									// khoi vao vu no cua threat
	if (ret == 0)	isSuccess = false;
	ret = ExplosionFunc::prepareExpMain();									// khoi tao vu no cua main
	if (ret == 0)	isSuccess = false;

	GiftFunc::prepareGiftRocket();											// khoi tao Gift
	GiftFunc::prepareGiftHP();						

	

	return isSuccess;
}