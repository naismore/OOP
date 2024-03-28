#include "SaveDictionaryToFile.h"
#include <fstream>
#include <Windows.h>

bool SaveDictionaryToFile(const std::string& path, std::map<std::string, std::string> dictionary)
{
	std::ofstream out;

	out.open(path, std::ios::app);

	if (!out.is_open())
	{
		return false;
	}

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		out << it->first << ' ' << it->second << std::endl;
	}

	return true;
}