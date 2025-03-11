#include <iostream>
#include <fstream>

#include "CShapeController.h"

using namespace std;

const string ERROR_OPEN_FILE = "Failed to open file for reading";

int main()
{
	setlocale(LC_ALL, "");
	CShapeController shapeController(std::cin, std::cout);
	while (!std::cin.eof() && !std::cin.fail())
	{
		shapeController.HandleCommand();
	}
}
