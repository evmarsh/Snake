#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>

class Snake {
	public:
		Snake();
		void draw(SDL_Renderer* gRenderer);
		int x();
		int y();
		int length();
		void incLength();
		void setX(int x);
		void setY(int y);
		void move(int direction);
	
	private:
		int x_;
		int y_;
		int length_;
		int size_;
};

#include "snake.inl"

#endif
