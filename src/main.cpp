#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

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

int main(int argc, char* args[]) {
	if (!init()) {
		std::cout << "Failed to init!" << std::endl;
	}
	else {
		SDL_Event e; 
		bool quit = false; 
		
		while(!quit) { 
			while( SDL_PollEvent( &e ) != 0 ){ 
				if( e.type == SDL_QUIT ) quit = true; 
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(gRenderer);	
				
			SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
			SDL_RenderFillRect(gRenderer, &fillRect);

			SDL_RenderPresent(gRenderer);
		}
	}

	close();

	return 0;
}
