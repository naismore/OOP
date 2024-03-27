#include "CTVSet.h"
#include <iostream>
#include <format>

CTVSet::CTVSet()
{
	p_condition = false;
	p_channelNumber = 0;
	p_previousChannelNumber = 1;
}

std::string CTVSet::Info()
{
	return (p_condition) ? std::format("TV is on. Channel {}", p_channelNumber);
}

void CTVSet::TurnOn()
{
	p_condition = true;
	p_channelNumber = p_previousChannelNumber;
}

void CTVSet::TurnOff()
{
	p_condition = false;
	p_previousChannelNumber = p_channelNumber;
	p_channelNumber = 0;
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