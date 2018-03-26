// GE.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <SDL.h>

#include "Ball.h"
#include "Point.h"


SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

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

			SDL_Delay(10);
			SDL_RenderPresent(renderer);
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
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
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
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(renderer);
			}
		}
	}
	return success;
}


void close(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow( window ); 
	renderer = NULL;
	window = NULL; 
	SDL_Quit(); 
}


void handleMouseEvent(const SDL_Event &e)
{
	//make point class!!
	int x, y;
	SDL_GetMouseState(&x, &y);

	Point mousePos(x, y);
	Ball *ball = new Ball(mousePos);
	ball->render(renderer);
}

