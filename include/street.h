#pragma once

#include "trafficlights.h"
#include "enums.h"

class Street
{
private:
    TrafficLight* light;
    Directions direction;
public:
    Street(TrafficLight* light, Directions direction);
    void startRoad();
};