#pragma once

#include "enums.h"

class TrafficLight {
    private:
        TrafficColor colorNorthSouth{RED};
        TrafficColor colorWestEast{GREEN};
    
    public:
        TrafficColor getNorthSouthColor();
        TrafficColor getWestEastColor();
        void startTrafficLight();
};