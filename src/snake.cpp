#include "snake.h"

Snake::Snake()
: x_ (300),
  y_ (300),
  length_ (0),
  size_ (50)
{ }

void Snake::draw(SDL_Renderer* gRenderer) {
	SDL_Rect fillRect;
	for (int i = 0; i < this->length_+1; i++) {
		fillRect = {this->x_, this->y_, this->size_, this->size_ };
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(gRenderer, &fillRect);
	}
}

void Snake::move(int direction) {
	//update position so constantly moving based on direction
	switch (direction) {
		case 0:
			if (this->y_ > 0) {
				this->y_ -= this->size_;
			}
			break;

		case 1:
			if (this->y_ < 700) {
				this->y_ += this->size_;
			}
			break;

		case 2:
			if (this->x_ > 0) {
				this->x_ -= this->size_;
			}
			break;

		case 3:
			if (this->x_ < 700) {
				this->x_ += this->size_;
			}
			break;
		
		default:
			break;
	}
}
