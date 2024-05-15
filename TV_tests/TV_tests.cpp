#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../TV/CTVSet.h"

// Прогнать OpenCppCoverage


TEST_CASE("Проверка граничных значений")
{
	CTVSet tv;
	CHECK(!tv.SelectChannel(0));
	CHECK(!tv.SelectChannel(100));
	CHECK(!tv.SelectChannel(-1));
	CHECK(tv.SelectChannel(99));
}

TEST_CASE("TurnOn")
{
	CTVSet tv;
	CHECK(tv.TurnOn());
	CHECK(tv.SelectChannel(32));
	CHECK(tv.Info() == "TV is ON. Channel: 32");
	CHECK(!tv.TurnOn());
	CHECK(tv.TurnOff());
	CHECK(tv.Info() == "TV is OFF. Channel: 0");
	CHECK(tv.TurnOn());
	CHECK(tv.Info() == "TV is ON. Channel: 32");
}

TEST_CASE()
{
	CTVSet tv;
	CHECK(!tv.TurnOff());
	CHECK(tv.TurnOn());
	CHECK(tv.TurnOff());
	CHECK(!tv.TurnOff());
}

TEST_CASE("SelectChannel")
{
	CTVSet tv;
	CHECK(tv.Info() == "TV is OFF. Channel: 0");
	CHECK(!tv.SelectChannel(1));
	CHECK(tv.TurnOn());
	CHECK(tv.SelectChannel(99));
	CHECK(!tv.SelectChannel(-1));
	CHECK(!tv.SelectChannel(100));
}

TEST_CASE("SelectPreviousChannel")
{
	CTVSet tv;
	CHECK(!tv.SelectPreviousChannel());
	CHECK(tv.TurnOn());
	CHECK(tv.Info() == "TV is ON. Channel: 1");
	CHECK(tv.SelectChannel(87));
	CHECK(tv.Info() == "TV is ON. Channel: 87");
	CHECK(tv.SelectPreviousChannel());
	CHECK(tv.Info() == "TV is ON. Channel: 1");
}