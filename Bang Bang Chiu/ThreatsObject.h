#pragma once


#include "CommonFunction.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include "MainObject.h"
#include <vector>


#define WIDTH_THREAT_0 50
#define HEIGHT_THREAT_0 32
#define WIDTH_THREAT_1 80
#define HEIGHT_THREAT_1 33
#define WIDTH_THREAT_2 80
#define HEIGHT_THREAT_2 33
#define WIDTH_THREAT_3 83
#define HEIGHT_THREAT_3 52
#define WIDTH_BOSS_4 120
#define HEIGHT_BOSS_4 60
#define WIDTH_BOSS_5 202
#define HEIGHT_BOSS_5 101
#define WIDTH_BOSS_6 80
#define HEIGHT_BOSS_6 33
#define WIDTH_SUB_BOSS 60
#define HEIGHT_SUB_BOSS 43
#define MAX_STEP 30
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

	void HandleMove(const int &x_border, const int &y_border);
	void HandleMoveOscilate(const int &x_border, const int &y_border);
	void HandleInputAction(SDL_Event events);
	
	void SetAmoList(vector<AmoObject*> amo_list) { _p_amo_list = amo_list; }
	vector<AmoObject*> GetAmoList() const { return _p_amo_list; }

	void initAmo(AmoObject *p_amo);
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