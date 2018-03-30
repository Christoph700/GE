#include "stdafx.h"
#include "GraphicsObject.h"


GraphicsObject::GraphicsObject(Point position)
{
	m_position = position;
}


Point GraphicsObject::getPosition(void) const
{
	return m_position;
}

