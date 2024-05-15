#include "CCylinder.h"
#include <cmath>

CCylinder::CCylinder(double baseRadius, double height, double density) : CBody("Cylinder", density), m_height(height), m_baseRadius(baseRadius)
{

}

double CCylinder::GetVolume()
{
	return 3.14 * pow(m_baseRadius, 2) * m_height;
}

double CCylinder::GetBaseRadius()
{
	return m_baseRadius;
}

double CCylinder::GetHeight()
{
	return m_height;
}