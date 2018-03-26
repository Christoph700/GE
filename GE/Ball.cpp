#include "stdafx.h"
#include "Ball.h"
#include <SDL.h>


Ball::Ball(Point position) : GraphicsObject(position)
{
}


Ball::~Ball()
{
}


void Ball::render(SDL_Renderer* renderer)
{
	SDL_Rect fillRect;
	fillRect.x = getPosition().x();
	fillRect.y = getPosition().y();
	fillRect.w = 20;
	fillRect.h = 20;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}


