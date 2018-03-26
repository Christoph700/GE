#pragma once

#include "GraphicsObject.h"

class Ball : public GraphicsObject
{
public:
	Ball(uint32_t x, uint32_t y);
	~Ball();

	void render(SDL_Renderer* renderer) override;

};

