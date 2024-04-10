#include "CTVSet.h"
#include <iostream>

CTVSet::CTVSet()
{
	p_condition = false;
	p_channelNumber = 0;
	p_previousChannelNumber = 1;
}

std::string CTVSet::Info()
{
	return (p_condition) ? "TV is on. Channel: " + std::to_string(p_channelNumber) + '\n' : "TV is off\n";
}

std::string CTVSet::TurnOn()
{
	if (p_condition) 
	{
		return "TV already on\n";
	}
	else
	{
		p_condition = true;
		p_channelNumber = p_previousChannelNumber;
		return "Turning on the TV...\n";
	}
}

std::string CTVSet::TurnOff()
{
	if (!p_condition)
	{
		return "TV already off\n";
	}
	else
	{
		p_condition = false;
		p_previousChannelNumber = p_channelNumber;
		p_channelNumber = 0;
		return "Turning off the TV...\n";
	}
}

void CTVSet::SelectChannel(int channelNumber)
{
	p_previousChannelNumber = p_channelNumber;
	p_channelNumber = channelNumber;
}

void CTVSet::SelectPreviousChannel()
{
	std::swap(p_channelNumber, p_previousChannelNumber);
}