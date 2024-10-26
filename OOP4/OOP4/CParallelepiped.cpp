#include "CParallelepiped.h";

CParallelepiped::CParallelepiped(double density, double height, double width, double depth)
    : m_height(height), m_width(width), m_depth(depth), CBody("Parallelepiped", density)
{
}

double CParallelepiped::GetHeight() const
{
    return m_height;
}

double CParallelepiped::GetWidth() const
{
    return m_width;
}

double CParallelepiped::GetDepth() const
{
    return m_depth;
}

double CParallelepiped::GetVolume() const 
{
    return m_height * m_width * m_depth;
}

void CParallelepiped::AppendProperties(std::ostream &strm) const 
{
    strm << "\theight = " << GetHeight() << std::endl
    << "\twidth = " << GetWidth() << std::endl
    << "\tdepth = " << GetDepth() << std::endl;
}