#pragma once
class CBody;
#include <vector>
#include <functional>
#include <map>

class CBodyControl
{
public:
	CBodyControl(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodiesVector);
	bool HandleCommand();

private:
	bool InfoAboutAllBodies(std::istream& args);
	bool AddBody(std::istream& args);
	bool GetBodyWithBiggestMass(std::istream& args);
	bool GetLightestBodyInWater(std::istream& args);

private:
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;

	std::vector<std::shared_ptr<CBody>>& m_bodiesVector;
};


