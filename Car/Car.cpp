#include "Car.h"
#include <stdexcept>

Car::Car() : engineOn_(false), gear_(0), speed_(0) {}

bool Car::TurnOnEngine() {
    if (!engineOn_) {
        engineOn_ = true;
        gear_ = 0;
        speed_ = 0;
        return true;
    }
    return false;
}

bool Car::TurnOffEngine() {
    if (engineOn_ && gear_ == 0 && speed_ == 0) {
        engineOn_ = false;
        return true;
    }
    return false;
}

bool Car::SetGear(int gear) {
    if (!engineOn_) {
        throw std::runtime_error("Engine is off");
    }
    if (gear < -1 || gear > 5) {
        throw std::invalid_argument("Invalid gear");
    }
    if (gear == -1 && speed_ != 0) {
        throw std::runtime_error("Cannot switch to reverse gear while moving");
    }
    if (gear == 0 && speed_ != 0) {
        throw std::runtime_error("Cannot switch to neutral gear while moving");
    }
    if (gear > 0 && speed_ < GetMinSpeed(gear)) {
        throw std::runtime_error("Cannot switch to gear while speed is too low");
    }
    if (gear > 0 && speed_ > GetMaxSpeed(gear)) {
        throw std::runtime_error("Cannot switch to gear while speed is too high");
    }
    gear_ = gear;
    return true;
}

bool Car::SetSpeed(int speed) {
    if (!engineOn_) {
        throw std::runtime_error("Engine is off");
    }
    if (gear_ == 0 && speed != 0) {
        throw std::runtime_error("Cannot change speed on neutral gear");
    }
    if (gear_ > 0 && (speed < GetMinSpeed(gear_) || speed > GetMaxSpeed(gear_))) {
        throw std::runtime_error("Cannot change speed to specified value");
    }
    speed_ = speed;
    return true;
}

bool Car::IsTurnedOn() const { return engineOn_; }
std::string Car::GetDirection() const {
    if (speed_ > 0) {
        return "forward";
    }
    else if (speed_ < 0) {
        return "backward";
    }
    else {
        return "standing still";
    }
}
int Car::GetSpeed() const { return std::abs(speed_); }
int Car::GetGear() const { return gear_; }

int Car::GetMinSpeed(int gear) const {
    switch (gear) {
    case -1: return 0;
    case 0: return 0;
    case 1: return 0;
    case 2: return 20;
    case 3: return 30;
    case 4: return 40;
    case 5: return 50;
    default: throw std::runtime_error("Invalid gear");
    }
}

int Car::GetMaxSpeed(int gear) const {
    switch (gear) {
    case -1: return 20;
    case 0: return INT_MAX;
    case 1: return 30;
    case 2: return 50;
    case 3: return 60;
    case 4: return 90;
    case 5: return 150;
    default: throw std::runtime_error("Invalid gear");
    }
}