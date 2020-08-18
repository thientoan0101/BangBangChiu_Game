#include"MainObject.h"

// constructor
// initialize position of main
MainObject::MainObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	_xVal = 0;
	_yVal = 0;
}

// destructor
MainObject::~MainObject(){
	// do something
}

void MainObject::setType(const int& type) { _mainType = type; }

// handle user input
void MainObject::handleInput(SDL_Event events) {
	// get key from keyboard
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym) {
		//move up
		case SDLK_UP: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		} 
		//move down
		case SDLK_DOWN: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		} 
		//move left
		case SDLK_LEFT: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		} 
		//move right
		case SDLK_RIGHT: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		}
		}
	}
	// when user do not push
	else if (events.type == SDL_KEYUP) {
		// all of these to keep the position of main
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_DOWN: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_LEFT: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		} case SDLK_RIGHT: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		}
		}
	}
	// when get mouse event main can fire
	else if (events.type == SDL_MOUSEBUTTONDOWN) {
		
		// create an amo
		AmoObject* pAmo = new AmoObject();
		
		// button left pushed main can fire
		if (events.button.button == SDL_BUTTON_LEFT) {
			// set width and height of amo
			pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			// load image of amo
			pAmo->loadImg("laser2.png");
			// set type of amo
			pAmo->setType(AmoObject::LAZER);
		}
		// set rect of amo
		pAmo->setRect(this->rect_.x + this->rect_.w * 0.7, this->rect_.y + this->rect_.h * 0.02);
		// let amo move
		pAmo->setIsMove(true);
		// set speed of amo
		pAmo->setX_Val(20);
		// push new amo to listAmo
		_pAmoList.push_back(pAmo);
	}
}

// handle moves of mainObject when user input from keyboard
void MainObject::handleMove() {
	rect_.x += _xVal;
	// if main position out of range of screen this line make it till on screen range
	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) rect_.x -= _xVal;
	rect_.y += _yVal;
	// if main position out of range of screen this line make it till on screen range
	if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) rect_.y -= _yVal;
}

// an amolist ready for war
void MainObject::setAmoList(vector<AmoObject*> amoList) { _pAmoList = amoList; }

// get list of amo after handled by using function (setAmoList)
vector<AmoObject*> MainObject::getAmoList() const { return _pAmoList; }

// create an amo
void MainObject::makeAmo(SDL_Surface* g_something) {
	for (int i = 0; i < _pAmoList.size(); i++) {
		// p_amo point to an amo at position i in listAmo
		AmoObject* p_amo = _pAmoList.at(i);
		// make sure that p_amo can create and have no bug
		if (p_amo) {
			// check amo still moving
			if (p_amo->getIsMove()) {
				// if amo is moving, show amo on the screen
				p_amo->show(g_Something);
				// let amo move
				p_amo->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}

			// if amo doesn't move mean when it come out of screen
			else {
				// delete amo come out of screen
				_pAmoList.erase(_pAmoList.begin() + i);
				// free amo
				delete p_amo;
			}
		}
	}
}

// delete an amo
void MainObject::removeAmo(const int& index) {
	// this function use to delete amolist
	for (int i = 0; i < _pAmoList.size(); i++)
		if (index < _pAmoList.size()) {
			// delete each element of list
			AmoObject* p_amo = _pAmoList.at(index);
			_pAmoList.erase(_pAmoList.begin() + index);
			// if p_amo != null, detele it
			if (p_amo) {
				delete p_amo;
				p_amo = NULL;
			}
		}
}