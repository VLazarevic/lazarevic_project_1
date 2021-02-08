#include "car.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

Car Car::generateCar() {
    random_device randomDevice;
    mt19937 gen{randomDevice()};
    uniform_real_distribution<> dis{1000, 9999};

    
    vector<string> districtTypes = {"AM", "BN", "BL", "GD", "GF", "HL", "HO", "KO", "KR", "KS", "LF", "MD", "ME", "MI", "NK", "P", "SP", "WN", "WB"};
    uniform_real_distribution<> dis_4{0, (double) districtTypes.size()};

    string licensePlate = districtTypes[(int) dis_4(gen)] + "-" + to_string((int) dis(gen));

    vector<string> carTypes = {"BMW", "VW", "AUDI", "MERCEDES", "PORSCHE", "OPEL", "NISSAN", "MAZDA", "TOYOTA", "HONDA", "PEUGEOT"};

    uniform_real_distribution<> dis_2{0, (double) carTypes.size()};
    string name = carTypes[(int) dis_2(gen)];

    // miliseconds
    uniform_real_distribution<> dis_3{1000, 2500};

    int speed = (int) dis_3(gen);

    return Car(name, licensePlate, speed);
}

std::string Car::getLicensePlate() {
    return this->licensePlate;
}

std::string Car::getName() {
    return this->name;
}

int Car::getSpeed() {
    return this->speed;
}