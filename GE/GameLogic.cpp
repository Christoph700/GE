#include "stdafx.h"
#include "GameLogic.h"
#include <SDL.h>
#include "Point.h"
#include "Ball.h"

GameLogic::GameLogic(SDL_Renderer* renderer) : renderer(renderer)
{
}


GameLogic::~GameLogic()
{
}


void GameLogic::handleMouseEvent(Point mousePosition)
{
	graphicObjects.push_back(std::make_shared<Ball>(mousePosition));
}


void GameLogic::run(void)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (auto graphicsObject : graphicObjects)
	{
		auto currentPos = graphicsObject->getPosition();
		graphicsObject->setPosition(currentPos += Point(0, 1));
		graphicsObject->render(renderer);
	}

	SDL_RenderPresent(renderer);
}
