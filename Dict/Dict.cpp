#include <iostream>
#include <map>
#include "SearchTranslation.h"
#include "AddTranslation.h"
#include "OpenDictionaryFile.h"
#include "SaveDictionaryToFile.h"
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* args[])
{

	map<string, string> dictionary;
	map<string, string> addingTranslation;



	/*
	if (argc != 2)
	{
		cout << "Usage minidictionary.exe <dict file>\n";
		return 1;
	}
	
	*/

	dictionary = OpenDictionaryFile("dict.txt");
	
	string inputWord; 

	bool working = true;
	while (true)
	{
		cin >> inputWord;
		std::transform(inputWord.begin(), inputWord.end(), inputWord.begin(), tolower);
		if (inputWord == "...")
		{
			break;
		}
		if (SearchTranslation(inputWord, dictionary) != "Undefined")
		{
			if (SearchTranslation(inputWord, dictionary) == "Error")
			{
				cout << "Error to search translation\n";
				return 1;
			}
			cout << "Word: " << inputWord << " Translation: " << SearchTranslation(inputWord, dictionary) << endl;
		}
		else
		{
			string inputTranslation;
			cout << "Такое слово не найдено, запишите к нему перевод: ";
			cin >> inputTranslation;
			if (!inputTranslation.empty())
			{
				std::transform(inputTranslation.begin(), inputTranslation.end(), inputTranslation.begin(), tolower);
				if (AddTranslation(inputWord, inputTranslation, dictionary, addingTranslation))
				{
					cout << "Translation " << inputTranslation << " to word " << inputWord << " was successfully saved!";
				}
				else
				{
					cout << "Error to save translation into dictionary!\n";
					return 1;
				}
			}
		}
	}
	
	if (!addingTranslation.empty())
	{
		string action;
		cout << "Сохранить изменения в словаре?(y/n): ";
		cin >> action;

		if (action == "y")
		{
			if (!SaveDictionaryToFile("dict.txt", addingTranslation))
			{
				cout << "Error to save dictionary\n";
				return 1;
			}

			cout << "Изменения сохранены. До свидания.\n";
			return 0;
		}
	}
	/*
	
	*/

	cout << "До свидания.\n";
	return 0;
}