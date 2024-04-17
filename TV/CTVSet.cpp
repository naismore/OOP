#include "CTVSet.h"
#include <map>
#include <iostream>

// Info по ТЗ
// Не нужно везде сувать try catch, если нет смысла

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

bool CTVSet::TurnOn()
{
	try
	{
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
	}
	catch (...)
	{
		return false;
	}
	
}

bool CTVSet::TurnOff()
{
	try
	{
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

	}
	catch (...)
	{
		return false;
	}
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