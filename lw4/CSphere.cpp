#include "CSphere.h"
#include <cmath>

CSphere::CSphere(double radius, double density)
{
	m_radius = radius;
	m_density = density;
}

double CSphere::GetVolume()
{
	return (4 * 3.14 * pow(m_radius, 3)) / 3;
}
double CSphere::GetDensity() 
{
	return m_density;
}
double CSphere::GetRadius()
{
	return m_radius;
}
double CSphere::GetMass()
{
	return GetVolume() * m_density;
}