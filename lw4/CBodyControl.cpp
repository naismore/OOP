#include "CBody.h"
#include "CBodyControl.h"
#include <sstream>
#include <string>

CBodyControl::CBodyControl(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodiesVector)
  : m_input(input)
  , m_output(output)
  , m_bodiesVector(bodiesVector)
  , m_actionMap({ { "Info", bind(&CBodyControl::InfoAboutAllBodies, this, std::placeholders::_1) },
      { "AddBody", bind(&CBodyControl::AddBody, this, std::placeholders::_1) },
      { "GetBodyWithBiggestMass", std::bind(&CBodyControl::GetBodyWithBiggestMass, this) },
      { "GetLightestBodyInWater", std::bind(&CBodyControl::GetLightestBodyInWater, this) } })
{
}

bool CBodyControl::HandleCommand()
{
  std::string commandLine;
  getline(m_input, commandLine);
  std::istringstream strm(commandLine);

  std::string action;
  strm >> action;
  auto it = m_actionMap.find(action);
  if (it != m_actionMap.end())
  {
    return it->second(strm);
  }

  return false;
}


bool CBodyControl::HandleCommand()
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CBodyControl::AddBody(std::istream& args)
{
	return false;
}


bool CBodyControl::GetBodyWithBiggestMass(std::istream& args)
{
	double maxMass = 0;
	int indexOfBodyWithBiggestMass = 0;
	for (int i = 0; i < m_bodiesVector.size(); i++)
	{
		
	}
}

bool CBodyControl::GetLightestBodyInWater(std::istream& args)
{
	return false;
}

bool CBodyControl::InfoAboutAllBodies(std::istream& args)
{
	return false;
}
