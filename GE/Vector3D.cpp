#include "stdafx.h"
#include "Vector3D.h"

Vector3D::Vector3D() : 
	m_X(0), m_Y(0), m_Z(0)
{}

Vector3D::Vector3D(int x, int y, int z) :
	m_X(x), m_Y(y), m_Z(z)
{
}

Vector3D::~Vector3D()
{
}

int Vector3D::x(void) const
{
	return m_X;
}

int Vector3D::y(void) const
{
	return m_Y;
}

int Vector3D::z(void) const
{
	return m_Z;
}

Vector3D Vector3D::operator+(const Vector3D &vector)
{
	return Vector3D(m_X + vector.x(), m_Y + vector.y(), m_Z + vector.z());
}

Vector3D Vector3D::operator*(int scalar)
{
	return Vector3D(m_X * scalar, m_Y * scalar, m_Z * scalar);
}
