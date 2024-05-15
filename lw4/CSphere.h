#pragma once
#include "CBody.h"

class CSphere : public CBody
{
public:
	CSphere(double radius, double density);
	double GetVolume();
	double GetDensity();
	double GetRadius();
	double GetMass();
private:
	double m_radius;
	double m_density;
};

