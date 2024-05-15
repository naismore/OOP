#pragma once
#include "CBody.h"
class CParallelepiped : public CBody
{
public:
	CParallelepiped(double width, double height, double depth, double density);
	double GetVolume() override;
	double GetWidth();
	double GetHeight();
	double GetDepth();
private:
	double m_width;
	double m_height;
	double m_depth;
};

