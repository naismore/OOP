#include "SearchTranslation.h"

std::string SearchTranslation(const std::string& word, std::map<std::string, std::string>& dictionary)
{
	std::string translation = "Undefined";
	try
	{
		translation = dictionary[word];
		return translation;
	}
	catch (...)
	{
		return "Error";
	}
}