#include "MainObject.h"


MainObject::MainObject()
{ 
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;

	x_val_ = 0;
	y_val_ = 0;
}



MainObject::~MainObject()
{
	;
}

void MainObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP: case SDLK_w:
			//todo
			y_val_ -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN: case SDLK_s:
			//todo
			y_val_ += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT: case SDLK_d:
			//todo
			x_val_ += WIDTH_MAIN_OBJECT/4;
			break;
		case SDLK_LEFT: case SDLK_a:
			//todo
			x_val_ -= WIDTH_MAIN_OBJECT / 4;
			break;

		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP: case SDLK_w:
			//todo
			y_val_ += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN: case SDLK_s:
			//todo
			y_val_ -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT: case SDLK_d:
			//todo
			x_val_ -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT: case SDLK_a:
			//todo
			x_val_ += WIDTH_MAIN_OBJECT / 4;
			break;

		default:
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoObject* p_amo = new AmoObject();
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			p_amo->SetWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			p_amo->loadImgObject("laser.png");
			p_amo->set_type(AmoObject::LASER);
			Mix_PlayChannel(-1, g_sound_bullet[0], 0);					// chay ko lap.
		}
		else if (events.button.button == SDL_BUTTON_RIGHT)
		{
			p_amo->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amo->loadImgObject("sphere.png");
			p_amo->set_type(AmoObject::SPHERE);
			Mix_PlayChannel(-1, g_sound_bullet[1], 0);	
		}

		p_amo->setRect(this->rect_.x + WIDTH_MAIN_OBJECT, this->rect_.y + HEIGHT_MAIN_OBJECT / 2);
		p_amo->set_is_move(true);
		p_amo->set_x_val(20);
		p_amo_list.push_back(p_amo);

	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{

	}

}


void MainObject::HandleMove()
{
	rect_.x += x_val_;
	if (rect_.x <0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH)
	{
		rect_.x -= x_val_;
	}

	rect_.y += y_val_;
	if (rect_.y <0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT - 100)
	{
		rect_.y -= y_val_;
	}
}

void MainObject::MakeAmo(SDL_Surface* des)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		AmoObject* p_amo = p_amo_list.at(i);
		if (p_amo != NULL)
		{
			if (p_amo->get_is_move())
			{
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_amo->showObject(des);
			}
			else
			{
				if (p_amo != NULL)
				{
					p_amo_list.erase(p_amo_list.begin() + i);
				 	delete p_amo;
					p_amo = NULL;
				}
			}
		}
	}

}



void MainObject::RemoveAmo(const int &idx)
{
	for (int i = 0; i < p_amo_list.size(); i++)
	{
		if (idx < p_amo_list.size())
		{
			AmoObject* p_amo = p_amo_list.at(idx);
			p_amo_list.erase(p_amo_list.begin() + idx);

			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
	}
}









