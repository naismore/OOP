#pragma once
#include <string>

// Почитать про константные методы
// Coding onventions

class CTVSet
{
private:

	int m_channelNumber;
	int m_previousChannelNumber;
	bool m_isTurnedOn;
public:
	CTVSet();
	std::string Info();
	void TurnOn();
	void TurnOff();
	void SelectChannel(int channelNumber);
	void SelectPreviousChannel();
};

