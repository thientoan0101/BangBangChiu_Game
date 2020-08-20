#include "ThreatsObject.h"




ThreatObject::ThreatObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;


	this->setWidthHeight(WIDTH_THREAT_0, HEIGHT_THREAT_0);
	_x_delta = 0;
	_y_delta = 0;
	_active_oscillation = false;
	_step = 0;
	// _blood = 1;
}

ThreatObject::~ThreatObject()
{
	/*if (p_amo_list_.size() > 0)
	{
		for (int i = 0; i < p_amo_list_.size(); i++)
		{
			AmoObject* p_amo = p_amo_list_.at(i);
			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		p_amo_list_.clear();
	}*/
}

void ThreatObject::HandleMove(const int &x_border, const int &y_border)
{
	//todo
	bool letRunToEnd = true;
	switch (_threat_type)													// con thay doi:
	{
	case 0: 
		this->set_x_delta(2 + SPEED_BACKGROUND);		break;
	case 1:
		this->set_x_delta(3 + SPEED_BACKGROUND);		break;
	case 2:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 3:
		this->set_x_delta(3 +SPEED_BACKGROUND);			this->set_y_delta(2);	letRunToEnd = false;	break;
	case 4:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 5:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 6:
		this->set_x_delta(1 + SPEED_BACKGROUND);		this->set_y_delta(1);	letRunToEnd = false;	break;
	case 10:
		this->set_x_delta(1 + SPEED_BACKGROUND);		this->set_y_delta(1);	letRunToEnd = false;	break;
	default:
		break;
	}



	rect_.x -= _x_delta;
	if (letRunToEnd)
	{
		if (rect_.x < 0)
		{
			rect_.x = SCREEN_WIDTH;
			rect_.y = rand() % SCREEN_HEIGHT;
		}
	}
	else {
		if (rect_.x < 2*SCREEN_WIDTH/3)
		{
			_active_oscillation = true;
		}
	}
}


void ThreatObject::HandleMoveOscilate(const int &x_border, const int &y_border)
{
	//todo
	if (_step == MAX_STEP) 
	{
		int temp = rand() % 2;
		if (temp) _x_delta = -(_x_delta + SPEED_BACKGROUND);
		temp = rand() % 2;
		if (temp) _y_delta = -(_y_delta);
		_step = 0;
	}

	rect_.x += _x_delta + SPEED_BACKGROUND;
	rect_.y += _y_delta;
	_step++;
	if (rect_.x < 0 || rect_.x > SCREEN_WIDTH || rect_.y < 0 || rect_.y > SCREEN_HEIGHT)
	{
		rect_.x = SCREEN_WIDTH + SCREEN_WIDTH/4;
		rect_.y = rand() % SCREEN_HEIGHT;
		_active_oscillation = false;
	}
	
}



void ThreatObject::HandleMoveSub(ThreatObject* &pBoss)
{
	//todo
	if (_step == MAX_STEP)
	{
		int temp = rand() % 2;
		if (temp) _x_delta = -_x_delta;
		temp = rand() % 2;
		if (temp) _y_delta = -_y_delta;
		_step = 0;
	}

	rect_.x += _x_delta;
	rect_.y += _y_delta;
	_step++;
	if (rect_.x < -SCREEN_WIDTH/20 || rect_.x > SCREEN_WIDTH*1.05 || rect_.y < -SCREEN_HEIGHT/20 || rect_.y > SCREEN_HEIGHT*1.05)
	{
		rect_.x = pBoss->rect_.x + pBoss->rect_.w/3;
		rect_.y = pBoss->rect_.y + pBoss->rect_.h + pBoss->rect_.h/4 ;
		_active_oscillation = false;
	}

}





void ThreatObject::HandleInputAction(SDL_Event events)
{
	//todo
}

//
//void ThreatObject::InitAmo(AmoObject *p_amo)
//{
//	if (p_amo)
//	{
//		bool ret = p_amo->LoadImg("sphere2.png");
//		if (ret)
//		{
//			p_amo->set_is_move(true);
//			p_amo->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
//			p_amo->set_type(AmoObject::SPHERE);
//			p_amo->SetRect(rect_.x, rect_.y + rect_.h*0.5);
//			p_amo->set_x_val(8);
//			p_amo_list_.push_back(p_amo);
//		}
//	}
//}
//

//
//void ThreatObject::MakeAmo(SDL_Surface* des, const int &x_limit, const int &y_limit)
//{
//	for (int i = 0; i < p_amo_list_.size(); i++)
//	{
//		AmoObject *p_amo = p_amo_list_.at(i);
//		if (p_amo)
//		{
//			if (p_amo->get_is_move())
//			{
//				p_amo->HandleMoveRightToLeft();
//				p_amo->Show(des);				
//			}
//			else
//			{
//				p_amo->set_is_move(true);
//				p_amo->SetRect(rect_.x, rect_.y + rect_.h*0.5);
//			}
//		}
//	}
//}
//


void ThreatObject::Reset(const int &xboder)
{
	rect_.x = xboder;
	//srand(time(NULL));
	rect_.y = rand() % SCREEN_HEIGHT;

	/*for (int i = 0; i < p_amo_list_.size(); i++)
	{
		AmoObject* p_amo = p_amo_list_.at(i);
		if (p_amo)
		{
			ResetAmo(p_amo);
		}
	}*/
}

