#include "stdafx.h"
#include "GraphicsObject.h"


GraphicsObject::GraphicsObject(Point position)
{
	m_Position = position;
}


Point GraphicsObject::getPosition(void) const
{
	return m_Position;
}

void GraphicsObject::setPosition(const Point &point)
{
	m_Position = point;
}

