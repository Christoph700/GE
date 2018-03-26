#pragma once

#include "GraphicsObject.h"

class Ball : public GraphicsObject
{
public:
	Ball(Point position);
	~Ball();

	void render(SDL_Renderer* renderer) override;

};

