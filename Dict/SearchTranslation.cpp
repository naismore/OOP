#include "SearchTranslation.h"

std::string SearchTranslation(const std::string& word, std::map<std::string, std::string>& dictionary)
{
	std::string translation = "Undefined";
	if (dictionary.count(word) != 0)
	{
		translation = dictionary[word];
	}
	return translation;

}
