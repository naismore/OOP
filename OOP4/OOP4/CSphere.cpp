#include "CSphere.h"
#include <string>

CSphere::CSphere(const double radius) : m_radius(radius) {};

double CSphere::GetDensity() const
{
}

double CSphere::GetMass() const
{
}

double CSphere::GetVolume() const
{
}

double CSphere::GetRadius() const
{
}

std::string CSphere::ToString() const
{
    return "Object: Sphere\nRadius: ";
}