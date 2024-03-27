#ifndef	APPLE_H
#define APPLE_H
#include "snake.h"
#include <cstdlib>
#include <ctime>

class Apple {
	public:
		Apple();
		void init();
		void draw(SDL_Renderer* gRenderer);
		int x();
		int y();
		void setX(int x);
		void setY(int y);
		void move(Snake &s);

	private:
		int x_;
		int y_;
		int size_;
};

#include "apple.inl"

#endif
