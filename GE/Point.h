#pragma once

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int x(void) const;
	int y(void) const;

private:
	int m_X;
	int m_Y;
};

