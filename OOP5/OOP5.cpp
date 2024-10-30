#include <iostream>
#define CONFIG_CATCH_MAIN
#include "../catch2/catch.hpp"
#include "CVector3D.h"

TEST_CASE("Vector GetLength")
{
	SECTION("Testing with known values")
	{
		CVector3D v1(3.0, 4.0, 0.0);
		REQUIRE(v1.GetLength() == 5.0);

		CVector3D v2(1.0, 2.0, 2.0);
		REQUIRE(v2.GetLength() == std::sqrt(9));

		CVector3D v3(0.0, 0.0, 0.0);
		REQUIRE(v3.GetLength() == 0.0);
	}

	SECTION("Testing with large values")
	{
		CVector3D v(10000.0, 20000.0, 30000.0);
		double expectedLength = std::sqrt(10000 * 10000 + 20000 * 20000 + 30000 * 30000);
		REQUIRE(v.GetLength() == expectedLength);
	}

	SECTION("Testing with negative values")
	{
		CVector3D v(-3.0, -4.0, 0.0);
		REQUIRE(v.GetLength() == 5.0);
	}

	SECTION("Testing with single vectors")
	{
		CVector3D v(1.0, 1.0, 1.0);
		double expectedLength = std::sqrt(3);
		REQUIRE(v.GetLength() == expectedLength);
	}
}

TEST_CASE("Vector Normalize")
{
	SECTION("Testing with non normalized vector")
	{
		CVector3D v(3.0, 4.0, 0.0);
		v.Normalize();
		// REQUIRE();
	}
}
