#include "include/SDL.h"
#include <stdlib.h>

#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 760;


SDL_Window* window = NULL;
SDL_Surface* screen = NULL;


int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("My first Screen",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	

	screen = SDL_GetWindowSurface(window);
		Uint32 bgColor = SDL_MapRGB(screen->format, 255, 0, 0);
		SDL_FillRect(screen, NULL, bgColor);
		SDL_UpdateWindowSurface(window);

		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_Rect square = { 362, 234, 300, 300 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderFillRect(renderer, &square);
		SDL_RenderPresent(renderer);
		SDL_Delay(35000);

	
	SDL_Quit();
	
	system("pause");
	return EXIT_SUCCESS;
}
