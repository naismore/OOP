#include <iostream>
#include <string>
#include "RemoveExtraSpaces.h"

void main()
{
    setlocale(LC_ALL, "");
    std::string temp;

    std::cout << "������� ������: ";
    std::getline(std::cin, temp);

    std::cout << "�������� ������: " << temp << std::endl;
    std::cout << "������������ ������: " << RemoveExtraSpaces(temp) << std::endl;
}
