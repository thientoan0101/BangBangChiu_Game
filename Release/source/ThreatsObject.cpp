#include "ThreatsObject.h"


bool activeBoss = false;
bool activeSubBoss = false;


vector<ThreatObject*> listThreats;
vector<ThreatObject*> listSub(2);
ThreatObject* pBoss;
int numThreats;




ThreatObject::ThreatObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT;
	/*rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;*/

	this->setWidthHeight(WIDTH_THREAT_0, HEIGHT_THREAT_0);
	_x_delta = 0;
	_y_delta = 0;
	_active_oscillation = false;
	_step = 0;
	// _blood = 1;
}

ThreatObject::~ThreatObject()
{
	if (_p_amo_list.size() > 0)
	{
		for (int i = 0; i < _p_amo_list.size(); i++)
		{
			AmoObject* p_amo = _p_amo_list.at(i);
			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		_p_amo_list.clear();
	}
}

void ThreatObject::Move()
{
	bool checkOscillation = this->getOscillation();
	if (checkOscillation)
	{
		this->HandleMoveOscilate(SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	else {
		this->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	this->showObject(g_screen);
	this->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
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
		this->set_x_delta(3 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 4:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 5:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
	case 6:
		this->set_x_delta(1 + SPEED_BACKGROUND);		this->set_y_delta(1);	letRunToEnd = false;	break;
	case 7:
		this->set_x_delta(2 + SPEED_BACKGROUND);		this->set_y_delta(2);	letRunToEnd = false;	break;
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
			//srand(time(NULL));
			rect_.y = rand() % SCREEN_HEIGHT - this->rect_.h;
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
	int tempX, tempY;
	//do	{
		tempX = rect_.x;
		tempY = rect_.y;
		if (_step == MAX_STEP)
		{
			int temp = rand() % 2;
			if (temp) _x_delta = -(_x_delta + SPEED_BACKGROUND);
			temp = rand() % 2;
			if (temp) _y_delta = -(_y_delta);
			_step = 0;
		}
		tempX  += _x_delta + SPEED_BACKGROUND;
		tempY += _y_delta;
	//} 
		 if (tempX < SCREEN_WIDTH - rect_.w && tempY > 0 && tempY < (SCREEN_HEIGHT - rect_.h))
		 {
			 rect_.x = tempX;
			 rect_.y = tempY;
		 }
	
	_step++;
	if (rect_.x < 0 || rect_.x > SCREEN_WIDTH || rect_.y < 0 || rect_.y > SCREEN_HEIGHT)
	{
		rect_.x = SCREEN_WIDTH + SCREEN_WIDTH / 10;
		rect_.y = rand() % SCREEN_HEIGHT - this->rect_.h;
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


void ThreatObject::initAmo(AmoObject *p_amo)
{
	bool ret;
	switch (_threat_type)
	{
	case 0:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 1:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 2:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 3:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 4:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 5:
		ret = p_amo->loadImgObject("./image/33.png");
		break;
	case 6:
		ret = p_amo->loadImgObject("./image/31.png");
		break;
	case 10:
		ret = p_amo->loadImgObject("./image/32.png");
		break;
	default:
		break;
	}



	if (p_amo)
	{
	/*	bool ret = p_amo->loadImgObject("sphere2.png");*/
		/*bool ret = p_amo->loadImgObject("33.png");*/
		if (ret)
		{
			p_amo->setIsMove(true);
			p_amo->setWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amo->setType(AmoObject::SPHERE);
			p_amo->setRect(rect_.x, rect_.y + rect_.h*0.5);
			p_amo->setX_Val(AMO_THREAT_SPEED);
			_p_amo_list.push_back(p_amo);
		}
	}
}




void ThreatObject::initAmo_boss(AmoObject* p_amo)
{
	bool ret;
	switch (_threat_type)
	{
	case 4:
		ret = p_amo->loadImgObject("./image/31.png");
		break;
	case 5:
		ret = p_amo->loadImgObject("./image/32.png");
		break;
	case 6:
		ret = p_amo->loadImgObject("./image/34.png");
		break;
	case 7:
		ret = p_amo->loadImgObject("./image/35.png");
		break;
	case 10:
		ret = p_amo->loadImgObject("./image/32.png");
		break;
	default:
		break;
	}



	if (p_amo)
	{
		if (ret)
		{
			p_amo->setIsMove(true);
			p_amo->setWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amo->setType(AmoObject::SPHERE);
			p_amo->setRect(rect_.x, rect_.y + rect_.h * 0.5);
			p_amo->setX_Val(AMO_BOSS_SPEED*2);
			_p_amo_list.push_back(p_amo);
		}
	}
}









void ThreatObject::MakeAmo(SDL_Surface* des, const int &x_limit, const int &y_limit)
{
	for (int i = 0; i < _p_amo_list.size(); i++)
	{
		AmoObject *p_amo = _p_amo_list.at(i);
		if (p_amo)
		{
			if (p_amo->getIsMove())
			{
				p_amo->handleMoveRToL();
				p_amo->showObject(des);
			}
			else
			{
				p_amo->setIsMove(true);
				p_amo->setRect(rect_.x, rect_.y + rect_.h*0.5);
			}
		}
	}
}



void ThreatObject::Reset(const int &xboder)
{
	rect_.x = xboder;
	rect_.y = rand() % SCREEN_HEIGHT - this->rect_.h;

}


void ThreatObject::ResetAmo(AmoObject* p_amo)
{
	p_amo->setRect(rect_.x, rect_.y + rect_.h*0.5);
}


// LEVEL ở đây:
//-----------------------------------------------------------------------------------------
void createThreat(ThreatObject* &pThreat, const int &type, const int &index)
{
	int width = 0, height = 0;
	switch (type)
	{
	case 0:
		width = WIDTH_THREAT_0;	height = HEIGHT_THREAT_0; 
		pThreat->loadImgObject("./image/threat_0.png");			
		break;
	case 1: 
		width = WIDTH_THREAT_1;	height = HEIGHT_THREAT_1;
		pThreat->loadImgObject("./image/threat_1.png");		
		break;
	case 2:
		width = WIDTH_THREAT_2;	height = HEIGHT_THREAT_2;
		pThreat->loadImgObject("./image/threat_2.png");		
		break;
	case 3:
		width = WIDTH_THREAT_3;	height = HEIGHT_THREAT_3;
		pThreat->loadImgObject("./image/threat_3.png");		
		break;
	default:
		break;
	}

	pThreat->rect_.w = width;
	pThreat->rect_.h = height;

	pThreat->_threat_type = type;
	int rng_y = rand() % SCREEN_HEIGHT - height;
	pThreat->setRect(SCREEN_WIDTH + (index+1) * rng_y, rng_y);
	pThreat->set_x_delta(2 + SPEED_BACKGROUND);
	AmoObject *p_amo = new AmoObject();
	pThreat->initAmo(p_amo);
}




void createListThreatObjects(vector<ThreatObject*> &listThreats, const int &level, int &numThreats)
{
	int num0, num1, num2, num3;
	switch (level)
	{	
	case 1: num0 = 1;	num1 = 2; num2 = 2; num3 = 0;	break;
	case 2: num0 = 0;	num1 = 2; num2 = 2; num3 = 1;	break;
	case 3: num0 = 0;	num1 = 2; num2 = 1; num3 = 2;	break;
	case 4: num0 = 0;	num1 = 1; num2 = 2; num3 = 2;	break;
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



void createBoss(ThreatObject* &pBoss, const int &level)
{
	int width, height;
	switch (level)
	{
	case 1:
		width = WIDTH_BOSS_4;	height = HEIGHT_BOSS_4;
		pBoss->loadImgObject("./image/boss_1.png");
		pBoss->_threat_type = 4;
		break;
	case 2:
		width = WIDTH_BOSS_5;	height = HEIGHT_BOSS_5;
		pBoss->loadImgObject("./image/boss_2.png");
		pBoss->_threat_type = 5;
		break;
	case 3:
		width = WIDTH_BOSS_6;	height = HEIGHT_BOSS_6;
		pBoss->loadImgObject("./image/boss_3.png");
		pBoss->_threat_type = 6;
		break;
	case 4:
		width = WIDTH_BOSS_7;	height = HEIGHT_BOSS_7;
		pBoss->loadImgObject("./image/boss_4.png");
		pBoss->_threat_type = 7;
		break;
	default:
		break;
	}
	
	pBoss->rect_.w = width;
	pBoss->rect_.h = height;

	int rng_y = rand() % SCREEN_HEIGHT - height;
	pBoss->setRect(SCREEN_WIDTH + 2 * rng_y, rng_y);
	pBoss->set_x_delta(2 + SPEED_BACKGROUND);
	pBoss->set_y_delta(2);
	AmoObject *p_amo = new AmoObject();
	pBoss->initAmo_boss(p_amo);
}



void createSubBoss(ThreatObject* &pSubBoss, ThreatObject* &pBoss)
{
	pSubBoss->loadImgObject("./image/sub_boss.png");
	pSubBoss->rect_.w = WIDTH_SUB_BOSS;
	pSubBoss->rect_.h = HEIGHT_SUB_BOSS;
	pSubBoss->_threat_type = 10;
	

	pSubBoss->setRect(pBoss->rect_.x - pBoss->rect_.w / 5, pBoss->rect_.y + pBoss->rect_.h / 2);
	pSubBoss->set_x_delta(1 + SPEED_BACKGROUND);
	pSubBoss->set_y_delta(1);
	AmoObject *p_amo = new AmoObject();
	pSubBoss->initAmo(p_amo);
}







//---------------------------------------------------------------------------------------------//

void ThreatFunc::prepareThreats()
{
	pBoss = new ThreatObject;
	createListThreatObjects(listThreats, level, numThreats);
	createBoss(pBoss, level);

	//vector<ThreatObject*> listSub(2);

	for (int i = 0; i < listSub.size(); i++)
	{
		listSub[i] = new ThreatObject;
		createSubBoss(listSub[i], pBoss);
	}


}


void ThreatFunc::freeThreats()
{
	for (int i = 0; i < listThreats.size(); i++)
	{
		delete listThreats[i];
	}
	for (int i = 0; i < listSub.size(); i++)
	{
		delete listSub[i];
	}
	delete pBoss;
}


void ThreatFunc::prepareBoss()
{
	createBoss(pBoss, level);

}