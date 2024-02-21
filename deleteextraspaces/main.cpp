#include <iostream>

using namespace std;

string RemoveExtraSpaces(std::string const& arg)
{
    bool space_sleep = true;
    string resultString;
    for (int i = 0; i < arg.length(); i++)
    {
        if(arg[i] == ' ' && space_sleep == true)
        {
            continue;
        }
        if(arg[i] == ' ' && space_sleep == false)
        {
            resultString.push_back(arg[i]);
            space_sleep = true;
        }
        else
        {
            resultString.push_back(arg[i]);
            space_sleep = false;
        }
    }
    return resultString;
}

int main(int argc, char* args[])
{
    if (argc != 2)
    {
        cout << "Usage " << args[0] << "<string>\n";
        return 1;
    }

    cout << RemoveExtraSpaces(args[1]) << endl;
    return 0;
}
