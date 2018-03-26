#include "stdafx.h"
#include "GraphicsObject.h"


GraphicsObject::GraphicsObject()
{
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
