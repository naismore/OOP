#pragma once
#include "CBody.h"
#include "vector"

class CCompound
{
public:
	bool AddChildBody(CBody& child);
private:
	std::vector<CBody> m_childs;
};

