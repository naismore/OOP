#include "CCylinder.h"

CCylinder::CCylinder(double density, double baseRadius, double height) : m_baseRadius(baseRadius), m_height(height), CBody("Cylinder", density) {};

double CCylinder::GetBaseRadius() const
{
    return m_baseRadius;
}

double CCylinder::GetHeight() const
{
    return m_height;
}

double CCylinder::GetVolume() const
{
    return pow(m_baseRadius, 2) * M_PI * m_height;
}

void CCylinder::AppendProperties(std::ostream &strm) const
{
    strm << "\tbase radius = " << GetBaseRadius() << std::endl
         << "\theight = " << GetHeight() << std::endl;
}