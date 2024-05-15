#pragma once
#include "CBody.h"

class CSphere : public CBody
{
public:
	CSphere(double radius, double density);
	double GetVolume() override;
	double GetRadius();
private:
	void AppendProperties(std::ostream& strm) override;
	double m_radius;
};

