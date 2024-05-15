#pragma once
#include "CBody.h"
class CCone : CBody
{
public:
	double GetBaseRadius();
	double GetHeight();
private:
	double m_baseRadius;
	double m_height;
};

