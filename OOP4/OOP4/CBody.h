#pragma once
#include <string>

class CBody
{
public:
	CBody(const double volume, const double density);
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	virtual std::string ToString() const = 0;
};

