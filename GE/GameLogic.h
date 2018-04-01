#pragma once

#include <vector>
#include <memory>

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
	std::vector<std::shared_ptr<GraphicsObject>> graphicObjects;
	SDL_Renderer* renderer;
};

