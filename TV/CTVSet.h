#pragma once
#include <string>

// Почитать про константные методы
// Coding onventions

class CTVSet
{
private:
	int p_channelNumber;
	int p_previousChannelNumber;
	bool p_condition;
public:
	CTVSet();
	std::string Info();
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(int channelNumber);
	bool SelectPreviousChannel();
};

