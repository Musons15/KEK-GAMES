#include "include/SDL.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 760;

#define Laser 50;

void printRect(int posX, int posY, SDL_Renderer* renderer, SDL_Texture*ship)
{
	SDL_Rect square = { posX, posY, 150, 150 };
	//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	//SDL_RenderFillRect(renderer, &square);
	SDL_RenderCopy(renderer, ship, nullptr, &square); 
}


SDL_Texture* ship; 
SDL_Texture* shot; 

int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	SDL_Window* window = SDL_CreateWindow("My first Screen",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);


	SDL_LoadBMP("nau.bmp");
	SDL_LoadBMP("missile.bmp");
	ship = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP ("nau.bmp")); 
	shot = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("missile.bmp"));

	bool exit = false; 
	SDL_Event e; 
	int posX = 400, posY = 250;	
	int speed = 10; 

	bool tecla_up = false; 
	bool tecla_down = false;
	bool tecla_left = false;
	bool tecla_right = false;
	bool tecla_space = false;

	int posBullX=10000;
	int posBullY=10000;
	int current_laser = 0; 

	SDL_Rect LASER[50];

	

	while (!exit) 
	{	
		while (SDL_PollEvent(&e) != 0) 
		{
			if (e.type == SDL_KEYDOWN && e.key.repeat == 0) 
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_UP: tecla_up = true;
						break;
					case SDLK_DOWN: tecla_down = true;
						break;
					case SDLK_LEFT: tecla_left = true;
						break;
					case SDLK_RIGHT: tecla_right = true;
						break;
					case SDLK_SPACE: tecla_space = true;
						break; 
				}
			}
			else if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) exit = true; 
			/*if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit = true;
			
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP && e.key.repeat == 0)
			{
				tecla_up = true; 
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN  && e.key.repeat == 0)
			{
				tecla_down = true; 
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT && e.key.repeat == 0)
			{
				tecla_right = true;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT && e.key.repeat == 0)
			{
				tecla_left = true; 
			}
			
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE && e.key.repeat==0) {
				tecla_space = true; 
			}*/

			if (e.type == SDL_KEYUP) 
			{
				switch (e.key.keysym.sym) 
				{
				case SDLK_UP: tecla_up = false; break; 
				case SDLK_DOWN: tecla_down = false; break; 
				case SDLK_RIGHT: tecla_right = false; break; 
				case SDLK_LEFT: tecla_left = false; break; 
				}
			}
			/*if (e.type == SDL_KEYUP && e.key.keysym.sym==SDLK_UP) tecla_up = false;
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_DOWN) tecla_down = false;
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LEFT) tecla_left = false;
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RIGHT) tecla_right = false;*/

			
		}
		if (posY > 0 && tecla_up) {
			 posY -= 5;
		}
		if ((posY <= SCREEN_HEIGHT-150) && tecla_down) {
			posY += 5;
		}
		if (posX > 0 && tecla_left) {
			posX -= 5;
		}
		if ((posX <= SCREEN_WIDTH -150) && tecla_right) {
			posX += 5;
		}

		

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		

		if (tecla_space)
		{
			tecla_space = false; 
			current_laser++;
			if (current_laser == 50) 
			{
				current_laser = 0;
			}
			LASER[current_laser].x = posX + 75;
			LASER[current_laser].y = posY + 75;
			LASER[current_laser].h = 20;
			LASER[current_laser].w = 20;
		}
		for (int i = 0; i < 50; i++) {
			LASER[i].y -= 10; 
			/*SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &LASER[i]);*/
			SDL_RenderCopy(renderer, shot, nullptr, &LASER[i]);
		}

		printRect(posX, posY,renderer,ship); 
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();
	

	return EXIT_SUCCESS;
}
