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
	for(auto graphicsObject : graphicObjects)
	{
		//delete graphicsObject;
	}
}


void GameLogic::handleMouseEvent(Point mousePosition)
{
	GraphicsObject *ball = new Ball(mousePosition);
	graphicObjects.push_back(ball);
}

void GameLogic::run(void)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	for (auto graphicsObject : graphicObjects)
	{
		auto currentPos = graphicsObject->getPosition();
		graphicsObject->setPosition(Point(currentPos.x(), currentPos.y() + 1));
		graphicsObject->render(renderer);
	}

	SDL_RenderPresent(renderer);
}
