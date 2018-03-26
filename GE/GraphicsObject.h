#pragma once

#include <cstdint>

class SDL_Renderer;

class GraphicsObject
{
public:
	GraphicsObject();
	~GraphicsObject();

	virtual void render(SDL_Renderer* renderer) = 0;
	uint32_t getX(void) const;
	uint32_t getY(void) const;

private:
	uint32_t m_X;
	uint32_t m_Y;
};

