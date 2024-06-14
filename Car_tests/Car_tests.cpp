#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"

#include "../Car/Car.h" // включаем файл с классом Car

TEST_CASE("Turning on and off the engine") {
    Car car;
    REQUIRE_FALSE(car.IsTurnedOn());
    REQUIRE(car.TurnOnEngine());
    REQUIRE(car.IsTurnedOn());
    REQUIRE(car.TurnOffEngine());
    REQUIRE_FALSE(car.IsTurnedOn());
}
TEST_CASE("Setting gear to invalid value") {
    Car car;
    car.TurnOnEngine();
    REQUIRE_THROWS_AS(car.SetGear(-2), std::invalid_argument);
    REQUIRE_THROWS_AS(car.SetGear(6), std::invalid_argument);
}
TEST_CASE("Setting gear to reverse gear while moving") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    car.SetSpeed(10);
    REQUIRE_THROWS_AS(car.SetGear(-1), std::runtime_error);
}
TEST_CASE("Setting gear to neutral gear while moving") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    car.SetSpeed(10);
    REQUIRE_THROWS_AS(car.SetGear(0), std::runtime_error);
}
TEST_CASE("Setting gear to invalid speed") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    REQUIRE_THROWS_AS(car.SetSpeed(-10), std::runtime_error);
}

TEST_CASE("Setting speed to invalid value") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    REQUIRE_THROWS_AS(car.SetSpeed(-10), std::runtime_error);
}

TEST_CASE("Setting speed to neutral gear") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(0);
    REQUIRE_THROWS_AS(car.SetSpeed(10), std::runtime_error);
}

TEST_CASE("Установка скорости в допустимое значение") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    car.SetSpeed(10);
    REQUIRE(car.GetSpeed() == 10);
}
TEST_CASE("Getting direction") {
    
    Car car;
    car.TurnOnEngine();
    REQUIRE(car.GetDirection() == "standing still");
    car.SetGear(1);
    car.SetSpeed(10);
    REQUIRE(car.GetDirection() == "forward");
    car.SetSpeed(0);
    car.SetGear(-1);
    car.SetSpeed(-10);
    REQUIRE(car.GetDirection() == "backward");
}
TEST_CASE("Getting gear") {
    Car car;
    car.TurnOnEngine();
    car.SetGear(1);
    REQUIRE(car.GetGear() == 1);
}




