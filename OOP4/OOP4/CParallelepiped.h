#pragma once
#include "CBody.h"

class CParallelepiped final : public CBody
{
public:
    CParallelepiped(double density, double height, double width, double depth);
    double GetVolume() const override;
    double GetHeight() const;
    double GetWidth() const;
    double GetDepth() const;

private:
    void AppendProperties(std::ostream &strm) const override;
    double m_density;
    double m_height;
    double m_width;
    double m_depth;
};