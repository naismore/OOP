#include "CVector3D.h"

CVector3D::CVector3D()
	: x(0)
	, y(0)
	, z(0) {};
CVector3D::CVector3D(double x0, double y0, double z0)
	: x(x0)
	, y(y0)
	, z(z0) {};

double CVector3D::GetLength() const
{
	return std::sqrt(x * x + y * y + z * z);
}

void CVector3D::Normalize()
{
	double length = GetLength();
	if (length > 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

CVector3D CVector3D::operator+(CVector3D& other) const
{
	return CVector3D(x + other.x, y + other.y, z + other.z);
}

CVector3D CVector3D::operator+() const
{
	return *this;
}

CVector3D CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D CVector3D::operator-(CVector3D& other) const
{
	return CVector3D(x - other.x, y - other.y, z - other.z);
}

std::ostream& operator<<(std::ostream& os, const CVector3D& vec)
{
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z;
	return os;
}

std::istream& operator>>(std::istream& is, CVector3D& vec)
{
	is >> vec.x >> vec.y >> vec.z;
	return is;
}

CVector3D& CVector3D::operator+=(const CVector3D& other)
{
	double lengthOther = other.GetLength();
	this->x += lengthOther * (other.x / other.GetLength());
	this->y += lengthOther * (other.y / other.GetLength());
	this->z += lengthOther * (other.z / other.GetLength());

	return *this;
}

CVector3D CVector3D::operator*(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D operator*(double scalar, CVector3D& vec)
{
	return vec * scalar;
}

CVector3D CVector3D::operator/(double scalar) const
{
	if (scalar == 0)
	{
		throw std::invalid_argument("Division by zero");
	}
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D& CVector3D::operator*=(double scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
	if (scalar == 0)
	{
		throw std::invalid_argument("Division by zero");
	}
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return *this;
}

bool CVector3D::operator==(const CVector3D& other) const
{
	return (std::fabs(this->x - other.x) < DBL_EPSILON && std::fabs(this->y - other.y) < DBL_EPSILON && std::fabs(this->z - other.z) < DBL_EPSILON);
}

bool CVector3D::operator!=(const CVector3D& other) const
{
	return !(*this == other);
}