#include <iostream>
#include "CTVSet.h"


using namespace std;

int main()
{
	CTVSet tv;
	cout << tv.Info();

	tv.TurnOn();
	cout << tv.Info(); 

	tv.SelectChannel(3);
	cout << tv.Info();

	tv.TurnOff();
	cout << tv.Info();

	tv.TurnOn();
	cout << tv.Info();

	tv.SelectChannel(5);
	cout << tv.Info();

	tv.SelectPreviousChannel();
	cout << tv.Info();
}

