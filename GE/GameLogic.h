#pragma once

#include <vector>

class GraphicsObject;
class Point;
struct SDL_Renderer;


class GameLogic
{
public:
	GameLogic(SDL_Renderer* renderer);
	~GameLogic();
	void handleMouseEvent(Point mousePosition);
	void run(void);

private:
	std::vector<GraphicsObject*> graphicObjects;
	SDL_Renderer* renderer;
};

