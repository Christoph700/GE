#include "stdafx.h"
#include "Ball.h"
#include <SDL.h>


Ball::Ball(uint32_t x, uint32_t y) : GraphicsObject(x, y)
{
}


Ball::~Ball()
{
}


void Ball::render(SDL_Renderer* renderer)
{
	SDL_Rect fillRect;
	fillRect.x = m_X;
	fillRect.y = m_Y;
	fillRect.w = 20;
	fillRect.h = 20;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}


