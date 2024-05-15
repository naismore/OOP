#include "CSphere.h"
#include <cmath>

CSphere::CSphere(double radius, double density) : CBody("Sphere", density), m_radius(radius)
{
}

double CSphere::GetVolume()
{
	return (4 * 3.14 * pow(m_radius, 3)) / 3;
}
double CSphere::GetRadius()
{
	return m_radius;
}

void CSphere::AppendProperties(std::ostream& strm)
{
	strm << "\tradius = " << GetRadius() << std::endl;
}