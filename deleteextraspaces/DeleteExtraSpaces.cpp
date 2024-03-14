#include <iostream>
#include <string>
#include "RES.h"

using namespace std;

int main()
{
    string temp;

    cout << "Введите строку: ";
    getline(cin, temp);

    cout << "Введеная строка: " << temp << endl;
    cout << "Обработанная строка: " << RemoveExtraSpaces(temp) << endl;
}

