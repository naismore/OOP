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

int main()
{
    std::cout << "Hello World!\n";
}

