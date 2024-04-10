#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../TV/CTVSet.h"

TEST_CASE("Default use TV")
{
	CTVSet tv;
	CHECK(tv.Info() == "TV is off\n");
	
	CHECK(tv.TurnOn() == "Turning on the TV...\n");
	CHECK(tv.Info() == "TV is on. Channel: 1\n");

	tv.SelectChannel(4);
	CHECK(tv.Info() == "TV is on. Channel: 4\n");

	tv.SelectPreviousChannel();
	CHECK(tv.Info() == "TV is on. Channel: 1\n");

	CHECK(tv.TurnOff() == "Turning off the TV...\n");
	CHECK(tv.Info() == "TV is off\n");

}

TEST_CASE("Turn on the TV when it's on and turn it off when it's off")
{
	CTVSet tv;
	CHECK(tv.TurnOff() == "TV already off\n");

	CHECK(tv.TurnOn() == "Turning on the TV...\n");
	
	CHECK(tv.TurnOn() == "TV already on\n");
	
}

TEST_CASE("Actions on a switched-off TV")
{
	CTVSet tv;
	CHECK(tv.TurnOff() == "TV already off\n");
	tv.SelectChannel(4);
	CHECK(tv.Info() == "TV is off\n");
	tv.SelectPreviousChannel();
	CHECK(tv.Info() == "TV is off\n");

}