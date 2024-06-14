#include <iostream>
#include "Car.h"

int main() {
    Car car;
    std::string command;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "Info") {
            std::cout << "Info: " << (car.IsTurnedOn() ? "on" : "off") << ", " << car.GetDirection() << ", " << car.GetSpeed() << ", " << car.GetGear() << std::endl;
        }
        else if (command == "EngineOn") {
            car.TurnOnEngine();
        }
        else if (command == "EngineOff") {
            car.TurnOffEngine();
        }
        else if (command == "SetGear") {
            int gear;
            std::cin >> gear;
            try {
                car.SetGear(gear);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "SetSpeed") {
            int speed;
            std::cin >> speed;
            try {
                car.SetSpeed(speed);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    return 0;
}