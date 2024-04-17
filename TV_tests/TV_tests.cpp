#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../TV/CTVSet.h"

TEST_CASE("Default use TV")
{
	CTVSet tv;
	CHECK(tv.Info() == "TV is off\n");
	
	CHECK(tv.TurnOn());
	CHECK(tv.Info() == "TV is on. Channel: 1\n");

	CHECK(tv.SelectChannel(4) == true);
	CHECK(tv.Info() == "TV is on. Channel: 4\n");

	// ТЕст на 99 канал
	CHECK(tv.SelectChannel(100) == false);
	CHECK(tv.SelectChannel(-12) == false);

	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.Info() == "TV is on. Channel: 1\n");

	CHECK(tv.TurnOff() == true);
	CHECK(tv.Info() == "TV is off\n");

}

TEST_CASE("Turn on the TV when it's on and turn it off when it's off")
{
	CTVSet tv;
	CHECK(tv.TurnOff() == true);

	CHECK(tv.TurnOn()); // Булевые значения не сравнивать 
	
	CHECK(tv.TurnOn());
}

TEST_CASE("Actions on a switched-off TV")
{
	CTVSet tv;
	CHECK(tv.TurnOff() == true);
	CHECK(tv.SelectChannel(4) == false);
	CHECK(tv.Info() == "TV is off\n");
	CHECK(tv.SelectPreviousChannel() == false);
	CHECK(tv.Info() == "TV is off\n");

}