#include "AddTranslation.h"
#include <map>

bool AddTranslation(const std::string& inputWord, const std::string& inputTranslation, std::map<std::string, std::string> dictionary, std::map<std::string, std::string> addingTranslation)
{
	try
	{
		dictionary[inputWord] = inputTranslation;
		addingTranslation[inputWord] = inputTranslation;
		return false;
	}
	catch (...)
	{
		return true;
	}
}