#include <string>
std::string SearchTranslation(const std::string& word)
{
	if (dictionary.count(word) != 0)
	{
		return dictionary[word];
	}
	else if (reverseTranslation.count(word) != 0)
	{
		return reverseTranslation[word];
	}
	else
	{
		return "Undefined";
	}
}