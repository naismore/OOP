#include "AddTranslation.h"
#include <map>

bool AddTranslation(const std::string& inputWord, const std::string& inputTranslation, std::map<std::string, std::string>& dictionary, std::map<std::string, std::string>& addingTranslation)
{
	if (!inputWord.empty() && !inputTranslation.empty())
	{
		dictionary[inputWord] = inputTranslation;
		dictionary[inputTranslation] = inputWord;
		addingTranslation[inputWord] = inputTranslation;
		addingTranslation[inputTranslation] = inputWord;
		return true;
	}
	return false;
}