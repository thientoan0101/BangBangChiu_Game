#pragma once

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "CommonFunction.h"

#include "ExplosionObject.h"
#include "ThreatsObject.h"
#include "Audio.h"
#include"HPObject.h"
#include"Gift.h"
#include"Random.h"
#include"TextObject.h"
#include"Menu.h"



#include"Background.h"
#include "WinLose.h"

extern int level;
extern bool is_quit;

namespace ControlFunc
{
	void setup();
	bool prepareGame();
	int playCampaign();
	bool playScore();

	void endGame();
}