//
//void ThreatObject::ResetAmo(AmoObject* p_amo)
//{
//	p_amo->SetRect(rect_.x, rect_.y + rect_.h*0.5);
//}



//-----------------------------------------------------------------------------------------
void createThreat(ThreatObject* &pThreat, const int &type, const int &index)
{
	int width, height;
	switch (type)
	{
	case 0:
		width = WIDTH_THREAT_0;	height = HEIGHT_THREAT_0; 
		pThreat->loadImgObject("threat_0.png");			
		//pThreat->_blood = 1;
		break;
	case 1: 
		width = WIDTH_THREAT_1;	height = HEIGHT_THREAT_1;
		pThreat->loadImgObject("threat_1.png");		
		//pThreat->_blood = 1;
		break;
	case 2:
		width = WIDTH_THREAT_2;	height = HEIGHT_THREAT_2;
		pThreat->loadImgObject("threat_2.png");		
		//pThreat->_blood = 1;
		break;
	case 3:
		width = WIDTH_THREAT_3;	height = HEIGHT_THREAT_3;
		pThreat->loadImgObject("threat_3.png");		
		//pThreat->_blood = 1;
		break;
	default:
		break;
	}

	pThreat->rect_.w = width;
	pThreat->rect_.h = height;

	pThreat->_threat_type = type;
	int rng_y = rand() % SCREEN_HEIGHT;
	pThreat->setRect(SCREEN_WIDTH + (index+1) * rng_y, rng_y);
	pThreat->set_x_delta(2 + SPEED_BACKGROUND);

}




void createListThreatObjects(vector<ThreatObject*> &listThreats, const int &level, int &numThreats)
{
	//vector<ThreatObject*> listThreats;
	int num0, num1, num2, num3;
	switch (level)
	{
	case 1: num0 = 3;	num1 = 1; num2 = 1; num3 = 0;	break;
	case 2: num0 = 1;	num1 = 2; num2 = 2; num3 = 0;	break;
	case 3: num0 = 0;	num1 = 2; num2 = 2; num3 = 1;	break;
	case 4: num0 = 0;	num1 = 2; num2 = 1; num3 = 2;	break;
	default:
		break;
	}
	
	for (int i = 0; i < num0; i++)
	{
		ThreatObject *pThreat = new ThreatObject;
		createThreat(pThreat, 0, i);
		listThreats.push_back(pThreat);
	
	}
	for (int i = 0; i < num1; i++)
	{
		ThreatObject *pThreat = new ThreatObject;
		createThreat(pThreat, 1, i);
		listThreats.push_back(pThreat);

	}
	for (int i = 0; i < num2; i++)
	{
		ThreatObject *pThreat = new ThreatObject;
		createThreat(pThreat, 2, i);
		listThreats.push_back(pThreat);
		
	}
	for (int i = 0; i < num3; i++)
	{
		ThreatObject *pThreat = new ThreatObject;
		createThreat(pThreat, 3, i);
		listThreats.push_back(pThreat);
	
	}
	numThreats = listThreats.size();
	// return listThreats;
}


void destroyThreatObjects(vector<ThreatObject*> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->rect_.x <= 0 || list[i]->rect_.x >= SCREEN_WIDTH ||
			list[i]->rect_.y <= 0 || list[i]->rect_.y >= SCREEN_HEIGHT)
		{			
			swap(list[i], list[list.size() - 1]);	
			list.pop_back();		
			
		}
	}
}



void createBoss(ThreatObject* &pBoss, const int &type)
{
	int width, height;
	switch (type)
	{
	case 4:
		width = WIDTH_BOSS_4;	height = HEIGHT_BOSS_4;
		pBoss->loadImgObject("boss_4.png");
		//pThreat->_blood = 1;
		break;
	case 5:
		width = WIDTH_BOSS_5;	height = HEIGHT_BOSS_5;
		pBoss->loadImgObject("boss_5.png");
		//pThreat->_blood = 1;
		break;
	case 6:
		width = WIDTH_BOSS_6;	height = HEIGHT_BOSS_6;
		pBoss->loadImgObject("boss_6.png");
		//pThreat->_blood = 1;
		break;
	
	default:
		break;
	}
	
	pBoss->rect_.w = width;
	pBoss->rect_.h = height;
	pBoss->_threat_type = type;


	int rng_y = rand() % SCREEN_HEIGHT;
	pBoss->setRect(SCREEN_WIDTH + 2 * rng_y, rng_y);
	pBoss->set_x_delta(2 + SPEED_BACKGROUND);

}



void createSubBoss(ThreatObject* &pSubBoss, ThreatObject* &pBoss)
{
	
	pSubBoss->loadImgObject("sub_boss.png");
	pSubBoss->rect_.w = WIDTH_SUB_BOSS;
	pSubBoss->rect_.h = HEIGHT_SUB_BOSS;
	pSubBoss->_threat_type = 10;
	//pThreat->_blood = 1;

	
	pSubBoss->setRect(pBoss->rect_.x - pBoss->rect_.w / 5, pBoss->rect_.y + pBoss->rect_.h / 2);
	pSubBoss->set_x_delta(1 + SPEED_BACKGROUND);
	pSubBoss->set_y_delta(1);
}




