#pragma once
#include "CBody.h"
class CSphere final : public CBody
{
public:
    CSphere(double density, double radius);
    double GetVolume() const override;
    double GetRadius() const;

private:
    void AppendProperties(std::ostream &strm) const override;
    double m_radius;
};
