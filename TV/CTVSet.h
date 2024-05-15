#pragma once
#include <string>

// �������� ��� ����������� ������
// Coding onventions

class CTVSet
{
private:
	// p �������� �� m
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

