#include <iostream>

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
    if (argc != 2)
    {
        cout << "Usage removeextraspaces.exe <string>\n";
        return 1;
    }

    cout << "Введеная строка: " << args[1] << endl;
    cout << "Обработанная строка: " << RemoveExtraSpaces(args[1]) << endl;
}

