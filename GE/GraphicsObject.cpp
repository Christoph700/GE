#include "stdafx.h"
#include "GraphicsObject.h"


GraphicsObject::GraphicsObject(uint32_t x, uint32_t y)
{
	m_X = x;
	m_Y = y;
}


GraphicsObject::~GraphicsObject()
{
}

uint32_t GraphicsObject::getX(void) const
{
	return m_X;
}

uint32_t GraphicsObject::getY(void) const
{
	return m_Y;
}
