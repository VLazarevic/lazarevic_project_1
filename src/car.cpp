#include "car.h"

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

Car::Car(string name, string licensePlate, int speed) {
    this->name = name;
    this->licensePlate = licensePlate;
    this->speed = speed;
}

Car Car::generateCar() {
    random_device randomDevice;
    mt19937 gen{randomDevice()};

    uniform_real_distribution<int> dis_1{1000, 9999};

    string licensePlate = "WN-" + to_string(dis_1(gen));
    
    vector<string> carTypes = {"BMW", "VW"};

    uniform_real_distribution<int> dis_2{0, carTypes.size()};
    string name = carTypes[dis_2(gen)];

    // miliseconds
    uniform_real_distribution<int> dis_3{500, 2500};

    int speed = dis_3(gen);

    return Car(name, licensePlate);
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