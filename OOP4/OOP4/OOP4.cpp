#include "stdafx.h"
#include "CCone.h"
#include "CParallelepiped.h"

#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

TEST_CASE("CCone")
{
    CCone cone(7.874, 10, 15);
    REQUIRE(cone.GetBaseRadius() == 10);
    REQUIRE(cone.GetDensity() == 7.874);
    REQUIRE(cone.GetHeight() == 15);
    REQUIRE(cone.GetMass() == cone.GetVolume() * cone.GetDensity());
    std::cout << cone.ToString() << std::endl; 
}

TEST_CASE("CParallelepiped")
{
    CParallelepiped par(7.874, 10, 10, 10);
    REQUIRE(par.GetDensity() == 7.874);
    REQUIRE(par.GetDepth() == 10);
    REQUIRE(par.GetHeight() == 10);
    REQUIRE(par.GetWidth() == 10);
    REQUIRE(par.GetMass() == par.GetVolume() * par.GetDensity());
    REQUIRE(par.GetVolume() == 1000);
}

