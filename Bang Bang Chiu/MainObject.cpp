#include"MainObject.h"

MainObject mainObject;




void MainObject::setAmoList(vector<AmoObject*> amoList) { _pAmoList = amoList; }

vector<AmoObject*> MainObject::getAmoList() const { return _pAmoList; }

MainObject::MainObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	_xVal = 0;
	_yVal = 0;
	_type = LEVEL_1;
}
MainObject::~MainObject() {

}

void MainObject::handleInput(SDL_Event& events, int& rocket_num, int& blood_num, int& DAME_OF_MAIN) {
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			if (this->getType() == LEVEL_1) _yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			else _yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_DOWN: {
			if (this->getType() == LEVEL_1) _yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			else _yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_LEFT: {
			if (this->getType() == LEVEL_1) _xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
			else _xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_RIGHT: {
			if (this->getType() == LEVEL_1) _xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
			else _xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_SPACE: {
			if (this->getType() == LEVEL_1) {
				DAME_OF_MAIN = 1;
				AmoObject* pAmo = new AmoObject();
				pAmo->setWidthHeight(WIDTH_BULLET, HEIGHT_BULLET);
				pAmo->loadImgObject("./image/bullet.png");
				pAmo->setType(AmoObject::BULLET);

				Mix_PlayChannel(-1, g_sound_bullet[0], 0);

				pAmo->setRect(this->rect_.x + this->rect_.w, this->rect_.y + this->rect_.h * 0.5);
				pAmo->setIsMove(true);
				pAmo->setX_Val(AMO_MAIN_SPEED);
				_pAmoList.push_back(pAmo);
			}
			else {
				DAME_OF_MAIN = 5;
				AmoObject* pAmo = new AmoObject();
				pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
				pAmo->loadImgObject("./image/lazer.png");
				pAmo->setType(AmoObject::LAZER);
				Mix_PlayChannel(-1, g_sound_bullet[0], 0);
				

				pAmo->setRect(this->rect_.x + WIDTH_MAIN_OBJECT_LV2, this->rect_.y + 5);
				pAmo->setIsMove(true);
				pAmo->setX_Val(AMO_MAIN_SPEED*3);
				_pAmoList.push_back(pAmo);
			}
			break;
		}
		case SDLK_e: {
			if (rocket_num > 0) {
				if (this->getType() == LEVEL_1) {
					DAME_OF_MAIN = 1;
					AmoObject* pAmo = new AmoObject();
					pAmo->setWidthHeight(WIDTH_ROCKET, HEIGHT_ROCKET);
					pAmo->loadImgObject("./image/rocket.png");
					pAmo->setType(AmoObject::ROCKET);

					Mix_PlayChannel(-1, g_sound_bullet[1], 0);

					pAmo->setRect(this->rect_.x + this->rect_.w, this->rect_.y * 0.9);
					pAmo->setIsMove(true);
					pAmo->setX_Val(AMO_MAIN_SPEED);
					_pAmoList.push_back(pAmo);
				}
				else {
					DAME_OF_MAIN = 1;
					AmoObject* pAmo = new AmoObject();
					pAmo->setWidthHeight(WIDTH_ULTI_LV2, HEIGHT_ULTI_LV2);
					pAmo->loadImgObject("./image/unti_lv2.png");
					pAmo->setType(AmoObject::ROCKET);
					Mix_PlayChannel(-1, g_sound_bullet[1], 0);
					

					pAmo->setRect(this->rect_.x, this->rect_.y * 0.9);
					pAmo->setIsMove(true);
					pAmo->setX_Val(AMO_MAIN_SPEED);
					_pAmoList.push_back(pAmo);
				}
				rocket_num--;
			}
			break;
		}
		case SDLK_r: {
			//++++++++++++++++++++++++++++++++++++++++++++++++
			//if (blood_num > 0) {
			//	//do some thing
			//}
			break;
		}
		}
	}
	else if (events.type == SDL_KEYUP) {
	switch (events.key.keysym.sym) {
	case SDLK_UP: {
		if (this->getType() == LEVEL_1) _yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
		else _yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
		break;
	} case SDLK_DOWN: {
		if (this->getType() == LEVEL_1) _yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
		else _yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
		break;
	} case SDLK_LEFT: {
		if (this->getType() == LEVEL_1) _xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
		else _xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
		break;
	} case SDLK_RIGHT: {
		if (this->getType() == LEVEL_1) _xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
		else _xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
		break;
	}
	}
	}
}

void MainObject::makeAmo(SDL_Surface* g_Something) {
	for (int i = 0; i < _pAmoList.size(); i++) {
		AmoObject* p_amo = _pAmoList.at(i);
		if (p_amo) {
			if (p_amo->getIsMove()) {
				p_amo->showObject(g_Something);
				p_amo->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else {
				_pAmoList.erase(_pAmoList.begin() + i);
				// free amo
				AmoObject::freeAmo(p_amo);
			}
		}
	}
}

void MainObject::handleMove() {
	rect_.x += _xVal;
	if (this->getType() == LEVEL_1) {
		if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) rect_.x -= _xVal;
		rect_.y += _yVal;
		if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) rect_.y -= _yVal;
	}
	else {
		if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT_LV2 > SCREEN_WIDTH) rect_.x -= _xVal;
		rect_.y += _yVal;
		if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT_LV2 > SCREEN_HEIGHT) rect_.y -= _yVal;
	}
	return;
}

void MainObject::removeAmo(const int& index) {
	for (int i = 0; i < _pAmoList.size(); i++)
		if (index < _pAmoList.size()) {
			AmoObject* p_amo = _pAmoList.at(index);
			_pAmoList.erase(_pAmoList.begin() + index);
			if (p_amo) {
				delete p_amo;
				p_amo = NULL;
			}
		}
	return;
}




//--------------------------------------------------------------------------//

bool MainFunc::prepareMain()
{
	mainObject.setRect(100, SCREEN_HEIGHT / 2);
	mainObject.setXY_Val(0, 0);
	bool ret = mainObject.loadImgObject("./image/main.png");					//main
	if (!ret)
	{
		return false;
	}
	return true;
}