#include "CBody.h"
#include <sstream>
#include <iomanip> 

CBody::CBody(const std::string& type, double density) : m_density(density), m_type(type)
{

}

double CBody::GetDensity()
{
	return m_density;
}

double CBody::GetMass()
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()
{
	std::ostringstream out;
	out << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(out);
	return out.str();
}
