#include "OpenDictionaryFile.h"
#include <fstream>
#include <sstream>

std::map<std::string, std::string> OpenDictionaryFile(const std::string& path)
{
	std::ifstream in(path);

	std::map<std::string, std::string> dictMap;

	if (!in.is_open())
	{
		return dictMap;
	}

	std::string line;
	while (getline(in, line))
	{
		if (!line.empty())
		{
			std::istringstream iss(line);
			std::string word, translation;

			iss >> word >> translation;
			dictMap[word] = translation;
			dictMap[translation] = word;
		}
	}
	return dictMap;
}