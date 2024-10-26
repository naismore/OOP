#include "CVector3D.h"

CVector3D::CVector3D() : x(0), y(0), z(0) {};
CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}; 

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

CVector3D CVector3D::operator+(CVector3D &other) const
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

std::ostream &operator<<(std::ostream &os, const CVector3D &vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}