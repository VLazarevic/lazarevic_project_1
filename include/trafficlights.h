#pragma once

#include "enums.h"
#include <mutex>

class TrafficLight {
    private:
        TrafficColor colorNorthSouth;
        TrafficColor colorWestEast;
        std::mutex l_mutex;

    public:
        TrafficColor getNorthSouthColor();
        TrafficColor getWestEastColor();
        void startTrafficLight();
};