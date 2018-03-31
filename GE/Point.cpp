#include "stdafx.h"
#include "Point.h"



Point::Point() : m_X(0), m_Y(0)
{
}

Point::Point(int x, int y) : m_X(x), m_Y(y)
{
}

Point &Point::operator+=(const Point & point)
{
	m_X += point.x();
	m_Y += point.y();
	return *this;
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
