#include "stdafx.h"
#include "GameLogic.h"
#include <SDL.h>
#include <iostream>
#include <chrono>
#include "Point.h"
#include "Ball.h"
#include "Vector3D.h"


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
	calculateDeltaTime();


	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	for (auto graphicsObject : graphicObjects)
	{
		auto currentPos = graphicsObject->getPosition();

		Vector3D speed(1, 2, 0);
		Vector3D currentPosition(currentPos.x(), currentPos.y(), 0);
		Vector3D newPosition = currentPosition + (speed * deltaTime);

		graphicsObject->setPosition(Point(newPosition.x(), newPosition.y()));
		graphicsObject->render(renderer);
	}
	SDL_RenderPresent(renderer);
}



void GameLogic::calculateDeltaTime(void)
{
	static std::chrono::steady_clock::time_point lastTimePoint;
	auto currentTimePoint = std::chrono::steady_clock::now();
	deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePoint - lastTimePoint).count();
	lastTimePoint = currentTimePoint;
	//std::cout << "deltaTime: " << deltaTime << std::endl;
}
