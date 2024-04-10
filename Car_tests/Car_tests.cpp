#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Car/Car.h"

TEST_CASE("")
{
	Car car;
	CHECK(car.IsTurnedOn() == false);
	CHECK(car.TurnOnEngine() == true);
	CHECK(car.IsTurnedOn() == true);
	CHECK(car.GetGear() == 0);
	CHECK(car.GetDirection() == 0);
	CHECK(car.SetGear(-1) == true);
}