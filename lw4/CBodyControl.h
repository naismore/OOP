#pragma once
#include <istream>
#include <functional>
#include <map>
#include <vector>

class CBody;

class CBodyControl
{
public:
	CBodyControl(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodiesVector);
	bool HandleCommand();
private:
	bool AddBody(std::istream& args);
	bool GetBodyWithBiggestMass(std::istream& args);
	bool GetLightestBodyInWater(std::istream& args);
	bool InfoAboutAllBodies(std::istream& args);
private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::vector<std::shared_ptr<CBody>>& m_bodiesVector;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};

