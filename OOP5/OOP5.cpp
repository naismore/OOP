#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "CVector3D.h"
#include "DotProduct.h"
#include "CrossProduct.h"
#include "Normalize.h"

TEST_CASE("CVector3D default constructor initializes to zero")
{
	CVector3D vec;
	REQUIRE(vec.GetLength() == 0);
}

TEST_CASE("CVector3D parameterized constructor initializes correctly")
{
	CVector3D vec(1.0, 2.0, 3.0);
	REQUIRE(vec.GetLength() == Approx(3.74166).epsilon(0.0001)); // sqrt(1^2 + 2^2 + 3^2)
}

TEST_CASE("CVector3D normalization works correctly")
{
	CVector3D vec(3.0, 4.0, 0.0);
	vec.Normalize();
	REQUIRE(vec.GetLength() == Approx(1.0).epsilon(0.0001));
}

TEST_CASE("CVector3D normalization of zero vector does not change it")
{
	CVector3D vec;
	vec.Normalize();
	REQUIRE(vec.GetLength() == 0);
}

TEST_CASE("CVector3D addition works correctly")
{
	CVector3D vec1(1.0, 2.0, 3.0);
	CVector3D vec2(4.0, 5.0, 6.0);
	CVector3D result = vec1 + vec2;
	REQUIRE(result == CVector3D(5.0, 7.0, 9.0));
}

TEST_CASE("CVector3D subtraction works correctly")
{
	CVector3D vec1(5.0, 7.0, 9.0);
	CVector3D vec2(1.0, 2.0, 3.0);
	CVector3D result = vec1 - vec2;
	REQUIRE(result == CVector3D(4.0, 5.0, 6.0));
}

TEST_CASE("CVector3D scalar multiplication works correctly")
{
	CVector3D vec(1.0, 2.0, 3.0);
	CVector3D result = vec * 2;
	REQUIRE(result == CVector3D(2.0, 4.0, 6.0));
}

TEST_CASE("CVector3D scalar multiplication with negative scalar")
{
	CVector3D vec(1.0, -2.0, 3.0);
	CVector3D result = vec * -1;
	REQUIRE(result == CVector3D(-1.0, 2.0, -3.0));
}

TEST_CASE("CVector3D scalar division works correctly")
{
	CVector3D vec(4.0, 8.0, 12.0);
	CVector3D result = vec / 4;
	REQUIRE(result == CVector3D(1.0, 2.0, 3.0));
}

TEST_CASE("CVector3D division by zero throws exception")
{
	CVector3D vec(1.0, 1.0, 1.0);
	REQUIRE_THROWS_AS(vec / 0, std::invalid_argument);
}

TEST_CASE("CVector3D equality operator works correctly")
{
	CVector3D vec1(1.00001, 2.00001, 3.00001);
	CVector3D vec2(1.00001, 2.00001, 3.00001);

	REQUIRE(vec1 == vec2); // Should be equal within the epsilon
}

TEST_CASE("CVector3D inequality operator works correctly")
{
	CVector3D vec1(1.0, 2.0, 3.0);
	CVector3D vec2(4.0, 5.0, 6.0);

	REQUIRE(vec1 != vec2); // Should not be equal
}

TEST_CASE("CVector3D operator+= works correctly")
{
	CVector3D vec(1.0, 2.0, 3.0);
	vec += CVector3D(4.0, -5.0, -6.0);

	REQUIRE(vec == CVector3D(5.0, -3.0, -3.0));
}

TEST_CASE("CVector3D operator*= works correctly")
{
	CVector3D vec(1.5, -2., 4.);
	vec *= -2;

	REQUIRE(vec == CVector3D(-3., 4., -8.));
}

TEST_CASE("CVector3D operator/= works correctly")
{
	CVector3D vec(-10., -20., -30.);
	vec /= -10.;

	REQUIRE(vec == CVector3D(1., 2., 3.));
}

TEST_CASE("CVector3D operator/ throws exception on division by zero")
{
	CVector3D vec(10., -20., -30.);

	REQUIRE_THROWS_AS(vec /= 0., std::invalid_argument);
}

TEST_CASE("CVector3D operator- returns correct negation")
{
	CVector3D vec(-7., -14., -21.);

	CVector3D negated = -vec;

	REQUIRE(negated == CVector3D(7., 14., 21.));
}

TEST_CASE("CVector multiplication with scalar from left side works correctly")
{
	CVector3D vec(1., -2., 4.);

	auto result = 2 * vec; // Assuming you have defined the operator* for double and vector

	REQUIRE(result == CVector3D(2., -4., 8.));
}


// Тесты для DotProduct
TEST_CASE("DotProduct calculates the correct scalar product", "[DotProduct]")
{
	CVector3D v1(1.0, 2.0, 3.0);
	CVector3D v2(4.0, -5.0, 6.0);
	double result = DotProduct(v1, v2);
	REQUIRE(result == Approx(12.0)); // 1*4 + 2*(-5) + 3*6 = 12
}

// Тесты для CrossProduct
TEST_CASE("CrossProduct calculates the correct vector product", "[CrossProduct]")
{
	CVector3D v1(1.0, 2.0, 3.0);
	CVector3D v2(4.0, 5.0, 6.0);
	CVector3D result = CrossProduct(v1, v2);

	REQUIRE(result.x == Approx(-3.0));
	REQUIRE(result.y == Approx(6.0));
	REQUIRE(result.z == Approx(-3.0)); // (2*6 - 3*5), (3*4 - 1*6), (1*5 - 2*4)
}

// Тесты для Normalize
TEST_CASE("Normalize returns a unit vector in the same direction", "[Normalize]")
{
	CVector3D v(3.0, 4.0, 0.0);
	CVector3D normalized = Normalize(v);

	REQUIRE(normalized.GetLength() == Approx(1.0)); // Должен быть единичный вектор
	REQUIRE(normalized.x == Approx(0.6)); // 3/5
	REQUIRE(normalized.y == Approx(0.8)); // 4/5
	REQUIRE(normalized.z == Approx(0.0));
}

// Тест для нормализации нулевого вектора
TEST_CASE("Normalize throws an exception for zero vector", "[Normalize]")
{
	CVector3D zeroVector(0.0, 0.0, 0.0);

	REQUIRE_THROWS_AS(Normalize(zeroVector), std::invalid_argument);
}
