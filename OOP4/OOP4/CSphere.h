#pragma once
#include "CBody.h"
class CSphere : public CBody
{
public:
    CSphere(const double radius);
    double GetVolume() const override;
    double GetMass() const override;
    double GetDensity() const override;
    double GetRadius() const;
    std::string ToString() const override;

private:
    double m_radius;
};
