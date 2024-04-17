#pragma once
class Car
{
public:
	Car();
	bool TurnOnEngine(); // Turning on the engine. Returned true if engine was turned on successful(or already is on)
	bool TurnOffEngine(); // Turning off the engine. 
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn();
	int GetDirection();
	unsigned int GetSpeed() const;
	int GetGear() const;
private:
	int p_speed = 0;
	int p_gear;
	bool p_engineCondition;
};

