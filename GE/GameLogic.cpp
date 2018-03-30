#include "stdafx.h"
#include "GameLogic.h"

#include "Point.h"
#include "Ball.h"

GameLogic::GameLogic(SDL_Renderer* renderer) : renderer(renderer)
{
}


GameLogic::~GameLogic()
{
	for (auto graphicsObject : graphicObjects)
	{
		//delete graphicsObject;
	}
}


void GameLogic::handleMouseEvent(Point mousePosition)
{
	GraphicsObject *ball = new Ball(mousePosition);
	graphicObjects.push_back(ball);
	ball->render(renderer);
}
