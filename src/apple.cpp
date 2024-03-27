#include "apple.h"

Apple::Apple()
: size_ (50)
{
	init();
}

void Apple::init() {
	int randX = 0;
	int randY = 0;
	std::srand(std::time(nullptr));
	
	bool notDone = true;

	while(notDone) {
		//generate a rand num between 1 and 15 then multiply by 50 so apple is in line with snake
		randX = (1 + std::rand() / ((RAND_MAX + 1u) / 15)) * 50;
		randY = (1 + std::rand() / ((RAND_MAX + 1u) / 15)) * 50;

		//make sure apple isn't on snake
		if (randX != 300 && randY != 300) {
			notDone = false;
		}
	}

	this->setX(randX);
	this->setY(randY);
}

void Apple::draw(SDL_Renderer* gRenderer) {
	SDL_Rect fillRect = {this->x_, this->y_, this->size_, this->size_ };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);
}

void Apple::move(Snake &s) {
	int randX = 0;
	int randY = 0;
	std::srand(std::time(nullptr));
	
	bool notDone = true;

	while(notDone) {
		//generate a rand num between 1 and 15 then multiply by 50 so apple is in line with snake
		randX = (1 + std::rand() / ((RAND_MAX + 1u) / 15)) * 50;
		randY = (1 + std::rand() / ((RAND_MAX + 1u) / 15)) * 50;

		//make sure apple isn't on snake
		if (randX != s.x() && randY != s.y()) {
			notDone = false;
		}
	}

	this->setX(randX);
	this->setY(randY);
}
