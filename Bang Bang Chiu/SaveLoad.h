#pragma once

#include "MainObject.h"
#include "ThreatsObject.h"
#include "MainObject.h"
#include "Gift.h"
#include "Score.h"

using namespace std;

void Reset(int& type_boss, int& level, Score& score);
void saveGame(int type_boss, int level, Score& score);
void load(int& type_boss, int& level, Score& score);

void loadGame(int& type_boss, int& level, Score& score);