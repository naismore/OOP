#include "CSphere.h"

CSphere::CSphere(double density, double radius) : CBody("Sphere", density), m_radius(radius) {};

double CSphere::GetVolume() const
{
    return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

double CSphere::GetRadius() const
{
    return m_radius;
}

void CSphere::AppendProperties(std::ostream &strm) const
{
    strm << "\tradius = " << GetRadius() << std::endl;
}