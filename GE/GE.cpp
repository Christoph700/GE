// GE.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <SDL.h>
#include "GameLogic.h"
#include "Point.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
GameLogic *gameLogic = NULL;


bool init(void);
void close(void);
void handleMouseEvent(const SDL_Event &e);



int main(int argc, char *args[])
{

	if (!init())
	{
		std::cerr << "init failed" << std::endl;
	}
	else
	{
		SDL_Event e;
		bool quit = false;
		while (!quit)
		{

			if(SDL_PollEvent(&e)) 
			{ 
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					handleMouseEvent(e);
					break;
				default:
					break;
				}
			}

			SDL_Delay(20);
			gameLogic->run();
		}
	}

	close();
    return 0;
}


bool init(void)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		std::cerr << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_HEIGHT, WINDOW_WIDTH, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cerr << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				std::cerr << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				gameLogic = new GameLogic(renderer);
			}
		}
	}
	return success;
}


void close(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window); 
	renderer = NULL;
	window = NULL; 
	SDL_Quit();

	delete gameLogic;
}


void handleMouseEvent(const SDL_Event &e)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	Point mousePos(x, y);
	gameLogic->handleMouseEvent(mousePos);
}

