#include "CTVSetControl.h"
#include "CTVSet.h"
#include <sstream>
#include <string>

using namespace std;
using namespace placeholders;

CTVSetControl::CTVSetControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap(
		{
			{"TurnOff", bind(&CTVSetControl::TurnOff, this, placeholders::_1)},
			{"TurnOn", bind(&CTVSetControl::TurnOff, this, _1)}
		}
		)
{

}

bool CTVSetControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CTVSetControl::TurnOn(std::istream& /*args*/)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CTVSetControl::TurnOff(std::istream& /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}
