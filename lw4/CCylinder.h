#pragma once
#include "CBody.h"

class CCylinder : public CBody
{
public:
	CCylinder(double baseRadius, double height, double density);
	double GetVolume() override;
	double GetBaseRadius();
	double GetHeight();
private:
	double m_baseRadius;
	double m_height;
};

