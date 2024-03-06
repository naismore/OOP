#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "calcsum/Add.h"
#include "calcsum/gcd.h"


TEST_CASE("Add() function must return sum of two args")
{
	CHECK(Add(3, 4) == 7);
}

TEST_CASE("GCD must return greatest common denominator")
{
	CHECK(GCD(3, 2) == 0);
}