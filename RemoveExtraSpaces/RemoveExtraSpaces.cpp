#include "RemoveExtraSpaces.h"
#include <set>

std::string RemoveExtraSpaces(std::string const& inputString)
{
    std::set<char> chars{' ', '\t'};
    std::string resultString = "";
    if (!inputString.empty())
    {
        bool space_sleep = true;
        for (const char& i : inputString)
        {
            if (chars.count(i) == 1 && space_sleep)
            {
                continue;
            }
            if (chars.count(i) == 1)
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
        if (!resultString.empty())
        {
            char i = resultString.back();
            while (chars.count(i) == 1)
            {
                resultString.pop_back();
                i = resultString.back();
            }
        }
    }

    return resultString;
}
