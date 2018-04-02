#pragma once


class Vector3D
{
public:
	Vector3D();
	Vector3D(int x, int y, int z);
	~Vector3D();
	
	int x(void) const;
	int y(void) const;
	int z(void) const;

	Vector3D operator+(const Vector3D &vector);
	Vector3D operator*(int scalar);


private:
	int m_X, m_Y, m_Z;
};

