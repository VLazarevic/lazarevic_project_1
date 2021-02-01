#pragma once

#include "trafficlights.h"
#include "car.h"
#include "enums.h"

#include <queue>

class Street
{
private:
    TrafficLight* light;
    Directions direction;
    int generateAmount;
    std::queue<Car>* carQueue = new std::queue<Car>();
public:
    Street(int generateAmount, TrafficLight* light, Directions direction);
    void startStreet();
    void fillCarQueue();
};