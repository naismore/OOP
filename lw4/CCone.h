#pragma once
#include "CBody.h"

class CCone : CBody
{
public:
	CCone(double baseRadius, double height, double density);
	double GetVolume() override;
	double GetBaseRadius();
	double GetHeight();
private:
	double m_baseRadius;
	double m_height;
};

