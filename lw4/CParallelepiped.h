#pragma once
#include "CBody.h"
class CParallelepiped : CBody
{
public:
	double GetWidth();
	double GetHeight();
	double GetDepth();
private:
	double m_width;
	double m_height;
	double m_depth;
};

