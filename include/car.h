#pragma once

#include <iostream>

class Car
{
private:
    std::string name;
    std::string licensePlate;
    int speed;
public:
    static Car generateCar();
    Car(std::string name, std::string licensePlate, int speed);
    std::string getLicensePlate();
    std::string getName();
    int getSpeed();
};
