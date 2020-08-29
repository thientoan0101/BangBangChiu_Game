#include"MainObject.h"

<<<<<<< Updated upstream
// constructor
// initialize position of main
=======
void MainObject::setAmoList(vector<AmoObject*> amoList) { _pAmoList = amoList; }

vector<AmoObject*> MainObject::getAmoList() const { return _pAmoList; }

>>>>>>> Stashed changes
MainObject::MainObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	_xVal = 0;
	_yVal = 0;
}
MainObject::~MainObject() {

<<<<<<< Updated upstream
// destructor
MainObject::~MainObject(){
	// do something
}

//set type of mainObject
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
		case SDLK_w: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		}
					//move down
		case SDLK_s: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		}
					  //move left
		case SDLK_a: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		}
					  //move right
		case SDLK_d: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		}
		// normal fire
		case SDLK_SPACE: {
			// create an amo
			AmoObject* pAmo = new AmoObject();

			// button left pushed main can fire
			// set width and height of amo
			pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			// load image of amo
			pAmo->loadImgObject("laser.png");
			// set type of amo
			pAmo->setType(AmoObject::LAZER);
			// set rect of amo
			pAmo->setRect(this->rect_.x + this->rect_.w * 0.7, this->rect_.y + this->rect_.h * 0.02);
			// let amo move
			pAmo->setIsMove(true);
			// set speed of amo
			pAmo->setX_Val(20);
			// push new amo to listAmo
			_pAmoList.push_back(pAmo);
		}
		// rocket fire
		case SDLK_e: {
			//// create an amo
			//AmoObject* pAmo = new AmoObject();

			//// button left pushed main can fire
			//// set width and height of amo
			//pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			//// load image of amo
			//pAmo->loadImgObject("laser2.png");
			//// set type of amo
			//pAmo->setType(AmoObject::LAZER);
			//// set rect of amo
			//pAmo->setRect(this->rect_.x + this->rect_.w * 0.7, this->rect_.y + this->rect_.h * 0.02);
			//// let amo move
			//pAmo->setIsMove(true);
			//// set speed of amo
			//pAmo->setX_Val(20);
			//// push new amo to listAmo
			//_pAmoList.push_back(pAmo);
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
		case SDLK_w: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_s: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_a: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		} case SDLK_d: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		}
		}
	}
}

// handle moves of mainObject when main out of range of screen
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
				p_amo->showObject(g_something);
				// let amo move
				p_amo->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}

			// if amo doesn't move mean when it come out of screen
			else {
				// delete amo come out of screen
				_pAmoList.erase(_pAmoList.begin() + i);
				// free amo
				delete p_amo;
=======
}

void MainObject::handleInput(SDL_Event events/*, Mix_Chunk* bullet_sound[NUM_AUDIO_EXPLOSION]*/) {
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			_yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_DOWN: {
			_yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_LEFT: {
			_xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_RIGHT: {
			_xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_SPACE: {
			/*AmoObject* pAmo = new AmoObject();
			pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			pAmo->loadImg("laser2.png");
			pAmo->setType(AmoObject::LAZER);

			Mix_PlayChannel(-1, bullet_sound[0], 0);

			pAmo->setRect(this->rect_.x + this->rect_.w * 0.7, this->rect_.y + this->rect_.h * 0.02);
			pAmo->setIsMove(true);
			pAmo->setX_Val(AMO_MAIN_SPEED);
			_pAmoList.push_back(pAmo);*/



			AmoObject* pAmo = new AmoObject();
			pAmo->setWidthHeight(WIDTH_BLUE_SLASH, HEIGHT_BLUE_SLASH);
			pAmo->loadImgObject("blue_slash.png");
			pAmo->setType(AmoObject::BLUE_SLASH);

			/*Mix_PlayChannel(-1, bullet_sound[0], 0);*/

			pAmo->setRect(this->rect_.x + this->rect_.w * 0.7, this->rect_.y + this->rect_.h * 0.02);
			pAmo->setIsMove(true);
			pAmo->setX_Val(AMO_MAIN_SPEED);
			_pAmoList.push_back(pAmo);
		}
		}
	}
	else if (events.type == SDL_KEYUP) {
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			_yVal += HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_DOWN: {
			_yVal -= HEIGHT_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_LEFT: {
			_xVal += WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		} case SDLK_RIGHT: {
			_xVal -= WIDTH_MAIN_OBJECT / MAIN_SPEED;
			break;
		}
		}
	} /*else if (events.type == SDL_MOUSEBUTTONDOWN) {
		AmoObject* pAmo = new AmoObject();
		if(events.button.button == SDL_BUTTON_LEFT){
			pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			pAmo->loadImg("laser2.png");
			pAmo->setType(AmoObject::LAZER);
		}
		pAmo->setRect(this->rect_.x + this->rect_.w *0.7, this->rect_.y + this->rect_.h * 0.02);
		pAmo->setIsMove(true);
		pAmo->setX_Val(20);
		_pAmoList.push_back(pAmo);
	}*/
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
>>>>>>> Stashed changes
			}
		}
	}
}

<<<<<<< Updated upstream
// create mainObject
void createMainObject(MainObject& mainObject) {
	mainObject.setRect(100, SCREEN_HEIGHT / 2);
	bool ret = mainObject.loadImgObject("main.png");
	if (!ret) return;
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
=======
void MainObject::handleMove() {
	rect_.x += _xVal;
	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) rect_.x -= _xVal;
	rect_.y += _yVal;
	if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) rect_.y -= _yVal;
}

void MainObject::removeAmo(const int& index) {
	for (int i = 0; i < _pAmoList.size(); i++)
		if (index < _pAmoList.size()) {
			AmoObject* p_amo = _pAmoList.at(index);
			_pAmoList.erase(_pAmoList.begin() + index);
>>>>>>> Stashed changes
			if (p_amo) {
				delete p_amo;
				p_amo = NULL;
			}
		}
}