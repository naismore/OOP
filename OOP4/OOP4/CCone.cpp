#include "CCone.h"

CCone::CCone(double density, double baseRadius, double height) : m_baseRadius(baseRadius), m_height(height), CBody("Cone", density) {};

double CCone::GetBaseRadius() const
{
    return m_baseRadius;
}

double CCone::GetHeight() const
{
    return m_height;
}

double CCone::GetVolume() const
{
    return (pow(m_baseRadius, 2) * M_PI * m_height) * 1 / 3;
}

void CCone::AppendProperties(std::ostream &strm) const
{
    strm << "\tbase radius = " << GetBaseRadius() << std::endl
    << "\theight = " << GetHeight() << std::endl;
}
