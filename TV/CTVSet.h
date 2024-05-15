#pragma once
#include <string>

// ѕочитать про константные методы
// Coding onventions

class CTVSet
{
private:
	// p заменить на m
	int m_channelNumber;
	int m_previousChannelNumber;
	bool m_isTurnedOn;
public:
	CTVSet();
	std::string Info();
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(int channelNumber);
	bool SelectPreviousChannel();
};

