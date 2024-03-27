//#include <SDL2/SDL.h>
#include <iostream>
#include "snake.h"
#include "apple.h"
#include "LTimer.h"

const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;
const int SCREEN_FPS = 5;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int xPos = 325;
int yPos = 325;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init() {
	bool success = true;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL couldn't init! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			std::cout << "Window couldn't be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				std::cout << "Renderer couldn't be created! SDL_Error: " << SDL_GetError();
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			}
		}
	}

	return success;
}

bool loadMedia() {
	bool success = true;

	return success;
}

void close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
}

bool doCollisions(Snake & s, Apple & a) {
	if (s.x() == a.x() && s.y() == a.y()) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char* args[]) {
	if (!init()) {
		std::cout << "Failed to init!" << std::endl;
	}
	else {
		SDL_Event e; 
		bool quit = false; 

		LTimer fpsTimer;
		LTimer capTimer;

		int countedFrames = 0;
		fpsTimer.start();

		Snake s;
		Apple a;

		bool collision = false;

		s.draw(gRenderer);
		a.draw(gRenderer);
		int direction = 0;
		while(!quit) { 

			capTimer.start();

			while( SDL_PollEvent( &e ) != 0 ){ 

				float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
				if (avgFPS > 2000000) {
					avgFPS = 0;
				}

				if( e.type == SDL_QUIT ) quit = true;
				else if (e.type == SDL_KEYDOWN) {
					switch(e.key.keysym.sym) {
						case SDLK_UP:
							direction = 0;
							break;

						case SDLK_DOWN:
							direction = 1;
							break;

						case SDLK_LEFT:
							direction = 2;
							break;

						case SDLK_RIGHT:
							direction = 3;
							break;
					}
				}
			}

			s.move(direction);

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(gRenderer);	
				
			a.draw(gRenderer);
			s.draw(gRenderer);

			collision = doCollisions(s, a);
			
			if (collision) {
				a.move(s);
				s.incLength();
			}

			SDL_RenderPresent(gRenderer);
			++countedFrames;

			int frameTicks = capTimer.getTicks();
			if (frameTicks < SCREEN_TICKS_PER_FRAME) {
				SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
			}
		}
	}

	close();

	return 0;
}
