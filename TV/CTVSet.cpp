#include "CTVSet.h"
#include <map>
#include <iostream>

CTVSet::CTVSet()
{
	// Поменять название на isturnedon
	p_condition = false;
	p_channelNumber = 0;
	p_previousChannelNumber = 1;
}

std::string CTVSet::Info()
{
	std::string condition = (p_condition) ? "ON" : "OFF";
	return "TV is " + condition + ". Channel: " + std::to_string(p_channelNumber);
}

bool CTVSet::TurnOn()
{
	// Поправить логику, чтение
	if (p_condition)
	{
		return true;
	}
	else
	{
		p_condition = true;
		p_channelNumber = p_previousChannelNumber;
		return true;
	}
	return false;
}

bool CTVSet::TurnOff()
{
	// Поправить логику
	if (!p_condition)
	{
		return true;
	}
	else
	{
		p_condition = false;
		p_previousChannelNumber = p_channelNumber;
		p_channelNumber = 0;
		return true;
	}
	return false;
}

bool CTVSet::SelectChannel(int channelNumber)
{
	if (p_condition && channelNumber > 0 && channelNumber <= 99)
	{
		p_previousChannelNumber = p_channelNumber;
		p_channelNumber = channelNumber;
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CTVSet::SelectPreviousChannel()
{
	if (p_condition)
	{
		std::swap(p_channelNumber, p_previousChannelNumber);
		return true;
	}
	else
	{
		return false;
	}
}