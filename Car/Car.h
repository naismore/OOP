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
	int GetDirection() const;
	unsigned int GetSpeed() const;
	int GetGear() const;
private:
	unsigned int p_speed;
	int p_gear;
	bool p_engineCondition;
};

