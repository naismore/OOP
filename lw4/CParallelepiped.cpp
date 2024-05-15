#include "CParallelepiped.h"



CParallelepiped::CParallelepiped(double width, double height, double depth, double density) : CBody("Parallelepiped", density), m_depth(depth), m_width(width), m_height(height)
{
}

double CParallelepiped::GetVolume()
{
	return m_width * m_height * m_depth;
}

double CParallelepiped::GetWidth()
{
	return m_width;
}

double CParallelepiped::GetHeight()
{
	return m_height;
}

double CParallelepiped::GetDepth()
{
	return m_depth;
}

