#include <iostream>

using namespace std;

class CTVSet
{
public:
    CTVSet()
    {
        p_condition = false;
        p_channelNumber = 0;
    }
    void Info()
    {
        cout << (!p_condition) ? "TV is off" : "TV is on. Channel: " << p_channelNumber;
    }
private:
    bool p_condition;
    int p_channelNumber;
};

int main()
{
    
}

