#pragma once
class CTVSet
{
public:
	CTVSet();
	std::string Info();
	void TurnOn();
	void TurnOff();
	void SelectChannel(int channelNumber);
	void SelectPreviousChannel();
private:
	int p_channelNumber;
	int p_previousChannelNumber;
	bool p_condition;
};

