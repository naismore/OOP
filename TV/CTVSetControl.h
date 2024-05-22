#pragma once
#include <istream>
#include <functional>
#include <map>

class CTVSet;

class CTVSetControl
{
public:
	CTVSetControl(CTVSet& tv, std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	bool TurnOff(std::istream& args);
	bool TurnOn(std::istream& args);
	bool Info(std::istream& args);
private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	CTVSet& m_tv;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;


};

