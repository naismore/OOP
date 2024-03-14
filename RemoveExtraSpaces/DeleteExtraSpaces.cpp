#include <iostream>
#include <string>
#include "RemoveExtraSpaces.h"

void main()
{
    setlocale(LC_ALL, "");
    std::string temp;

    std::cout << "Введите строку: ";
    std::getline(std::cin, temp);

    std::cout << "Введеная строка: " << temp << std::endl;
    std::cout << "Обработанная строка: " << RemoveExtraSpaces(temp) << std::endl;
}
