#include "include/SDL.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 760;


void printRect(int posX, int posY, SDL_Renderer* renderer) 
{
	SDL_Rect square = { posX, posY, 150, 150 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &square);
}


int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	SDL_Window* window = SDL_CreateWindow("My first Screen",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	
	bool exit = false; 
	SDL_Event e; 
	int posX = 400, posY = 250;	
	int speed = 10; 
	
	
	while (!exit) 
	{	
		while (SDL_PollEvent(&e) != 0) 
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit = true;
			
			int limX = (posX < 0);
			int limX1 = (posX >= SCREEN_WIDTH - 150);
			int limY = (posY < 0);
			int limY1 = (posY >= SCREEN_HEIGHT - 150);
			

			if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym==SDLK_w) && !limY)
			{
				posY -= speed;
			}
			if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s) && !limY1)
			{
				posY += speed;
			}
			if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d) && !limX1)
			{
				posX += speed;
			}
			if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a) && !limX)
			{
				posX -= speed;
			}
		}
	
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		printRect(posX, posY,renderer); 
		SDL_RenderPresent(renderer);

	}
	SDL_Quit();
	
	system("pause");
	return EXIT_SUCCESS;
}
