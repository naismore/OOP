#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

map<string, string> dictionary;
map<string, string> addingTranslations;

bool SaveDictionaryToFile(const string& path)
{
	ofstream out;

	out.open(path, ios::app);

	if (!out.is_open())
	{
		return false;
	}

	for (auto it = addingTranslations.begin(); it != addingTranslations.end(); ++it)
	{
		out << it->first << ' ' << it->second << endl;
	}

	return true;
}

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

int main(int argc, char* args[])
{
	setlocale(LC_ALL, "");
	SetConsoleOutputCP(CP_UTF8);
	
	if (argc != 2)
	{
		cout << "Usage minidictionary.exe <dict file>\n";
		return 1;
	}

	if (!OpenFile(args[1]))
	{
		cout << "Error to open input file\n";
		return 1;
	}

	string inputWord;
	bool working = true;
	while (true)
	{
		cin >> inputWord;
		if (inputWord == "...")
		{
			break;
		}

		if (dictionary.count(inputWord) != 0)
		{
			cout << "Слово: " << inputWord << ". Перевод: " << dictionary.find(inputWord)->second << endl;
		}
		else
		{
			string inputTranslation;
			cout << "Такое слово не найдено, запишите к нему перевод: ";
			cin >> inputTranslation;
			if (!inputTranslation.empty())
			{
				dictionary[inputWord] = inputTranslation;
				addingTranslations[inputWord] = inputTranslation;
			}
		}
	}

	if (!addingTranslations.empty())
	{
		string action;
		cout << "Сохранить изменения в словаре?(y/n): ";
		cin >> action;

		if (action == "y")
		{
			if (!SaveDictionaryToFile(args[1]))
			{
				cout << "Error to save dictionary\n";
				return 1;
			}

			cout << "Изменения сохранены. До свидания.\n";
			return 0;
		}
	}
	
	cout << "До свидания.\n";
	return 0;
}