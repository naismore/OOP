#include <iostream>
#include <vector>
#include <sstream>
#include "CTVSet.h"
#include "CTVSetControl.h"

using namespace std;

const std::string COMMAND_HELPER = "TurnOn";

int main()
{
	CTVSet tv;
	CTVSetControl tvController(tv, std::cin, std::cout);
	
	cout << COMMAND_HELPER << endl;
	while (!cin.eof() && !cin.fail())
	{
		std::cout << "> ";
		if (!tvController.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
			std::cout << COMMAND_HELPER << std::endl;
		}
	}
	return 0;
}


/*
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
		"SelectPreviousChannel",
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
			if (tv.TurnOn()) 
			{
				cout << tv.Info() << endl;
			}
			else
			{
				cout << "Couldn't turn on the TV" << endl;
			}
			break;
		case 1:
			if (tv.TurnOff()) 
			{
				cout << "The TV was successfully turned off\n";
			}
			else
			{
				"Couldn't turn off the TV\n";
			}
			break;
		case 2:
			if (!commandWords[1].empty())
			{
				cout << ((tv.SelectChannel(stoi(commandWords[1]))) ? "The channel was successfully switched to " + commandWords[1] + "\n" : "The channel could not be switched\n");
			}
			break;
		case 3:
			if (tv.SelectPreviousChannel())
			{
				cout << tv.Info() << endl;
			}
			else
			{
				cout << "Failed to switch to the previous channel" << endl;
			}
		case 4:
			cout << tv.Info() << endl;
			break;
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}	
}

*/
