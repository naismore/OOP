#include <iostream>
#include <string>

using namespace std;

string RemoveExtraSpaces(std::string const& arg)
{
    bool space_sleep = true;
    string resultString;
    for (char i : arg)
    {
        if (i == ' ' && space_sleep)
        {
            continue;
        }
        if (i == ' ')
        {
            resultString.push_back(i);
            space_sleep = true;
        }
        else
        {
            resultString.push_back(i);
            space_sleep = false;
        }
    }
    return resultString;
}

int main(int argc, char* args[])
{
    string temp;

    cout << "Введите строку: ";
    getline(cin, temp);

    cout << "Введеная строка: " << temp << endl;
    cout << "Обработанная строка: " << RemoveExtraSpaces(temp) << endl;
}

