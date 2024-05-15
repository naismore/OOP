#pragma once
#include <iostream>
class CBody
{
public:

	CBody(const std::string& type, double density);

	double GetDensity();
	virtual double GetVolume() = 0;
	double GetMass();
	std::string ToString();
private:
	virtual void AppendProperties(std::ostream& strm) = 0;
	double m_density;
	std::string m_type;
};

