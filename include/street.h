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
    queue<Car> carQueue;
public:
    Street(int generateAmount, TrafficLight* light, Directions direction);
    void startStreet();
    void fillCarQueue();
};