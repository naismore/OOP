#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

bool OpenFile(const string& path)
{
	ifstream in(path);

	if (!in.is_open())
	{
		return false;
	}
	
	string line;
	while (getline(in, line))
	{
		if (!line.empty())
		{
			istringstream iss(line);
			string word, translation;

			iss >> word >> translation;
			dictionary[word] = translation;
		}
	}
	return true;
}

map<string, string> dictionary;

int Main(int argc, char* args[])
{

}