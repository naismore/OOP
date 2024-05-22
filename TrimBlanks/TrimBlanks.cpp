#include <iostream>

using namespace std;


/*
string TrimBlanks(string const& str)
{
	bool spaceSleep = true;
	string resultString;
	for (int i = 0; i < str.length(); i++)
	{
		if(str[i] != ' ' )
	}
	return resultString;
}

*/

std::string TrimBlanks(const std::string& str) {
	// Находим первую позицию, где символ не пробел
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
		return ""; // Строка состоит только из пробелов

	// Находим последнюю позицию, где символ не пробел
	size_t last = str.find_last_not_of(' ');

	// Возвращаем подстроку без начальных и конечных пробелов
	return str.substr(first, (last - first + 1));
}

int main()
{
	setlocale(LC_ALL, "");
	cout << TrimBlanks("              asdads   asdasd  a sd           ") + '#' << endl;
	return 0;
}