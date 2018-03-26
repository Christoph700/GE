#pragma once

#include "Point.h"

class SDL_Renderer;

class GraphicsObject
{
public:
	GraphicsObject(Point position);
	~GraphicsObject();

	virtual void render(SDL_Renderer* renderer) = 0;
	Point getPosition(void) const;

private:
	Point m_position;
};

