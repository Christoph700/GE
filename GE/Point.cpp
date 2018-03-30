#include "stdafx.h"
#include "Point.h"



Point::Point() : m_X(0), m_Y(0)
{
}

Point::Point(int x, int y) : m_X(x), m_Y(y)
{
}


Point::~Point()
{
}


int Point::x(void) const
{
	return m_X;
}

int Point::y(void) const
{
	return m_Y;
}
