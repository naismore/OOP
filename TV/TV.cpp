#include <iostream>
#include <vector>
#include <sstream>
#include "CTVSet.h"

using namespace std;

int main()
{
	CTVSet tv;
	string command, word;
	vector<string> commandWords;
	vector<string> commands
	{
		"TurnOn",
		"TurnOff",
		"SelectChannel",
		"Info"
	};

	cout << "TELEVISION" << endl;
	while (true)
	{
		cout << "Enter the command: ";

		getline(cin, command);
		istringstream iss(command);
		
		commandWords.clear();

		while (iss >> word)
		{
			commandWords.push_back(word);
		}

		switch (find(commands.begin(), commands.end(), commandWords.front()) - commands.begin())
		{
		case 0:
			tv.TurnOn();
			cout << tv.Info() << endl;
			break;
		case 1:
			if (tv.TurnOff()) 
			{
				cout << "The TV was successfully turned off\n";
			}
			else
			{
				"Error!\n";
			}
			break;
		case 2:
			if (!commandWords[1].empty())
			{
				cout << ((tv.SelectChannel(stoi(commandWords[1]))) ? "The channel was successfully switched to " + commandWords[1] + "\n" : "Error!\n");
			}
			break;
		case 3:
			cout << tv.Info() << endl;
			break;
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}	
}

