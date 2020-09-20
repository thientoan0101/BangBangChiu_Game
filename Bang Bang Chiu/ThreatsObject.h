#pragma once

#include "Control.h"
#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include "MainObject.h"
#include <vector>


#define WIDTH_THREAT_0 100
#define HEIGHT_THREAT_0 66
#define WIDTH_THREAT_1 140
#define HEIGHT_THREAT_1 127
#define WIDTH_THREAT_2 100
#define HEIGHT_THREAT_2 73
#define WIDTH_THREAT_3 100
#define HEIGHT_THREAT_3 100
#define WIDTH_BOSS_4 223
#define HEIGHT_BOSS_4 204
#define WIDTH_BOSS_5 290
#define HEIGHT_BOSS_5 219
#define WIDTH_BOSS_6 250
#define HEIGHT_BOSS_6 212
#define WIDTH_BOSS_7 179
#define HEIGHT_BOSS_7 231
#define WIDTH_SUB_BOSS 95
#define HEIGHT_SUB_BOSS 45

#define MAX_STEP 30
#define NUM_THREAT 4


extern bool activeBoss;
extern bool activeSubBoss;





class ThreatObject : public BaseObject
{
private:
	
	int _x_delta;
	int _y_delta;
	vector<AmoObject*> _p_amo_list;
	int _threat_type;
	
	bool _active_oscillation;
	int _step;
	// Blood _blood;

public: // distribute:
	enum ThreatType
	{
		TYPE_0 = 0,
		TYPE_1 = 1,
		TYPE_2 = 2,
		TYPE_3 = 3,
		BOSS_1 = 4,
		BOSS_2 = 5,
		BOSS_3 = 6,
		BOSS_4 = 7,
		SUB = 10
	};


public: // Constructor - Destructor:
	ThreatObject();
	~ThreatObject();

public: // Properties: 
	void set_x_delta(const int &value) { _x_delta = value; }
	void set_y_delta(const int &value) { _y_delta = value; }
	int get_x_delta() const { return _x_delta; }
	int get_y_delta() const { return _y_delta; }

	void setOscillation(const bool &value) { _active_oscillation = value; }
	bool getOscillation() const { return _active_oscillation; }

	int getType() const { return _threat_type; }
	void setType(const int &type) { _threat_type = type; }

public: // Methods - Behaviors:

	void Move();
	void HandleMove(const int &x_border, const int &y_border);
	void HandleMoveOscilate(const int &x_border, const int &y_border);
	void HandleInputAction(SDL_Event events);
	
	void SetAmoList(vector<AmoObject*> amo_list) { _p_amo_list = amo_list; }
	vector<AmoObject*> GetAmoList() const { return _p_amo_list; }

	void initAmo(AmoObject *p_amo);
	void initAmo_boss(AmoObject* p_amo);
	void MakeAmo(SDL_Surface* des, const int &x_limit, const int &y_limit);


	//dat lai vi tri:
	void Reset(const int &xboder);
	void ResetAmo(AmoObject* p_amo);

public: // friend functions:

	friend void createListThreatObjects(vector<ThreatObject*> &list, const int &level, int &numThreats);
	friend void createThreat(ThreatObject* &pThreat, const int &type, const int &index);
	friend void destroyThreatObjects(vector<ThreatObject*> &list);


	friend void createBoss(ThreatObject* &pBoss, const int &type);
	friend void createSubBoss(ThreatObject* &pSubBoss, ThreatObject* &pBoss);
	void HandleMoveSub(ThreatObject* &pBoss);

};



extern vector<ThreatObject*> listThreats;
extern vector<ThreatObject*> listSub;
extern ThreatObject* pBoss;
extern int numThreats;


namespace ThreatFunc
{
	void prepareThreats();
	void freeThreats();
	void prepareBoss();
}