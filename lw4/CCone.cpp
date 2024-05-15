#include "CCone.h"
#include <cmath>

CCone::CCone(double baseRadius, double height, double density) : CBody("Cone", density), m_baseRadius(baseRadius), m_height(height)
{

}

double CCone::GetBaseRadius()
{
	return m_baseRadius;
}

double CCone::GetHeight()
{
	return m_height;
}

double CCone::GetVolume() 
{
	return (3.14 * pow(m_baseRadius, 2) * m_height) / 3;
}