#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car();
    bool TurnOnEngine();
    bool TurnOffEngine();
    bool SetGear(int gear);
    bool SetSpeed(int speed);
    bool IsTurnedOn() const;
    std::string GetDirection() const;
    int GetSpeed() const;
    int GetGear() const;

private:
    bool engineOn_;
    int gear_;
    int speed_;
    int GetMinSpeed(int gear) const;
    int GetMaxSpeed(int gear) const;
};

#endif // CAR_H