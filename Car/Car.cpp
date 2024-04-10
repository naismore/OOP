#include <iostream>
#include "Car.h"

Car::Car()
{
	bool p_engineCondition = false;
	unsigned int p_speed = 0;
	int p_gear = 0;
}

bool Car::TurnOnEngine()
{
	try
	{
		if (p_engineCondition)
		{
			return true;
		}
		else if (!p_engineCondition)
		{
			p_engineCondition = true;
			return true;
		}
	}
	catch (...)
	{
		return false;
	}	
}

bool Car::TurnOffEngine()
{
	try
	{
		if (p_engineCondition && p_gear == 0 && p_speed == 0)
		{
			p_engineCondition = false;
			return true;
		}
		else if(!p_engineCondition)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}	
}

bool Car::SetGear(int gear)
{
	if (p_engineCondition)
	{
		switch (gear)
		{
		case -1:
			if (p_speed == 0)
			{
				p_gear = gear;
				return true;
				break;
			}
		case 0:
			p_gear = gear;
			return true;
			break;
		case 1:
			if (p_speed == 0)
			{
				p_gear = gear;
				return true;
				break;
			}
		case 2:
			if (p_speed >= 20 && p_speed <= 50 && p_gear != -1)
			{
				p_gear = gear;
				return true;
				break;
			}
		case 3:
			if (p_speed >= 30 && p_speed <= 60)
			{
				p_gear = gear;
				return true;
				break;
			}
		case 4:
			if (p_speed >= 40 && p_speed <= 90)
			{
				p_gear = gear;
				return true;
				break;
			}
		case 5:
			if (p_speed >= 50 && p_speed <= 150)
			{
				p_gear = gear;
				return true;
				break;
			}
		default:
			return false;
		}
	}
	return false;
}

bool Car::SetSpeed(int speed)
{
	if (p_engineCondition)
	{
		switch (p_gear)
		{
		case -1:
			if (speed >= 0 && speed <= 20)
			{
				p_speed = speed;
				return true;
				break;
			}
		case 0:
			if (speed < p_speed)
			{
				p_speed = speed;
				return true;
				break;
			}
		case 1:
			if (speed >= 0 && speed <= 30)
			{
				p_speed = speed;
				return true;
				break;		
			}
		case 2:
			if (speed >= 20 && speed <= 5)
			{
				p_speed = speed;
				return true;
				break;
			}
		case 3:
			if (speed >= 30 && speed <= 60)
			{
				p_speed = speed;
				return true;
				break;
			}
		case 4:
			if (speed >= 40 && speed <= 90)
			{
				p_speed = speed;
				return true;
				break;
			}
		case 5:
			if (speed >= 50 && speed <= 150)
			{
				p_speed = speed;
				return true;
				break;
			}
		default:
			return false;
		}
	}
	return false;
}

bool Car::IsTurnedOn() 
{
	return p_engineCondition;
}

int Car::GetDirection() const
{
	if (p_gear > 0)
	{
		return 1;
	}
	return p_gear;
}

unsigned int Car::GetSpeed() const
{
	return p_speed;
}

int Car::GetGear() const
{
	return p_gear;
}
