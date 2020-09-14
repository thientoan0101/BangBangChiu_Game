#pragma once

#include "MainObject.h"
#include "ThreatsObject.h"
#include "Gift.h"

using namespace std;

void saveGame(MainObject main, int main_HP, int main_typeAmo, int main_typePlane, unsigned int die_num, vector<ThreatObject*> list_Threats, int numThreat, ThreatObject* pBoss, int type_boss, unsigned int die_num_boss, vector<ThreatObject*> listSubBoss, vector<Gift*> listGifts, int level);
void loadGame(MainObject& main, int main_HP, int main_typeAmo, int main_typePlane, unsigned int& die_num, vector<ThreatObject*>& list_Threats, int& numThreat, ThreatObject* pBoss, int& type_boss, unsigned int& die_num_boss, vector<ThreatObject*>& listSubBoss, vector<Gift*>& listGifts, int& level);