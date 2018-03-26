#include "stdafx.h"
#include "Ball.h"
#include <SDL.h>


Ball::Ball()
{
}


Ball::~Ball()
{
}


void Ball::render(SDL_Renderer* renderer)
{
	SDL_Rect fillRect;
	fillRect.x = 10;
	fillRect.y = 10;
	fillRect.w = 100;
	fillRect.h = 100;
	SDL_RenderFillRect(renderer, &fillRect);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
}


