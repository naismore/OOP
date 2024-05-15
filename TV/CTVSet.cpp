#include "CTVSet.h"
#include <map>
#include <iostream>

CTVSet::CTVSet()
{
	m_isTurnedOn = false;
	m_channelNumber = 0;
	m_previousChannelNumber = 1;
}

std::string CTVSet::Info()
{
	std::string condition = (m_isTurnedOn) ? "ON" : "OFF";
	return "TV is " + condition + ". Channel: " + std::to_string(m_channelNumber);
}

bool CTVSet::TurnOn()
{
	if (!m_isTurnedOn)
	{
		m_isTurnedOn = true;
		m_channelNumber = m_previousChannelNumber;
		return true;
	}
	else
	{
		return false;
	}
}

bool CTVSet::TurnOff()
{
	if (m_isTurnedOn)
	{
		m_isTurnedOn = false;
		m_previousChannelNumber = m_channelNumber;
		m_channelNumber = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool CTVSet::SelectChannel(int channelNumber)
{
	if (m_isTurnedOn && channelNumber > 0 && channelNumber <= 99)
	{
		m_previousChannelNumber = m_channelNumber;
		m_channelNumber = channelNumber;
		return true;
	}
	else
	{
		return false;
	}
	
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isTurnedOn)
	{
		std::swap(m_channelNumber, m_previousChannelNumber);
		return true;
	}
	else
	{
		return false;
	}
}